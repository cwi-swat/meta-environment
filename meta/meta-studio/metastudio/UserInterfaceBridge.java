// Java tool bridge UserInterfaceBridge
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 12:03:25 PM

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
  //{{{  public void showListChoice(String s0, String s1, ATerm t2)

  public void showListChoice(String s0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.showListChoice(s0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `showListChoice' not supported.");
    }
  }

  //}}}
  //{{{  public void addEvents(ATerm t0, String s1, ATerm t2)

  public void addEvents(ATerm t0, String s1, ATerm t2)
  {
    if (tool != null) {
      tool.addEvents(t0, s1, t2);
    }
    else {
      throw new UnsupportedOperationException("method `addEvents' not supported.");
    }
  }

  //}}}
  //{{{  public void addEvents(ATerm t0, ATerm t1)

  public void addEvents(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.addEvents(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `addEvents' not supported.");
    }
  }

  //}}}
  //{{{  public void renderGraph(String s0, ATerm t1)

  public void renderGraph(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.renderGraph(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `renderGraph' not supported.");
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
  //{{{  public void displayTreelist(String s0, ATerm t1)

  public void displayTreelist(String s0, ATerm t1)
  {
    if (tool != null) {
      tool.displayTreelist(s0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `displayTreelist' not supported.");
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
