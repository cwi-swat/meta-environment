// Java tool bridge ModuleBrowserBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 12:30:30 PM

package metastudio.components.modulebrowser;

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

  //{{{  public void displayGraph(String s0, ATerm t1)

  public void displayGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayGraph' not supported.");
    }
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
