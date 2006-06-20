// Java tool interface GraphPainterTif
// This file is generated automatically, please do not edit!
// generation time: Jun 20, 2006 12:59:46 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface GraphPainterTif
{
  public void displayGraph(String s0, ATerm t1, ATerm t2);
  public void selectNode(String s0, ATerm t1, ATerm t2);
  public void showPopup(String s0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm createPanel(String s0, ATerm t1, ATerm t2, ATerm t3);
  public ATerm sizeGraph(String s0, ATerm t1, ATerm t2);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
