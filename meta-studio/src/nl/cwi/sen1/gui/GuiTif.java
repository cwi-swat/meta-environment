// Java tool interface GuiTif
// This file is generated automatically, please do not edit!
// generation time: Feb 22, 2007 12:49:51 PM

package nl.cwi.sen1.gui;

import aterm.*;

public interface GuiTif
{
  public void addJob(String s0);
  public void setAtomicStep(String s0, int i1);
  public void loadJar(String s0);
  public void loadJarUrls(String s0, ATerm t1);
  public void addMenuEvents(ATerm t0);
  public void jobDone(String s0);
  public void setStatus(String s0);
  public void addDeterministicJob(String s0, int i1);
  public void loadJarClasspath(String s0, String s1);
  public void setTitle(String s0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
