// Java tool bridge ExampleBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 7, 2005 9:24:59 PM

package toolbus.tool.java;

import aterm.ATerm;
import aterm.ATermFactory;


public class ExampleBridge
  extends ExampleTool
{
  private ExampleTif tool;

  //{{{  public ExampleBridge(ATermFactory factory, ExampleTif tool)

  public ExampleBridge(ATermFactory factory, ExampleTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public ATerm msg(String s0)

  public ATerm msg(String s0)
  {
	System.err.println("msg(" + s0 + ") called");
    if (tool != null) {
      return tool.msg(s0);
    }
    else {
      throw new UnsupportedOperationException("method `msg' not supported.");
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
