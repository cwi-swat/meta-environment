package metastudio.components.menubar;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

// TODO:  * apification of button actions
//        * simplification of menu construction algorithm
//        * what can be shared with ModulePopupMenu?
//        * add nested menu's?

public class MenuBar extends JPanel implements MenuBarTif, Runnable {
    private static ATerm ACTION_MENUBAR;
    private JMenuBar bar;
    private Map map;
    private MenuBarBridge bridge;
    private ATermFactory factory;

    public MenuBar(ATermFactory factory, String[] args, JFrame parent) {
    	this.factory = factory;
    	
    	setLayout(new BorderLayout());
    	
        bar = new JMenuBar();
        parent.setJMenuBar(bar);

        
        ACTION_MENUBAR = factory.parse("studio-menubar");

        try {
        	bridge = new MenuBarBridge(factory, this);
        	bridge.init(args);
        	bridge.setLockObject(this);
        	bridge.connect("menu-bar", null, -1);
        } catch (IOException e) {
        	e.printStackTrace();
        }
    }

    public JMenuBar getJMenuBar() {
        return bar;
    }

    public void addEvents(ATerm events) {
            addMenu((ATermList) events);            
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

    private void addMenu(ATermList buttons) {
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
                        factory.make(
                            "button-selected(<term>)", action);

                    bridge.postEvent(event);
                }
            });
            buttons = buttons.getNext();
        }
    }

    private String getMenuLabel(ATermList list) {
        return ((ATermAppl) list.getFirst()).getName();
    }

	public void recAckEvent(ATerm t0) {
		
	}

	public void recTerminate(ATerm t0) {
		
	}

	public void run() {
		bridge.run();
	}
}
