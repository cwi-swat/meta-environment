package metastudio.components.toolbar;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.net.URL;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JToolBar;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class ToolBar extends JPanel implements ToolBarTif, Runnable {
    private JToolBar toolBar;
    private ToolBarBridge bridge;
    private ATermFactory factory;
	
    public ToolBar(ATermFactory factory, String [] args) {
    	this.factory = factory;
    	
        setLayout(new BorderLayout());
        
        toolBar = new JToolBar();
        add(toolBar);
        
        try {
        	bridge = new ToolBarBridge(factory, this);
        	bridge.init(args);
        	bridge.setLockObject(this);
        	bridge.connect("tool-bar", null, -1);
        } catch (IOException e) {
        	remove(toolBar);
        	e.printStackTrace();
        }
    }

    public void addEvents(ATerm events) {
        addToolBarActions((ATermList) events);
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
        String path = "/toolbarButtonGraphics/general/" + name; 
        URL url = path.getClass().getResource(path);
        if (url != null) {
            Icon icon = new ImageIcon(url);
            Action it = new AbstractAction(label, icon) {
                public void actionPerformed(ActionEvent actionEvent) {
                    ATerm event =
                        factory.make(
                            "button-selected(<term>)",
                            action);
                    bridge.postEvent(event);
                }
            };
            JButton button = toolBar.add(it);
            button.setToolTipText(label);
        }
    }

	public void recAckEvent(ATerm t0) {
		
	}

	public void recTerminate(ATerm t0) {
		
	}

	public void run() {
		bridge.run();
	}
}
