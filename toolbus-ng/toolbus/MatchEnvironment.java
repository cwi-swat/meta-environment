/**
 * @author paulk, Jul 21, 2002
 */

package toolbus;
import java.util.Vector;

import aterm.ATerm;


public class MatchEnvironment {
	private Vector dict;
	
	public MatchEnvironment(){
			dict = new Vector();
	}
	
	public boolean putResVar(ATerm rvar, ATerm val) {
		ATerm var1 = TBTerm.changeResVarIntoVar(rvar);
		for(int i = 0; i < dict.size(); i += 2){
			ATerm var2 = (ATerm) dict.elementAt(i);
			if(var2.equals(var1))
				return val.equals((ATerm) dict.elementAt(i+1));
		}
		dict.add(var1);
		dict.add(val);
		return true;
	}	
	
	public void update(Environment env) {
		for(int i = 0; i < dict.size(); i += 2){
			ATerm var = (ATerm) dict.elementAt(i);
			ATerm val =(ATerm) dict.elementAt(i+1);
			env.putVar(var, val);
		}
	}
}
	