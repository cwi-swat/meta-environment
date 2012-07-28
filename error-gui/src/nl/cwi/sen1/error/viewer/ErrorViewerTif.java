// Java tool interface ErrorViewerTif
// This file is generated automatically, please do not edit!
// generation time: Jan 30, 2007 7:11:53 AM

package nl.cwi.sen1.error.viewer;

import aterm.*;

public interface ErrorViewerTif
{
  public void showFeedbackSummary(String s0, ATerm t1);
  public void refreshFeedbackSummary(String s0, ATerm t1);
  public void removeFeedbackSummary(String s0, String s1);
  public void removeFeedbackSummary(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
