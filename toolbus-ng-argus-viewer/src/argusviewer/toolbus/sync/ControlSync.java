package argusviewer.toolbus.sync;


import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import toolbus.StateElement;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import toolbus.viewer.DebugToolBus;
import toolbus.viewer.IViewerConstants;
import argusviewer.ExceptionReporter;
import argusviewer.ExceptionReporter.ExceptionState;
import argusviewer.view.listeners.IControlListener;
import argusviewer.view.listeners.IPerformanceControlListener;
import argusviewer.view.listeners.IProcessInstanceControlListener;
import argusviewer.view.listeners.IStateControlListener;
import argusviewer.view.listeners.IToolControlListener;
import aterm.ATerm;

/**
 * 
 * Handles control of the toolbus
 * 
 * @author Tim Van Laer 
 * @author M. van Beest
 */
public class ControlSync {
	private final DebugToolBus m_debugToolBus;
	
	private final List<ProcessInstance> m_currentProcesses; //still useful??
    private final List<ToolInstance> m_currentTools;
    private final Map<ProcessInstance, String> m_processFileNames;
	
	private volatile boolean m_isToolbusRunning = false;
	private volatile boolean m_isToolbusStepRunning = false;
    private volatile int m_toolbusState = IViewerConstants.UNKNOWN_STATE;
	private volatile int m_stepRunningDelay = 0;	
	private volatile boolean m_isToolbusTerminated = false;
	
	private final ArrayList<IControlListener> m_controlListeners;
	private final ArrayList<IToolControlListener> m_toolListeners;
	private final ArrayList<IProcessInstanceControlListener> m_processInstanceListeners;
	private final ArrayList<IPerformanceControlListener> m_performanceListeners;
	private final ArrayList<IStateControlListener> m_stateListeners;
	
	/**
	 * constructor for filter synchronizator
	 * @param debugToolbus the toolbus instance
	 */
	public ControlSync(DebugToolBus debugToolbus){
		m_debugToolBus = debugToolbus;
		
		m_currentProcesses = new ArrayList<ProcessInstance>();
        m_currentTools = new ArrayList<ToolInstance>();
        m_processFileNames = new ConcurrentHashMap<ProcessInstance, String>();
        
        m_controlListeners = new ArrayList<IControlListener>();
        m_toolListeners = new ArrayList<IToolControlListener>();
        m_processInstanceListeners = new ArrayList<IProcessInstanceControlListener>();
        m_performanceListeners = new ArrayList<IPerformanceControlListener>();
        m_stateListeners = new ArrayList<IStateControlListener>();
	}
	

	/**
	 * This method triggers the run action at the toolbus. 
	 * script will run without break and history information
	 */
	public void doRun() {
		m_isToolbusStepRunning = false;
		
		doSteppingRun(0);
	}
	
	/**
	 * This method triggers the stepping run action. As soon as the step is executed at
	 * the toolbus, a new doStep is triggered. 
	 * You can specify a delay. This is the time in milliseconds, the datacomm object will 
	 * wait every cycle.
	 * @param delay delay in milliseconds
	 */
	public void doSteppingRun(int delay) {
		if (!m_isToolbusStepRunning) {
			m_isToolbusStepRunning = true;
			m_stepRunningDelay = delay;
			
			doStep();
		}
	}

	/**
	 * triggers one step at the toolbus.
	 */
	public void doStep(){
		m_debugToolBus.doStep();		
	}
	
	/**
	 * triggers steps at the toolbus
	 * @param number number of steps triggered.
	 */
	public void doStep(int number){
		for (int i = 0; i < number; i++) {
			m_debugToolBus.doStep();
		}
	}

	/**
	 * stop running or steprunning
	 */
	public void doStop(){
		m_isToolbusStepRunning = false;
		
		m_debugToolBus.doStop();
	}

	/**
	 * terminate the toolbus.
	 */
	public void doTerminate(){
		m_isToolbusStepRunning = false;
		if (!isToolbusTerminated()){
			m_debugToolBus.doTerminate();
			//m_debugToolBus = null;
		}
		
	}
	
	/**
	 * tests if the toolbus is running.
	 * @return true if toolbus is running
	 */
	public boolean isToolbusRunning(){
		return m_isToolbusRunning;        
    }
	
    /**
     * The state of the debugToolbus has changed.
     * @param state the current state of the debugToolbus.
     */
	public void setState(int state){
		m_toolbusState = state;
		for (IStateControlListener stateLstr : m_stateListeners){
			stateLstr.setState(state);
		}
	}
	

	/**
	 * get the current state of the toolbus.
	 * @return current state  check IViewerConstants for possible values.	 
	 */
	public int getState() {
		return m_toolbusState;
	}
    
	/**
	 * this method is triggered by the toolbus when a step is executed
	 * @param tick the currently executed tick at the toolbus
	 * @param processInstance the current active processInstance
	 * @param executedStateElement the executed state element
	 * @param partners all related processInstances
	 */
	public void stepExecuted(int tick, ProcessInstance processInstance, StateElement executedStateElement, ProcessInstance[] partners) {		
						
		//logic for the stepRun action
		if (m_isToolbusStepRunning) {
			if (0 < m_stepRunningDelay) {
				try {
					Thread.sleep(m_stepRunningDelay);
				} catch (InterruptedException e) { 
					// We are not interested in the InterruptedException
					ExceptionReporter.process(e, ExceptionState.IGNORED);
				}
			}
			
			m_debugToolBus.doStep();
		}
		
		for (IControlListener controlLstr : m_controlListeners) {
			controlLstr.stepExecuted(tick, processInstance, executedStateElement, partners);
		}
	}
    
