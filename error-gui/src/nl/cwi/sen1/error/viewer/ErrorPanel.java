package nl.cwi.sen1.error.viewer;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.net.URL;
import java.util.Enumeration;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
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

    public ErrorPanel() {
        super(new BorderLayout());

        JToolBar toolBar = new JToolBar("Error ToolBar",
                SwingConstants.VERTICAL);
        addButtons(toolBar);

        errorDecorator = new ErrorDecorator();

        top = new DefaultMutableTreeNode("Errors");

        tree = new JTree(top);
        tree.getSelectionModel().setSelectionMode(
                TreeSelectionModel.SINGLE_TREE_SELECTION);
        tree.setRootVisible(false);
        tree.setShowsRootHandles(true);

        DefaultTreeCellRenderer renderer = new DefaultTreeCellRenderer();
        Icon personIcon = null;
        renderer.setLeafIcon(personIcon);
        renderer.setClosedIcon(personIcon);
        renderer.setOpenIcon(personIcon);
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

    // private DefaultMutableTreeNode createNodes() {
    // Area area = factory.makeArea_Area(10, 1, 12, 4, 2, 3);
    // Location location = factory.makeLocation_AreaInFile(
    // "/home/kooiker/meta/bool.trm", area);
    // Subject subject1 = factory.makeSubject_Localized(
    // "character '0' unexpected", location);
    // SubjectList subjectList = factory.makeSubjectList(subject1);
    //
    // Location loc = factory
    // .makeLocation_AreaInFile(
    // "/home/kooiker/meta/installed/library/basic/Booleans.sdf",
    // area);
    // Subject subject2 = factory.makeSubject_Localized(
    // "module Booleans", loc);
    // subjectList = subjectList.append(subject2);
    //
    // Error error = factory.makeError_Error("Parse Error", subjectList);
    // ErrorList errorList = factory.makeErrorList(error);
    // Summary summary = factory.makeSummary_Summary("sglr", "14",
    // errorList);
    //
    // Area area2 = factory.makeArea_Area(10, 1, 12, 4, 2, 3);
    // Location location2 = factory.makeLocation_AreaInFile(
    // "Booleans.asf", area2);
    // Subject subject3 = factory
    // .makeSubject_Localized("Bool", location2);
    // SubjectList subjectList2 = factory.makeSubjectList(subject3);
    //
    // Error error2 = factory.makeError_Error(
    // "Uninstantiated variable occurence", subjectList2);
    // ErrorList errorList2 = factory.makeErrorList(error2);
    // Summary summary2 = factory.makeSummary_Summary("asf-checker",
    // "14", errorList2);
    //
    // errorDecorator.addErrors(top, summary);
    // errorDecorator.addErrors(top, summary2);
    //
    // return top;
    // }

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
