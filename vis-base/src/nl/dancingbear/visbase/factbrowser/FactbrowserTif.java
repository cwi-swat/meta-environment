// Java tool interface FactbrowserTif
// This file is generated automatically, please do not edit!
// generation time: Aug 14, 2007 5:15:07 PM

package nl.dancingbear.visbase.factbrowser;

import aterm.*;

public interface FactbrowserTif
{
  public void fbRstoreUnloaded(int i0);
  public void fbAddVisualizationPlugin(ATerm t0, int i1, String s2);
  public void fbShowRstoreFacts(String s0, int i1, ATerm t2);
  public ATerm getSelectedRstoreid();
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
