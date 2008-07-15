package argusviewer.toolbus;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import toolbus.StateElement;
import toolbus.commandline.CommandLine;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import toolbus.viewer.DebugToolBus;
import toolbus.viewer.IPerformanceMonitor;
import toolbus.viewer.IViewer;
import toolbus.viewer.IViewerConstants;
import toolbus.viewer.ScriptCodeStore;
import argusviewer.toolbus.sync.BreakpointSync;
import argusviewer.toolbus.sync.ControlSync;
import argusviewer.toolbus.sync.FilterSync;
import argusviewer.toolbus.sync.FocusSync;
import aterm.ATerm;

/**
 * 
 * DataComm handles connection between viewer and toolbus. 
 *
 * @author T. Van Laer
 * @author J. Wulffers
 * @author J. van den Bos  
 * @author M. van Beest
 *
 */
public final class DataComm implements IViewer, IPerformanceMonitor {
	
	private DebugToolBus m_debugToolbus;
    private ScriptCodeStore m_scriptCodeStore;
    private Thread m_toolbusThread;

	private boolean m_isToolbusRunning = false;

	private BreakpointSync m_breakPointSync;
	private FocusSync m_focusSync;
	private ControlSync m_controlSync;
	private FilterSync m_filterSync;
	
	private int	m_tick = 0;


    /**
	 * Constructor of the DataComm object. DataComm handles the connection
	 * with the toolbus.
	 * @param args The arguments to start the toolbus.
     * @throws Exception could not start the toolbus
	 */	
	public DataComm(String[] args) throws Exception {
		m_breakPointSync = new BreakpointSync(m_debugToolbus);
		m_focusSync = new FocusSync();
		m_controlSync = new ControlSync(m_debugToolbus);
		m_filterSync = new FilterSync();
		
		// The toolbus will be initialized later to resolve threading issues.
		initToolbus(args);
		
		m_scriptCodeStore = new ScriptCodeStore(m_debugToolbus);	
    }

	private void initToolbus(String[] args) throws Exception {		
		m_debugToolbus = new DebugToolBus(args, this, this);
		
		//intial state toolbus
		m_debugToolbus.doStop();
		CommandLine.createCommandLine(m_debugToolbus);
		
		try {
			
			if (m_debugToolbus.parsecup()) {		
			
				m_toolbusThread = new Thread(new Runnable() {
					public void run() {					
						m_debugToolbus.execute();
					}			
				});
				m_toolbusThread.start();
				
			} else {				
				m_debugToolbus = null;
			}
		
		} catch (Exception ex) {
			throw new Exception("Error starting ToolBus.", ex);
		}

		m_controlSync.setToolbus(m_debugToolbus);
		m_breakPointSync.setToolbus(m_debugToolbus);
	}	
	
	/**
	 * get the running thread of the toolbus.
	 * @return The thread wherein the toolbus operates
	 */
	public Thread getToolbusThread() {
		return m_toolbusThread;
	}


    /**
	 * this method is triggered when the toolbus is started.
	 */
	public void toolbusStarting() {
		m_isToolbusRunning = true;
		m_controlSync.setToolbusRunning(true);
	}

	/**
	 * this method is triggered when the toolbus is terminated.
	 */
	public void toolbusTerminating() {
		m_isToolbusRunning = false;
		m_controlSync.setToolbusRunning(false);
		updateState(IViewerConstants.READY_STATE);
	}

    /**
	 * This method is triggered by the toolbus when a new process is started.
	 * @param processInstance the processInstance that is started. 
	 */	
	public void processInstanceStarted(ProcessInstance processInstance) {
		m_controlSync.addProcessInstance(processInstance);		
	}

	/**
	 * This method is triggered by the toolbus when a process is terminated.
	 * @param processInstance the processInstance that is terminated. 
	 */
	public void processInstanceTerminated(ProcessInstance processInstance) {
		m_controlSync.removeProcessInstance(processInstance);
	}
	
    /**
     * this method is triggered by the toolbus when a new tool is connected.
     * This also starts the performance monitoring for this tool.
     * @param toolInstance the instance of the new tool
     */
    public void toolConnected(ToolInstance toolInstance) {
        m_controlSync.addToolInstance(toolInstance);
        m_debugToolbus.startMonitoringTool(toolInstance.getToolKey());
    }

