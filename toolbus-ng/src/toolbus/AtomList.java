package toolbus;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import toolbus.atom.Atom;

public class AtomList implements Iterable<Atom>{
	private final Set<Atom> elements;
	
	public AtomList(){
		elements = new HashSet<Atom>();
	}
	
	public AtomList(Atom a){
		elements = new HashSet<Atom>();
		elements.add(a);
	}
	
	private void add(Atom atom){
		elements.add(atom);
	}
	
	public AtomList union(AtomList as){
		AtomList r = new AtomList();
		
		Iterator<Atom> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			Atom a = elementsIterator.next();
			
			r.add(a);
		}
		
		Iterator<Atom> atomSetIterator = as.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			
			r.add(a);
		}
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
