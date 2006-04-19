// Java tool bridge ErrorViewerBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 9:56:30 AM

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

  public void showFeedbackSummary(ATerm t0)
  {
    if (tool != null) {
      tool.showFeedbackSummary(t0);
    }
    else {
      throw new UnsupportedOperationException("method `showFeedbackSummary' not supported.");
    }
  }
  public void removeFeedbackSummary(String s0)
  {
    if (tool != null) {
      tool.removeFeedbackSummary(s0);
    }
    else {
      throw new UnsupportedOperationException("method `removeFeedbackSummary' not supported.");
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
