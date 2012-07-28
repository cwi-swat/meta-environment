// Java tool bridge SvgBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 11, 2007 3:42:54 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class SvgBridge
  extends SvgTool
{
  private SvgTif tool;

  public SvgBridge(ATermFactory factory, SvgTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void display(String s0, String s1)
  {
    if (tool != null) {
      tool.display(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `display' not supported.");
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
