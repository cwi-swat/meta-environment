// Java tool bridge SwixmlBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 23, 2007 3:17:40 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class SwixmlBridge
  extends SwixmlTool
{
  private SwixmlTif tool;

  public SwixmlBridge(ATermFactory factory, SwixmlTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void swixmlDisplay(String s0, String s1)
  {
    if (tool != null) {
      tool.swixmlDisplay(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `swixmlDisplay' not supported.");
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
