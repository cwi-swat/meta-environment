// Java tool bridge ErrorListBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:54:44 PM

package metastudio.components.errorlist;

import aterm.*;

public class ErrorListBridge
  extends ErrorListTool
{
  private ErrorListTif tool;

  //{{{  public ErrorListBridge(ATermFactory factory, ErrorListTif tool)

  public ErrorListBridge(ATermFactory factory, ErrorListTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void showFeedbackSummary(ATerm t0)

  public void showFeedbackSummary(ATerm t0)
  {
    if (tool != null) {
      tool.showFeedbackSummary(t0);
    }
    else {
      throw new UnsupportedOperationException("method `showFeedbackSummary' not supported.");
    }
  }

  //}}}
  //{{{  public void removeFeedbackSummary(String s0, String s1)

  public void removeFeedbackSummary(String s0, String s1)
  {
    if (tool != null) {
      tool.removeFeedbackSummary(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `removeFeedbackSummary' not supported.");
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
