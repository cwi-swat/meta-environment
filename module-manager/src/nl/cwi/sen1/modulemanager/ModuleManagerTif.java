// Java tool interface ModuleManagerTif
// This file is generated automatically, please do not edit!
// generation time: Sep 5, 2005 2:47:40 PM

package nl.cwi.sen1.modulemanager;

import aterm.*;

public interface ModuleManagerTif
{
  public void deleteDependencies(ATerm t0);
  public void addDependencies(ATerm t0, ATerm t1);
  public void createModule(ATerm t0);
  public void addDependency(ATerm t0, ATerm t1);
  public void deleteModule(ATerm t0);
  public void deleteAttribute(ATerm t0, ATerm t1, ATerm t2);
  public void deleteDependency(ATerm t0, ATerm t1);
  public void addAttribute(ATerm t0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm getDependingModules(ATerm t0);
  public ATerm getDependentModules(ATerm t0);
  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2);
  public ATerm renameModule(ATerm t0, ATerm t1);
  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2);
  public ATerm getModuleId(ATerm t0, ATerm t1);
  public void recTerminate(ATerm t0);
}
