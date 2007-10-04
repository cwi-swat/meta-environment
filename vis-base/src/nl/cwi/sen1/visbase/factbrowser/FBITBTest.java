package nl.cwi.sen1.visbase.factbrowser;

import java.io.File;
import java.net.URL;

import nl.cwi.sen1.tunit.StackTraceUtil;
import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStub;
import nl.cwi.sen1.tunit.ToolStub.TimeoutExceededException;
import nl.cwi.sen1.tunit.ToolStub.UnexpectedTermException;
import aterm.ATerm;

/**
 * This test case tests the Fact Browser Interface Toolbus script.
 * 
 * @author Raymond Bergen
 * @author Srinivasan Tharmarajah
 * @date 23-02-2007
 */
public class FBITBTest extends TUnitTestCase {
    private ToolStub m_metaStudioDialogStubTool;

    private ToolStub m_fbiTool;

    private ToolStub m_fbmpStubTool;

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
            m_metaStudioDialogStubTool = this.createToolStub("msdialogstub");
            m_fbiTool = this.createToolStub("factbrowser");
            m_fbmpStubTool = this.createToolStub("fbmpstub");

            connectToolStubs();

            // Run test cases
            loadRStore();
            selectFacts();
            selectVisualization();
            unloadRStore();

            disconnectToolStubs();
        } catch (Exception ex) {
            System.out.println(StackTraceUtil.getStackTrace(ex));
            fail(ex.toString());
        }
    }

    /**
     * This function tests the selection of a visualization.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void selectVisualization() throws UnexpectedTermException,
            TimeoutExceededException {
        ATerm fbVisualizationSelected = this.factory.make(
                "fb-visualization-selected(<int>,<int>,<int>)", 1, 1, 1);
        m_fbiTool.sendEvent(fbVisualizationSelected);
        m_fbiTool.expectAckEvent(fbVisualizationSelected, 3000);

        ATerm fbVisualizationSelectedRecieved = this.factory
                .make("fb-visualization-selected-recieved");
        m_fbmpStubTool.expectDo(fbVisualizationSelectedRecieved, 3000);
    }

    /**
     * This function tests the selection of facts.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void selectFacts() throws UnexpectedTermException,
            TimeoutExceededException {
        ATerm fbTypeSelected = this.factory.make("fb-type-selected(<term>)",
                this.factory.make("rType"));
        m_fbiTool.sendEvent(fbTypeSelected);
        m_fbiTool.expectAckEvent(fbTypeSelected, 3000);

        ATerm fbTypeSelectedRecieved = this.factory
                .make("fb-type-selected-recieved");
        m_fbmpStubTool.expectDo(fbTypeSelectedRecieved, 3000);

        ATerm fbAddVisualizationPlugin = this.factory.make(
                "fb-add-visualization-plugin(<term>, <int>, <str>)",
                this.factory.make("rType"), 1, "pluginTestName");
        m_fbiTool.expectDo(fbAddVisualizationPlugin, 3000);
    }

    /**
     * This function tests the loading of a Rstore.
     * 
     * @author Raymond Bergen
     * @author Srinivasan Tharmarajah
     * @date 21-02-2007
     */
    private void loadRStore() throws UnexpectedTermException,
            TimeoutExceededException {
        ATerm fbLoadRstore = this.factory.make("fb-load-rstore()");
        m_fbiTool.sendEvent(fbLoadRstore);
        m_fbiTool.expectAckEvent(fbLoadRstore, 3000);

        ATerm askForFileRecieved = this.factory.make("ask-for-file-recieved");
        m_metaStudioDialogStubTool.expectDo(askForFileRecieved, 3000);

        ATerm fbRstoreLoaded = this.factory.make("fb-rstore-loaded");
        m_fbmpStubTool.expectDo(fbRstoreLoaded, 3000);

        ATerm fbShowRstoreFacts = this.factory.make(
                "fb-show-rstore-facts(<str>, <int>, <list>)", "rstoreTestName",
                1, this.factory.makeList());
        m_fbiTool.expectDo(fbShowRstoreFacts, 3000);
    }
    
    private void unloadRStore() throws UnexpectedTermException, TimeoutExceededException {
        int rstoreId = 5;
        ATerm fbUnloadRstore = this.factory.make("fb-unload-rstore(<int>)", rstoreId);
        m_fbiTool.sendEvent(fbUnloadRstore);
        m_fbiTool.expectAckEvent(fbUnloadRstore, 3000);        
        m_fbmpStubTool.expectDo(fbUnloadRstore, 3000);
        
        ATerm fbRStoreUnloaded = this.factory.make("fb-rstore-unloaded(<int>)", rstoreId);
        m_fbiTool.expectDo(fbRStoreUnloaded, 3000);
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
        try {
            // Retrieve the fbmp file
            URL url = this.getClass().getResource("/tbscript/init.tb");

            // Make a File object from the URL so we can determine the search
            // path
            File file = new File(url.toURI());

            this.startToolbus(file.getParent(), url.getPath(), 7000);
        } catch (Exception ex) {
            System.out.println(StackTraceUtil.getStackTrace(ex));
            this.stopToolbus();
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
        this.stopToolbus();
    }
}
