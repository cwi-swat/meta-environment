// Java tool bridge UserInterfaceBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 11:56:46 AM

package metastudio;

import aterm.*;

public class UserInterfaceBridge
  extends UserInterfaceTool
{
  private UserInterfaceTif tool;

  //{{{  public UserInterfaceBridge(ATermFactory factory, UserInterfaceTif tool)

  public UserInterfaceBridge(ATermFactory factory, UserInterfaceTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void initializeUi(String s0)

  public void initializeUi(String s0)
  {
    if (tool != null) {
      tool.initializeUi(s0);
    }
    else {
      throw new UnsupportedOperationException("method `initializeUi' not supported.");
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
