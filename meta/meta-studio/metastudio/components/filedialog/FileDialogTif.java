// Java tool interface FileDialogTif
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:17:38 PM

package metastudio.components.filedialog;

import aterm.*;

public interface FileDialogTif
{
  public void showListChoice(String s0, String s1, ATerm t2);
  public ATerm showQuestionDialog(String s0);
  public ATerm showFileDialog(String s0, String s1, String s2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
