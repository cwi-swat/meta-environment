// Java tool interface ModuleManagerTif
// This file is generated automatically, please do not edit!
// generation time: Feb 8, 2006 11:42:04 AM

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
  public void registerInheritedAttribute(ATerm t0, ATerm t1, ATerm t2, ATerm t3, ATerm t4);
  public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2);
  public ATerm getAllAttributes(ATerm t0);
  public ATerm getDependencies();
  public ATerm getChildrenModules(ATerm t0);
  public ATerm getAllParentModules(ATerm t0);
  public ATerm getClosableModules(ATerm t0);
  public ATerm getAllChildrenModules(ATerm t0);
  public ATerm getAllModules();
  public ATerm createModule();
  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2);
  public ATerm getModuleGraph(ATerm t0);
  public ATerm getParentModules(ATerm t0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
