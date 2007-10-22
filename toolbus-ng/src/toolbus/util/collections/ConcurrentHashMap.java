package toolbus.util.collections;


/**
 * A high performance thread-safe HashMap designed for use in multi-threaded environments.
 * 
 * @author Arnold Lankamp
 * @param <T>
 *            The key type
 * @param <R>
 *            The value type
 */
public class ConcurrentHashMap<T, R> {
	private final static int DEFAULT_NR_OF_SEGMENTS_BITSIZE = 5;
	
	private final Segment<T, R>[] segments;
	
	/**
	 * Default constructor.
	 */
	public ConcurrentHashMap(){
		super();
		
		segments = (Segment<T, R>[]) new Segment[1 << DEFAULT_NR_OF_SEGMENTS_BITSIZE];
		for(int i = segments.length - 1; i >= 0; i--){
			segments[i] = new Segment<T, R>();
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
	 * Inserts the given key value pair into the table. If the given key is already present in the
	 * collection the value will be replaced and the old value returned.
	 * 
	 * @param key
	 *            The key.
	 * @param value
	 *            The value.
	 * @return Null if the value wasn't present yet, otherwise the 'old' value will be returned.
	 */
	public R put(T key, R value){
		int hash = supplementalHash(key.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		return segments[segmentNr].put(key, hash, value);
	}
	
	/**
	 * Retrieves the value associated with the given key from the table. This function is lock-free
	 * in the general case.
	 * 
	 * @param key
	 *            The key.
	 * @return The value that was found; null if there was no present value associated with the
	 *         given key.
	 */
	public R get(T key){
		int hash = supplementalHash(key.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		return segments[segmentNr].get(key, hash);
	}
	
	/**
	 * Checks if this collection contains a mapping associated with the given key.
	 * 
	 * @param key
	 *            The key.
	 * @return True if the value was present, false otherwise.
	 */
	public boolean contains(T key){
		int hash = supplementalHash(key.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		return segments[segmentNr].contains(key, hash);
	}
	
	/**
	 * Removes the mapping associated with the given key from the collection.
	 * 
	 * @param key
	 *            The key.
	 * @return The value associated with the given key, if present; null otherwise.
	 */
	public R remove(T key){
		int hash = supplementalHash(key.hashCode());
		int segmentNr = hash >>> (32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE);
		
		return segments[segmentNr].remove(key, hash);
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
	public void iterate(HashMapEntryHandler<T, R> entryHandler){
		for(int i = segments.length - 1; i >= 0; i--){
			int action = segments[i].iterate(entryHandler);
			if((action & EntryHandlerConstants.BREAK) == EntryHandlerConstants.BREAK) break;
		}
	}
	
	/**
	 * A segment is a hashtable that contains a certain range of hashvalues.
	 * 
	 * @author Arnold Lankamp
	 * @param <T>
	 *            The key type.
	 * @param <R>
	 *            The value type.
	 */
	private static class Segment<T, R> {
		private final static int MAX_SEGMENT_BITSIZE = 32 - DEFAULT_NR_OF_SEGMENTS_BITSIZE;
		private final static int DEFAULT_SEGMENT_BITSIZE = 5;
		private final static float DEFAULT_LOAD_FACTOR = 1f;
		
		private volatile Entry<T, R>[] entries;
		
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
			
			entries = (Entry<T, R>[]) new Entry[nrOfEntries];
			
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
				
				Entry<T, R>[] oldEntries = entries;
				Entry<T, R>[] newEntries = (Entry<T, R>[]) new Entry[nrOfEntries];
				
				Entry<T, R> currentEntryRoot = new Entry<T, R>(null, null, null, 0);
				Entry<T, R> shiftedEntryRoot = new Entry<T, R>(null, null, null, 0);
				int oldSize = oldEntries.length;
				
				for(int i = oldSize - 1; i >= 0; i--){
					Entry<T, R> e = oldEntries[i];
					if(e != null){
						Entry<T, R> lastCurrentEntry = currentEntryRoot;
						Entry<T, R> lastShiftedEntry = shiftedEntryRoot;
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
		 * Inserts a new mapping into this segment.
		 * 
		 * @param key
		 *            The key.
		 * @param hash
		 *            The hash code of the key.
		 * @param value
		 *            The value.
		 * @return Null if the mapping is new; othewise the value that was previously associated
		 *         with the give key is returned.
		 */
		public synchronized R put(T key, int hash, R value){
			if(key == null) throw new IllegalArgumentException("Cannot use 'null' as key.");
			if(value == null) throw new IllegalArgumentException("Cannot insert 'null' value.");
			
			int position = hash & hashMask;
			
			// Find (and replace if present).
			Entry<T, R>[] table = entries; // Volatile read.
			Entry<T, R> e = table[position];
			if(e != null){
				do{
					if(hash == e.hash && key.equals(e.key)){
						R oldValue = e.value;
						e.value = value;
						
						entries = table; // Volatile write.
						return oldValue;
					}
					e = e.next;
				}while(e != null);
			}
			
			// Insert.
			ensureCapacity();
			
			table = entries; // Get the latest version of the entries table, in case we rehashed.
			
			Entry<T, R> next = table[position];
			e = new Entry<T, R>(next, key, value, hash);
			table[position] = e;
			
			load++;
			
			entries = table; // Volatile write.
			
			return null;
		}
		
		/**
		 * Locates and returns the value associated with the given key.
		 * 
		 * @param key
		 *            The key.
		 * @param hash
		 *            The hashcode of the key.
		 * @return The value associated with the given key; null otherwise.
		 */
		private R find(T key, int hash){
			int position = hash & hashMask;
			
			Entry<T, R> e = entries[position]; // Volatile read.
			if(e != null){
				do{
					if(hash == e.hash && key.equals(e.key)){
						return e.value;
					}
					e = e.next;
				}while(e != null);
			}
			
			return null;
		}
		
		/**
		 * Returns the value associated with the given key.
		 * 
		 * @param key
		 *            The key.
		 * @param hash
		 *            The hashcode of the key.
		 * @return The value associated with the given key; null otherwise.
		 */
		public R get(T key, int hash){
			if(key == null) return null;
			
			R result = find(key, hash);
			if(result != null) return result;
			// It could be that we didn't find it because we were rehashing, so try again while
			// holding the global lock for this segment.
			synchronized(this){
				return find(key, hash);
			}
		}
		
		/**
		 * Checks if this segment contains a mapping associated with the given key.
		 * 
		 * @param key
		 *            The key.
		 * @param hash
		 *            The hashcode of the key.
		 * @return True if there is a mapping present associated with the given key; false
		 *         otherwise.
		 */
		public boolean contains(T key, int hash){
			return (get(key, hash) != null);
		}
		
		/**
		 * Removes the mapping associated with the given key from this segment.
		 * 
		 * @param key
		 *            The key.
		 * @param hash
		 *            The hashcode of the key.
		 * @return The value associated with the given key; null otherwise.
		 */
		public synchronized R remove(T key, int hash){
			if(key == null) return null;
			
			int position = hash & hashMask;
			
			Entry<T, R>[] table = entries;
			Entry<T, R> e = table[position];
			Entry<T, R> previous = null;
			if(e != null){
				do{
					if(hash == e.hash && key.equals(e.key)){
						if(previous != null){
							previous.next = e.next;
						}else{
							table[position] = e.next;
						}
						
						load--;
						
						entries = table; // Volatile write.
						
						return e.value;
					}
					
					previous = e;
					e = e.next;
				}while(e != null);
			}
			
			return null;
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
		public synchronized int iterate(HashMapEntryHandler<T, R> entryHandler){
			Entry<T, R>[] table = entries;
			
			for(int i = table.length - 1; i >= 0; i--){
				Entry<T, R> e = table[i];
				Entry<T, R> previous = null;
				if(e != null){
					do{
						int action = entryHandler.handle(e.key, e.value);
						if((action & EntryHandlerConstants.REMOVE) == EntryHandlerConstants.REMOVE){
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
		 * Entry representing a mapping.
		 * 
		 * @author Arnold Lankamp
		 * @param <T>
		 *            The key type.
		 * @param <R>
		 *            The value type.
		 */
		private static class Entry<T, R> {
			public Entry<T, R> next; // Not final because we relink entries while rehashing.
			public final int hash;
			public final T key;
			public R value; // Not final since we need to be able to replace values.
			
			public Entry(Entry<T, R> next, T key, R value, int hash){
				super();
				
				this.next = next;
				this.hash = hash;
				this.key = key;
				this.value = value;
			}
		}
	}
	
	/**
	 * Entry handler for this hashmap.
	 * 
	 * @author Arnold Lankamp
	 * @param <T>
	 *            The key type.
	 * @param <R>
	 *            The value type.
	 */
	public interface HashMapEntryHandler<T, R> extends EntryHandlerConstants{
		int handle(T key, R value);
	}
}
