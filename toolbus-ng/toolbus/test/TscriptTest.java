package toolbus.test;

import java.io.*;

import toolbus.*;

import aterm.ATermFactory;
import aterm.pure.PureFactory;

import junit.framework.TestCase;

public class TscriptTest extends TestCase {
  private ATermFactory factory;

  public TscriptTest(String name) {
    super(name);
    factory = new PureFactory();
    TBTerm.init(factory);
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
     System.out.println('"' + currentOutput + '"');
    System.out.println('"' + sbuf.toString() + '"');
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
    return equalOutput(sout.toString(), dir + name + ".out");
  }

  public void testBasics() {
    assertTrue(runTest("B0"));
    assertTrue(runTest("B1"));
    assertTrue(runTest("B2"));
    assertTrue(runTest("B3"));
  }
  
  public void testAssign(){
    assertTrue(runTest("Assign0"));
    assertTrue(runTest("Assign1"));
  }

}
