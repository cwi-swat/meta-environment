package metastudio;

import javax.swing.*;
import javax.swing.tree.*;
import javax.swing.event.*;
import java.io.*;
import java.util.*;

public class ModuleTreeModel extends TreeModelSupport implements TreeModel, Serializable {

    private TreeNode root;
    private List moduleSelectionListeners;
    private Map moduleTable;

    public ModuleTreeModel() {
	moduleTable = new HashMap();
	moduleSelectionListeners = new LinkedList();
	root = new TreeNode("", "", false);
    }

    public Object getRoot() {
        return root;
    }

    public Object getChild( Object parent, int index ) {
        return ((TreeNode)parent).getChild(index);
    }

    public int getChildCount( Object parent ) {
	return ((TreeNode)parent).getChildCount();
    }

    public boolean isLeaf( Object node ) {
        return ((TreeNode)node).isLeaf();
    }

    public void valueForPathChanged( TreePath path, Object newValue ) {
    }

    public int getIndexOfChild( Object par, Object ch ) {
	TreeNode parent = (TreeNode)par;
	TreeNode child = (TreeNode)ch;	

	if (parent == null) 
	    return -1;

	return parent.getIndexOfChild(child);
    }


    public void addModuleSelectionListener(ModuleSelectionListener listener)
    {
	moduleSelectionListeners.add(listener);
    }


    //}}}
    //{{{ public void selectModule(String moduleName)

    public void selectModule(String moduleName)
    {
	selectModule(getModule(moduleName));
    }

    //}}}
    //{{{ public void selectModule(Module module)

    public void selectModule(Module module)
    {
	Iterator iter = moduleSelectionListeners.iterator();
	while (iter.hasNext()) {
	    ModuleSelectionListener l = (ModuleSelectionListener)iter.next();
	    l.moduleSelected(module);
	}
    }

    //}}}
    //{{{ public Module getModule(String name)

    public Module getModule(String name)
    {
	return (Module)moduleTable.get(name);
    }

    //}}}
    //{{{ public void addModule(Module module)

    public void addModule(Module module)
    {
	String name = module.getName();

	if (moduleTable.put(name, module) == null) {
	    root.addChild("", name);
	    repaintTree();
	}
    }

    //}}}
    //{{{ public void removeModule(String name)

    public void removeModule(String name)
    {
	moduleTable.remove(name);
	root.removeChild(name);
	repaintTree();
    }

    //}}}
    //{{{ public void clearModules()

    public void clearModules()
    {
	moduleTable.clear();
	root.clearChildren();
	repaintTree();
    }

    //}}}

    public TreePath makeTreePath(String name)
    {
	List l = root.makePath(name, new ArrayList());

	return new TreePath(l.toArray());
    }

    public void repaintTree() {
	Object path[] = new Object[1];
	path[0] = root;
	fireTreeStructureChanged(new TreeModelEvent(root, path));
    }
}






