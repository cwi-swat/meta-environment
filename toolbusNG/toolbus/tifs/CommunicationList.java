package toolbus.tifs;

import java.util.LinkedList;

import aterm.ATermAppl;
import aterm.ATermList;

public class CommunicationList extends LinkedList {

  public CommunicationList(ATermList representation) {
    initCommunicationList(representation);
  }

  private void initCommunicationList(ATermList representation) {
    ATermList iter = representation;
    while (!iter.isEmpty()) {
      addElement(Communication.create((ATermAppl) iter.getFirst()));
      iter = iter.getNext();
    }
  }
}
