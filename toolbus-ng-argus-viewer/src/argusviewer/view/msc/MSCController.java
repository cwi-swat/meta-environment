package argusviewer.view.msc;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import prefuse.activity.Activity;
import prefuse.data.Tuple;
import prefuse.visual.VisualItem;
import toolbus.StateElement;
import toolbus.atom.Atom;
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
import argusviewer.util.ArgusSettings;
import argusviewer.util.ToolbusUtil;
import argusviewer.view.listeners.IControlListener;
import argusviewer.view.listeners.IFocusListener;
import argusviewer.view.listeners.IHighlightListener;
import argusviewer.view.listeners.IProcessFilterListener;
import argusviewer.view.listeners.IProcessInstanceControlListener;
import argusviewer.view.listeners.IToolControlListener;
import argusviewer.view.listeners.IToolFilterListener;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.MSCData;
import argusviewer.view.msc.data.Message;
import argusviewer.view.msc.data.Statement;
import argusviewer.view.msc.visual.MSCVisualization;

/**
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Arne Timmerman
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author Alexander Bij
 * @author Roberto vd Linden
 */
public class MSCController implements IControlListener, IToolControlListener,
		IProcessInstanceControlListener, IProcessFilterListener,
		IToolFilterListener, IFocusListener, IHighlightListener {

	private DataComm m_dataCommunication;
	private MSCData m_mscData;
	private MSCVisualization m_mscVisualization;
	private MSCView m_mscView;
	private MSCVisualizationThread m_mscVisualizationThread;

	private int m_latestTick = -1;
	private Tuple m_latestAddedStatement = null;

	private static final int FIRST_TICK = -2;
	private static final HashMap<Class< ? extends Atom>, Entity.Type> SOURCE_OF_STATEMENT;

	static {
		SOURCE_OF_STATEMENT = new HashMap<Class< ? extends Atom>, Entity.Type>();
		SOURCE_OF_STATEMENT.put(Connect.class, Entity.Type.TOOL);
		SOURCE_OF_STATEMENT.put(DisConnect.class, Entity.Type.TOOL);
		SOURCE_OF_STATEMENT.put(RecVal.class, Entity.Type.TOOL);
		SOURCE_OF_STATEMENT.put(Event.class, Entity.Type.TOOL);
		SOURCE_OF_STATEMENT.put(RecPerfStats.class, Entity.Type.TOOL);

		SOURCE_OF_STATEMENT.put(Execute.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(Terminate.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(Eval.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(AckEvent.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(Do.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(SndKill.class, Entity.Type.PROCESS);
		SOURCE_OF_STATEMENT.put(GetPerfStats.class, Entity.Type.PROCESS);
	}

	/**
	 * Create a controller for the Message Sequence Chart. The controller
	 * synchronizes between ToolBus dataCommunication, the data model,
	 * visualization and view of the Message Sequence Chart.
	 * 
	 * @param dataCommunication
	 *            communication protocol for connection to ToolBus
	 * @param mscData
	 *            data model for the Message Sequence Chart
	 * @param mscVisualisation
	 *            visualization of the data model
	 * @param mscView
	 *            view on the visualization of the Message Sequence Chart
	 */
	public MSCController(DataComm dataCommunication, MSCData mscData,
			MSCVisualization mscVisualisation, MSCView mscView) {

		this.m_dataCommunication = dataCommunication;
		this.m_mscData = mscData;
		this.m_mscVisualization = mscVisualisation;
		this.m_mscView = mscView;

		this.m_mscVisualizationThread = new MSCVisualizationThread(this,
				m_mscVisualization.getVisualization());

		m_dataCommunication.getControlSync().register((IControlListener) this);
		m_dataCommunication.getControlSync().register(
				(IToolControlListener) this);
		m_dataCommunication.getControlSync().register(
				(IProcessInstanceControlListener) this);
		m_dataCommunication.getFilterSync().register(
				(IProcessFilterListener) this);
		m_dataCommunication.getFilterSync()
				.register((IToolFilterListener) this);
		m_dataCommunication.getFocusSync().register((IFocusListener) this);
		m_dataCommunication.getFocusSync().register((IHighlightListener) this);

		populateEntitiesList();
	}

	/**
	 * Create a controller for the Message Sequence Chart for test purposes.
	 * 
	 * @param mscData
	 *            data model for the Message Sequence Chart
	 * @param mscVisualisation
	 *            visualization of the data model
	 * @param mscView
	 *            view on the visualization of the Message Sequence Chart
	 * @param startVisualization
	 *            set this parameter to true to start the visualization thread
	 */
	protected MSCController(MSCData mscData, MSCVisualization mscVisualisation,
			MSCView mscView, boolean startVisualization) {
		this.m_mscData = mscData;
		this.m_mscVisualization = mscVisualisation;
		this.m_mscView = mscView;

		if (startVisualization) {
			this.m_mscVisualizationThread = new MSCVisualizationThread(this,
					m_mscVisualization.getVisualization());
		}
	}

	/**
	 * Get the Thread that handles the visualization of the contents on the
	 * Message Sequence Chart.
	 * 
	 * @return the visualization thread of the Message Sequence Chart
	 */
	public MSCVisualizationThread getVisualizationThread() {
		return m_mscVisualizationThread;
	}

	/**
	 * Setter made for testing purposes. Sets the {@link MSCVisualizationThread}.
	 * 
	 * @param visualisationThread
	 *            The {@link MSCVisualizationThread}.
	 */
	protected void setSynchronizationThread(
			MSCVisualizationThread visualisationThread) {
		m_mscVisualizationThread = visualisationThread;
	}

	/**
	 * This function processes the visualization redrawing, by running all the
	 * actions that are attached to the visualization.
	 */
	public void processVisualization() {
		Activity activity = m_mscVisualization.refreshVisualization();
		activity.addActivityListener(m_mscVisualizationThread);
	}

	/**
	 * This function is notified by the visualization thread that the
	 * visualization is finished. The display in the MSCView should be
	 * refreshed.
	 */
	public void visualizationFinished() {
		m_mscView.refreshDisplays();

		// Set focus to the latest statement added, if enabled
		if (isStatementFocusEnabled() && (m_latestAddedStatement != null)) {
			VisualItem visualStatement = m_mscVisualization
					.getVisibleStatement(m_latestAddedStatement);
			if (visualStatement != null) {
				m_mscView.setStatementFocus(visualStatement);
				m_latestAddedStatement = null;
			}
		}
	}

	/**
	 * Refresh the visualization of the Message Sequence Chart.
	 */
	protected void refreshVisualization() {
		m_mscVisualizationThread.receivedWork();
	}

	/**
	 * Get all the processes and tools currently running from the toolbus.
	 */
	private void populateEntitiesList() {

		for (ProcessInstance process : m_dataCommunication.getControlSync()
				.getProcesses()) {
			m_mscData.addEntity(new Entity(process.getProcessId(), process
					.getProcessName(), Entity.Type.PROCESS, true, FIRST_TICK));
		}

		for (ToolInstance tool : m_dataCommunication.getControlSync()
				.getTools()) {
			m_mscData.addEntity(new Entity(tool.getToolKey()
					.getUniqueIdentifier(), tool.getToolName(),
					Entity.Type.TOOL, true, FIRST_TICK));
		}

		m_mscData.addEntity(new Entity("Sink", Entity.Type.SINK));
		m_mscData.addEntity(new Entity("Sink", Entity.Type.SINK));
		refreshVisualization();
	}

	/**
	 * Add an executed statement to the Message Sequence Chart.
	 * 
	 * @param tick
	 *            The timetick indicating when the statement was executed
	 * @param processInstance
	 *            The process instance which executed the statement
	 * @param executedStateElement
	 *            The statement that was executed
	 * @param partners
	 *            In case of a message, this shows the receiving process or tool
	 *            instances
	 */
	public void stepExecuted(int tick, ProcessInstance processInstance,
			StateElement executedStateElement, ProcessInstance[] partners) {

		m_latestTick = tick;

		String executingProcessId = processInstance.getProcessName()
				+ processInstance.getProcessId();
		String executedStatementContent = executedStateElement.toString();

		Message.Type msgType = getMessageType(executedStateElement);

		if (msgType == null) {
			addStatement(executingProcessId, executedStatementContent);
		} else {
			switch (msgType) {
			case ASYNC:
				addProcessMessage(executingProcessId, executedStatementContent,
						partners, Message.Type.ASYNC);
				break;
			case SYNC:
				addProcessMessage(executingProcessId, executedStatementContent,
						partners, Message.Type.SYNC);
				break;
			case TOOLCOMM:
				addToolMessage(executingProcessId, executedStateElement);
				break;
			default:
				addStatement(executingProcessId, executedStatementContent);
				break;
			}
		}
	}

	/**
	 * Determine the type of message this StateElement represents
	 * 
	 * @param statement
	 *            The StateElement to check
	 * @return The type of Message, or null if the stateElement does not
	 *         represent a Message
	 */
	protected Message.Type getMessageType(StateElement statement) {
		Class< ? extends StateElement> statementClass = statement.getClass();

		if (Statement.SYNC_COMMUNICATION.contains(statementClass)) {
			return Message.Type.SYNC;
		} else if (Statement.ASYNC_COMMUNICATION.contains(statementClass)) {
			return Message.Type.ASYNC;
		} else if (Statement.TOOL_COMMUNICATION.contains(statementClass)) {
			return Message.Type.TOOLCOMM;
		}

		return null;
	}

	/**
	 * Add a new message that has been send between processes to the Message
	 * Sequence Chart.
	 * 
	 * @param executingProcessId
	 *            the Id of the Process that executed the statement
	 * @param executedStatementContent
	 *            the content of the executed statement
	 * @param destinationProcesses
	 *            the Process instances that receive the message.
	 * @param messageType
	 *            the type of the message, i.e. Message.Type.SYNC
	 */
	protected void addProcessMessage(String executingProcessId,
			String executedStatementContent,
			ProcessInstance[] destinationProcesses, Message.Type messageType) {

		ArrayList<String> destinationProcessIds = new ArrayList<String>();
		if (destinationProcesses != null) {
			for (ProcessInstance destinationProcess : destinationProcesses) {
				String destinationProcessId = destinationProcess
						.getProcessName()
						+ destinationProcess.getProcessId();
				destinationProcessIds.add(destinationProcessId);
			}
		}

		addMessage(executingProcessId, executedStatementContent,
				destinationProcessIds, messageType);
	}

	/**
	 * Add a new tool message to the Message Sequence Chart. This message is
	 * received or send by the given process.
	 * 
	 * @param processId
	 *            the Id of the process that has send or received the message
	 * @param executedStateElement
	 *            the executed statement that send or received the message
	 */
	protected void addToolMessage(String processId,
			StateElement executedStateElement) {
		String toolId = ToolbusUtil.getToolIdFromStateElement(executedStateElement);
		if (toolId == null) {
			return;
		}

		// Determine the sender and receiver of the message
		ArrayList<String> destinationId = new ArrayList<String>();
		Entity.Type sourceType = SOURCE_OF_STATEMENT.get(executedStateElement
				.getClass());
		String sourceId;

		if (sourceType == Entity.Type.TOOL) {
			sourceId = toolId;
			destinationId.add(processId);
		} else {
			sourceId = processId;
			destinationId.add(toolId);
		}

		String executedStatementContent = executedStateElement.toString();
		addMessage(sourceId, executedStatementContent, destinationId,
				Message.Type.TOOLCOMM);
	}

	/**
	 * Add a new message to the Message Sequence Chart. This method also adds
	 * the executing statement that sends the message.
	 * 
	 * @param executingEntityId
	 *            the Id of the Entity that executed the statement
	 * @param executedStatementContent
	 *            the content of the executed statement
	 * @param messageDestinationIds
	 *            the Ids of the Entities that receive the message
	 * @param messageType
	 *            the type of the message, i.e. Message.Type.TOOL
	 */
	protected void addMessage(String executingEntityId,
			String executedStatementContent,
			ArrayList<String> messageDestinationIds, Message.Type messageType) {

		if (messageDestinationIds != null) {
			String messageContents = ToolbusUtil
					.getMessageFromStateElement(executedStatementContent);
			Message message = new Message(messageContents, m_latestTick,
					messageDestinationIds, messageType);
			m_mscData.addMessage(message);
		}

		addStatement(executingEntityId, executedStatementContent);
	}

	/**
	 * Add a new statement to the Message Sequence Chart.
	 * 
	 * @param executingEntityId
	 *            the Id of the Entity that executed the statement
	 * @param executedStatementContent
	 *            the content of the executed statement
	 */
	protected void addStatement(String executingEntityId,
			String executedStatementContent) {
		Statement executedStatement = new Statement(executedStatementContent,
				executingEntityId, m_latestTick);
		m_latestAddedStatement = m_mscData.addStatement(executedStatement);

		refreshVisualization();
	}

	/**
	 * Add a new process instance to the Message Sequence Chart.
	 * 
	 * @param processInstance
	 *            The process instance to be added to the MSC
	 */
	public void addProcessInstance(ProcessInstance processInstance) {
		m_mscData.addEntity(new Entity(processInstance.getProcessId(),
				processInstance.getProcessName(), Entity.Type.PROCESS, true,
				m_latestTick));

		refreshVisualization();
	}

	/**
	 * Add a new tool instance to the Message Sequence Chart.
	 * 
	 * @param toolInstance
	 *            The tool instance to be added to the MSC
	 */
	public void addToolInstance(ToolInstance toolInstance) {
		int toolId = toolInstance.getToolID();
		String toolName = toolInstance.getToolName();
		Entity.Type type = Entity.Type.TOOL;
		Entity toolEntity = new Entity(toolId, toolName, type, true, m_latestTick);

		m_mscData.addEntity(toolEntity);
		refreshVisualization();
	}

	/**
	 * {@inheritDoc}
	 */
	public void setProcessFilter(List<ProcessInstance> filteredProcesses) {
		m_mscVisualization.setVisibleProcesses(filteredProcesses);
		refreshVisualization();
	}

	/**
	 * {@inheritDoc}
	 */
	public void setToolFilter(List<ToolInstance> filteredTools) {
		m_mscVisualization.setVisibleTools(filteredTools);
		refreshVisualization();
	}

	/**
	 * 'Remove' the processInstance from the dataset by marking it as terminated
	 * 
	 * @param processInstance
	 *            The processInstance to be 'removed'
	 */
	public void removeProcessInstance(ProcessInstance processInstance) {
		int processId = processInstance.getProcessId();
		m_mscVisualization.setEntityTerminated(m_latestTick,
				Entity.Type.PROCESS, processId);
		refreshVisualization();
	}

	/**
	 * Remove the toolInstance from the dataset by marking it as 'terminated'
	 * 
	 * @param toolInstance
	 *            The processInstance to be 'removed'
	 */
	public void removeToolInstance(ToolInstance toolInstance) {
		int toolId = toolInstance.getToolID();
		m_mscVisualization.setEntityTerminated(m_latestTick, Entity.Type.TOOL, toolId);
		refreshVisualization();
	}

	/**
	 * {@inheritDoc}
	 */
	public void setFocus(ProcessInstance processInstance) {
		int processId = processInstance.getProcessId();
		setEntityFocus(Entity.Type.PROCESS, processId);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setFocus(ToolInstance toolInstance) {
		int toolId = toolInstance.getToolID();
		setEntityFocus(Entity.Type.TOOL, toolId);
	}

	/**
	 * Set focus to the Entity with the given properties.
	 * 
	 * @param entityType
	 *            the type of the Entity, i.e. Entity.Type.TOOL
	 * @param entityId
	 *            the unique identifies of the Entity (per type)
	 */
	protected void setEntityFocus(Entity.Type entityType, int entityId) {
		VisualItem visualEntity = m_mscVisualization.getVisibleEntity(
				entityType, entityId);
		if (visualEntity != null) {
			m_mscView.setEntityFocus(visualEntity);
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void setHighlight(ProcessInstance processInstance) {
		int processId = processInstance.getProcessId();
		m_mscVisualization.setEntityHighlight(Entity.Type.PROCESS, processId);
		refreshVisualization();
	}

	/**
	 * {@inheritDoc}
	 */
	public void setHighlight(ToolInstance toolInstance) {
		if (toolInstance != null) {
			int toolId = toolInstance.getToolID();
			m_mscVisualization.setEntityHighlight(Entity.Type.TOOL, toolId);
			refreshVisualization();
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void setHighlightByProcessName(String processName) {
		m_mscVisualization.setEntityHighlight(Entity.Type.PROCESS, processName);
		refreshVisualization();
	}

	/**
	 * {@inheritDoc}
	 */
	public void setHighlightByToolName(String toolName) {
		m_mscVisualization.setEntityHighlight(Entity.Type.TOOL, toolName);
		refreshVisualization();
	}

	/**
	 * Check if the automatic statement focus is enabled. This setting is stored
	 * in the settings file.
	 * 
	 * @return true if automatic statement focus is enabled, else false
	 */
	protected boolean isStatementFocusEnabled() {
		ArgusSettings settings = ArgusSettings.getInstance();
		String focusSetting = settings.getAttributeValue("MSC",
				"statementFocus", "false");
		return focusSetting.equals("true");
	}

}
