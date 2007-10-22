package toolbus.tifs;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;

public class Tif{
	private final ATermAppl representation;
	private final List<Process> processList;
	
	public Tif(ATerm t){
		representation = (ATermAppl) t;
		
		processList = new ArrayList<Process>();
		initProcessList();
	}
	
	public int getVersion(){
		ATermAppl versionTerm = (ATermAppl) representation.getArgument(0);
		return ((ATermInt) versionTerm.getArgument(0)).getInt();
	}
	
	public String getPackageName(){
		ATermAppl pkgTerm = (ATermAppl) representation.getArgument(1);
		return ((ATermAppl) pkgTerm.getArgument(0)).getAFun().getName();
	}
	
	public String getToolName(){
		ATermAppl toolTerm = (ATermAppl) representation.getArgument(2);
		return ((ATermAppl) toolTerm.getArgument(0)).getAFun().getName();
	}
	
	private void initProcessList(){
		ATermList iter = (ATermList) representation.getArgument(3);
		while(!iter.isEmpty()){
			processList.add(new Process(iter.getFirst()));
			iter = iter.getNext();
		}
	}
	
	public Iterator<Process> fetchProcessIterator(){
		return processList.iterator();
	}
	
	public String toString(){
		Iterator<Process> iter;
		StringBuilder buf = new StringBuilder();
		buf.append("tifs");
		buf.append('(');
		buf.append("version");
		buf.append('(');
		buf.append(getVersion());
		buf.append(')');
		buf.append(',');
		buf.append("package");
		buf.append('(');
		buf.append('"');
		buf.append(getPackageName());
		buf.append('"');
		buf.append(')');
		buf.append(',');
		buf.append("tool");
		buf.append('(');
		buf.append('"');
		buf.append(getToolName());
		buf.append('"');
		buf.append(')');
		buf.append(',');
		buf.append('[');
		iter = fetchProcessIterator();
		while(iter.hasNext()){
			Process process = iter.next();
			buf.append(process);
			if(iter.hasNext()){
				buf.append(',');
			}
		}
		buf.append(']');
		buf.append(')');
		
		return buf.toString();
	}
	
}
