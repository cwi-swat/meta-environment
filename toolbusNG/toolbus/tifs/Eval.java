package toolbus.tifs;

import aterm.*;

public class Eval extends Communication {
  private ATermAppl representation;
    
  public Eval(ATerm t) {
    setRepresentation(t);
  }
  
  private void setRepresentation(ATerm t) {
    this.representation = (ATermAppl) t;
  }
  
  public String getResultType() {
    ATermAppl resultTerm = (ATermAppl) representation.getArgument(1);
    return resultTerm.getAFun().getName();
  }

  public String toString() {
    return "eval(...," + getResultType() + ")";
  }
}
