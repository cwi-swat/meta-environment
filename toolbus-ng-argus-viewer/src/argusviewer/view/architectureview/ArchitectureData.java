package argusviewer.view.architectureview;

import java.util.Iterator;

import org.apache.log4j.Logger;

import prefuse.data.Table;
import prefuse.data.Tuple;
import prefuse.data.expression.parser.ExpressionParser;
import prefuse.data.tuple.TupleSet;

/**
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 *
 */
public class ArchitectureData {
	private static Logger log = Logger.getLogger(ArchitectureData.class);
	private Table m_toolbusSingleton;
	private Table m_processes;
	private Table m_tools;
	private Table m_messages;
		
	/**
	 * Default constructor.
	 */
	public ArchitectureData() {
		initializeTables();
	}
		
	/**
	 * Gets the Processes table.
	 * 
	 * @return The Processes table
	 */
	public Table getProcessesTable() {
		return m_processes;
	}
	
	/**
	 * gets the toolbussingleton
	 * @return the toolbus singleton table
	 */
	public Table getToolbusSingletonTable() {
		return m_toolbusSingleton;
	}
	
	/**
	 * Gets the Tools table.
	 * @return The Tools Table
	 */
	public Table getToolsTable() {
		return m_tools;
	}

	/**
	 * Add a new process to the Process table. 
	 * 
	 * @param process The process to add
	 * @return The Tuple that has been added to the Process table, or null if Process already exists
	 */
	public Tuple addProcess(Process process) {
		Tuple processTuple = null;
		
		String processName = process.getString(Process.PROCESS_FIELDNAME);
		for (int i = 0; i < m_processes.getTupleCount(); i++) {
			Tuple tuple = m_processes.getTuple(i);
			String name = tuple.getString(Process.PROCESS_FIELDNAME);
			if (name.equals(processName)) {
				return null; // Already exists
			}
		}

		processTuple = m_processes.addTuple(process); 
		return processTuple;
	}

	/**
	 * add function for the toolbus singleton. fastly hacked the same was the toolbussingleton has been hacked.
	 * @param tb the toolbus singleton
	 * @return null when it exists, the toolbus singleton tuple otherwise.
	 */
	public Tuple addToolbusSingleton(ToolbusSingleton tb) {
		Tuple singleton = null;
		singleton = m_toolbusSingleton.addTuple(tb);
		return singleton;
		
	}
	
	/**
	 * add a tool to the data
	 * @param tool instance of a tool the tool to add.
	 * @return the tuple the tool add created.
	 */
	public Tuple addTool(Tool tool) {
		Tuple toolTuple = null;
		
		String toolName = tool.getString(Tool.TOOL_FIELDNAME);
		for (int i = 0; i < m_tools.getTupleCount(); i++) {
			Tuple tuple = m_tools.getTuple(i);
			String name = tuple.getString(Tool.TOOL_FIELDNAME);
			if (name.equals(toolName)) {
				log.debug("addTool: Tool already exists");
				return null; // Already exists
			}
		}
		log.debug("addTool: Tool doesn't exists so it should be created");
		toolTuple = m_tools.addTuple(tool);
		log.debug(toolTuple);
		
		return toolTuple;
	}
	
	private void initializeTables() {
		m_processes = Process.TABLE_SCHEMA.instantiate();
		m_tools = Tool.TABLE_SCHEMA.instantiate();
		m_messages = Message.TABLE_SCHEMA.instantiate();
		m_toolbusSingleton = ToolbusSingleton.TABLE_SCHEMA.instantiate();
		log.debug("tables initialized.");
	}

	/**
	 * Checks if a message with the same source and target
	 * already exists in the table
	 * @param message The Message to be added
	 */
	public void addMessage(Message message) {
		String searchPredicateText = Message.SOURCENAME_FIELDNAME 
									+ " == '" + message.get(Message.SOURCENAME_FIELDNAME) 
									+ "' && " + Message.SOURCETYPE_FIELDNAME 
									+ " == '" + message.get(Message.SOURCETYPE_FIELDNAME) + "'";

		Iterator<Tuple> sourceTuples = m_messages.tuples(ExpressionParser.predicate(searchPredicateText));
		boolean alreadyInList = false;
		while (sourceTuples.hasNext()) {
			Tuple tup = sourceTuples.next();
			if (tup.get(Message.SOURCENAME_FIELDNAME).equals(tup.get(Message.TARGETNAME_FIELDNAME))) {
				alreadyInList = true;
				break;
			}			
			if (tup.get(Message.TARGETNAME_FIELDNAME).equals(message.get(Message.TARGETNAME_FIELDNAME))
					&& tup.get(Message.TARGETTYPE_FIELDNAME).equals(message.get(Message.TARGETTYPE_FIELDNAME))) {
				alreadyInList = true;
				break;
			}	
		}
		if (!alreadyInList) {
			m_messages.addTuple(message);
		}
	}

	/**
	 * Returns the message table
	 * @return TupleSet MessageTable
	 */
	public TupleSet getMessageTable() {
		return m_messages;
	}
}
