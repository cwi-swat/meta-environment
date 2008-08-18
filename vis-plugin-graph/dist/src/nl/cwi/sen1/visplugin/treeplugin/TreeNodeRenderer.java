package nl.cwi.sen1.visplugin.treeplugin;


import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.TexturePaint;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.util.Iterator;
import java.util.Vector;
import java.util.HashMap;
import prefuse.controls.ControlAdapter;
import prefuse.data.Graph;
import prefuse.data.Node;
import prefuse.data.Tree;
import prefuse.data.expression.Predicate;
import prefuse.render.ImageFactory;
import prefuse.render.ShapeRenderer;
import prefuse.util.ColorLib;
import prefuse.util.ColorMap;
import prefuse.util.FontLib;
import prefuse.util.GraphicsLib;
import prefuse.util.PrefuseLib;
import prefuse.visual.NodeItem;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;
import prefuse.Visualization;

/**
 * A renderer for tree nodes. Draws two simple type rectangles, but defers
 * the bounds management to the layout.
 */
public class TreeNodeRenderer extends ShapeRenderer {
	private static ColorMap m_cmap;
	private static ColorMap m_leafmap = new ColorMap(ColorLib.getInterpolatedPalette(70, ColorLib.rgb(220,220,220),ColorLib.rgb(220,40,40)), 0, 70);
	private static ColorMap m_leafMmap = new ColorMap(ColorLib.getInterpolatedPalette(70, ColorLib.rgb(64,255,112),ColorLib.rgb(0,46,12)), 0, 70);
	private static ColorMap m_leafRmap= new ColorMap(ColorLib.getInterpolatedPalette(70, ColorLib.rgb(167,198,255),ColorLib.rgb(30,54,83)), 0, 70);
	private static String m_LeafLeftColorRepresentation = "None";
	private static String m_LeafMiddleColorRepresentation = "None";
	private static String m_LeafRightColorRepresentation = "None";
	private static TreeVisualization m_treeVisualization;
	private static String m_selectedLeavesNumberRepresentation = "None";
	private static String m_selectedLeavesTextureRepresentation = "None";
	private static Tree m_tree;
    private static int maxLevel = 0;
    private static HashMap<String, Integer> m_metricsMaxValue;
    Vector<VisualItem> vvi = new Vector();
    VisualItem vi;

    public TreeNodeRenderer(Tree tree, TreeVisualization treeVisualization, int depth, HashMap<String, Integer> metricsMaxValue) {
    	m_cmap = new ColorMap(ColorLib.getInterpolatedPalette(depth+1, ColorLib.rgb(80,80,80),ColorLib.rgb(200,200,120)), 0, depth);
	    m_treeVisualization = treeVisualization;
	    m_tree = tree;
	    m_metricsMaxValue = metricsMaxValue;
    }

    public void render(Graphics2D g, VisualItem item) {
    	Shape shape = getRawShape(item);
    	if(item.getString("type").equals("leaf")){
    		fillNode(g, item, shape);
        	g.setPaint(Color.DARK_GRAY);
            g.draw(shape);
    	} else {
    		Shape dir = getDirectoryShape(item, item.getX(), item.getY(), 35, 25);
    		//g.setPaint(new Color(250,240,120));
            if ( m_treeVisualization.getVisualization().isInGroup(item, Visualization.SEARCH_ITEMS)){
             	g.setPaint(ColorLib.getColor(0, 170, 170));
           	} else {
           		g.setPaint(Color.ORANGE);
           	}
    		g.fill(dir);
        	g.setPaint(Color.DARK_GRAY);
        	g.draw(dir);

    	}
        g.setPaint(Color.BLACK);
        g.setFont(new Font("Tahoma", Font.PLAIN, 12));
        AffineTransform saved = g.getTransform();
        AffineTransform rotate = AffineTransform.getRotateInstance(-3.1415926/2, (float)item.getX(), (float)item.getY());
        g.transform(rotate);
    	g.drawString(item.getString("name"), (float)item.getX()+3, (float)item.getY()+5);
        g.setTransform(saved);

    	fillTexture(g, item, shape);
    	drawText(g, item, shape);
    	fillLinks(g, item, shape);
    	drawLinks(g, item);

    }

