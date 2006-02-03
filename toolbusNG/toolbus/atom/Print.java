/**
 * @author paulk
 */
package toolbus.atom;
import java.io.PrintWriter;

import toolbus.Environment;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Print extends Atom {
  private Ref arg;

  public Print(ATerm a, TBTermFactory tbfactory) {
    super(tbfactory);
    arg = new Ref(a);
    setAtomArgs(arg);
  }
  
  public ProcessExpression copy(){
    Atom a = new Print(arg.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
  private String sprintf(ATermList args){
  	if(args.getLength() == 0)
  		new ToolBusException("missing arguments");
  	if(tbfactory.isStr(args.elementAt(0)))
  			new ToolBusException("first argument should be a string");
  	String fmt = ((ATermAppl) args.elementAt(0)).getName();
  	String res = new String();
  	int iarg = 1;
  	for(int i = 0; i < fmt.length(); i++){
  		char c = fmt.charAt(i);
  		if(c != '%'){
  			if(c != '\\'){
  				res += c;
  				continue;
  			} else {
  				if(i == fmt.length())
  		  			new ToolBusException("format string too short");
  		  		i++;
  		  		char d = fmt.charAt(i);
  		  		if(d == 'n') 
  		  			res += "\n";
  		  		else if(d == 't')
  		  			res += "\t";
  		  		else
  		  			res += d;
  		  		continue;
  			}
  		}
  		if(i == fmt.length())
  			new ToolBusException("format string too short");
  		i++;
  		char d = fmt.charAt(i);
 		if(iarg == args.getLength())
  			new ToolBusException("argument list too short");	
  		res += args.elementAt(iarg++);
  	}
	if(iarg < args.getLength())
			new ToolBusException("argument list too long");	
  	return res;
  }

  public boolean execute() throws ToolBusException {
    if (isEnabled()) {
      Environment e = getEnv();
      //System.err.println("Print: " + this + "; env = " + e);
      PrintWriter out = getToolBus().getPrintWriter();
      ATerm res = tbfactory.substitute(arg.value, e);
      //System.err.println("res =" + res);
      out.print(sprintf((ATermList) res));
      out.flush();
      return true;
    }
    return false;
  }
}
