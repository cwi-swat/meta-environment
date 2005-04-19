// Java tool interface GraphPainterTif
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2005 2:11:05 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface GraphPainterTif
{
  public void displayGraph(String s0, ATerm t1);
  public void selectNode(String s0, String s1);
  public ATerm sizeGraph(String s0, ATerm t1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
