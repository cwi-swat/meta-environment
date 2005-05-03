// Java tool bridge DebugAdapterBridge
// This file is generated automatically, please do not edit!
// generation time: Oct 6, 2004 8:54:49 AM

package nl.cwi.sen1.tide.adapters;

import aterm.*;

public class DebugAdapterBridge
  extends DebugAdapterTool
{
  private DebugAdapterTif tool;

  //{{{  public DebugAdapterBridge(ATermFactory factory, DebugAdapterTif tool)

  public DebugAdapterBridge(ATermFactory factory, DebugAdapterTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public ATerm modifyRule(int i0, int i1, ATerm t2, ATerm t3, ATerm t4, ATerm t5)

  public ATerm modifyRule(int i0, int i1, ATerm t2, ATerm t3, ATerm t4, ATerm t5)
  {
    if (tool != null) {
      return tool.modifyRule(i0, i1, t2, t3, t4, t5);
    }
    else {
      throw new UnsupportedOperationException("method `modifyRule' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm disableRule(int i0, int i1)

  public ATerm disableRule(int i0, int i1)
  {
    if (tool != null) {
      return tool.disableRule(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `disableRule' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm enableRule(int i0, int i1)

  public ATerm enableRule(int i0, int i1)
  {
    if (tool != null) {
      return tool.enableRule(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `enableRule' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm deleteRule(int i0, int i1)

  public ATerm deleteRule(int i0, int i1)
  {
    if (tool != null) {
      return tool.deleteRule(i0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `deleteRule' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm createRule(int i0, ATerm t1, ATerm t2, ATerm t3, ATerm t4, ATerm t5)

  public ATerm createRule(int i0, ATerm t1, ATerm t2, ATerm t3, ATerm t4, ATerm t5)
  {
    if (tool != null) {
      return tool.createRule(i0, t1, t2, t3, t4, t5);
    }
    else {
      throw new UnsupportedOperationException("method `createRule' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm evaluate(int i0, ATerm t1)

  public ATerm evaluate(int i0, ATerm t1)
  {
    if (tool != null) {
      return tool.evaluate(i0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `evaluate' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
