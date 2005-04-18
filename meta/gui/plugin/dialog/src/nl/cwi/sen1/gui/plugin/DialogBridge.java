// Java tool bridge DialogBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 18, 2005 10:48:18 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class DialogBridge
  extends DialogTool
{
  private DialogTif tool;

  //{{{  public DialogBridge(ATermFactory factory, DialogTif tool)

  public DialogBridge(ATermFactory factory, DialogTif tool)
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
