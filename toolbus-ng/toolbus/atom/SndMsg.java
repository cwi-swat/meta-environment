/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import aterm.*;
import toolbus.process.*;
import toolbus.*;

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