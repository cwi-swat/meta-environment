package toolbus.tifs;

import java.util.*;

import aterm.*;

public class Process {
  private ATermAppl representation;
  private List communicationList;

  public Process(ATerm t) {
    setRepresentation(t);
    initCommunicationList();
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
      // <yuck>
      if (name.equals("eval")) {
        comm = new Eval(appl);
      }
      else if (name.equals("do")) {
        comm = new Do(appl);
      }
      else if (name.equals("event")) {
        comm = new Event(appl);
      }
      if (comm != null) {
        communicationList.add(comm);
      }
      // </yuck>
      iter = iter.getNext();
    }
  }

  public String getName() {
    ATermAppl nameTerm = (ATermAppl) representation.getArgument(0);
    return ((ATermAppl) nameTerm.getArgument(0)).getAFun().getName();
  }

  public Iterator fetchCommunicationIterator() {
    return communicationList.iterator();
  }

  public String toString() {
    StringBuffer buf = new StringBuffer();
    buf.append("process(");
    buf.append("name(");
    buf.append('"');
    buf.append(getName());
    buf.append('"');
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
