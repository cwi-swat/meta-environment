package toolbus.tifs;

import java.util.*;

import aterm.*;

abstract public class Communication {
  private ATermAppl representation;
  private List argumentList;
  
  public Communication(ATerm t) {
    setRepresentation(t);
  }

  private void setRepresentation(ATerm t) {
    this.representation = (ATermAppl) t;
  }

  protected ATermAppl getRepresentation() {
    return representation;
  }
  
  public String getName() {
    ATermAppl resultTerm = (ATermAppl) representation.getArgument(0);
    return resultTerm.getAFun().getName();
  }

  public Iterator fetchArgumentIterator() {
    if (argumentList == null) {
      initArgumentList();
    }
    return argumentList.iterator();
  }

  private void initArgumentList() {
    argumentList = new LinkedList();
    ATermAppl args = (ATermAppl) representation.getArgument(0);
    int arity = args.getArity();
    for (int i=0; i<arity; i++) {
      ATermAppl arg = (ATermAppl) args.getArgument(i);
      String typeName = arg.getAFun().getName();
      argumentList.add(typeName);
    }
  }
}
