package org.autocode.bootstrap.generator.java;

//{{{ imports

import org.autocode.bootstrap.generator.repository.*;
import org.autocode.support.*;
import java.util.*;

//}}}

public class JavaMethod
  extends Method
  implements JavaAccessSpecifiers
{
  //{{{ attributes

  private int _access;
  private boolean _abstract;
  private boolean _final;
  private boolean _static;

  //}}}

  //{{{ public JavaMethod(String name, String resultType, MethodBody body)

  public JavaMethod(String name, String resultType, MethodBody body)
  {
    super(name, resultType, body);
    _access = ACCESS_PUBLIC;
    _abstract = false;
    _final = false;
    _static = false;
  }

  //}}}
  //{{{ public JavaMethod(String name, String resultType)

  public JavaMethod(String name, String resultType)
  {
    this(name, resultType,
	 new MethodBody("throw new UnsupportedOperationException();"));
  }

  //}}}

  //{{{ public JavaMethod(String name)

  public JavaMethod(String name)
  {
    this(name, null);
  }

  //}}}

  //{{{ public int getAccess()

  public int getAccess()
  {
    return _access;
  }

  //}}}
  //{{{ public void setAccess(int access)

  public void setAccess(int access)
  {
    _access = access;
  }

  //}}}

  //{{{ public boolean isAbstract()

  public boolean isAbstract()
  {
    return _abstract;
  }

  //}}}
  //{{{ public void setAbstract(boolean on)

  public void setAbstract(boolean on)
  {
    _abstract = on;
  }

  //}}}

  //{{{ public boolean isFinal()

  public boolean isFinal()
  {
    return _final;
  }

  //}}}
  //{{{ public void setFinal(boolean on)

  public void setFinal(boolean on)
  {
    _final = on;
  }

  //}}}

  //{{{ public boolean isStatic()

  public boolean isStatic()
  {
    return _static;
  }

  //}}}
  //{{{ public void setStatic(boolean on)

  public void setStatic(boolean on)
  {
    _static = on;
  }

  //}}}
}
