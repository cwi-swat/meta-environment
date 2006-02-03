package toolbus;

import aterm.pure.ATermApplImpl;

public abstract class AbstractTBTerm extends ATermApplImpl {
	  protected aterm.ATerm term;

	 protected TBTermFactory tbfactory;
	 

	  public AbstractTBTerm(TBTermFactory tbfactory) {
	    super(tbfactory);
	    this.tbfactory = tbfactory;
	  }

	  public void init(int hashCode, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
	    super.init(hashCode, annos, fun, args);
	  }

	  public void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
	    super.initHashCode(annos, fun, args);
	  }

//	  abstract public aterm.ATerm toTerm();

//	  public String toString() {
//	    return toTerm().toString();
//	  }

	  protected void setTerm(aterm.ATerm term) {
	    this.term = term;
	  }

	//  public TBTermFactory getTBTermFactory() {
	//    return abstractTBTermFactory;
	//  }
}
