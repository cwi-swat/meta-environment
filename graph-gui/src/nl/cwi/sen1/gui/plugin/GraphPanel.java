package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.geom.AffineTransform;
import java.awt.geom.NoninvertibleTransformException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import javax.swing.AbstractAction;
import javax.swing.JPanel;

import nl.cwi.sen1.util.Preferences;
import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.Action;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.animate.LocationAnimator;
import prefuse.action.animate.PolarLocationAnimator;
import prefuse.action.assignment.ColorAction;
import prefuse.action.assignment.FontAction;
import prefuse.action.layout.CircleLayout;
import prefuse.action.layout.GridLayout;
import prefuse.action.layout.RandomLayout;
import prefuse.action.layout.graph.FruchtermanReingoldLayout;
import prefuse.activity.Activity;
import prefuse.activity.SlowInSlowOutPacer;
import prefuse.controls.ControlAdapter;
import prefuse.controls.DragControl;
import prefuse.controls.FocusControl;
import prefuse.controls.PanControl;
import prefuse.controls.ZoomControl;
import prefuse.controls.ZoomToFitControl;
import prefuse.data.Graph;
import prefuse.data.Tuple;
import prefuse.data.event.TupleSetListener;
import prefuse.data.tuple.TupleSet;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.util.display.ExportDisplayAction;
import prefuse.util.force.ForceSimulator;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;

public class GraphPanel extends JPanel {
    private String id;

    private Display display;

    private Visualization vis;

    private GraphPanelListener listener;

    private Activity currentLayout;

    private Activity currentAnimation;

    private Set<String> layouts;

    private EdgeRenderer edgeRenderer;

    private ForceSimulator forceSimulator;

    public GraphPanel(String id, final Preferences prefs) {
        this.id = id;
        setLayout(new BorderLayout());

        vis = new Visualization();

        LabelRenderer lr = new GraphNodeRenderer(GraphConstants.LABEL);
        lr.setHorizontalPadding(prefs.getInt(GraphConstants.NODE_BORDER_WIDTH));
        lr.setVerticalPadding(prefs.getInt(GraphConstants.NODE_BORDER_HEIGHT));
        edgeRenderer = new GraphEdgeRenderer(Constants.EDGE_TYPE_LINE,
                Constants.EDGE_ARROW_FORWARD);
        vis.setRendererFactory(new DefaultRendererFactory(lr, edgeRenderer));

        ColorAction nStroke = new ColorAction(GraphConstants.NODES,
                VisualItem.STROKECOLOR);
        nStroke.setDefaultColor(prefs.getColor(GraphConstants.NODE_FOREGROUND)
                .getRGB());
        nStroke.add(new InGroupPredicate(Visualization.FOCUS_ITEMS), prefs
                .getColor(GraphConstants.NODE_SELECTED_FOREGROUND).getRGB());

        ColorAction nFill = new GraphColorAction(GraphConstants.NODES,
                GraphConstants.FILLCOLOR, VisualItem.FILLCOLOR);
        nFill.setDefaultColor(prefs.getColor(GraphConstants.NODE_BACKGROUND)
                .getRGB());
        nFill.add(new InGroupPredicate(Visualization.FOCUS_ITEMS), prefs
                .getColor(GraphConstants.NODE_SELECTED_BACKGROUND).getRGB());

        ColorAction eStroke = new ColorAction(GraphConstants.EDGES,
                VisualItem.STROKECOLOR);
        eStroke.setDefaultColor(Color.BLACK.getRGB());

        ColorAction eFill = new ColorAction(GraphConstants.EDGES,
                VisualItem.FILLCOLOR);
        eStroke.setDefaultColor(Color.BLACK.getRGB());

        ColorAction text = new ColorAction(GraphConstants.NODES,
                VisualItem.TEXTCOLOR);
        text.setDefaultColor(ColorLib.gray(50));

        FontAction font = new FontAction(GraphConstants.NODES, prefs
                .getFont(GraphConstants.NODE_FONT));

        ActionList draw = new ActionList();
        draw.add(text);
        draw.add(nStroke);
        draw.add(nFill);
        draw.add(eStroke);
        draw.add(eFill);
        draw.add(font);
        draw.add(new RepaintAction());

        vis.putAction("draw", draw);

        display = new Display(vis);
        display.setHighQuality(true);
        display.addControlListener(new DragControl());
        display.addControlListener(new ZoomControl());
        display.addControlListener(new ZoomToFitControl());
        display.addControlListener(new PanControl());
        display.addControlListener(new FocusControl(2));
        display.addControlListener(new ControlAdapter() {
            public void itemEntered(VisualItem item, MouseEvent e) {
                if (item.isInGroup(GraphConstants.NODES)) {
                    item.setFillColor(prefs.getColor(
                            GraphConstants.NODE_HOVERED_BACKGROUND).getRGB());
                    item.setStrokeColor(prefs.getColor(
                            GraphConstants.NODE_HOVERED_FOREGROUND).getRGB());
                    item.getVisualization().repaint();
                }
            }

            public void itemExited(VisualItem item, MouseEvent e) {
                if (item.isInGroup(GraphConstants.NODES)) {
                    item.setFillColor(item.getInt(GraphConstants.FILLCOLOR));
                    item.setStrokeColor(prefs.getColor(GraphConstants.NODE_FOREGROUND)
                            .getRGB());
                    item.getVisualization().repaint();
                }
            }

            public void itemPressed(VisualItem item, MouseEvent e) {
                if (e.isPopupTrigger()) {
                    firePopupRequested(item.getString(GraphConstants.ID), e);
                }
            }

            public void itemReleased(VisualItem gi, MouseEvent e) {
                itemPressed(gi, e);
            }
        });

        TupleSet focusGroup = vis.getGroup(Visualization.FOCUS_ITEMS);
        focusGroup.addTupleSetListener(new TupleSetListener() {
            public void tupleSetChanged(TupleSet ts, Tuple[] add, Tuple[] rem) {
                for (Tuple t : add) {
                    fireNodeSelected(((VisualItem) t)
                            .getString(GraphConstants.ID));
                }
            }
        });

        createLayouts();
        setPolarAnimation();

        add(display, BorderLayout.CENTER);
    }

