// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 9:44:36 AM

package metastudio;

import aterm.*;

public interface UserInterfaceTif
{
  public void displayGraph(String s0, ATerm t1);
  public void addEvents(ATerm t0, String s1, ATerm t2);
  public void addEvents(ATerm t0, ATerm t1);
  public void initializeUi(String s0);
  public void displayTreelist(String s0, ATerm t1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
