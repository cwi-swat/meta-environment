package org.autocode.bootstrap.generator.java;

import org.autocode.bootstrap.generator.repository.*;

import org.autocode.support.*;

public class JavaAttribute
  extends Attribute
  implements JavaAccessSpecifiers
{
  //{{{ private static final EnumerationMap accessEnumerationMap

  private static final EnumerationMap accessEnumerationMap =
    new EnumerationMap() {
      public int parse(String value)
      {
	if (value.equals("private")) {
	  return 0;
	} else if (value.equals("protected")) {
	  return 1;
	} else if (value.equals("anonymous")) {
	  return 2;
	} else if (value.equals("public")) {
	  return 3;
	}

	throw new IllegalArgumentException("illegal enumeration literal: " + value);
      }

      public String yield(int value)
      {
	switch (value) {
	  case 0: return "private";
	  case 1: return "protected";
	  case 2: return "anonymous";
	  case 3: return "public";
	}

	throw new IllegalArgumentException("illegal enumeration value: " + value);
      }
    };

  //}}}
  private TypedMap accessSpecifiers;

  //{{{ public JavaAttribute(String name, String type, TypedMap accessSpecifiers)

  public JavaAttribute(String name, String type, TypedMap accessSpecifiers)
  {
    super(name, type);

    this.accessSpecifiers = accessSpecifiers;
  }

  //}}}

  //{{{ public int getAccess()

  public int getAccess()
  {
    return accessSpecifiers.getEnumeration("access", accessEnumerationMap);
  }

  //}}}

  //{{{ public boolean isFinal()

  public boolean isFinal()
  {
    return accessSpecifiers.getBoolean("final");
  }

  //}}}
  //{{{ public boolean isStatic()

  public boolean isStatic()
  {
    return accessSpecifiers.getBoolean("static");
  }

  //}}}
}
