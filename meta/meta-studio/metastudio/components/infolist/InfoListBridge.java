// Java tool bridge InfoListBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 11:22:37 AM

package metastudio.components.infolist;

import aterm.*;

public class InfoListBridge
  extends InfoListTool
{
  private InfoListTif tool;

  //{{{  public InfoListBridge(ATermFactory factory, InfoListTif tool)

  public InfoListBridge(ATermFactory factory, InfoListTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void errorf(String s0, ATerm t1)

  public void errorf(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.errorf(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `errorf' not supported.");
    }
  }

  //}}}
  //{{{  public void error(String s0)

  public void error(String s0)
  {
    if (tool != null) {
      tool.error(s0);
    }
    else {
      throw new UnsupportedOperationException("method `error' not supported.");
    }
  }

  //}}}
  //{{{  public void warningf(String s0, ATerm t1)

  public void warningf(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.warningf(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `warningf' not supported.");
    }
  }

  //}}}
  //{{{  public void warning(String s0)

  public void warning(String s0)
  {
    if (tool != null) {
      tool.warning(s0);
    }
    else {
      throw new UnsupportedOperationException("method `warning' not supported.");
    }
  }

  //}}}
  //{{{  public void message(String s0)

  public void message(String s0)
  {
    if (tool != null) {
      tool.message(s0);
    }
    else {
      throw new UnsupportedOperationException("method `message' not supported.");
    }
  }

  //}}}
  //{{{  public void messagef(String s0, ATerm t1)

  public void messagef(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.messagef(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `messagef' not supported.");
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
