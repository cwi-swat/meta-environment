// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: May 25, 2004 1:10:40 PM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void addStatus(ATerm t0, String s1);
  public void showListChoice(String s0, String s1, ATerm t2);
  public void renderGraph(String s0, ATerm t1);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void showFeedbackSummary(ATerm t0);
  public void errorf(String s0, ATerm t1);
  public void initializeUi(String s0);
  public void addEvents(ATerm t0, String s1, ATerm t2);
  public void addEvents(ATerm t0, ATerm t1);
  public void clearHistory();
  public void displayGraph(String s0, ATerm t1);
  public void error(String s0);
  public void removeFeedbackSummary(String s0, String s1);
  public void warning(String s0);
  public void messagef(String s0, ATerm t1);
  public void endStatus(ATerm t0);
  public void message(String s0);
  public void warningf(String s0, ATerm t1);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
