
package toolbus.aterm;
import java.io.*;

public class ParseError extends Exception
{
  private ATermChannel channel;
  private char last;
  private String error;

/*  public ParseError(InputChannel c, char lst, String err) {
    super(explanation(c, lst, err));
    channel = c;
    last = lst;
    error = err;
  }
*/
  public ParseError(ATermChannel c, int lst, String err) {
    super(explanation(c, (char)lst, err));
    channel = c;
    last = (char)lst;
    error = err;
  }
  static private String explanation(ATermChannel c, char lst, String err) {
    StringBuffer str = new StringBuffer();

    str.append(err);
    if(c == null)
      str.append(" at the end of the input.");
    else {
      str.append("\ninput left (max 40 chars.): ");
      int ch;
      int i = 40;
      str.append('\'');
      if(lst != (char)-1)
        str.append(lst);
      try {
        while((ch = c.read()) != -1 && i-- > 0) {
          str.append((int)ch);
        }
      } catch (IOException e) {
        str.append("*read error*");
      }
      str.append('\'');
    }
    str.append('\n');
    return str.toString();
  }
}
