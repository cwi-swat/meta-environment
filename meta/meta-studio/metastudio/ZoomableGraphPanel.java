package metastudio;

import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import metastudio.graph.Graph;
import metastudio.graph.Node;
import aterm.ATermFactory;

public class ZoomableGraphPanel extends JPanelTool {
    private GraphPanel graphPanel;
    private JSlider slider;
    
    public ZoomableGraphPanel(ATermFactory factory, UserInterfaceBridge bridge, String id) {
        super(factory, bridge);
        
        graphPanel = new GraphPanel(id);
        slider = createSlider();
        
        JScrollPane scrolledPane = new JScrollPane(graphPanel);
        scrolledPane.getViewport().setBackground(Color.white);
        
        add(scrolledPane, BorderLayout.CENTER);
        add(slider,BorderLayout.WEST);
    }
    
    private JSlider createSlider() {
        slider = new JSlider(0,200,5);
        slider.setOrientation(SwingConstants.VERTICAL);
        slider.setBackground(Color.white);
        slider.setValue(100);
        
        slider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                graphPanel.setScale(slider.getValue());
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
