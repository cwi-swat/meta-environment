package toolbus.tifs;

import java.util.*;

import aterm.*;

public class Process {
  private ATermAppl representation;
  private CommunicationList communicationList;

  public Process(ATerm t) {
    setRepresentation(t);
    initCommunicationList();
  }
  
  private void setRepresentation(ATerm t) {
    this.representation = (ATermAppl) t;
  }

  private void initCommunicationList() {
    ATermList list = (ATermList) representation.getArgument(1);
    communicationList = new CommunicationList(list);
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
