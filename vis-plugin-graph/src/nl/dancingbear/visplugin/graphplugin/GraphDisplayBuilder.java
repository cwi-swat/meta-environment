
package nl.dancingbear.visplugin.graphplugin;

import nl.cwi.sen1.gui.plugin.prefusedot.DotAdapter;
import nl.cwi.sen1.gui.plugin.prefusedot.DotEdgeRenderer;
import nl.cwi.sen1.gui.plugin.prefusedot.DotLayout;
import nl.cwi.sen1.gui.plugin.prefusedot.DotNodeRenderer;
import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.assignment.ColorAction;
import prefuse.action.assignment.FontAction;
import prefuse.action.layout.graph.NodeLinkTreeLayout;
import prefuse.controls.DragControl;
import prefuse.controls.FocusControl;
import prefuse.controls.PanControl;
import prefuse.controls.WheelZoomControl;
import prefuse.controls.ZoomControl;
import prefuse.data.Graph;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.render.RendererFactory;
import prefuse.util.ColorLib;
import prefuse.visual.VisualItem;

/**
 * Builder to create a display (formatting, colors and layout) for a graph.
 * 
 * @author A. Belgraver
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007  
 */
public class GraphDisplayBuilder {
    
    private final static int BREADTHSPACING = 30;
	private DotLayout dotLayout;

    /**
     * Main method for the graph creation.
     *
     * @param graph the graph to be displayed.
     * @return
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007  
     */
    public Display createDisplayFromGraph(Graph graph){

        // Setup the visualization type and renderer
        Visualization vis = new Visualization();
        vis.addGraph(GraphConstants.GRAPH, graph);
        RendererFactory drf = createRenderers();
        vis.setRendererFactory(drf);

        // Add the nodes and give them a color
        ActionList colors = createColorActions();
        ActionList layout = createLayoutActions();

        // Add the actions available for this graph.
        vis.putAction(GraphConstants.COLOR, colors);
        vis.putAction(GraphConstants.LAYOUT, layout);

        // Setup the display in which to display the graph
        Display display = createDisplay(vis);

        // Start the graph.
        vis.run(GraphConstants.COLOR);
        vis.run(GraphConstants.LAYOUT);

        return display;
    }

    /**
     * Construct a renderer factory that contains renderers that will
     * render all components of a graph on the screen.
     * 
     * @return a rendererfactory that will render the graph's components
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007  
     */
    private RendererFactory createRenderers() {
        // The the name labels for NodeItems have to be rendered using
        // a labelrenderer. The column to show is conveniently called "label"
        LabelRenderer lr = new DotNodeRenderer(DotAdapter.DOT_LABEL);
        EdgeRenderer er = new DotEdgeRenderer(Constants.EDGE_TYPE_LINE, Constants.EDGE_ARROW_FORWARD);
        
        // Create a new default renderer factory
        DefaultRendererFactory drf = new DefaultRendererFactory(lr, er);
        
        return drf;
    }

    /**
     * Set the color for the nodes, if no color is set they will be black and white.
     * 
     * @return ActionList holding needed color actions.
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007  
     */
    private ActionList createColorActions() {
        // Text options.
        ColorAction text = new ColorAction(GraphConstants.NODES, VisualItem.TEXTCOLOR,
                ColorLib.gray(0));
        text.setDefaultColor(GraphConstants.TEXTCOLOR);
        FontAction nFont = new FontAction(GraphConstants.NODES, GraphConstants.NODE_FONT);

        // Outer line color.
        ColorAction nStroke = new ColorAction(GraphConstants.NODES,
                VisualItem.STROKECOLOR);
        nStroke.setDefaultColor(GraphConstants.NODE_LINECOLOR);

        // Fill color.
        ColorAction nFill = new ColorAction(GraphConstants.NODES, VisualItem.FILLCOLOR);
        nFill.setDefaultColor(GraphConstants.NODE_FILLCOLOR);

        // Edge lines and heads.
        ColorAction nEdges = new ColorAction(GraphConstants.EDGES, VisualItem.STROKECOLOR);
        nEdges.setDefaultColor(GraphConstants.ARROWCOLOR);
        ColorAction nHeads = new ColorAction(GraphConstants.EDGES, VisualItem.FILLCOLOR);
        nHeads.setDefaultColor(GraphConstants.ARROWCOLOR);

        // Bundle the color actions in an actionlist.
        ActionList colors = new ActionList();
        colors.add(text);
        colors.add(nFont);
        colors.add(nStroke);
        colors.add(nFill);
        colors.add(nEdges);
        colors.add(nHeads);
        colors.add(new RepaintAction());
        
        return colors;
    }

    /**
     * Create the layout and actions for the graph.
     * 
     * @return ActionList used to place the graph on the screen
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007  
     */
    private ActionList createLayoutActions() {
        dotLayout = new DotLayout(GraphConstants.GRAPH);

        // Create an actions avaible for the graph.
        ActionList layout = new ActionList();
        layout.add(dotLayout);

        // Repaint the screen to activate the changes.
        layout.add(new RepaintAction());
        return layout;

    }

    /**
     * Create and configure the visualization display.
     * 
     * @param vis The visualisation to display
     * @return A configured display object
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007  
     */
    private Display createDisplay(Visualization vis) {
        Display d = new Display(vis);
        
        // Anti aliasing on
        d.setHighQuality(true);

        // Allow manipulation of those nodes while visible in the panel
        d.addControlListener(new FocusControl());
        d.addControlListener(new DragControl());
        d.addControlListener(new PanControl());
        
        // Allowing zooming in the panel.
        d.addControlListener(new ZoomControl());
        d.addControlListener(new WheelZoomControl());
        
        return d;
    }


}
