package metastudio.components.graphs;

import java.awt.BorderLayout;
import java.awt.FontMetrics;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JViewport;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import metastudio.MultiBridge;
import metastudio.components.ToolComponent;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;

// TODO: extract functionality from the GraphPanel that should be here.
public class ZoomableGraphPanel extends ToolComponent {
    private int SLIDER_STEP_SIZE;
    private int SLIDER_MINIMUM;
    private int SLIDER_MAXIMUM;
    private int SLIDER_DEFAULT;
    private GraphPanel graphPanel;
    private JSlider slider;
    private MetaGraphFactory factory;
    private JViewport view;

    public ZoomableGraphPanel(
        MetaGraphFactory factory,
        MultiBridge bridge,
        String id) {
        super(factory.getPureFactory(), bridge);
        this.factory = factory;

        graphPanel = new GraphPanel(id);

        slider = createSlider();
        setSliderToolTip();
        MouseWheelListener wheel = new MouseWheelListener() {
            public void mouseWheelMoved(MouseWheelEvent e) {
                slider.setValue(slider.getValue() - e.getUnitsToScroll());
            }
        };

        JScrollPane scrolledPane = new JScrollPane(graphPanel);
        view = scrolledPane.getViewport();
        view.setBackground(Preferences.getColor("graph.background"));
        view.addMouseWheelListener(wheel);

        add(scrolledPane, BorderLayout.CENTER);
        add(slider, BorderLayout.WEST);

        scrolledPane.getViewport().addMouseWheelListener(wheel);
        graphPanel.setScale(Preferences.getInteger("graph.scale.default"));
    }
    
    public MetaGraphFactory getGraphFactory() {
        return factory;
    }
    
    private void setSliderToolTip() {
        slider.setToolTipText("Zoom" + slider.getValue() + "%");
    }

    private JSlider createSlider() {
        SLIDER_MINIMUM = Preferences.getInteger("graph.scale.minimum");
        SLIDER_MAXIMUM = Preferences.getInteger("graph.scale.maximum");
        SLIDER_STEP_SIZE = Preferences.getInteger("graph.scale.stepsize");
        SLIDER_DEFAULT = Preferences.getInteger("graph.scale.default");
        slider = new JSlider(SLIDER_MINIMUM, SLIDER_MAXIMUM, SLIDER_STEP_SIZE);
        slider.setOrientation(SwingConstants.VERTICAL);
        slider.setBackground(Preferences.getColor("graph.scale.background"));
        slider.setValue(SLIDER_DEFAULT);

        slider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                graphPanel.setScale(slider.getValue());
                setSliderToolTip();
                graphPanel.setSelectedNode(graphPanel.getSelectedNode());
                graphPanel.setToolTipEnabled(slider.getValue() < 100);
            }
        });

        return slider;
    }

    public void displayGraph(String id, ATerm graphTerm) {
        if (id.equals(getId())) {
            Graph graph = factory.GraphFromTerm(graphTerm);
            layoutGraph(graph);
        }
    }

    public void layoutGraph(Graph graph) {
        final FontMetrics metrics =
            graphPanel.getFontMetrics(Preferences.getFont(GraphPanel.PREF_NODE_FONT));

        NodeSizer sizer = new NodeSizer() {
            public int getWidth(Node node) {
                return metrics.stringWidth(node.getLabel())
                    + Preferences.getInteger("node.border.width") * 2;
            }
            public int getHeight(Node node) {
                return metrics.getHeight()
                    + Preferences.getInteger("node.border.height") * 2;
            }
        };

        graph = orderNodes(graph);
        graph = sizeNodes(graph, sizer);

        postEvent(
            getFactory().make("layout-graph(<str>,<term>)", getId(), graph.toTerm()));
    }
    
    protected Graph orderNodes(Graph graph) {
        return graph;
    }
    
    protected Graph sizeNodes(Graph graph, NodeSizer sizer) {
        return graph.sizeNodes(sizer);
    }
    
    public void graphLayouted(String id, ATerm graphTerm) {
        if (id.equals(getId())) {
            Graph graph = factory.GraphFromTerm(graphTerm);
            setGraph(graph);
            setVisible(true);
            graphPanel.repaint();
        }
    }

    public GraphPanel getGraphPanel() {
        return graphPanel;
    }

    public String getId() {
        return graphPanel.getId();
    }

    public Node getNodeAt(int x, int y) {
        return graphPanel.getNodeAt(x, y);
    }

    public void setDragEnabled(boolean on) {
        graphPanel.setDragEnabled(on);
    }

    public void setGraph(Graph graph) {
        graphPanel.setGraph(graph);
    }

    public int getIndex() {
        return graphPanel.getIndex();
    }
}
