package toolbus.tifs;

import java.util.Iterator;

import aterm.ATerm;
import aterm.ATermAppl;

public class Eval extends Communication{
	
	public Eval(ATerm t){
		super(t);
	}
	
	public String getResultType(){
		ATermAppl resultTerm = (ATermAppl) getRepresentation().getArgument(1);
		return resultTerm.getAFun().getName();
	}
	
	public String toString(){
		StringBuilder buf = new StringBuilder();
		buf.append("eval(");
		buf.append(getName());
		Iterator<String> iter = fetchArgumentIterator();
		if(iter.hasNext()){
			buf.append('(');
			while(iter.hasNext()){
				buf.append(iter.next());
				if(iter.hasNext()){
					buf.append(',');
				}
			}
			buf.append(')');
		}
		buf.append(',');
		buf.append(getResultType());
		buf.append(')');
		return buf.toString();
	}
}