    public AbstractAction getSaveImageAction() {
        return new ExportDisplayAction(display);
    }

    public void setCurvedEdges() {
        edgeRenderer.setEdgeType(Constants.EDGE_TYPE_CURVE);
        runNow();
    }

    public void setStraightEdges() {
        edgeRenderer.setEdgeType(Constants.EDGE_TYPE_LINE);
        runNow();
    }

    public void setNoAnimation() {
        ActionList animation = new ActionList(vis);
        animation.add(new RepaintAction());
        vis.putAction("no-animation", animation);
        currentAnimation = animation;
    }

    public void setPolarAnimation() {
        ActionList animation = new ActionList(vis, 1500);
        animation.setPacingFunction(new SlowInSlowOutPacer());
        animation.add(new PolarLocationAnimator());
        animation.add(new RepaintAction());
        vis.putAction("polar-animation", animation);
        currentAnimation = animation;
    }

    public void setLinearAnimation() {
        ActionList animation = new ActionList(vis, 1500);
        animation.setPacingFunction(new SlowInSlowOutPacer());
        animation.add(new LocationAnimator());
        animation.add(new RepaintAction());
        vis.putAction("linear-animation", animation);
        currentAnimation = animation;
    }

    // private class Hierarchy extends VerticalTreeLayout {
    // public Hierarchy() {
    // m_heightInc = 100;
    // }
    // }

