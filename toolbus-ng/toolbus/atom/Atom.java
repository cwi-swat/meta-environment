/**
 * @author paulk
 */

package toolbus.atom;

import java.util.Random;

import aterm.*;
import toolbus.*;
import toolbus.process.*;

public class Atom implements ProcessExpression {
  private ATermList args; // arguments of this atom (modified by compile)
  private AtomSet first; // first set, equals {this}
  private AtomSet follow; // follow set
  //private AtomSet partners;	// communication partners in other processes
  private ProcessInstance process; // process instance to which the atom belongs
  private Environment env; // the environment of that process instance
  private ATerm test; // optional test that guards this atom

  protected static Random rand = new Random();

  public Atom() {
    this.args = null;
    first = new AtomSet();
    first.add(this);
    follow = new AtomSet();
    //partners = new AtomSet();
    test = null;
  }

  public Atom(ATermList args) {
    this();
    this.args = args;
    //System.out.println("constructed: " + this);
  }

  public Atom(ATermList args, ATerm arg) {
    this();
    this.args = args.append(arg);
    //System.out.println("constructed: " + this);
  }

  public Atom(ATerm arg1, ATerm arg2) {
    this();
    this.args = TBTerm.factory.makeList(arg1, TBTerm.factory.makeList(arg2));
  }

  public ATermList getArgs() {
    return args;
  }

  public void addArgs(ATermList args) {
    if (this.args != null)
      System.out.println("*** redefining arguments");
    this.args = args;
  }

  public ProcessExpression copy() {
    Atom newAtom;
    try {
      newAtom = (Atom) this.getClass().newInstance();
    } catch (Exception e) {
      throw new ToolBusInternalError(e.getMessage());
    }
    newAtom.addArgs(this.args);
    return newAtom;
  }

  public AtomSet getFirst() {
    return first;
  }

  public AtomSet getFollow() {
    return follow;
  }

  public void extendFollow(AtomSet f) {
    //System.out.println(this + ": extendFollow(" + f + ")");
    //System.out.println("follow was: " + follow);	
    //if(follow.size() == 0)
    follow = follow.union(f);

    //System.out.println("follow becomes: " + follow);
  }

  public Environment getEnv() {
    return env;
  }

  public String toString() {
    int pid = (process == null) ? -1 : process.getProcessId();
    String strtest = (test == null) ? "" : " if " + test;
    return this.getClass().getName() + "[" + pid + "]( " + args + ")" + strtest;
  }

  public AtomSet getAtoms() {
    return first;
  }

  public boolean canCommunicate(Atom a) {
    return false;
  }

  public void addPartner(Atom a) {
    //partners.add(a);
  }

  public AtomSet getPartners() {
    //return partners;
    return null;
  }

  public boolean hasPartners() {
    //return partners.size() > 0;
    return false;
  }

  public void compile(ProcessInstance processInstance, AtomSet follow) throws ToolBusException {
    process = processInstance;
    env = processInstance.getEnv();
    this.follow = follow;
    //System.out.println(this.getClass().getName() + ": compiling " + args);
    if (args != null)
      args = (ATermList) TBTerm.compileVars(args, env);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled()) {
      return false;
    } else {
      return true;
    }
  }

  public ATerm getTest() {
    return test;
  }

  public void setTest(ATerm test) throws ToolBusException {
    this.test = TBTerm.compileVars(test, env);
  }

  public boolean isEnabled() throws ToolBusException {
    if (test == null)
      return true;
    else {
      boolean res = TBTerm.isTrue(TBTerm.eval(test, env));
      //System.out.println(this.getProcess().getProcessId() + ": " + this + " : evaluate: " + test + " ==> " + res);
      return res;
    }
  }

  public ProcessInstance getProcess() {
    return process;
  }

  public MatchResult matchArgs(Atom b) throws ToolBusException {
    if (args.getLength() == 0) {
      if (b.getArgs().getLength() == 0)
        return new MatchResult(true, null, null);
      else
        return new MatchResult(false, null, null);
    } else
      return TBTerm.match(args, env, b.getArgs(), b.getEnv());
  }
}
