package org.autocode.bootstrap.generator.repository;

import java.util.*;
import java.io.*;

public class MethodBody
{
  private List _lineList;

  //{{{ public MethodBody()

  public MethodBody()
  {
    _lineList = new LinkedList();
  }

  //}}}
  //{{{ public MethodBody(String line)

  public MethodBody(String line)
  {
    this();
    addLine(line);
  }

  //}}}

  //{{{ public void addLine(String line)

  public void addLine(String line)
  {
    _lineList.add(line);
  }

  //}}}
  //{{{ public Iterator fetchLineIterator()

  public Iterator fetchLineIterator()
  {
    return _lineList.iterator();
  }

  //}}}

  //{{{ public void emit(int indentLevel, PrintWriter printer)

  public void emit(int indentLevel, PrintWriter printer)
  {
    Iterator lines = fetchLineIterator();
    while (lines.hasNext()) {
      for (int i=0; i<indentLevel; i++) {
	printer.print("  ");
      }
      printer.println(lines.next().toString());
    }
  }

  //}}}
}
