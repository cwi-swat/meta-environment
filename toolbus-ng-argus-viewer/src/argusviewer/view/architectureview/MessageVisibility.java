package argusviewer.view.architectureview;

import org.apache.log4j.Logger;
import prefuse.action.GroupAction;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;

import java.util.Iterator;

/**
 * @author: John Franse
 * @author: Tigran Kalaidjan
 */
public class MessageVisibility extends GroupAction {

	private VisualItem m_selectedVisualItem = null;
    private Logger m_logger = Logger.getLogger(MessageVisibility.class);

    /**
	 * Create a default MessageVisibility without extra parameters.
	 */
	public MessageVisibility() {
		super();
	}

	/**
	 * Set the ProcessInstances that should be visible in the visualisation
	 * where this filter is applied to.
	 * @param item VisualItem that should show its communication
	 */
	public void setSelectedVisualItem(VisualItem item) {
		m_selectedVisualItem = item;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	@SuppressWarnings("unchecked")
	public void run(double v) {
		Iterator items = m_vis.items(Message.TABLE_NAME);
        while (items.hasNext()) {
            VisualItem item = (VisualItem) items.next();
            
            String sourceName = (String) item.get(Message.SOURCENAME_FIELDNAME);
            String sourceType = (String) item.get(Message.SOURCETYPE_FIELDNAME);

            String targetName = (String) item.get(Message.TARGETNAME_FIELDNAME);

            m_logger.debug(sourceType);
            
            boolean messageIsVisible = false;
			if (m_selectedVisualItem != null) {
				if (m_selectedVisualItem.canGet(Process.PROCESS_FIELDNAME, String.class)) {
					String processName = (String) m_selectedVisualItem.get(Process.PROCESS_FIELDNAME);					
					messageIsVisible = (processName.equals(sourceName) || processName.equals(targetName));
				} else if (m_selectedVisualItem.canGet(Tool.TOOL_FIELDNAME, String.class)) {
					String toolName = (String) m_selectedVisualItem.get(Tool.TOOL_FIELDNAME);
					messageIsVisible = (toolName.equals(sourceName) || toolName.equals(targetName));
				}
			}
			if (messageIsVisible) {
                m_logger.debug("Set to visible: " + item.get(Message.SOURCENAME_FIELDNAME) + " >> " + item.get(Message.TARGETNAME_FIELDNAME));  
			}

			PrefuseLib.updateVisible(item, messageIsVisible);
        }
	}
}