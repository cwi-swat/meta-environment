package metastudio.components.graphs;

import java.awt.BorderLayout;
import java.awt.Color;
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
import metastudio.data.graph.Node;
import aterm.ATermFactory;

// TODO: extract functionality from the GraphPanel that should be here.
public class ZoomableGraphPanel extends ToolComponent {
    private static final int SLIDER_STEP_SIZE = 5;
    private GraphPanel graphPanel;
    private JSlider slider;
    
    public ZoomableGraphPanel(ATermFactory factory, UserInterfaceBridge bridge, String id) {
        super(factory, bridge);
        
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
        add(slider,BorderLayout.WEST);
        
        scrolledPane.getViewport().addMouseWheelListener(wheel);
    }
    
    private void setSliderToolTip() {
        slider.setToolTipText("Zoom" + slider.getValue() + "%");
    }

    private JSlider createSlider() {
        slider = new JSlider(0,200,SLIDER_STEP_SIZE);
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
