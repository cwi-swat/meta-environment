package org.autocode.generator.util;

abstract public class AutocodeEnumeration
{
  private String s;

  //{{{ public AutocodeEnumeration(String s)

  public AutocodeEnumeration(String s)
  {
    this.s = s;
  }

  //}}}

  //{{{ public String yield()

  public String yield()
  {
    return s;
  }

  //}}}
}
