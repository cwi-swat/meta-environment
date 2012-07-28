package org.autocode.generator.java.repository;

//{{{ imports

import org.autocode.generator.repository.*;
import org.autocode.generator.java.repository.*;

//}}}

public class JavaAttribute
  extends Attribute
{
  private JavaAccessSpecifier _access;
  private boolean _final;
  private boolean _static;

  //{{{ public JavaAttribute(name, type, access, isfinal, isstatic)

  public JavaAttribute(String name, String type, JavaAccessSpecifier access,
		       boolean isfinal, boolean isstatic)
  {
    super(name, type);

    this._access = access;
    this._final = isfinal;
    this._static = isstatic;
  }

  //}}}

  //{{{ public JavaAccessSpecifier getAccess()

  public JavaAccessSpecifier getAccess()
  {
    return _access;
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
