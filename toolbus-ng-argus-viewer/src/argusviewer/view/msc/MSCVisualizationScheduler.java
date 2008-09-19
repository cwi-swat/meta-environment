package argusviewer.view.msc;

import javax.swing.SwingUtilities;

public class MSCVisualizationScheduler implements Runnable{
	private final static int MSC_REDRAW_TIMEOUT = 500;
	
	private final NotificationLock lock = new NotificationLock();
	
	private final MSCController controller;
	
	private volatile boolean receivedWork;
	
	private volatile boolean running;
	
	private static class NotificationLock{
		public volatile boolean notified = false;
	}
	
	public MSCVisualizationScheduler(MSCController controller){
		this.controller = controller;

		receivedWork = false;
		running = false;
	}
	
	public void run(){
		running = true;
		while(running){
			if(receivedWork){
				receivedWork = false;
				try{
					SwingUtilities.invokeAndWait(new Runnable(){
						public void run(){
							controller.processVisualization();
						}
					});
				}catch(Exception irex){
					receivedWork = true; // Try again next iteration.
				}
			}
			waitFor(MSC_REDRAW_TIMEOUT);
		}
	}
	
	public void stopRunning(){
		running = false;
	}
	
	private void waitFor(int timeout){
		long waitTill = System.currentTimeMillis() + timeout;
		synchronized(lock){
			while(((System.currentTimeMillis() - waitTill) < 0) && !lock.notified){
				try{
					lock.wait(timeout);
				}catch(InterruptedException e){
					// Ignore.
				}
			}
			lock.notified = false;
		}
	}
	
	public void wakeup(){
		synchronized(lock){
			lock.notified = true;
			lock.notify();
		}
	}
	
	public void receivedWork(){
		receivedWork = true;
	}
}
