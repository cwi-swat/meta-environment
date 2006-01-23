// Java tool bridge ModuleManagerBridge
// This file is generated automatically, please do not edit!
// generation time: Jan 23, 2006 9:14:16 AM

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
  //{{{  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2)

  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      return tool.getAttribute(t0, t1, t2);
    }
      throw new UnsupportedOperationException("method `getAttribute' not supported.");
  }

  //}}}
  //{{{  public ATerm getAllAttributes(ATerm t0)

  public ATerm getAllAttributes(ATerm t0)
  {
    if (tool != null) {
      return tool.getAllAttributes(t0);
    }
      throw new UnsupportedOperationException("method `getAllAttributes' not supported.");
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
  //{{{  public ATerm getChildrenModules(ATerm t0)

  public ATerm getChildrenModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getChildrenModules(t0);
    }
      throw new UnsupportedOperationException("method `getChildrenModules' not supported.");
  }

  //}}}
  //{{{  public ATerm getAllParentModules(ATerm t0)

  public ATerm getAllParentModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getAllParentModules(t0);
    }
      throw new UnsupportedOperationException("method `getAllParentModules' not supported.");
  }

  //}}}
  //{{{  public ATerm getClosableModules(ATerm t0)

  public ATerm getClosableModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getClosableModules(t0);
    }
      throw new UnsupportedOperationException("method `getClosableModules' not supported.");
  }

  //}}}
  //{{{  public ATerm getAllChildrenModules(ATerm t0)

  public ATerm getAllChildrenModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getAllChildrenModules(t0);
    }
      throw new UnsupportedOperationException("method `getAllChildrenModules' not supported.");
  }

  //}}}
  //{{{  public ATerm getAllModules()

  public ATerm getAllModules()
  {
    if (tool != null) {
      return tool.getAllModules();
    }
      throw new UnsupportedOperationException("method `getAllModules' not supported.");
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
  //{{{  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2)

  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      return tool.getModuleIdByAttribute(t0, t1, t2);
    }
      throw new UnsupportedOperationException("method `getModuleIdByAttribute' not supported.");
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
  //{{{  public ATerm getParentModules(ATerm t0)

  public ATerm getParentModules(ATerm t0)
  {
    if (tool != null) {
      return tool.getParentModules(t0);
    }
      throw new UnsupportedOperationException("method `getParentModules' not supported.");
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
