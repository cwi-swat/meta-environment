package toolbus.util.collections;


/**
 * A high performance thread-safe HashSet designed for use in multi-threaded environments.
 * 
 * @author Arnold Lankamp
 * @param <T>
 *            The value type.
 */
public class ConcurrentHashSet<T> {
	private final static int DEFAULT_NR_OF_SEGMENTS_BITSIZE = 5;
	
	private final Segment<T>[] segments;
	
	/**
	 * Default constructor.
	 */
	public ConcurrentHashSet(){
		super();
		
		segments = (Segment<T>[]) new Segment[1 << DEFAULT_NR_OF_SEGMENTS_BITSIZE];
		for(int i = segments.length - 1; i >= 0; i--){
			segments[i] = new Segment<T>();
		}
	}
	
	/**
	 * Supplemental hash function that guards against weak hash functions and ensures neighboring
	 * hash values (most probably) do not end up in the same segment. This should reduce the amount
	 * of locking when sequencial integers are inserted for example.
	 * 
	 * @param h
	 *            The original hash value.
	 * @return The 'strengthened' hash value.
	 */
	private int supplementalHash(int h){
		int key = h;
		key = ~key + (key << 15); // key = (key << 15) - key - 1;
		key ^= (key >> 12);
		key += (key << 2);
		key ^= (key >> 4);
		key += (key << 3);
		key += (key << 11);
		key ^= (key >> 16);
		
		return key;
	}
	
