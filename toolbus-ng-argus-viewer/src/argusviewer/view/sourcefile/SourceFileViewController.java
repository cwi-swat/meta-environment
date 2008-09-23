package argusviewer.view.sourcefile;

import java.awt.Container;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Observable;

import toolbus.StateElement;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.ExceptionReporter;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.listeners.IBreakPointHitListener;
import argusviewer.view.listeners.IControlListener;
import argusviewer.view.listeners.IFileBreakPointListener;
import argusviewer.view.listeners.IFocusListener;

/**
 * Controls different script-files with their panels used by the toolbus.
 * @author Qais & Bas
 * @author M. van Beest
 * @author J. van den Bos
 * @author John Franse
 * @author Tigran Kalaidjan
 * 
 */
public class SourceFileViewController extends Observable implements IView, IControlListener, IFileBreakPointListener, IBreakPointHitListener, IFocusListener {
	private final Map<String, SourceFilePanel> m_sourceCodeTabs; 	//m_sourceCodeTabs contains a table scripts and panels
	private final DataComm dataComm;
	private volatile boolean m_processBreakpointHit;
	private volatile boolean m_sourceBreakpointHit;

	/**
	 * Constructs the sourceViewController and initialize an table (m_sourceCodeTabs) of scripts and panels
	 * @param dataComm	the DataComm object used for communication with the ToolBus. This value can't be null.
	 */
	public SourceFileViewController(DataComm dataComm) {
		this.dataComm = dataComm;
		
		registerWithDataComm();
		
		m_sourceCodeTabs = new HashMap<String, SourceFilePanel>();	
		
		m_processBreakpointHit = false;
		m_sourceBreakpointHit = false;
		
		try {
			updateView();
		} catch (RuntimeException e) {
			// TODO This should never occur; probably due to a concurrency problem.
			ExceptionReporter.process(e, ExceptionReporter.ExceptionState.UNRECOVERABLE);
		}
	}

	/**
	 * fills the m_sourceCodeTabs with all scriptfiles and creates appropriate panels 
	 * {@inheritDoc}
	 */
	public void updateView(){		
		List<String> scriptNames = dataComm.getScriptfiles();
		
		for(String scriptName : scriptNames){
			synchronized(m_sourceCodeTabs){
				if(!m_sourceCodeTabs.containsKey(scriptName)){							
					createNewSourceTab(scriptName); 
				}
			}
		}		
	}	

	/**
	 * show the script file with the line number where step has been executed 
	 * {@inheritDoc}
	 */
	public void setFocus(ProcessInstance processInstance) {		
		PositionInformation posInfo = processInstance.getProcessDefinition().getPosInfo(); 
		String scriptName = posInfo.getFileName();
		int beginLine = posInfo.getBeginLine();
		synchronized(m_sourceCodeTabs){
			if(m_sourceCodeTabs.containsKey(scriptName)){
				m_sourceCodeTabs.get(scriptName).setVisible(true);
				m_sourceCodeTabs.get(scriptName).scrollToLine(beginLine, true);
				setChanged();
				notifyObservers(getScriptNameFromFileName(scriptName));
			}
		}
	}

	/**
	 * add breakpoint to a script file
	 * {@inheritDoc}
	 */
	public void addBreakpoint(String fileName, int lineNumber) {
		synchronized(m_sourceCodeTabs){
			if (m_sourceCodeTabs.containsKey(fileName)) {
				m_sourceCodeTabs.get(fileName).addBreakPoint(lineNumber);
			}
		}
	}

	/**
	 * remove a breakpoint from scriptfile
	 * {@inheritDoc}
	 */
	public void removeBreakpoint(String fileName, int lineNumber) {
		synchronized(m_sourceCodeTabs){
			if(m_sourceCodeTabs.containsKey(fileName)){
				m_sourceCodeTabs.get(fileName).removeBreakPoint(lineNumber);
				m_sourceCodeTabs.get(fileName).removeAllLineSelection();
			}
		}
	}

