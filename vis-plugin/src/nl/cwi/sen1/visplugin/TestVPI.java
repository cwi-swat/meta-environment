package nl.cwi.sen1.visplugin;

import java.io.File;
import java.net.URL;

import nl.cwi.sen1.tunit.StackTraceUtil;
import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStub;
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

    private ToolStub m_vpiProcess = null;

    private ToolStub m_vpiProcessStub = null;

    private static final int TIMEOUT = 5000;

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

                // Cleanup the toolbus processes.
                disconnectToolStubs();

            } catch (Exception ex) {
                System.out.println(StackTraceUtil.getStackTrace(ex));
                fail(ex.toString());
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
            m_vpiProcess = createToolStub("visualizationPlugin");
            m_vpiProcessStub = createToolStub("vpistub");
            this.connectToolStubs();

            // The VPI sends a request for a name right after connections, this
            // is the reason this request is handled here.
            ATerm vpGetName = factory.make("vp-get-name");
            m_vpiProcess.expectEval(vpGetName, TIMEOUT);
            ATerm vpName = factory.make("vp-name(<str>)", "TestName");
            m_vpiProcess.sendValue(vpName);

        } catch (Exception ex) {
            System.out.println(StackTraceUtil.getStackTrace(ex));
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
        m_vpiProcessStub.expectAckEvent(vpiSendTestNote, TIMEOUT);

        ATerm vpIsTypeSupported = factory.make("vp-is-type-supported(<str>)",
                "Test type");
        m_vpiProcess.expectEval(vpIsTypeSupported, TIMEOUT);

        ATerm vpTypeSupported = factory.make("vp-type-supported(<bool>)", true);
        m_vpiProcess.sendValue(vpTypeSupported);

        ATerm vpGetAvailableVisualizationPluginsTest = factory
                .make("vp-get-available-visualization-plugins-test");
        m_vpiProcessStub.expectDo(vpGetAvailableVisualizationPluginsTest,
                TIMEOUT);

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
        m_vpiProcessStub.expectAckEvent(vpiVisualizeFact, TIMEOUT);

        ATerm vpVisualizeFact = factory.make(
                "vp-visualize-fact(<int>, <int>, <str>)", 0, 0, "Test type");
        m_vpiProcess.expectDo(vpVisualizeFact, TIMEOUT);
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
        m_vpiProcessStub.expectAckEvent(vpiSendTestUpdateNote, TIMEOUT);

        ATerm vpFactOutOfDate = factory.make(
                "vp-fact-out-of-date(<int>, <int>)", 0, 0);
        m_vpiProcess.expectDo(vpFactOutOfDate, TIMEOUT);
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
        m_vpiProcess.expectAckEvent(vpLinkClicked, TIMEOUT);

        m_vpiProcessStub.expectDo(vpLinkClicked, TIMEOUT);
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
        m_vpiProcessStub.expectAckEvent(rcRStoreUnloaded, TIMEOUT);

        ATerm vpRStoreUnloaded = factory.make("vp-rstore-unloaded(<int>)", 123);
        m_vpiProcess.expectDo(vpRStoreUnloaded, TIMEOUT);
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
        try {
            //Retrieve the fbmp file
            URL url = this.getClass().getResource("/tbscript/startVPIUnitTest.tb");

            //Make a File object from the URL so we can determine the search path
            File file = new File(url.toURI());

            this.startToolbus(file.getParent(), url.getPath(), 7000);
        } catch (Exception ex) {
            System.out.println(StackTraceUtil.getStackTrace(ex));
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
