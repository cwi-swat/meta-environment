/**
 * @author paulk
 */
package toolbus.atom;
import toolbus.Environment;
import toolbus.TBTerm;
import toolbus.ToolBusException;

import aterm.ATermList;

public class Print extends Atom {

  public Print(ATermList args) {
    super(args);
  }

  public Print() {
    super();
  }

  public boolean execute() throws ToolBusException {
    if (super.execute()) {
      Environment e = getEnv();
      //System.out.println("Print, env is: " + e);
      ATermList args = getArgs();
      for (int i = 0; i < args.getLength(); i++) {
        System.out.print(TBTerm.eval(args.elementAt(i), e));
      }
      System.out.println("");
      return true;
    } else {
      return false;
    }
  }
}
