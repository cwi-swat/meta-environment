// Java tool bridge TideControlBridge
// This file is generated automatically, please do not edit!
// generation time: Jun 25, 2001 3:38:17 PM

package tide.tool;

import aterm.*;
import toolbus.*;

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
