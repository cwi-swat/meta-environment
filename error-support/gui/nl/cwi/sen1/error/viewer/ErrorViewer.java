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
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;
import javax.swing.tree.TreeSelectionModel;

import nl.cwi.sen1.error.model.ErrorDecorator;
import aterm.pure.PureFactory;
import errorapi.types.Area;
import errorapi.types.Error;
import errorapi.types.ErrorList;
import errorapi.types.Location;
import errorapi.types.Subject;
import errorapi.types.SubjectList;
import errorapi.types.Summary;

public class ErrorViewer extends JPanel {
	private PureFactory factory;

	private errorapi.Factory errorFactory;

	private JTree tree;

	static final private String PREVIOUS = "previous";

	static final private String UP = "up";

	static final private String NEXT = "next";

	public ErrorViewer() {
		super(new BorderLayout());

		JToolBar toolBar = new JToolBar("Error ToolBar");
		addButtons(toolBar);

		DefaultMutableTreeNode top = createNodes();

		tree = new JTree(top);
		tree.getSelectionModel().setSelectionMode(
				TreeSelectionModel.SINGLE_TREE_SELECTION);

		JScrollPane scrollPane = new JScrollPane(tree);
		add(toolBar, BorderLayout.NORTH);
		add(scrollPane, BorderLayout.CENTER);
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
				tree.expandPath(new TreePath((TreeNode) tree.getModel().getRoot()));
			}
		};
		toolBar.add(action);
	}

	private DefaultMutableTreeNode createNodes() {
		factory = new PureFactory();
		errorFactory = new errorapi.Factory(factory);

		Area area = errorFactory.makeArea_Area(10, 1, 12, 4, 2, 3);
		Location location = errorFactory.makeLocation_AreaInFile(
				"/home/kooiker/meta/bool.trm", area);
		Subject subject1 = errorFactory.makeSubject_Localized(
				"character '0' unexpected", location);
		SubjectList subjectList = errorFactory.makeSubjectList(subject1);

		Location loc = errorFactory
				.makeLocation_AreaInFile(
						"/home/kooiker/meta/installed/library/basic/Booleans.sdf",
						area);
		Subject subject2 = errorFactory.makeSubject_Localized(
				"module Booleans", loc);
		subjectList = subjectList.append(subject2);

		Error error = errorFactory.makeError_Error("Parse Error", subjectList);
		ErrorList errorList = errorFactory.makeErrorList(error);
		Summary summary = errorFactory.makeSummary_Summary("sglr", "14",
				errorList);

		Area area2 = errorFactory.makeArea_Area(10, 1, 12, 4, 2, 3);
		Location location2 = errorFactory.makeLocation_AreaInFile(
				"Booleans.asf", area2);
		Subject subject3 = errorFactory
				.makeSubject_Localized("Bool", location2);
		SubjectList subjectList2 = errorFactory.makeSubjectList(subject3);

		Error error2 = errorFactory.makeError_Error(
				"Uninstantiated variable occurence", subjectList2);
		ErrorList errorList2 = errorFactory.makeErrorList(error2);
		Summary summary2 = errorFactory.makeSummary_Summary("asf-checker",
				"14", errorList2);

		DefaultMutableTreeNode top = new DefaultMutableTreeNode("Errors");
		ErrorDecorator errorDecorator = new ErrorDecorator();
		errorDecorator.addErrors(top, summary);
		errorDecorator.addErrors(top, summary2);

		return top;
	}

	private static void createAndShowGUI() {
		JFrame frame = new JFrame("Error Viewer");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		ErrorViewer newContentPane = new ErrorViewer();
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
