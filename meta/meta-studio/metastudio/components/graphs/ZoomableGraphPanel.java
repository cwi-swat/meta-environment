package metastudio.components.graphs;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JViewport;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import metastudio.UserInterfaceBridge;
import metastudio.components.ToolComponent;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;

// TODO: extract functionality from the GraphPanel that should be here.
public class ZoomableGraphPanel extends ToolComponent {
    private static final int SLIDER_STEP_SIZE = 5;
    private GraphPanel graphPanel;
    private JSlider slider;
    private MetaGraphFactory factory;

    public ZoomableGraphPanel(
        MetaGraphFactory factory,
        UserInterfaceBridge bridge,
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
        JViewport view = scrolledPane.getViewport();
        view.setBackground(Color.white);
        view.addMouseWheelListener(wheel);

        add(scrolledPane, BorderLayout.CENTER);
        add(slider, BorderLayout.WEST);

        scrolledPane.getViewport().addMouseWheelListener(wheel);
    }

    public MetaGraphFactory getGraphFactory() {
        return factory;
    }
    
    private void setSliderToolTip() {
        slider.setToolTipText("Zoom" + slider.getValue() + "%");
    }

    private JSlider createSlider() {
        slider = new JSlider(0, 200, SLIDER_STEP_SIZE);
        slider.setOrientation(SwingConstants.VERTICAL);
        slider.setBackground(Color.white);
        slider.setValue(100);

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
                    + Preferences.getInteger(Preferences.PREF_NODE_BORDER_WIDTH) * 2;
            }
            public int getHeight(Node node) {
                return metrics.getHeight()
                    + Preferences.getInteger(Preferences.PREF_NODE_BORDER_HEIGHT) * 2;
            }
        };

        graph = graph.orderNodes();
        graph = graph.sizeNodes(sizer);

        postEvent(
            getFactory().make("layout-graph(<str>,<term>)", getId(), graph.toTerm()));
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
