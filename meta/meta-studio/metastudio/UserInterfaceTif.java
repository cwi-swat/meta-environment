// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Dec 18, 2003 4:42:20 PM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void addStatus(ATerm t0, String s1);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void errorf(String s0, ATerm t1);
  public void graphLayouted(String s0, ATerm t1);
  public void initializeUi(String s0);
  public void buttonsFound(ATerm t0, String s1, ATerm t2);
  public void clearHistory();
  public void displayGraph(String s0, ATerm t1);
  public void error(String s0);
  public void newGraph(ATerm t0);
  public void updateList(String s0, String s1);
  public void warning(String s0);
  public void displayFeedbackSummary(ATerm t0);
  public void messagef(String s0, ATerm t1);
  public void endStatus(ATerm t0);
  public void message(String s0);
  public void warningf(String s0, ATerm t1);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
