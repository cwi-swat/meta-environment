package toolbus;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import toolbus.atom.Atom;

public class AtomSet implements Iterable<Atom>{
	private final Set<Atom> elements;
	
	public AtomSet(){
		elements = new HashSet<Atom>();
	}
	
	public AtomSet(Atom a){
		elements = new HashSet<Atom>();
		elements.add(a);
	}
	
	public void addAtom(Atom a){
		elements.add(a);
	}
	
	public void delAtom(Atom a){
		elements.remove(a);
	}
	
	public AtomSet union(AtomSet as){
		AtomSet r = new AtomSet();
		
		Iterator<Atom> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			Atom a = elementsIterator.next();
			
			r.addAtom(a);
		}
		
		Iterator<Atom> atomSetIterator = as.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			
			r.addAtom(a);
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
