package org.autocode.generator.repository;

//{{{ imports

import java.util.*;

//}}}

public class Method
{
  //{{{ attributes

  private String name;
  private String resultType;
  private String description;
  private CodeBlock body;
  private Set exceptionSet;
  private List formalParameterList;

  //}}}

  //{{{ public Method(String name, String resultType, CodeBlock body)

  public Method(String name, String resultType, CodeBlock body)
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

  //{{{ public String getDescription()

  public String getDescription()
  {
    return description;
  }

  //}}}
  //{{{ public void setDescription(String description)

  public void setDescription(String description)
  {
    this.description = description;
  }

  //}}}

  //{{{ public CodeBlock getBody()

  public CodeBlock getBody()
  {
    return body;
  }

  //}}}
  //{{{ public void setBody(CodeBlock body)

  public void setBody(CodeBlock body)
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
