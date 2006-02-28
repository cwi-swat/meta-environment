package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.event.MouseEvent;
import java.awt.geom.AffineTransform;
import java.awt.geom.NoninvertibleTransformException;
import java.util.Iterator;

import javax.swing.AbstractAction;
import javax.swing.JPanel;

import nl.cwi.sen1.util.Preferences;
import edu.berkeley.guir.prefuse.Display;
import edu.berkeley.guir.prefuse.ItemRegistry;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.VisualItem;
import edu.berkeley.guir.prefuse.action.ActionMap;
import edu.berkeley.guir.prefuse.action.RepaintAction;
import edu.berkeley.guir.prefuse.action.animate.LocationAnimator;
import edu.berkeley.guir.prefuse.action.animate.PolarLocationAnimator;
import edu.berkeley.guir.prefuse.action.filter.GraphFilter;
import edu.berkeley.guir.prefuse.action.filter.TreeFilter;
import edu.berkeley.guir.prefuse.activity.ActionList;
import edu.berkeley.guir.prefuse.activity.Activity;
import edu.berkeley.guir.prefuse.activity.ActivityManager;
import edu.berkeley.guir.prefuse.activity.SlowInSlowOutPacer;
import edu.berkeley.guir.prefuse.event.ControlAdapter;
import edu.berkeley.guir.prefuse.event.FocusEvent;
import edu.berkeley.guir.prefuse.event.FocusListener;
import edu.berkeley.guir.prefuse.graph.DefaultGraph;
import edu.berkeley.guir.prefuse.graph.DefaultNode;
import edu.berkeley.guir.prefuse.graph.Graph;
import edu.berkeley.guir.prefuse.render.DefaultEdgeRenderer;
import edu.berkeley.guir.prefuse.render.DefaultRendererFactory;
import edu.berkeley.guir.prefuse.render.ShapeRenderer;
import edu.berkeley.guir.prefuse.render.TextItemRenderer;
import edu.berkeley.guir.prefuse.util.display.ExportDisplayAction;
import edu.berkeley.guir.prefusex.controls.DragControl;
import edu.berkeley.guir.prefusex.controls.FocusControl;
import edu.berkeley.guir.prefusex.controls.PanControl;
import edu.berkeley.guir.prefusex.controls.ZoomControl;
import edu.berkeley.guir.prefusex.force.DragForce;
import edu.berkeley.guir.prefusex.force.ForceSimulator;
import edu.berkeley.guir.prefusex.force.NBodyForce;
import edu.berkeley.guir.prefusex.force.SpringForce;
import edu.berkeley.guir.prefusex.layout.CircleLayout;
import edu.berkeley.guir.prefusex.layout.ForceDirectedLayout;
import edu.berkeley.guir.prefusex.layout.FruchtermanReingoldLayout;
import edu.berkeley.guir.prefusex.layout.GridLayout;
import edu.berkeley.guir.prefusex.layout.IndentedTreeLayout;
import edu.berkeley.guir.prefusex.layout.RadialTreeLayout;
import edu.berkeley.guir.prefusex.layout.RandomLayout;
import edu.berkeley.guir.prefusex.layout.VerticalTreeLayout;

public class GraphPanel extends JPanel {
    private static final String ID = "id";

    private String id;

    private Display display;

    private ItemRegistry registry;

    private GraphPanelListener listener;

    private Activity currentLayout;

    private ActionMap layouts;

    private ActionList highlighting;

    private ActionList animation;

    private DefaultEdgeRenderer edgeRenderer;

    private ForceSimulator forceSimulator;

    private TextItemRenderer nodeRenderer;

    public GraphPanel(String id, Preferences prefs) {
        this.id = id;
        setLayout(new BorderLayout());

        registry = new ItemRegistry(new DefaultGraph());

        display = new Display(registry);
        display.setHighQuality(true);

        nodeRenderer = new GraphNodeRenderer();
        nodeRenderer.setTextAttributeName("label");
        nodeRenderer.setFont(prefs.getFont("graph.node.font"));
        nodeRenderer.setHorizontalPadding(prefs
                .getInt("graph.node.border.width"));
        nodeRenderer.setVerticalPadding(prefs
                .getInt("graph.node.border.height"));

        edgeRenderer = new GraphEdgeRenderer();
        edgeRenderer.setRenderType(ShapeRenderer.RENDER_TYPE_DRAW);
        edgeRenderer.setEdgeType(DefaultEdgeRenderer.EDGE_TYPE_LINE);

        registry.setRendererFactory(new DefaultRendererFactory(nodeRenderer,
                edgeRenderer, null));

        display.addControlListener(new FocusControl(2, highlighting));
        display.addControlListener(new DragControl(true, true));
        display.addControlListener(new ZoomControl(true));
        display.addControlListener(new PanControl(true));
        display.addControlListener(new ControlAdapter() {
            public void itemPressed(VisualItem gi, MouseEvent e) {
                if (e.isPopupTrigger()) {
                    firePopupRequested(gi.getAttribute(ID), e);
                }
            }

            public void itemReleased(VisualItem gi, MouseEvent e) {
                itemPressed(gi, e);
            }
        });

        registry.getDefaultFocusSet().addFocusListener(new FocusListener() {
            public void focusChanged(FocusEvent e) {
                NodeItem n = registry
                        .getNodeItem((edu.berkeley.guir.prefuse.graph.Node) e
                                .getFirstAdded());
                fireNodeSelected(n == null ? null : n.getAttribute(ID));

                highlighting.runNow();
            }
        });

        createLayouts();
        createVisualEffects(prefs);

        add(display, BorderLayout.CENTER);
    }

