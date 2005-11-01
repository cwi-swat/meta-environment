// Java tool interface ModuleManagerTif
// This file is generated automatically, please do not edit!
// generation time: Nov 1, 2005 10:32:32 AM

package nl.cwi.sen1.modulemanager;

import aterm.*;

public interface ModuleManagerTif
{
  public void deleteDependencies(ATerm t0);
  public void addDependency(ATerm t0, ATerm t1);
  public void deleteModule(ATerm t0);
  public void deleteAttribute(ATerm t0, ATerm t1, ATerm t2);
  public void deleteDependency(ATerm t0, ATerm t1);
  public void addAttribute(ATerm t0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm getModuleGraph(ATerm t0);
  public ATerm createModule();
  public ATerm getDependencies();
  public ATerm getDependingModules(ATerm t0);
  public ATerm getClosableModules(ATerm t0);
  public ATerm getAllDependingModules(ATerm t0);
  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2);
  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2);
  public void recTerminate(ATerm t0);
}
