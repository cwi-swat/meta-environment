package metastudio.components;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JComponent;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.MenuElement;

import metastudio.UserInterfaceBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

//TODO: * fix difference between module-popup and new-module-popup, this
//        has dissappeared in the last refactoring...
//      * apification of button API stuff
//      * see what's in common with the MenuBar
//      * refactor constant strings...
//      * try to get wrid of the duplication between JMenu and JPopupMenu...

public class ModulePopupMenu extends ToolComponent {
    private static ATerm ACTION_MODULE_POPUP;
    private static ATerm ACTION_NEW_MODULE_POPUP;

    private static JComponent _parent;
    private static int _x;
    private static int _y;

    public ModulePopupMenu(ATermFactory factory, UserInterfaceBridge bridge) {
        super(factory, bridge);

        ACTION_MODULE_POPUP = factory.parse("module-popup");
        ACTION_NEW_MODULE_POPUP = factory.parse("new-module-popup");

    }

    /**
	 * Use to store coordinates for showing future popups
	 * 
	 * @param mouseX
	 * @param mouseY
	 */
    public static void setPopupLocation(JComponent parent, int x, int y) {
        _x = x;
        _y = y;
        _parent = parent;
    }

    public void buttonsFound(ATerm type, String moduleName, ATerm buttons) {
        if (type.equals(ACTION_MODULE_POPUP) || type.equals(ACTION_NEW_MODULE_POPUP)) {
            showModulePopup(type, moduleName, buttons, _parent, _x, _y);
        }
    }

    private void showModulePopup(
        final ATerm type,
        final String moduleName,
        ATerm buttons,
        JComponent parent,
        int x,
        int y) {
        ATermList list = (ATermList) buttons;
        JPopupMenu menu = makePopup(type, moduleName, list);
        menu.show(parent, x, y);
    }

    private JPopupMenu makePopup(
        final ATerm type,
        final String moduleName,
        ATermList list) {
        JPopupMenu menu = new JPopupMenu();
        for (; !list.isEmpty(); list = list.getNext()) {
            ATerm button = list.getFirst();
            addItem(menu, type, moduleName, button);
        }
        return menu;
    }

    private void addItem(JPopupMenu menu, ATerm type, String moduleName, ATerm button) {
        addItem(0, menu, type, moduleName, button);
    }

    private void addItem(
        int level,
        JPopupMenu menu,
        ATerm type,
        String moduleName,
        ATerm button) {

        boolean found = addSubMenu(level, type, moduleName, button, menu);

        if (!found) {
            ATermList path = getPath(button);

            if (path.getLength() - 1 == level) {
                addLeafButton(menu, type, moduleName, getLabel(button, level), button);
            } else {
                JMenu subMenu = new JMenu(getLabel(button, level));
                menu.add(subMenu);
                addItem(level, menu, type, moduleName, button);
            }
        }
    }

    private void addItem(
            int level,
            JMenu menu,
            ATerm type,
            String moduleName,
            ATerm button) {
        boolean found = addSubMenu(level, type, moduleName, button, menu);

        if (!found) {
            ATermList path = getPath(button);

            if (path.getLength() - 1 == level) {
                addLeafButton(menu, type, moduleName, getLabel(button, level), button);
            } else {
                JMenu subMenu = new JMenu(getLabel(button, level));
                menu.add(subMenu);
                addItem(level, menu, type, moduleName, button);
            }
        }
    }
    
    
    private boolean addSubMenu(
        int level,
        ATerm type,
        String moduleName,
        ATerm button,
        JPopupMenu menu) {
        MenuElement[] children = (MenuElement[]) menu.getSubElements();
        return findSubMenu(level, type, moduleName, button, children);
    }
    
    private boolean addSubMenu(
            int level,
            ATerm type,
            String moduleName,
            ATerm button,
            JMenu menu) {
        MenuElement[] children = (MenuElement[]) menu.getSubElements();
        return findSubMenu(level, type, moduleName, button, children);
    }

    private boolean findSubMenu(int level, ATerm type, String moduleName, ATerm button, MenuElement[] children) {
        boolean found = false;
        for (int i = 0; !found && i < children.length; i++) {
            if (children[i] instanceof JMenu) {
                JMenu subMenu = (JMenu) children[i];
                if (subMenu.getText().equals(getLabel(button, level))) {
                    found = true;
                    addItem(level + 1, subMenu, type, moduleName, button);
                }
            }
        }
        return found;
    }

    private void addLeafButton(
        JPopupMenu menu,
        final ATerm type,
        final String moduleName,
        final String label,
        final ATerm action) {
        JMenuItem item = makeMenuItem(type, moduleName, label, action);
        menu.add(item);
    }
    
    private void addLeafButton(
            JMenu menu,
            final ATerm type,
            final String moduleName,
            final String label,
            final ATerm action) {
        JMenuItem item = makeMenuItem(type, moduleName, label, action);
        menu.add(item);
    }
    
    private JMenuItem makeMenuItem(
        final ATerm type,
        final String moduleName,
        final String label,
        final ATerm action) {
        JMenuItem item = new JMenuItem(action.toString());
        item.setAction(new AbstractAction(label) {
            public void actionPerformed(ActionEvent e) {
                ATerm event =
                    getFactory().make(
                        "button-selected(<term>, <str>,<term>)",
                        type,
                        moduleName,
                        action);

                postEvent(event);
            }
        });
        return item;
    }
    
    private String getLabel(ATerm button, int level) {
        ATermList path = getPath(button);
        ATermAppl label = (ATermAppl) path.elementAt(level);
        return label.getName();
    }

    private ATermList getPath(ATerm button) {
        ATermList path = (ATermList) ((ATermAppl) button).getArgument(0);
        return path;
    }
    

}