    public AbstractAction getSaveImageAction() {
        return new ExportDisplayAction(display);
    }

    public void setCurvedEdges() {
        edgeRenderer.setEdgeType(DefaultEdgeRenderer.EDGE_TYPE_CURVE);
        runNow();
    }

    public void setStraightEdges() {
        edgeRenderer.setEdgeType(DefaultEdgeRenderer.EDGE_TYPE_LINE);
        runNow();
    }

    public void setNoAnimation() {
        animation = new ActionList(registry);
        animation.add(new RepaintAction());
    }

    public void setPolarAnimation() {
        animation = new ActionList(registry, 1500, 20);
        animation.setPacingFunction(new SlowInSlowOutPacer());
        animation.add(new PolarLocationAnimator());
        animation.add(new RepaintAction());
    }

    public void setLinearAnimation() {
        animation = new ActionList(registry, 1500, 20);
        animation.setPacingFunction(new SlowInSlowOutPacer());
        animation.add(new LocationAnimator());
        animation.add(new RepaintAction());
    }

    private void createVisualEffects(Preferences prefs) {
        setNoAnimation();
        createHighlighter(prefs);
    }

    private void createHighlighter(Preferences prefs) {
        highlighting = new ActionList(registry);
        highlighting.add(new GraphColoring(prefs));
        highlighting.add(new RepaintAction());
    }

    private class Hierarchy extends VerticalTreeLayout {
        public Hierarchy() {
            m_heightInc = 100;
        }
    }

    private void createLayouts() {
        layouts = new ActionMap();

        ActionList dot = new ActionList(registry);
        dot.add(new GraphFilter());
        dot.add(new GraphDotLayout());
        layouts.put("Dot", dot);

        ActionList manual = new ActionList(registry);
        manual.add(new GraphFilter());
        layouts.put("Manual", manual);

        ActionList hierarchy = new ActionList(registry);
        hierarchy.add(new TreeFilter(false, true, false));
        hierarchy.add(new Hierarchy());
        layouts.put("Vertical Tree", hierarchy);

        ActionList radial = new ActionList(registry);
        radial.add(new TreeFilter(false, true, false));
        radial.add(new RadialTreeLayout());
        layouts.put("Radial Tree", radial);

        ActionList indented = new ActionList(registry);
        indented.add(new TreeFilter(false, true, false));
        indented.add(new IndentedTreeLayout());
        indented.add(new RepaintAction());
        layouts.put("Indented Tree", indented);

        forceSimulator = new ForceSimulator();
        forceSimulator.addForce(new NBodyForce(-.4f, 0f, .1f));
        forceSimulator.addForce(new SpringForce(4E-5f, 80f));
        forceSimulator.addForce(new DragForce(-0.005f));

        ActionList contforce = new ActionList(registry, -1, 50);
        contforce.add(new GraphFilter());
        contforce.add(new ForceDirectedLayout(forceSimulator, false));
        contforce.add(new RepaintAction());
        layouts.put("Force", contforce);

        ActionList random = new ActionList(registry);
        random.add(new GraphFilter());
        random.add(new RandomLayout());
        layouts.put("Random", random);

        ActionList circle = new ActionList(registry);
        circle.add(new GraphFilter());
        circle.add(new CircleLayout());
        layouts.put("Circle", circle);

        ActionList grid = new ActionList(registry);
        grid.add(new GraphFilter());
        grid.add(new GridLayout());
        layouts.put("Grid", grid);

        ActionList funny = new ActionList(registry);
        funny.add(new GraphFilter());
        funny.add(new FruchtermanReingoldLayout());
        layouts.put("Funny", funny);
    }

    public ForceSimulator getForceSimulator() {
        return forceSimulator;
    }

    public Object[] getLayouts() {
        return layouts.keys();
    }

    public void setLayout(String name) {
        ActionList newLayout = (ActionList) layouts.get(name);

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
            currentLayout.runNow();
            highlighting.runNow();
            animation.runNow();
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

    void setGraph(Graph graph) {
        setSize(getParent().getWidth(), getParent().getHeight());
        registry.clear();
        registry.setGraph(graph);
        runNow();
    }

    public void setSelectedNode(String nodeId) {
        Iterator iter = registry.getGraph().getNodes();

        while (iter.hasNext()) {
            DefaultNode node = (DefaultNode) iter.next();
            if (node.getAttribute(ID).equals(nodeId)) {
                registry.getFocusManager().getDefaultFocusSet().set(node);
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

    static public void cleanUp() {
        ActivityManager.kill();
    }

}
