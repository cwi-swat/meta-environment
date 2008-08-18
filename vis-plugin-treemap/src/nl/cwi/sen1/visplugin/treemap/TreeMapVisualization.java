package nl.cwi.sen1.visplugin.treemap;

import java.awt.Color;
import java.awt.event.MouseEvent;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Vector;
import javax.swing.ToolTipManager;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.animate.ColorAnimator;
import prefuse.controls.ControlAdapter;
import prefuse.controls.ToolTipControl;
import prefuse.data.Node;
import prefuse.data.Tree;
import prefuse.data.query.SearchQueryBinding;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.LabelRenderer;
import prefuse.visual.VisualItem;
import prefuse.visual.VisualTree;
import prefuse.visual.expression.InGroupPredicate;
import prefuse.visual.sort.TreeDepthItemSorter;

/**
 * TreeMap layout of a hierarchical data represents an existing software system
 *
 * @author Qais
 */
@SuppressWarnings("serial")
public class TreeMapVisualization extends Display {


    private static final String tree = "tree";
    private static final String treeNodes = "tree.nodes";
    private static final String treeEdges = "tree.edges";
    private static final String labels = "labels";
    private static int m_padding;
    private static Tree m_tree;
    private static String m_label;
    private static TreeMapLayout treeMapLayout;
    private static TreeMapNodeRenderer m_treeMapNodeRenderer;
    private static ZoomToFitControl zoomToFitControl = new ZoomToFitControl();
    private static HashMap<String, Integer> m_metricsMaxValues;
    private static SearchQueryBinding searchQ;

    /**
     * Constructor of the treemap, initialize a tree map with a specific layout and sets
     * the colors and filter
     * @param tree the tree
     * @param label label refrence
     */
    public TreeMapVisualization(Tree tree, String label, int padding, HashMap<String, Integer> metricsMaxValues) {
        super(new Visualization());
        m_tree = tree;
        m_label = label;
        m_padding = padding;
        m_metricsMaxValues = metricsMaxValues;
        init();
    }

    /**
     * sets the space value between a node and its parent
     * @param padding space value between a node and its parent
     */
    public void updatePadding(int padding){
        m_padding = padding;
        this.update();
    }


    /**
     * updates the display by removing all display-components and creating new components because
     * changing intern values of filters and controllers and then repainting the display does not work !!! (maybe Prefuse bug)
     */
    public void update(){
        treeMapLayout.setFrameWidth(m_padding);
        treeMapLayout.run();
        this.repaint();
        m_vis.repaint();
    }

    /**
     * initialize the display components, adds filters and control listeners
     */
    @SuppressWarnings("unchecked")
	private void init(){
    	treeMapLayout = new TreeMapLayout(tree, m_padding);

        // add the tree to the visualization
        VisualTree vt = m_vis.addTree(tree, m_tree);
        m_vis.setVisible(treeEdges, null, false);

        // set up the renderers - one for nodes and one for labels
        DefaultRendererFactory rf = new DefaultRendererFactory();
        m_treeMapNodeRenderer = new TreeMapNodeRenderer(this, getTreeDepth(), m_metricsMaxValues);
        rf.add(new InGroupPredicate(treeNodes), m_treeMapNodeRenderer);
        rf.add(new InGroupPredicate(labels), new LabelRenderer(m_label));
        m_vis.setRendererFactory(rf);

        // animate paint change
        ActionList animatePaint = new ActionList(777);
        animatePaint.add(new ColorAnimator(treeNodes));
        animatePaint.add(new RepaintAction());
        m_vis.putAction("animatePaint", animatePaint);

        // create the single filtering and layout action list
        ActionList layout = new ActionList();
        layout.add(treeMapLayout);
        layout.add(new TreeMapLabelLayout(labels,0,5));
        layout.add(new RepaintAction());
        m_vis.putAction("layout", layout);

        setItemSorter(new TreeDepthItemSorter(true));

        addControlListener(new ControlAdapter() {
            public void itemEntered(VisualItem item, MouseEvent e) {
                item.getVisualization().repaint();
            }
            public void itemExited(VisualItem item, MouseEvent e) {
                item.getVisualization().repaint();
            }
        });

    	searchQ = new SearchQueryBinding(vt.getNodeTable(), m_label);
        m_vis.addFocusGroup(Visualization.SEARCH_ITEMS, searchQ.getSearchSet());

        this.addControlListener(new ToolTipControl("name"));
       	ToolTipManager.sharedInstance().setInitialDelay(0);


//	    this.addControlListener(zoomToFitControl);
//	    this.addControlListener(new WheelZoomControl());
//	    this.addControlListener(new PanControl());


        setSize(760,700);
        // perform layout
        setBackground(Color.WHITE);

        m_vis.run("layout");

// to fit the visualization size to the windows size :(  not working
//        MouseEvent event = new MouseEvent( this, MouseEvent.MOUSE_CLICKED, 0, MouseEvent.BUTTON2, 0, 0, 1, false );
//        zoomToFitControl.mouseClicked(event);

    }


    public SearchQueryBinding getSearchQuery() {
	    return searchQ;
    }

    /**
     * counts the depth of the tree
     * @return integer value represents the depth of the tree
     */
    @SuppressWarnings("unchecked")
	private int getTreeDepth(){
    	int depth = 0;
    	Iterator<Node> iter = m_tree.nodes();
    	while (iter.hasNext()) {
    	    Node n = (Node) iter.next();
    	    int d = n.getDepth();
    	    if (d>depth) {
    		depth=d;
    	    }
    	}
    	return depth;
    }

    /**
     * returns the standard node Renderer
     * @return TreeNodeRender
     */
    public TreeMapNodeRenderer getTreeMapNodeRenderer(){
    	return m_treeMapNodeRenderer;
    }

    public ZoomToFitControl getZoomToFitControl(){
    	return zoomToFitControl;
    }

    /**
     * returns the names of all optional metrics (if they exist)
     * @return the names of all optional metrics
     */
    @SuppressWarnings("unchecked")
	public Vector<String> getOptionalMetrics(){
    	Iterator<Node> iter = m_tree.nodes();
    	Node nextNode = m_tree.getRoot();
    	Vector<String> optionalMetricNames = new Vector<String>();
    	optionalMetricNames.add("Loc");
    	while (iter.hasNext()) {
    	    nextNode = (Node) iter.next();
    	}
    	if(nextNode.canGet("optionalMetrics", String.class)){
        	String optionalMetrics = nextNode.getString("optionalMetrics");
            String[] optionalMetric = optionalMetrics.split(";");
            for(String nextMetric : optionalMetric){
            	String metricName = nextMetric.substring(0, nextMetric.indexOf(","));
            	optionalMetricNames.add(metricName);
            }
    	}
    	return optionalMetricNames;
    }

    public void updateLayoutSelectedMetric(String selectedMetric){
		treeMapLayout.updateSelectedMetric(selectedMetric);
		this.update();
	}

} // end of class TreeMap
