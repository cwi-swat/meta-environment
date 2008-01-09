package toolbus.environment;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * ListBindings uses a simple LinkedList to implement the Bindings interface.
 */
class ListBindings implements Bindings{
	private final LinkedList<Binding> bindings;
	
	public ListBindings(){
		bindings = new LinkedList<Binding>();
	}
	
	protected ListBindings(ListBindings listBindings){
		bindings = new LinkedList<Binding>();
		bindings.addAll(listBindings.bindings);
	}
	
	public Bindings clone(){
		return new ListBindings(this);
	}
	
	public Binding get(String key){
		Iterator<Binding> bindingsIterator = bindings.iterator();
		while(bindingsIterator.hasNext()){
			Binding b = bindingsIterator.next();
			
			if(b.getName().equals(key)){
				return b;
			}
		}
		return null;
	}
	
	public int size(){
		return bindings.size();
	}
	
	public void put(String key, Binding b){
		bindings.addFirst(b);
	}
	
	public void remove(String key){
		Iterator<Binding> bindingIterator = bindings.iterator();
		while(bindingIterator.hasNext()){
			Binding b = bindingIterator.next();
			if(b.getName().equals(key)){
				bindingIterator.remove();
				return;
			}
		}
		System.err.println("remove:" + key + " is not present\n" + this);
	}
	
	public List<Binding> getBindingsAsList(){
		List<Binding> newBindings = new LinkedList<Binding>();
		newBindings.addAll(bindings);
		
		return newBindings;
	}
	
	public String toString(){
		String res = "{", sep = "";
		
		Iterator<Binding> bindingsIterator = bindings.iterator();
		while(bindingsIterator.hasNext()){
			Binding b = bindingsIterator.next();
			
			res += sep + b;
			sep = ", ";
		}
		return res + "}";
	}
}
