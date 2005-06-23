/**
 * @author paulk
 */
package toolbus.atom;
import java.io.*;

import toolbus.*;
import toolbus.process.ProcessExpression;
import aterm.*;

public class Print extends Atom {
  private Ref arg;

  public Print(ATerm a) {
    super();
    arg = new Ref(a);
    setAtomArgs(arg);
  }
  
  public ProcessExpression copy(){
    return new Print(arg.value);
  }

  public boolean execute() throws ToolBusException {
    if (isEnabled()) {
      Environment e = getEnv();
      //System.err.println("Print: " + this);
      PrintWriter out = getToolBus().getPrintWriter();
      ATerm res = TBTerm.substitute(arg.value, e);
      //System.err.println("res =" + res);
      if(res.getType() == ATerm.LIST){
	      for (int i = 0; i < ((ATermList) res).getLength(); i++) {
	        out.print( ((ATermList) res).elementAt(i).toString() );
	      }
      } else
      	  out.print(res.toString());
      out.println();
      out.flush();
      return nextState();
    } else {
      return false;
    }
  }
}