    /**
     * fill the nodes with colors according to depth or complexity value. (complexity is an optional metric)
     * @param g java graphics
     * @param item the prefuse visual item to be drawn
     * @param shape the shape to draw, it represents the item
     */
    private void fillNode(Graphics2D g, VisualItem item, Shape shape){
    	int value = 0 ;

        if ( m_treeVisualization.getVisualization().isInGroup(item, Visualization.SEARCH_ITEMS)){
         	g.setPaint(ColorLib.getColor(0, 170, 170));
           	g.fill(shape);
       	}
    	else if(item.getString("type").equals("leaf") && item.canGet("optionalMetrics", String.class)){
           	String optionalMetrics = item.getString("optionalMetrics");
            String[] optionalMetric = optionalMetrics.split(";");
            for(String nextMetric : optionalMetric){
               	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
               	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
               	try{
                   	value = Integer.valueOf(metricValue);
               	} catch (Exception e){
               		e.printStackTrace();
               	}
                if(metricName.equals(m_LeafLeftColorRepresentation)){
					int maxValueMetric =  m_metricsMaxValue.get(m_LeafLeftColorRepresentation);
	                m_leafmap = new ColorMap(ColorLib.getInterpolatedPalette(maxValueMetric, ColorLib.rgb(220,220,220),ColorLib.rgb(220,40,40)), 0, maxValueMetric);
                  	g.setPaint(new Color(m_leafmap.getColor(value)));
                   	g.fill(shape);
                }
                else if (m_LeafLeftColorRepresentation.equals("None")) {
                   	NodeItem nitem = (NodeItem)item;
                   	g.setPaint(new Color(m_cmap.getColor(nitem.getDepth())));
                   	g.fill(shape);
                }
            }
            for(String nextMetric : optionalMetric){
               	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
               	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
               	try{
                   	value = Integer.valueOf(metricValue);
               	} catch (Exception e){
               		e.printStackTrace();
               	}
               	double x = shape.getBounds().getX();
               	double y = shape.getBounds().getY();
               	double w = shape.getBounds().getWidth();
               	double h = shape.getBounds().getHeight();
                if(metricName.equals(m_LeafMiddleColorRepresentation)){
					int maxValueMetric =  m_metricsMaxValue.get(m_LeafMiddleColorRepresentation);
	                m_leafMmap = new ColorMap(ColorLib.getInterpolatedPalette(maxValueMetric, ColorLib.rgb(64,255,112),ColorLib.rgb(0,46,12)), 0, maxValueMetric);
                	Rectangle2D rect = new Rectangle();
                	rect.setFrame(x+12, y, 12, h);
                	g.setPaint(new Color(m_leafMmap.getColor(value)));
                	g.fill(rect);

                }
                if(metricName.equals(m_LeafRightColorRepresentation)){
					int maxValueMetric =  m_metricsMaxValue.get(m_LeafRightColorRepresentation);
	                m_leafRmap = new ColorMap(ColorLib.getInterpolatedPalette(maxValueMetric, ColorLib.rgb(167,198,255),ColorLib.rgb(30,54,83)), 0, maxValueMetric);
                	Rectangle2D rect2 = new Rectangle();
                	rect2.setFrame(x+24, y, 12, h);
                	g.setPaint(new Color(m_leafRmap.getColor(value)));
                	g.fill(rect2);
                }
            }

    	}

    }

    /**
     * shows a node with its link nodes by filling them with black and gray color
     * @param g java graphics
     * @param item the prefuse visual item to be drawn
     * @param shape the shape to draw, it represents the item
     */
    private void fillLinks(Graphics2D g, VisualItem item, Shape shape){
    	if(item.getString("type").equals("leaf")){
    		if(item.canGet("linked", Integer.TYPE)){
    			int linked = item.getInt("linked");
    			if (linked == 1) {
                	g.setPaint(Color.BLACK);
                	g.fill(shape);
    			} else if (linked == 2){
                	g.setPaint(Color.DARK_GRAY);
                	g.fill(shape);
    			}
    		}
    	}
    }

