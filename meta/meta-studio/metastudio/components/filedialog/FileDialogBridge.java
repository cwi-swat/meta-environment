// Java tool bridge FileDialogBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 11:55:34 AM

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
