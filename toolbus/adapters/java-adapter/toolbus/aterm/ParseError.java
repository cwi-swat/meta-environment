/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

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
          str.append((char)ch);
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
