package toolbus.tifs;

import java.util.*;

import aterm.*;

abstract public class Communication {
  private ATermAppl representation;
  private List argumentList;

  public Communication(ATerm t) {
    setRepresentation(t);
    initArgumentList();
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

  public String getResultType() {
    return "void";
  }

  public Iterator fetchArgumentIterator() {
    return argumentList.iterator();
  }

  private void initArgumentList() {
    argumentList = new LinkedList();
    ATermAppl args = (ATermAppl) representation.getArgument(0);
    int arity = args.getArity();
    for (int i = 0; i < arity; i++) {
      ATermAppl arg = (ATermAppl) args.getArgument(i);
      String typeName = arg.getAFun().getName();
      argumentList.add(typeName);
    }
  }

  public static Communication create(ATermAppl appl) {
    AFun fun = appl.getAFun();
    String name = fun.getName();

    // <yuck>
    if (name.equals("eval")) {
      return new Eval(appl);
    } else if (name.equals("do")) {
      return new Do(appl);
    } else if (name.equals("event")) {
      return new Event(appl);
    }
    // </yuck>

    throw new RuntimeException("illegal communication construct: " + name);
  }

}
