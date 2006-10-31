package nl.cwi.sen1.util;

import java.awt.Component;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JPopupMenu;

import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import toolbus.AbstractTool;
import aterm.ATerm;

public class StudioPopupMenu extends JPopupMenu {
	public StudioPopupMenu(ATerm id, AbstractTool bridge, ActionDescriptionList menus, Action action) {
		MenuBuilder menuBuilder = new MenuBuilder(bridge);
		JMenu menu = new JMenu();
		menuBuilder.fill(menu, id, menus, action);
		addAll(menu);
	}
	
	public void addAll(JMenu menu) {
		Component[] components = menu.getMenuComponents();
		for (Component c : components) {
			add(c,0);
		}
	}
}
