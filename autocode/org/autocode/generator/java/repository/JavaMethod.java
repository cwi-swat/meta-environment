package org.autocode.generator.java.repository;

//{{{ imports

import org.autocode.generator.repository.*;

import java.util.*;

//}}}

public class JavaMethod
  extends Method
{
  //{{{ attributes

  private JavaAccessSpecifier _access;
  private boolean _abstract;
  private boolean _final;
  private boolean _static;

  //}}}

  //{{{ public JavaMethod(name, type, access, abstract, final, static, body)

  public JavaMethod(String name, String resultType, JavaAccessSpecifier access,
		    boolean isabstract, boolean isfinal, boolean isstatic,
		    CodeBlock body)
  {
    super(name, resultType, body);
    _access = access;
    _abstract = isabstract;
    _final = isfinal;
    _static = isstatic;
  }

  //}}}

  //{{{ public JavaAccessSpecifier getAccess()

  public JavaAccessSpecifier getAccess()
  {
    return _access;
  }

  //}}}

  //{{{ public boolean isAbstract()

  public boolean isAbstract()
  {
    return _abstract;
  }

  //}}}
  //{{{ public boolean isFinal()

  public boolean isFinal()
  {
    return _final;
  }

  //}}}
  //{{{ public boolean isStatic()

  public boolean isStatic()
  {
    return _static;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    StringBuffer buf = new StringBuffer();

    buf.append(getAccess().yield());
    buf.append(' ');

    if (isAbstract()) {
      buf.append("abstract ");
    }

    if (isStatic()) {
      buf.append("static ");
    }

    if (isFinal()) {
      buf.append("final ");
    }

    String resultType = getResultType();
    if (resultType != null) {
      buf.append(resultType);
      buf.append(' ');
    }

    buf.append(getName());
    buf.append('(');

    Iterator iter = fetchFormalParameterIterator();
    while (iter.hasNext()) {
      FormalParameter param = (FormalParameter)iter.next();
      buf.append(param.toString());
      if (iter.hasNext()) {
	buf.append(", ");
      }
    }

    buf.append(')');

    return buf.toString();
  }

  //}}}
}
