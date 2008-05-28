package nl.cwi.sen1.visbase.factbrowser;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStubNG;
import aterm.ATerm;

/**
 * This test case tests the Fact Browser Interface Toolbus script.
 * 
 * @author Raymond Bergen
 * @author Srinivasan Tharmarajah
 * @date 23-02-2007
 */
public class FBITBTest extends TUnitTestCase {
	
    private ToolStubNG m_metaStudioDialogStubTool;
    private ToolStubNG m_fbiTool;
    private ToolStubNG m_fbmpStubTool;

    /**
     * The function that contains executes all the test cases.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    public void testFBI() {
        try {
            // Initialize the tools
            m_metaStudioDialogStubTool = new ToolStubNG("msdialogstub", "localhost", getPort(), true);
            m_fbiTool = new ToolStubNG("factbrowser", "localhost", getPort(), true);
            m_fbmpStubTool = new ToolStubNG("fbmpstub", "localhost", getPort(), true);

            m_metaStudioDialogStubTool.connect();
            m_fbiTool.connect();
            m_fbmpStubTool.connect();

            // Run test cases
            loadRStore();
            selectFacts();
            selectVisualization();
            unloadRStore();
            
            m_metaStudioDialogStubTool.waitForCompletion();
            m_fbiTool.waitForCompletion();
            m_fbmpStubTool.waitForCompletion();
        } catch (Exception ex) {
            ex.printStackTrace();
            fail(ex.toString());
        } finally {
        	m_metaStudioDialogStubTool.disconnect();
            m_fbiTool.disconnect();
            m_fbmpStubTool.disconnect();
        }
    }

    /**
     * This function tests the selection of a visualization.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void selectVisualization() {
        ATerm fbVisualizationSelected = factory.make("fb-visualization-selected(<int>,<int>,<int>)", 1, 1, 1);
        m_fbiTool.sendEvent(fbVisualizationSelected);

        ATerm fbVisualizationSelectedRecieved = factory.make("fb-visualization-selected-recieved");
        m_fbmpStubTool.registerForDo(fbVisualizationSelectedRecieved);
        m_fbmpStubTool.expectAction();
    }

    /**
     * This function tests the selection of facts.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void selectFacts() {
        ATerm fbTypeSelected = factory.make("fb-type-selected(<term>)", factory.make("rType"));
        m_fbiTool.sendEvent(fbTypeSelected);

        ATerm fbTypeSelectedRecieved = factory.make("fb-type-selected-recieved");
        m_fbmpStubTool.registerForDo(fbTypeSelectedRecieved);
        m_fbmpStubTool.expectAction();

        ATerm fbAddVisualizationPlugin = factory.make(
                "fb-add-visualization-plugin(<term>, <int>, <str>)",
                factory.make("rType"), 1, "pluginTestName");
        m_fbiTool.registerForDo(fbAddVisualizationPlugin);
        m_fbiTool.expectAction();
    }

    /**
     * This function tests the loading of a Rstore.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void loadRStore() {
        ATerm fbLoadRstore = factory.make("fb-load-rstore()");
        m_fbiTool.sendEvent(fbLoadRstore);

        ATerm askForFileRecieved = factory.make("ask-for-file-recieved");
        m_metaStudioDialogStubTool.registerForDo(askForFileRecieved);
        m_metaStudioDialogStubTool.expectAction();

        ATerm fbRstoreLoaded = factory.make("fb-rstore-loaded");
        m_fbmpStubTool.registerForDo(fbRstoreLoaded);
        m_fbmpStubTool.expectAction();

        ATerm fbShowRstoreFacts = factory.make(
                "fb-show-rstore-facts(<str>, <int>, <list>)",
                "rstoreTestName", 1, factory.makeList());
        m_fbiTool.registerForDo(fbShowRstoreFacts);
        m_fbiTool.expectAction();
    }
    
    private void unloadRStore() {
        int rstoreId = 5;
        ATerm fbUnloadRstore = factory.make("fb-unload-rstore(<int>)", rstoreId);
        m_fbiTool.sendEvent(fbUnloadRstore);        
        m_fbmpStubTool.registerForDo(fbUnloadRstore);
        m_fbmpStubTool.expectAction();
        
        ATerm fbRStoreUnloaded = factory.make("fb-rstore-unloaded(<int>)", rstoreId);
        m_fbiTool.registerForDo(fbRStoreUnloaded);
        m_fbiTool.expectAction();
    }

    /**
     * Let the JUnit framework start the toolbus at a given port and load the
     * initialization test script. It is important to stop the toolbus if an
     * exception arises! If the exception is not caught the toolbus process will
     * still be running. If we re-run the toolbus process the toolbus will be
     * initialized at a new port because there is a toolbus process still
     * running at the given port.
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 23-02-2007
     */
    protected void setUp() {
    	String topSrcDir = ".";

        System.out.println(topSrcDir);
         
        try {
            startToolbus(topSrcDir + "/tbscript/", topSrcDir + "/tbscript/init.tb");
        } catch (Exception ex) {
        	ex.printStackTrace();
            stopToolbus();
            fail(ex.toString());
        }
    }

    /**
     * Clean up the allocated resources at the end of the test.
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 23-02-2007
     */
    protected void tearDown() {
        stopToolbus();
    }
}
