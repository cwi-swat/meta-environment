// Java tool interface DebugToolTif
// This file is generated automatically, please do not edit!
// generation time: Jun 10, 2004 3:05:13 PM

package nl.cwi.sen1.tide.tool.support;

import aterm.*;

public interface DebugToolTif
{
  public void processDestroyed(ATerm t0);
  public void adapterDisconnected(ATerm t0);
  public void event(ATerm t0, int i1, ATerm t2);
  public void processCreated(ATerm t0, String s1);
  public void adapterConnected(ATerm t0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
