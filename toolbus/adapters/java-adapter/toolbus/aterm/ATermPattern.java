
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
  private ATermRef pattern;

  //{ public ATermPattern(ATermRef pat)

  /**
    * Create a pattern object given a template term containing 
    * zero or more placeholders.
    */

  public ATermPattern(ATermRef pat)
  {
    pattern = pat;
  }

  //}
  //{ public ATermPattern(String pat)

  /**
    * Create a pattern object given a string that represents
    * a placeholder term.
    */

  public ATermPattern(String pat)
    throws ParseError
  {
    pattern = ATermParser.makeSimple(pat);
  }

  //}
  //{ public ATermRef getPattern()

  /**
    * Retrieve the pattern placeholder term of this term pattern.
    */

  public ATermRef getPattern()
  {
    return pattern;
  }

  //}
  //{ public void setPattern(ATermRef pat)

  /**
    * Change the pattern represented by this object.
    */

  public void setPattern(ATermRef pat)
  {
    pattern = pat;
  }

  //}
  //{ public void setPattern(String pat)

  /**
    * Change the pattern represented by this object.
    */

  public void setPattern(String pat)
    throws ParseError
  {
    pattern = ATermParser.makeSimple(pat);
  }

  //}

  //{ public boolean match(ATermRef term)

  /**
    * Match a term against the current pattern. Matching subterms are
    * stored as the elements of the Vector class.
    */

  public boolean match(ATermRef term)
  {
    removeAllElements();
    return pattern.getATerm().match(term.getATerm(), this);
  }

  //}

  //{ public ATermRef makeFromElements()

  /**
    * Build a new term using the elements in this pattern.
    */

  public ATermRef makeFromElements()
    throws IllegalPlaceholder
  {
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make()

  /**
    * Make a term with zero placeholders.
    */

  public ATermRef make()
    throws IllegalPlaceholder
  {
    setSize(0);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object arg1)

  /**
    * Make a term with one placeholder.
    */

  public ATermRef make(Object arg1)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(arg1);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object a1, Object a2)

  /**
    * Make a term with two placeholders.
    */

  public ATermRef make(Object arg1, Object arg2)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object a1, Object a2, Object a3)

  /**
    * Make a term with three placeholders.
    */

  public ATermRef make(Object arg1, Object arg2, Object arg3)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    addElement(arg3);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object a1, Object a2, Object a3, Object a4)

  /**
    * Make a term with four placeholders.
    */

  public ATermRef make(Object arg1, Object arg2, Object arg3, Object arg4)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(arg1);
    addElement(arg2);
    addElement(arg3);
    addElement(arg4);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object a1, Object a2, Object a3, Object a4, Object a5)

  /**
    * Make a term with five placeholders.
    */

  public ATermRef make(Object a1, Object a2, Object a3, Object a4, Object a5)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Oject a1, a2, a3, a4, a5, a6)

  /**
    * Make a term with six placeholders.
    */

  public ATermRef make(Object a1, Object a2, Object a3, Object a4, Object a5,
		       Object a6)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    addElement(a6);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ public ATermRef make(Object a1, a2, a3, a4, a5, a6, a7)

  /**
    * Make a term with seven placeholders.
    */

  public ATermRef make(Object a1, Object a2, Object a3, Object a4, Object a5,
		       Object a6, Object a7)
    throws IllegalPlaceholder
  {
    setSize(0);
    addElement(a1);
    addElement(a2);
    addElement(a3);
    addElement(a4);
    addElement(a5);
    addElement(a6);
    addElement(a7);
    return makeTerm(pattern.getATerm(), elements());
  }

  //}
  //{ protected ATermRef makeTerm(int index)

  /**
    * Make a term, using subterms starting at index.
    */

  protected ATermRef makeTerm(ATerm pattern, Enumeration e)
    throws IllegalPlaceholder
  {
    ATerms terms;

    switch(pattern.getType())
      {
	case ATerm.INT:	        return new ATermIntRef(((ATermInt)pattern));
	case ATerm.REAL:	return new ATermRealRef(((ATermReal)pattern));
	case ATerm.ATERMS:	return makeTerms((ATerms)pattern, e);
	case ATerm.LIST:	
	  return new ATermListRef((ATermsRef)makeTerm(((ATermList)pattern).getATerms(), e));

	case ATerm.APPL:
	  String fun = ((ATermAppl)pattern).getFun();
	  ATerms args = ((ATermAppl)pattern).getArgs();
	  return new ATermApplRef(fun, makeTerms(args, e));

	default:	// Must be a placeholder
	  return makePlaceholder(((ATermPlaceholder)pattern).getPlaceholderType(), e);
      }
  }

  //}

  //{ protected ATermsRef makeTerms(ATerms terms, Enumeration e)

  protected ATermsRef makeTerms(ATerms terms, Enumeration e)
    throws IllegalPlaceholder
  {
    Vector result = new Vector();
    
    while(terms != null) {
      if(terms.getFirst().getType() == ATerm.PLACEHOLDER) {
	ATerm type = ((ATermPlaceholder)terms.getFirst()).getPlaceholderType();
	if(type.getType() == ATerm.APPL) {
	  if(((ATermAppl)type).getFun().equals("terms") &&
	     ((ATermAppl)type).getArgs() == null) {
	    ATermsRef elsref = (ATermsRef)e.nextElement();
	    ATerms els = (elsref == null ? null : elsref.getATerms());
	    while(els != null) {
	      ATerm el = els.getFirst();
	      els = els.getNext();
	      switch(el.getType()) {
    	    	case ATerm.ATERMS:	
		  result.addElement(new ATermsRef((ATerms)el));
		  break;
		  
		case ATerm.APPL:
		  result.addElement(new ATermApplRef((ATermAppl)el));
		  break;
		  
		case ATerm.LIST:
		  result.addElement(new ATermListRef((ATermList)el));
		  break;
		  
		case ATerm.INT:
		  result.addElement(new ATermIntRef((ATermInt)el));
		  break;
		  
		case ATerm.REAL:
		  result.addElement(new ATermRealRef((ATermReal)el));
		  break;

		case ATerm.PLACEHOLDER:
		  result.addElement(new ATermPlaceholderRef((ATermPlaceholder)el));
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

    ATermsRef R = null;
    
    for(int i=result.size()-1; i>=0; i--)
      R = new ATermsRef((ATermRef)result.elementAt(i), R);
    
    return R;
  }

  //}
  //{ protected ATermRef makePlaceholder(ATerm type, Enumeration e)

  protected ATermRef makePlaceholder(ATerm type, Enumeration e)
    throws IllegalPlaceholder
  {
    if(type.getType() == ATerm.APPL) {
      ATermAppl appl = (ATermAppl)type;
      String fun = appl.getFun();
      ATerms args = appl.getArgs();
      
      if(fun.equals("int") && args == null) {
	Integer Int = (Integer)e.nextElement();
	return new ATermIntRef(Int.intValue());
      }
      if(fun.equals("real") && args == null) {
	Double D = (Double)e.nextElement();
	return new ATermRealRef(D.doubleValue());
      }
      if(fun.equals("appl") && args == null)
	return (ATermApplRef)e.nextElement();
      if(fun.equals("term") && args == null)
	return (ATermRef)e.nextElement();
      if(fun.equals("list") && args == null)
	return (ATermListRef)e.nextElement();
      if(fun.equals("str") && args == null)
	return new ATermApplRef((String)e.nextElement(), null, true);
      if(fun.equals("fun")) {
	if(args == null)
	  return new ATermApplRef((String)e.nextElement(), null);
	else
	  return new ATermApplRef((String)e.nextElement(), makeTerms(args, e));
      }
      if(fun.equals("placeholder")) {
	return new ATermPlaceholderRef((ATermRef)e.nextElement());
      }
    }
    throw new IllegalPlaceholder(type);
  }

//}
}

