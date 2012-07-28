package argusviewer.view.architectureview;

import java.util.Iterator;

import prefuse.action.GroupAction;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;

/**
 * @author: John Franse
 * @author: Tigran Kalaidjan
 */
public class MessageVisibility extends GroupAction{
    private volatile VisualItem m_selectedVisualItem = null;

    /**
	 * Create a default MessageVisibility without extra parameters.
	 */
	public MessageVisibility(){
		super();
	}

	/**
	 * Set the ProcessInstances that should be visible in the visualisation
	 * where this filter is applied to.
	 * @param item VisualItem that should show its communication
	 */
	public void setSelectedVisualItem(VisualItem item){
		m_selectedVisualItem = item;
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double v){
		Iterator<VisualItem> items = m_vis.items(Message.TABLE_NAME);
        while (items.hasNext()) {
            VisualItem item = items.next();
            
            String sourceName = (String) item.get(Message.SOURCENAME_FIELDNAME);
            String targetName = (String) item.get(Message.TARGETNAME_FIELDNAME);
            
            boolean messageIsVisible = false;
			if(m_selectedVisualItem != null){
				if(m_selectedVisualItem.canGet(Process.PROCESS_FIELDNAME, String.class)){
					String processName = (String) m_selectedVisualItem.get(Process.PROCESS_FIELDNAME);					
					messageIsVisible = (processName.equals(sourceName) || processName.equals(targetName));
				}else if(m_selectedVisualItem.canGet(Tool.TOOL_FIELDNAME, String.class)){
					String toolName = (String) m_selectedVisualItem.get(Tool.TOOL_FIELDNAME);
					messageIsVisible = (toolName.equals(sourceName) || toolName.equals(targetName));
				}
			}

			PrefuseLib.updateVisible(item, messageIsVisible);
        }
	}
}