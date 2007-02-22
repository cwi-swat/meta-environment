// Java tool bridge ConsoleBridge
// This file is generated automatically, please do not edit!
// generation time: Feb 22, 2007 3:24:38 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ConsoleBridge
  extends ConsoleTool
{
  private ConsoleTif tool;

  public ConsoleBridge(ATermFactory factory, ConsoleTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void addMessage(String s0)
  {
    if (tool != null) {
      tool.addMessage(s0);
    }
    else {
      throw new UnsupportedOperationException("method `addMessage' not supported.");
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
