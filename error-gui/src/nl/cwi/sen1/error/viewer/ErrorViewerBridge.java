// Java tool bridge ErrorViewerBridge
// This file is generated automatically, please do not edit!
// generation time: Oct 11, 2006 1:39:32 PM

package nl.cwi.sen1.error.viewer;

import aterm.*;

public class ErrorViewerBridge
  extends ErrorViewerTool
{
  private ErrorViewerTif tool;

  public ErrorViewerBridge(ATermFactory factory, ErrorViewerTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void showFeedbackSummary(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.showFeedbackSummary(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showFeedbackSummary' not supported.");
    }
  }
  public void removeFeedbackSummary(String s0, String s1)
  {
    if (tool != null) {
      tool.removeFeedbackSummary(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `removeFeedbackSummary' not supported.");
    }
  }
  public void removeFeedbackSummary(String s0, String s1, String s2)
  {
    if (tool != null) {
      tool.removeFeedbackSummary(s0, s1, s2);
    }
    else {
      throw new UnsupportedOperationException("method `removeFeedbackSummary' not supported.");
    }
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
