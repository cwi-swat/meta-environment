package metastudio.components;

import java.awt.event.ActionEvent;
import java.net.URL;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JToolBar;

import metastudio.*;
import metastudio.MultiBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class ToolBar extends UserInterfacePanel {
    private JToolBar toolBar;
    private static ATerm ACTION_TOOLBAR;

    public ToolBar(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        
        ACTION_TOOLBAR = factory.parse("studio-toolbar");

        toolBar = new JToolBar();
        add(toolBar);
        
        postEvent(factory.make("get-events(<term>)", ACTION_TOOLBAR));
    }

    public void addEvents(ATerm type, ATerm events) {
        if (type.equals(ACTION_TOOLBAR)) {
            addToolBarActions((ATermList) events);
        }
    }
    
    public void addToolBarActions(ATermList buttons) {
        while (!buttons.isEmpty()) {
            ATerm button = buttons.getFirst();
            addToolBarAction((ATermAppl) button);
            buttons = buttons.getNext();
        }
    }
    
    // TODO: radically improve this  by apification
    private void addToolBarAction(final ATermAppl action) {
        String label = ((ATermAppl) action.getArgument(0)).getName();
        String name = ((ATermAppl) action.getArgument(1)).getName();
        String path = "/images/" + name; 
        URL url = path.getClass().getResource(path);
        if (url != null) {
            Icon icon = new ImageIcon(url);
            Action it = new AbstractAction(label, icon) {
                public void actionPerformed(ActionEvent actionEvent) {
                    ATerm event =
                        getFactory().make(
                            "button-selected(<term>,<term>)",
                            ACTION_TOOLBAR,
                            action);
                    postEvent(event);
                }
            };
            JButton button = toolBar.add(it);
            button.setToolTipText(label);
        }
    }
}
