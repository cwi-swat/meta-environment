package argusviewer.view.architectureview;

import java.awt.Container;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JScrollPane;
import javax.swing.JSplitPane;

import prefuse.Visualization;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.architectureview.performance.tree.PerformanceTreeTable;

/**
 * Plugin for the Architecture View.
 * The Architecture View is a representation of the all
 * ToolBus processes and external tools.
 *
 * @author Frank Oppedijk
 */
public class ArchitecturePlugin implements IView{
	private static final String PLUGIN_NAME = "Architecture View";
	private static final String PREFERRED_POSITION = "TopRight";
	private static final int INITIAL_DIVIDER_LOCATION = 300;

	private final Map<String, Container> m_visualComponents;

	/**
	 * Construct a Architecture View plugin.
	 * @param dataCommunication communication protocol for connection to ToolBus
	 */
	public ArchitecturePlugin(DataComm dataCommunication){
		super();
		
		PerformanceTreeTable m_performanceTreeTable = new PerformanceTreeTable();
		JScrollPane toolPane = new JScrollPane(m_performanceTreeTable);
		// Do not show Prefuse INFO messages, only severe errors
		Logger.getLogger("prefuse").setLevel(Level.SEVERE);
		
		Visualization archVisualization = new Visualization();
		ArchitectureData architectureData = new ArchitectureData(archVisualization);
		ArchitectureView m_archView = new ArchitectureView(dataCommunication, architectureData, archVisualization, m_performanceTreeTable);
		new ArchitectureController(dataCommunication, architectureData, m_archView, m_performanceTreeTable);
		
		JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, m_archView.getVisualComponent(), toolPane);
		splitPane.setDividerLocation(INITIAL_DIVIDER_LOCATION);

		Map<String, Container> visualComponents = new HashMap<String, Container>();
		visualComponents.put(PLUGIN_NAME, splitPane);
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
