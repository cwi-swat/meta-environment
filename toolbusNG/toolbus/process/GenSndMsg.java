package toolbus.process;

import java.util.Stack;

import toolbus.ToolBusException;
import toolbus.atom.State;

import aterm.ATerm;

public class GenSndMsg extends AbstractProcessExpression {
  private ATerm msg; // The message to send/receive
  private boolean inPair = false; // part of a send/receive pair (or not)
  private boolean open = false; // the opening action
  private boolean inTool = false; // the closing action

  public GenSndMsg(ATerm msg) {
    this.msg = msg;
  }

  public GenSndMsg(ATerm msg, boolean inPair, boolean open, boolean inTool) {
    this.msg = msg;
    this.inPair = inPair;
    this.open = open;
    this.inTool = inTool;
  }

  public ProcessExpression copy() {
    return new GenSndMsg(msg, inPair, open, inTool);
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {

  }

  public void compile(ProcessInstance P, State follows) throws ToolBusException {
    //    PE.compile(P, follows);
    //    setFollow(PE.getFollow());
  }

  public State getAtoms() {
    //    return PE.getAtoms();
    return null;
  }

  public String toString() {
    return "GenSndMsg";
  }
}
