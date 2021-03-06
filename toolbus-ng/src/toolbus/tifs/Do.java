package toolbus.tifs;

import java.util.Iterator;

import aterm.ATerm;

public class Do extends Communication{
	
	public Do(ATerm t){
		super(t);
	}
	
	public String toString(){
		StringBuilder buf = new StringBuilder();
		buf.append("do(");
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
