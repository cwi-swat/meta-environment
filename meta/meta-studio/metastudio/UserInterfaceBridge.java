// Java tool bridge UserInterfaceBridge
// This file is generated automatically, please do not edit!
// generation time: Jul 3, 2003 11:55:48 AM

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
  //{{{  public void initializeUi(String s0)

  public void initializeUi(String s0)
  {
    if (tool != null) {
      tool.initializeUi(s0);
    }
    else {
      throw new UnsupportedOperationException("method `initializeUi' not supported.");
    }
  }

  //}}}
  //{{{  public void buttonsFound(String s0, String s1, ATerm t2)

  public void buttonsFound(String s0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.buttonsFound(s0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `buttonsFound' not supported.");
    }
  }

  //}}}
  //{{{  public void clearHistory()

  public void clearHistory()
  {
    if (tool != null) {
      tool.clearHistory();
    }
    else {
      throw new UnsupportedOperationException("method `clearHistory' not supported.");
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
  //{{{  public void newGraph(ATerm t0)

  public void newGraph(ATerm t0)
  {
    if (tool != null) {
      tool.newGraph(t0);
    }
    else {
      throw new UnsupportedOperationException("method `newGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void updateList(String s0, String s1)

  public void updateList(String s0, String s1)
  {
    if (tool != null) {
      tool.updateList(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `updateList' not supported.");
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
  //{{{  public ATerm deconsFilename(String s0, String s1)

  public ATerm deconsFilename(String s0, String s1)
  {
    if (tool != null) {
      return tool.deconsFilename(s0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `deconsFilename' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm showQuestionDialog(String s0)

  public ATerm showQuestionDialog(String s0)
  {
    if (tool != null) {
      return tool.showQuestionDialog(s0);
    }
    else {
      throw new UnsupportedOperationException("method `showQuestionDialog' not supported.");
    }
  }

  //}}}
  //{{{  public ATerm showFileDialog(String s0, String s1, String s2)

  public ATerm showFileDialog(String s0, String s1, String s2)
  {
    if (tool != null) {
      return tool.showFileDialog(s0, s1, s2);
    }
    else {
      throw new UnsupportedOperationException("method `showFileDialog' not supported.");
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
