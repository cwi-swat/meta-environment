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
import java.util.*;

/**
  * ATermPatterns are used to match terms against a pattern and to
  * build new terms given a pattern.
  * 
  * ATermPattern is a subclass of Vector, because we need a place
  * to store subterms matching with the placeholders in the original
  * term.
  */

public class ATermPattern extends Vector
{
  private ATerm pattern;

  //{ public ATermPattern(ATerm pat)

  /**
    * Create a pattern object given a template term containing 
    * zero or more placeholders.
    */

  public ATermPattern(ATerm pat)
  {
    pattern = pat;
  }

  //}
  //{ public ATermPattern(String pat)

  /**
    * Create a pattern object given a string that represents
    * a placeholder term.
    */

  public ATermPattern(World world, String pat)
    throws ParseError
  {
    pattern = world.makeSimple(pat);
  }

  //}
  //{ public ATerm getPattern()

  /**
    * Retrieve the pattern placeholder term of this term pattern.
    */

  public ATerm getPattern()
  {
    return pattern;
  }

  //}
  //{ public void setPattern(ATerm pat)

  /**
    * Change the pattern represented by this object.
    */

  public void setPattern(ATerm pat)
  {
    pattern = pat;
  }

  //}
  //{ public void setPattern(String pat)

  /**
    * Change the pattern represented by this object.
    */

  public void setPattern(World world, String pat)
    throws ParseError
  {
    pattern = world.makeSimple(pat);
  }

  //}

  //{ public boolean match(ATerm term)

  /**
    * Match a term against the current pattern. Matching subterms are
    * stored as the elements of the Vector class.
    */

  public boolean match(ATerm term)
  {
    removeAllElements();
    return pattern.getATermImpl().match(term.getATermImpl(), this);
  }

  //}

  //{ public ATerm makeFromElements()

  /**
    * Build a new term using the elements in this pattern.
    */

  public ATerm makeFromElements()
  {
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make()

  /**
    * Make a term with zero placeholders.
    */

  public ATerm make()
  {
    setSize(0);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object arg1)

  /**
    * Make a term with one placeholder.
    */

  public ATerm make(Object arg1)
  {
    setSize(0);
    addElement(arg1);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object a1, Object a2)

  /**
    * Make a term with two placeholders.
    */

  public ATerm make(Object arg1, Object arg2)
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object a1, Object a2, Object a3)

  /**
    * Make a term with three placeholders.
    */