	/**
	 * scroll to line where  step has been executed
	 * {@inheritDoc}
	 */
	public void stepExecuted(int tick, ProcessInstance processInstance, StateElement executedStateElement, ProcessInstance[] partners){		
		// ignore this, line is already highlighted
		if(m_sourceBreakpointHit){
			m_sourceBreakpointHit = false;
			return;
		} 
						
		clearAllHighlights();

		if(!dataComm.getControlSync().isToolbusStepRunning()){
			String scriptName = executedStateElement.getPosInfo().getFileName();
			
			synchronized(m_sourceCodeTabs){
				if(m_sourceCodeTabs.containsKey(scriptName)){
					SourceFilePanel panel = m_sourceCodeTabs.get(scriptName);
					
					int beginLine = executedStateElement.getPosInfo().getBeginLine();
					int endLine = executedStateElement.getPosInfo().getEndLine();
					
					// a step is executed at a reached process breakpoint
					if (m_processBreakpointHit){
						panel.setBreakpointLineSelection(beginLine, endLine);
						m_processBreakpointHit = false;
					}else{
						// a step is executed without a reached breakpoint
						panel.setStepLineSelection(beginLine, endLine);
					}
								
					panel.scrollToLine(beginLine, false);
					setChanged();
					notifyObservers(getScriptNameFromFileName(scriptName));
				}
			}
		}		
	}

	/**
	 * Scroll to the line of the breakpoint, and set the selection 
	 * {@inheritDoc}
	 */
	public void hitBreakpoint(ProcessInstance processInstance) {		
		m_processBreakpointHit = true;
		dataComm.getControlSync().doStop();
	}

	/**
	 * scroll to line number of the breakpoint 
	 * {@inheritDoc}
	 */
	public void hitBreakpoint(StateElement stateElement) {	
		m_sourceBreakpointHit = true;
		
		clearAllHighlights();
		
		String scriptName = stateElement.getPosInfo().getFileName();
		
		synchronized(m_sourceCodeTabs){
			if(m_sourceCodeTabs.containsKey(scriptName)){
				int beginLine = stateElement.getPosInfo().getBeginLine();
				int endLine = stateElement.getPosInfo().getEndLine();
				
				m_sourceCodeTabs.get(scriptName).setBreakpointLineSelection(beginLine, endLine);
				m_sourceCodeTabs.get(scriptName).scrollToLine(beginLine, false);
				setChanged();
				notifyObservers(getScriptNameFromFileName(scriptName));
			}
		}
		
		//halt the execution of the script and allow for manual stepping
		dataComm.getControlSync().doStop();
	}
	
	/** 
	 * {@inheritDoc}
	 */
	public HashMap<String, Container> getVisualComponents(){
		HashMap<String, Container> nameContainerHashMap = new HashMap<String, Container>();
		
		synchronized(m_sourceCodeTabs){
			for(String fileNameKey : m_sourceCodeTabs.keySet()){
			   String scriptName = getScriptNameFromFileName(fileNameKey);
			   Container sourceFilePanel = m_sourceCodeTabs.get(fileNameKey);
			   nameContainerHashMap.put(scriptName, sourceFilePanel);
			}
		}
		return nameContainerHashMap;		
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPreferredPosition() {
		return "DownRight";
	}

	/**
	 * {@inheritDoc}
	 */
	public void setFocus(ToolInstance toolInstance) {
		// TODO Auto-generated method stub
		
	}

	/**
	 * {@inheritDoc}
	 */
	public String getPluginName() {
		return "Source File View";
	}

	/**
	 * Register the SourceFileViewController with various datacomm syncronization systems to
	 * get callbacks to the interface functions.
	 * @param dataComm the DataComm object used for communication with the ToolBus
	 */
	private void registerWithDataComm() {
		dataComm.getBreakPointSync().register((IFileBreakPointListener) this);
		dataComm.getBreakPointSync().register((IBreakPointHitListener) this);
		dataComm.getControlSync().register(this);
		dataComm.getFocusSync().register(this);
	}
	
	/**
	 * Removes the path information from a filename and returns the name of the script
	 * including its extension
	 * 
	 * @param fullScriptName the full name of the script, including its path information
	 * @return the name of the script, including its extension.
	 */
	private String getScriptNameFromFileName(String fullScriptName) {
		return fullScriptName.substring(fullScriptName.lastIndexOf("/") + 1, fullScriptName.length());
	}
	
	/**
	 * Creates a new SourceCodeTab from a scriptname. This is newly created tab will not be displayed
	 * until it is retrieved by the rootviewgui.
	 * 
	 * @param scriptName
	 */
	private void createNewSourceTab(String scriptName) {
		String sourceCode = dataComm.getSource(scriptName);
		
		SourceFilePanel newSourceFilePanel = new SourceFilePanel(dataComm, scriptName, sourceCode);
		synchronized(m_sourceCodeTabs){
			m_sourceCodeTabs.put(scriptName, newSourceFilePanel);
		}
	}
	
	/**
	 * Clears all highlights in the sourcecodetabs.
	 */
	private void clearAllHighlights(){
		synchronized(m_sourceCodeTabs){
			for(SourceFilePanel panel : m_sourceCodeTabs.values()){
				panel.removeAllLineSelection();
			}
		}
	}
}
