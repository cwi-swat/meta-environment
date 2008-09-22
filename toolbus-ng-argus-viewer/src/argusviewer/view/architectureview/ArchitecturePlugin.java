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
public class ArchitecturePlugin implements IView {
	private static final String PLUGIN_NAME = "Architecture View";
	private static final String PREFERRED_POSITION = "TopRight";
	private static final int INITIAL_DIVIDER_LOCATION = 300;

	private final HashMap<String, Container> m_visualComponents;

	private final ArchitectureData architectureData;
	private final Visualization archVisualization;

	/**
	 * Construct a Architecture View plugin.
	 * @param dataCommunication communication protocol for connection to ToolBus
	 */
	public ArchitecturePlugin(DataComm dataCommunication){
		PerformanceTreeTable m_performanceTreeTable = new PerformanceTreeTable();
		JScrollPane toolPane = new JScrollPane(m_performanceTreeTable);
		// Do not show Prefuse INFO messages, only severe errors
		Logger.getLogger("prefuse").setLevel(Level.SEVERE);
		
		archVisualization = new Visualization();
		architectureData = new ArchitectureData(archVisualization);
		ArchitectureView m_archView = new ArchitectureView(dataCommunication, architectureData, archVisualization, m_performanceTreeTable);
		new ArchitectureController(dataCommunication, architectureData, m_archView, m_performanceTreeTable);
		
		JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, m_archView.getVisualComponent(), toolPane);
		splitPane.setDividerLocation(INITIAL_DIVIDER_LOCATION);

		m_visualComponents = new HashMap<String, Container>();
		m_visualComponents.put(PLUGIN_NAME, splitPane);
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
