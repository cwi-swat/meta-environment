package org.autocode.generator.repository;

import java.util.*;

public class CompilationUnit
{
  private List _attributeList;
  private List _methodList;

  //{{{ public CompilationUnit()

  public CompilationUnit()
  {
    _attributeList = new LinkedList();
    _methodList = new LinkedList();
  }

  //}}}

  //{{{ public void addAttribute(Attribute attribute)

  public void addAttribute(Attribute attribute)
  {
    _attributeList.add(attribute);
  }

  //}}}
  //{{{ public Iterator fetchAttributeIterator()

  public Iterator fetchAttributeIterator()
  {
    return _attributeList.iterator();
  }

  //}}}

  //{{{ public void addMethod(Method method)

  public void addMethod(Method method)
  {
    _methodList.add(method);
  }

  //}}}
  //{{{ public Iterator fetchMethodIterator()

  public Iterator fetchMethodIterator()
  {
    return _methodList.iterator();
  }

  //}}}

  //{{{ public boolean hasAttribute(Attribute attribute)

  public boolean hasAttribute(Attribute attribute)
  {
    return _attributeList.contains(attribute);
  }

  //}}}
}
