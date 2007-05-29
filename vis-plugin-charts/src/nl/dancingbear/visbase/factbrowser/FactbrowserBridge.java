package nl.dancingbear.visbase.factbrowser;

// Java tool bridge FactbrowserBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 13, 2007 3:53:39 PM


import aterm.*;

public class FactbrowserBridge
  extends FactbrowserTool
{
  private FactbrowserTif tool;

  public FactbrowserBridge(ATermFactory factory, FactbrowserTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void fbRstoreUnloaded(int i0)
  {
    if (tool != null) {
      tool.fbRstoreUnloaded(i0);
    }
    else {
      throw new UnsupportedOperationException("method `fbRstoreUnloaded' not supported.");
    }
  }
  public void fbAddVisualizationPlugin(ATerm t0, int i1, String s2)
  {
    if (tool != null) {
      tool.fbAddVisualizationPlugin(t0, i1, s2);
    }
    else {
      throw new UnsupportedOperationException("method `fbAddVisualizationPlugin' not supported.");
    }
  }
  public void fbShowRstoreFacts(String s0, int i1, ATerm t2)
  {
    if (tool != null) {
      tool.fbShowRstoreFacts(s0, i1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `fbShowRstoreFacts' not supported.");
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
