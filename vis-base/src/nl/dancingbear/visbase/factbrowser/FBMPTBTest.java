package nl.dancingbear.visbase.factbrowser;

import java.io.File;
import java.net.URL;

import nl.dancingbear.tunit.StackTraceUtil;
import nl.dancingbear.tunit.TUnitTestCase;
import nl.dancingbear.tunit.ToolStub;
import nl.dancingbear.tunit.ToolStub.TimeoutExceededException;
import nl.dancingbear.tunit.ToolStub.UnexpectedTermException;
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
	private ToolStub m_FBMPTool;
	
    /**
     * Test the all the toolbus scenarios.
     * 
     * @author Bas Basten 
     * @author Anton Lycklama a Nijeholt 
     * @date 07-03-2007
     *   
     */
	public void testFBMP() {
		try {
			m_FBMPTool = this.createToolStub("fbmp-test-tool");
		
			this.connectToolStubs();

			this.checkScenario(1);
			this.checkScenario(2);
            this.checkScenario(3);
            this.checkScenario(4);
            this.checkScenario(5);
            this.checkScenario(6);
			
			this.disconnectToolStubs();
		}
		catch (Exception ex) {
			System.out.println(StackTraceUtil.getStackTrace(ex));
			fail(ex.toString());
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
	private void checkScenario(int scenarioNumber) throws UnexpectedTermException, TimeoutExceededException {
		ATerm scenarioStart = this.factory.make("start-scenario(<int>)", scenarioNumber);
		m_FBMPTool.sendEvent(scenarioStart);
		m_FBMPTool.expectAckEvent(scenarioStart, 3000);
		ATerm scenarioResult = this.factory.make("scenario-successful(<int>)", scenarioNumber);
		m_FBMPTool.expectDo(scenarioResult, 3000);
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
		// Get the absolute path of the top directory of the current package.
		// For example: /tmp/<user>/metarepos/tunit
		String topSrcDir = getTopSrcDir();
		
		System.out.println(topSrcDir);
		
		try {
            //Retrieve the fbmp file
            URL url = this.getClass().getResource("/tbscript/fbmp_test_init.tb");
            
            //Make a File object from the URL so we can determine the search path
            File file = new File(url.toURI());

            this.startToolbus(file.getParent(), url.getPath(), 7000);
		}
		catch (Exception ex) {
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
	 * @date 07-03-2007
	 */	
	protected void tearDown() {		
		this.stopToolbus();
	}	
}
