// Java tool bridge StatusBarBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 10:08:49 AM

package metastudio.components.statusbar;

import aterm.*;

public class StatusBarBridge
  extends StatusBarTool
{
  private StatusBarTif tool;

  //{{{  public StatusBarBridge(ATermFactory factory, StatusBarTif tool)

  public StatusBarBridge(ATermFactory factory, StatusBarTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void addStatus(ATerm t0, String s1)

  public void addStatus(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.addStatus(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `addStatus' not supported.");
    }
  }

  //}}}
  //{{{  public void addStatusf(ATerm t0, String s1, ATerm t2)

  public void addStatusf(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.addStatusf(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `addStatusf' not supported.");
    }
  }

  //}}}
  //{{{  public void endStatus(ATerm t0)

  public void endStatus(ATerm t0)
  {
    if (tool != null) {
      tool.endStatus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `endStatus' not supported.");
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
