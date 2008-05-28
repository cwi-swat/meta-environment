package nl.cwi.sen1.visbase.factbrowser;

import java.io.File;
import java.net.URL;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStubNG;
import aterm.ATerm;

/**
 * The FBMP Toolbus test case for toolbus testing.
 * 
 * @author Bas Basten 
 * @author Anton Lycklama a Nijeholt 
 * @date 07-03-2007
 * 
 */
public class FBMPTBTest extends TUnitTestCase {
	private ToolStubNG m_FBMPTool;
	
    /**
     * Test the all the toolbus scenarios.
     * 
     * @author Bas Basten 
     * @author Anton Lycklama a Nijeholt 
     * @date 07-03-2007
     *   
     */
	public void testFBMP() {
		m_FBMPTool = new ToolStubNG("fbmp-test-tool", "localhost", getPort(), true);

		try {
			m_FBMPTool.connect();

			this.checkScenario(1);
			this.checkScenario(2);
            this.checkScenario(3);
            this.checkScenario(4);
            this.checkScenario(5);
            this.checkScenario(6);
			
			m_FBMPTool.waitForCompletion();
		}
		catch (Exception ex) {
			ex.printStackTrace();
			fail(ex.toString());
		} finally {
			m_FBMPTool.disconnect();
		}
	}

    /**
     * A scenario can be started with this method.
     * The toolbus will send a start-scenario<int> event
     * with the corresponding scenarioNumber.
     * It then expects the scenario to send a
     * scenario-successful<int> with the scenarioNumber
     * specified.
     *
     * @author Bas Basten 
     * @author Anton Lycklama a Nijeholt 
     * @date 07-03-2007     * 
     * 
     * @param scenarioNumber
     * @throws UnexpectedTermException
     * @throws TimeoutExceededException
     */
	private void checkScenario(int scenarioNumber) {
		ATerm scenarioStart = this.factory.make("start-scenario(<int>)", scenarioNumber);
		m_FBMPTool.sendEvent(scenarioStart);
		ATerm scenarioResult = this.factory.make("scenario-successful(<int>)", scenarioNumber);
		m_FBMPTool.registerForDo(scenarioResult);
		m_FBMPTool.expectAction();
	}
	
	/**
	 * Let the JUnit framework start the toolbus at a given port and load the
	 * initialization test script. It is important to stop the toolbus if an
	 * exception arises! If the exception is not caught the toolbus process will
	 * still be running. If we re-run the toolbus process the toolbus will be
	 * initialized at a new port because there is a toolbus process still running
	 * at the given port. 
	 * 
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 07-03-2007
	 */
	protected void setUp() {
		String topSrcDir = ".";

        System.out.println(topSrcDir);
         
        try {
            startToolbus(topSrcDir + "/tbscript/", topSrcDir + "/tbscript/fbmp_test_init.tb");
        } catch (Exception ex) {
			ex.printStackTrace();
			this.stopToolbus();
			fail(ex.toString());			
		}
	}
	
	/**
	 * Clean up the allocated resources at the end of the test. 
	 * 
	 * @author Bas Basten
	 * @author Anton Lycklama a Nijeholt
	 * @date 07-03-2007
	 */	
	protected void tearDown() {		
		this.stopToolbus();
	}	
}
