package metaedit.util;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

// TODO:  * apification of button actions
//        * simplification of menu construction algorithm
//        * what can be shared with ModulePopupMenu?
//        * add nested menu's?

public class MenuBar {
  private JMenuBar bar;
  private Map map;

  public MenuBar(ATermFactory factory) {
    bar = new JMenuBar();
  }

  public JMenuBar getJMenuBar() {
    return bar;
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
      }
      else {
        String name = ( (ATermAppl) names.getFirst()).getName();
        cur = addMenuName(cur, name);
        names = names.getNext();
      }
    }

    return cur;
  }

  public void addMenu(ATermList actionList) {
    JMenu menu=null;
    while (!actionList.isEmpty()) {
      final ATerm action = actionList.getFirst();
      ATermList menuItems = (ATermList) ( (ATermAppl) action).getArgument(0);
      ATerm menuItem = menuItems.getFirst();
      final String menuName = ( (ATermAppl) menuItem).getName();
      menu = getMenuItem(getMenu(menuName), menuItems.getNext());
      String label = getMenuLabel(menuItems.getNext());
      JMenuItem menuItem_ = new JMenuItem();
     menuItem_.setActionCommand(menuName);
     menuItem_.setText(label);
      menu.add(menuItem_);
      actionList = actionList.getNext();
    }
  }

  private String getMenuLabel(ATermList list) {
    return ( (ATermAppl) list.getFirst()).getName();
  }
}
