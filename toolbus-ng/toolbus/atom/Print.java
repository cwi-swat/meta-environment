/**
 * @author paulk
 */
package toolbus.atom;
import aterm.*;
import toolbus.process.*;
import toolbus.*;

public class Print extends Atom {

	public Print(ATermList args) {
		super(args);
	}
	
	public Print(){
		super();
	}

	public boolean execute()
	throws ToolBusException
	 {
	 	if(!isEnabled())
	 		return false;
		Environment e = this.getEnv();
		//System.out.println("Print, env is: " + e);
		ATermList args = this.getArgs();
		for (int i = 0; i < args.getLength(); i++) {
			System.out.print(TBTerm.eval(args.elementAt(i), e));
		}
		System.out.println("");
		return true;
	}
}
