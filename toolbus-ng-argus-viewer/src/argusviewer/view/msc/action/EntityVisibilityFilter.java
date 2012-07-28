package argusviewer.view.msc.action;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import prefuse.action.GroupAction;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.view.msc.data.Entity;

/**
 * @author: Arne Timmerman
 */
public class EntityVisibilityFilter extends GroupAction {
	private final List<Integer> m_visibleProcessInstances;
    private final List<Integer> m_visibleToolInstances;

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
	public void setVisibleProcesses(List<ProcessInstance> visibleProcessInstances){
		synchronized(m_visibleProcessInstances){
			m_visibleProcessInstances.clear();
			for(ProcessInstance processInstance : visibleProcessInstances){
				m_visibleProcessInstances.add(Integer.valueOf(processInstance.getProcessId()));
			}
		}
	}

	/**
	 * Set the ToolInstances that should be visible in the visualisation
	 * where this filter is applied to.
	 * @param visibleToolInstances a list of ToolInstances that should be visible
	 */
	public void setVisibleTools(List<ToolInstance> visibleToolInstances){
		synchronized(m_visibleToolInstances){
			m_visibleToolInstances.clear();
			for (ToolInstance toolInstance : visibleToolInstances){
				int toolId = toolInstance.getToolID();
				m_visibleToolInstances.add(Integer.valueOf(toolId));
			}
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double v){
		Iterator<VisualItem> items = m_vis.items(Entity.TABLE_NAME);

		while(items.hasNext()){
            VisualItem item = items.next();
            Entity.Type entityType = (Entity.Type) item.get(Entity.TYPE_FIELDNAME);
			int entityId = ((Integer) item.get(Entity.ID_FIELDNAME)).intValue();

			boolean entityIsVisible = false;
			if(entityType == Entity.Type.PROCESS){
				synchronized(m_visibleProcessInstances){
					entityIsVisible = m_visibleProcessInstances.contains(Integer.valueOf(entityId));
				}
			}else if(entityType == Entity.Type.TOOL){
				synchronized(m_visibleToolInstances){
					entityIsVisible = m_visibleToolInstances.contains(Integer.valueOf(entityId));
				}
			}else if(entityType == Entity.Type.SINK){
				entityIsVisible = true;
			}else{
				// Error
			}

			PrefuseLib.updateVisible(item, entityIsVisible);
        }
	}

}