// Java tool bridge StatusHistoryBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 3:52:29 PM

package metastudio.components.statushistory;

import aterm.*;

public class StatusHistoryBridge
  extends StatusHistoryTool
{
  private StatusHistoryTif tool;

  //{{{  public StatusHistoryBridge(ATermFactory factory, StatusHistoryTif tool)

  public StatusHistoryBridge(ATermFactory factory, StatusHistoryTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void logStatus(ATerm t0, String s1)

  public void logStatus(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.logStatus(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `logStatus' not supported.");
    }
  }

  //}}}
  //{{{  public void logEndStatus(ATerm t0)

  public void logEndStatus(ATerm t0)
  {
    if (tool != null) {
      tool.logEndStatus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `logEndStatus' not supported.");
    }
  }

  //}}}
  //{{{  public void logStatusf(ATerm t0, String s1, ATerm t2)

  public void logStatusf(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.logStatusf(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `logStatusf' not supported.");
    }
  }

  //}}}
  //{{{  public void clearHistory()

  public void clearHistory()
  {
    if (tool != null) {
      tool.clearHistory();
    }
    else {
      throw new UnsupportedOperationException("method `clearHistory' not supported.");
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
