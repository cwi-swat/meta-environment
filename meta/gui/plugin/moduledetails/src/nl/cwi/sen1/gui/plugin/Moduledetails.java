package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Attribute;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.TableEntry;
import nl.cwi.sen1.moduleapi.types.TableEntryTable;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class Moduledetails extends DefaultStudioPlugin implements ModuledetailsTif {
    private static final String TOOL_NAME = "moduledetails";

    private ModuledetailsBridge bridge;

    private Factory factory;

    private ModuledetailsPanel panel;
    
    public String getName() {
        return TOOL_NAME;
    }
    
    public Moduledetails() {
    }

    public void initStudioPlugin(Studio studio) {
        factory = Factory.getInstance((PureFactory) studio
                .getATermFactory());

        panel = new ModuledetailsPanel();
        
        bridge = new ModuledetailsBridge(studio.getATermFactory(), this);
        bridge.setLockObject(this);
        
        StudioComponent comp = new StudioComponentImpl("Moduledetails", panel) {
            public void requestClose() throws CloseAbortedException {
                throw new CloseAbortedException();
            }
        };
        studio.connect(getName(), bridge);
        ((StudioWithPredefinedLayout) studio).addComponent(comp,
                StudioImplWithPredefinedLayout.BOTTOM_LEFT);
    }
    
    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }

    public void setDetails(ATerm details) {
        AttributeStore store = factory.AttributeStoreFromTerm(details);
        
        while (!store.isEmpty()) {
            Attribute attribute = (Attribute) store.getFirst();
            
            ATerm namespace = attribute.getNamespace();
            TableEntryTable table = attribute.getTable();

            while (!table.isEmpty()) {
                TableEntry entry = (TableEntry) table.getFirst();
            
                ATerm key = entry.getKey();
                ATerm value = entry.getValue();
                panel.setDetails(namespace.toString(), key.toString(), value.toString());
                
                table = (TableEntryTable) table.getNext();
            }
            
            store = (AttributeStore) store.getNext();
        }
    }
}
