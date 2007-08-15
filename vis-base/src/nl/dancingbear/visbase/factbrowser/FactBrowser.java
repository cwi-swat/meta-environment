package nl.dancingbear.visbase.factbrowser;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.tree.DefaultMutableTreeNode;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.types.RType;
import nl.dancingbear.visbase.factbrowser.data.FactBrowserDataManager;
import nl.dancingbear.visbase.factbrowser.data.RStore;
import nl.dancingbear.visbase.factbrowser.data.RStoreFact;
import nl.dancingbear.visbase.factbrowser.data.VisualisationPlugin;
import nl.dancingbear.visbase.rstorecontainer.datatypes.ATermParseException;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfo;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfoList;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.ATerm;
import aterm.ATermList;

/**
 * This class is the main entry point for the toolbus FactBrowserInterface
 * script. It also listens to event from the FactBrowserWindow with the visual
 * tree containing the RStores
 * 
 * <b>DataManager</b> This method has a dataManager which takes care of the
 * registration of new Rstores/Facts/FactTypes and VisualisationPlugins.
 * 
 * <b>RTypes decoding</b> For the decoding of the given Facts with Rtypes, the
 * rstore-container FactInfoList()is used. This will get a container class with
 * all the nessecary information about the Facts.
 * 
 * @extends DefaultStudioPlungin This class makes it possible to add this class
 *          as a plugin in the Meta-Environment.
 * 
 * @implemented FactBrowserTif This is the interface containing the methods
 *              responsible for the communication with the toolbus
 * 
 * @author Renze de Vries
 * @Date 12-02-2007
 */
