// Java tool interface ModuleManagerTif
// This file is generated automatically, please do not edit!
// generation time: Sep 7, 2005 10:05:19 AM

package nl.cwi.sen1.modulemanager;

import aterm.*;

public interface ModuleManagerTif
{
  public void deleteDependencies(int i0);
  public void addDependencies(ATerm t0);
  public void addDependency(int i0, int i1);
  public void deleteModule(int i0);
  public void deleteAttribute(int i0, ATerm t1, ATerm t2);
  public void deleteDependency(int i0, int i1);
  public void addAttribute(int i0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm createModule(ATerm t0);
  public ATerm getDependingModules(int i0);
  public ATerm getDependentModules(int i0);
  public ATerm getAttribute(int i0, ATerm t1, ATerm t2);
  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2);
  public void recTerminate(ATerm t0);
}
