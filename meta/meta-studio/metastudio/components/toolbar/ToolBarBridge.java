// Java tool bridge ToolBarBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 3:35:53 PM

package metastudio.components.toolbar;

import aterm.*;

public class ToolBarBridge
  extends ToolBarTool
{
  private ToolBarTif tool;

  //{{{  public ToolBarBridge(ATermFactory factory, ToolBarTif tool)

  public ToolBarBridge(ATermFactory factory, ToolBarTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void addEvents(ATerm t0)

  public void addEvents(ATerm t0)
  {
    if (tool != null) {
      tool.addEvents(t0);
    }
    else {
      throw new UnsupportedOperationException("method `addEvents' not supported.");
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
