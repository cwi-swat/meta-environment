// Java tool bridge ModuleManagerBridge
// This file is generated automatically, please do not edit!
// generation time: Aug 25, 2005 11:11:10 AM

package nl.cwi.sen1.modulemanager;

import aterm.*;

public class ModuleManagerBridge
  extends ModuleManagerTool
{
  private ModuleManagerTif tool;

  //{{{  public ModuleManagerBridge(ATermFactory factory, ModuleManagerTif tool)

  public ModuleManagerBridge(ATermFactory factory, ModuleManagerTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void createModule(ATerm t0)

  public void createModule(ATerm t0)
  {
    if (tool != null) {
      tool.createModule(t0);
    }
    else {
      throw new UnsupportedOperationException("method `createModule' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteModule(ATerm t0)

  public void deleteModule(ATerm t0)
  {
    if (tool != null) {
      tool.deleteModule(t0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteModule' not supported.");
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
