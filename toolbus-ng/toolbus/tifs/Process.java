package toolbus.tifs;

import java.util.*;

public class Process {
  private String name;
  private List communicationList;
  
  public Process() {
    communicationList = new LinkedList();
  }
  
  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }
  
  public void addSignature(Communication communication) {
    communicationList.add(communication);
  }
}
