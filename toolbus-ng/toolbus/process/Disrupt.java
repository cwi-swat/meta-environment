package toolbus.process;

import java.util.Stack;
import java.util.Vector;

import aterm.ATerm;

import toolbus.AtomSet;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;

public class Disrupt extends ProcessExpression {
  private ProcessExpression left, right;

  public Disrupt(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, ATerm posInfo) {
	super(tbfactory, posInfo);
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Disrupt(left, right, tbfactory, getPosInfo());
  }

 // public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
 //   left.expand(P, calls);
 //   right.expand(P, calls);
 //   setFirst(left.getFirst().union(right.getFirst()));
 // }
  
  public void computeFirst(){
 	 left.computeFirst();
 	 right.computeFirst();
 	 setFirst(left.getFirst().union(right.getFirst()));
 }
  
  public void replaceFormals(Environment env) throws ToolBusException{
		left.replaceFormals(env);
		right.replaceFormals(env);
	  }

  public void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException {
    left.compile(P, calls, follow);
    right.compile(P, calls, follow);
    State rightFirst = right.getFirst();
    setFollow(follow);
   // Vector atoms = left.getAtoms().getElementsAsVector();
   // for (int i = 0; i < atoms.size(); i++) {
   //   Atom at = (Atom) atoms.get(i);
      
    for(Atom at : left.getAtoms().getSet())
      if (at.getFollow().size() != 0) {
        at.addToFollow(rightFirst);
      }
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }
}
