// $Id$
package toolbus.aterm;
import toolbus.aterm.*;
import toolbus.tool.*;

  /** This class defines AsFix operations on a call-by-need basis. If
   you miss something here: add it. For now, no well-formedness
   checking is done here.<p>
   
   All methods in this class are static, there is no AsFix
   constructor. All methods follow the specification as close as
   possible.  */

public class AsFix {

  /** acc is the AsFix access or selection function. <p> <tt>t[sym]</tt>
  in the specification is <tt>acc(t,sym)</tt> here. This will return
  the element named <tt>sym</tt> from the term <tt>t</tt> <p> 
  @see toolbus.aterm.AFun#init to find out which named elements are
  defined.  */

  public static ATerm acc(ATermAppl t, AFun af2) throws ParseError {
    AFun af1 = new AFun(ATerm.the_world, t.getFun());
    ATermAppl at = af1.init();
    return namedElem(af2,new ATermList(ATerm.the_world, at.getArgs()),
		     new ATermList(ATerm.the_world, t.getArgs()));
  }

  /** repl is the AsFix replacement function. <p> <tt>t[sym :=
  t']</tt> in the specification is <tt>repl(t,sym,t')</tt> here. It
  replaces named element <tt>sym</tt> of <tt>t</tt> with term
  <tt>t'</tt>.  <p> 
  @see toolbus.aterm.AFun#init to find out which
  named elements are defined.*/

  public static ATermAppl repl(ATermAppl t1, AFun af, ATerm t2) throws ParseError {
    AFun af1 = new AFun(ATerm.the_world, t1.getFun());
    ATermAppl at = af1.init();
    t1.setArgs(replace(new ATermList(ATerm.the_world, t1.getArgs()), 
		       position(af,new ATermList(ATerm.the_world, at.getArgs()), 0), 
		       t2).getATerms());
    return t1;
  }
  
  /** position find the index of a AFun in a list of ATerms.
   */
  private static int position(AFun af, ATermList l, int i) {
    if (af.equals(l.getATerms().getFirst())) {
      return i;
    } else {
      return position(af, new ATermList(ATerm.the_world, l.getATerms().getNext()), i+1);
    }
  }
  /** replace does the actual replacing. It replaces index <tt>i</tt>
   of list <tt>l</tt> with term <tt>t</tt>.  */
  private static ATermList replace(ATermList l, int i, ATerm t) {
    if (i == 0) {
      return new ATermList(ATerm.the_world, 
			   new ATerms(ATerm.the_world, t,
				      l.getATerms().getNext()));
    } else {
      return new ATermList(ATerm.the_world, 
			   new ATerms(ATerm.the_world, l.getATerms().getFirst(), 
				      replace(new ATermList(ATerm.the_world,
			    l.getATerms().getNext()), i-1, t).getATerms()));
    }
  }

  
  /** namedElem is the same as in the AsFix specification. It looks up
   at which location <tt>af</tt> exists in <tt>l1</tt> and returns the
   term at taht location in list <tt>l2</tt> */
  private static ATerm namedElem(AFun af, ATermList l1, ATermList l2) {
    if (af.equals(l1.getATerms().getFirst())) {
      return l2.getATerms().getFirst();
    } else {
      return namedElem(af, new ATermList(ATerm.the_world, l1.getATerms().getNext()),
		       new ATermList(ATerm.the_world, l2.getATerms().getNext()));
    }
  }
}
