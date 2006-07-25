// Java tool bridge GuiBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 29, 2006 1:02:23 PM

package nl.cwi.sen1.gui;

import aterm.*;

public class GuiBridge
  extends GuiTool
{
  private GuiTif tool;

  public GuiBridge(ATermFactory factory, GuiTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void loadJarUrls(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.loadJarUrls(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `loadJarUrls' not supported.");
    }
  }
  public void loadJar(String s0)
  {
    if (tool != null) {
      tool.loadJar(s0);
    }
    else {
      throw new UnsupportedOperationException("method `loadJar' not supported.");
    }
  }
  public void addMenuEvents(ATerm t0)
  {
    if (tool != null) {
      tool.addMenuEvents(t0);
    }
    else {
      throw new UnsupportedOperationException("method `addMenuEvents' not supported.");
    }
  }
  public void loadJarClasspath(String s0, String s1)
  {
    if (tool != null) {
      tool.loadJarClasspath(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `loadJarClasspath' not supported.");
    }
  }
  public void jobDone(String s0)
  {
    if (tool != null) {
      tool.jobDone(s0);
    }
    else {
      throw new UnsupportedOperationException("method `jobDone' not supported.");
    }
  }
  public void addJob(String s0)
  {
    if (tool != null) {
      tool.addJob(s0);
    }
    else {
      throw new UnsupportedOperationException("method `addJob' not supported.");
    }
  }
  public void setStatus(String s0)
  {
    if (tool != null) {
      tool.setStatus(s0);
    }
    else {
      throw new UnsupportedOperationException("method `setStatus' not supported.");
    }
  }
  public void setTitle(String s0)
  {
    if (tool != null) {
      tool.setTitle(s0);
    }
    else {
      throw new UnsupportedOperationException("method `setTitle' not supported.");
    }
  }
  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }
  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }
}
