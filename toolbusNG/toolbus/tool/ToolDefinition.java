package toolbus.tool;
import java.util.Vector;

import toolbus.*;

import aterm.*;

/**
 * @author paulk
 */
public class ToolDefinition{
	private static int ninstances = 0;
	private String name;
	private String cmd;
	private Vector occurrences;
	
	public ToolDefinition(String name, String cmd){
		this.name = name;
		this.cmd = cmd;
		occurrences = new Vector();
	}

	public String getName() {
		return name;
	}
	
	public void registerOccurrence(String atomname, ATerm pat){
		int nargs = ((ATermList) pat).getLength();
		
		AFun afun = TBTerm.factory.makeAFun(atomname, nargs, false);
		occurrences.add(TBTerm.factory.makeAppl(afun, (ATermList) pat));
	}
	
	private ATermList makeSig(){
		ATermList sig = (ATermList) TBTerm.factory.make("[]");
		for(int i = 0; i < occurrences.size(); i++){
			sig = TBTerm.factory.makeList((ATerm) occurrences.get(i), sig);
		}
		return sig;
	}
	
	public ToolInstance instantiate(ToolBus TB, ATermList args)
	throws ToolBusException
	{
		AFun afun = TBTerm.factory.makeAFun(name, 1, false);
		ATermAppl tid =  TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(ninstances));
		ninstances++;
		return new JavaTool(cmd, tid, new InternalToolBridge(TB), makeSig());
	}
}