  public ATerm make(Object arg1, Object arg2, Object arg3)
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    addElement(arg3);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object a1, Object a2, Object a3, Object a4)

  /**
    * Make a term with four placeholders.
    */

  public ATerm make(Object arg1, Object arg2, Object arg3, Object arg4)
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    addElement(arg3);
    addElement(arg4);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object a1, Object a2, Object a3, Object a4, Object a5)

  /**
    * Make a term with five placeholders.
    */

  public ATerm make(Object a1, Object a2, Object a3, Object a4, Object a5)
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Oject a1, a2, a3, a4, a5, a6)

  /**
    * Make a term with six placeholders.
    */

  public ATerm make(Object a1, Object a2, Object a3, Object a4, Object a5,
		       Object a6)
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    addElement(a6);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ public ATerm make(Object a1, a2, a3, a4, a5, a6, a7)

  /**
    * Make a term with seven placeholders.
    */

  public ATerm make(Object a1, Object a2, Object a3, Object a4, Object a5,
		       Object a6, Object a7)
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    addElement(a6);
    addElement(a7);
    return makeTerm(pattern.getATermImpl(), elements());
  }

  //}
  //{ protected ATerm makeTerm(ATermImpl pattern, Enumeration e)

  /**
    * Make a term, using subterms starting at index.
    */

  protected ATerm makeTerm(ATermImpl pattern, Enumeration e)
  {
    ATermsImpl terms;

    switch(pattern.getType())
      {
	case ATermImpl.INT:     return new ATermInt(((ATermIntImpl)pattern));
	case ATermImpl.REAL:	return new ATermReal(((ATermRealImpl)pattern));
	case ATermImpl.ATERMS:	return makeTerms((ATermsImpl)pattern, e);
	case ATermImpl.LIST:	
	  return pattern.getWorld().makeList((ATerms)makeTerm(((ATermListImpl)pattern).getATermsImpl(), e));

	case ATermImpl.APPL:
	  String fun = ((ATermApplImpl)pattern).getFun();
	  ATermsImpl args = ((ATermApplImpl)pattern).getArgs();
	  return pattern.getWorld().makeAppl(fun, makeTerms(args, e));

	default:	// Must be a placeholder
	  return makePlaceholder(((ATermPlaceholderImpl)pattern).getPlaceholderType(), e);
      }
  }

  //}

  //{ protected ATerms makeTerms(ATermsImpl terms, Enumeration e)

  protected ATerms makeTerms(ATermsImpl terms, Enumeration e)
  {
    Vector result = new Vector();
    World world = terms.getWorld();
    
    while(!terms.isEmpty()) {
      if(terms.getFirst().getType() == ATermImpl.PLACEHOLDER) {
	ATermImpl type = ((ATermPlaceholderImpl)terms.getFirst()).getPlaceholderType();
	if(type.getType() == ATermImpl.APPL) {
	  if(((ATermApplImpl)type).getFun().equals("terms") &&
	     ((ATermApplImpl)type).getArgs().isEmpty()) {
	    ATerms elsref = (ATerms)e.nextElement();
	    ATermsImpl els = elsref.getATermsImpl();
	    while(!els.isEmpty()) {
	      ATermImpl el = els.getFirst();
	      els = els.getNext();
	      switch(el.getType()) {
    	    	case ATermImpl.ATERMS:	
		  result.addElement(new ATerms((ATermsImpl)el));
		  break;
		  
		case ATermImpl.APPL:
		  result.addElement(new ATermAppl((ATermApplImpl)el));
		  break;
		  
		case ATermImpl.LIST:
		  result.addElement(new ATermList((ATermListImpl)el));
		  break;
		  
		case ATermImpl.INT:
		  result.addElement(new ATermInt((ATermIntImpl)el));
		  break;
		  
		case ATermImpl.REAL:
		  result.addElement(new ATermReal((ATermRealImpl)el));
		  break;

		case ATermImpl.PLACEHOLDER:
		  result.addElement(new ATermPlaceholder((ATermPlaceholderImpl)el));
		  break;
	      }
	    }  
	    terms = terms.getNext();
	    continue;
	  }
	}
      }
      result.addElement(makeTerm(terms.getFirst(), e));
      terms = terms.getNext();
    }

    ATerms R = world.empty;
    
    for(int i=result.size()-1; i>=0; i--)
      R = world.makeATerms((ATerm)result.elementAt(i), R);
    
    return R;
  }

  //}
  //{ protected ATerm makePlaceholder(ATermImpl type, Enumeration e)

  protected ATerm makePlaceholder(ATermImpl type, Enumeration e)
  {
    World world = type.getWorld();

    if(type.getType() == ATermImpl.APPL) {
      ATermApplImpl appl = (ATermApplImpl)type;
      String fun = appl.getFun();
      ATermsImpl args = appl.getArgs();
      
      if(fun.equals("int") && args.isEmpty()) {
	Integer Int = (Integer)e.nextElement();
	return world.makeInt(Int.intValue());
      }
      if(fun.equals("real") && args.isEmpty()) {
	Double D = (Double)e.nextElement();
	return world.makeReal(D.doubleValue());
      }
      if(fun.equals("appl") && args.isEmpty())
	return (ATermAppl)e.nextElement();
      if(fun.equals("term") && args.isEmpty())
	return (ATerm)e.nextElement();
      if(fun.equals("list") && args.isEmpty())
	return (ATermList)e.nextElement();
      if(fun.equals("str") && args.isEmpty())
	return world.makeAppl((String)e.nextElement(), world.empty, null, true);
      if(fun.equals("fun")) {
	if(args == null)
	  return world.makeAppl((String)e.nextElement(), world.empty);
	else
	  return world.makeAppl((String)e.nextElement(), makeTerms(args, e));
      }
      if(fun.equals("placeholder")) {
	return world.makePlaceholder((ATerm)e.nextElement());
      }
    }
    throw new IllegalArgumentException("illegal placeholder: " + type.toString());
  }

//}
}

