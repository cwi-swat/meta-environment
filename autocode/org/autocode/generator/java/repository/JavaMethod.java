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
		    MethodBody body)
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
}
