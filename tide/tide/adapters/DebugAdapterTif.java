// Java tool interface DebugAdapterTif
// This file is generated automatically, please do not edit!
// generation time: Oct 6, 2004 8:54:49 AM

package tide.adapters;

import aterm.*;

public interface DebugAdapterTif
{
  public ATerm modifyRule(int i0, int i1, ATerm t2, ATerm t3, ATerm t4, ATerm t5);
  public ATerm disableRule(int i0, int i1);
  public ATerm enableRule(int i0, int i1);
  public ATerm deleteRule(int i0, int i1);
  public ATerm createRule(int i0, ATerm t1, ATerm t2, ATerm t3, ATerm t4, ATerm t5);
  public ATerm evaluate(int i0, ATerm t1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
