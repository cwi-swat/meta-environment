// Java tool bridge VisPluginTextUnparsingBridge
// This file is generated automatically, please do not edit!
// generation time: Aug 22, 2007 2:40:01 PM

package nl.cwi.sen1.visplugin.text;

import aterm.*;

public class VisPluginTextUnparsingBridge
  extends VisPluginTextUnparsingTool
{
  private VisPluginTextUnparsingTif tool;

  public VisPluginTextUnparsingBridge(ATermFactory factory, VisPluginTextUnparsingTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void displayUnparsedRtuple(String s0)
  {
    if (tool != null) {
      tool.displayUnparsedRtuple(s0);
    }
    else {
      throw new UnsupportedOperationException("method `displayUnparsedRtuple' not supported.");
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
