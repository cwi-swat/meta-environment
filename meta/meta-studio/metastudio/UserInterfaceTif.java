// Java tool interface UserInterfaceTif
// This file is generated automatically, please do not edit!
// generation time: Oct 15, 2002 7:08:22 PM

package metastudio;

import aterm.*;
import toolbus.*;

public interface UserInterfaceTif
{
  public void addStatus(ATerm t0, String s1);
  public void finishedOpeningModules(ATerm t0);
  public void moduleInfo(String s0, ATerm t1);
  public void addStatusf(ATerm t0, String s1, ATerm t2);
  public void errorf(String s0, ATerm t1);
  public void graphLayouted(ATerm t0);
  public void initializeUi(String s0, String s1, String s2, String s3, String s4);
  public void deleteModules(ATerm t0);
  public void error(String s0);
  public void newGraph(ATerm t0, ATerm t1);
  public void endStatus(ATerm t0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
