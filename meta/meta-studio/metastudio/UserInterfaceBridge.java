// Java tool bridge UserInterfaceBridge
// This file is generated automatically, please do not edit!
// generation time: Feb 18, 2003 10:59:31 AM

package metastudio;

import aterm.*;

public class UserInterfaceBridge
  extends UserInterfaceTool
{
  private UserInterfaceTif tool;

  //{{{  public UserInterfaceBridge(ATermFactory factory, UserInterfaceTif tool)

  public UserInterfaceBridge(ATermFactory factory, UserInterfaceTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void addStatus(ATerm t0, String s1)

  public void addStatus(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.addStatus(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `addStatus' not supported.");
    }
  }

  //}}}
  //{{{  public void finishedOpeningModules(ATerm t0)

  public void finishedOpeningModules(ATerm t0)
  {
    if (tool != null) {
      tool.finishedOpeningModules(t0);
    }
    else {
      throw new UnsupportedOperationException("method `finishedOpeningModules' not supported.");
    }
  }

  //}}}
  //{{{  public void moduleInfo(String s0, ATerm t1)

  public void moduleInfo(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.moduleInfo(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `moduleInfo' not supported.");
    }
  }

  //}}}
  //{{{  public void addStatusf(ATerm t0, String s1, ATerm t2)

  public void addStatusf(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.addStatusf(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `addStatusf' not supported.");
    }
  }

  //}}}
  //{{{  public void errorf(String s0, ATerm t1)

  public void errorf(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.errorf(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `errorf' not supported.");
    }
  }

  //}}}
  //{{{  public void graphLayouted(String s0, ATerm t1)

  public void graphLayouted(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.graphLayouted(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `graphLayouted' not supported.");
    }
  }

  //}}}
  //{{{  public void initializeUi(String s0, String s1, String s2, String s3, String s4)

  public void initializeUi(String s0, String s1, String s2, String s3, String s4)
  {
    if (tool != null) {
      tool.initializeUi(s0, s1, s2, s3, s4);
    }
    else {
      throw new UnsupportedOperationException("method `initializeUi' not supported.");
    }
  }

  //}}}
  //{{{  public void deleteModules(ATerm t0)

  public void deleteModules(ATerm t0)
  {
    if (tool != null) {
      tool.deleteModules(t0);
    }
    else {
      throw new UnsupportedOperationException("method `deleteModules' not supported.");
    }
  }

  //}}}
  //{{{  public void error(String s0)

  public void error(String s0)
  {
    if (tool != null) {
      tool.error(s0);
    }
    else {
      throw new UnsupportedOperationException("method `error' not supported.");
    }
  }

  //}}}
  //{{{  public void displayGraph(String s0, ATerm t1)

  public void displayGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void newGraph(ATerm t0, ATerm t1)

  public void newGraph(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.newGraph(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `newGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void endStatus(ATerm t0)

  public void endStatus(ATerm t0)
  {
    if (tool != null) {
      tool.endStatus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `endStatus' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
