package argusviewer.toolbus.sync;

import java.util.ArrayList;
import argusviewer.view.listeners.IFocusListener;
import argusviewer.view.listeners.IHighlightListener;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

/**
 * 
 * This class handles the focused and highlighted processes and tools.
 * 
 * @author Tim Van Laer 
 * @author M. van Beest
 */
public class FocusSync {

    private String m_focusedProcessName;
	private String m_highlightedProcessName;
	private ProcessInstance m_focusedProcessInstance;
	private ProcessInstance m_highlightedProcessInstance;
	private String m_focusedToolName;
	private String m_highlightedToolName;
	private ToolInstance m_focusedToolInstance;
	private ToolInstance m_highlightedToolInstance;
	
	private ArrayList<IFocusListener> m_focusListeners;
	private ArrayList<IHighlightListener> m_highlightListeners;
	
	/**
	 * constructor of the focus synchronizator
	 */
	public FocusSync() {
		m_focusListeners = new ArrayList<IFocusListener>();
		m_highlightListeners = new ArrayList<IHighlightListener>();
	}
	
	/**
	 * Registers an IFocusListener
	 * @param listener the IFocusListener to add
	 */
	public void register(IFocusListener listener) {
		m_focusListeners.add(listener);
	}
    
	/**
	 * Registers an IHighlightListener
	 * @param listener the IHighlightListener to add
	 */
	public void register(IHighlightListener listener) {
		m_highlightListeners.add(listener);
	}
    
    /**
	 * give focus to certain processInstance
	 * @param processInstance the processInstance
	 */
	public void setFocus(ProcessInstance processInstance) {
		m_focusedProcessInstance = processInstance;

		for (IFocusListener focusLstr : m_focusListeners) {
			focusLstr.setFocus(processInstance);
		}
	}

	/**
	 * set highlight to certain processInstance
	 *@param processInstance the processInstance
	 */
	public void setHighlight(ProcessInstance processInstance) {
		m_highlightedProcessInstance = processInstance;
		
		for (IHighlightListener highlightLstr : m_highlightListeners) {
			highlightLstr.setHighlight(processInstance);
		}
	}

    /**
	 * set highlight to certain tool instance
	 * @param toolInstance the toolInstance
	 */
    public void setHighlight(ToolInstance toolInstance) {
		m_highlightedToolInstance = toolInstance;

		for (IHighlightListener highlightLstr : m_highlightListeners) {
			highlightLstr.setHighlight(toolInstance);
		}
	}

    /**
	 * set highlight to certain process
	 * @param processName the name of the process
	 */
    public void setHighlightByProcessName(String processName) {
		m_highlightedProcessName = processName;
		
		for (IHighlightListener highlightLstr : m_highlightListeners) {
			highlightLstr.setHighlightByProcessName(processName);
		}
	}

    /**
	 * set highlight to certain tool
	 * @param toolName the name of the tool
	 */
    public void setHighlightByToolName(String toolName) {
		m_highlightedToolName = toolName;		

		for (IHighlightListener highlightLstr : m_highlightListeners) {
			highlightLstr.setHighlightByToolName(toolName);
		}
	}

    /**
	 * set focus to certain tool instance
	 * @param toolInstance the toolInstance
	 */
    public void setFocus(ToolInstance toolInstance) {
		m_focusedToolInstance = toolInstance;
		
		for (IFocusListener focusLstr : m_focusListeners) {
			focusLstr.setFocus(toolInstance);
		}
	}

    /**
     * get the instance of the currently highlighted tool.
     * @return highlighted tool instance
     */
    public ToolInstance getHighlightToolInstance() {
		return m_highlightedToolInstance;
	}
    

    /**
     * get the name of the currently focused process.
     * @return focused process name
     */
    public String getFocusProcess() {
		return m_focusedProcessName;
	}

    /**
     * get the instance of the currently focused process.
     * @return focused process instance
     */
    public ProcessInstance getFocusProcessInstance() {
		return m_focusedProcessInstance;
	}

    /**
     * get the name of the currently focused tool.
     * @return focused tool name
     */
    public String getFocusTool() {
		return m_focusedToolName;
	}

    /**
     * get the instance of the currently focused tool.
     * @return focused tool instance
     */
    public ToolInstance getFocusToolInstance() {
		return m_focusedToolInstance;
	}

    /**
     * get the name of the currently highlighted process.
     * @return highlighted process name
     */
    public String getHighlightProcess() {
		return m_highlightedProcessName;
	}

    /**
     * get the instance of the currently highlighted process.
     * @return highlighted process instance
     */
    public ProcessInstance getHighlightProcessInstance() {
		return m_highlightedProcessInstance;
	}

    /**
     * get the name of the currently highlighted tool.
     * @return highlighted tool name
     */
    public String getHighlightTool() {
		return m_highlightedToolName;
	}
	
}