	/**
	 * Inserts the given value into the table.
	 * 
	 * @param value
	 *            The value.
	 */
	public void put(T value){
		int hash = supplementalHash(value.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		segments[segmentNr].put(value, hash);
	}
	
	/**
	 * Checks if this collection contains give value.
	 * 
	 * @param value
	 *            The value.
	 * @return True if this collection contains the given value; false otherwise.
	 */
	public boolean contains(T value){
		int hash = supplementalHash(value.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		return segments[segmentNr].contains(value, hash);
	}
	
	/**
	 * Removes the given value from the collection.
	 * 
	 * @param value
	 *            The value.
	 */
	public void remove(T value){
		int hash = supplementalHash(value.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		segments[segmentNr].remove(value, hash);
	}
	
	/**
	 * Counts the number of entries in this collection. Note that the value might be slightly off,
	 * due to the absence of locking.
	 * 
	 * @return The number of entries in this collection.
	 */
	public int size(){
		int totalLoad = 0;
		for(int i = segments.length - 1; i >= 0; i--){
			totalLoad += segments[i].size();
		}
		return totalLoad;
	}
	
	/**
	 * Iterates over this collection.
	 * 
	 * @param entryHandler
	 *            The entry handler to use.
	 */
	public void iterate(HashSetEntryHandler<T> entryHandler){
		for(int i = segments.length - 1; i >= 0; i--){
			int action = segments[i].iterate(entryHandler);
			if((action & EntryHandlerConstants.BREAK) == EntryHandlerConstants.BREAK) break;
		}
	}
	
	/**
	 * A segment is a hashset that contains a certain range of hashvalues.
	 * 
	 * @author Arnold Lankamp
	 * @param <T>
	 *            The value type.
	 */
	private static class Segment<T> {
		private final static int MAX_SEGMENT_BITSIZE = 32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE;
		private final static int DEFAULT_SEGMENT_BITSIZE = 5;
		private final static float DEFAULT_LOAD_FACTOR = 1f;
		
		private volatile Entry<T>[] entries;
		
		private volatile int hashMask;
		private int bitSize;
		
		private int threshold;
		private int load;
		
		/**
		 * Default constructor.
		 */
		public Segment(){
			super();
			
			bitSize = DEFAULT_SEGMENT_BITSIZE;
			int nrOfEntries = 1 << bitSize;
			
			hashMask = nrOfEntries - 1;
			
			entries = (Entry<T>[]) new Entry[nrOfEntries];
			
			threshold = (int) (nrOfEntries * DEFAULT_LOAD_FACTOR);
			load = 0;
		}
		
		/**
		 * Checks if the load of this segment exceeds the threshold and resizes it if needed.
		 */
		private void ensureCapacity(){
			if(load > threshold){
				if(bitSize >= MAX_SEGMENT_BITSIZE) return; // We won't do any more rehashes if the
															// segment is already streched to it's
															// maximum (since this would be a
															// useless thing to do).
				
				int nrOfEntries = 1 << (++bitSize);
				int newHashMask = nrOfEntries - 1;
				
				Entry<T>[] oldEntries = entries;
				Entry<T>[] newEntries = (Entry<T>[]) new Entry[nrOfEntries];
				
				Entry<T> currentEntryRoot = new Entry<T>(null, null, 0);
				Entry<T> shiftedEntryRoot = new Entry<T>(null, null, 0);
				int oldSize = oldEntries.length;
				
				for(int i = oldSize - 1; i >= 0; i--){
					Entry<T> e = oldEntries[i];
					if(e != null){
						Entry<T> lastCurrentEntry = currentEntryRoot;
						Entry<T> lastShiftedEntry = shiftedEntryRoot;
						do{
							int position = e.hash & newHashMask;
							
							if(position == i){
								lastCurrentEntry.next = e;
								lastCurrentEntry = e;
							}else{
								lastShiftedEntry.next = e;
								lastShiftedEntry = e;
							}
							
							e = e.next;
						}while(e != null);
						
						lastShiftedEntry.next = null;
						lastCurrentEntry.next = null;
						
						newEntries[i] = currentEntryRoot.next;
						newEntries[i | oldSize] = shiftedEntryRoot.next; // The entries got shifted by the size of the old table.
					}
				}
				
				threshold <<= 1;
				entries = newEntries;
				hashMask = newHashMask;
			}
		}
		
		/**
		 * Inserts the given value into this segment.
		 * 
		 * @param value
		 *            The value.
		 * @param hash
		 *            The hashcode of the value.
		 */
		public synchronized void put(T value, int hash){
			if(value == null) throw new IllegalArgumentException("Cannot insert 'null'.");
			
			int position = hash & hashMask;
			
			// Check if the set already contains the given value.
			Entry<T>[] table = entries;
			Entry<T> e = table[position];
			if(e != null){
				do{
					if(hash == e.hash && value.equals(e.value)){
						return;
					}
					e = e.next;
				}while(e != null);
			}
			
			
			// Insert.
			ensureCapacity();
			
			table = entries; // Get the latest version of the entries table and hashmask, just in case we rehashed.
			position = hash & hashMask;
			
			Entry<T> next = table[position];
			e = new Entry<T>(next, value, hash);
			table[position] = e;
			
			load++;
			
			entries = table; // Volatile write.
		}
		
		/**
		 * Checks if the given value is present in this segment.
		 * 
		 * @param value
		 *            The value.
		 * @param hash
		 *            The hashcode of the value.
		 * @return True if the value is present; false otherwise.
		 */
		public boolean contains(T value, int hash){
			if(value == null) return false;
			
			int position = hash & hashMask;
			Entry<T> e = entries[position]; // Volatile read.
			if(e != null){
				do{
					if(hash == e.hash && value.equals(e.value)){
						return true;
					}
					e = e.next;
				}while(e != null);
			}
			
			// Try again while holding the global lock for this segment, if we couldn't find what we're looking for.
			synchronized(this){
				position = hash & hashMask;
				e = entries[position];
				if(e != null){
					do{
						if(hash == e.hash && value.equals(e.value)){
							return true;
						}
						e = e.next;
					}while(e != null);
				}
				return false;
			}
		}
		
		/**
		 * Removes the given value from this segment.
		 * 
		 * @param value
		 *            The value.
		 * @param hash
		 *            The hashcode of the value.
		 */
		public synchronized void remove(T value, int hash){
			if(value == null) return;
			
			int position = hash & hashMask;
			
			Entry<T>[] table = entries;
			Entry<T> e = table[position];
			Entry<T> previous = null;
			if(e != null){
				do{
					if(hash == e.hash && value.equals(e.value)){
						if(previous != null){
							previous.next = e.next;
						}else{
							table[position] = e.next;
						}
						
						load--;
						
						entries = table; // Volatile write.
					}
					
					previous = e;
					e = e.next;
				}while(e != null);
			}
		}
		
		/**
		 * Returns the load of this segment. Note that it might be off by one, due to the absence of
		 * synchronization.
		 * 
		 * @return The load of this segment.
		 */
		public int size(){
			if(entries != null){ // Volatile read.
				return load;
			}
			return 0;
		}
		
		/**
		 * Iterates over this segment.
		 * 
		 * @param entryHandler
		 *            The entry handler to use.
		 * @return The exit status of the iteration (can be either CONTINUE or BREAK).
		 */
		public synchronized int iterate(HashSetEntryHandler<T> entryHandler){
			Entry<T>[] table = entries;
			
			for(int i = table.length - 1; i >= 0; i--){
				Entry<T> e = table[i];
				Entry<T> previous = null;
				if(e != null){
					do{
						int action = entryHandler.handle(e.value);
						if((action & EntryHandlerConstants.REMOVE) == EntryHandlerConstants.REMOVE){
							if(!entryHandler.canRemove) throw new UnsupportedOperationException("Removal of entries is not allowed for the type of iterator you're using.");
							if(previous != null){
								previous.next = e.next;
							}else{
								table[i] = e.next;
							}
							
							load--;
							
							table = entries; // Volatile write.
						}
						if((action & EntryHandlerConstants.BREAK) == EntryHandlerConstants.BREAK){
							return EntryHandlerConstants.BREAK;
						}
						
						previous = e;
						e = e.next;
					}while(e != null);
				}
			}
			return EntryHandlerConstants.CONTINUE;
		}
		
		/**
		 * Entry containing a value.
		 * 
		 * @author Arnold Lankamp
		 * @param <T>
		 *            The value type.
		 */
		private static class Entry<T> {
			public Entry<T> next; // Not final because we relink entries while rehashing.
			public final int hash;
			public final T value;
			
			public Entry(Entry<T> next, T value, int hash){
				super();
				
				this.next = next;
				this.hash = hash;
				this.value = value;
			}
		}
	}
	
	/**
	 * Entry handler for this hashset.
	 * 
	 * @author Arnold Lankamp
	 * @param <T>
	 *            The value type.
	 */
	public abstract static class HashSetEntryHandler<T> implements EntryHandlerConstants{
		public boolean canRemove = true;
		
		/**
		 * Handles one entry.
		 * 
		 * @param value
		 *            The value.
		 * @see toolbus.util.collections.EntryHandlerConstants
		 * @return The operation the iterator should take (continue, break or remove).
		 */
		public abstract int handle(T value);
	}
	
	/**
	 * A read only version of the entry handler (e.g. removal is disabled).
	 * 
	 * @author Arnold Lankamp
	 * @param <T>
	 *            The value type.
	 */
	public abstract static class ReadOnlyHashSetEntryHandler<T> extends HashSetEntryHandler<T>{
		{
			canRemove = false; // Disable removal
		}
	}
}
