package org.autocode.generator.java;

public class JavaReservedWords
{
  private static final String[] RESERVED =
  {
    "class", "package", "import",
    "static", "final",
    "public", "private", "protected",
    "int", "char", "float", "double",
    "if", "switch", "case", "for", "while", "break", "return",
    "throw", "throws", "try", "catch", "finally"
  };

  //{{{ static boolean isReservedWord(String keyword)

  static boolean isReservedWord(String keyword)
  {
    for (int i=0; i<RESERVED.length; i++) {
      if (keyword.equals(RESERVED[i])) {
	return true;
      }
    }

    return false;
  }

  //}}}
}
