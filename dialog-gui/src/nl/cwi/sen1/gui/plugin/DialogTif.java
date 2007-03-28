// Java tool interface DialogTif
// This file is generated automatically, please do not edit!
// generation time: Mar 28, 2007 3:57:36 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface DialogTif
{
  public void showProgressMessage(String s0);
  public void showErrorDialogWithArguments(String s0, ATerm t1);
  public void showMessageDialog(String s0);
  public void showProgressList(String s0);
  public void showProgressMessageWithArguments(String s0, ATerm t1);
  public void showErrorDialog(String s0);
  public void closeProgressList();
  public ATerm showQuestionDialog(String s0);
  public ATerm showDirectoryDialog(String s0, ATerm t1);
  public ATerm showFileDialog(String s0, ATerm t1, String s2);
  public void recTerminate(ATerm t0);
}
