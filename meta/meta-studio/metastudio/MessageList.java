package metastudio;

import java.awt.BorderLayout;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ParseError;
import aterm.pure.PureFactory;

public class MessageList extends JPanelTool implements ListSelectionListener {
	private JList list;
	private String moduleName;
	private ATermList data;

	public MessageList(PureFactory factory, UserInterfaceBridge bridge) {
        super(factory, bridge);
        
		list = new JList();
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addListSelectionListener(this);
		
		setLayout(new BorderLayout());
		add(new JScrollPane(list), BorderLayout.CENTER);
	}

	public void setContent(String moduleName, ATermList data) {
		this.moduleName = moduleName;
		this.data = data;

		int length = data.getLength();
		String[] items_strings = new String[length];

		for (int i = 0; i < length; i++) {
			ATerm atrm = data.elementAt(i);
			java.util.List matching;

			try {
				matching = atrm.match("listitem(<str>,<term>)");
			} catch (ParseError exc) {
				System.err.println("Can't show list containing non-listitems");
				return;
			}

			if (matching == null) {
				System.out.println(atrm.toString());
			} else {
				items_strings[i] = matching.get(0).toString();
			}
		}

		list.setListData(items_strings);
		list.repaint();
	}

	public void valueChanged(ListSelectionEvent e) {
		if (!(e.getValueIsAdjusting())) {
			int index = list.getSelectedIndex();

			if (index != -1) {
				ATerm sel = data.elementAt(index);

				java.util.List matching;

				try {
					matching = sel.match("listitem(<str>,<term>)");
				} catch (ParseError exc) {
					System.err.println("Selected element has bad structure");
					return;
				}

				if (matching == null) {
					System.err.println("This is not a valid listitem: " + sel);
				} else {
					postEvent(
						getFactory().make(
							"element-selected(<str>,<term>)",
							moduleName,
							matching.get(1)));
				}
			}
		}
	}
    
    public void updateList(String moduleName, String actions) {
        ATerm data = getFactory().parse(actions);

        if (data instanceof ATermAppl) {
            ATermAppl applData = (ATermAppl) data;
            data = (ATerm) applData.getArguments().getFirst();
            error("Deprecated use of list with function symbol " + applData.getAFun());
        }

        if (data instanceof ATermList) {
            setContent(moduleName, (ATermList) data);
        } else {
            error("Can't show something in list view which is not a ATermList: " + data);
        }
    }
}
