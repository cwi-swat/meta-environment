/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import java.util.*;

import aterm.ATerm;

import toolbus.*;
import toolbus.process.ProcessInstance;

abstract class CommAtom extends Atom {
  
  protected static Random rand = new Random();

  private AtomSet partners = new AtomSet(); // communication partners in other processes
  private Ref msg;

   public CommAtom(ATerm msg){
    super();
    this.msg = new Ref(msg);
    setAtomArgs(this.msg);
   }
   
   public ATerm getMsg(){
    return msg.value;
   }

  public void addPartner(Atom a) {
    partners.add(a);
  }

  public AtomSet getPartners() {
    return partners;
  }

  public boolean hasPartners() {
    return partners.size() > 0;
  }
  
  public MatchResult matchArgs(CommAtom b) throws ToolBusException {
      return TBTerm.match(msg.value, getEnv(), b.getMsg(), b.getEnv());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    Vector partnervec = partners.getAtomsAsVector();
    int psize = partnervec.size();
    //System.out.println("psize = " + psize);

    if (psize > 0) {
      ProcessInstance pa = getProcess();
      for (int pindex = rand.nextInt(psize), pleft = psize; pleft > 0; pindex = (pindex + 1) % psize, pleft--) {
        CommAtom b = (CommAtom) partnervec.elementAt(pindex);
        ProcessInstance pb = b.getProcess();
        if (pb.contains(b) && b.isEnabled()) {
          MatchResult r = matchArgs(b);
          if (r.matches()) {
            //								System.out.println(
            //									"--- " +
            //									pa.getProcessId()
            //										+ "/"
            //										+ pb.getProcessId()
            //										+ ": "
            //										+ this
            //										+ " communicates with "
            //										+ b);
            r.getLeft().update(pa.getEnv());
            r.getRight().update(pb.getEnv());

            // pa.follow(this) is done by AtomSet.execute
            pb.nestState(b);
            return true;
          }
        }
      }
    }
    return false;
  }
}
