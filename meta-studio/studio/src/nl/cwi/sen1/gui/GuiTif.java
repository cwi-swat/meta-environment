// Java tool interface GuiTif
// This file is generated automatically, please do not edit!
// generation time: Apr 29, 2005 2:36:44 PM

package nl.cwi.sen1.gui;

import aterm.*;

public interface GuiTif
{
  public void loadJarUrls(String s0, ATerm t1);
  public void loadJar(String s0);
  public void loadClass(String s0, String s1);
  public void addMenuEvents(ATerm t0);
  public void loadJarClasspath(String s0, String s1);
  public void setTitle(String s0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
