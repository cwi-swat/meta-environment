package org.autocode.generator.repository.java;

import org.autocode.generator.repository.*;

public class JavaAttribute
  extends Attribute
  implements JavaAccessSpecifiers
{
  private int _access;
  private boolean _final;
  private boolean _static;

  //{{{ public JavaAttribute(String name, String type, TypedMap accessSpecifiers)

  public JavaAttribute(String name, String type, int access, boolean isfinal,
		       boolean isstatic)
  {
    super(name, type);

    this._access = access;
    this._final = isfinal;
    this._static = isstatic;
  }

  //}}}

  //{{{ public int getAccess()

  public int getAccess()
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
  //{{{ public booaccessSpecifiers.getBoolean("final");lean isStatic()

  public boolean isStatic()
  {
    return _static;
  }

  //}}}
}
