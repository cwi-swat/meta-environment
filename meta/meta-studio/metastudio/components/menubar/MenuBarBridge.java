// Java tool bridge MenuBarBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 2:06:21 PM

package metastudio.components.menubar;

import aterm.*;

public class MenuBarBridge
  extends MenuBarTool
{
  private MenuBarTif tool;

  //{{{  public MenuBarBridge(ATermFactory factory, MenuBarTif tool)

  public MenuBarBridge(ATermFactory factory, MenuBarTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void addEvents(ATerm t0, ATerm t1)

  public void addEvents(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.addEvents(t0, t1);
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
