package toolbus.atom;

import toolbus.TBTerm;

import aterm.ATermList;

/**
 * @author paulk, Aug 3, 2002
 */

public class RecMsg extends CommAtom {
	
	public RecMsg(ATermList args){
		super(args);
	}
	
	public RecMsg(){
		super();
	}
	
	public boolean canCommunicate(Atom a){
		return a instanceof SndMsg && TBTerm.mightMatch(getArgs(), a.getArgs());
	}
}

