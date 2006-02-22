package toolbus.environment;

import java.util.HashMap;
import java.util.LinkedList;


/**
 * HashBindings implements the Bindings interface.
 * The implementation below uses a HashMap of LinkedLists
 *
 */
class HashBindings implements Bindings {
   protected HashMap<String,LinkedList<Binding>> bindings;
   
   public HashBindings(){
	   bindings = new HashMap<String,LinkedList<Binding>>(10);
   }
   
   private void setBindings(HashMap<String,LinkedList<Binding>> b){
	   bindings = b;
   }
   
   public Bindings clone(){
	   HashBindings b = new HashBindings();
	   HashMap<String,LinkedList<Binding>> cpbindings;
	   cpbindings = new HashMap<String,LinkedList<Binding>>(10);
	   for(String key : bindings.keySet()){
		   LinkedList<Binding> l = bindings.get(key);
		   cpbindings.put(key,(LinkedList<Binding>)l.clone());
	   }
	   b.setBindings(cpbindings);
	   return b;
   }
   
   public Binding get(String key){
	   LinkedList<Binding> l = bindings.get(key);
	   if(l != null && !l.isEmpty()){
		   return l.getFirst();
	   }
	   return null;
   }
   
   public void put(String key, Binding b){
	   LinkedList<Binding> l = bindings.get(key);
	   if(l != null){
		   l.addFirst(b);
		   bindings.put(key, l);
	   } else {
		   l = new LinkedList<Binding>();
		   l.addFirst(b);
		   bindings.put(key,l);
	   }
   }
   
   public void remove(String key){
	   LinkedList<Binding> l = bindings.get(key);
	   if(l != null && !l.isEmpty()){   
		   l.removeFirst();
		   bindings.put(key,l);
	   } else {
		   System.err.println("remove:" + key + " is not present\n" + this);
	   }
   }
	public String toString() {
		String res = "{", sep = "";
		for(String key : bindings.keySet()){
			LinkedList<Binding> all = bindings.get(key);
		
			for (Binding b : all){
				String op = b.isFormal() ? " :-> " : " : ";
				res += sep + b.var + op + b.val;
				sep = ", ";
			}
		}
		return res + "}";
	}
}
