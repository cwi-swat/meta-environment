// Java tool bridge ModuleBrowserBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2005 1:45:46 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ModuleBrowserBridge
  extends ModuleBrowserTool
{
  private ModuleBrowserTif tool;

  //{{{  public ModuleBrowserBridge(ATermFactory factory, ModuleBrowserTif tool)

  public ModuleBrowserBridge(ATermFactory factory, ModuleBrowserTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void selectModule(String s0)

  public void selectModule(String s0)
  {
    if (tool != null) {
      tool.selectModule(s0);
    }
    else {
      throw new UnsupportedOperationException("method `selectModule' not supported.");
    }
  }

  //}}}
  //{{{  public void displayTreelist(String s0, ATerm t1)

  public void displayTreelist(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayTreelist(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayTreelist' not supported.");
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
