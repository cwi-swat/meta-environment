// Java tool bridge GraphPainterBridge
// This file is generated automatically, please do not edit!
// generation time: May 2, 2006 10:49:15 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class GraphPainterBridge
  extends GraphPainterTool
{
  private GraphPainterTif tool;

  public GraphPainterBridge(ATermFactory factory, GraphPainterTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void displayGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayGraph' not supported.");
    }
  }
  public void displayGraph(String s0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      tool.displayGraph(s0, t1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `displayGraph' not supported.");
    }
  }
  public void selectNode(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.selectNode(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `selectNode' not supported.");
    }
  }
  public void showPopup(String s0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      tool.showPopup(s0, t1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `showPopup' not supported.");
    }
  }
  public ATerm sizeGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      return tool.sizeGraph(s0, t1);
    }
      throw new UnsupportedOperationException("method `sizeGraph' not supported.");
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
