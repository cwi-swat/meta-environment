/**
 * @author paulk
 */
package toolbus.atom;

import java.io.PrintWriter;

import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusExecutionException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Print extends Atom{
	private final Ref arg;
	
	public Print(ATerm a, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		arg = new Ref(a);
		setAtomArgs(new Ref[]{arg});
	}
	
	public ProcessExpression copy(){
		Atom a = new Print(arg.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	private String sprintf(ATermList args){
		if(args.getLength() == 0) new ToolBusExecutionException("Missing arguments.", getPosInfo());
		if(tbfactory.isStr(args.elementAt(0))) new ToolBusExecutionException("First argument should be a string.", getPosInfo());
		String fmt = ((ATermAppl) args.elementAt(0)).getName();
		String res = new String();
		int iarg = 1;
		for(int i = 0; i < fmt.length(); i++){
			char c = fmt.charAt(i);
			if(c != '%'){
				if(c != '\\'){
					res += c;
					continue;
				}
				
				if(i == fmt.length()) new ToolBusExecutionException("Format string too short.", getPosInfo());
				i++;
				char d = fmt.charAt(i);
				if(d == 'n')
					res += "\n";
				else if(d == 't')
					res += "\t";
				else res += d;
				continue;
			}
			if(i == fmt.length()) new ToolBusExecutionException("Format string too short.", getPosInfo());
			i++;
			
			if(iarg == args.getLength()) new ToolBusExecutionException("Argument list too short.", getPosInfo());
			res += args.elementAt(iarg++);
		}
		if(iarg < args.getLength()) new ToolBusExecutionException("Argument list too long.", getPosInfo());
		return res;
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			Environment e = getEnv();
			// System.err.println("Print.execute: " + this + "; env = " + e);
			PrintWriter out = getToolBus().getPrintWriter();
			ATerm res = tbfactory.fullSubstitute(arg.value, e);
			if(res == null) throw new ToolBusExecutionException("Illegal printf pattern: "+arg.value+".", getPosInfo());
			// System.err.println("res =" + res);
			out.print(sprintf((ATermList) res));
			out.flush();
			return true;
		}
		return false;
	}
}
