package toolbus.process;

import java.lang.reflect.Constructor;
import java.util.*;
import java.util.Stack;

import aterm.*;
import aterm.ATerm;
import toolbus.*;
import toolbus.ToolBusException;
import toolbus.atom.*;

/*
 *  Handle general message pairs of the following form:
 * 
 *    open inbetween operator postlude
 * 
 * open:      SndMsg or RecMsg
 * inbetween: arbitrary process expression
 * operator:  one of the binary process operators (i.e. Sequence, Iteration, Alternative)
 * postlude:  arbitrary process expression whose first set contains either solely SndMsgs or RecMsgs
 *            (depending on the open atom: open=SndMsg -> first set of postlude contains RecMsgs, etc.)
 * 
 */

public class MsgPair extends AbstractProcessExpression implements StateElement {
  private boolean sndThenRec;
  private boolean inTool;
  private ATerm msg;
  private ProcessExpression inbetween;
  private ProcessExpression postlude;
  private String operator;
  private ProcessExpression PE;
  private Atom toolAtom = null;
  
  private ProcessInstance processInstance;

  public MsgPair(
    boolean sndThenRec,
    boolean inTool,
    ATerm msg,
    ProcessExpression inbetween,
    String operator,
    ProcessExpression postlude)
    throws ToolBusException {
    this.sndThenRec = sndThenRec;
    this.inTool = inTool;
    this.msg = msg;
    this.inbetween = inbetween;
    this.postlude = postlude;
    this.operator = operator;

    ProcessExpression prelude;

    if (sndThenRec) {
      if (inTool) {
        prelude = new Sequence(new Event(msg), new SndMsg(msg));
      } else {
        prelude = new SndMsg(msg);
      }
    } else {
      if (inTool) {
        toolAtom = new Eval(msg);
        prelude = new Sequence(new RecMsg(msg), toolAtom);
      } else {
        prelude = new RecMsg(msg);
      }
    }
    Constructor cons;
    try {
      Class cls = Class.forName("toolbus.process." + operator);
      Class pe = Class.forName("toolbus.process.ProcessExpression");

      cons = cls.getConstructor(new Class[] { pe, pe });
    } catch (Exception e) {
      e.printStackTrace();
      throw new ToolBusException("illegal operator");
    }

    ProcessExpression rest = postlude;
    if (inbetween != null) {
      try {
        rest = (ProcessExpression) cons.newInstance(new Object[] { inbetween, postlude });
      } catch (Exception e) {
        throw new ToolBusException("cannot instantiate " + operator);
      }
    }

    PE = new Sequence(prelude, rest);
    System.err.println("prelude   = " + prelude);
    System.err.println("inbetween = " + inbetween);
    System.err.println("postlude  = " + postlude);
    System.err.println("rest      = " + rest);
    System.err.println("PE        = " + PE);
  }

  public ProcessExpression copy() {
    try {
      return new MsgPair(sndThenRec, inTool, msg, inbetween.copy(), operator, postlude.copy());
    } catch (ToolBusException e) {
      throw new ToolBusInternalError("cannot copy SndAndRecMsg");
    }
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    processInstance = P;
    PE.expand(P, calls);
    setFirst(PE.getFirst());
    Vector atoms = postlude.getFirst().getElementsAsVector();
    ATermList atomPatterns = TBTerm.factory.makeList();
    for (int i = 0; i < atoms.size(); i++) {
      Atom atom = (Atom) atoms.elementAt(i);
      if ((sndThenRec && atom instanceof RecMsg) || (!sndThenRec && atom instanceof SndMsg) ){
        atomPatterns = atomPatterns.append(TBTerm.makePattern(atom.getAtomArgValue(0), atom.getEnv(), true));
      } else {
        throw new ToolBusException((sndThenRec) ? "SndMsg" : "RecMsg" + " required, but " + atoms.elementAt(i) + " found");
      }
    }
    if(toolAtom != null){
      toolAtom.addAtomArg(atomPatterns);
    }
    System.err.println(atomPatterns);
  }

  public void compile(ProcessInstance P, State follows) throws ToolBusException {
    PE.compile(P, follows);
    setFollow(PE.getFollow());
  }

  public State getAtoms() {
    return PE.getAtoms();
  }

  public String toString() {
    return "SndAndRecMsg(" + msg + ", " + inbetween + ", " + operator + ", " + postlude + ")";
  }
  
  // Implementation of the StateElement interface

  public boolean contains(StateElement a) {
    return PE.getFirst().contains(a);
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }

  public boolean execute() throws ToolBusException {
    return PE.getFirst().execute();
   
  }
}
