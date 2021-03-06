// Java tool bridge DialogBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 28, 2007 3:57:36 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class DialogBridge
  extends DialogTool
{
  private DialogTif tool;

  public DialogBridge(ATermFactory factory, DialogTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void showProgressMessage(String s0)
  {
    if (tool != null) {
      tool.showProgressMessage(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showProgressMessage' not supported.");
    }
  }
  public void showErrorDialogWithArguments(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.showErrorDialogWithArguments(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showErrorDialogWithArguments' not supported.");
    }
  }
  public void showMessageDialog(String s0)
  {
    if (tool != null) {
      tool.showMessageDialog(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showMessageDialog' not supported.");
    }
  }
  public void showProgressList(String s0)
  {
    if (tool != null) {
      tool.showProgressList(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showProgressList' not supported.");
    }
  }
  public void showProgressMessageWithArguments(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.showProgressMessageWithArguments(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showProgressMessageWithArguments' not supported.");
    }
  }
  public void showErrorDialog(String s0)
  {
    if (tool != null) {
      tool.showErrorDialog(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showErrorDialog' not supported.");
    }
  }
  public void closeProgressList()
  {
    if (tool != null) {
      tool.closeProgressList();
    }
    else {
      throw new UnsupportedOperationException("method `closeProgressList' not supported.");
    }
  }
  public ATerm showQuestionDialog(String s0)
  {
    if (tool != null) {
      return tool.showQuestionDialog(s0);
    }
      throw new UnsupportedOperationException("method `showQuestionDialog' not supported.");
  }
  public ATerm showDirectoryDialog(String s0, ATerm t1)
  {
    if (tool != null) {
      return tool.showDirectoryDialog(s0, t1);
    }
      throw new UnsupportedOperationException("method `showDirectoryDialog' not supported.");
  }
  public ATerm showFileDialog(String s0, ATerm t1, String s2)
  {
    if (tool != null) {
      return tool.showFileDialog(s0, t1, s2);
    }
      throw new UnsupportedOperationException("method `showFileDialog' not supported.");
  }
  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }
}
