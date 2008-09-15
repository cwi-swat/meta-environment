package argusviewer.view.msc;

import java.awt.Container;
import java.util.HashMap;
import java.util.Map;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.msc.data.MSCData;
import argusviewer.view.msc.visual.MSCVisualization;


/**
 * Plugin for the Message Sequence Chart.
 * The Message Sequence Chart is a sequential representation of the
 * execution of statements and messages of ToolBus processes and
 * external tools.
 *
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Arne Timmerman
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author Alexander Bij
 * @author Roberto vd Linden
 */
public class MSCPlugin implements IView {

	private static final String PLUGIN_NAME = "Message Sequence Chart";
	private static final String PREFERRED_POSITION = "TopRight";

	private HashMap<String, Container> m_visualComponents;

	/**
	 * Construct a Message Sequence Chart plugin.
	 * @param dataCommunication communication protocol for connection to ToolBus
	 */
	public MSCPlugin(DataComm dataCommunication) {
		MSCData mscData = new MSCData();
		MSCVisualization mscVisualisation = new MSCVisualization(mscData);
		MSCView mscView = new MSCView(mscVisualisation);
		MSCController mscController = new MSCController(dataCommunication, mscData, mscVisualisation, mscView);
		mscController.initialize();

		m_visualComponents = new HashMap<String, Container>();
		m_visualComponents.put(PLUGIN_NAME, mscView);
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

}
