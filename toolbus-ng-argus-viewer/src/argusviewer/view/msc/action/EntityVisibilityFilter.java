package argusviewer.view.msc.action;

import argusviewer.util.ToolbusUtil;
import argusviewer.view.msc.data.Entity;
import aterm.ATerm;
import prefuse.action.GroupAction;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

/**
 * @author: Arne Timmerman
 */
public class EntityVisibilityFilter extends GroupAction {

	private List<Integer> m_visibleProcessInstances;
    private List<Integer> m_visibleToolInstances;

	/**
	 * Create a default EntityVisibilityFilter without extra parameters.
	 */
	public EntityVisibilityFilter() {
		super();

		this.m_visibleProcessInstances = new ArrayList<Integer>();
		this.m_visibleToolInstances = new ArrayList<Integer>();
	}

	/**
	 * Set the ProcessInstances that should be visible in the visualisation
	 * where this filter is applied to.
	 * @param visibleProcessInstances a list of ProcessInstances that should be visible
	 */
	public void setVisibleProcesses(List<ProcessInstance> visibleProcessInstances) {
		m_visibleProcessInstances.clear();
		for (ProcessInstance processInstance : visibleProcessInstances) {
			m_visibleProcessInstances.add(processInstance.getProcessId());
		}
	}

	/**
	 * Set the ToolInstances that should be visible in the visualisation
	 * where this filter is applied to.
	 * @param visibleToolInstances a list of ToolInstances that should be visible
	 */
	public void setVisibleTools(List<ToolInstance> visibleToolInstances) {
		m_visibleToolInstances.clear();
		for (ToolInstance toolInstance : visibleToolInstances) {
			ATerm toolKey = toolInstance.getToolKey();
			m_visibleToolInstances.add(ToolbusUtil.getToolIdFromKey(toolKey));
		}
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	@SuppressWarnings("unchecked")
	public void run(double v) {
		Iterator items = m_vis.items(Entity.TABLE_NAME);

		while (items.hasNext()) {
            VisualItem item = (VisualItem) items.next();
            Entity.Type entityType = (Entity.Type) item.get(Entity.TYPE_FIELDNAME);
			int entityId = (Integer) item.get(Entity.ID_FIELDNAME);

			boolean entityIsVisible = false;
			if (entityType == Entity.Type.PROCESS) {
				entityIsVisible = m_visibleProcessInstances.contains(entityId);
			} else if (entityType == Entity.Type.TOOL) {
				entityIsVisible = m_visibleToolInstances.contains(entityId);
			} else if (entityType == Entity.Type.SINK) {
				entityIsVisible = true;
			} else {
				assert false : "An unknown type of Entity encountered.";
			}

			PrefuseLib.updateVisible(item, entityIsVisible);
        }
	}

}