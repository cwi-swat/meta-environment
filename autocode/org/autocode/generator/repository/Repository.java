package org.autocode.generator.repository;

import java.util.*;

public class Repository
{
  private List compilationUnitList;

  //{{{ public Repository()

  public Repository()
  {
    compilationUnitList = new LinkedList();
  }

  //}}}

  //{{{ public void addCompilationUnit(CompilationUnit compilationUnit)

  public void addCompilationUnit(CompilationUnit compilationUnit)
  {
    compilationUnitList.add(compilationUnit);
  }

  //}}}
  //{{{ public Iterator fetchCompilationUnitIterator()

  public Iterator fetchCompilationUnitIterator()
  {
    return compilationUnitList.iterator();
  }

  //}}}
}
