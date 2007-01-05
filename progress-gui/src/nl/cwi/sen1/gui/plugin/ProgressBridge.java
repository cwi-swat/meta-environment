// Java tool bridge ProgressBridge
// This file is generated automatically, please do not edit!
// generation time: Jan 4, 2007 3:18:21 PM

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

  public void setMessage(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.setMessage(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `setMessage' not supported.");
    }
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
  public void setStatus(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.setStatus(t0, s1, t2);
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
