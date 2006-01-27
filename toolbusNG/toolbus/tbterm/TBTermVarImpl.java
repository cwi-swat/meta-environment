package toolbus.tbterm;

import java.io.IOException;
import java.io.OutputStream;
import java.util.List;

import jjtraveler.VisitFailure;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.Visitable;
import aterm.Visitor;
import aterm.pure.ATermApplImpl;
import aterm.pure.PureFactory;

public class TBTermVarImpl extends ATermApplImpl implements TBTermVar {
	
	public TBTermVarImpl(TBTermFactory factory){
		super(factory);
	}

	protected ATermAppl make(AFun fun, ATerm[] i_args, ATermList annos) {
		return getPureFactory().makeAppl(fun, i_args, annos);
	}

	protected ATermAppl make(AFun fun, ATerm[] i_args) {
		return make(fun, i_args, getPureFactory().makeList());
	}

	protected TBTermVar make(String name, String ProcessName, TBTermType type) {
		
		return make(getFactory().varAFun, i_args, getPureFactory().makeList());
	}

}
