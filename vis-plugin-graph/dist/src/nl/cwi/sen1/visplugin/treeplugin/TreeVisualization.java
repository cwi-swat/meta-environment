package nl.cwi.sen1.visplugin.treeplugin;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.geom.Point2D;
import java.util.Iterator;
import java.util.Vector;
import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.ItemAction;
import prefuse.action.RepaintAction;
import prefuse.action.animate.ColorAnimator;
import prefuse.action.animate.LocationAnimator;
import prefuse.action.animate.QualityControlAnimator;
import prefuse.action.assignment.ColorAction;
import prefuse.action.filter.FisheyeTreeFilter;
import prefuse.action.layout.CollapsedSubtreeLayout;
import prefuse.action.layout.graph.NodeLinkTreeLayout;
import prefuse.activity.SlowInSlowOutPacer;
import prefuse.controls.DragControl;
import prefuse.controls.PanControl;
import prefuse.controls.WheelZoomControl;
import prefuse.controls.ZoomControl;
//import prefuse.controls.FocusControl;
import prefuse.data.Node;
import prefuse.data.Tree;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.util.ColorLib;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;
import prefuse.visual.sort.TreeDepthItemSorter;
import prefuse.controls.ToolTipControl;
import javax.swing.ToolTipManager;
import java.util.HashMap;
import prefuse.data.query.SearchQueryBinding;
import prefuse.Visualization;
import prefuse.visual.VisualTree;
import java.awt.event.MouseEvent;
import prefuse.visual.VisualItem;

/**
 *
 *
 * @author Qais
 */
@SuppressWarnings("serial")
public class TreeVisualization extends Display {

    private static String tree = "tree";
    private static String treeNodes = "tree.nodes";
    private static String treeEdges = "tree.edges";
    private static final String labels = "name";
    private static Tree m_tree;
    private static TreeNodeRenderer m_treeNodeRenderer;
    private static EdgeRenderer m_edgeRenderer;
    private static int m_viewHierarchyLevel = 1;
    private static int m_orientation = Constants.ORIENT_TOP_BOTTOM;
    private static HashMap<String, Integer> m_metricsMaxValues;
    private static SearchQueryBinding searchQ;
    private static NodeLinkTreeLayout treeLayout;
    private static FisheyeTreeFilter m_fisheyeTreeFilter;
    private static CollapsedSubtreeLayout subLayout;
    private static VisualTree vt;

    /**
     * Constructor of the tree, initialize a tree with a specific layout and sets
     * the colors and filter
     * @param tree the tree
     */
    public TreeVisualization(Tree t, HashMap<String, Integer> metricsMaxValues) {
        super(new Visualization());
        m_tree =t;
        m_metricsMaxValues = metricsMaxValues;
        init();
    }

    /**
     * initialize the display components, adds filters and control listeners
     */
    @SuppressWarnings("unchecked")
    private void init(){
        vt = m_vis.addTree(tree, m_tree);
        m_edgeRenderer = new EdgeRenderer(Constants.EDGE_TYPE_LINE);

        m_treeNodeRenderer =  new TreeNodeRenderer(m_tree, this, getTreeDepth(), m_metricsMaxValues);
        DefaultRendererFactory rf = new DefaultRendererFactory();

        rf.add(new InGroupPredicate(treeEdges), m_edgeRenderer);
        rf.add(new InGroupPredicate(treeNodes), m_treeNodeRenderer);
        m_vis.setRendererFactory(rf);

        ItemAction edgeColor = new ColorAction(treeEdges,VisualItem.STROKECOLOR, ColorLib.rgb(10,10,10));

        // create the tree layout action
        treeLayout = new NodeLinkTreeLayout(tree,m_orientation, 300, 5, 4);
        treeLayout.setLayoutAnchor(new Point2D.Double(300,300));
        m_vis.putAction("treeLayout", treeLayout);

        subLayout = new CollapsedSubtreeLayout(tree, m_orientation);
        m_vis.putAction("subLayout", subLayout);

        // create the filtering and layout
        ActionList filter = new ActionList();
        m_fisheyeTreeFilter = new FisheyeTreeFilter(tree, m_viewHierarchyLevel);
        filter.add(m_fisheyeTreeFilter);
        filter.add(treeLayout);
        filter.add(subLayout);
        filter.add(edgeColor);
        m_vis.putAction("filter", filter);

        // animated transition
        ActionList animate = new ActionList(1000);
        animate.add(new QualityControlAnimator());
        animate.add(new RepaintAction());
        m_vis.putAction("animate", animate);
        m_vis.alwaysRunAfter("filter", "animate");

        // create animator for orientation changes
        ActionList orient = new ActionList(2000);
        orient.setPacingFunction(new SlowInSlowOutPacer());
        orient.add(new QualityControlAnimator());
        orient.add(new LocationAnimator(treeNodes));
        orient.add(new RepaintAction());

        this.setItemSorter(new TreeDepthItemSorter());
        this.addControlListener(new DragControl());
        this.addControlListener(new ZoomControl());
        this.addControlListener(new WheelZoomControl());
        this.addControlListener(new PanControl());
        this.addControlListener(new FocusControl(1, "filter"));

    	searchQ = new SearchQueryBinding(vt.getNodeTable(), labels);
        m_vis.addFocusGroup(Visualization.SEARCH_ITEMS, searchQ.getSearchSet());


        this.addControlListener(new ToolTipControl("name"));
       	ToolTipManager.sharedInstance().setInitialDelay(0);

        // filter graph and perform Top-down layout
        setOrientation(m_orientation);
        // initialize the display
        setSize(900,900);
        m_vis.run("filter");

    }

    public SearchQueryBinding getSearchQuery() {
	   return searchQ;
	}


    /**
     * sets the top-down orientation for the tree
     * @param orientation
     */
    private void setOrientation(int orientation) {
        NodeLinkTreeLayout rtl = (NodeLinkTreeLayout)m_vis.getAction("treeLayout");
        CollapsedSubtreeLayout stl = (CollapsedSubtreeLayout)m_vis.getAction("subLayout");
        m_edgeRenderer.setHorizontalAlignment1(Constants.CENTER);
        m_edgeRenderer.setHorizontalAlignment2(Constants.CENTER);
        m_edgeRenderer.setVerticalAlignment1(Constants.BOTTOM);
        m_edgeRenderer.setVerticalAlignment2(Constants.TOP);
        rtl.setOrientation(orientation);
        stl.setOrientation(orientation);
    }

    public TreeNodeRenderer getTreeNodeRenderer(){
    	return m_treeNodeRenderer;
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
    	optionalMetricNames.add("None");
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

    /**
     * expands the view level of the tree
     * @param level
     */
    public void setViewHierarchyLevel(int level){
    	m_viewHierarchyLevel = level;
    	m_fisheyeTreeFilter.setDistance(m_viewHierarchyLevel);
    	update();
    }

    /**
     * hides or shows the node labels
     * @param isHide boolean value hides or shows the node labels
     */
    public void update(){
       	m_fisheyeTreeFilter.run();
        treeLayout.run();
       	this.repaint();
        m_vis.repaint();

    }

    /**
     * counts the depth of the tree
     * @return integer value represents the depth of the tree
     */
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

} // end of class TreeMap
