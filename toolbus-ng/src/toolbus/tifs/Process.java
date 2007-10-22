package toolbus.tifs;

import java.util.Iterator;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Process{
	private final ATermAppl representation;
	private final CommunicationList communicationList;
	
	public Process(ATerm t){
		representation = (ATermAppl) t;
		
		ATermList list = (ATermList) representation.getArgument(1);
		communicationList = new CommunicationList(list);
	}
	
	public String getName(){
		ATermAppl nameTerm = (ATermAppl) representation.getArgument(0);
		return ((ATermAppl) nameTerm.getArgument(0)).getAFun().getName();
	}
	
	public Iterator<Communication> fetchCommunicationIterator(){
		return communicationList.iterator();
	}
	
	public String toString(){
		StringBuilder buf = new StringBuilder();
		buf.append("process(");
		buf.append("name(");
		buf.append('"');
		buf.append(getName());
		buf.append('"');
		buf.append(')');
		buf.append(',');
		buf.append('[');
		Iterator<Communication> iter = fetchCommunicationIterator();
		while(iter.hasNext()){
			buf.append(iter.next());
			if(iter.hasNext()){
				buf.append(',');
			}
		}
		buf.append(']');
		buf.append(')');
		return buf.toString();
	}
}
