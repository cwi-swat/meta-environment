// Java tool bridge NavigatorBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 21, 2005 10:36:27 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class NavigatorBridge
  extends NavigatorTool
{
  private NavigatorTif tool;

  //{{{  public NavigatorBridge(ATermFactory factory, NavigatorTif tool)

  public NavigatorBridge(ATermFactory factory, NavigatorTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void selectModule(String s0)

  public void selectModule(String s0)
  {
    if (tool != null) {
      tool.selectModule(s0);
    }
    else {
      throw new UnsupportedOperationException("method `selectModule' not supported.");
    }
  }

  //}}}
  //{{{  public void addEvents(ATerm t0, String s1, ATerm t2)

  public void addEvents(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.addEvents(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `addEvents' not supported.");
    }
  }

  //}}}
  //{{{  public void setModules(ATerm t0)

  public void setModules(ATerm t0)
  {
    if (tool != null) {
      tool.setModules(t0);
    }
    else {
      throw new UnsupportedOperationException("method `setModules' not supported.");
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