    /**
     * shows a node with its link nodes by creating line nerween them
     * @param g java graphics
     * @param item the prefuse visual item to be drawn
     */
	private void drawLinks(Graphics2D g, VisualItem item){

		if(item.getString("type").equals("leaf") && item.canGet("linked", Integer.TYPE)){
			if(item.getInt("linked") == 1){
				String links = item.getString("setLinks");
				String[] linkNodes = links.split(";");
				for (String link : linkNodes){
					Node nextLink = getLastPathNode(m_tree, link);
					String linkPath = nextLink.getString("path");
					Iterator<VisualItem> m = item.getVisualization().items("tree.nodes");
					while (m.hasNext()) {
						VisualItem ma = m.next();
						if(linkPath.equals(ma.getString("path")) ){
							drawArrow(g, item, ma);
						}
						if(!ma.isExpanded() && ma.getString("type").equals("in")){
							ma.setExpanded(true);
						}
						if(maxLevel < nextLink.getDepth() && linkPath.equals(ma.getString("path"))){
							maxLevel = nextLink.getDepth();
						}
					}
				}
				m_treeVisualization.setViewHierarchyLevel(maxLevel);
				//item.setValidated(true);
				//item.setVisible(true);
	    	}
		}
	 }


	private void drawArrow(Graphics2D g, VisualItem item, VisualItem ma){
		float x1 = (float) item.getBounds().getCenterX();
		float y1 = (float) item.getBounds().getMaxY();
		float x2 = (float)  ma.getBounds().getCenterX();
		float y2 = (float) ma.getBounds().getMaxY();
		g.setPaint(Color.BLUE);
		GeneralPath m_path = new GeneralPath();
    	m_path.reset();
        m_path.moveTo(x1, y1);
        m_path.lineTo(x2, y2);
//        double xd = (x1 - x2)* 0.1;
//        double yd = (y2 - y1)* 0.1;
//        if(x1 > x2 && y1 < y2){
//            m_path.moveTo(x2, y2);
//            m_path.lineTo(x2+5, y2-10);
//            m_path.moveTo(x2, y2);
//            m_path.lineTo(x2+10, y2-5);
//        }
//        else if(x1 < x2 && y1 > y2){
//            m_path.moveTo(x2, y2);
//            m_path.lineTo(x2-5, y2+10);
//            m_path.moveTo(x2, y2);
//            m_path.lineTo(x2-5, y2-2);
//        }
        g.draw(m_path);
	}


    /**
     * sets the text labels of the nodes, these labels represents values of a specific metric
     * @param g java graphics
     * @param item the prefuse visual item to be drawn
     * @param shape the shape to draw, it represents the item
     */
    private void drawText(Graphics2D g, VisualItem item, Shape shape){
    	int value = 0 ;
    	if(item.getString("type").equals("leaf")){
            if(item.canGet("optionalMetrics", String.class) && !m_selectedLeavesNumberRepresentation.equals("None")){
            	String optionalMetrics = item.getString("optionalMetrics");
                String[] optionalMetric = optionalMetrics.split(";");
                for(String nextMetric : optionalMetric){
                	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
                	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
                	try{
                    	if (metricName.equals(m_selectedLeavesNumberRepresentation)) {
	                    	value = Integer.valueOf(metricValue);
	            	    	g.setPaint(Color.BLACK);
	            	    	g.setFont(FontLib.getFont("Tahoma", Font.PLAIN, 12));
	            	    	g.drawString(value+"", (int)(item.getBounds().getCenterX()-5), (int)(item.getBounds().getMaxY()+15));
                    	}
                	} catch (Exception e){
                		e.printStackTrace();
                	}
                }
    		}
    	}
    }

