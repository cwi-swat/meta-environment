// Java tool bridge ProgressBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 28, 2005 8:06:26 AM

package nl.cwi.sen1.gui.plugin.viewer;

import aterm.*;

public class ProgressBridge
  extends ProgressTool
{
  private ProgressTif tool;

  //{{{  public ProgressBridge(ATermFactory factory, ProgressTif tool)

  public ProgressBridge(ATermFactory factory, ProgressTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void clearStatusWindow()

  public void clearStatusWindow()
  {
    if (tool != null) {
      tool.clearStatusWindow();
    }
    else {
      throw new UnsupportedOperationException("method `clearStatusWindow' not supported.");
    }
  }

  //}}}
  //{{{  public void setStatus(String s0, ATerm t1)

  public void setStatus(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.setStatus(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `setStatus' not supported.");
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
