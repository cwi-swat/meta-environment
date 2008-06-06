package nl.cwi.sen1.visbase.factbrowser;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolComValidator;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * This test case tests the Fact Browser Interface Toolbus script.
 * 
 * @author Raymond Bergen
 * @author Srinivasan Tharmarajah
 */
public class FBITBTest extends TUnitTestCase{

    /**
     * The function that contains executes all the test cases.
     */
    public void testFBI(){
    	MSDialogTool msDialogTool = new MSDialogTool(this, "msdialogstub", true);
    	FactBrowserTool factBrowserTool = new FactBrowserTool(this, "factbrowser", true);
    	FBMPTool fbmpTool = new FBMPTool(this, "fbmpstub", true);
        
    	Thread msDialogToolExecutor = new Thread(msDialogTool);
    	msDialogToolExecutor.setDaemon(true);
    	msDialogToolExecutor.start();
    	Thread factBrowserToolExecutor = new Thread(factBrowserTool);
    	factBrowserToolExecutor.setDaemon(true);
    	factBrowserToolExecutor.start();
    	Thread fbmpToolExecutor = new Thread(fbmpTool);
    	fbmpToolExecutor.setDaemon(true);
    	fbmpToolExecutor.start();
    	
    	toolbus.waitTillShutdown();
    	
    	if(hasFailed()) fail();
        
        System.out.println("Test Passed");
    }
    
    protected void setUp() {
        try{
            startToolbus("./tbscript/", "./tbscript/init.tb");
        }catch (Exception ex){
        	ex.printStackTrace();
            stopToolbus();
            fail(ex.toString());
        }
    }
    
    protected void tearDown() {
        stopToolbus();
    }
    
    public static class MSDialogTool extends ToolComValidator{
    	private static PureFactory factory = getFactory();
    	private final TUnitTestCase testCase;
    	
    	public MSDialogTool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			loadRstore();
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    	
    	private void loadRstore(){
    		ATerm askForFileRecieved = factory.make("ask-for-file-recieved");
	        registerForDo(askForFileRecieved);
	        expectAction();
    	}
    }
    
    public static class FactBrowserTool extends ToolComValidator{
    	private static PureFactory factory = getFactory();
    	private final TUnitTestCase testCase;
    	
    	public FactBrowserTool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			loadRStore();
    			selectFacts();
    			selectVisualization();
    			unloadRStore();
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    	
    	private void loadRStore(){
    		ATerm fbLoadRstore = factory.make("fb-load-rstore()");
	        sendEvent(fbLoadRstore);
			
	        ATerm fbShowRstoreFacts = factory.make("fb-show-rstore-facts(<str>, <int>, <list>)", "rstoreTestName", 1, factory.makeList());
	        registerForDo(fbShowRstoreFacts);
	        expectAction();
    	}
    	
    	private void selectFacts(){
    		ATerm fbTypeSelected = factory.make("fb-type-selected(<term>)", factory.make("rType"));
	        sendEvent(fbTypeSelected);
	        
	        ATerm fbAddVisualizationPlugin = factory.make("fb-add-visualization-plugin(<term>, <int>, <str>)", factory.make("rType"), 1, "pluginTestName");
	        registerForDo(fbAddVisualizationPlugin);
	        expectAction();
    	}
    	
    	private void selectVisualization(){
    		ATerm fbVisualizationSelected = factory.make("fb-visualization-selected(<int>,<int>,<int>)", 1, 1, 1);
	        sendEvent(fbVisualizationSelected);
    	}
    	
    	private void unloadRStore(){
	        int rstoreId = 5;
	        ATerm fbRStoreUnloaded = factory.make("fb-rstore-unloaded(<int>)", rstoreId);
	        registerForDo(fbRStoreUnloaded);
	        expectAction();
    	}
    }
    
    public static class FBMPTool extends ToolComValidator{
    	private static PureFactory factory = getFactory();
    	private final TUnitTestCase testCase;
    	
    	public FBMPTool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			loadRStore();
    			selectFacts();
    			selectVisualization();
    			unloadRStore();
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    	
    	private void loadRStore(){
	        ATerm fbRstoreLoaded = factory.make("fb-rstore-loaded");
	        registerForDo(fbRstoreLoaded);
	        expectAction();
    	}
    	
    	private void selectFacts(){
	        ATerm fbTypeSelectedRecieved = factory.make("fb-type-selected-recieved");
	        registerForDo(fbTypeSelectedRecieved);
	        expectAction();
    	}
    	
    	private void selectVisualization(){
	        ATerm fbVisualizationSelectedRecieved = factory.make("fb-visualization-selected-recieved");
	        registerForDo(fbVisualizationSelectedRecieved);
	        expectAction();
    	}
    	
    	private void unloadRStore(){
	        int rstoreId = 5;
	        ATerm fbUnloadRstore = factory.make("fb-unload-rstore(<int>)", rstoreId);
	        sendEvent(fbUnloadRstore);        
	        registerForDo(fbUnloadRstore);
	        expectAction();
    	}
    }
}
