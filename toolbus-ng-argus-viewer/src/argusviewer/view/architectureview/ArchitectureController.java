package argusviewer.view.architectureview;

import java.util.Enumeration;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.regex.MatchResult;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import toolbus.StateElement;
import toolbus.atom.tool.AckEvent;
import toolbus.atom.tool.Connect;
import toolbus.atom.tool.DisConnect;
import toolbus.atom.tool.Do;
import toolbus.atom.tool.Eval;
import toolbus.atom.tool.Event;
import toolbus.atom.tool.Execute;
import toolbus.atom.tool.GetPerfStats;
import toolbus.atom.tool.RecPerfStats;
import toolbus.atom.tool.RecVal;
import toolbus.atom.tool.SndKill;
import toolbus.atom.tool.Terminate;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.toolbus.DataComm;
import argusviewer.util.ToolbusUtil;
import argusviewer.view.architectureview.performance.ThreadInfo;
import argusviewer.view.architectureview.performance.ToolPerformanceInfo;
import argusviewer.view.architectureview.performance.tree.PerformanceTreeTable;
import argusviewer.view.listeners.IControlListener;
import argusviewer.view.listeners.IPerformanceControlListener;
import argusviewer.view.listeners.IProcessInstanceControlListener;
import argusviewer.view.listeners.IToolControlListener;
import aterm.ATerm;

/**
 * This class implements the IControlListener stuff for the Architecture View
 *
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Jeldert Pol
 */
public class ArchitectureController implements IControlListener, IProcessInstanceControlListener, IToolControlListener, IPerformanceControlListener{
	private final DataComm m_dataComm;
	private final ArchitectureData m_archData;
	private final ArchitectureView m_archView;
	private final PerformanceTreeTable m_performanceTreeTable;
	
	private final Map<ToolInstance, ToolPerformanceInfo> m_toolPerformance;
	
	private static final HashMap<Class<?>, String> SOURCE_OF_STATEMENT = new HashMap<Class<?>, String>();
	static{
		SOURCE_OF_STATEMENT.put(Connect.class, "Tool");
		SOURCE_OF_STATEMENT.put(DisConnect.class, "Tool");
		SOURCE_OF_STATEMENT.put(RecVal.class, "Tool");
		SOURCE_OF_STATEMENT.put(Event.class, "Tool");
		SOURCE_OF_STATEMENT.put(RecPerfStats.class, "Tool");

		SOURCE_OF_STATEMENT.put(Execute.class, "Process");
		SOURCE_OF_STATEMENT.put(Terminate.class, "Process");
		SOURCE_OF_STATEMENT.put(Eval.class, "Process");
		SOURCE_OF_STATEMENT.put(AckEvent.class, "Process");
		SOURCE_OF_STATEMENT.put(Do.class, "Process");
		SOURCE_OF_STATEMENT.put(SndKill.class, "Process");
		SOURCE_OF_STATEMENT.put(GetPerfStats.class, "Process");
	}
	
	/**
	 * @param dataComm The DataComm to use
	 * @param archData The ArchitectureData data model to use
	 * @param archView The Architecture View itself
	 * @param performanceTreeTable The table for the tool performance info
	 */
	public ArchitectureController(DataComm dataComm, ArchitectureData archData, ArchitectureView archView, PerformanceTreeTable performanceTreeTable) {
		m_dataComm = dataComm;
		m_archView = archView;
		m_archData = archData;
		m_performanceTreeTable = performanceTreeTable;
		
		m_toolPerformance = new HashMap<ToolInstance, ToolPerformanceInfo>();
		
		m_dataComm.getControlSync().register((IControlListener) this);
		m_dataComm.getControlSync().register((IToolControlListener) this);
		m_dataComm.getControlSync().register((IProcessInstanceControlListener) this);
		m_dataComm.getControlSync().register((IPerformanceControlListener) this);
		populateArchitectureList(); // Setup initial filling of the data model
	}
	
	/**
	 * {@inheritDoc}
	 */
	public void addProcessInstance(ProcessInstance processInstance) {
		m_archData.addProcess(new Process(processInstance.getProcessName()));
		m_archView.updateVisualization();
	}
	
	/**
	 * {@inheritDoc}
	 */
	public void addToolInstance(ToolInstance toolInstance) {
		m_archData.addTool(new Tool(toolInstance.getToolName()));
		m_archView.updateVisualization();
	}

	/**
	 * add a toolbus singleton instance
	 */
	public void addToolbusSingletonInstance(){
		m_archData.addToolbusSingleton(new ToolbusSingleton());
		m_archView.updateVisualization();
	}

