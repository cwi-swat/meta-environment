// Java tool interface ErrorViewerTif
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 9:56:30 AM

package nl.cwi.sen1.error.viewer;

import aterm.*;

public interface ErrorViewerTif
{
  public void showFeedbackSummary(ATerm t0);
  public void removeFeedbackSummary(String s0);
  public void removeFeedbackSummary(String s0, String s1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
