// Java tool interface StatusHistoryTif
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 3:52:28 PM

package metastudio.components.statushistory;

import aterm.*;

public interface StatusHistoryTif
{
  public void logStatus(ATerm t0, String s1);
  public void logEndStatus(ATerm t0);
  public void logStatusf(ATerm t0, String s1, ATerm t2);
  public void clearHistory();
  public void recTerminate(ATerm t0);
}
