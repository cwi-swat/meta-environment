package nl.cwi.sen1.gui.plugin;



import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import aterm.ATerm;

public class Progress extends DefaultStudioPlugin implements ProgressTif {
    private static final String TOOL_NAME = "progress";

    private ProgressBridge bridge;

    private ProgressPanel panel;
    
    public String getName() {
        return TOOL_NAME;
    }
    
    public Progress() {
    }

    public void initStudioPlugin(Studio studio) {
        panel = new ProgressPanel();
        
        bridge = new ProgressBridge(studio.getATermFactory(), this);
        bridge.setLockObject(this);
        
        StudioComponent comp = new StudioComponentImpl("Progress", panel) {
            public void requestClose() throws CloseAbortedException {
                throw new CloseAbortedException();
            }
        };
        studio.connect(getName(), bridge);
        ((StudioWithPredefinedLayout) studio).addComponent(comp,
                StudioImplWithPredefinedLayout.TOP_LEFT);
    }
    
    public void setStatus(String message, String column, ATerm value) {
        panel.setStatus(message, column, value.toString());
    }

    public void removeStatus(String message) {
        panel.removeStatus(message);
    }
    
    public void clearStatusWindow() {
    }

    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }
}
