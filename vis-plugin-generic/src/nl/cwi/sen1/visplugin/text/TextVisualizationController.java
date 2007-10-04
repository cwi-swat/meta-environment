package nl.cwi.sen1.visplugin.text;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * The TableVisualizationController class
 * 
 */
public class TextVisualizationController extends VisualizationPluginController {
	private TextVisualizationWindow m_window;

	private VisPluginTextUnparsing unparser;

	/**
	 * Default constructor.
	 * 
	 */
	public TextVisualizationController() {
		super();
		m_window = null;
	}

	public final void initStudioPlugin(final Studio studioArgument) {
		/* connect this vis tool via the generic vis interface */
		super.initStudioPlugin(studioArgument);

		/* connect a second tool for communicating with lifting and unparsing tools 
		 * asynchronously
		 */
		unparser = new VisPluginTextUnparsing();
		Thread unparserThread = new Thread() {
			public void run() {
				unparser.initStudioPlugin(studioArgument);
			}
		};
		unparserThread.setName(unparser.getName() + "-starter");
		unparserThread.start();
	}

	/**
	 * Return Table visualization window
	 * 
	 */
	public VisualizationPluginWindow createWindow() {
		m_window = new TextVisualizationWindow(unparser);
		return m_window;
	}

	/**
	 * Gets the plugin name [Table Visualization Plugin]
	 * 
	 */
	public String getPluginName() {
		return "Text";
	}

	/**
	 * Define the supported types. Not implemented because we override the
	 * isTypeSupported() function.
	 * 
	 */
	public ATerm[] getSupportedTypes() {
		ATerm[] atermList = new ATerm[0];
		return atermList;
	}

	/**
	 * Check if a type is supported
	 * 
	 * @param type
	 *            The type to check
	 */
	protected boolean isTypeSupported(ATerm type) {
		return true;
	}
}
