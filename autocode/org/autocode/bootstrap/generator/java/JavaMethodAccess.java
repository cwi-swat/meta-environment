package org.autocode.bootstrap.generator.java;

abstract public class JavaMethodAccess
{
  public static final int PRIVATE = 0;
  public static final int ANONYMOUS = 1;
  public static final int PROTECTED = 2;
  public static final int PUBLIC = 3;

  private static final String[] _VALUES =
  { "private", "anonymous", "protected", "public" };


  //{{{ public static final int parse(String arg)

  public static final int parse(String arg)
  {
    for (int i=0; i<_VALUES.length; i++) {
      if (_VALUES[i].equals(arg)) {
	return i;
      }
    }

    throw new IllegalArgumentException("not a JavaMethodAccess element: "
				       + arg);
  }

  //}}}

  //{{{ public static final String yield(int value)

  public static final String yield(int value)
  {
    return _VALUES[value];
  }

  //}}}
}
