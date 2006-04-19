// Java tool bridge ProgressBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 10:00:36 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ProgressBridge
  extends ProgressTool
{
  private ProgressTif tool;

  public ProgressBridge(ATermFactory factory, ProgressTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void clearStatusWindow()
  {
    if (tool != null) {
      tool.clearStatusWindow();
    }
    else {
      throw new UnsupportedOperationException("method `clearStatusWindow' not supported.");
    }
  }
  public void setStatus(String s0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.setStatus(s0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `setStatus' not supported.");
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
