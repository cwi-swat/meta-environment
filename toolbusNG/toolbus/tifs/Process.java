package toolbus.tifs;

import java.util.*;

import aterm.*;

public class Process {
  private ATermAppl representation;
  private List communicationList;

  public Process(ATerm t) {
    setRepresentation(t);
  }

  private void setRepresentation(ATerm t) {
    this.representation = (ATermAppl) t;
  }

  private void initCommunicationList() {
    communicationList = new LinkedList();
    ATermList iter = (ATermList) representation.getArgument(1);
    while (!iter.isEmpty()) {
      Communication comm = null;
      ATermAppl appl = (ATermAppl) iter.getFirst();
      AFun fun = appl.getAFun();
      String name = fun.getName();
      if (name.equals("eval")) {
        comm = new Eval(appl);
      }
      if (comm != null) {
        communicationList.add(comm);
      }
      iter = iter.getNext();
    }
  }

  public String getName() {
    ATermAppl nameTerm = (ATermAppl) representation.getArgument(0);
    return ((ATermAppl) nameTerm.getArgument(0)).getAFun().getName();
  }

  public Iterator fetchCommunicationIterator() {
    if (communicationList == null) {
      initCommunicationList();
    }

    return communicationList.iterator();
  }

  public String toString() {
    StringBuffer buf = new StringBuffer();
    buf.append("process(");
    buf.append("name(");
    buf.append(getName());
    buf.append(')');
    buf.append(',');
    buf.append('[');
    Iterator iter = fetchCommunicationIterator();
    while (iter.hasNext()) {
      buf.append((Communication) iter.next());
      if (iter.hasNext()) {
        buf.append(',');
      }
    }
    buf.append(']');
    buf.append(')');
    return buf.toString();
  }
}
