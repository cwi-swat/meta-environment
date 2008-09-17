package argusviewer.view.architectureview;

import java.awt.Container;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JScrollPane;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.architectureview.performance.tree.PerformanceTreeTable;

import prefuse.Visualization;

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

	private HashMap<String, Container> m_visualComponents;

	private PerformanceTreeTable m_performanceTreeTable;
	private ArchitectureData m_architectureData;
	private Visualization m_archVisualization;
	private ArchitectureView m_archView;
	private ArchitectureController m_architectureController; 

	/**
	 * Construct a Architecture View plugin.
	 * @param dataCommunication communication protocol for connection to ToolBus
	 */
	public ArchitecturePlugin(DataComm dataCommunication) {
		m_performanceTreeTable = new PerformanceTreeTable();
		JScrollPane toolPane = new JScrollPane(m_performanceTreeTable);
		// Do not show Prefuse INFO messages, only severe errors
		Logger.getLogger("prefuse").setLevel(Level.SEVERE);
		

		m_architectureData = new ArchitectureData();
		m_archVisualization = new Visualization();
		m_archView = new ArchitectureView(dataCommunication, m_architectureData, m_archVisualization, m_performanceTreeTable);
		m_architectureController = new ArchitectureController(dataCommunication, m_architectureData, m_archView, m_performanceTreeTable);
		
		ArchitectureSplitPane splitPane = new ArchitectureSplitPane(m_archView.getVisualComponent(), toolPane);

		m_visualComponents = new HashMap<String, Container>();
		m_visualComponents.put(PLUGIN_NAME, splitPane);
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPluginName() {
		return PLUGIN_NAME;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPreferredPosition() {
		return PREFERRED_POSITION;
	}

	/**
	 * {@inheritDoc}
	 */
	public Map<String, Container> getVisualComponents() {
		return m_visualComponents;
	}

	/**
	 * ArchitectureController getter for testing purposes. 
	 * @return ArchitectureController 
	 */
	protected ArchitectureController getArchitectureController() {
		return m_architectureController;
	}
	
	/**
	 * ArchitectureView getter for testing purposes.
	 * @return ArchitectureView
	 */
	protected ArchitectureView getArchitectureView() {
		return m_archView;
	}
	
	/**
	 * Visualizationgetter for testing purposes.
	 * @return the architecture visualization
	 */
	protected Visualization getVisualization() {
		return m_archVisualization;
	}
	
	/**
	 * ArchitectureData getter for testing purposes.
	 * @return ArchitectureData
	 */
	protected ArchitectureData getArchitectureData() {
		return m_architectureData; 
	}
	
	/**
	 * PerformanceTreeTable getter for testing purposes.
	 * @return PerformanceTreeTable
	 */
	protected PerformanceTreeTable getPerformanceTreeTable() {
		return m_performanceTreeTable;
	}
}
