package metastudio.components;

import java.awt.event.ActionEvent;
import java.util.HashMap;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;

import metastudio.MultiBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

// TODO:  * apification of button actions
//        * simplification of menu construction algorithm
//        * what can be shared with ModulePopupMenu?
//        * add nested menu's?

public class MenuBar extends ToolComponent {
    private static ATerm ACTION_MENUBAR;
    private JMenuBar bar;
    private Map map;

    public MenuBar(ATermFactory factory, MultiBridge bridge, JFrame parent) {
        super(factory, bridge);
        bar = new JMenuBar();
        parent.setJMenuBar(bar);

        
        ACTION_MENUBAR = factory.parse("studio-menubar");

        postEvent(factory.make("get-buttons(<term>,<str>)", ACTION_MENUBAR, "*"));
    }

    public JMenuBar getJMenuBar() {
        return bar;
    }

    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        if (buttonType.equals(ACTION_MENUBAR)) {
            addMenu(buttonType, moduleName, (ATermList) buttons);            
        }
    }

    private JMenu getMenu(String name) {
        JMenu menu;

        if (map == null) {
            map = new HashMap();
        }

        menu = (JMenu) map.get(name);

        if (menu == null) {
            menu = new JMenu(name);
            map.put(name, menu);
            bar.add(menu);
        }

        validate();

        return menu;
    }

    private JMenu findMenuLocation(JMenu[] children, String name) {
        for (int i = 0; i < children.length; i++) {
            if (name.equals(children[i].getText())) {
                return children[i];
            }
        }
        return null;
    }

    private JMenu addMenuName(JMenu menu, String name) {
        JMenu[] children = (JMenu[]) menu.getSubElements();
        JMenu location = findMenuLocation(children, name);

        if (location == null) {
            JMenu newItem = new JMenu(name);
            menu.add(newItem);
            return newItem;
        }

        return location;
    }

    private JMenu getMenuItem(JMenu menu, ATermList names) {
        JMenu cur = menu;

        while (!names.isEmpty()) {
            if (names.getLength() == 1) {
                break;
            } else {
                String name = ((ATermAppl) names.getFirst()).getName();
                cur = addMenuName(cur, name);
                names = names.getNext();
            }
        }

        return cur;
    }

    private void addMenu(final ATerm type, String moduleName, ATermList buttons) {
        while (!buttons.isEmpty()) {
            final ATerm action = buttons.getFirst();
            ATermList menuItems = (ATermList) ((ATermAppl) action).getArgument(0);
            ATerm menuItem = menuItems.getFirst();
            final String menuName = ((ATermAppl) menuItem).getName();
            JMenu menu = getMenuItem(getMenu(menuName), menuItems.getNext());
            String label = getMenuLabel(menuItems.getNext());
            menu.add(new AbstractAction(label) {
                public void actionPerformed(ActionEvent e) {
                    ATerm event =
                        getFactory().make(
                            "button-selected(<term>, <term>)",
                            type,
                            action);

                    postEvent(event);
                }
            });
            buttons = buttons.getNext();
        }
    }

    private String getMenuLabel(ATermList list) {
        return ((ATermAppl) list.getFirst()).getName();
    }
}
