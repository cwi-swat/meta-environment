/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import java.util.Vector;

import toolbus.MatchResult;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;

import aterm.ATermList;

class CommAtom extends Atom {
	private AtomSet partners;	// communication partners in other processes
	
	public CommAtom(ATermList args){
		super(args);
		//System.out.println("constructed: " + this);
		partners = new AtomSet();
	}
	
	public CommAtom(){
		super();
		partners = new AtomSet();
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
	
	public boolean execute() throws ToolBusException
	{
		if(!isEnabled())
				return false;
		Vector partnervec = partners.getAtomsAsVector();
		int psize = partnervec.size();
			//System.out.println("psize = " + psize);
			
		if (psize > 0) {
			ProcessInstance pa = getProcess();
			for (int pindex = rand.nextInt(psize), pleft = psize; pleft > 0; pindex = (pindex + 1) % psize,pleft--) {
				Atom b = (Atom) partnervec.elementAt(pindex);
				ProcessInstance pb = b.getProcess();
				if (pb.prefixContains(b) && b.isEnabled()){
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
						pb.follow(b);
						return true;
					}
				}
			}
		}
		return false;
	}
}