    private void createLayouts() {
        layouts = new HashSet<String>();

        ActionList dot = new ActionList();
        dot.add(new GraphDotLayout(GraphConstants.GRAPH));
        vis.putAction("Dot", dot);
        layouts.add("Dot");

        // ActionList manual = new ActionList();
        // vis.putAction("Manual", manual);
        // layouts.add("Manual");

        // ActionList hierarchy = new ActionList(vis);
        // hierarchy.add(new TreeFilter(false, true, false));
        // hierarchy.add(new Hierarchy());
        // vis.putAction("Vertical Tree", hierarchy);

        // ActionList radial = new ActionList();
        // radial.add(new RadialTreeLayout(GraphConstants.GRAPH));
        // vis.putAction("Radial Tree", radial);
        // layouts.add("Radial Tree");

        // ActionList indented = new ActionList(registry);
        // indented.add(new TreeFilter(false, true, false));
        // indented.add(new IndentedTreeLayout());
        // indented.add(new RepaintAction());
        // registry.putAction("Indented Tree", indented);

        // forceSimulator = new ForceSimulator();
        // forceSimulator.addForce(new NBodyForce(-.4f, 0f, .1f));
        // forceSimulator.addForce(new SpringForce(4E-5f, 80f));
        // forceSimulator.addForce(new DragForce(-0.005f));
        //
        // ActionList contforce = new ActionList(-1, 50);
        // contforce.add(new GraphFilter());
        // contforce.add(new ForceDirectedLayout(GraphConstants.GRAPH,
        // forceSimulator, false));
        // vis.putAction("Force", contforce);
        // layouts.add("Force");

        ActionList random = new ActionList();
        random.add(new RandomLayout());
        vis.putAction("Random", random);
        layouts.add("Random");

        ActionList circle = new ActionList();
        circle.add(new CircleLayout(GraphConstants.GRAPH));
        vis.putAction("Circle", circle);
        layouts.add("Circle");

        // ActionList grid = new ActionList();
        // grid.add(new GridLayout(GraphConstants.NODES));
        // vis.putAction("Grid", grid);
        //        layouts.add("Grid");

        ActionList funny = new ActionList();
        funny.add(new FruchtermanReingoldLayout(GraphConstants.GRAPH));
        vis.putAction("Funny", funny);
        layouts.add("Funny");
    }

    public ForceSimulator getForceSimulator() {
        return forceSimulator;
    }

    public Object[] getLayouts() {
        return layouts.toArray();
    }

    public void setLayout(String name) {
        Action newLayout = vis.getAction(name);

        if (newLayout != null) {
            cancel();
            currentLayout = newLayout;
            runNow();
        } else {
            throw new UnsupportedOperationException("Layout " + name
                    + " does not exist");
        }
    }

    private void runNow() {
        if (currentLayout != null) {
            vis.run("draw");
            currentLayout.run();
            vis.repaint();
            currentAnimation.run();
        } else {
            System.err.println("No current layout!");
        }
    }

    private void cancel() {
        if (currentLayout != null) {
            currentLayout.cancel();
        }
    }

    protected void resize() {
        setSize(getParent().getWidth(), getParent().getHeight());
    }

    void setGraphPanelListener(GraphPanelListener l) {
        this.listener = l;
    }

    protected void fireNodeSelected(String selectedNodeId) {
        listener.nodeSelected(selectedNodeId);
    }

    protected void firePopupRequested(String nodeId, MouseEvent e) {
        listener.popupRequested(nodeId, e);
    }

    void setGraph(Graph g) {
        setSize(getParent().getWidth(), getParent().getHeight());
        vis.reset();
        vis.addGraph(GraphConstants.GRAPH, g);
        Activity oldAnimation = currentAnimation;
        setNoAnimation();
        runNow();
        currentAnimation = oldAnimation;
    }

    public void setSelectedNode(String nodeId) {
        Graph g = (Graph) vis.getGroup(GraphConstants.GRAPH);
        Iterator nodeIter = g.nodes();
        while (nodeIter.hasNext()) {
            VisualItem node = (VisualItem) nodeIter.next();
            if (node.getString(GraphConstants.ID).equals(nodeId)) {
                TupleSet focusGroup = vis.getGroup(Visualization.FOCUS_ITEMS);
                focusGroup.setTuple(node);
            }
        }
    }

    public void restoreZoomAndPan() {
        try {
            display.setTransform(new AffineTransform());
            display.repaint();
        } catch (NoninvertibleTransformException e) {
            // this does not happen
        }
    }

    public String getId() {
        return id;
    }
}
