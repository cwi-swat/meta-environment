package toolbus.tifs;

import java.util.*;

import aterm.*;

public class Eval extends Communication {
  public Eval(ATerm t) {
    super(t);
  }

  public String getResultType() {
    ATermAppl resultTerm = (ATermAppl) getRepresentation().getArgument(1);
    return resultTerm.getAFun().getName();
  }

  public String toString() {
    StringBuffer buf = new StringBuffer();
    buf.append("eval(");
    buf.append(getName());
    Iterator iter = fetchArgumentIterator();
    if (iter.hasNext()) {
      buf.append('(');
      while (iter.hasNext()) {
        buf.append((String) iter.next());
        if (iter.hasNext()) {
          buf.append(',');
        }
      }
      buf.append(')');
    }
    buf.append(',');
    buf.append(getResultType());
    buf.append(')');
    return buf.toString();
  }
}
