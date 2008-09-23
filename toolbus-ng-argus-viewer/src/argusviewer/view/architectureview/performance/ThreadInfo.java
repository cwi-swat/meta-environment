package argusviewer.view.architectureview.performance;

/**
 * thread info
 * TODO better comments for class and methods
 * 
 * @author Tigran Kalaidjan
 */
public class ThreadInfo {
	private final String m_threadName;
	private final int m_threadUserTime;
	private final int m_threadSystemTime;

	/**
	 * constructor
	 * 
	 * @param threadName
	 *            String
	 * @param threadUserTime
	 *            int
	 * @param threadSystemTime
	 *            int
	 */
	public ThreadInfo(String threadName, int threadUserTime, int threadSystemTime) {
		this.m_threadName = threadName;
		this.m_threadUserTime = threadUserTime;
		this.m_threadSystemTime = threadSystemTime;

	}

	/**
	 * get tread name
	 * 
	 * @return thread name
	 */
	public String getThreadName() {
		return m_threadName;
	}

	/**
	 * get thread user time
	 * 
	 * @return tread user time
	 */
	public int getThreadUserTime() {
		return m_threadUserTime;
	}

	/**
	 * get thread system time
	 * 
	 * @return thread system time
	 */
	public int getThreadSystemTime() {
		return m_threadSystemTime;
	}
}
