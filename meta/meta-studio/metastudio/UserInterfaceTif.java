// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Jan 14, 2004 1:57:26 PM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void messagef(String s0, ATerm t1);
  public void updateList(String s0, String s1);
  public void initializeUi(String s0);
  public void showListChoice(String s0, String s1, ATerm t2);
  public void warningf(String s0, ATerm t1);
  public void message(String s0);
  public void newGraph(ATerm t0);
  public void displayGraph(String s0, ATerm t1);
  public void clearHistory();
  public void graphLayouted(String s0, ATerm t1);
  public void errorf(String s0, ATerm t1);
  public void warning(String s0);
  public void error(String s0);
  public void buttonsFound(ATerm t0, String s1, ATerm t2);
  public void displayFeedbackSummary(ATerm t0);
  public void removeFeedbackSummary(String s0, String s1);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void endStatus(ATerm t0);
  public void addStatus(ATerm t0, String s1);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
