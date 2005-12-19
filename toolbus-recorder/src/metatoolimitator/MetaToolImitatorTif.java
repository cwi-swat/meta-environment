package metatoolimitator;
// Java tool interface MetaToolImitatorTif
// This file is generated automatically, please do not edit!
// generation time: Jun 30, 2005 11:02:22 AM


import aterm.*;

public interface MetaToolImitatorTif
{
  /*
  public void messagef(String s0, ATerm t1);
  public void initializeUi(String s0);
  public void showListChoice(String s0, String s1, ATerm t2);
  public void warningf(String s0, ATerm t1);
  public void message(String s0);
  public void newGraph(ATerm t0);
  public void refreshFeedbackSummary(ATerm t0);
  public void displayGraph(String s0, ATerm t1);
  public void clearHistory();
  public void graphLayouted(String s0, ATerm t1);
  public void errorf(String s0, ATerm t1);
  public void warning(String s0);
  public void error(String s0);
  public void buttonsFound(ATerm t0, String s1, ATerm t2);
  public void removeFeedbackSummary(String s0, String s1);
  public void showFeedbackSummary(ATerm t0);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void endStatus(ATerm t0);
  public void addStatus(ATerm t0, String s1);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(ATerm t0, String s1, String s2, String s3);
  public ATerm makeGraph(ATerm t0);
  public void recAckEvent(ATerm t0);
  */
  public void recTerminate(ATerm t0);
  public ATerm processCommunication();
}
