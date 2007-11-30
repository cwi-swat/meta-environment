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
		
		for(Atom a : elements){
			r.addAtom(a);
		}
		for(Atom a : as.getSet()){
			r.addAtom(a);
		}
		return r;
	}
	
	public Iterator<Atom> iterator(){
		return elements.iterator();
	}
	
	public Set<Atom> getSet(){
		return elements;
	}
	
	public String toString(){
		String S = "{";
		String sep = "";
		for(Atom a : elements){
			S += sep + a.toString();
			sep = ", ";
		}
		return S + "}";
	}
}
