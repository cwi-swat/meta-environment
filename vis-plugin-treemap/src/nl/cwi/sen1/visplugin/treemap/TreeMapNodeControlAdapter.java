package nl.cwi.sen1.visplugin.treemap;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;

import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import prefuse.controls.ControlAdapter;
import prefuse.visual.VisualItem;
import prefuse.data.Node;
import prefuse.data.Tree;


/**
 * handles the nodes control events like clicking on the nodes
 * @author Qais
 *
 */
public class TreeMapNodeControlAdapter extends ControlAdapter {
	static JTextArea m_metricArea;
	static JTextPane m_codeOverviewArea;
	static final Color basicLevelComplexityColor = new Color(255,255,255);
	static final Color firstLevelComplexityColor = new Color(150,150,150);
	static final Color secondLevelComplexityColor = new Color(200,170,170);
	static final Color thirdLevelComplexityColor = new Color(200,150,150);
	static final Color forthLevelComplexityColor = new Color(200,130,130);
	static final Color fifthLevelComplexityColor = new Color(200,110,110);
	static final Color sixthLevelComplexityColor = new Color(200,80,80);
	static final Color seventhLevelComplexityColor = new Color(200,60,60);
	static int m_itemClickCount = 0;
	static int m_leftClicked = 0;
	static boolean nodeItemClicked = false;
	static String m_filePath;
	static JTextPane m_codeArea;
	static String m_selectedLeavesColorRepresentation = "None";
	static String m_setMetric= "setNone";
	private Tree m_tree;
	TreeMapVisualization m_treeMapVisualization;

	/**
	 * handles the controls and updates the two textArea views textArea and metricArea
	 * @param codeOverviewArea code overview area
	 * @param metricArea metric overview area
	 */
	public TreeMapNodeControlAdapter(TreeMapVisualization treeMapVisualization, Tree tree, JTextPane codeOverviewArea, JTextArea metricArea){
		m_tree = tree;
		m_codeOverviewArea = codeOverviewArea;
		m_metricArea = metricArea;
	    m_treeMapVisualization = treeMapVisualization;
	}

	/* (non-Javadoc)
	 * @see prefuse.controls.ControlAdapter#itemClicked(prefuse.visual.VisualItem, java.awt.event.MouseEvent)
	 */
	public void itemClicked(VisualItem item, MouseEvent e){
		if (e.getButton() == MouseEvent.BUTTON3){
			if(item.getString("type").equals("leaf") && item.canGet("setLinks", String.class)){
				m_leftClicked++;
				if(m_leftClicked %2 == 0){
					removeAllLinks(m_tree.getRoot());
				}
				else{
					String links = item.getString("setLinks");
					String[] linkNodes = links.split(";");
					for (String link : linkNodes){
						Node nextLink = getLastPathNode(m_tree, link);
						if(nextLink.canGet("linked", Integer.TYPE)){
								nextLink.setInt("linked", 2);
						}
					}
					if(item.canGet("linked", Integer.TYPE)){
						item.setInt("linked", 1);
						m_treeMapVisualization.update();
					}

				}
			}
		}
		else{
			if(item.getString("type").equals("leaf")){
				m_itemClickCount++;
			}
			if (m_itemClickCount % 2 == 0){
				nodeItemClicked = false;
				this.itemExited(item, e);
			} else {
				nodeItemClicked = true;
			}
		}
	}

	/**
	 * reset all by links colorified nodes
	 * @param nextNode
	 */
	private void removeAllLinks(Node nextNode){
		Iterator<Node> iter = nextNode.children();
		while(iter.hasNext()){
			Node node = iter.next();
			if(node.canGet("linked", Integer.TYPE)){
				node.setInt("linked", 0);
			}
			removeAllLinks(node);
		}
		m_treeMapVisualization.update();
	}

	/**
	 * finds the tree file-node (last hierarchy node) from a given tree
	 * @param tree the nodes-tree
	 * @param filePath the path to a specific node ( specific file)
	 * @return
	 */
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