	/**
	 * Get all the processes and tools currently running from the toolbus.
	 */
	private void populateArchitectureList(){
		for(ProcessInstance process : m_dataComm.getControlSync().getProcesses()){
			addProcessInstance(process);	
		}

		for(ToolInstance tool : m_dataComm.getControlSync().getTools()){
			addToolInstance(tool);
		}
		
		addToolbusSingletonInstance();
	}

	/**
	 * {@inheritDoc}
	 */
	public void removeProcessInstance(ProcessInstance processInstance){
		// In the architecture view, removals are not used to modify the view.
	}

	/**
	 * {@inheritDoc}
	 */
	
	public void removeToolInstance(ToolInstance toolInstance){
		// In the architecture view, removals are not used to modify the view.
	}

	/**
	 * Add an executed statement to the Message Sequence Chart.
	 * TODO assert use of the first part of the function; it seems MSC functionality.
	 *
	 * @param tick The timetick indicating when the statement was executed
	 * @param processInstance The process instance which executed the statement
	 * @param executedStateElement The statement that was executed
	 * @param partners In case of a message, this shows the receiving process instances
	 */
	public void stepExecuted(int tick, ProcessInstance processInstance,
			StateElement executedStateElement, ProcessInstance[] partners) {

		String sourceName = "";
		String sourceType = "";
		
		Hashtable<String, String> messageReceivers = new Hashtable<String, String>();

		String processName = processInstance.getProcessName();
		String executedStatementString = executedStateElement.toString();
		
		Message.Type msgType = getMessageType(executedStateElement);
		if (msgType != null) {
			switch (msgType) {
			case ASYNC:
				/* falls through, handle async and sync messages in the same way */
			case SYNC:
				sourceName = processName;
				sourceType = "Process";
				if ((partners != null) && (partners.length > 0)) {
					for (ProcessInstance partner : partners) {
						messageReceivers.put(partner.getProcessName(), "Process");
					}
				}
				break;
			case TOOLCOMM:
				String toolName = ToolbusUtil.getToolIdFromStateElement(executedStateElement);

				String sendingType = SOURCE_OF_STATEMENT.get(executedStateElement.getClass());

				if (sendingType == "Process") {
					sourceName = processName;
					sourceType = "Process";
					messageReceivers.put(toolName, "Tool");
				} else {
					sourceName = toolName;
					sourceType = "Tool";
					messageReceivers.put(processName, "Process");
				}
				break;
			default:
				//empty line
			}
		}

		// If a message has been sent, add it to the data model
		Enumeration<String> enumerator = messageReceivers.keys();
		while (enumerator.hasMoreElements()) {	
			String targetName = enumerator.nextElement();
			m_archData.addMessage(new Message(getMessageFromStateElement(executedStatementString), 
					sourceName, sourceType , targetName, messageReceivers.get(targetName), msgType));
			m_archView.updateVisualization();
		}
	}

	/**
	 * Determine the type of message this StateElement represents
	 * 
	 * TODO should it be eliminated? It looks like MSC cloned crud.
	 *
	 * @param elem
	 *            The StateElement to check
	 * @return The type of Message, or null if the stateElement does not
	 *         represent a Message
	 */
	private Message.Type getMessageType(StateElement elem) {
		for (int i = 0; i < Message.SYNC_COMMUNICATION.length; i++) {
			if (elem.getClass() == Message.SYNC_COMMUNICATION[i]) {
				return Message.Type.SYNC;
			}
		}

		for (int i = 0; i < Message.ASYNC_COMMUNICATION.length; i++) {
			if (elem.getClass() == Message.ASYNC_COMMUNICATION[i]) {
				return Message.Type.ASYNC;
			}
		}

		for (int i = 0; i < Message.TOOL_COMMUNICATION.length; i++) {
			if (elem.getClass() == Message.TOOL_COMMUNICATION[i]) {
				return Message.Type.TOOLCOMM;
			}
		}

		return null;
	}
	
	/**
	 * Get a consistent String representation of the given state element.
	 *
	 * @param stateElement
	 *            name of the state element to format
	 * @return a formatted state element name
	 */
	private String getMessageFromStateElement(String stateElement) {

		int msgStartIndex = stateElement.indexOf('(');
		int msgEndIndex = stateElement.lastIndexOf(')');

		if ((msgStartIndex != -1) && (msgEndIndex != -1)) {
			return stateElement.substring(msgStartIndex + 1, msgEndIndex);
		}
		return stateElement;
	}
	
