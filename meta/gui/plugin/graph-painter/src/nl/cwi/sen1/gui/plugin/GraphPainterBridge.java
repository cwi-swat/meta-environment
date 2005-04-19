// Java tool bridge GraphPainterBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2005 2:11:05 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class GraphPainterBridge
  extends GraphPainterTool
{
  private GraphPainterTif tool;

  //{{{  public GraphPainterBridge(ATermFactory factory, GraphPainterTif tool)

  public GraphPainterBridge(ATermFactory factory, GraphPainterTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void displayGraph(String s0, ATerm t1)

  public void displayGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void selectNode(String s0, String s1)

  public void selectNode(String s0, String s1)
  {
    if (tool != null) {
      tool.selectNode(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `selectNode' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm sizeGraph(String s0, ATerm t1)

  public ATerm sizeGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      return tool.sizeGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `sizeGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
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
