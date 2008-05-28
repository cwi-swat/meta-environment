package nl.cwi.sen1.visplugin;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStubNG;
import aterm.ATerm;

/**
 * TUnit test class, this class tests the communication from and to the VPI and
 * VPCP toolbus processes.
 *
 * @author Aldert Boerhoop
 * @author Anton Gerdessen
 * @date 06-03-2007
 */
public class TestVPI extends TUnitTestCase {

    private ToolStubNG m_vpiProcess;
    private ToolStubNG m_vpiProcessStub;

    /**
     * The function that contains the actual test cases.
     *
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007
     */
    public void testVPIContract() {
        // Connect to the toolbus, this step must be executed before any
        // tests can be run.
        if (connectTools()) {
            try {
                // Run the actual tests.
                visualisationSupported();
                visualiseFact();
                factUpdated();
                linkClicked();
                rstoreUnloaded();
                
                m_vpiProcess.waitForCompletion();
                m_vpiProcessStub.waitForCompletion();
                
            } catch (Exception ex) {
            	ex.printStackTrace();
                fail(ex.toString());
            } finally {
            	m_vpiProcess.disconnect();
            	m_vpiProcessStub.disconnect();
            }
        }
    }

    /**
     * Function which start the toolbus and loads the VPI/VPCP process and the
     * toolbus stub process. It also handles the initial verificating requests
     * the VPI sends when it is created.
     *
     * @return true if the connection was successful
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007
     */
    private boolean connectTools() {
        Boolean success = true;
        try {
            m_vpiProcess = new ToolStubNG("visualizationPlugin", "localhost", getPort(), true);
            m_vpiProcessStub = new ToolStubNG("vpistub", "localhost", getPort(), true);
            
            m_vpiProcess.connect();
            m_vpiProcessStub.connect();

            // The VPI sends a request for a name right after connections, this
            // is the reason this request is handled here.
            ATerm vpGetName = factory.make("vp-get-name");
            ATerm vpName = factory.make("vp-name(<str>)", "TestName");
            m_vpiProcess.registerForEval(vpGetName, vpName);
            m_vpiProcess.expectAction();

        } catch (Exception ex) {
        	ex.printStackTrace();
            success = false;
        }
        return success;
    }

    /**
     * Test to simulate a requests if a specific RTytpe is supported.
     *
     * @exception Any exception which the underlying TUnit can throw
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007

     */
    private void visualisationSupported() throws Exception {
        ATerm vpiSendTestNote = factory.make("vpi-send-test-note");
        m_vpiProcessStub.sendEvent(vpiSendTestNote);

        ATerm vpIsTypeSupported = factory.make("vp-is-type-supported(<str>)", "Test type");
        ATerm vpTypeSupported = factory.make("vp-type-supported(<bool>)", true);
        m_vpiProcess.registerForEval(vpIsTypeSupported, vpTypeSupported);
        m_vpiProcess.expectAction();

        ATerm vpGetAvailableVisualizationPluginsTest = factory.make("vp-get-available-visualization-plugins-test");
        m_vpiProcessStub.registerForDo(vpGetAvailableVisualizationPluginsTest);
        m_vpiProcessStub.expectAction();
    }

    /**
     * Test to simulate a visualise fact event.
     *
     * @exception Any exception which the underlying TUnit can throw
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007

     */
    private void visualiseFact() throws Exception {

        ATerm vpiVisualizeFact = factory.make("vp-visualize-fact");
        m_vpiProcessStub.sendEvent(vpiVisualizeFact);
        
        ATerm vpVisualizeFact = factory.make("vp-visualize-fact(<int>, <int>, <str>)", 0, 0, "Test type");
        m_vpiProcess.registerForDo(vpVisualizeFact);
        m_vpiProcess.expectAction();
    }

    /**
     * Test to simulate a fact updates event.
     *
     * @exception Any exception which the underlying TUnit can throw
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007
     */
    private void factUpdated() throws Exception {
        ATerm vpiSendTestUpdateNote = factory.make("vpi-send-test-update-note");
        m_vpiProcessStub.sendEvent(vpiSendTestUpdateNote);

        ATerm vpFactOutOfDate = factory.make("vp-fact-out-of-date(<int>, <int>)", 0, 0);
        m_vpiProcess.registerForDo(vpFactOutOfDate);
        m_vpiProcess.expectAction();
    }

    /**
     * Test to simulate a link click event.
     *
     * @exception Any exception which the underlying TUnit can throw
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007 *
     */
    private void linkClicked() throws Exception {
        ATerm location = factory.make("loc");
        ATerm vpLinkClicked = factory.make("vp-link-clicked(<term>)", location);
        m_vpiProcess.sendEvent(vpLinkClicked);

        m_vpiProcessStub.registerForDo(vpLinkClicked);
        m_vpiProcessStub.expectAction();
    }

    /**
     * Tests the unload rstore functionality.  
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 19-03-2007 
     * 
     * @throws Exception
     */
    private void rstoreUnloaded() throws Exception {
        ATerm rcRStoreUnloaded = factory.make("rc-rstore-unloaded(<int>)", 123);
        m_vpiProcessStub.sendEvent(rcRStoreUnloaded);

        ATerm vpRStoreUnloaded = factory.make("vp-rstore-unloaded(<int>)", 123);
        m_vpiProcess.registerForDo(vpRStoreUnloaded);
        m_vpiProcess.expectAction();
    }

    /**
     * Setup function, custom version used to allow more understandable TB
     * script names and the directory from which to load them.
     *
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007
     */
    protected void setUp() {
    	String topSrcDir = ".";

        System.out.println(topSrcDir);
         
        try {
            startToolbus(topSrcDir + "/tbscript/", topSrcDir + "/tbscript/startVPIUnitTest.tb");
        } catch (Exception ex) {
        	ex.printStackTrace();
            this.stopToolbus();
            fail(ex.toString());
        }
    }

    /**
     * Clean up the allocated resources at the end of the tests.
     *
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @date 06-03-2007
     */
    protected void tearDown() {
        stopToolbus();
        System.out.println("Toolbus processes terminated.");
    }

}
