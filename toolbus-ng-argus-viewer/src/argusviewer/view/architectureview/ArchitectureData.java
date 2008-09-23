package argusviewer.view.architectureview;

import java.util.Iterator;

import prefuse.Visualization;
import prefuse.data.Table;
import prefuse.data.Tuple;
import prefuse.data.expression.parser.ExpressionParser;
import prefuse.data.tuple.TupleSet;

/**
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 */
public class ArchitectureData {
	private final Table toolbusSingleton;
	private final Table processes;
	private final Table tools;
	private final Table messages;
	
	private final Visualization archVisualization;
	
	/**
	 * Default constructor.
	 */
	public ArchitectureData(Visualization archVisualization){
		this.archVisualization = archVisualization;
		
		processes = Process.TABLE_SCHEMA.instantiate();
		tools = Tool.TABLE_SCHEMA.instantiate();
		messages = Message.TABLE_SCHEMA.instantiate();
		toolbusSingleton = ToolbusSingleton.TABLE_SCHEMA.instantiate();
	}
	
	/**
	 * Gets the Processes table.
	 * 
	 * @return The Processes table
	 */
	public Table getProcessesTable() {
		return processes;
	}
	
	/**
	 * gets the toolbussingleton
	 * @return the toolbus singleton table
	 */
	public Table getToolbusSingletonTable() {
		return toolbusSingleton;
	}
	
	/**
	 * Gets the Tools table.
	 * @return The Tools Table
	 */
	public Table getToolsTable() {
		return tools;
	}

	/**
	 * Add a new process to the Process table. 
	 * 
	 * @param process The process to add
	 * @return The Tuple that has been added to the Process table, or null if Process already exists
	 */
	public Tuple addProcess(Process process){
		synchronized(archVisualization){
			String processName = process.getString(Process.PROCESS_FIELDNAME);
			for (int i = 0; i < processes.getTupleCount(); i++) {
				Tuple tuple = processes.getTuple(i);
				String name = tuple.getString(Process.PROCESS_FIELDNAME);
				if (name.equals(processName)) {
					return null; // Already exists
				}
			}
	
			Tuple processTuple = processes.addTuple(process); 
			return processTuple;
		}
	}

	/**
	 * add function for the toolbus singleton. fastly hacked the same was the toolbussingleton has been hacked.
	 * @param tb the toolbus singleton
	 * @return null when it exists, the toolbus singleton tuple otherwise.
	 */
	public Tuple addToolbusSingleton(ToolbusSingleton tb){
		synchronized(archVisualization){
			Tuple singleton = null;
			singleton = toolbusSingleton.addTuple(tb);
			return singleton;
		}
	}
	
	/**
	 * add a tool to the data
	 * @param tool instance of a tool the tool to add.
	 * @return the tuple the tool add created.
	 */
	public Tuple addTool(Tool tool){
		synchronized(archVisualization){
			String toolName = tool.getString(Tool.TOOL_FIELDNAME);
			for (int i = 0; i < tools.getTupleCount(); i++) {
				Tuple tuple = tools.getTuple(i);
				String name = tuple.getString(Tool.TOOL_FIELDNAME);
				if (name.equals(toolName)) {
					return null; // Already exists
				}
			}
			Tuple toolTuple = tools.addTuple(tool);
			
			return toolTuple;
		}
	}

	/**
	 * Checks if a message with the same source and target
	 * already exists in the table
	 * @param message The Message to be added
	 */
	public void addMessage(Message message){
		synchronized(archVisualization){
			String searchPredicateText = Message.SOURCENAME_FIELDNAME 
										+ " == '" + message.get(Message.SOURCENAME_FIELDNAME) 
										+ "' && " + Message.SOURCETYPE_FIELDNAME 
										+ " == '" + message.get(Message.SOURCETYPE_FIELDNAME) + "'";
	
			Iterator<Tuple> sourceTuples = messages.tuples(ExpressionParser.predicate(searchPredicateText));
			boolean alreadyInList = false;
			while(sourceTuples.hasNext()){
				Tuple tup = sourceTuples.next();
				if(tup.get(Message.SOURCENAME_FIELDNAME).equals(tup.get(Message.TARGETNAME_FIELDNAME)) || (tup.get(Message.TARGETNAME_FIELDNAME).equals(message.get(Message.TARGETNAME_FIELDNAME)) && tup.get(Message.TARGETTYPE_FIELDNAME).equals(message.get(Message.TARGETTYPE_FIELDNAME)))) {
					alreadyInList = true;
					break;
				}	
			}
			if(!alreadyInList){
				messages.addTuple(message);
			}
		}
	}

	/**
	 * Returns the message table
	 * @return TupleSet MessageTable
	 */
	public TupleSet getMessageTable() {
		return messages;
	}
}