    /* (non-Javadoc)
     * @see prefuse.controls.ControlAdapter#itemEntered(prefuse.visual.VisualItem, java.awt.event.MouseEvent)
     */
    public void itemEntered(VisualItem item, MouseEvent e) {
    	if(nodeItemClicked){
    		return;
    	}
        String optionalMetrics = "";
        m_metricArea.append(" Name : "+item.getString("name")+"\n");
        if(item.getString("type").equals("leaf")){
            m_metricArea.append(" Type : file\n");
        } else{
            m_metricArea.append(" Type : directory\n");
        }
        m_metricArea.append(" Path : "+item.getString("path")+"\n");
        m_metricArea.append(" LOC : "+item.getString("Loc")+"\n");
        if(item.canGetString("optionalMetrics") && item.getString("type").equals("leaf")){
        	optionalMetrics = item.getString("optionalMetrics");
            // all other metrics
            String[] optionalMetric = optionalMetrics.split(";");
            for(String otherMetric : optionalMetric){
            	String metricName = otherMetric.substring(0, otherMetric.indexOf(","));
            	String metricValue = otherMetric.substring(otherMetric.indexOf(",")+1);
                m_metricArea.append(" "+metricName+" : "+metricValue+"\n");
                if(metricName.equals(m_selectedLeavesColorRepresentation)){
                	m_setMetric = "set" + metricName;
                } else{
                	m_setMetric = "set" + m_selectedLeavesColorRepresentation;
                }

            }
        }
        // for windows OS just to test the application at home
        //String temp = item.getString("path").replace("/", "\\");
       // m_filePath = "C"+temp.substring(1);
        //m_filePath = "D:"+item.getString("path").replace("/", "\\");
        m_filePath = item.getString("path").substring(1);
        String str;
        try {
        	File file = new File(m_filePath);
        	String path = file.getCanonicalPath();
        	m_codeArea = new JTextPane();
            BufferedReader in = new BufferedReader(new FileReader(path));
            StyledDocument doc = (StyledDocument)m_codeOverviewArea.getDocument();
            Style basic = doc.addStyle("basic", null);
            StyleConstants.setFontSize(basic, 2);
            StyledDocument codeDoc = (StyledDocument)m_codeArea.getDocument();
            Style codeBasic = codeDoc.addStyle("codeBasic", null);
            String[] methods = null;
            if(item.canGet(m_setMetric, String.class)){
            	methods = item.getString(m_setMetric).split(";");
            }
            int lineNumber = 1;
            int totalLengthForViewer = 0;
            int totalLength = 0;
            String space = "";
            while ((str = in.readLine()) != null) {
            	if(lineNumber < 10) space = "     ";
            	else if(lineNumber < 100) space = "    ";
            	else if(lineNumber < 1000) space = "   ";
            	else if(lineNumber < 10000) space = "  ";
            	else space = " ";
            	appendToTextPane(doc, getStrepLine(str)+"\n", basic);
            	appendToTextPane(codeDoc, lineNumber+space+str+"\n", codeBasic);
            	int spaceLength = str.length()- str.trim().length();
            	int charsLength = str.length() - spaceLength;
            	Color color = getComplexityColor(methods, lineNumber, 1);
               	doc.setCharacterAttributes(totalLength+spaceLength, charsLength, getOverviewStyle(doc, color), false);
                color = getComplexityColor(methods, lineNumber, 2);
               	codeDoc.setCharacterAttributes(totalLengthForViewer+spaceLength+6, charsLength+6, getCodeStyle(codeDoc, color), false);
                totalLength += str.length()+1;
                totalLengthForViewer += str.length()+1+6;
            	lineNumber++;
            }
            in.close();
        } catch (Exception ee) {
        }
    }

    /**
     * return a color to colorize a given line of code
     * it determines the color according to the complexity of the methods
     * @param methods methods with there complexity
     * @param lineNumber linenumber of the code
     * @return
     */
    private Color getComplexityColor(String[] methods, int lineNumber, int i){
    	int colorIndex = 0;
    	Color color;

    	colorIndex = getColorIndex(methods, lineNumber);

    	//initiate the basic color

		if(i == 1){
			color = firstLevelComplexityColor;
		} else {
			color = basicLevelComplexityColor;
		}

    	if(colorIndex >= 10 && colorIndex < 20)
    		color = secondLevelComplexityColor;
    	else if(colorIndex >= 20 && colorIndex < 30)
    		color = thirdLevelComplexityColor;
    	else if(colorIndex >= 30 && colorIndex < 40)
    		color = forthLevelComplexityColor;
    	else if(colorIndex >= 40 && colorIndex < 50)
    		color = fifthLevelComplexityColor;
    	else if(colorIndex >= 50 && colorIndex < 60)
    		color = sixthLevelComplexityColor;
    	else if(colorIndex >= 60 )
    		color = seventhLevelComplexityColor;;
    	return color;
    }

    /**
     * return an integer representing the color index to colorize
     * a given linecode according to methods and there complexity
     * @param methods
     * @param lineNumber
     * @return
     * @throws IOException
     */
    private int getColorIndex(String[] methods, int lineNumber) {
    	int colorIndex = 0;
    	try{
    		if(methods != null){
    			for(String nextMethod : methods){
    				String[] method = nextMethod.split(",");
    				if(lineNumber >= Integer.valueOf(method[0]) && lineNumber <= Integer.valueOf(method[1])){
    					colorIndex = Integer.valueOf(method[2]);
    				}
    			}
    		}
		}catch(Exception e){}
    	return colorIndex;
    }

    /**
     * return the default style of the code overview panel
     * with the given doc and the color
     */
    private Style getOverviewStyle(StyledDocument doc, Color color){
        Style style = doc.addStyle("", null);
        StyleConstants.setFontSize(style, 2);
        StyleConstants.setBackground(style, color);
        return style;
    }

    /**
     * return the default style of the code overview panel
     * with the given doc and the color
     */
    private Style getCodeStyle(StyledDocument doc, Color color){
        Style style = doc.addStyle("", null);
        StyleConstants.setBackground(style, color);
        return style;
    }



    /**
     * return a strepline text with same length of the codeline text
     * @param line line of code text
     * @return the string with scorelines
     */
    private String getStrepLine(String line){
    	String temp = "";
    	int beginSpaces = line.length() - line.trim().length();
    	for(int i=0; i <line.length(); i++){
    		if(i < beginSpaces){
    			temp += " ";
    		} else{
    			temp += "-";
    		}
    	}
    	return temp;
    }

    /**
     * @param doc the document to add the text
     * @param text text to be added
     * @param style style of the text to be appended
     */
    private void appendToTextPane(StyledDocument doc, String text, Style style){
    	try{
    		doc.insertString(doc.getLength(), text, style);
    	} catch (Exception e) {
    		e.printStackTrace();
    	}
    }

    /* (non-Javadoc)
     * @see prefuse.controls.ControlAdapter#itemExited(prefuse.visual.VisualItem, java.awt.event.MouseEvent)
     */
    public void itemExited(VisualItem item, MouseEvent e) {
    	if(nodeItemClicked){
    		return;
    	}
        m_codeOverviewArea.setText(null);
        m_metricArea.setText(null);
    }

    public String getFilePath(){
    	return m_filePath;
    }

    public JTextPane getCodeDoc(){
    	return m_codeArea;
    }
    public void setLeavesColorRepresentation(String selectedMetric){
    	m_selectedLeavesColorRepresentation = selectedMetric;
    }
}
