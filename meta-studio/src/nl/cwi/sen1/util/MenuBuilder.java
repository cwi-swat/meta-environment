package nl.cwi.sen1.util;

import java.awt.Component;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;

import nl.cwi.sen1.configapi.types.ActionDescription;
import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.ItemLabels;
import nl.cwi.sen1.configapi.types.KeyModifier;
import nl.cwi.sen1.configapi.types.KeyModifierList;
import nl.cwi.sen1.configapi.types.ShortCut;
import toolbus.AbstractTool;
import aterm.ATerm;

public class MenuBuilder {
	private AbstractTool bridge;

	public MenuBuilder(AbstractTool bridge) {
		this.bridge = bridge;
	}

	/**
	 * Build a JMenu from a list of menu declarations in ATerm format. This
	 * method may skip the first item the menu path leading up to each menu
	 * item, such that the JMenu can be embedded in a menu bar, as well as in a
	 * popup menu.
	 * 
	 * @param id
	 *            the name of the gui element that owns the menu
	 * @param menuList
	 *            the list of menu options
	 * @param action
	 *            if not null, this action will be executed on clicking the menu
	 * @param skip
	 *            the number of labels to skip
	 * @return
	 */
	public void fill(JMenu menu, ATerm id, ActionDescriptionList menuList, Action action) {
		for (; !menuList.isEmpty(); menuList = menuList.getTail()) {
			ActionDescription first = menuList.getHead();
			Event event = first.getEvent();
			Action exec = action != null ? action : buildMenuAction(id, bridge,
					event);
			addMenuPath(menu, event, exec);
		}
	}
	
	/**
	 * This extension point implements the default reaction to a menu event,
	 * which is forward the event to the ToolBus
	 * 
	 * @param id
	 * @param bridge
	 * @param event
	 * @return
	 */
	protected Action buildMenuAction(ATerm id, AbstractTool bridge, Event event) {
		return new MenuAction(id, bridge, event);
	}

	private void addMenuPath(JMenu menu, Event event, Action action) {
		if (!event.hasLabels()) {
			return;
		}
		
		ItemLabels items = event.getLabels();

		if (items.isEmpty()) {
			return;
		}

		/* traverse the existing menu structure to find a matching path */
		for (; items.getLength() > 1; items = items.getTail()) {
			String text = items.getHead().getName();
			JMenu menuExists = findSubMenu(menu, text);
			if (menuExists == null) {
				menuExists = new JMenu(text);
				menu.add(menuExists);
			}
			menu = menuExists;
		}

		/* add a new leaf to the deepest node of the found path */
		String text = items.getHead().getName();
		JMenuItem leaf = new JMenuItem(action);
		leaf.setText(text);
		if (event.hasShortcut()) {
			KeyStroke keyStroke = createKeyStroke(event.getShortcut());
			if (keyStroke != null) {
				leaf.setAccelerator(keyStroke);
			}
		}
		leaf.setToolTipText(event.getInfo());
		menu.add(leaf);
	}

	private KeyStroke createKeyStroke(ShortCut shortcut) {
		String key = shortcut.getKey().toString();
		KeyModifierList modifiers = shortcut.getList();

		int mask = 0;
		while (!modifiers.isEmpty()) {
			KeyModifier mod = modifiers.getHead();
			modifiers = modifiers.getTail();

			if (mod.isMUnderscoreALT()) {
				mask |= InputEvent.ALT_MASK;
			} else if (mod.isMUnderscoreCTRL()) {
				mask |= InputEvent.CTRL_MASK;
			} else {
				mask |= InputEvent.SHIFT_MASK;
			}
		}

		try {
			return KeyStroke.getKeyStroke(KeyEvent.class.getField(key).getInt(
					KeyEvent.class), mask);
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (NoSuchFieldException e) {
			e.printStackTrace();
		}

		return null;
	}

	private JMenu findSubMenu(JMenu parent, String text) {
		Component[] components = parent.getMenuComponents();
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
