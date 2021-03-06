package toolbus.test;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringWriter;

import junit.framework.TestCase;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;

public class TscriptTest extends TestCase{
	
	public TscriptTest(String name){
		super(name);
	}
	
	private boolean equalOutput(String currentOutput, String prevOutputFile){
		StringWriter sbuf = new StringWriter();
		File prev_file = new File(prevOutputFile);
		FileReader prev = null;
		try{
			prev = new FileReader(prev_file);
			char[] buffer = new char[4096];
			int chars_read;
			while((chars_read = prev.read(buffer)) != -1){
				sbuf.write(buffer, 0, chars_read);
			}
			sbuf.close();
		}catch(IOException e){
			System.err.println(e.getMessage());
			return false;
		}finally{
			if(prev != null) try{
				prev.close();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
		
		return sbuf.toString().equals(currentOutput);
		
	}
	
	private String dir = "src/toolbus/test/";
	
	private boolean runTest(String name){
		StringWriter sout = new StringWriter();
		
		ToolBus toolbus = new ToolBus(new String[0], sout);
		toolbus.setProperty("script.path", dir + name + ".tb");
		try{
			toolbus.parsecup();
		}catch(ToolBusException tbex){
			throw new RuntimeException(tbex);
		}
		toolbus.prepare();
		toolbus.execute();
		
		try{
			sout.close();
		}catch(IOException e){
			System.err.println("runTest: " + e.getMessage());
		}
		System.err.println("*** Output of " + name + ": \"" + sout.toString() + '"');
		return equalOutput(sout.toString(), dir + name + ".out");
	}
	
	public void testBasics(){
		// assertTrue(runTest("B0"));
		assertTrue(runTest("B1"));
		assertTrue(runTest("B2"));
		// assertTrue(runTest("B3"));
	}
	
	public void testAssign(){
		assertTrue(runTest("Assign0"));
		assertTrue(runTest("Assign1"));
		assertTrue(runTest("Assign2"));
		assertTrue(runTest("Assign3"));
		assertTrue(runTest("Assign4"));
		assertTrue(runTest("Assign5"));
		assertTrue(runTest("Assign6"));
		assertTrue(runTest("Bind"));
		assertTrue(runTest("Let1"));
	}
	
	public void testIf(){
		assertTrue(runTest("If0"));
		assertTrue(runTest("If1"));
		assertTrue(runTest("If2"));
		assertTrue(runTest("If3"));
		assertTrue(runTest("If4"));
		assertTrue(runTest("If5"));
		assertTrue(runTest("If6"));
		assertTrue(runTest("If7"));
	}
	
	public void testIter(){
		assertTrue(runTest("Iter0"));
		assertTrue(runTest("Iter1"));
		assertTrue(runTest("Iter2"));
	}
	
	public void testMsg(){
		assertTrue(runTest("Msg0"));
		assertTrue(runTest("Msg1"));
		assertTrue(runTest("Msg2"));
		assertTrue(runTest("Msg3"));
		assertTrue(runTest("Msg4"));
		assertTrue(runTest("Msg5"));
	}
	
	public void testCall(){
		assertTrue(runTest("Call0"));
		assertTrue(runTest("Call1"));
		assertTrue(runTest("Call2"));
		assertTrue(runTest("Call3"));
		assertTrue(runTest("Call4"));
		assertTrue(runTest("Call5"));
		assertTrue(runTest("Call6"));
		assertTrue(runTest("Call7"));
		assertTrue(runTest("Call8"));
		assertTrue(runTest("Call9"));
		
		assertTrue(runTest("DynCall1"));
		assertTrue(runTest("DynCall2"));
	}
	
	public void testExpr(){
		assertTrue(runTest("Expr"));
	}
	
	public void testType(){
		assertTrue(runTest("Types"));
	}
	
	public void testNote(){
		assertTrue(runTest("Notes"));
	}
	
	public void testOther(){
		assertTrue(runTest("Define"));
		assertTrue(runTest("RightChoice1"));
		assertTrue(runTest("RightChoice2"));
		assertTrue(runTest("LeftChoice1"));
		assertTrue(runTest("LeftChoice2"));
		assertTrue(runTest("Sieve"));
		assertTrue(runTest("Prod"));
	}
}
