package argusviewer.view.processlist;

import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.HashMap;

import javax.swing.JScrollPane;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;


/**
 * This is the Process List View. It implements {@link IView}, so it can be
 * called. It also starts the other classes needed.
 * 
 * @author R. Schuddeboom
 * @author H. Baggelaar
 * @author J. Pol
 */
@SuppressWarnings("serial")
public class ProcessListView extends JScrollPane implements IView {
	private static final String PLUGINNAME = "Process List";
	private static final String PREFEREDPOSITION = "TopLeft";

	private DataComm m_dataComm;
	private ProcessTreeTable m_table;

	/**
	 * Constructor for ProcessListView.
	 * 
	 * @param dataComm
	 *            A {@link DataComm} instance needed to get required
	 *            information.
	 */
	public ProcessListView(DataComm dataComm) {
		m_dataComm = dataComm;
		m_table = new ProcessTreeTable(m_dataComm);		
		getViewport().add(m_table);
		addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				m_table.requestFocus();		
			}
		});
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPluginName() {
		return PLUGINNAME;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPreferredPosition() {
		return PREFEREDPOSITION;
	}

	/**
	 * {@inheritDoc}
	 */
	public HashMap<String, Container> getVisualComponents() {
		HashMap<String, Container> hashMap = new HashMap<String, Container>();
		hashMap.put(PLUGINNAME, this);
		return hashMap;
	}
}
