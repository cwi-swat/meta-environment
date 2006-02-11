package toolbus.test;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringWriter;

import junit.framework.TestCase;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.ToolBusException;

public class TscriptTest extends TestCase {
	private TBTermFactory tbfactory;

  public TscriptTest(String name) {
    super(name);
    tbfactory = TBTermFactory.getInstance();
  }

  private boolean equalOutput(String currentOutput, String prevOutputFile) {
    StringWriter sbuf = new StringWriter();
    File prev_file = new File(prevOutputFile);
    FileReader prev = null;
    try {
      prev = new FileReader(prev_file);
      char[] buffer = new char[4096];
      int chars_read;
      while ((chars_read = prev.read(buffer)) != -1) {
        sbuf.write(buffer, 0, chars_read);
      }
      sbuf.close();
    } catch (IOException e) {
      System.err.println(e.getMessage());
      return false;
    } finally {
      if (prev != null)
        try {
          prev.close();
        } catch (IOException e) {
          ;
        }
    }

    return sbuf.toString().equals(currentOutput);

  }

  private String dir = "toolbus/test/";

  private boolean runTest(String name) {
    StringWriter sout = new StringWriter();
    ToolBus T = new ToolBus(sout);
    try {
      T.parse(dir + name + ".tb");
      T.execute();
    } catch (ToolBusException e) {
    }

    try {
      sout.close();
    } catch (IOException e) {
    }
    System.err.println("*** Output of " + name + ": \"" + sout.toString() + '"');
    return equalOutput(sout.toString(), dir + name + ".out");
  }

  public void testBasics() {
    assertTrue(runTest("B0"));
    assertTrue(runTest("B1"));
    assertTrue(runTest("B2"));
    assertTrue(runTest("B3"));
  }

  public void testAssign() {
    assertTrue(runTest("Assign0"));
    assertTrue(runTest("Assign1"));
    assertTrue(runTest("Assign2"));
    assertTrue(runTest("Assign3"));
    assertTrue(runTest("Assign4"));
    assertTrue(runTest("Assign5"));
    assertTrue(runTest("Assign6"));
    assertTrue(runTest("Bind"));
  }

  public void testIf() {
    assertTrue(runTest("If0"));
    assertTrue(runTest("If1"));
    assertTrue(runTest("If2"));
    assertTrue(runTest("If3"));
    assertTrue(runTest("If4"));
    assertTrue(runTest("If5"));
  }

  public void testIter() {  //TODO: does not terminate
    assertTrue(runTest("Iter0"));
    assertTrue(runTest("Iter1"));
  }

  public void testMsg() {
    assertTrue(runTest("Msg0"));
    assertTrue(runTest("Msg1"));
    assertTrue(runTest("Msg2"));
    assertTrue(runTest("Msg3"));
    assertTrue(runTest("Msg4"));
    assertTrue(runTest("Msg5"));
  }

  public void testCall() {
    assertTrue(runTest("Call0"));
    assertTrue(runTest("Call1"));
    assertTrue(runTest("Call2"));
    assertTrue(runTest("Call3"));
  }
  
  public void testExpr() {
  	assertTrue(runTest("Expr"));
  }
  
  public void testType() {
  	assertTrue(runTest("Types"));
  }

  public void xxtestNote() {
  	assertTrue(runTest("Notes"));
  }
  
  public void testOther(){
  	assertTrue(runTest("Sieve"));
 	assertTrue(runTest("Prod"));
  }
}
