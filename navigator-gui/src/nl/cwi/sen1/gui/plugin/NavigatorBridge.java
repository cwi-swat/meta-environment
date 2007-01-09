// Java tool bridge NavigatorBridge
// This file is generated automatically, please do not edit!
// generation time: Jan 9, 2007 11:51:32 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class NavigatorBridge
  extends NavigatorTool
{
  private NavigatorTif tool;

  public NavigatorBridge(ATermFactory factory, NavigatorTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void selectModule(ATerm t0)
  {
    if (tool != null) {
      tool.selectModule(t0);
    }
    else {
      throw new UnsupportedOperationException("method `selectModule' not supported.");
    }
  }
  public void updateModule(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.updateModule(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `updateModule' not supported.");
    }
  }
  public void deleteModule(ATerm t0)
  {
    if (tool != null) {
      tool.deleteModule(t0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteModule' not supported.");
    }
  }
  public void showPopup(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.showPopup(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showPopup' not supported.");
    }
  }
  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }
  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }
}
