package argusviewer.view.msc.data;

import java.util.LinkedList;
import java.util.List;

import prefuse.Visualization;
import prefuse.data.Table;
import prefuse.data.Tuple;
import argusviewer.ApplicationSettings;

/**
 * The data tables for the Message Sequence Chart View. There are three tables:
 * - Entities: Contains a list of processes and tools;
 * - Statements: Contains all the statements executed by the processes or tools, along with a timestamp;
 * - Messages: Contains all the communication messages between processes and tools.
 * 
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Hidde Baggelaar
 */
public class MSCData{
	private final Table m_entities;
	private final Table m_statements;
	private final Table m_messages;

	private final LinkedList<Tuple> statementList;
	private final LinkedList<Tuple> messagesList;
	
	private volatile Visualization m_viz;
	
	/**
	 * Default constructor.
	 */
	public MSCData(){
		m_entities = Entity.TABLE_SCHEMA.instantiate();
		m_statements = Statement.TABLE_SCHEMA.instantiate();
		m_messages = Message.TABLE_SCHEMA.instantiate();
		
		statementList = new LinkedList<Tuple>();
		messagesList = new LinkedList<Tuple>();
	}
	
	/**
	 * Gets the Entities table.
	 * 
	 * @return The Entities table
	 */
	public Table getEntitiesTable(){
		return m_entities;
	}
	
	/**
	 * Gets the Statements table.
	 * 
	 * @return The Statements table
	 */
	public Table getStatementsTable(){
		return m_statements;
	}
	
	/**
	 * Gets the Messages table.
	 * 
	 * @return The Messages table
	 */
	public Table getMessagesTable(){
		return m_messages;
	}
	
	/**
	 * Add a new entity to the Entities table.
	 * 
	 * @param entity The entity to add
	 * @return The Tuple that has been added to the Entities table
	 */
	public Tuple addEntity(Entity entity){
		synchronized(m_viz){
			return m_entities.addTuple(entity);
		}
	}
	
	/**
	 * Add a new statement to the Statements table. 
	 * If there are too many statements in the table, the table 
	 * will be shortened. Statements are also added to the statementList, 
	 * so sequential statement ordering is stored. 
	 * 
	 * @param statement The statement to add
	 * @return The Tuple that has been added to the Statements table
	 */
	public Tuple addStatement(Statement statement){
		synchronized(m_viz){
			int historyLimit = ApplicationSettings.getHistoryLimit();
			
			if(historyLimit > 0){
				while (m_statements.getRowCount() >= historyLimit){
					removeStatement();
				}
			}
	
			Tuple stmTuple = m_statements.addTuple(statement); 
	
			synchronized(statementList){
				statementList.add(stmTuple);
			}
			return stmTuple;
		}
	}

	/**
	 * Removes a statement from the MSD
	 */
	private void removeStatement(){
		synchronized(m_viz){
			Tuple firstTuple;
			synchronized(statementList){
				firstTuple = statementList.getFirst();
			}

			// Remove action is synchronized to prevent PreFuse from drawing at the same time
			removeMessage(firstTuple);
			m_statements.removeTuple(firstTuple);
			statementList.removeFirst();			
		}
	}
	
	/**
	 * Add a new message to the Message table. Messages  are also added to the messagesList, 
	 * so sequential message ordering is stored
	 * 
	 * @param message The message to add
	 * @return The Tuple that has been added to the Message table
	 */
	public Tuple addMessage(Message message){
		synchronized(m_viz){
			Tuple msgTuple = m_messages.addTuple(message);
			synchronized(messagesList){
				messagesList.add(msgTuple);
			}
			return msgTuple;
		}
	}
	
	/**
	 * Removes the message that originated from the given statement
	 * @param stmTuple the message to remove
	 */
	protected void removeMessage(Tuple stmTuple){
		synchronized(m_viz){
			synchronized(messagesList){
				//no messages, so no need to remove any
				if(messagesList.size() == 0){
					return;
				}
				
				Tuple first = messagesList.getFirst();
				int msgTimestamp = ((Integer) first.get(Message.SOURCEID_FIELDNAME)).intValue(); 
				int stmTimestamp = ((Integer) stmTuple.get(Statement.TIMESTAMP_FIELDNAME)).intValue();
		 
				if(msgTimestamp == stmTimestamp){
					// Remove action is synchronized to prevent PreFuse from drawing at the same time
					m_messages.removeTuple(first);
					messagesList.removeFirst();
				}
			}
		}
		
	}

	/**
	 * Get the list of statements in the data model.
	 * @return the statementList
	 */
	public LinkedList<Tuple> getStatementList(){
		synchronized(statementList){
			LinkedList<Tuple> statementsListCopy = new LinkedList<Tuple>();
			statementsListCopy.addAll(statementList);
			return statementsListCopy;
		}
	}
	
	/**
	 * Sets the visualization on which we will synchronize
	 * @param viz the visualization on which we will synchronize
	 */
	public void setVisualization(Visualization viz) {
		m_viz = viz;
	}

	/**
	 * Get the unmodifiable MessageList. Used for testing purposes.
	 * @return the unmodifiable messageList
	 */
	public List<Tuple> getMessagesList(){
		synchronized(messagesList){
			LinkedList<Tuple> messagesListCopy = new LinkedList<Tuple>();
			messagesListCopy.addAll(messagesList);
			return messagesListCopy;
		}
	}
}
