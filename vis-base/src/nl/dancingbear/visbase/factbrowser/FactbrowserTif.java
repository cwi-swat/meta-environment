// Java tool interface FactbrowserTif
// This file is generated automatically, please do not edit!
// generation time: Aug 17, 2007 9:19:04 AM

package nl.dancingbear.visbase.factbrowser;

import aterm.*;

public interface FactbrowserTif
{
  public void fbRstoreUnloaded(int i0);
  public void fbAddVisualizationPlugin(ATerm t0, int i1, String s2);
  public void fbShowRstoreFacts(String s0, int i1, ATerm t2);
  public void showPopup(int i0, ATerm t1);
  public ATerm getSelectedRstoreid();
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
