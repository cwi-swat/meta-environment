// Java tool interface GuiTif
// This file is generated automatically, please do not edit!
// generation time: May 2, 2005 2:24:06 PM

package nl.cwi.sen1.gui;

import aterm.ATerm;

public interface GuiTif
{
  public void loadJarUrls(String s0, ATerm t1);
  public void loadJar(String s0);
  public void addMenuEvents(ATerm t0);
  public void loadJarClasspath(String s0, String s1);
  public void setTitle(String s0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
