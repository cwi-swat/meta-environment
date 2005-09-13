// Java tool bridge ModuleManagerBridge
// This file is generated automatically, please do not edit!
// generation time: Sep 13, 2005 12:00:34 PM

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

  //{{{  public void deleteDependencies(int i0)

  public void deleteDependencies(int i0)
  {
    if (tool != null) {
      tool.deleteDependencies(i0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteDependencies' not supported.");
    }
  }

  //}}}
  //{{{  public void addDependency(int i0, int i1)

  public void addDependency(int i0, int i1)
  {
    if (tool != null) {
      tool.addDependency(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `addDependency' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteModule(int i0)

  public void deleteModule(int i0)
  {
    if (tool != null) {
      tool.deleteModule(i0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteModule' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteAttribute(int i0, ATerm t1, ATerm t2)

  public void deleteAttribute(int i0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      tool.deleteAttribute(i0, t1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `deleteAttribute' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteDependency(int i0, int i1)

  public void deleteDependency(int i0, int i1)
  {
    if (tool != null) {
      tool.deleteDependency(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `deleteDependency' not supported.");
    }
  }

  //}}}
  //{{{  public void addAttribute(int i0, ATerm t1, ATerm t2, ATerm t3)

  public void addAttribute(int i0, ATerm t1, ATerm t2, ATerm t3)
  {
    if (tool != null) {
      tool.addAttribute(i0, t1, t2, t3);
    }
    else {
      throw new UnsupportedOperationException("method `addAttribute' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm getDependenciesByAttribute(ATerm t0, ATerm t1)

  public ATerm getDependenciesByAttribute(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      return tool.getDependenciesByAttribute(t0, t1);
    }
      throw new UnsupportedOperationException("method `getDependenciesByAttribute' not supported.");
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
  //{{{  public ATerm createModule(ATerm t0)

  public ATerm createModule(ATerm t0)
  {
    if (tool != null) {
      return tool.createModule(t0);
    }
      throw new UnsupportedOperationException("method `createModule' not supported.");
  }

  //}}}
  //{{{  public ATerm getAttribute(int i0, ATerm t1, ATerm t2)

  public ATerm getAttribute(int i0, ATerm t1, ATerm t2)
  {
    if (tool != null) {
      return tool.getAttribute(i0, t1, t2);
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
