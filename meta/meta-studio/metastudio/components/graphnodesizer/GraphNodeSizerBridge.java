// Java tool bridge GraphNodeSizerBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 9:13:16 AM

package metastudio.components.graphnodesizer;

import aterm.*;

public class GraphNodeSizerBridge
  extends GraphNodeSizerTool
{
  private GraphNodeSizerTif tool;

  //{{{  public GraphNodeSizerBridge(ATermFactory factory, GraphNodeSizerTif tool)

  public GraphNodeSizerBridge(ATermFactory factory, GraphNodeSizerTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public ATerm sizeGraph(ATerm t0)

  public ATerm sizeGraph(ATerm t0)
  {
    if (tool != null) {
      return tool.sizeGraph(t0);
    }
    else {
      throw new UnsupportedOperationException("method `sizeGraph' not supported.");
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
