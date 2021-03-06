// Java tool bridge ModuledetailsBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 11, 2007 3:34:17 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class ModuledetailsBridge
  extends ModuledetailsTool
{
  private ModuledetailsTif tool;

  public ModuledetailsBridge(ATermFactory factory, ModuledetailsTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void setDetails(ATerm t0)
  {
    if (tool != null) {
      tool.setDetails(t0);
    }
    else {
      throw new UnsupportedOperationException("method `setDetails' not supported.");
    }
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
