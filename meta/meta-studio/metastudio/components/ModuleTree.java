package metastudio.components;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.SwingUtilities;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import metastudio.MultiBridge;
import metastudio.data.Module;
import metastudio.data.ModuleSelectionModel;
import metastudio.data.ModuleTreeModel;
import metastudio.data.ModuleTreeNode;
import aterm.ATermFactory;

public class ModuleTree extends ToolComponent {
    private JTree tree;

    public ModuleTree(
        ATermFactory factory,
        MultiBridge bridge,
        final ModuleTreeModel manager) {
        super(factory, bridge);

        tree = new JTree(manager);
        tree.setRootVisible(false);
        tree.setShowsRootHandles(true);
        tree.setExpandsSelectedPaths(true);
        tree.setSelectionModel(new ModuleSelectionModel());
        tree.addTreeSelectionListener(new TreeSelectionListener() {
            public void valueChanged(TreeSelectionEvent e) {
                manager.selectModule(getCurrentModule());
            }
        });
        tree.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                ModulePopupMenu.setPopupLocation(
                    (JComponent) e.getSource(),
                    e.getX(),
                    e.getY());
                if (e.isPopupTrigger() || SwingUtilities.isRightMouseButton(e)) {
                    TreePath path = tree.getClosestPathForLocation(e.getX(), e.getY());

                    if (path != null) {
                        tree.setSelectionPath(path);
                        postEvent(
                            getFactory().make(
                                "get-buttons(module-popup,<str>)",
                                getCurrentModule()));
                    }

                }

            }
        });

        add(new JScrollPane(tree));

        manager.addModuleSelectionListener(new ModuleSelectionListener() {
            public void moduleSelected(Module module) {
                if (module != null) {
                    TreePath path = manager.makeTreePath(module.getName());
                    tree.setSelectionPath(path);
                    tree.scrollPathToVisible(path);
                } else {
                    tree.clearSelection();
                }
            }
        });
    }

    private String getCurrentModule() {
        TreePath path = tree.getSelectionPath();

        if (path != null) {
            ModuleTreeNode selectedModule = (ModuleTreeNode) path.getLastPathComponent();
            return selectedModule.getFullName();
        }

        return null;
    }
}
