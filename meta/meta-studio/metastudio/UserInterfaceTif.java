// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Jun 3, 2003 1:08:20 PM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void addStatus(ATerm t0, String s1);
  public void moduleInfo(String s0, ATerm t1);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void errorf(String s0, ATerm t1);
  public void graphLayouted(String s0, ATerm t1);
  public void initializeUi(String s0, String s1, String s2, String s3, String s4);
  public void buttonsFound(String s0, String s1, ATerm t2);
  public void clearHistory();
  public void deleteModules(ATerm t0);
  public void error(String s0);
  public void displayGraph(String s0, ATerm t1);
  public void newGraph(ATerm t0);
  public void updateList(ATerm t0);
  public void endStatus(ATerm t0);
  public ATerm deconsFilename(String s0, String s1);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
