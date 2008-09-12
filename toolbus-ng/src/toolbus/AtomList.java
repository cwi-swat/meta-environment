package toolbus;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import toolbus.atom.Atom;

public class AtomList implements Iterable<Atom>{
	private final List<Atom> elements;
	
	public AtomList(){
		elements = new LinkedList<Atom>();
	}
	
	public AtomList(Atom a){
		elements = new LinkedList<Atom>();
		elements.add(a);
	}
	
	private void addAll(AtomList atomList){
		elements.addAll(atomList.elements);
	}
	
	public AtomList union(AtomList atomList){
		AtomList r = new AtomList();
		
		r.addAll(this);
		r.addAll(atomList);
		
		return r;
	}
	
	public Iterator<Atom> iterator(){
		return elements.iterator();
	}
	
	public int size(){
		return elements.size();
	}
	
	public String toString(){
		String sep = "";
		
		String s = "{";
		
		Iterator<Atom> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			Atom a = elementsIterator.next();
			
			s += sep + a.toString();
			sep = ", ";
		}
		s += "}";
		
		return s;
	}
}
