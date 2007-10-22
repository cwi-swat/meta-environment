package toolbus.tifs;

import java.util.Iterator;

import aterm.ATerm;

public class Event extends Communication{
	
	public Event(ATerm t){
		super(t);
	}
	
	public String toString(){
		StringBuilder buf = new StringBuilder();
		buf.append("event(");
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
		buf.append(')');
		return buf.toString();
	}
}
