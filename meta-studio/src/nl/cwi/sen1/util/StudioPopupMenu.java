package nl.cwi.sen1.util;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.MenuElement;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.Item;
import nl.cwi.sen1.configapi.types.ItemList;
import aterm.ATermList;
import aterm.pure.PureFactory;

//TODO: 
//      * apification of button API stuff
//      * see what's in common with the MenuBar
//      * refactor constant strings...
//      * try to get rid of the duplication between JMenu and JPopupMenu...

public class StudioPopupMenu extends JPopupMenu {
    private Factory factory;

    private PopupHandler handler;

    public StudioPopupMenu(ATermList menus) {
        factory = Factory.getInstance((PureFactory) menus.getFactory());
        
        while (!menus.isEmpty()) {
            Event action = factory.EventFromTerm(menus.getFirst());
            addItem(action);
            menus = menus.getNext();
        }
    }

    private void addItem(Event action) {
        addItem(0, action);
    }

    private void addItem(int level, Event action) {

        boolean found = addSubMenu(level, action);

        if (!found) {
            ItemList path = action.getList();

            if (path.getLength() - 1 == level) {
                addLeafAction(getLabel(action, level), action);
            } else {
                JMenu subMenu = new JMenu(getLabel(action, level));
                add(subMenu);
                addItem(level, action);
            }
        }
    }

    private void addItem(int level, JMenu menu, Event action) {
        boolean found = addSubMenu(level, action, menu);

        if (!found) {
            ItemList path = action.getList();

            if (path.getLength() - 1 == level) {
                addLeafaction(menu, getLabel(action, level), action);
            } else {
                JMenu subMenu = new JMenu(getLabel(action, level));
                menu.add(subMenu);
                addItem(level, menu, action);
            }
        }
    }

    private boolean addSubMenu(int level, Event action) {
        MenuElement[] children = getSubElements();
        return findSubMenu(level, action, children);
    }

    private boolean addSubMenu(int level, Event action, JMenu menu) {
        MenuElement[] children = menu.getSubElements();
        return findSubMenu(level, action, children);
    }

    private boolean findSubMenu(int level, Event action, MenuElement[] children) {
        boolean found = false;
        for (int i = 0; !found && i < children.length; i++) {
            if (children[i] instanceof JMenu) {
                JMenu subMenu = (JMenu) children[i];
                if (subMenu.getText().equals(getLabel(action, level))) {
                    found = true;
                    addItem(level + 1, subMenu, action);
                }
            }
        }
        return found;
    }

    private void addLeafAction(final String label, final Event action) {
        JMenuItem item = makeMenuItem(label, action);
        add(item);
    }

    private void addLeafaction(JMenu menu, final String label,
            final Event action) {
        JMenuItem item = makeMenuItem(label, action);
        menu.add(item);
    }

    private JMenuItem makeMenuItem(final String label, final Event action) {
        JMenuItem item = new JMenuItem(new AbstractAction(label) {
            public void actionPerformed(ActionEvent e) {
                firePopupMenuSelected(action);
            }
        });
        return item;
    }

    protected void firePopupMenuSelected(Event action) {
        if (handler != null) {
            handler.popupSelected(action);
        }
    }

    private String getLabel(Event action, int level) {
        ItemList items = action.getList();
        Item item = (Item) items.getChildAt(level);
        return item.getName();
    }

    public void setPopupHandler(PopupHandler handler) {
        this.handler = handler;
    }

}
