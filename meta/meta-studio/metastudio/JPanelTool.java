package metastudio;

import javax.swing.JPanel;

import aterm.ATerm;
import aterm.ATermFactory;

public abstract class JPanelTool extends JPanel {
    private ATermFactory factory;
    private UserInterfaceBridge bridge;
    
    public JPanelTool(ATermFactory factory, UserInterfaceBridge bridge) {
        this.factory = factory;
        this.bridge = bridge;
    }
    
    protected void postEvent(ATerm event) {
        getBridge().postEvent(event);
    }
    
    protected ATermFactory getFactory() {
        return factory;
    }
    
    protected UserInterfaceBridge getBridge() {
        return bridge;
    }
}
