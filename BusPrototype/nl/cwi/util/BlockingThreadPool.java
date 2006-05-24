package nl.cwi.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Threadpool with a configurable amount of worker thread. This pool will accept
 * all jobs and return directly; except when all the workers are occupied, then
 * the addJob(Runnable job) will block untill a worker becomes available to
 * handle the job. The worker threads can be specified to run as daemon threads,
 * so they will not prevent the application from terminating.
 * 
 * @author Arnold Lankamp
 */
public class BlockingThreadPool{
	private final Object lock = new Object();
	private final Object waitLock = new Object();

	private List knownWorkers = null;
	private List workers = null;

	private int unCompletedJobs = -1;

	/**
	 * Constructor
	 * 
	 * @param nrOfWorkers
	 *            The amount of threads in the threadpool.
	 * @param daemon
	 *            Specifies if the worker threads should run as daemon threads.
	 */
	public BlockingThreadPool(int nrOfWorkers, boolean daemon){
		super();

		initializeWorkers(nrOfWorkers, daemon);

		unCompletedJobs = 0;
	}

	/**
	 * Initializes the worker threads.
	 * 
	 * @param nrOfWorkers
	 *            The amount for workers in the threadpool.
	 * @param daemon
	 *            Specifies if the worker threads should run as daemon threads.
	 */
	public void initializeWorkers(int nrOfWorkers, boolean daemon){
		workers = new ArrayList(nrOfWorkers);

		for(int i = 0; i < nrOfWorkers; i++){
			Worker worker = new Worker();
			worker.setDaemon(daemon);
			worker.start();

			workers.add(worker);
		}

		knownWorkers = new ArrayList(nrOfWorkers);
		knownWorkers.addAll(workers);
	}

	/**
	 * Requests a worker to be assigned to the given worker thread. If all
	 * workers are bussy the calling thread will be blocked untill a worker
	 * becomes available. Beware however that the calling thread will still be
	 * in possesion of any locks it obtained, which could hinder program
	 * execution.
	 * 
	 * @param job
	 *            The job that needs to be handled.
	 */
	public void addJob(Runnable job){
		synchronized(lock){
			unCompletedJobs++;

			if(!workers.isEmpty()){
				startJob(job);
			}else{
				try{
					lock.wait();
				}catch(InterruptedException irex){
					throw new RuntimeException("Thread " + Thread.currentThread().getName() + " interrupted, while waiting for a lock.");
				}
				startJob(job);
			}
		}
	}

	/**
	 * Assigns a job to a thread. Only one thread should call this method at a
	 * time (addJob(Runnable job is the only method should call this as it
	 * handle the synchronization)).
	 * 
	 * @param job
	 */
	private void startJob(Runnable job){
		Worker worker = (Worker) workers.get(0);
		workers.remove(worker);

		worker.setJob(job);
		synchronized(worker){
			worker.notify();
		}
	}

	/**
	 * Destroys this threadpool. Only use this method when you are absolutely
	 * sure that there are no more jobs waiting to be handled. All the jobs of
	 * the blocked threads will be discarded. After calling this method all
	 * references to this threadpool should be set to null, because it will no
	 * longer be able to function and it can be properly collected by the GC. DO
	 * NOT CALL THE addjob(Runnable job) METHOD AFTER DESTROYING THIS POOL, IT
	 * WILL DISCARD THE JOB AND MIGHT BLOCK THE CALLING THREAD INDEFINATELY!
	 */
	public void destroy(){
		for(int i = 0; i < knownWorkers.size(); i++){
			Worker worker = (Worker) knownWorkers.get(i);
			worker.stopRunning();
			worker.interrupt();
			worker.setJob(null);
		}
		// Notify the blocked threads, so they can continue execution.
		// Because all the worker threads are terminated there jobs will not be
		// processed.
		synchronized(lock){
			lock.notifyAll();
		}
		synchronized(waitLock){
			waitLock.notifyAll();
		}
	}

	/**
	 * Returns true if this threadpool is doing nothing atm.
	 * 
	 * @return True if this threadpool is doing nothing atm; returns false
	 *         otherwise.
	 */
	public boolean isIdle(){
		return (unCompletedJobs == 0);
	}

	/**
	 * This method will block untill this threadpool is done with all the given
	 * work is has atm.
	 */
	public void waitTillIdle(){
		synchronized(waitLock){
			while(!isIdle()){
				try{
					// Wait 500ms maximum, this is nessacary since we cannot
					// obtain the monitor on the lock object; the reason for
					// this is that if wait() is called it will not release the
					// monitor on lock, probably blocking the execution of this
					// threadpool indefinately.
					waitLock.wait(500);
				}catch(InterruptedException irex){
					throw new RuntimeException("Thread " + Thread.currentThread().getName() + " interrupted. Some stupid ass killed this thread (or the threadpool got destroyed).");
				}
			}

			// Return control to the scheduler before checking again.
			Thread.yield();
		}
	}

	/**
	 * A worker thread that is capable of handling jobs.
	 * 
	 * @author lankamp
	 */
	private class Worker extends Thread{
		private Runnable job = null;
		private boolean running = false;

		/**
		 * Default constructor
		 */
		public Worker(){
			super();
		}

		/**
		 * Assigns a job to this worker.
		 * 
		 * @param job
		 */
		public void setJob(Runnable job){
			this.job = job;
		}

		/**
		 * Waits for jobs to arrive and handles them.
		 */
		public void run(){
			running = true;

			while(running){
				try{
					// A new job can be assigned before the next iteration
					synchronized(this){
						if(job == null) wait();
					}

					// This is nessecary, because we do not want this thread
					// to die when a RuntimeException occurs during the
					// execution of the job we are currently handling.
					try{
						job.run();
					}catch(RuntimeException rex){
						rex.printStackTrace();
					}

					job = null;

					synchronized(lock){
						workers.add(this);

						lock.notify();

						unCompletedJobs--;
					}

					if(isIdle()){
						synchronized(waitLock){
							waitLock.notifyAll();
						}
					}
				}catch(InterruptedException irex){
					// Ignore. Happens when this thread is destroyed
				}
			}
		}

		/**
		 * Stops this worker at the next iteration.
		 */
		public void stopRunning(){
			running = false;
		}
	}
}
