package toolbus.tifs;

import java.io.IOException;
import java.util.*;

import aterm.*;

public class Tif {
  private ATermAppl representation;
  private List processList;

  public Tif(ATerm t) {
    setRepresentation(t);
  }
  
  private void setRepresentation(ATerm t) {
    representation = (ATermAppl) t;
  }

  public int getVersion() {
    ATermAppl versionTerm = (ATermAppl) representation.getArgument(0);
    return ((ATermInt) versionTerm.getArgument(0)).getInt();
  }

  public String getPackageName() {
    ATermAppl pkgTerm = (ATermAppl) representation.getArgument(1);
    return ((ATermAppl) pkgTerm.getArgument(0)).getAFun().getName();
  }

  public String getToolName() {
    ATermAppl toolTerm = (ATermAppl) representation.getArgument(2);
    return ((ATermAppl) toolTerm.getArgument(0)).getAFun().getName();
  }

  private void initProcessList() {
    processList = new LinkedList();
    ATermList iter = (ATermList) representation.getArgument(3);
    while (!iter.isEmpty()) {
      processList.add(new Process(iter.getFirst()));
      iter = iter.getNext();
    }
  }

  public Iterator fetchProcessIterator() {
    if (processList == null) {
      initProcessList();
    }

    return processList.iterator();
  }
  
  public String toString() {
    StringBuffer buf = new StringBuffer();
    buf.append("tifs");
    buf.append('(');
    buf.append("version");
    buf.append('(');
    buf.append(getVersion());
    buf.append(')');
    buf.append(',');
    buf.append("package");
    buf.append('(');
    buf.append('"');
    buf.append(getPackageName());
    buf.append('"');
    buf.append(')');
    buf.append(',');
    buf.append("tool");
    buf.append('(');
    buf.append('"');
    buf.append(getToolName());
    buf.append('"');
    buf.append(')');
    buf.append(',');
    buf.append('[');
    Iterator iter = fetchProcessIterator();
    while (iter.hasNext()) {
      Process process = (Process)iter.next();
      buf.append(process);
      if (iter.hasNext()) {
        buf.append(',');
      }
    }
    buf.append(']');
    buf.append(')');

    return buf.toString();
  }

  public static void main(String[] args) {
    ATermFactory factory = new aterm.pure.PureFactory();
    ATerm tifsTerm = null;
    String fileName = args[0];
    try {
      tifsTerm = factory.readFromFile(fileName);
    } catch (IOException e) {
      System.err.println("Error reading " + fileName + ": " + e);
    }
    Tif tif = new Tif(tifsTerm);
    System.out.println("tif read: ");
    System.out.println(tif);
  }
}