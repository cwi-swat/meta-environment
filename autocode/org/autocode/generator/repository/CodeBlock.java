package org.autocode.generator.repository;

import java.util.*;
import java.io.*;

public class CodeBlock
{
  private List _lineList;

  //{{{ public CodeBlock()

  public CodeBlock()
  {
    _lineList = new LinkedList();
  }

  //}}}
  //{{{ public CodeBlock(String line)

  public CodeBlock(String line)
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
