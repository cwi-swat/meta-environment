package metastudio;

import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;

import metastudio.graph.*;
import aterm.*;

class ButtonAction extends AbstractAction
{
    private String buttonType;
    private ATermList buttonName;
    private UserInterfaceBridge bridge;
    private static MetaGraphFactory factory;    
    private JList moduleList;

    public ButtonAction(String name, String btype, ATermList bname,   
			JList ml, UserInterfaceBridge br, MetaGraphFactory fac)
    {
	super(name);
	buttonType = btype;
	buttonName = bname;
	moduleList = ml;
	bridge = br;
	factory = fac;
    }

    public ButtonAction(String name, Icon icon, String btype, ATermList bname,   
			JList ml, UserInterfaceBridge br, MetaGraphFactory fac)
    {
	super(name, icon);
	buttonType = btype;
	buttonName = bname;
	moduleList = ml;
	bridge = br;
	factory = fac;
    }

    public void actionPerformed(ActionEvent event) {
	Object[] values = moduleList.getSelectedValues();
	if (values.length > 0) {
	    for (int i = 0; i < values.length; i++) {
		bridge.postEvent(factory.make("button-selected(<str>, <str>, <list>)", 
					      buttonType, (String) values[i], buttonName));
	    }
	}
	else {
	    bridge.postEvent(factory.make("button-selected(<str>, <list>)", 
					  buttonType, buttonName));
	}
    }
}