    /**
     * this method is triggered by the toolbus when a tool is disconnected.
     * This also ends the performance monitoring for this tool.
     * @param toolInstance the instance of the disconnnected tool
     */
    public void toolConnectionClosed(ToolInstance toolInstance) {
        m_controlSync.removeToolInstance(toolInstance);
        m_debugToolbus.stopMonitoringTool(toolInstance.getToolKey());
    }

    /**
     * toolbus triggers this method when performance stats are ready
     * @param toolInstance the toolinstance
     * @param aTerm the a-term
     */
    public void performanceStatsArrived(ToolInstance toolInstance, ATerm aTerm) {
    	m_controlSync.updatePerformance(toolInstance, aTerm);
    }

    /**
     * get source of a specific script
	 * @param scriptName the relative path to the script
	 * @return the t-script sourcecode.
	 */
	public String getSource(String scriptName) {
        try {
            return new String(m_scriptCodeStore.getCode(scriptName));
        } catch (IOException e) {
            throw new RuntimeException("An IO error occurred.", e);
        }
    }

    /**
	 * this method is triggered by the toolbus when a step is executed
	 * @param processInstance the current active processInstance
	 * @param executedStateElement the executed state element
	 * @param partners all related processInstances
	 */
	public void stepExecuted(ProcessInstance processInstance,
			StateElement executedStateElement, ProcessInstance[] partners) {
		
		//very strange CWI state of the toolbus, ignore this and doStep.
		if (executedStateElement.getPosInfo() == null) {
			/* If the posInfo was 'null', the stateElement isn't related directly
			 * related to anything in the ToolBus script (it will be an atom that
			 * was inserted during the creation of the statemachine, by the parser).
			 * -- In this case do another step. */
			m_controlSync.doStep();
			return;
		}
		
		m_controlSync.stepExecuted(getLastTick(), processInstance, executedStateElement, partners);
		incrementTick(); // Increases tick by 1, sequence of statements is important here!
	}

	/**
	 * this method is triggered when the state of the toolbus changes.
	 * @param state the new state of the toolbus. check IViewerConstants for possible values.
	 */
	public void updateState(int state) {
		m_controlSync.setState(state);
	}


	/**
	 * get the toolbus instance itself. Actually only for debugging.
	 * @return the running toolbus.
	 */
	public DebugToolBus getToolbus() {
		return m_debugToolbus;		
	}

	/**
	 * tests if the toolbus is running.
	 * @return true if toolbus is running
	 */
	public boolean isToolbusRunning() {
		return m_isToolbusRunning;        
    }

	/**
	 * get list of all active script files
	 * @return list with relative script files
	 */
	public List<String> getScriptfiles() {
        List<String> scriptFiles = new ArrayList<String>();
        scriptFiles.addAll(Arrays.asList(m_scriptCodeStore.getScriptNames()));
        return Collections.unmodifiableList(scriptFiles);        
    }

	/**
	 * this method is triggered when the toolbus hits a process breakpoint.
	 * @param processInstance the processInstance
	 */
	public void processBreakPointHit(ProcessInstance processInstance) {
		m_breakPointSync.hitBreakpoint(processInstance);		
	}

	/**
	 * this method is triggered when the toolbus hits a source breakpoint.
	 * @param stateElement the current active stateElement
	 */
	public void sourceBreakPointHit(StateElement stateElement) {
		m_breakPointSync.hitBreakpoint(stateElement);	
	}

	/**
	 * is triggered when the toolbus hits a stateelement breakpoint.
	 * @param stateElement the current active stateElement
	 */
	public void stateElementBreakPointHit(StateElement stateElement) {
		m_breakPointSync.hitBreakpoint(stateElement);	
	}
    
    /**
     * get breakpoint synchronizer
     * @return breakpointSync
     */
    public BreakpointSync getBreakPointSync() {
    	return m_breakPointSync;
    }
    
    /**
     * get focus synchronizer
     * @return focusSync
     */
    public FocusSync getFocusSync() {
    	return m_focusSync;
    }
    
    /**
     * get control synchronizer
     * @return controlSync
     */
    public ControlSync getControlSync() {
    	return m_controlSync;
    }
    
    /**
     * get filter synchronizer
     * @return filterSync
     */
    public FilterSync getFilterSync() {
    	return m_filterSync;
    }    

    /**
     * get number of the last tick of the toolbus.
     * @return the tick number
     */
    public int getLastTick() {
		return m_tick;
	}
    
    /**
     * Increment the tick counter
     */
    private void incrementTick() {
    	m_tick++;
    }
}
