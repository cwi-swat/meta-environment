// Java tool bridge NavigatorBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 22, 2005 1:03:35 PM

package nl.cwi.sen1.gui.plugin;

import aterm.ATerm;
import aterm.ATermFactory;

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
  //{{{  public void showPopup(String s0, ATerm t1)

  public void showPopup(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.showPopup(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showPopup' not supported.");
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
