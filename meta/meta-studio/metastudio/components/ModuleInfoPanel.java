package metastudio.components;

import java.util.Iterator;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreePath;

import metastudio.MultiBridge;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import metastudio.utils.Preferences;
import aterm.ATermFactory;

public class ModuleInfoPanel extends ToolComponent implements ModuleSelectionListener {
    private JTree tree;

    private DefaultMutableTreeNode root;
    private DefaultMutableTreeNode imports;
    private DefaultMutableTreeNode importedBy;

    private ModuleTreeModel manager;

    public ModuleInfoPanel(
        ATermFactory factory,
        MultiBridge bridge,
        ModuleTreeModel moduleManager) {
        super(factory, bridge);
        this.manager = moduleManager;

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        setBackground(Preferences.getColor("moduleinfo.background"));

        root = new DefaultMutableTreeNode();
        imports = new DefaultMutableTreeNode(Preferences.getString("moduleinfo.imports"));
        importedBy = new DefaultMutableTreeNode(Preferences.getString("moduleinfo.importedby"));

        tree = new JTree(root);
        tree.setRootVisible(false);
        tree.setBackground(Preferences.getColor("moduleinfo.background"));

        add(new JScrollPane(tree));
        moduleManager.addModuleSelectionListener(this);

        tree.addTreeSelectionListener(new TreeSelectionListener() {
            public void valueChanged(TreeSelectionEvent e) {
                TreePath path = tree.getSelectionPath();

                if (path != null) {
                    DefaultMutableTreeNode node =
                        (DefaultMutableTreeNode) path.getLastPathComponent();

                    if (node.isLeaf()) {
                        String module = node.toString();
                        manager.selectModule(module);
                    }
                }
            }
        });
    }

    public void moduleSelected(Module module) {
        root.removeAllChildren();
        
        if (module != null) {
            setLeafs(importedBy, module, module.getParents());
            makeVisible(importedBy);
            
            setLeafs(imports, module, module.getChildren());
            makeVisible(imports);
        } 
        
        refresh();
    }

    private void makeVisible(DefaultMutableTreeNode node) {
        if (node.getChildCount() > 0) {
            root.insert(node, 0);
        }
    }

    private void setLeafs(DefaultMutableTreeNode node, Module module, List leafs) {
        node.removeAllChildren();
        
        Iterator iter = leafs.iterator();
        while (iter.hasNext()) {
            String child = (String) iter.next();
            DefaultMutableTreeNode childNode = new DefaultMutableTreeNode(child);

            node.insert(childNode, node.getChildCount());
        }
    }
    
    private void refresh() {
        ((DefaultTreeModel) tree.getModel()).reload();
    }
}
