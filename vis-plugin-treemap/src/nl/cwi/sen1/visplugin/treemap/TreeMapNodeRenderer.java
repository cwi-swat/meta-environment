package nl.cwi.sen1.visplugin.treemap;

import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.TexturePaint;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;
import java.awt.image.BufferedImage;
import prefuse.render.AbstractShapeRenderer;
import prefuse.util.ColorLib;
import prefuse.util.ColorMap;
import prefuse.util.FontLib;
import prefuse.visual.NodeItem;
import prefuse.visual.VisualItem;
import java.util.HashMap;
import prefuse.Visualization;


    /**
     * A renderer for treemap nodes. Draws and fills simple round rectangles, but defers
     * the bounds management to the layouts.
     * @author Qais
     */
    public class TreeMapNodeRenderer extends AbstractShapeRenderer {
        private static Rectangle2D  m_Rect = new Rectangle2D.Double();
		private static ColorMap m_cmap;
		private static ColorMap m_leafmap;
		private static String m_selectedLeavesColorRepresentation = "None";
		private static TreeMapVisualization m_treeMapVisualization;
		private static String m_selectedLeavesNumberRepresentation = "None";
		private static String m_selectedLeavesTextureRepresentation = "None";
		private static final int depthBeginColorIndex = ColorLib.rgb(80,80,80);
		private static final int depthEndColorIndex = ColorLib.rgb(200,200,120);
		private static final int complexityBeginColorIndex = ColorLib.rgb(220,220,220);
		private static final int complexityEndColorIndex = ColorLib.rgb(220,40,40);
		private static HashMap<String, Integer> m_metricsMaxValue;

        /**
         * Node Renderer draws of fills the nodes
         * @param treeMapVisualization the tree map visualization
         * @param depth depth max of the tree
         */
        public TreeMapNodeRenderer(TreeMapVisualization treeMapVisualization, int depth, HashMap<String, Integer> metricsMaxValue) {
            m_manageBounds = false;
		    m_cmap = new ColorMap(ColorLib.getInterpolatedPalette(depth+1, depthBeginColorIndex, depthEndColorIndex), 0, depth);
		    m_leafmap = new ColorMap(ColorLib.getInterpolatedPalette(70, complexityBeginColorIndex, complexityEndColorIndex), 0, 70);
		    m_treeMapVisualization = treeMapVisualization;
		    m_metricsMaxValue = metricsMaxValue;
        }

        /* (non-Javadoc)
         * @see prefuse.render.AbstractShapeRenderer#render(java.awt.Graphics2D, prefuse.visual.VisualItem)
         */
        public void render(Graphics2D g, VisualItem item) {
        	Shape shape = getRawShape(item);
        	fillNodes(g, item, shape);
        	fillLinks(g, item, shape);
        	fillTexture(g, item, shape);
        	drawText(g, item, shape);
        	animateBorder(g, item, shape);
        }

        /**
         * fill the nodes with colors according to depth or complexity value. (complexity is an optional metric)
         * @param g java graphics
         * @param item the prefuse visual item to be drawn
         * @param shape the shape to draw, it represents the item
         */
        private void fillNodes(Graphics2D g, VisualItem item, Shape shape){
        	int value = 0 ;

            if ( m_treeMapVisualization.getVisualization().isInGroup(item, Visualization.SEARCH_ITEMS)){
            	g.setPaint(ColorLib.getColor(0, 170, 170));
               	g.fill(shape);

        	}
            else if(item.getString("type").equals("leaf")){
				if (!m_selectedLeavesColorRepresentation.equals("None")){
					if(item.canGet("Loc",Integer.TYPE) && m_selectedLeavesColorRepresentation.equals("Loc")){
						value = item.getInt("Loc");
					}
					else if(item.canGet("optionalMetrics", String.class) ){
						String optionalMetrics = item.getString("optionalMetrics");
						String[] optionalMetric = optionalMetrics.split(";");
						for(String nextMetric : optionalMetric){
							String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
							String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
							try{
								if(metricName.equals(m_selectedLeavesColorRepresentation)){
									value = Integer.valueOf(metricValue);
								}
							} catch (Exception e){
								e.printStackTrace();
							}
						}
					}
	                int maxValueMetric =  m_metricsMaxValue.get(m_selectedLeavesColorRepresentation);
	                m_leafmap = new ColorMap(ColorLib.getInterpolatedPalette(maxValueMetric, complexityBeginColorIndex, complexityEndColorIndex), 0, maxValueMetric);
		            g.setPaint(new Color(m_leafmap.getColor(value)));
		            g.fill(shape);
        		} else {
	            	NodeItem nitem = (NodeItem)item;
	           		g.setPaint(new Color(m_cmap.getColor(nitem.getDepth())));
	           		g.fill(shape);
	           	}
        	} else{
            	NodeItem nitem = (NodeItem)item;
           		g.setPaint(new Color(m_cmap.getColor(nitem.getDepth())));
           		g.fill(shape);
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
         * fills the nodes with a transparent texture to represent an additional metric
         * @param g java graphics
         * @param item the prefuse visual item to be drawn
         * @param shape the shape to draw, it represents the item
         */
        private void fillTexture(Graphics2D g, VisualItem item, Shape shape){
        	int value = 0 ;
        	float alpha = 0;
        	int maxValueMetric = 0;
        	if(item.getString("type").equals("leaf") && !m_selectedLeavesTextureRepresentation.equals("None")){
				if(item.canGet("Loc",Integer.TYPE) && m_selectedLeavesTextureRepresentation.equals("Loc")){
					value = item.getInt("Loc");
				} else if(item.canGet("optionalMetrics", String.class)){
                	String optionalMetrics = item.getString("optionalMetrics");
                    String[] optionalMetric = optionalMetrics.split(";");
                    for(String nextMetric : optionalMetric){
                    	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
                    	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
                    	try{
							if (metricName.equals(m_selectedLeavesTextureRepresentation)) {
	                    		value = Integer.valueOf(metricValue);
							}
                    	} catch (Exception e){
                    		e.printStackTrace();
                    	}
                    }
        		}
				BufferedImage bufferedImage = new BufferedImage(10, 10,BufferedImage.BITMASK);
				Graphics2D bufferedImageGraphics = bufferedImage.createGraphics();
				maxValueMetric =  m_metricsMaxValue.get(m_selectedLeavesTextureRepresentation);
				if(maxValueMetric <= 10){
					alpha = (float)(value*0.1);
				} else if (maxValueMetric <= 150) {
					alpha = (float)(value*0.01);
				} else  {
					alpha = (float)(value*0.001);
				}
				if (alpha >= 1.0) alpha = 1.0f;
				bufferedImageGraphics.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC, alpha));
				bufferedImageGraphics.setColor(Color.BLACK);
				bufferedImageGraphics.setStroke(new BasicStroke (1.5F, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL));
				bufferedImageGraphics.drawLine(0, 0, 10, 10);
				Rectangle r = new Rectangle(0, 0, 10, 10);
				g.setPaint(new TexturePaint(bufferedImage, r));
				g.fill(shape);
        	}
        }

        /**
         * sets the text labels of the nodes, these labels represents values of a specific metric
         * @param g java graphics
         * @param item the prefuse visual item to be drawn
         * @param shape the shape to draw, it represents the item
         */
        private void drawText(Graphics2D g, VisualItem item, Shape shape){
        	int value = 0 ;
        	if(item.getString("type").equals("leaf") && !m_selectedLeavesNumberRepresentation.equals("None")){
				if(item.canGet("Loc",Integer.TYPE) && m_selectedLeavesNumberRepresentation.equals("Loc")){
					value = item.getInt("Loc");
				} else if(item.canGet("optionalMetrics", String.class) ){
                	String optionalMetrics = item.getString("optionalMetrics");
                    String[] optionalMetric = optionalMetrics.split(";");
                    for(String nextMetric : optionalMetric){
                    	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
                    	String metricValue = nextMetric.substring(nextMetric.indexOf(",")+1);
                    	try{
                    	} catch (Exception e){
                    		e.printStackTrace();
                    	}

                    	if (metricName.equals(m_selectedLeavesNumberRepresentation)) {
	                    	value = Integer.valueOf(metricValue);

                    	}
                    }
        		}
				g.setPaint(Color.WHITE);
				int width = 0;
				if(value < 10 ){
					width = 5;
				} else if (value >= 10 && value < 100){
					width = 10;
				} else if (value >= 100 && value < 1000 ){
					width = 15;
				} else if (value >= 1000){
					width = 20;
				}
				g.fillRect((int)item.getBounds().getCenterX(), (int)item.getBounds().getCenterY()-9, width, 10);
				g.setPaint(Color.BLACK);
				g.setFont(FontLib.getFont("Tahoma", Font.PLAIN, 10));
				g.drawString(value+"", (int)item.getBounds().getCenterX(), (int)item.getBounds().getCenterY());
        	}
        }

        /**
         * switches nodes boarder-color between white an black
         * @param g java standard graphics
         * @param item the prefuse visual item to be drawn
         * @param shape the shape to draw, it represents the item
         */
        private void animateBorder(Graphics2D g, VisualItem item, Shape shape){
        	if(item.isHover()){
            	g.setPaint(Color.WHITE);
            	g.draw(shape);
        	} else {
        		g.setPaint(Color.BLACK);
        		g.draw(shape);
        	}
        }

        /* (non-Javadoc)
         * @see prefuse.render.AbstractShapeRenderer#getRawShape(prefuse.visual.VisualItem)
         */
        protected Shape getRawShape(VisualItem item) {
        	Rectangle2D itemBounds = item.getBounds();
		   // m_roundRect.setRoundRect(itemBounds.getX(),itemBounds.getY(),itemBounds.getWidth(),itemBounds.getHeight(),(double)10,(double)10);
		   // return m_roundRect;

		    m_Rect.setRect(itemBounds.getX(),itemBounds.getY(),itemBounds.getWidth(),itemBounds.getHeight());
		    return m_Rect;
        }

        /**
         *
         * @param selectedMetric the selected metric by the color combobox
         */
        public void setLeavesColorRepresentation(String selectedMetric){
        	m_selectedLeavesColorRepresentation = selectedMetric;
        	m_treeMapVisualization.update();
        }

        /**
         * @param selectedMetric the selected metric by the number combobox
         */
        public void setLeavesNumberRepresentation(String selectedMetric){
        	m_selectedLeavesNumberRepresentation = selectedMetric;
        	m_treeMapVisualization.update();
        }

        /**
         * @param selectedMetric the selected metric by the texture combobox
         */
        public void setLeavesTextureRepresentation(String selectedMetric){
        	m_selectedLeavesTextureRepresentation = selectedMetric;
        	m_treeMapVisualization.update();
        }
    } // end of inner class NodeRenderer
