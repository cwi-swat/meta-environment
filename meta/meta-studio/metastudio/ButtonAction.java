package metastudio;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.tree.*;
import java.awt.event.*;

import metastudio.graph.*;
import aterm.*;

class ButtonAction extends AbstractAction
{
    private String buttonType;
    private ATermList buttonName;
    private UserInterfaceBridge bridge;
    private static MetaGraphFactory factory;    
    private JTree moduleTree;

    public ButtonAction(String name, String btype, ATermList bname,   
			JTree ml, UserInterfaceBridge br, MetaGraphFactory fac)
    {
	super(name);
	buttonType = btype;
	buttonName = bname;
	moduleTree = ml;
	bridge = br;
	factory = fac;
    }

    public ButtonAction(String name, Icon icon, String btype, ATermList bname,   
			JTree ml, UserInterfaceBridge br, MetaGraphFactory fac)
    {
	super(name, icon);
	buttonType = btype;
	buttonName = bname;
	moduleTree = ml;
	bridge = br;
	factory = fac;
    }

    public void actionPerformed(ActionEvent event) {
	TreePath values[] = moduleTree.getSelectionPaths();	

	if (values != null && values.length > 0) {
	    for (int i = 0; i < values.length; i++) {
		bridge.postEvent(factory.make("button-selected(<str>, <str>, <list>)", buttonType, ((TreeNode)values[i].getLastPathComponent()).getFullName(), buttonName));
	    }
	}
	else {
	    bridge.postEvent(factory.make("button-selected(<str>, <list>)", 
					  buttonType, buttonName));
	}
    }
}



