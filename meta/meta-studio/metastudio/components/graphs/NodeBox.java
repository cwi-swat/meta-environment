package metastudio.components.graphs;

import java.awt.Color;
import java.awt.Component;
import java.awt.Insets;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import metastudio.MultiBridge;
import metastudio.data.graph.Graph;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;

public class NodeBox extends JPanel {
    private final Node node;
    private LineBorder line;
    private MultiBridge bridge;
    boolean leaf;

    public NodeBox(final MultiBridge bridge, Node node, boolean leaf) {
        this.node = node;
        this.bridge = bridge;
        this.leaf = leaf;
        
        makeNode(node);
        
        if (leaf) {
            JLabel label = new JLabel(node.getLabel());
            label.setOpaque(false);
            setOpaque(false);
            add(label);
        }
        
        setForeground(Preferences.getColor("box.node.foreground"));
        setBackground(Preferences.getColor("box.node.background"));
        setToolTipText(node.getLabel());
        setAlignmentY(Component.CENTER_ALIGNMENT);

        addListeners(node, this);
    }
    
    private void addListeners(Node node, JComponent c) {
        c.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent e) {
                NodeBox source = (NodeBox) e.getSource();
                source.setBackground(Preferences.getColor("box.node.hovered.background"));
                source.setForeground(Preferences.getColor("box.node.hovered.foreground"));
                source.setOpaque(true);
            }
            public void mouseExited(MouseEvent e) {
                NodeBox source = (NodeBox) e.getSource();
                source.setBackground(Preferences.getColor("box.node.background"));
                source.setForeground(Preferences.getColor("box.node.foreground"));
                if (source.leaf) {
                    source.setOpaque(false);
                }
            }
        });
        
        if (node.hasInfo("message")) {
            final ATerm message = node.getInfo("message");
            
            c.addMouseListener(new MouseAdapter() {
              public void mouseClicked(MouseEvent event) {
                bridge.postEvent(message);
              }
            });
        }
    }

    private void makeNode(Node node) {
        int orientation;
        int thickness;
        Color color;
        
        if (Graph.getNodeShape(node).isDiamond()) {
            orientation = BoxLayout.Y_AXIS;
            color = Preferences.getColor("box.node.vertical.border");
            thickness = Preferences.getInteger("box.node.vertical.borderthickness");
        } else {
            orientation = BoxLayout.X_AXIS;
            color = Preferences.getColor("box.node.horizontal.border");
            thickness = Preferences.getInteger("box.node.horizontal.borderthickness");
        }

        BoxLayout layoutManager = new BoxLayout(this, orientation);
        setLayout(layoutManager);

        if (!leaf) {
          line = new LineBorder(color, thickness);
          CompoundBorder border =
              new CompoundBorder(
                  line,
                  new EmptyBorder(
                      new Insets(
                          Preferences.getInteger("box.node.border.width"),
                          Preferences.getInteger("box.node.border.height"),
                          Preferences.getInteger("box.node.border.width"),
                          Preferences.getInteger("box.node.border.height"))));
          setBorder(border);
        }
    }

    public Node getNode() {
        return node;
    }
}
