package nl.dancingbear.visbase.factbrowser;

// Java tool interface FactbrowserTif
// This file is generated automatically, please do not edit!
// generation time: Mar 13, 2007 3:53:39 PM


import aterm.*;

public interface FactbrowserTif
{
  public void fbRstoreUnloaded(int i0);
  public void fbAddVisualizationPlugin(ATerm t0, int i1, String s2);
  public void fbShowRstoreFacts(String s0, int i1, ATerm t2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
