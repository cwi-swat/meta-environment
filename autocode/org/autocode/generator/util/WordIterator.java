package org.autocode.generator;

public class WordIterator
{
  private static final String SEPARATOR_CHARS = "-_.";

  private String identifier;
  private int index;
  private int length;

  private StringBuffer word;
  private char c;

  //{{{ public WordIterator(String identifier)

  public WordIterator(String identifier)
  {
    this.identifier = identifier;
    length = identifier.length();
    index = 0;
  }

  //}}}

  //{{{ public boolean hasNext()

  public boolean hasNext()
  {
    return index < length;
  }

  //}}}

  //{{{ private void nextChar()

  private void nextChar()
  {
    word.append(Character.toLowerCase(c));
    c = identifier.charAt(index++);
  }

  //}}}

  //{{{ private boolean isSeparatorChar(char c)

  private boolean isSeparatorChar(char c)
  {
    return SEPARATOR_CHARS.indexOf(c) != -1;
  }

  //}}}
  //{{{ public String next()

  /* Volgens Hayco gaat deze functie nog een keer op de schop! */

  public String next()
  {
    word = new StringBuffer();
    c = identifier.charAt(index++);

    boolean uppercase = Character.isUpperCase(c);

    if (index == length) {
      return word.toString();
    }

    nextChar();

    // Find two case switches
    boolean done = false;
    for (int i=0; !done && i<2; i++) {
      while (!done && uppercase == Character.isUpperCase(c)) {
	if (index == length) {
	  word.append(Character.toLowerCase(c));
	  done = true;
	  break;
	}
	if (isSeparatorChar(c)) {
	  while (index < length
		 && (isSeparatorChar(identifier.charAt(index)))) {
	    index++;
	  }
	  done = true;
	  break;
	}
	nextChar();
      }

      uppercase = !uppercase;
    }

    if (!done) {
      index--;
    }

    return word.toString();
  }

  //}}}
}
