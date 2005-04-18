// Java tool bridge ModuleBrowserBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 18, 2005 1:46:09 PM

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

  //{{{  public void addEvents(ATerm t0, String s1, ATerm t2)

  public void addEvents(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.addEvents(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `addEvents' not supported.");
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
