package toolbus.atom;
/**
 * @author paulk, Jul 24, 2002
 */


public class Delta extends Atom {
	
	public Delta(){
		super();
	}

	public AtomSet getFirst(){
		return new AtomSet();		// replace by single copy
	}
	
     public boolean isEnabled(){
     	return false;
     }
}