	// IPerformanceControlListener start
	
	/**
	 * Displays the performance stats for this Toolinstance
	 * @param toolInstance The associated Toolinstance
	 * @param term The performancestats
	 */
	public void updatePerformance(ToolInstance toolInstance, ATerm term){
		if(!m_toolPerformance.containsKey(toolInstance)){
			m_toolPerformance.put(toolInstance, new ToolPerformanceInfo(toolInstance.getToolID(), toolInstance.getToolName()));
		} 

		ToolPerformanceInfo info = m_toolPerformance.get(toolInstance);
		
		String toolType;
		toolType = term.getChildAt(0).getChildAt(0).toString();
		toolType = (String) getValueFromATerm(toolType, String.class, true);

		String toolLanguage;
		toolLanguage = term.getChildAt(0).getChildAt(1).toString();
		toolLanguage = (String) getValueFromATerm(toolLanguage, String.class, true);

		String toolMemHeap = "0";
		int toolMemoryHeapUsage = 0;
		String toolMemNonHeap = "0";
		int toolMemoryNonHeapUsage = 0;
		
		if(term.getChildAt(1).getChildCount() == 2){
			toolMemHeap = term.getChildAt(1).getChildAt(0).toString();
			toolMemoryHeapUsage = ((Integer) getValueFromATerm(toolMemHeap, Integer.class, false)).intValue();
	
			toolMemNonHeap = term.getChildAt(1).getChildAt(1).toString();
			toolMemoryNonHeapUsage = ((Integer) getValueFromATerm(toolMemNonHeap, Integer.class, false)).intValue();
		}

		info.setToolType(toolType);
		info.setToolLanguage(toolLanguage);
		info.setToolMemoryHeapUsage(toolMemoryHeapUsage);
		info.setToolMemoryNonHeapUsage(toolMemoryNonHeapUsage);		
		
		String toolThreads = term.getChildAt(2).toString();
		toolThreads = (String) getValueFromATerm(toolThreads, String.class, true);
		
		Pattern pattern = Pattern.compile("[a-zA-Z0-9 \\-\\_]+\\(user-time\\(\\d+\\),system-time\\(\\d+\\)\\)");
		Matcher matcher = pattern.matcher(toolThreads);

		Hashtable<String, ThreadInfo> threads = new Hashtable<String, ThreadInfo>();
		
		while(matcher.find()){
        	MatchResult result = matcher.toMatchResult();
        	String threadName = (String) getNameFromATerm(result.group());
        	
        	int userTime = 0;
    		int systemTime = 0;
    		
        	String[] times = ((String) getValueFromATerm(result.group(), String.class, false)).split(",");
    		for(String time : times){
        		String timeName = (String) getNameFromATerm(time);

        		if(timeName.equals("user-time")){
        			userTime = ((Integer) getValueFromATerm(time, Integer.class, false)).intValue();
        		}else{
        			systemTime = ((Integer) getValueFromATerm(time, Integer.class, false)).intValue();
        		}
        	}
        	
       		threads.put(threadName, new ThreadInfo(threadName, userTime, systemTime));
        	
        	info.setThreads(threads);
        }
		
		
		for(ToolPerformanceInfo i : m_toolPerformance.values()){
			m_performanceTreeTable.add(i);
		}
	}
	
	/**
	 * Returns the value in the ATerm in the correct Type
	 * @param aterm Entire ATerm
	 * @param type The class of the type that was sent in the ATerm
	 * @return value
	 */
	private Object getValueFromATerm(String aterm, Class< ? > type, boolean encapsulated){
		int beginIndex = aterm.indexOf("(");
		int endIndex = aterm.lastIndexOf(")");
		if(encapsulated){
			beginIndex++;
			endIndex--;
		}
		
		if(beginIndex == -1 || endIndex == -1){
			if(type.equals(Integer.class)){
				return Integer.valueOf(0);
			}
			return "";
		}
		
		if(type.equals(Integer.class)){
			return new Integer(aterm.substring(beginIndex + 1, endIndex));
		}else if (type.equals(String.class)){
			return aterm.substring(beginIndex + 1, endIndex);
		}else{
			return aterm.substring(beginIndex, endIndex);
		}
	}
	
	/**
	 * Returns the name from an ATerm
	 * @param aterm Entire ATerm
	 * @return name
	 */
	private Object getNameFromATerm(String aterm){
		int endIndex = aterm.indexOf("(");
		return aterm.substring(0, endIndex);
	}
	
	// IPerformanceControlListener end
}
