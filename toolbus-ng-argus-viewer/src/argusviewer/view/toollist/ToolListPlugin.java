package argusviewer.view.toollist;

import java.awt.Container;
import java.util.HashMap;
import java.util.Map;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;


/**
 * ToolListPlugin provides a view that represents a visualisation of Tools from a ToolBus script.
 *
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class ToolListPlugin implements IView{
	private final Map<String, Container> m_visualComponents;
	private final ToolListView m_toolListView;

	public static final String PLUGIN_NAME = "Tool List";
	private static final String PREFERRED_POSITION = "CenterLeft";

	/**
	 * Constructor for ToolListPlugin.
	 *
	 * @param dataComm DataComm to get the required information
	 */
	public ToolListPlugin(DataComm dataComm){
		super();
		
		m_toolListView = new ToolListView();
		new ToolListController(dataComm, m_toolListView);
		
		Map<String, Container> visualComponents = new HashMap<String, Container>();
		visualComponents.put(PLUGIN_NAME, m_toolListView);
		m_visualComponents = visualComponents;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPluginName(){
		return PLUGIN_NAME;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPreferredPosition(){
		return PREFERRED_POSITION;
	}

	/**
	 * {@inheritDoc}
	 */
	public Map<String, Container> getVisualComponents(){
		return m_visualComponents;
	}
}
