// Java tool bridge TideControlBridge
// This file is generated automatically, please do not edit!
// generation time: Oct 18, 2004 7:30:51 PM

package tide;

import aterm.*;

public class TideControlBridge
  extends TideControlTool
{
  private TideControlTif tool;

  //{{{  public TideControlBridge(ATermFactory factory, TideControlTif tool)

  public TideControlBridge(ATermFactory factory, TideControlTif tool)
  {
    super(factory);
    this.tool = tool;
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
