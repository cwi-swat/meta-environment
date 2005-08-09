package nl.cwi.sen1.error.viewer;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.net.URL;
import java.util.Enumeration;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JToolBar;
import javax.swing.JTree;
import javax.swing.SwingConstants;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;
import javax.swing.tree.TreeSelectionModel;

import nl.cwi.sen1.error.model.ErrorDecorator;
import errorapi.types.Summary;

public class ErrorPanel extends JPanel {
    private JTree tree;

    private ErrorDecorator errorDecorator;

    private DefaultMutableTreeNode top;

	private DefaultTreeModel treeModel;

    public ErrorPanel() {
        super(new BorderLayout());

        JToolBar toolBar = new JToolBar("Error ToolBar",
                SwingConstants.VERTICAL);
        addButtons(toolBar);

        errorDecorator = new ErrorDecorator();

        top = new DefaultMutableTreeNode("Errors");
        treeModel = new DefaultTreeModel(top);

        tree = new JTree(treeModel);
        tree.getSelectionModel().setSelectionMode(
                TreeSelectionModel.SINGLE_TREE_SELECTION);
        tree.setRootVisible(false);
        tree.setShowsRootHandles(true);

        DefaultTreeCellRenderer renderer = new ErrorTreeCellRenderer();
        
        tree.setCellRenderer(renderer);

        JScrollPane scrollPane = new JScrollPane(tree);
        add(toolBar, BorderLayout.WEST);
        add(scrollPane, BorderLayout.CENTER);
    }

    public JTree getTree() {
        return tree;
    }

    public void addError(Summary summary) {
        errorDecorator.addErrors(top, summary);
        ((DefaultTreeModel) tree.getModel()).reload();
        tree.expandPath(new TreePath(top));
    }
    
	public void removeAllMatchingErrors(String producer, String id) {
		errorDecorator.removeAllMatchingErrors(top, producer, id);
		treeModel.reload();
	}

    public void expandAll(JTree tree, boolean expand) {
        TreeNode root = (TreeNode) tree.getModel().getRoot();
        
        // Traverse tree from root
        expandAll(tree, new TreePath(root), expand);
        
    }

    private void expandAll(JTree tree, TreePath parent, boolean expand) {
        // Traverse children
        TreeNode node = (TreeNode) parent.getLastPathComponent();
        if (node.getChildCount() >= 0) {
            for (Enumeration e = node.children(); e.hasMoreElements();) {
                TreeNode n = (TreeNode) e.nextElement();
                TreePath path = parent.pathByAddingChild(n);
                expandAll(tree, path, expand);
            }
        }

        // Expansion or collapse must be done bottom-up
        if (expand) {
            tree.expandPath(parent);
        } else {
            tree.collapsePath(parent);
        }
    }

    private void addButtons(JToolBar toolBar) {
        URL url = getClass().getResource(
                "/toolbarButtonGraphics/general/ZoomIn16.gif");
        Action action = new AbstractAction("Expand All", new ImageIcon(url)) {
            public void actionPerformed(ActionEvent e) {
                expandAll(tree, true);
            }
        };
        toolBar.add(action);
        url = getClass().getResource(
                "/toolbarButtonGraphics/general/ZoomOut16.gif");
        action = new AbstractAction("Collapse All", new ImageIcon(url)) {
            public void actionPerformed(ActionEvent e) {
                expandAll(tree, false);
                tree.expandPath(new TreePath(tree.getModel().getRoot()));
            }
        };
        toolBar.add(action);
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Error Viewer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // errorapi.Factory factory = new errorapi.Factory(new PureFactory());

        ErrorPanel newContentPane = new ErrorPanel();
        newContentPane.setOpaque(true); // content panes must be opaque
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }

	
}
