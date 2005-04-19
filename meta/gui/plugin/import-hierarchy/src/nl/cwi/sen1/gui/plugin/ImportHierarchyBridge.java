// Java tool bridge ImportHierarchyBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2005 3:01:35 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ImportHierarchyBridge
  extends ImportHierarchyTool
{
  private ImportHierarchyTif tool;

  //{{{  public ImportHierarchyBridge(ATermFactory factory, ImportHierarchyTif tool)

  public ImportHierarchyBridge(ATermFactory factory, ImportHierarchyTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void setHierarchy(String s0, ATerm t1, ATerm t2)

  public void setHierarchy(String s0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      tool.setHierarchy(s0, t1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `setHierarchy' not supported.");
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
