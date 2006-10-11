// Java tool interface ErrorViewerTif
// This file is generated automatically, please do not edit!
// generation time: Oct 11, 2006 1:39:32 PM

package nl.cwi.sen1.error.viewer;

import aterm.*;

public interface ErrorViewerTif
{
  public void showFeedbackSummary(String s0, ATerm t1);
  public void removeFeedbackSummary(String s0, String s1);
  public void removeFeedbackSummary(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