    /**
     * a certain tool is updated:
     * @param toolInstance the tool that is updated.
     * @param aTerm the performance stats
     */
	public void updatePerformance(ToolInstance toolInstance, ATerm aTerm) {
		for (IPerformanceControlListener performanceLstr : m_performanceListeners) {
			performanceLstr.updatePerformance(toolInstance, aTerm);
		}
	}
    
    /**
     * Process instance is added on the toolbus
     * @param processInstance the new processInstance
     */
	public void addProcessInstance(ProcessInstance processInstance) {
		m_currentProcesses.add(processInstance);
		
		if (!processInstance.getStateElements().isEmpty()) {
			int last = processInstance.getStateElements().size() - 1;
		
			PositionInformation pi = ((StateElement) processInstance.getStateElements().toArray()[last]).getPosInfo();
			if (pi != null) {
				String filename = pi.getFileName();
				m_processFileNames.put(processInstance, filename);
			}
		}
		
		for (IProcessInstanceControlListener processInstanceLstr : m_processInstanceListeners) {
			processInstanceLstr.addProcessInstance(processInstance);
		}
	}
	
    /**
     * Process instance is removed on the toolbus
     * @param processInstance the removed processInstance
     */
	public void removeProcessInstance(ProcessInstance processInstance) {
		m_currentProcesses.remove(processInstance);		
		
		m_processFileNames.remove(processInstance);
		
		for (IProcessInstanceControlListener processInstanceLstr : m_processInstanceListeners) {
			processInstanceLstr.removeProcessInstance(processInstance);
		}
	}

    /**
     * Tool instance is added on the toolbus
     * @param toolInstance the new tool instance
     */
	public void addToolInstance(ToolInstance toolInstance) {
		m_currentTools.add(toolInstance);
		
		for (IToolControlListener toolLstr : m_toolListeners) {
			toolLstr.addToolInstance(toolInstance);
		}
	}
    /**
     * Tool instance is removed on the toolbus
     * @param toolInstance the removed tool instance
     */
	public void removeToolInstance(ToolInstance toolInstance) {
		m_currentTools.remove(toolInstance);
		
		for (IToolControlListener toolLstr : m_toolListeners) {
			toolLstr.removeToolInstance(toolInstance);
		}
	}
	
	/**
	 * set the toolbus state
	 * @param isToolbusRunning true if toolbus is running
	 */
	public void setToolbusRunning(boolean isToolbusRunning) {
		m_isToolbusRunning = isToolbusRunning;
		if (!m_isToolbusRunning) {
			m_isToolbusTerminated = true;
		}
	}
    
    /**
	 * get a list of all active processes.
	 * @return active processes.
	 */
	public List<ProcessInstance> getProcesses() {
		if (!isToolbusTerminated()) {
			return m_debugToolBus.getProcesses();
		}
		
		// toolbus is not active, so we return an empty processlist.
		// if we ask the toolbus for processes, we get the last active processes
		// even when the toolbus is not active.
		return new ArrayList<ProcessInstance>();
	}

    /**
	 * get all connected tools from the toolbus
	 * @return connected tools.
	 */
	public List<ToolInstance> getTools() {
        return m_currentTools;
    }


    /**
     * get the delay in milliseconds for the toolbus step run action.
     * this delay is the time the toolbus waits before continue with next step.
     * @return the delay in millisecs.
     */
    public int getSteppingDelay() {
		return m_stepRunningDelay;
	}
    
    /**
     * Sets the set run action delay in milliseconds. This delay is the time
     * the toolbus waits before it continues to the next step.
     * @param delay The delay in millisecs.
     */
    public void setSteppingDelay(int delay) {
    	m_stepRunningDelay = delay;
    }
    
	/**
	 * checks if toolbus is terminated
	 * @return true if toolbus is terminated
	 */
	public boolean isToolbusTerminated() {
		return m_isToolbusTerminated;
	}
	
	/**
	 * @param listener register this listener
	 */
	public void register(IControlListener listener) {
		m_controlListeners.add(listener);
	}

	/**
	 * @param listener register this listener
	 */
	public void register(IToolControlListener listener) {
		m_toolListeners.add(listener);
	}

	/**
	 * @param listener register this listener
	 */
	public void register(IProcessInstanceControlListener listener) {
		m_processInstanceListeners.add(listener);
	}

	/**
	 * @param listener register this listener
	 */
	public void register(IPerformanceControlListener listener) {
		m_performanceListeners.add(listener);
	}

	/**
	 * @param listener register this listener
	 */
	public void register(IStateControlListener listener) {
		m_stateListeners.add(listener);
	}

	/**
	 * @return true if toolbus is in step-running mode
	 */
	public boolean isToolbusStepRunning() {
		return m_isToolbusStepRunning;
	}
}
