package org.autocode.bootstrap.generator.java;

public interface JavaAccessSpecifiers
{
  public static final int ACCESS_PRIVATE = 0;
  public static final int ACCESS_PROTECTED = 1;
  public static final int ACCESS_ANONYMOUS = 2;
  public static final int ACCESS_PUBLIC = 3;

  public static final String[] ACCESS =
  { "private", "protected", null, "public"
  };

}

