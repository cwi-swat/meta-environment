package metastudio.components.graphs;

import java.awt.Color;
import java.util.Iterator;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JViewport;

import metastudio.MultiBridge;
import metastudio.components.ToolComponent;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class BoxTree extends ToolComponent {
    private MetaGraphFactory factory;
    private JPanel rootPanel;

    public BoxTree(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        this.factory = new MetaGraphFactory((PureFactory) factory);

        setLayout(new BoxLayout(this, BoxLayout.X_AXIS));

        rootPanel = new JPanel();
        rootPanel.setBackground(Color.white);
        JScrollPane scrolledPane = new JScrollPane(rootPanel);
        JViewport view = scrolledPane.getViewport();
        view.setBackground(Preferences.getColor("box.background"));
        add(scrolledPane);
    }

    public void displayGraph(String id, ATerm graphTerm) {
        if (id.equals(getId())) {
            Graph graph = factory.GraphFromTerm(graphTerm);
            setGraph(graph);
            repaint();
        }
    }

    private String getId() {
        return "parsetree";
    }

    private void setGraph(Graph graph) {
        rootPanel.removeAll();
        Node root = Graph.getRootNode(graph);

        if (root != null) {
            rootPanel.add(buildHierarchy(graph, root));
        }

        repaint();
    }

    // TODO: remove recursion here, it gets too deep!
    private JComponent buildHierarchy(Graph graph, Node node) {
        List children = Graph.getChildren(graph, node);

        if (children.size() == 0) {
            return new NodeBox(getBridge(), node, true);
        } else {
            NodeBox box = new NodeBox(getBridge(), node, false);
            Iterator iter = children.iterator();

            while (iter.hasNext()) {
                Node child = (Node) iter.next();
                box.add(buildHierarchy(graph, child));
            }
            return box;
        }
    }
}
