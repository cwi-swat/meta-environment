// Java tool bridge ConsoleGrabberBridge
// This file is generated automatically, please do not edit!
// generation time: Feb 23, 2007 1:41:31 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ConsoleGrabberBridge
  extends ConsoleGrabberTool
{
  private ConsoleGrabberTif tool;

  public ConsoleGrabberBridge(ATermFactory factory, ConsoleGrabberTif tool)
  {
    super(factory);
    this.tool = tool;
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
