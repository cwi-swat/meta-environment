// Java tool interface GuiTif
// This file is generated automatically, please do not edit!
// generation time: Mar 29, 2006 1:02:23 PM

package nl.cwi.sen1.gui;

import aterm.*;

public interface GuiTif
{
  public void loadJarUrls(String s0, ATerm t1);
  public void loadJar(String s0);
  public void addMenuEvents(ATerm t0);
  public void loadJarClasspath(String s0, String s1);
  public void jobDone(String s0);
  public void addJob(String s0);
  public void setStatus(String s0);
  public void setTitle(String s0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
