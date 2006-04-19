// Java tool interface DialogTif
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 9:54:56 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface DialogTif
{
  public void showProgressMessage(String s0);
  public void showErrorDialogWithArguments(String s0, ATerm t1);
  public void showProgressList(String s0);
  public void showProgressMessageWithArguments(String s0, ATerm t1);
  public void showErrorDialog(String s0);
  public void closeProgressList();
  public ATerm showQuestionDialog(String s0);
  public ATerm showDirectoryDialog(String s0, ATerm t1);
  public ATerm showFileDialog(String s0, ATerm t1, String s2);
  public void recTerminate(ATerm t0);
}
