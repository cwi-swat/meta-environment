package metastudio.components;

import java.awt.event.ActionEvent;
import java.net.URL;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JToolBar;

import metastudio.UserInterfaceBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class ToolBar extends ToolComponent {
    private JToolBar toolBar;
    private static ATerm ACTION_TOOLBAR;

    public ToolBar(ATermFactory factory, UserInterfaceBridge bridge) {
        super(factory, bridge);
        
        ACTION_TOOLBAR = factory.parse("studio-toolbar");

        toolBar = new JToolBar();
        add(toolBar);
        
        postEvent(factory.make("get-buttons(<term>,<str>)", ACTION_TOOLBAR, "*"));
    }

    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        if (buttonType.equals(ACTION_TOOLBAR)) {
            addToolBarActions((ATermList) buttons);
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
        if (url == null) {
            error("Unable to get icon: " + path);
        } else {
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
