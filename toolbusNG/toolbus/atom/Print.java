/**
 * @author paulk
 */
package toolbus.atom;
import toolbus.*;
import toolbus.process.ProcessExpression;

import aterm.*;
import aterm.ATermList;

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
      //System.out.println("Print, env is: " + e);
      ATermList args = (ATermList) arg.value;
      for (int i = 0; i < args.getLength(); i++) {
        System.out.print(TBTerm.eval(args.elementAt(i), e));
      }
      System.out.println("");
      return nextState();
    } else {
      return false;
    }
  }
}
