// Java tool bridge FileDialogBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:17:38 PM

package metastudio.components.filedialog;

import aterm.*;

public class FileDialogBridge
  extends FileDialogTool
{
  private FileDialogTif tool;

  //{{{  public FileDialogBridge(ATermFactory factory, FileDialogTif tool)

  public FileDialogBridge(ATermFactory factory, FileDialogTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void showListChoice(String s0, String s1, ATerm t2)

  public void showListChoice(String s0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.showListChoice(s0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `showListChoice' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm showQuestionDialog(String s0)

  public ATerm showQuestionDialog(String s0)
  {
    if (tool != null) {
      return tool.showQuestionDialog(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showQuestionDialog' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm showFileDialog(String s0, String s1, String s2)

  public ATerm showFileDialog(String s0, String s1, String s2)
  {
    if (tool != null) {
      return tool.showFileDialog(s0, s1, s2);
    }
    else {
      throw new UnsupportedOperationException("method `showFileDialog' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
