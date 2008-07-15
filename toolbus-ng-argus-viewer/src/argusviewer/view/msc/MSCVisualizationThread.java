package argusviewer.view.msc;

import org.apache.log4j.Logger;
import prefuse.Visualization;
import prefuse.activity.Activity;
import prefuse.activity.ActivityListener;

import java.util.Date;

/**
 * The MSCVisualizationThread implements a thread which
 * enables an asynchronous connection between the MessageSequenceChart and
 * Prefuse. This is done by putting a thread in the middle which passes the
 * messages. Reason for this construction is performance.
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 * @author John Franse
 */
public class MSCVisualizationThread
		implements ActivityListener, Runnable {
	private static final int THREAD_SLEEP_TIME_MILLISECONDS = 100;
	private static final int REDRAW_WHILE_COMPUTING_TIMEOUT_MILLISECONDS = 1000;
	
	private boolean m_busyRefreshingVisualization;
	private Object m_busyRefreshingVisualizationLock = new Object();
	private MSCController m_parent;
	private boolean m_receivedWork;
	private Thread m_thread;
	private TimerClass m_timer;
	private Logger m_log = Logger.getLogger(getClass());
	
	private thread_states m_state;
	private Visualization m_visualization;

	/**
	 * The states in which this thread can be.
	 * There are a total of three states.
	 * VISUALISE means prefuse is now visualizing. From this state it can go to
	 * 	IDLE or HOLD.
	 * IDLE means nothing is happening, and no new work is being supplied. From
	 * 	this state it can go it VISUALISE.
	 * HOLD means the thread is being bombarded with work requests. It holds
	 * 	this work until it's idle or a timeout has been reached in which a new
	 * 	visualization is required. It can go from here to IDLE or VISUALISE.
	 */
	
	private static enum thread_states {
		VISUALIZE,
		IDLE,
		HOLD
	}

	/**
	 * Initializes the variables for the thread.
	 * @param parent The MessageSequenceChart this thread "belongs" to.
	 * @param visualization the prefuse Visualization
	 */
	public MSCVisualizationThread(MSCController parent, Visualization visualization) {
		setBusyRefreshingVisualization(false);

		m_parent = parent;
		m_visualization = visualization;

		m_receivedWork = false;
		m_state = thread_states.IDLE;
		
		m_thread = new Thread(null, this, getClass().getName());
		
		m_timer = new TimerClass(this);
		startThread();
	}
	/**
	 * startThread is a function explicitly created to start the thread. 
	 * Findbugs has a problem with Thread.start() being in the constructor.
	 * We believe this is not a problem since the
	 * MSCVisualizationThread does not require full
	 * initialization.
	 */ 
	private void startThread() {
		getThread().start();
		new Thread(null, m_timer, m_timer.getClass().getName()).start();
	}

	/**
	 * This function keeps track of the synchronization between adding
	 * statements and drawing the function.
	 */
	public void run() {
		while (true) {
			switch(m_state) {
			case VISUALIZE:
				m_log.debug(new Date().getTime() + " state VISUALIZE"); 
				processVisualize();
				break;
			case HOLD:
				m_log.debug(new Date().getTime() + " state HOLD"); 
				processHold();
				break;
			case IDLE:
				m_log.debug(new Date().getTime() + " state IDLE"); 
				processIdle();
				break;
			default:
				// This doesn't happen
				m_log.debug("The " + getClass().getName() + " came into an unknown state.");
				assert false;
				break;
			}
		}
	}
	
	/**
	 * Process the visualize state.
	 */
	private void processVisualize() {
		assert m_receivedWork;
		assert !getBusyRefreshingVisualization();
		
		m_receivedWork = false;
		setBusyRefreshingVisualization(true);
		
		synchronized (m_visualization) {
			m_parent.processVisualization();
		}

		do {
		// PreFuse will notify us.
		waitForNotification();
		} while (getBusyRefreshingVisualization());

		assert !getBusyRefreshingVisualization();
		
		if (m_timer.beenIdle()) {
			m_state = thread_states.IDLE;
		} else {
			m_state = thread_states.HOLD;
		}
	}
	
	private void processHold() {
		assert !getBusyRefreshingVisualization();
		
		m_timer.startTimeoutTimer();
		
		while (true) {
			// We will be notified by our {@link TimerClass} when system becomes idle
			timedOutWait(REDRAW_WHILE_COMPUTING_TIMEOUT_MILLISECONDS);


			if (m_timer.beenIdle()) {
				// We were awakened by the {@link TimerClass} thread
				m_state = thread_states.IDLE;
				break;
			}
			if (m_timer.hasTimedOut()) {
				if (m_receivedWork) {
					m_state = thread_states.VISUALIZE;
					break;
				}
				// Timer timed out but there is nothing to do.
				m_timer.startTimeoutTimer();
			}
		}
		m_timer.stopTimer();
	}

	/**
	 * Process the IDLE state.
	 */
	private void processIdle() {
		assert !getBusyRefreshingVisualization();
		
		while (!m_receivedWork) {
			waitForNotification();
		}
		m_state = thread_states.VISUALIZE;
	}
	
	private synchronized boolean timedOutWait(int timeout) {
		try {
			wait(timeout);
		} catch (InterruptedException e) {
			return false;
		}
		return true;
	}

	private synchronized void waitForNotification() {
		try {
			wait();
		} catch (InterruptedException e) {
			// We have expected this
			Logger.getLogger("MessageSequenceChart").debug("MessageSequenceChart thread was interrupted. No big deal.");
		}
	}

	/**
	 * This does the notification in a synchronized fashion.
	 */
	public synchronized void wake() {
		notify();
	}
	
	/**
	 * receivedWork notifies the MessageSequenceChartSyncronisationThread there
	 * is work to be done.
	 */
	public void receivedWork() {
		m_timer.addWork();
		m_receivedWork = true;
		wake();
	}
	
	/**
	 * ActivityListener required function. Removes the listener and sets the
	 * busy signal to false.
	 * @param a The activity to work on
	 */
	public void activityFinished(Activity a) {
		a.removeActivityListener(this);
		setBusyRefreshingVisualization(false);
		wake();

		m_parent.visualizationFinished();
	}

	/**
	 * ActivityListener required function. Removes the listener and unsets the
	 * busy signal.
	 * @param a The activity to work on
	 */
	public void activityCancelled(Activity a) {
		a.removeActivityListener(this);
		setBusyRefreshingVisualization(false);
		wake();
	}

	/**
	 * ActivityListener required function. Intentionally left blank. Thus not
	 * tested.
	 * @param a The activity to work on
	 */
	public void activityScheduled(Activity a) { /* Left blank intentionally. */ }

	/**
	 * ActivityListener required function. Intentionally left blank. Thus not
	 * tested.
	 * @param a The activity to work on
	 */
	public void activityStarted(Activity a) { /* Left blank intentionally. */ }

	/**
	 * ActivityListener required function. Intentionally left blank. Thus not
	 * tested.
	 * @param a The activity to work on
	 */
	public void activityStepped(Activity a) { /* Left blank intentionally. */ }
		
	/**
	 * Returns the actual thread which does the running. 
	 * @return the actual thread which does the running.
	 */
	public Thread getThread() {
		return m_thread;
	}

	/**
	 * Reports whether the thread has work to do.
	 * @return true when it has work to do (or is doing work). False otherwise.
	 */
	public boolean hasWorkToDo() {
		return m_receivedWork || getBusyRefreshingVisualization();
	}
	
	/**
	 * Synchronized setter
	 * @param value the value to set the m_busyRefreshingVisualization flag
	 */
	public void setBusyRefreshingVisualization(boolean value) {
		synchronized (m_busyRefreshingVisualizationLock) {
			m_busyRefreshingVisualization = value;			
		}
	}

	/**
	 * Synchronized getter
	 * @return true when busy refreshing visualization, false when not
	 */
	public boolean getBusyRefreshingVisualization() {
		synchronized (m_busyRefreshingVisualizationLock) {
			return m_busyRefreshingVisualization;			
		}
	}

	/**
	 * Inner class to keep track if the thread has been idle.
	 * @author Ivo Tamboer
	 * @author Frank Oppedijk
	 */
	private static class TimerClass implements Runnable {
		private long m_workCallsPrevious = 0;
		private long m_workCalls = 0;
		private long m_timerStart;
		private MSCVisualizationThread m_mscThread;
		
		public TimerClass(MSCVisualizationThread parent) {
			m_workCallsPrevious = 0;
			m_workCalls = 0;
			m_mscThread = parent;
			stopTimer();
		}
		
		public void run() {
			long temp;
			while (true) {
				temp = m_workCalls;
				try {
					Thread.sleep(THREAD_SLEEP_TIME_MILLISECONDS);
				} catch (InterruptedException e) {
					// the whole point of this thread is that it doesn't get interrupted.
					assert false;
				}
				m_workCallsPrevious = temp;
				// check if you want to notify for timer timeout.
				if (hasTimedOut()) {
					m_mscThread.wake();
				}
				
				if (beenIdle()) {
					m_mscThread.wake();					
				}
			}
		}
	
		public void addWork() {
			m_workCalls++;
		}
		
		public boolean beenIdle() {
			return m_workCalls == m_workCallsPrevious;
		}
		
		public boolean hasTimedOut() {
			long now = new Date().getTime();
			long timeOutMoment = m_timerStart + REDRAW_WHILE_COMPUTING_TIMEOUT_MILLISECONDS;
			
			if (timeOutMoment <= now) {
				return true;
			}
			return false;
		}
		
		public void startTimeoutTimer() {
			m_timerStart = new Date().getTime();
		}

		private void stopTimer() {
			// Nothing to do
		}	
	}
}