public class FactBrowser extends DefaultStudioPlugin implements FactbrowserTif,
		MouseListener, ActionListener {
	private static final int SINGLE_CLICK = 1;
	private static final int DOUBLE_CLICK = 2;

	private FactBrowserDataManager dataManager;

	private static final String TOOL_NAME = "factbrowser";

	private static final Log log = LogFactory.getLog(FactBrowser.class);

	private Studio metaStudio;

	private FactbrowserBridge factBrowserBridge;

	private FactBrowserWindow factBrowserWindow;

	private JPopupMenu m_popupMenu;
	private JMenuItem m_unloadMenu;

	/**
	 * This is the default constructor it creates the dataManager and the
	 * visualisationClass
	 * 
	 * @author Renze de Vries
	 * @date 22-02-2007
	 */
	public FactBrowser() {
		dataManager = FactBrowserDataManager.getInstance();
		factBrowserWindow = new FactBrowserWindow();
		m_popupMenu = new JPopupMenu();
		m_unloadMenu = new JMenuItem();
		m_unloadMenu.setText("Unload");
		m_unloadMenu.addActionListener(this);
		m_popupMenu.add(m_unloadMenu);
		factBrowserWindow.add(m_popupMenu);
	}

	/**
	 * <b>ToolbusInterface</b> This method is a toolBus interface required
	 * implementation. It gets as parameters the type of the visualisation, name
	 * and the identifier for the plugin. It passes the visualisation to the
	 * dataManager and signals the visualisationWindow to redraw.
	 * 
	 * 
	 * @param pluginType
	 * @param pluginIdentifier
	 * @param pluginName1
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	public void fbAddVisualizationPlugin(ATerm pluginType,
			int pluginIdentifier, String pluginName) {
		log.debug("Incoming Visualisation plugin with name: " + pluginName
				+ " and identifier: " + pluginIdentifier);
		log.debug("Incoming Visualisation plugin with type: "
				+ pluginType.toString());

		VisualisationPlugin visPlugin = new VisualisationPlugin(pluginName,
				pluginIdentifier);
		dataManager.createVisualisation(visPlugin, dataManager
				.addFactType(pluginType.toString()));

		factBrowserWindow.redrawTree();

	}

	/**
	 * <b>ToolbusInterface</b> This method is an interface for the toolbus
	 * communications. It's task is to add a passed Rstore with all it's
	 * children facts to the dataStore which is managed by the (caching)
	 * dataManager.
	 * 
	 * @param rstoreName
	 * @param rstoreIdentifier
	 * @param rstoreFacts
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	public void fbShowRstoreFacts(String rstoreName, int rstoreIdentifier,
			ATerm rstoreFacts) {

		// Create the RStoreNode and set the parameters Name and Identifier
		RStore rstoreNode = new RStore(rstoreName, rstoreIdentifier);

		// We want to create all children FactNodes so Create a FactInfoList
		FactInfoList factInfoList = null;
		try {
			// Put the ATerm containing the RStore facts in the List
			factInfoList = new FactInfoList((ATermList) rstoreFacts);

			// Iterate through FactInfo list
			for (FactInfo factInfo : factInfoList.getFactInfos()) {
				// Create a new factNode so we can add them to the in memory
				// tree
				RStoreFact factNode = new RStoreFact(factInfo.getName(),
						factInfo.getId(), dataManager.addFactType(factInfo
								.getType()));

				factNode.setRType(factInfo.getRType());

				// add them to the parent RStore
				rstoreNode.addFactNode(factNode);
			}

		} catch (ATermParseException e) {
			e.printStackTrace();
		}

		// Finally add the Rstore to the visual tree
		factBrowserWindow.addRStore(rstoreNode);
	}

	/**
	 * Removes the rstore with the specified rstoreIdentifier from the tree.
	 * 
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 19-03-2007
	 * 
	 * @param rstoreIdentifier
	 */
	public void fbRstoreUnloaded(int rstoreIdentifier) {
		factBrowserWindow.removeRStoreTreeNode(rstoreIdentifier);
	}

	/**
	 * Method must be implemented as part of toolbus compliance
	 */
	public void recAckEvent(ATerm t0) {
	}

	/**
	 * Method will be called when the connection with the toolbus is terminated
	 */
	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}

	/**
	 * This method returns the name of this Tool for the metaStudio.
	 */
	public String getName() {
		return TOOL_NAME;
	}

	/**
	 * This is the entry method for the FactBrowser. When the meta-environment
	 * is started this will be called to add the factBrowser to the studio. It
	 * calls a method which will load the layout with the menu's.
	 * 
	 * @param metaStudio
	 *            This is the instance of the metaStudio
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	public void initStudioPlugin(Studio metaStudio) {
		this.metaStudio = metaStudio;

		factBrowserBridge = new FactbrowserBridge(metaStudio.getATermFactory(),
				this);
		metaStudio.connect(getName(), factBrowserBridge);

		initFactBrowserLayout();
	}

	/**
	 * This method will initialize the layout and add it to the MetaStudio
	 * environment
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	private void initFactBrowserLayout() {
		JMenu rstoreFileMenu = new JMenu("Facts");

		JMenuItem rstoreOpen = new JMenuItem("Load Rstore");
		rstoreOpen.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				openRstore();
			}
		});
		rstoreFileMenu.add(rstoreOpen);

		connectPanelWithMenu(rstoreFileMenu, factBrowserWindow, "Facts",
				StudioImplWithPredefinedLayout.TOP_LEFT);

		factBrowserWindow.setMouseListener(this);
	}

	/**
	 * This method is the action when someone has pushed the menuitem "Load
	 * Rstore". It sends an ATerm to the FactBrowserInterface
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	private void openRstore() {
		ATerm term = metaStudio.getATermFactory().make("fb-load-rstore");
		factBrowserBridge.postEvent(term);
	}

	/**
	 * This methods registers the visual component in the meta-studio and adds
	 * the menu components.
	 * 
	 * @param menu
	 *            This is the menu that's going to be added to the meta-studio
	 * @param panel
	 *            This is the visual component that contains the factBrowser
	 * @param title
	 *            This is the title of the tab the visual component is displayed
	 *            in
	 * 
	 * @copied from ExamplePlugin
	 * 
	 * @author Arjen van Schie
	 */
	private void connectPanelWithMenu(JMenu menu, JPanel panel, String title,
			String orientation) {
		if (panel != null) {
			// generate the meta-studio component from the default
			// implementation
			StudioComponent component = new StudioComponentImpl(title, panel) {
				@Override
				public void requestClose() throws CloseAbortedException {
					throw new CloseAbortedException();
				}
			};

			// add the component to the studio
			((StudioWithPredefinedLayout) metaStudio).addComponent(component,
					orientation);

			// add the menu (if there is any)
			if (menu != null) {
				metaStudio.addComponentMenu(component, menu);
			}
		}
	}

	/**
	 * This method gets the selectedNode in the visual tree and requests the
	 * identifiers from the dataManager. Then it sends it over the toolbus. This
	 * method handles the double clicking on tree nodes and also the right mouse
	 * clicking on rstore nodes so users can unload rstores. Currently no Mac
	 * support is build in.
	 * 
	 * @param mouseEvent
	 *            This contains the event which was generated by the visual
	 *            component
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	public void mouseClicked(MouseEvent mouseEvent) {
		if (mouseEvent.getButton() == MouseEvent.BUTTON1) {
			if (mouseEvent.getClickCount() == DOUBLE_CLICK) {
				mouseDoubleClick(mouseEvent);
			}
		} else if (mouseEvent.getButton() == MouseEvent.BUTTON3) {
			if (mouseEvent.getClickCount() == SINGLE_CLICK) {
				// TODO fix this
				// if (mouseEvent.isPopupTrigger()) {
				showPopupMenu(mouseEvent);
				// }
			}
		}
	}

	/**
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * 
	 * In the future there needs to be Mac support. This isn't fully implemented
	 * yet but it should work something like this.
	 */
	public void mouseReleased(MouseEvent mouseEvent) {
		// TODO fix this
		// if (mouseEvent.isPopupTrigger()) {
		// showPopupMenu(mouseEvent);
		// }
	}

	/**
	 * Handles the double click actions on a rstore tree node and a
	 * visualization treenode. Only the messages will be send, the data itself
	 * will not be handled here.
	 * 
	 * Scenario 1: If the user double clicks on a rstore tree node a message
	 * will be send to the toolbus and requests all the facts within the rstore.
	 * 
	 * Scenario 2: If the user double clicks on a fact tree node a message will
	 * be send to the toolbus to request all the possible visualizations for the
	 * given fact.
	 * 
	 * @author Renze de Vries
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 19-03-2007
	 */
	private void mouseDoubleClick(MouseEvent mouseEvent) {
		factBrowserWindow.selectNodeAtPosition(mouseEvent.getX(), mouseEvent
				.getY());

		DefaultMutableTreeNode selectedNode = factBrowserWindow
				.getSelectedNode();

		if (selectedNode != null) {
			// This is to check if the selection was on a
			// VisualisationPlugin
			if (dataManager.checkValidVisualisationPlugin(selectedNode)) {
				int visPluginID = dataManager.getVisPluginID(selectedNode);
				int factID = dataManager.getFactID(selectedNode);
				int rstoreID = dataManager.getRStoreID(selectedNode);

				// build the Aterm with the given identifiers and send it
				ATerm term = metaStudio.getATermFactory().make(
						"fb-visualization-selected(<int>, <int>, <int>)",
						rstoreID, factID, visPluginID);
				factBrowserBridge.sendEvent(term);
			} else if (dataManager.checkValidRStoreFact(selectedNode)) {
				RType rtype = dataManager.getFactRType(selectedNode);

				ATerm term = metaStudio.getATermFactory().make(
						"fb-type-selected(<term>)", rtype.toTerm());
				factBrowserBridge.sendEvent(term);
			} else if (dataManager.checkValidRStore(selectedNode)) {
				// Do nothing
			} else {
				log.warn("A node was selected which was an invalid type");
			}
		} else {
			log.warn("Double clicked but there was no node selected");
		}
	}

	/**
	 * Shows the unload popup menu at a given position (X & Y).
	 * 
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 19-03-2007
	 * 
	 * @param mouseEvent
	 */
	private void showPopupMenu(MouseEvent mouseEvent) {
		factBrowserWindow.selectNodeAtPosition(mouseEvent.getX(), mouseEvent
				.getY());

		DefaultMutableTreeNode selectedNode = factBrowserWindow
				.getSelectedNode();

		if (selectedNode != null) {
			if (dataManager.checkValidRStore(selectedNode)) {
				int offsetY = factBrowserWindow.getVerticalBarOffset();
				int offsetX = factBrowserWindow.getHorizontalBarOffset();
				mouseEvent.translatePoint(-offsetX, -offsetY);
				m_popupMenu.show(factBrowserWindow, mouseEvent.getX(),
						mouseEvent.getY());
				m_popupMenu.setVisible(true);
			}
		}
	}

	/**
	 * @author Taeke Kooiker
	 * @date 14-08-2007
	 */
	public ATerm getSelectedRstoreid() {
		DefaultMutableTreeNode selectedNode = factBrowserWindow
				.getSelectedNode();

		if (selectedNode != null) {
			while (!(selectedNode.getUserObject() instanceof RStore)
					|| selectedNode.getParent() == null) {
				selectedNode = (DefaultMutableTreeNode) selectedNode
						.getParent();
			}

			if (selectedNode.getUserObject() instanceof RStore) {
				int rstoreID = FactBrowserDataManager.getInstance()
						.getRStoreID(selectedNode);
				ATerm term = metaStudio.getATermFactory().make(
						"snd-value(selected-rstoreid(<int>))", rstoreID);
				return term;
			}
		}
		
		ATerm term = metaStudio.getATermFactory().make("snd-value(no-rstore-selected)");
		return term;
	}

	/**
	 * Sends an unload message when the unload popup menu button has been
	 * clicked.
	 * 
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 19-03-2007
	 */
	public void actionPerformed(ActionEvent actionEvent) {
		if (actionEvent.getSource() == m_unloadMenu) {
			m_popupMenu.setVisible(false);

			DefaultMutableTreeNode selectedNode = factBrowserWindow
					.getSelectedNode();

			if (dataManager.checkValidRStore(selectedNode)) {
				int rstoreID = dataManager.getRStoreID(selectedNode);

				// build the Aterm with RStore FactType
				ATerm term = metaStudio.getATermFactory().make(
						"fb-unload-rstore(<int>)", rstoreID);
				factBrowserBridge.sendEvent(term);
			}
		}
	}

	/**
	 * Redundant method required by mouseListener interface
	 */
	public void mouseEntered(MouseEvent e) {
	}

	/**
	 * Redundant method required by mouseListener interface
	 */
	public void mouseExited(MouseEvent e) {
	}

	/**
	 * Redundant method required by mouseListener interface
	 */
	public void mousePressed(MouseEvent e) {
	}
}
