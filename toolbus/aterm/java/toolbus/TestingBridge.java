// Java tool bridge TestingBridge
// This file is generated automatically, please do not edit!
// generation time: Jul 12, 2001 10:48:23 AM

package toolbus;

import aterm.*;
import toolbus.*;

public class TestingBridge
  extends TestingTool
{
  private TestingTif tool;

  //{{{  public TestingBridge(ATermFactory factory, TestingTif tool)

  public TestingBridge(ATermFactory factory, TestingTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void listtest(ATerm t0)

  public void listtest(ATerm t0)
  {
    if (tool != null) {
      tool.listtest(t0);
    }
    else {
      throw new UnsupportedOperationException("method `listtest' not supported.");
    }
  }

  //}}}
  //{{{  public void testit(String s0)

  public void testit(String s0)
  {
    if (tool != null) {
      tool.testit(s0);
    }
    else {
      throw new UnsupportedOperationException("method `testit' not supported.");
    }
  }

  //}}}
  //{{{  public void testit(String s0, ATerm t1)

  public void testit(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.testit(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `testit' not supported.");
    }
  }

  //}}}
  //{{{  public void testit(String s0, int i1)

  public void testit(String s0, int i1)
  {
    if (tool != null) {
      tool.testit(s0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `testit' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm question(ATerm t0)

  public ATerm question(ATerm t0)
  {
    if (tool != null) {
      return tool.question(t0);
    }
    else {
      throw new UnsupportedOperationException("method `question' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
