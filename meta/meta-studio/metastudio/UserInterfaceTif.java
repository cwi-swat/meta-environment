// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 12:03:25 PM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void displayGraph(String s0, ATerm t1);
  public void showListChoice(String s0, String s1, ATerm t2);
  public void addEvents(ATerm t0, String s1, ATerm t2);
  public void addEvents(ATerm t0, ATerm t1);
  public void renderGraph(String s0, ATerm t1);
  public void initializeUi(String s0);
  public void clearHistory();
  public void displayTreelist(String s0, ATerm t1);
  public ATerm showQuestionDialog(String s0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
