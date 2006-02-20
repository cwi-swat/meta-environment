package nl.cwi.sen1.gui;

import javax.swing.Action;
import javax.swing.KeyStroke;

import aterm.ATerm;

public class MenuItem {
    private ATerm menuPath;

    private Action action;
    
    private KeyStroke keyStroke;

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
    
    public void setAccelerator(KeyStroke keyStroke) {
        this.keyStroke = keyStroke;
    }
    
    public KeyStroke getAccelerator() {
        return keyStroke;
    }
}