    /**
     * fills the nodes with a transparent texture to represent an additional metric
     * @param g java graphics
     * @param item the prefuse visual item to be drawn
     * @param shape the shape to draw, it represents the item
     */
    private void fillTexture(Graphics2D g, VisualItem item, Shape shape){
    	int value = 0 ;
    	if(item.getString("type").equals("leaf")){
            if(item.canGet("optionalMetrics", String.class) && !m_selectedLeavesTextureRepresentation.equals("None")){
            	String optionalMetrics = item.getString("optionalMetrics");
                String[] optionalMetric = optionalMetrics.split(";");
                for(String nextMetric : optionalMetric){
                	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
                	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
                	try{
                    	if (metricName.equals(m_selectedLeavesTextureRepresentation)) {
	                    	value = Integer.valueOf(metricValue);
	                    	BufferedImage bufferedImage = new BufferedImage(10, 10,BufferedImage.BITMASK);
	                    	Graphics2D bufferedImageGraphics = bufferedImage.createGraphics();
	                    	int maxValueMetric =  m_metricsMaxValue.get(m_selectedLeavesTextureRepresentation);
	                    	float alpha = 0;
	                    	if(maxValueMetric <= 10){
	                    		alpha = (float)(value*0.1);
	                    	} else {
	                    		alpha = (float)(value*0.01);
	                    	}
		                   	if (alpha >= 1.0) alpha = 1.0f;
	                    	bufferedImageGraphics.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC, alpha ));
	                    	bufferedImageGraphics.setColor(Color.BLACK);
	                    	bufferedImageGraphics.setStroke(new BasicStroke (1.5F, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL));
	                    	bufferedImageGraphics.drawLine(0, 0, 10, 10);
	                    	Rectangle r = new Rectangle(0, 0, 10, 10);
	                    	g.setPaint(new TexturePaint(bufferedImage, r));
	                    	g.fill(shape);
                    	}
                	} catch (Exception e){
                		e.printStackTrace();
                	}
                }
    		}
    	}
    }

	@SuppressWarnings("unchecked")
	private Node getLastPathNode(Tree tree, String filePath){
		Node nextNode = tree.getRoot();
		filePath = filePath.substring(1, filePath.length());
		String[] pathParts = filePath.split("/");
		for(String  nextPart : pathParts){
			Iterator<Node> iter = nextNode.children();
			while(iter.hasNext()){
				Node node = iter.next();
				if(node.getString("name").equals(nextPart)){
					nextNode = node;
				}
			}
		}
		return nextNode;
	}

    /**
     * draws a fileshape of the given dimenisions.
     */
    private Shape getDirectoryShape(VisualItem item, double x, double y, double width, double height) {
        GeneralPath m_path = new GeneralPath();
    	m_path.reset();
        m_path.moveTo((float)x, (float)y);
        m_path.lineTo((float)(x+width), (float)y);
        m_path.lineTo((float)(x+width), (float) (y+height));
        m_path.lineTo((float)x, (float)(y+height));
        m_path.lineTo((float)x, (float)y);
        m_path.moveTo((float)(x+width), (float)y+5);
        m_path.lineTo((float)(x+width+5), (float)y+5);
        m_path.lineTo((float)(x+width), (float)(y+height));
        return m_path;
    }

    /* (non-Javadoc)
     * @see prefuse.render.ShapeRenderer#getRawShape(prefuse.visual.VisualItem)
     */
    protected Shape getRawShape(VisualItem item) {
        double x = item.getX();
        if ( Double.isNaN(x) || Double.isInfinite(x) )
            x = 0;
        double y = item.getY();
        if ( Double.isNaN(y) || Double.isInfinite(y) )
            y = 0;
        double width = 20*item.getSize();

        if(item.getString("type").equals("leaf")){

        	double height = ((item.getDouble("weight")/100) )* 1000;
        	return rectangle(x, y, 36, height);
        }
        else{
        	return ellipse(x, y, 36, 25);
        }
    }

    /**
     *
     * @param selectedMetric the selected metric by the first color combobox
     */
    public void setLeafLeftColorRepresentation(String selectedMetric){
    	m_LeafLeftColorRepresentation = selectedMetric;
    	m_treeVisualization.update();
    }

    /**
     *
     * @param selectedMetric the selected metric by the second color combobox
     */
    public void setLeafMiddleColorRepresentation(String selectedMetric){
    	m_LeafMiddleColorRepresentation = selectedMetric;
    	m_treeVisualization.update();
    }

    /**
     *
     * @param selectedMetric the selected metric by the third color combobox
     */
    public void setLeafRightColorRepresentation(String selectedMetric){
    	m_LeafRightColorRepresentation = selectedMetric;
    	m_treeVisualization.update();
    }

    /**
     *
     * @param selectedMetric the selected metric by the number combobox
     */
    public void setLeavesNumberRepresentation(String selectedMetric){
    	m_selectedLeavesNumberRepresentation = selectedMetric;
    	m_treeVisualization.update();
    }

    /**
     *
     * @param selectedMetric the selected metric by the texture combobox
     */
    public void setLeavesTextureRepresentation(String selectedMetric){
    	m_selectedLeavesTextureRepresentation = selectedMetric;
    	m_treeVisualization.update();
    }


} // end of inner class NodeRenderer