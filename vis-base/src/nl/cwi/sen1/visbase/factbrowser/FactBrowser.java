package nl.cwi.sen1.visbase.factbrowser;

import java.awt.event.MouseEvent;
import java.util.Iterator;

import javax.swing.tree.DefaultMutableTreeNode;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.util.DefaultPopupImpl;
import nl.cwi.sen1.util.MouseAdapter;
import nl.cwi.sen1.visbase.factbrowser.data.FactBrowserDataManager;
import nl.cwi.sen1.visbase.factbrowser.data.RStore;
import nl.cwi.sen1.visbase.factbrowser.data.RStoreFact;
import nl.cwi.sen1.visbase.factbrowser.data.VisualisationPlugin;
import nl.dancingbear.visbase.rstorecontainer.datatypes.ATermParseException;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfo;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfoList;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

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
public class FactBrowser extends DefaultStudioPlugin implements FactbrowserTif {
	private static final int DOUBLE_CLICK = 2;

	private FactBrowserDataManager dataManager;

	private static final String TOOL_NAME = "factbrowser";

	private static final Log log = LogFactory.getLog(FactBrowser.class);

	private Factory configFactory;

	private Studio studio;

	private StudioComponent component;

	private FactbrowserBridge bridge;

	private FactBrowserWindow factBrowserWindow;

	private DefaultPopupImpl popup;

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

		Iterator<RStoreFact> iterator = rstoreNode.getFactNodes().iterator();
		while (iterator.hasNext()) {
			RType rtype = iterator.next().getRType();

			ATerm term = studio.getATermFactory().make(
					"fb-type-selected(<term>)", rtype.toTerm());
			bridge.sendEvent(term);
		}

		studio.makeVisible(component);
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

	private ATerm createEventId(ATerm moduleId) {
		return studio.getATermFactory().make(TOOL_NAME + "(<term>)", moduleId);
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
		this.studio = metaStudio;
		this.configFactory = Factory.getInstance((PureFactory) metaStudio
				.getATermFactory());
		bridge = new FactbrowserBridge(metaStudio.getATermFactory(), this);
		popup = new DefaultPopupImpl(bridge);
		metaStudio.connect(getName(), bridge);

		addFactBrowserComponent();
	}

	/**
	 * This method will initialize the layout and add it to the MetaStudio
	 * environment
	 * 
	 * @author Renze de Vries
	 * @date 20-02-2007
	 */
	private void addFactBrowserComponent() {
		final ATerm id = configFactory.getPureFactory().parse(TOOL_NAME);
		final Event popupAction = configFactory.makeEvent_Popup();

		factBrowserWindow.addMouseListener(new MouseAdapter(id, bridge,
				popupAction) {
			@Override
			public void mousePressed(MouseEvent e) {
				factBrowserWindow.selectNodeAtPosition(e.getX(), e.getY());

				ATerm rStoreId = getSelectedRStoreId();
				if (rStoreId != null) {
					setId(createEventId(rStoreId));
					super.mousePressed(e);
				}
			}

			@Override
			public void mouseClicked(MouseEvent e) {
				if (e.getButton() == MouseEvent.BUTTON1) {
					if (e.getClickCount() == DOUBLE_CLICK) {
						mouseDoubleClick(e);
					}
				}
			}
		});

		component = new StudioComponentImpl("Facts", factBrowserWindow) {
			@Override
			public void requestClose() throws CloseAbortedException {
				throw new CloseAbortedException();
			}
		};
		((StudioWithPredefinedLayout) studio).addComponent(component,
				StudioImplWithPredefinedLayout.TOP_LEFT);

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
				ATerm term = studio.getATermFactory().make(
						"fb-visualization-selected(<int>, <int>, <int>)",
						rstoreID, factID, visPluginID);
				bridge.sendEvent(term);
			} else if (dataManager.checkValidRStoreFact(selectedNode)) {
			} else if (dataManager.checkValidRStore(selectedNode)) {
			} else {
				log.warn("A node was selected which was an invalid type");
			}
		} else {
			log.warn("Double clicked but there was no node selected");
		}
	}

	/**
	 * @author Taeke Kooiker
	 * @date 14-08-2007
	 */
	public void showPopup(int RStoreId, ATerm menuList) {
		ActionDescriptionList l = configFactory
				.ActionDescriptionListFromTerm(menuList);
		popup.showPopup(menuList.getFactory().makeInt(RStoreId), l);
	}

	/**
	 * @author Taeke Kooiker
	 * @date 14-08-2007
	 */
	public ATerm getSelectedRstoreid() {
		ATerm rStoreId = getSelectedRStoreId();

		if (rStoreId != null) {
			ATerm term = studio.getATermFactory().make(
					"snd-value(selected-rstoreid(<term>))", rStoreId);
			return term;
		}

		ATerm term = studio.getATermFactory().make(
				"snd-value(no-rstore-selected)");
		return term;
	}

	/**
	 * @author Taeke Kooiker
	 * @date 15-08-2007
	 */
	private ATerm getSelectedRStoreId() {
		DefaultMutableTreeNode selectedNode = factBrowserWindow
				.getSelectedNode();

		if (selectedNode != null) {
			while (!(selectedNode.getUserObject() instanceof RStore)
					|| selectedNode.getParent() == null) {
				selectedNode = (DefaultMutableTreeNode) selectedNode
						.getParent();
			}

			if (selectedNode.getUserObject() instanceof RStore) {
				int id = FactBrowserDataManager.getInstance().getRStoreID(
						selectedNode);
				return studio.getATermFactory().makeInt(id);
			}
		}

		return null;
	}
}
