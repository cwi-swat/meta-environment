package argusviewer.toolbus.sync;

import java.util.ArrayList;
import argusviewer.view.listeners.IFocusListener;
import argusviewer.view.listeners.IHighlightListener;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

/**
 * This class handles the focused and highlighted processes and tools.
 * 
 * @author Tim Van Laer 
 * @author M. van Beest
 */
public class FocusSync{
	private final ArrayList<IFocusListener> m_focusListeners;
	private final ArrayList<IHighlightListener> m_highlightListeners;
	
	/**
	 * constructor of the focus synchronizator
	 */
	public FocusSync(){
		m_focusListeners = new ArrayList<IFocusListener>();
		m_highlightListeners = new ArrayList<IHighlightListener>();
	}
	
	/**
	 * Registers an IFocusListener
	 * @param listener the IFocusListener to add
	 */
	public void register(IFocusListener listener){
		m_focusListeners.add(listener);
	}
    
	/**
	 * Registers an IHighlightListener
	 * @param listener the IHighlightListener to add
	 */
	public void register(IHighlightListener listener){
		m_highlightListeners.add(listener);
	}
    
    /**
	 * give focus to certain processInstance
	 * @param processInstance the processInstance
	 */
	public void setFocus(ProcessInstance processInstance){
		for(IFocusListener focusLstr : m_focusListeners){
			focusLstr.setFocus(processInstance);
		}
	}

	/**
	 * set highlight to certain processInstance
	 *@param processInstance the processInstance
	 */
	public void setHighlight(ProcessInstance processInstance){
		for(IHighlightListener highlightLstr : m_highlightListeners){
			highlightLstr.setHighlight(processInstance);
		}
	}

    /**
	 * set highlight to certain tool instance
	 * @param toolInstance the toolInstance
	 */
    public void setHighlight(ToolInstance toolInstance){
		for(IHighlightListener highlightLstr : m_highlightListeners){
			highlightLstr.setHighlight(toolInstance);
		}
	}

    /**
	 * set highlight to certain process
	 * @param processName the name of the process
	 */
    public void setHighlightByProcessName(String processName){
		for(IHighlightListener highlightLstr : m_highlightListeners){
			highlightLstr.setHighlightByProcessName(processName);
		}
	}

    /**
	 * set highlight to certain tool
	 * @param toolName the name of the tool
	 */
    public void setHighlightByToolName(String toolName){
		for(IHighlightListener highlightLstr : m_highlightListeners){
			highlightLstr.setHighlightByToolName(toolName);
		}
	}

    /**
	 * set focus to certain tool instance
	 * @param toolInstance the toolInstance
	 */
    public void setFocus(ToolInstance toolInstance){
		for(IFocusListener focusLstr : m_focusListeners){
			focusLstr.setFocus(toolInstance);
		}
	}
}
