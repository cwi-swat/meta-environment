package nl.cwi.sen1.visbase.factbrowser;

import javax.swing.tree.DefaultMutableTreeNode;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.visbase.factbrowser.data.FactBrowserDataManager;
import nl.cwi.sen1.visbase.factbrowser.data.RStore;
import nl.cwi.sen1.visbase.factbrowser.data.RStoreFact;
import nl.cwi.sen1.visbase.factbrowser.data.RStoreFactType;
import nl.cwi.sen1.visbase.factbrowser.data.VisualisationPlugin;
import aterm.pure.PureFactory;

/**
 * This is the class which tests the toolbus interfaces as far as is possible.
 * 
 * <br>
 * <b>Classes not tested</b> FactBrowserDemo - This class was not tested
 * because it only contains visual items FactBrowserTif - This class was not
 * tested because toolbus generated file FactBrowserTool - This class was not
 * tested because toolbus generated file FactBrowserBridge - This class was not
 * tested because toolbus generated file
 * 
 * <br>
 * <b>methods not tested</b> FactBrowser.fbShowRstoreFacts - Not tested because
 * of complex RStoreFacts which must be composed FactBrowser.recAckEvent - This
 * is a blank method simply for toolbus compatibility FactBrowser.recTerminate -
 * This is a method which is called when the toolbus is terminating
 * FactBrowser.initStudioPlugin - Can only be tested when connected to the
 * MetaStudio FactBrowser.initFactBrowserLayout - This is a visual method so can
 * only be tested with a visual environment FactBrowser.openRstore - Can only be
 * tested when connected to the MetaStudio FactBrowser.connectPanelWithMenu -
 * Can only be tested when connected to the MetaStudio
 * 
 * @author Renze de Vries
 * @date 22-02-2007
 * 
 */
public class FactBrowserTest extends TestCase {
	private PureFactory pureFactory = null;

	private Factory factory = null;

	private FactBrowser factBrowser = null;

	/**
	 * This method sets up the Unit Test so the nessecary factory instances are
	 * present.
	 * 
	 * @author Renze de Vries
	 * @date 22-02-2007
	 */
	protected void setUp() {
		pureFactory = FactBrowserFactorySingleton.getPureFactoryInstance();
		factory = FactBrowserFactorySingleton.getFactoryInstance();
		factBrowser = new FactBrowser();
	}

	/**
	 * Test if the correct toolname is given for the FactBrowser
	 * 
	 * @author Renze de Vries
	 * @date 22-02-2007
	 */
	public void testToolName() {
		assertEquals("This is not the correct toolname", "factbrowser",
				factBrowser.getName());
	}

	/**
	 * This method tests is the initialisations in the "SetUp" are working as
	 * should be.
	 * 
	 * @author Renze de Vries
	 * @date 12-03-2007
	 */
	public void testFactory() {
		assertNotNull("The factory should not be null", factory);

		assertNotNull("The FactBrowser should not be null", factBrowser);

		assertNotNull("The pureFactory should not be null", pureFactory);
	}

	/**
	 * This method tests if it is possible to add a visualisation plugin to the
	 * FactBrowser
	 * 
	 * @author Renze de Vries
	 * @date 22-02-2007
	 */
	public void testAddVisualisation() {
		factBrowser.fbAddVisualizationPlugin(pureFactory.make("<str>",
				"<str>,<str>"), 1, "Visualisatie Test Plugin");

		RStoreFactType factType = FactBrowserDataManager.getInstance()
				.addFactType("\"<str>,<str>\"");

		RStoreFactType factTypeCompare = FactBrowserDataManager.getInstance()
				.addFactType("<str>,<str>");

		assertNotSame("The two given factTypes should not be the same",
				factType, factTypeCompare);

		assertEquals("There should be a added visualisation plugin", 1,
				factType.getVisualisationPlugins().size());
	}

	/**
	 * Test it the visualisationWindow will create
	 * 
	 * @author Renze de Vries
	 * @date 07-03-2007
	 */
	public void testVisualisationWindow() {
		FactBrowserWindow factBrowserWindow = new FactBrowserWindow();

		assertNotNull("Visualisation Windows not created", factBrowserWindow);
	}

	/**
	 * This test checks if the retrieval of data is succesfull when a double
	 * click should happen. It cannot simulate the mouseclick itself but does do
	 * the same interanlly as the mouseClicked method.
	 * 
	 * @author Renze de Vries
	 * @date 11-03-2007
	 */
	public void testMouseClicked() {
		FactBrowserDataManager dataManager = FactBrowserDataManager
				.getInstance();

		RStore rstore = new RStore("rstore1", 4);

		DefaultMutableTreeNode rootNode = new DefaultMutableTreeNode("root");
		DefaultMutableTreeNode rstoreNode = new DefaultMutableTreeNode(rstore);
		rootNode.add(rstoreNode);

		RStoreFact rstoreFact = new RStoreFact("fact1", 5, dataManager
				.addFactType("<str,bool>"));
		rstoreNode.add(rstoreFact);

		VisualisationPlugin visPlugin = new VisualisationPlugin("plugin1", 2);
		dataManager.createVisualisation(visPlugin, dataManager
				.addFactType("<str,bool>"));

		assertEquals("This node should be the visualisationPlugin", "plugin1",
				rstoreFact.getFirstLeaf().toString());

		DefaultMutableTreeNode selectedNode = rstoreFact.getFirstLeaf();

		assertEquals("The selectedNode should be a valid visualisationPlugin",
				true, dataManager.checkValidVisualisationPlugin(selectedNode));

		assertEquals("The visualisationPlugin identifier should be 2", 2,
				dataManager.getVisPluginID(selectedNode));

		assertEquals("The RstoreFact identifier should be 5", 5, dataManager
				.getFactID(selectedNode));

		assertEquals("The RStore identifier should be 4", 4, dataManager
				.getRStoreID(selectedNode));

		assertEquals("This TreeNode should not be an RStoreFact", false,
				dataManager.checkValidRStoreFact(selectedNode));

		assertEquals("This TreeNode should be a RStoreFact", true, dataManager
				.checkValidRStoreFact(rstoreFact));
	}
}
