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
  the element named <tt>sym</tt> from the term <tt>t</tt> <p> @see
  toolbus.aterm.AFun#init to find out which named elements are
  defined.  */

  public static ATermRef acc(ATermApplRef t, AFun af2) throws Exception {
    AFun af1 = new AFun(t.getFun());
    ATermApplRef at = af1.init();
    return namedElem(af2,new ATermListRef(at.getArgs()),new ATermListRef(t.getArgs()));
  }

  /** repl is the AsFix replacement function. <p> <tt>t[sym :=
  t']</tt> in the specification is <tt>repl(t,sym,t')</tt> here. It
  replaces named element <tt>sym</tt> of <tt>t</tt> with term
  <tt>t'</tt>.  <p> @see toolbus.aterm.AFun#init to find out which
  named elements are defined.*/

  public static ATermApplRef repl(ATermApplRef t1, AFun af, ATermRef t2) throws Exception {
    AFun af1 = new AFun(t1.getFun());
    ATermApplRef at = af1.init();
    t1.setArgs(replace(new ATermListRef(t1.getArgs()), position(af,new ATermListRef(at.getArgs()), 0), t2).getATerms());
    return t1;
  }
  
  /** position find the index of a AFun in a list of ATerms.
   */
  private static int position(AFun af, ATermListRef l, int i) {
    if (af.equals(l.getATerms().getFirst())) {
      return i;
    } else {
      return position(af, new ATermListRef(l.getATerms().getNext()), i+1);
    }
  }
  /** replace does the actual replacing. It replaces index <tt>i</tt>
   of list <tt>l</tt> with term <tt>t</tt>.  */
  private static ATermListRef replace(ATermListRef l, int i, ATermRef t) {
    if (i == 0) {
      return new ATermListRef(new ATermsRef(t,l.getATerms().getNext()));
    } else {
      return new ATermListRef(new ATermsRef(l.getATerms().getFirst(), replace(new ATermListRef(l.getATerms().getNext()), i-1, t).getATerms()));
    }
  }

  
  /** namedElem is the same as in the AsFix specification. It looks up
   at which location <tt>af</tt> exists in <tt>l1</tt> and returns the
   term at taht location in list <tt>l2</tt> */
  private static ATermRef namedElem(AFun af, ATermListRef l1, ATermListRef l2) {
    if (af.equals(l1.getATerms().getFirst())) {
      return l2.getATerms().getFirst();
    } else {
      return namedElem(af, new ATermListRef(l1.getATerms().getNext()),new ATermListRef(l2.getATerms().getNext()));
    }
  }
}
