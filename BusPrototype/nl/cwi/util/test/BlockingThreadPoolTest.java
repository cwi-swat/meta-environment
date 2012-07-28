package nl.cwi.util.test;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import junit.textui.TestRunner;
import nl.cwi.util.BlockingThreadPool;

public class BlockingThreadPoolTest extends TestCase{
	private BlockingThreadPool blockingThreadPool = null;

	public BlockingThreadPoolTest(){
		super();
	}

	public void setUp(){
		blockingThreadPool = new BlockingThreadPool(3, false);
	}

	public void tearDown(){
		blockingThreadPool.destroy();
	}

	public void testJob(){
		final Thread t = Thread.currentThread();

		Runnable job = new Runnable(){

			public void run(){
				try{
					Thread.sleep(1000);
				}catch(InterruptedException irex){
					irex.printStackTrace();
				}
				t.interrupt();
			}
		};

		blockingThreadPool.addJob(job);

		try{
			synchronized(t){
				t.wait(2000);
			}

			fail("not interrupted within 2 seconds");
		}catch(InterruptedException irex){
			// Ignore, this should happen
		}
	}
	
	public void testMultipleJobs(){
		final Thread t = Thread.currentThread();

		final Runnable job = new Runnable(){
			public void run(){
				//Do nothing
			}
		};
		
		final Runnable blockingJob = new Runnable(){
			public void run(){
				t.interrupt();
			}
		};
		
		new Thread(){
				public void run(){
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(blockingJob);
				}
		}.start();

		try{
			synchronized(t){
				t.wait(2000);
			}

			fail("not interrupted within 2 seconds");
		}catch(InterruptedException irex){
			// Ignore, this should happen
		}
	}

	public void testBlocking(){
		final Thread t = Thread.currentThread();

		final Runnable job = new Runnable(){
			public void run(){
				try{
					synchronized(t){
						t.wait();
					}
				}catch(InterruptedException irex){
					irex.printStackTrace();
				}
			}
		};
		
		final Runnable blockingJob = new Runnable(){
			public void run(){
				t.interrupt();
			}
		};

		new Thread(){
				public void run(){
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(job);
					blockingThreadPool.addJob(blockingJob);
				}
		}.start();

		try{
			synchronized(t){
				t.wait(2000);
				t.notifyAll();
			}
		}catch(InterruptedException irex){
			fail("Interrupted within 2 seconds, thread should have blocked");
		}finally{
			synchronized(t){
				t.notifyAll();
			}
		}		
	}
	
	public void testTillIdle(){
		final Runnable job = new Runnable(){
			public void run(){
				synchronized(this){
					try{
						Thread.sleep(1000);
					}catch(InterruptedException irex){
						irex.printStackTrace();
					}
				}
			}
		};
		
		new Thread(){
			public void run(){
				blockingThreadPool.addJob(job);
				blockingThreadPool.addJob(job);
				blockingThreadPool.addJob(job);
				blockingThreadPool.addJob(job);
			}
		}.start();
		
		try{
			Thread.sleep(100);
		}catch(InterruptedException irex){
			irex.printStackTrace();
		}
		
		blockingThreadPool.waitTillIdle();
		
		if(!blockingThreadPool.isIdle()) fail("Wait till Idle failed");
	}
	
	public static void main(String[] args){
		Test t = new TestSuite(BlockingThreadPoolTest.class);
		TestRunner.run(t);
	}
}
