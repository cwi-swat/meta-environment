package nl.cwi.sen1.gui;

import javax.swing.Action;

import aterm.ATerm;

public class MenuItem {
    private ATerm menuPath;

    private Action action;

    public MenuItem(ATerm menuPath, Action action) {
        this.menuPath = menuPath;
        this.action = action;
    }

    public ATerm getMenuPath() {
        return menuPath;
    }

    public Action getAction() {
        return action;
    }
}
