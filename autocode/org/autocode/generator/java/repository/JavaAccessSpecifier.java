package org.autocode.generator.java.repository;

import org.autocode.generator.util.*;

public class JavaAccessSpecifier
  extends AutocodeEnumeration
{
  //{{{ private JavaAccessSpecifier(String s)

  private JavaAccessSpecifier(String s)
  {
    super(s);
  }

  //}}}

  //{{{ public static JavaAccessSpecifier parse(String s)

  public static JavaAccessSpecifier parse(String s)
  {
    return new JavaAccessSpecifier(s);
  }

  //}}}
}
