package metastudio;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import aterm.ATerm;
import aterm.ATermList;
import aterm.ParseError;
import aterm.pure.PureFactory;

public class MessageWindow extends JFrame implements ListSelectionListener {
	private JList list;
	private String moduleName;
	private UserInterfaceBridge bridge;
	private PureFactory factory;
	private ATermList data;

	public MessageWindow(UserInterfaceBridge bridge, PureFactory factory) {
		this.bridge = bridge;
		this.factory = factory;

		list = new JList();
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addListSelectionListener(this);

		Container content = getContentPane();
		JPanel mainPanel = new JPanel();

		mainPanel.setLayout(new BorderLayout());
		mainPanel.setBorder(BorderFactory.createTitledBorder("Messages"));
		mainPanel.add(new JScrollPane(list), BorderLayout.CENTER);
		content.setLayout(new BorderLayout());
		content.add(mainPanel, BorderLayout.CENTER);

		setTitle("Message list");
		setSize(300, 400);

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
					bridge.postEvent(
						factory.make(
							"element-selected(<str>,<term>)",
							moduleName,
							matching.get(1)));
				}
			}
		}
	}
}
