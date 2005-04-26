package nl.cwi.sen1.util;

import java.awt.Component;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class StudioMenuBar extends JMenuBar {
	public void addMenuPath(ATerm menuPath, Action action) {

		ATermList menuItems = (ATermList) ((ATermAppl) menuPath).getArgument(0);

		ATerm menuItem = menuItems.getFirst();
		String text = ((ATermAppl) menuItem).getName();
		JMenu menu = addMenu(text);

		menuItems = menuItems.getNext();
		while (menuItems.getLength() > 1) {
			text = ((ATermAppl) menuItems.getFirst()).getName();
			JMenu menuExists = findSubMenu(menu, text);
			if (menuExists == null) {
				menuExists = new JMenu(text);
				menu.add(menuExists);
			}
			menu = menuExists;
			menuItems = menuItems.getNext();
		}

		text = ((ATermAppl) menuItems.getFirst()).getName();
		JMenuItem leaf = new JMenuItem(action);
		leaf.setText(text);
		menu.add(leaf);
	}

	private JMenu addMenu(String text) {
		JMenu menu;
		for (int i = 0; i < getMenuCount(); i++) {
			menu = getMenu(i);
			if (menu.getText().equals(text)) {
				return menu;
			}
		}
		menu = new JMenu(text);
		return add(menu);
	}

	private JMenu findSubMenu(JMenuItem parent, String text) {
		Component[] components = parent.getComponents();
		for (int i = 0; i < components.length; i++) {
			Component cur = components[i];
			if (cur instanceof JMenu) {
				JMenu item = (JMenu) cur;
				if (item.getText().equals(text)) {
					return item;
				}
			}
		}
		return null;
	}
}
