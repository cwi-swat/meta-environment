package argusviewer.view.consoleview;

import java.awt.BorderLayout;
import java.awt.Container;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import argusviewer.view.IView;

/**
 * This class implements the ConsoleView Panel for the Argus Viewer
 * 
 * @author M. van Beest
 */
public class ConsoleViewPanel extends JPanel implements IView {
	private static final long serialVersionUID = -5391911104562410731L;
	
	public static final String CONSOLE_VIEW_NAME = "Console";
	public static final String PREFERRED_POSITION = "DownLeft";
	
	private final ConsoleViewOutputStream m_consoleViewOutputStream;
	private final ConsoleViewErrorStream m_consoleViewErrorStream;
	
	private final PrintStream m_originalErrorStream; 
	
	/*
	 * The graphical components 
	 */
	private ConsoleViewColorPane m_textPane = new ConsoleViewColorPane();
	private JScrollPane m_scrollPane = new JScrollPane(m_textPane);
	
	/**
	 * Constructs the Console View Panel and prepares the outputbuffers
	 */
	public ConsoleViewPanel() {
		this.setLayout(new BorderLayout());
		
		this.add(m_scrollPane, BorderLayout.CENTER);
		m_textPane.setEditable(false);
		m_scrollPane.setAutoscrolls(true);

		m_consoleViewOutputStream = new ConsoleViewOutputStream(m_textPane);
		System.setOut(new PrintStream(m_consoleViewOutputStream));
		
		m_originalErrorStream = System.err;
		m_consoleViewErrorStream = new ConsoleViewErrorStream(m_textPane, m_originalErrorStream);				
		System.setErr(new PrintStream(m_consoleViewErrorStream));		
	}
	
	
	/**
	 * Gets the plugin name
	 * @return the name of the plugin
	 */
	public String getPluginName(){
		return CONSOLE_VIEW_NAME;
	}

	/**
	 * Gets the preferred position of the panel
	 * @return the preferred position
	 */
	public String getPreferredPosition(){
		return PREFERRED_POSITION;
	}

	/**
	 * Returns the visual components that show the actual panelcontents
	 * @return A map with the visual components and their names
	 */
	public Map<String, Container> getVisualComponents(){
		HashMap<String, Container> nameContainerHashMap = new HashMap<String, Container>(1);
		nameContainerHashMap.put(CONSOLE_VIEW_NAME, this);
		
		return nameContainerHashMap;
	}
}
