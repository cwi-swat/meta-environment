
package nl.dancingbear.visplugin.graphplugin;

import java.awt.event.MouseEvent;

import nl.cwi.sen1.gui.plugin.prefusedot.DotEdgeRenderer;
import nl.cwi.sen1.gui.plugin.prefusedot.DotLabelLayout;
import nl.cwi.sen1.gui.plugin.prefusedot.DotNodeLayout;
import nl.cwi.sen1.gui.plugin.prefusedot.DotNodeRenderer;
import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.assignment.ColorAction;
import prefuse.action.assignment.FontAction;
import prefuse.action.layout.Layout;
import prefuse.controls.DragControl;
import prefuse.controls.FocusControl;
import prefuse.controls.PanControl;
import prefuse.controls.WheelZoomControl;
import prefuse.controls.ZoomControl;
import prefuse.data.Graph;
import prefuse.data.Schema;
import prefuse.render.AbstractShapeRenderer;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.util.FontLib;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;

/**
 * Builder to create a display (formatting, colors and layout) for a graph.
 * 
 * @author A. Belgraver
 * @author Anton Gerdessen (reviewer)
 * @author Jurgen Vinju
 * @date 07-3-2007  
 */
public class GraphDisplayBuilder {
	private DotNodeLayout dotLayout;
	
	private static final Schema LABEL_SCHEMA = PrefuseLib.getVisualItemSchema(); 
	{ 
	LABEL_SCHEMA.setDefault(VisualItem.INTERACTIVE, false); 
	LABEL_SCHEMA.setDefault(VisualItem.TEXTCOLOR, ColorLib.gray(100)); 
	LABEL_SCHEMA.setDefault(VisualItem.FONT, FontLib.getFont("Tahoma", 16)); 
	} 

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
        vis.addDecorators(GraphConstants.LABELS, GraphConstants.NODES);
    
    	DefaultRendererFactory drf = new DefaultRendererFactory();
    	
		LabelRenderer lr = new LabelRenderer(GraphConstants.LABEL);
		lr.setHorizontalTextAlignment(Constants.CENTER);
		lr.setVerticalTextAlignment(Constants.CENTER);
		lr.setRenderType(AbstractShapeRenderer.RENDER_TYPE_NONE);
		drf.add(new InGroupPredicate(GraphConstants.LABELS), lr);
		
        DotNodeRenderer nr = new DotNodeRenderer();
        nr.setRenderType(AbstractShapeRenderer.RENDER_TYPE_DRAW_AND_FILL);
		drf.add(new InGroupPredicate(GraphConstants.NODES), nr);

		EdgeRenderer er = new DotEdgeRenderer(Constants.EDGE_TYPE_LINE, Constants.EDGE_ARROW_FORWARD);
		drf.add(new InGroupPredicate(GraphConstants.EDGES), er);

		vis.setRendererFactory(drf);
		
		// Create an actions avaible for the graph.
		ActionList layout = new ActionList();
        dotLayout = new DotNodeLayout(GraphConstants.GRAPH);
		layout.add(dotLayout);
		Layout labelLayout = new DotLabelLayout(GraphConstants.LABELS);
	    layout.add(labelLayout);
		layout.add(new RepaintAction());
		vis.putAction(GraphConstants.LAYOUT, layout);
		vis.putAction(GraphConstants.LABELLAYOUT, labelLayout);
		
		vis.setInteractive(GraphConstants.LABELS, null, false);

        // Add the actions available for this graph.
		ActionList colors = createColorActions();
		vis.putAction(GraphConstants.COLOR, colors);
       
        // Setup the display in which to display the graph
        Display display = createDisplay(vis);

        // Start the graph.
        vis.run(GraphConstants.COLOR);
        vis.run(GraphConstants.LAYOUT);

        return display;
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
        ColorAction text = new ColorAction(GraphConstants.LABELS, VisualItem.TEXTCOLOR,
                ColorLib.gray(0));
        text.setDefaultColor(GraphConstants.TEXTCOLOR);
        FontAction nFont = new FontAction(GraphConstants.LABELS, GraphConstants.NODE_FONT);
        
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
        colors.add(nFont);
        colors.add(nStroke);
        colors.add(nFill);
        colors.add(nEdges);
        colors.add(nHeads);
        colors.add(text);
        colors.add(new RepaintAction());
        
        return colors;
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
        d.addControlListener(new DragControl() {
        	public void itemDragged(VisualItem item, MouseEvent e) {
        		super.itemDragged(item, e);
        		// This is a bit sluggish, because it relayouts all labels instead of just
        		// the one that has moved
        		item.getVisualization().run(GraphConstants.LABELLAYOUT);
        	}
        });
        d.addControlListener(new PanControl());
        
        // Allowing zooming in the panel.
        d.addControlListener(new ZoomControl());
        d.addControlListener(new WheelZoomControl());
        
        return d;
    }
}
