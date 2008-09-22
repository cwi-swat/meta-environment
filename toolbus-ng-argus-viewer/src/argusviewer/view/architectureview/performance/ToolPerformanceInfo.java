package argusviewer.view.architectureview.performance;

import java.util.Hashtable;

/**
 * TODO better comments for class and methods
 * 
 * @author Tigran Kalaidjan
 */
public class ToolPerformanceInfo {
	private final int m_toolId;
	private final String m_toolName;
	private String m_toolType;
	private String m_toolLanguage;
	private int m_toolMemoryHeapUsage;
	private int m_toolMemoryNonHeapUsage;

	private Hashtable<String, ThreadInfo> m_threads = new Hashtable<String, ThreadInfo>();

	/**
	 * @param toolId
	 *            The Id of tool
	 * @param toolName
	 *            The name of the tool
	 */
	public ToolPerformanceInfo(int toolId, String toolName) {
		this.m_toolId = toolId;
		this.m_toolName = toolName;
	}

	/**
	 * get tool Id
	 * 
	 * @return tool Id
	 */
	public int getToolId() {
		return m_toolId;
	}

	/**
	 * get tool name
	 * 
	 * @return tool name
	 */
	public String getToolName() {
		return m_toolName;
	}

	/**
	 * get tool type
	 * 
	 * @return tool type
	 */
	public String getToolType() {
		return m_toolType;
	}

	/**
	 * get tool language
	 * 
	 * @return tool language
	 */
	public String getToolLanguage() {
		return m_toolLanguage;
	}

	/**
	 * get tool memory heap usage
	 * 
	 * @return tool memory heap usage
	 */
	public int getToolMemoryHeapUsage() {
		return m_toolMemoryHeapUsage;
	}

	/**
	 * get tool memory non heap usage
	 * 
	 * @return tool memory non heap usage
	 */
	public int getToolMemoryNonHeapUsage() {
		return m_toolMemoryNonHeapUsage;
	}

	/**
	 * get tool threads
	 * 
	 * @return tool treads
	 */
	public Hashtable<String, ThreadInfo> getThreads() {
		return m_threads;
	}

	/**
	 * set tool type
	 * 
	 * @param toolType
	 *            String
	 */
	public void setToolType(String toolType) {
		m_toolType = toolType;
	}

	/**
	 * set tool language
	 * 
	 * @param toolLanguage
	 *            String
	 */
	public void setToolLanguage(String toolLanguage) {
		m_toolLanguage = toolLanguage;
	}

	/**
	 * set tool memory heap usage
	 * 
	 * @param toolMemoryHeapUsage
	 *            Integer
	 */
	public void setToolMemoryHeapUsage(int toolMemoryHeapUsage) {
		m_toolMemoryHeapUsage = toolMemoryHeapUsage;
	}

	/**
	 * set tool memory non heap usage
	 * 
	 * @param toolMemoryNonHeapUsage
	 *            Integer
	 */
	public void setToolMemoryNonHeapUsage(int toolMemoryNonHeapUsage) {
		m_toolMemoryNonHeapUsage = toolMemoryNonHeapUsage;
	}

	/**
	 * set tool threads
	 * 
	 * @param threads
	 *            Hashtable
	 */
	public void setThreads(Hashtable<String, ThreadInfo> threads) {
		m_threads = threads;
	}

	/**
	 * tool info to string
	 * 
	 * @return tool info String
	 */
	public String toString() {
		String toolInfo = "getToolId: " + getToolId() + "\n"
				+ "getToolType: " + getToolType() + "\n"
				+ "getToolLanguage: " + getToolLanguage() + "\n"
				+ "getToolMemoryHeapUsage: " + getToolMemoryHeapUsage() + "\n"
				+ "getToolMemoryNonHeapUsage: " + getToolMemoryNonHeapUsage()
				+ "\n";

		for (ThreadInfo t : getThreads().values()) {
			toolInfo = toolInfo + "getThreadName: " + t.getThreadName() + "\n"
					+ "getThreadUserTime: " + t.getThreadUserTime() + "\n"
					+ "getThreadSystemTime: " + t.getThreadSystemTime() + "\n";
		}

		return toolInfo;
	}
}
