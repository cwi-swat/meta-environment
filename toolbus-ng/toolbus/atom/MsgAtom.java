/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import java.util.Vector;

import toolbus.*;
import toolbus.process.*;

import aterm.*;
import aterm.ATerm;

abstract class MsgAtom extends Atom {

  private State partners = new State(); // communication partners in other processes
  private Ref msg;
  private Ref qual;

  private ATerm matchPattern;

  public MsgAtom(ATerm msg) {
    super();
    this.msg = new Ref(msg);
    this.qual = new Ref(TBTerm.TermPlaceholder);
    setAtomArgs(this.msg, this.qual);
  }

  public MsgAtom(ATerm msg, ATerm qual) {
    super();
    this.msg = new Ref(msg);
    this.qual = new Ref(qual);
    setAtomArgs(this.msg, this.qual);
  }

  public ATerm getMsg() {
    return msg.value;
  }

  public ATerm getQual() {
    return qual.value;
  }
  
  public ATerm getMatchPattern(){
    return matchPattern;
  }

  public boolean canCommunicate(MsgAtom a) {
    return ((this instanceof SndMsg && a instanceof RecMsg) || (this instanceof RecMsg && a instanceof SndMsg))
      && TBTerm.mightMatch(getMsg(), a.getMsg());
  }

  public void addMsgPartner(StateElement a) {
    partners.add(a);
  }

  public State getMsgPartners() {
    return partners;
  }

  public boolean hasMsgPartners() {
    return partners.size() > 0;
  }

  public MatchResult matchPartner(MsgAtom b) throws ToolBusException {
    return TBTerm.match(matchPattern, getEnv(), b.getMatchPattern(), b.getEnv());
  }

  public void compile(ProcessInstance processInstance, State follow) throws ToolBusException {
    super.compile(processInstance, follow);
    ATermFactory factory = getQual().getFactory();
    if (this instanceof SndMsg) {
      matchPattern =
        factory.makeList(getMsg(), factory.makeList(getQual(), factory.makeList(processInstance.getProcessId())));
    } else {
      matchPattern =
        factory.makeList(getMsg(), factory.makeList(processInstance.getProcessId(), factory.makeList(getQual())));
    }
    
    System.out.println(matchPattern);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    Vector partnervec = partners.getElementsAsVector();
    int psize = partnervec.size();
    //System.out.println("psize = " + psize);

    if (psize > 0) {
      ProcessInstance pa = getProcess();
      for (int pindex = ToolBus.nextInt(psize), pleft = psize; pleft > 0; pindex = (pindex + 1) % psize, pleft--) {
        MsgAtom b = (MsgAtom) partnervec.elementAt(pindex);
        ProcessInstance pb = b.getProcess();
        if (pb.contains(b) && b.isEnabled()) {
          MatchResult r = matchPartner(b);
          if (r.matches()) {
            if (ToolBus.isVerbose()) {
              System.out.println(
                "--- " + pa.getProcessId() + "/" + pb.getProcessId() + ": " + this +" communicates with " + b);
            }
            r.getLeft().update(pa.getEnv());
            r.getRight().update(pb.getEnv());

            this.nextState();
            b.nextState();
            return true;
          }
        }
      }
    }
    return false;
  }
}
