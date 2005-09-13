// Java tool interface ModuleManagerTif
// This file is generated automatically, please do not edit!
// generation time: Sep 13, 2005 12:00:34 PM

package nl.cwi.sen1.modulemanager;

import aterm.*;

public interface ModuleManagerTif
{
  public void deleteDependencies(int i0);
  public void addDependency(int i0, int i1);
  public void deleteModule(int i0);
  public void deleteAttribute(int i0, ATerm t1, ATerm t2);
  public void deleteDependency(int i0, int i1);
  public void addAttribute(int i0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm getDependenciesByAttribute(ATerm t0, ATerm t1);
  public ATerm createModule();
  public ATerm createModule(ATerm t0);
  public ATerm getAttribute(int i0, ATerm t1, ATerm t2);
  public ATerm getModuleIdByAttribute(ATerm t0, ATerm t1, ATerm t2);
  public void recTerminate(ATerm t0);
}
