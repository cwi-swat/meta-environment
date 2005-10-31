// Java tool bridge ModuleManagerBridge
// This file is generated automatically, please do not edit!
// generation time: Oct 31, 2005 9:53:30 AM

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

  //{{{  public void deleteDependencies(ATerm t0)

  public void deleteDependencies(ATerm t0)
  {
    if (tool != null) {
      tool.deleteDependencies(t0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteDependencies' not supported.");
    }
  }

  //}}}
  //{{{  public void addDependency(ATerm t0, ATerm t1)

  public void addDependency(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.addDependency(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `addDependency' not supported.");
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
  //{{{  public void deleteAttribute(ATerm t0, ATerm t1, ATerm t2)

  public void deleteAttribute(ATerm t0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      tool.deleteAttribute(t0, t1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `deleteAttribute' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteDependency(ATerm t0, ATerm t1)

  public void deleteDependency(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.deleteDependency(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `deleteDependency' not supported.");
    }
  }

  //}}}
  //{{{  public void addAttribute(ATerm t0, ATerm t1, ATerm t2, ATerm t3)

  public void addAttribute(ATerm t0, ATerm t1, ATerm t2, ATerm t3)
  {
    if (tool != null) {
      tool.addAttribute(t0, t1, t2, t3);
    }
    else {
      throw new UnsupportedOperationException("method `addAttribute' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm getModuleGraph(ATerm t0)

  public ATerm getModuleGraph(ATerm t0)
  {
    if (tool != null) {
      return tool.getModuleGraph(t0);
    }
      throw new UnsupportedOperationException("method `getModuleGraph' not supported.");
  }

  //}}}
  //{{{  public ATerm createModule()

  public ATerm createModule()
  {
    if (tool != null) {
      return tool.createModule();
    }
      throw new UnsupportedOperationException("method `createModule' not supported.");
  }

  //}}}
  //{{{  public ATerm getDependencies()

  public ATerm getDependencies()
  {
    if (tool != null) {
      return tool.getDependencies();
    }
      throw new UnsupportedOperationException("method `getDependencies' not supported.");
  }

  //}}}
  //{{{  public ATerm getDependingModules(ATerm t0)

  public ATerm getDependingModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getDependingModules(t0);
    }
      throw new UnsupportedOperationException("method `getDependingModules' not supported.");
  }

  //}}}
  //{{{  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2)

  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      return tool.getAttribute(t0, t1, t2);
    }
      throw new UnsupportedOperationException("method `getAttribute' not supported.");
  }

  //}}}
  //{{{  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2)

  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      return tool.getModuleIdByAttribute(t0, t1, t2);
    }
      throw new UnsupportedOperationException("method `getModuleIdByAttribute' not supported.");
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
