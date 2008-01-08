package toolbus.util.concurrency;

/**
 * This is a latch which enables the user to block the execution of a specific piece of code until
 * all acquired locks are released.
 * 
 * @author Arnold Lankamp
 */
public class Latch{
	private final Object lock;
	private int count;
	
	/**
	 * Default constructor.
	 */
	public Latch(){
		lock = new Object();
		count = 0;
	}
	
	/**
	 * Acquires one lock.
	 */
	public void acquire(){
		synchronized(lock){
			count++;
		}
	}
	
	/**
	 * Releases one lock.
	 */
	public void release(){
		synchronized(lock){
			if(--count == 0){
				lock.notify();
			}
		}
	}
	
	/**
	 * Blocks until all aqcuired locks are released.
	 * 
	 * @throws InterruptedException Thrown when the blocked thread is interrupted.
	 */
	public void await() throws InterruptedException{
		synchronized(lock){
			if(count == 0){
				lock.wait();
			}
		}
	}
}
