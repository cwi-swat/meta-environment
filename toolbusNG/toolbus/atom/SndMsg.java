/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import toolbus.TBTerm;

import aterm.ATermList;

public class SndMsg extends CommAtom {
	
	public SndMsg(ATermList args){
		super(args);
	}
	
	public SndMsg(){
		super();
	}
	
	public boolean canCommunicate(Atom a){
		return a instanceof  RecMsg && TBTerm.mightMatch(getArgs(), a.getArgs());
	}
}