package metastudio.components.graphs;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FontMetrics;
import java.awt.Insets;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.image.ImageObserver;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JViewport;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.MouseInputAdapter;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;

// TODO: extract functionality from the GraphPanel that should be here.
public class ZoomableGraphPanel extends UserInterfacePanel {
    private int SLIDER_STEP_SIZE;
    private int SLIDER_MINIMUM;
    private int SLIDER_MAXIMUM;
    private int SLIDER_DEFAULT;
    private GraphPanel graphPanel;
    private JSlider slider;
    private MetaGraphFactory factory;
    private JViewport view;
    private JButton zoomToFit;

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
        
        JPanel sliderPanel = new JPanel();
        sliderPanel.setLayout(new BorderLayout());
        
        sliderPanel.add(slider, BorderLayout.CENTER);
        
        zoomToFit = new JButton("Z");
        zoomToFit.addMouseListener(new MouseInputAdapter() {
            public void mouseClicked(MouseEvent e) {
                int scale = graphPanel.getZoomToFitFactor(view.getVisibleRect());
                slider.setValue(Math.min(scale, SLIDER_MAXIMUM));
            }
        });
        zoomToFit.setToolTipText("Zoom to fit");
        zoomToFit.setMinimumSize(new Dimension(ImageObserver.HEIGHT,ImageObserver.HEIGHT));
        zoomToFit.setMaximumSize(new Dimension(ImageObserver.HEIGHT,ImageObserver.HEIGHT));
        zoomToFit.setMargin(new Insets(0,0,0,0));
        sliderPanel.add(zoomToFit, BorderLayout.SOUTH);
        
        add(sliderPanel, BorderLayout.WEST);
        

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
        
        fireValueChangedListener();
    }

    public void layoutGraph(Graph graph) {
        final FontMetrics metrics =
            graphPanel.getFontMetrics(Preferences.getFont(GraphPanel.PREF_NODE_FONT));

        NodeSizer sizer = new NodeSizer() {
            public int getWidth(Node node) {
                return metrics.stringWidth(node.getLabel())
                    + Preferences.getInteger("graph.node.border.width") * 2;
            }
            public int getHeight(Node node) {
                return metrics.getHeight()
                    + Preferences.getInteger("graph.node.border.height") * 2;
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
