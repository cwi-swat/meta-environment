/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import java.util.*;

import aterm.ATerm;

import toolbus.*;
import toolbus.process.*;
import toolbus.process.ProcessInstance;

abstract class MsgAtom extends Atom {

  protected static Random rand = new Random();

  private State partners = new State(); // communication partners in other processes
  private Ref msg;

  public MsgAtom(ATerm msg) {
    super();
    this.msg = new Ref(msg);
    setAtomArgs(this.msg);
  }

  public ATerm getMsg() {
    return msg.value;
  }

 public boolean canCommunicate(MsgAtom a) {
    return ((this instanceof SndMsg && a instanceof RecMsg) ||
              (this instanceof RecMsg && a instanceof SndMsg)) &&  
             TBTerm.mightMatch(getMsg(), a.getMsg());
  }
  
  public void addMsgPartner(StateElement a) {
    System.out.println(this + " addMsgPartner " +  a);
    partners.add(a);
  }

  public State getMsgPartners() {
    return partners;
  }

  public boolean hasMsgPartners() {
    return partners.size() > 0;
  }

  public MatchResult matchArgs(MsgAtom b) throws ToolBusException {
    return TBTerm.match(msg.value, getEnv(), b.getMsg(), b.getEnv());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    Vector partnervec = partners.getElementsAsVector();
    int psize = partnervec.size();
    //System.out.println("psize = " + psize);

    if (psize > 0) {
      ProcessInstance pa = getProcess();
      for (int pindex = rand.nextInt(psize), pleft = psize; pleft > 0; pindex = (pindex + 1) % psize, pleft--) {
        MsgAtom b = (MsgAtom) partnervec.elementAt(pindex);
        ProcessInstance pb = b.getProcess();
        if (pb.contains(b) && b.isEnabled()) {
          MatchResult r = matchArgs(b);
          if (r.matches()) {
            System.out.println(
              "--- " + pa.getProcessId() + "/" + pb.getProcessId() + ": " + this +" communicates with " + b);
            r.getLeft().update(pa.getEnv());
            r.getRight().update(pb.getEnv());

            // this.nextState() is done by AtomSet.execute
            b.nextState();
            return true;
          }
        }
      }
    }
    return false;
  }
}
