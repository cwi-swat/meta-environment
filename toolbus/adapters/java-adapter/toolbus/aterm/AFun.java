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
// $Id$
package toolbus.aterm;

import toolbus.tool.*;

/** This class defines the AFun as a subclass of the ATermAppl. It also defines a number of AsFix initialization functions for specific AFuns. This class is only used in conjunction with the class AsFix.
@see AsFix
*/
public class AFun extends ATermAppl {
  public AFun(World world, String af) {
    super(world, af);
  }
  /** init defines AsFix terms. It initializes terms with a well-defined value. See specification for details.
<p>

So far the following AFuns are defined:
<ul> <li> prod <li> appl <li> list <li> lex <li> term <li> var </ul>
*/

  public ATermAppl init() {
    String af = this.getFun();
    ATermAppl result = null;
    try {
    	if (af.equals("prod")) {
      	result = (ATermAppl) world.makeSimple("prod(module-name,w(\"\"),syms,w(\"\"),l(\"->\"),w(\"\"),sym,w(\"\"),attrs)");
    	} else if (af.equals("appl")) {
    	  result = (ATermAppl) world.makeSimple("appl(prod,w(\"\"),args)");
    	} else if (af.equals("list")) {
      	result = (ATermAppl) world.makeSimple("list(sym,w(\"\"),elems)");
      	//    } else {
      	//      throw new Exception("Undefined AFun being initialized: "+af);
    	} else if (af.equals("lex")) {
				result = (ATermAppl) world.makeSimple("lex(name,sym)");
    	} else if (af.equals("term")) {
				result = (ATermAppl) world.makeSimple("term(l(\"term\"),w(\"\"),name,w(\"\"),module-name,w-left,term,w-right,abbrevs)");
    	} else if (af.equals("var")) {
				result = (ATermAppl) world.makeSimple("var(name,sym)");
    	} else {
				System.err.println("AFun.init: Tried to init undefined afun");
				System.exit(1);
    	}
    }
    catch (ParseError e) {
			System.err.println(e);
			System.exit(1);
    }
    return result;
  }
}	
