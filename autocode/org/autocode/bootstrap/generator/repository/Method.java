package org.autocode.bootstrap.generator.repository;

//{{{ imports

import java.util.*;

//}}}

public class Method
{
  //{{{ attributes

  private String name;
  private String resultType;
  private MethodBody body;
  private Set exceptionSet;
  private List formalParameterList;

  //}}}

  //{{{ public Method(String name, String resultType, MethodBody body)

  public Method(String name, String resultType, MethodBody body)
  {
    this.name = name;
    this.resultType = resultType;
    this.body = body;
    this.exceptionSet = new HashSet();
    this.formalParameterList = new LinkedList();
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public String getResultType()

  public String getResultType()
  {
    return resultType;
  }

  //}}}

  //{{{ public MethodBody getBody()

  public MethodBody getBody()
  {
    return body;
  }

  //}}}
  //{{{ public void setBody(MethodBody body)

  public void setBody(MethodBody body)
  {
    this.body = body;
  }

  //}}}

  //{{{ public void addException(String exception)

  public void addException(String exception)
  {
    exceptionSet.add(exception);
  }

  //}}}
  //{{{ public Iterator fetchExceptionIterator()

  public Iterator fetchExceptionIterator()
  {
    return exceptionSet.iterator();
  }

  //}}}

  //{{{ public void addFormalParameter(FormalParameter formalParameter)

  public void addFormalParameter(FormalParameter formalParameter)
  {
    formalParameterList.add(formalParameter);
  }

  //}}}
  //{{{ public Iterator fetchFormalParameterIterator()

  public Iterator fetchFormalParameterIterator()
  {
    return formalParameterList.iterator();
  }

  //}}}
}
