// Java tool bridge DebugToolBridge
// This file is generated automatically, please do not edit!
// generation time: Jun 10, 2004 3:05:13 PM

package tide.tool.support;

import aterm.*;

public class DebugToolBridge
  extends DebugToolTool
{
  private DebugToolTif tool;

  //{{{  public DebugToolBridge(ATermFactory factory, DebugToolTif tool)

  public DebugToolBridge(ATermFactory factory, DebugToolTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void processDestroyed(ATerm t0)

  public void processDestroyed(ATerm t0)
  {
    if (tool != null) {
      tool.processDestroyed(t0);
    }
    else {
      throw new UnsupportedOperationException("method `processDestroyed' not supported.");
    }
  }

  //}}}
  //{{{  public void adapterDisconnected(ATerm t0)

  public void adapterDisconnected(ATerm t0)
  {
    if (tool != null) {
      tool.adapterDisconnected(t0);
    }
    else {
      throw new UnsupportedOperationException("method `adapterDisconnected' not supported.");
    }
  }

  //}}}
  //{{{  public void event(ATerm t0, int i1, ATerm t2)

  public void event(ATerm t0, int i1, ATerm t2)
  {
    if (tool != null) {
      tool.event(t0, i1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `event' not supported.");
    }
  }

  //}}}
  //{{{  public void processCreated(ATerm t0, String s1)

  public void processCreated(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.processCreated(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `processCreated' not supported.");
    }
  }

  //}}}
  //{{{  public void adapterConnected(ATerm t0)

  public void adapterConnected(ATerm t0)
  {
    if (tool != null) {
      tool.adapterConnected(t0);
    }
    else {
      throw new UnsupportedOperationException("method `adapterConnected' not supported.");
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
