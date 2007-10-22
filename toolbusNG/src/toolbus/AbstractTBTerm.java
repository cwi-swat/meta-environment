package toolbus;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.ATermApplImpl;

public abstract class AbstractTBTerm extends ATermApplImpl{
	protected final TBTermFactory tbfactory;
	
	public AbstractTBTerm(TBTermFactory tbfactory, ATermList annos, AFun fun, ATerm[] args){
		super(tbfactory, annos, fun, args);
		this.tbfactory = tbfactory;
	}
}
