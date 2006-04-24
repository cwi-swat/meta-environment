// Java tool bridge ProgressBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 24, 2006 11:58:11 PM

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

  public void removeStatus(ATerm t0)
  {
    if (tool != null) {
      tool.removeStatus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `removeStatus' not supported.");
    }
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
  public void setStatus(ATerm t0, String s1, String s2, ATerm t3)
  {
    if (tool != null) {
      tool.setStatus(t0, s1, s2, t3);
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
