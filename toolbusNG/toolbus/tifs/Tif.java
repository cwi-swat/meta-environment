package toolbus.tifs;

import java.util.*;

public class Tif {
  private int version;
  private String packageName;
  private String toolName;
  private List processList;
  
  public Tif() {
    processList = new LinkedList();
  }
  
  public String getPackageName() {
    return packageName;
  }

  public String getToolName() {
    return toolName;
  }

  public int getVersion() {
    return version;
  }

  public void setPackageName(String packageName) {
    this.packageName = packageName;
  }

  public void setToolName(String toolName) {
    this.toolName = toolName;
  }

  public void setVersion(int version) {
    this.version = version;
  }
  
  public void addProcess(Process process) {
    processList.add(process);
  }
  
  public Iterator fetchProcessIterator() {
    return processList.iterator();
  }
}