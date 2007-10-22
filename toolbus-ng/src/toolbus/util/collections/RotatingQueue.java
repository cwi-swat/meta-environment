package toolbus.util.collections;

/**
 * This is a high performance queue implementation that uses very little memory and produces only
 * very little garbage (only during resizing of the backing array). It's about 3 to 5 times as fast
 * as Java's LinkedList queue implementation and uses about 3 times as little memory.
 * 
 * NOTE: This implementation does not contain any locking, so if you want to use this implementation 
 * in a concurrent environment you will have to take care of the locking yourself.
 * 
 * @author Arnold Lankamp
 */
public class RotatingQueue<E>{
	private E[] queue;
	private int capacity;
	private int capacityMask;
	private int nextPutIndex;
	private int getIndex;
	
	/**
	 * Default constructor.
	 */
	public RotatingQueue(){
		super();
		
		capacity = 16;
		capacityMask = capacity - 1;
		
		queue = (E[]) new Object[capacity];
		
		nextPutIndex = 1;
		getIndex = 0;
	}
	
	/**
	 * Ensures that the capacity remains large enough.
	 */
	private void ensureCapacity(){
		if(nextPutIndex == getIndex){
			int size = capacity;
			capacity <<= 1;
			capacityMask = capacity - 1;
			E[] newQueue = (E[]) new Object[capacity];
			if(getIndex == 0){
				System.arraycopy(queue, 0, newQueue, 0, queue.length);
				
				nextPutIndex = size;
			}else{
				int numElemsTillEnd = size - getIndex;
				System.arraycopy(queue, getIndex, newQueue, 0, numElemsTillEnd);
				System.arraycopy(queue, 0, newQueue, numElemsTillEnd, getIndex);
				
				getIndex = 0;
				nextPutIndex = size;
			}
			
			queue = newQueue;
		}
	}
	
	/**
	 * Enqueues an element.
	 * 
	 * @param element
	 *            The element to enqueue.
	 */
	public void put(E element){
		ensureCapacity();
		
		queue[nextPutIndex] = element;
		
		nextPutIndex = (nextPutIndex + 1) & capacityMask;
	}
	
	/**
	 * Checks if there is data present in this queue.
	 * 
	 * @return True if there is data present in this queue; false otherwise.
	 */
	public boolean isEmpty(){
		return (nextPutIndex == ((getIndex + 1) & capacityMask));
	}
	
	/**
	 * Retrieves the first element in this queue, if present.
	 * 
	 * @return The first element in this queue; it this queue is empty NULL will be returned.
	 */
	public E get(){
		if(isEmpty()) return null;
		
		getIndex = (getIndex + 1) & capacityMask;
		E element = queue[getIndex];
		queue[getIndex] = null;
		
		return element;
	}
}
