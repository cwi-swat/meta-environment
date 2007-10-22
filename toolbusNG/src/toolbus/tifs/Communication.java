package toolbus.tifs;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;

abstract public class Communication{
	private final ATermAppl representation;
	private final List<String> argumentList;
	
	public Communication(ATerm t){
		representation = (ATermAppl) t;
		
		argumentList = new ArrayList<String>();
		initArgumentList();
	}
	
	protected ATermAppl getRepresentation(){
		return representation;
	}
	
	public String getName(){
		ATermAppl resultTerm = (ATermAppl) representation.getArgument(0);
		return resultTerm.getAFun().getName();
	}
	
	public String getResultType(){
		return "void";
	}
	
	public Iterator<String> fetchArgumentIterator(){
		return argumentList.iterator();
	}
	
	private void initArgumentList(){
		ATermAppl args = (ATermAppl) representation.getArgument(0);
		int arity = args.getArity();
		for(int i = 0; i < arity; i++){
			ATermAppl arg = (ATermAppl) args.getArgument(i);
			String typeName = arg.getAFun().getName();
			argumentList.add(typeName);
		}
	}
	
	public static Communication create(ATermAppl appl){
		AFun fun = appl.getAFun();
		String name = fun.getName();
		
		// <yuck>
		if(name.equals("eval")){
			return new Eval(appl);
		}else if(name.equals("do")){
			return new Do(appl);
		}else if(name.equals("event")){
			return new Event(appl);
		}
		// </yuck>
		
		throw new RuntimeException("illegal communication construct: " + name);
	}
	
}
