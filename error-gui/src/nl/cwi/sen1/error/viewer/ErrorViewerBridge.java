// Java tool bridge ErrorViewerBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 8, 2005 4:18:23 PM

package nl.cwi.sen1.error.viewer;

import aterm.ATerm;
import aterm.ATermFactory;

public class ErrorViewerBridge
  extends ErrorViewerTool
{
  private ErrorViewerTif tool;

  //{{{  public ErrorViewerBridge(ATermFactory factory, ErrorViewerTif tool)

  public ErrorViewerBridge(ATermFactory factory, ErrorViewerTif tool)
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
