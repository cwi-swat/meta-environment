
package toolbus.aterm;

/**
 * IllegalPlaceholder is thrown when an malformed placeholder is encountered.
 */

public class IllegalPlaceholder extends Exception
{
  private ATerm term;
  IllegalPlaceholder(ATerm t)	{ term = t; }
}
