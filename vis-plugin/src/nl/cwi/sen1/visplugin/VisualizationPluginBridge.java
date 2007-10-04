package nl.cwi.sen1.visplugin;

// Java tool bridge VisualizationPluginBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 14, 2007 12:48:38 PM


import aterm.*;

public class VisualizationPluginBridge
  extends VisualizationPluginTool
{
  private VisualizationPluginTif tool;

  public VisualizationPluginBridge(ATermFactory factory, VisualizationPluginTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void vpFileDialogResult(int i0, String s1)
  {
    if (tool != null) {
      tool.vpFileDialogResult(i0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `vpFileDialogResult' not supported.");
    }
  }
  public void vpVisualizeFact(int i0, int i1, ATerm t2)
  {
    if (tool != null) {
      tool.vpVisualizeFact(i0, i1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `vpVisualizeFact' not supported.");
    }
  }
  public void vpRstoreUnloaded(int i0)
  {
    if (tool != null) {
      tool.vpRstoreUnloaded(i0);
    }
    else {
      throw new UnsupportedOperationException("method `vpRstoreUnloaded' not supported.");
    }
  }
  public void vpFileDialogCancel(int i0)
  {
    if (tool != null) {
      tool.vpFileDialogCancel(i0);
    }
    else {
      throw new UnsupportedOperationException("method `vpFileDialogCancel' not supported.");
    }
  }
  public void vpFactOutOfDate(int i0, int i1)
  {
    if (tool != null) {
      tool.vpFactOutOfDate(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `vpFactOutOfDate' not supported.");
    }
  }
  public ATerm vpGetName()
  {
    if (tool != null) {
      return tool.vpGetName();
    }
      throw new UnsupportedOperationException("method `vpGetName' not supported.");
  }
  public ATerm vpIsTypeSupported(ATerm t0)
  {
    if (tool != null) {
      return tool.vpIsTypeSupported(t0);
    }
      throw new UnsupportedOperationException("method `vpIsTypeSupported' not supported.");
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
