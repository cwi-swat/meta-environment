
package toolbus.aterm;
import java.io.*;

class ATermSize
{
  public static void main(String[] args)
	throws IOException, ParseError
  {
    ATerm T = ATerm.the_world.parse(System.in);
    System.out.println("This term has " + T.size() + " nodes.");
  }
}
