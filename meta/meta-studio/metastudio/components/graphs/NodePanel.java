package metastudio.components.graphs;

import java.awt.Color;
import java.awt.Component;
import java.awt.Insets;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BoxLayout;
import javax.swing.JPanel;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import metastudio.MultiBridge;
import metastudio.data.graph.Graph;
import metastudio.data.graph.Node;
import aterm.ATerm;

public class NodePanel extends JPanel {
    private final Node node;
    private LineBorder line;
    private static final int BOX_BORDER_THICKNESS = 8;

    public NodePanel(final MultiBridge bridge, Node node) {
        this.node = node;
        int orientation;
        int thickness;
        Color color;

        if (Graph.getNodeShape(node).isDiamond()) {
            orientation = BoxLayout.Y_AXIS;
            color = Color.red;
            thickness = 3;
        } else {
            orientation = BoxLayout.X_AXIS;
            color = Color.black;
            thickness = 1;
        }

        BoxLayout layoutManager = new BoxLayout(this, orientation);
        setLayout(layoutManager);

        line = new LineBorder(color, thickness);
        CompoundBorder border =
            new CompoundBorder(
                new EmptyBorder(
                    new Insets(
                        BOX_BORDER_THICKNESS,
                        BOX_BORDER_THICKNESS,
                        BOX_BORDER_THICKNESS,
                        BOX_BORDER_THICKNESS)),
                line);
        setBorder(border);
        setToolTipText(node.getLabel());
        setBackground(Color.white);
        setAlignmentY(Component.CENTER_ALIGNMENT);

        if (node.hasInfo("message")) {
            final ATerm message = node.getInfo("message");

            addMouseListener(new MouseAdapter() {
                public void mouseClicked(MouseEvent event) {
                    bridge.postEvent(message);
                }
            });
        }
    }

    public Node getNode() {
        return node;
    }
}
