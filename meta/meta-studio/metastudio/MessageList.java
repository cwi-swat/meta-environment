package metastudio;

import javax.swing.*;
import java.awt.*;
import aterm.*;
import java.util.*;
import javax.swing.event.*;

public class MessageList extends JScrollPane 
{
    String name;
    public ATermList items;
    String[] items_strings;
    JList view = new JList();

    class ListEventHandler implements ListSelectionListener 
    {
	UserInterfaceBridge bridge;
	ATermFactory factory;
	MessageList list;

	ListEventHandler(UserInterfaceBridge lvb, ATermFactory fac, MessageList gl)
	{
	    bridge = lvb;
	    factory = fac;
	    list = gl;
	}
	
	public void valueChanged(ListSelectionEvent e) 
	{
	    if (!(e.getValueIsAdjusting())) {

		try {
		    int index = ((JList)(e.getSource())).getMinSelectionIndex();

		    ATerm sel = list.items.elementAt(index);
	    
		    java.util.List matching;
		    
		    System.out.println(sel.toString());

		    try {
			matching = sel.match("listitem(<str>,[<list>],<term>)");
		    }
		    catch (ParseError exc) {
			errMessage("Selected element has bad structure");
			return;
		    }
		    
		    if (matching == null) {
			System.err.println("This is not a valid listitem: " + sel);
		    }
		    else {
			System.out.println(matching);
			bridge.postEvent(factory.make("element-selected(<list>,<str>,<term>)", 
						      matching.get(1), 
                                                      name,
						      matching.get(2)));
		    }
		}
		catch (IllegalArgumentException iae) {
		    System.out.println("List update event");
		}
	    }
	}
    }
    
    public MessageList(UserInterfaceBridge lvt, ATermFactory fac) 
    {
	view.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	getViewport().setView(view);
	view.addListSelectionListener(new ListEventHandler(lvt, fac, this));

    }

    public void setContent(String moduleName, ATermList data)
    {
	name = moduleName;
        items = data;

	int length = items.getLength();
	items_strings = new String[length];

	for (int i = 0; i < length; i++) {
	    ATerm atrm = items.elementAt(i);
	    java.util.List matching;

	    try {
		matching = atrm.match("listitem(<str>,[<list>],<term>)");
	    }
	    catch (ParseError exc) {
		errMessage("Can't show list containing non-listitems");
		return;
	    }

	    if (matching == null) {
		System.out.println(atrm.toString());
	    }
	    else {
		items_strings[i] = matching.get(0).toString();
	    }
	}

	view.setListData(items_strings);
	view.repaint();
    } 

    public void errMessage(String s){
	System.out.println(s);
    }
}

