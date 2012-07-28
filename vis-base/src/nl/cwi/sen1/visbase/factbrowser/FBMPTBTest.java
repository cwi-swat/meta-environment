package nl.cwi.sen1.visbase.factbrowser;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolComValidator;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * The FBMP Toolbus test case for toolbus testing.
 * 
 * @author Bas Basten 
 * @author Anton Lycklama a Nijeholt
 * 
 */
public class FBMPTBTest extends TUnitTestCase {
	
    /**
     * Test the all the toolbus scenarios.
     */
	public void testFBMP() {
		FBMPTool fbmpTool = new FBMPTool(this, "fbmp-test-tool", true);
        
    	Thread fbmpToolExecutor = new Thread(fbmpTool);
    	fbmpToolExecutor.setDaemon(true);
    	fbmpToolExecutor.start();
    	
    	toolbus.waitTillShutdown();
    	
    	if(hasFailed()) fail();
        
        System.out.println("Test Passed");
	}
	
	protected void setUp() {
		try{
            startToolbus("./tbscript/", "./tbscript/fbmp_test_init.tb");
        }catch (Exception ex){
			ex.printStackTrace();
			stopToolbus();
			fail(ex.toString());			
		}
	}
	
	protected void tearDown() {		
		stopToolbus();
	}
	
	public static class FBMPTool extends ToolComValidator{
    	private final TUnitTestCase testCase;
    	
    	public FBMPTool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			PureFactory factory = getFactory();

    			for(int i = 1; i <= 6; i++){
	    			ATerm scenarioStart = factory.make("start-scenario(<int>)", i);
	    			sendEvent(scenarioStart);
	    			
	    			ATerm scenarioResult = factory.make("scenario-successful(<int>)", i);
	    			registerForDo(scenarioResult);
	    			expectAction();
	    			
	    			waitForCompletion();
    			}
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    }
}
