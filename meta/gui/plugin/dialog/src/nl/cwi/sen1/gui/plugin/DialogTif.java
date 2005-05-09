// Java tool interface DialogTif
// This file is generated automatically, please do not edit!
// generation time: May 9, 2005 3:36:50 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface DialogTif
{
  public void showProgressMessage(String s0);
  public void showProgressList(String s0);
  public void showProgressMessageWithArguments(String s0, ATerm t1);
  public void closeProgressList();
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recTerminate(ATerm t0);
}
