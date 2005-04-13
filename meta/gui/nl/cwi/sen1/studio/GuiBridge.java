// Java tool bridge GuiBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 13, 2005 10:12:21 AM

package nl.cwi.sen1.studio;

import aterm.ATerm;
import aterm.ATermFactory;

public class GuiBridge
  extends GuiTool
{
  private GuiTif tool;

  //{{{  public GuiBridge(ATermFactory factory, GuiTif tool)

  public GuiBridge(ATermFactory factory, GuiTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void loadJar(String s0)

  public void loadJar(String s0)
  {
    if (tool != null) {
      tool.loadJar(s0);
    }
    else {
      throw new UnsupportedOperationException("method `loadJar' not supported.");
    }
  }

  //}}}
  //{{{  public void loadClass(String s0, String s1)

  public void loadClass(String s0, String s1)
  {
    if (tool != null) {
      tool.loadClass(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `loadClass' not supported.");
    }
  }

  //}}}
  //{{{  public void setTitle(String s0)

  public void setTitle(String s0)
  {
    if (tool != null) {
      tool.setTitle(s0);
    }
    else {
      throw new UnsupportedOperationException("method `setTitle' not supported.");
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
