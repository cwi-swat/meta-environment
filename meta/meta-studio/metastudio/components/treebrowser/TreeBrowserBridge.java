// Java tool bridge TreeBrowserBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 10:56:33 AM

package metastudio.components.treebrowser;

import aterm.*;

public class TreeBrowserBridge
  extends TreeBrowserTool
{
  private TreeBrowserTif tool;

  //{{{  public TreeBrowserBridge(ATermFactory factory, TreeBrowserTif tool)

  public TreeBrowserBridge(ATermFactory factory, TreeBrowserTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void displayTree(ATerm t0)

  public void displayTree(ATerm t0)
  {
    if (tool != null) {
      tool.displayTree(t0);
    }
    else {
      throw new UnsupportedOperationException("method `displayTree' not supported.");
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
