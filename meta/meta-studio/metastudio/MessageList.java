package metastudio;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.ParseError;

public class MessageList extends JScrollPane {
  private String name;
  private ATermList items;
  private String[] items_strings;
  private JList view = new JList();

  class ListEventHandler implements ListSelectionListener {
    UserInterfaceBridge bridge;
    ATermFactory factory;
    MessageList list;

    ListEventHandler(UserInterfaceBridge bridge, ATermFactory factory, MessageList list) {
      this.bridge = bridge;
      this.factory = factory;
      this.list = list;
    }

    public void valueChanged(ListSelectionEvent e) {
      if (!(e.getValueIsAdjusting())) {
	int index = ((JList) (e.getSource())).getMinSelectionIndex();

	if (index != -1) {
	  ATerm sel = list.getItems().elementAt(index);

	  java.util.List matching;

	  try {
	    matching = sel.match("listitem(<str>,<term>)");
	  } catch (ParseError exc) {
	    errMessage("Selected element has bad structure");
	    return;
	  }

	  if (matching == null) {
	    errMessage("This is not a valid listitem: " + sel);
	  } else {
	    bridge.postEvent(factory.make("element-selected(<str>,<term>)", name, matching.get(1)));
	  }
	}
      }
    }
  }

  public MessageList(UserInterfaceBridge bridge, ATermFactory factory) {
    view.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    getViewport().setView(view);
    view.addListSelectionListener(new ListEventHandler(bridge, factory, this));
  }

  protected ATermList getItems() {
    return items;
  }

  public void setContent(String moduleName, ATermList data) {
    name = moduleName;
    items = data;

    int length = items.getLength();
    items_strings = new String[length];

    for (int i = 0; i < length; i++) {
      ATerm atrm = items.elementAt(i);
      java.util.List matching;

      try {
	matching = atrm.match("listitem(<str>,<term>)");
      } catch (ParseError exc) {
	errMessage("Can't show list containing non-listitems");
	return;
      }

      if (matching == null) {
	System.out.println(atrm.toString());
      } else {
	items_strings[i] = matching.get(0).toString();
      }
    }

    view.setListData(items_strings);
    view.repaint();
  }

  public void errMessage(String s) {
    System.err.println(s);
  }
}
