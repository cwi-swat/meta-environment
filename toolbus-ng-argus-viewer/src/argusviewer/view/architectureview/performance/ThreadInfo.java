package argusviewer.view.architectureview.performance;

/**
 * thread info
 * TODO better comments for class and methods
 * 
 * @author Tigran Kalaidjan
 */
public class ThreadInfo {

	private String m_threadName;
	private int m_threadUserTime;
	private int m_threadSystemTime;

	/**
	 * default constructor
	 */
	public ThreadInfo() {
	}

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
	public ThreadInfo(String threadName, int threadUserTime,
			int threadSystemTime) {
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

	/**
	 * set thread name
	 * 
	 * @param threadName
	 *            String
	 */
	public void setThreadName(String threadName) {
		m_threadName = threadName;
	}

	/**
	 * set thread user time
	 * 
	 * @param threadUserTime
	 *            int
	 */
	public void setThreadUserTime(int threadUserTime) {
		m_threadUserTime = threadUserTime;
	}

	/**
	 * set thread system time
	 * 
	 * @param threadSystemTime
	 *            int
	 */
	public void setThreadSystemTime(int threadSystemTime) {
		m_threadSystemTime = threadSystemTime;
	}

}
