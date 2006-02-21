package nl.cwi.sen1.util;

import java.awt.Component;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;
import javax.swing.event.MenuKeyEvent;

import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.ItemList;
import nl.cwi.sen1.configapi.types.KeyModifier;
import nl.cwi.sen1.configapi.types.ShortCut;

public class StudioMenuBar extends JMenuBar {
    public void addMenuPath(Event event, Action action) {
        ItemList items = event.getList();

        String text = items.getHead().getName();
        JMenu menu = addMenu(text);

        items = items.getTail();
        while (items.getLength() > 1) {
            text = items.getHead().getName();
            JMenu menuExists = findSubMenu(menu, text);
            if (menuExists == null) {
                menuExists = new JMenu(text);
                menu.add(menuExists);
            }
            menu = menuExists;
            items = items.getTail();
        }

        text = items.getHead().getName();
        JMenuItem leaf = new JMenuItem(action);
        leaf.setText(text);
        if (event.hasShortcut()) {
            KeyStroke keyStroke = createKeyStroke(event.getShortcut());
            if (keyStroke != null) {
                leaf.setAccelerator(keyStroke);
            }
        }
        menu.add(leaf);
    }

    private KeyStroke createKeyStroke(ShortCut shortcut) {
        String key = shortcut.getKey().toString();
        KeyModifier mod = shortcut.getModifier();
        int mask;
        
        if (mod.isMUnderscoreALT()) {
            mask = InputEvent.ALT_MASK;
        }
        else if (mod.isMUnderscoreCTRL()) {
            mask = InputEvent.CTRL_MASK;
        }
        else {
            mask = InputEvent.SHIFT_MASK;
        }
        
        try {
            return KeyStroke.getKeyStroke(KeyEvent.class.getField(key).getInt(KeyEvent.class),mask);
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
