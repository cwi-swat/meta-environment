package argusviewer.view.msc.data;

import java.util.ArrayList;

import prefuse.data.Schema;
import toolbus.StateElement;
import toolbus.atom.msg.RecMsg;
import toolbus.atom.msg.SndMsg;
import toolbus.atom.note.RecNote;
import toolbus.atom.note.SndNote;
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

/**
 * This class represents a tuple in the Statements table (a statement executed by a process).
 * 
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 *
 */
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Statement extends AbstractTuple {
	private static final int HASH_CODE = 31;

	public static final String STATEMENT_FIELDNAME = "statement";
	public static final Class<?> STATEMENT_FIELDTYPE = String.class;
	public static final String STATEMENT_DEFAULT_VALUE = "";
	private String m_statement;
	
	public static final String PARENTID_FIELDNAME = "parentId";
	public static final Class<?> PARENTID_FIELDTYPE = String.class;
	public static final String PARENTID_DEFAULT_VALUE = "";
	private String m_parentId;
	
	public static final String TIMESTAMP_FIELDNAME = "timestamp";
	public static final Class<?> TIMESTAMP_FIELDTYPE = Integer.class;
	public static final int TIMESTAMP_DEFAULT_VALUE = -1;
	private int m_timestamp;
	
	public static final String TABLE_NAME = "statements";
	private static final int TABLE_COLUMNCOUNT = 3;
	public static final Schema TABLE_SCHEMA;
	static{
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(STATEMENT_FIELDNAME, STATEMENT_FIELDTYPE, STATEMENT_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(PARENTID_FIELDNAME, PARENTID_FIELDTYPE, PARENTID_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TIMESTAMP_FIELDNAME, TIMESTAMP_FIELDTYPE, Integer.valueOf(TIMESTAMP_DEFAULT_VALUE));
	}

	public static final String[] COLUMNS = {STATEMENT_FIELDNAME, PARENTID_FIELDNAME, TIMESTAMP_FIELDNAME};

	public static final ArrayList<Class< ? extends StateElement>> ASYNC_COMMUNICATION;
	public static final ArrayList<Class< ? extends StateElement>> SYNC_COMMUNICATION;
	public static final ArrayList<Class< ? extends StateElement>> TOOL_COMMUNICATION;

	static{
		ASYNC_COMMUNICATION = new ArrayList<Class< ? extends StateElement>>();
		ASYNC_COMMUNICATION.add(RecNote.class);
		ASYNC_COMMUNICATION.add(SndNote.class);

		SYNC_COMMUNICATION = new ArrayList<Class< ? extends StateElement>>();
		SYNC_COMMUNICATION.add(RecMsg.class);
		SYNC_COMMUNICATION.add(SndMsg.class);

		TOOL_COMMUNICATION = new ArrayList<Class< ? extends StateElement>>();
		TOOL_COMMUNICATION.add(AckEvent.class);
		TOOL_COMMUNICATION.add(Connect.class);
		TOOL_COMMUNICATION.add(DisConnect.class);
		TOOL_COMMUNICATION.add(Do.class);
		TOOL_COMMUNICATION.add(Eval.class);
		TOOL_COMMUNICATION.add(Event.class);
		TOOL_COMMUNICATION.add(Execute.class);
		TOOL_COMMUNICATION.add(GetPerfStats.class);
		TOOL_COMMUNICATION.add(RecPerfStats.class);
		TOOL_COMMUNICATION.add(RecVal.class);
		TOOL_COMMUNICATION.add(SndKill.class);
		TOOL_COMMUNICATION.add(Terminate.class);
	}
	
	/**
	 * Create a Statement tuple with the given id, statement, parentId and timestamp values.
	 * 
	 * @param statement The statement
	 * @param parentId The process/tool id of the parent (the process or tool which executed the statement)
	 * @param timestamp The (relative) time at which the statement was executed 
	 */
	public Statement(String statement, String parentId, int timestamp) {
		m_statement = statement;
		m_parentId = parentId;
		m_timestamp = timestamp;
	}
	
	/**
	 * {@inheritDoc}
	 */
	protected String[] getColumns() {
		return COLUMNS;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field) {
		if (field.equals(STATEMENT_FIELDNAME)) {
			return m_statement;
		} else if (field.equals(PARENTID_FIELDNAME)) {
			return m_parentId;
		} else if (field.equals(TIMESTAMP_FIELDNAME)) {
			return Integer.valueOf(m_timestamp);
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(int col) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			return get(COLUMNS[col]);
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(String field) {
		if (field.equals(STATEMENT_FIELDNAME)) {
			return STATEMENT_FIELDTYPE;
		} else if (field.equals(PARENTID_FIELDNAME)) {
			return PARENTID_FIELDTYPE;
		} else if (field.equals(TIMESTAMP_FIELDNAME)) {
			return TIMESTAMP_FIELDTYPE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(int col) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			return getColumnType(COLUMNS[col]);
		}
		
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field) {
		if (field.equals(STATEMENT_FIELDNAME)) {
			return STATEMENT_DEFAULT_VALUE;
		} else if (field.equals(PARENTID_FIELDNAME)) {
			return PARENTID_DEFAULT_VALUE;
		} else if (field.equals(TIMESTAMP_FIELDNAME)) {
			return Integer.valueOf(TIMESTAMP_DEFAULT_VALUE);
		} else {
			// This shouldn't happen
			return null;
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public Schema getSchema() {
		return TABLE_SCHEMA;
	}

	/**
	 * {@inheritDoc}
	 */
	public void revertToDefault(String field) {
		if (field.equals(STATEMENT_FIELDNAME)) {
			set(field, STATEMENT_DEFAULT_VALUE);
		} else if (field.equals(PARENTID_FIELDNAME)) {
			set(field, PARENTID_DEFAULT_VALUE);
		} else if (field.equals(TIMESTAMP_FIELDNAME)) {
			set(field, Integer.valueOf(TIMESTAMP_DEFAULT_VALUE));
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value) {
		Class valueType = value.getClass();

		if (canSet(field, valueType)) {
			if (field.equals(STATEMENT_FIELDNAME)) {
				m_statement = (String) value;
			} else if (field.equals(PARENTID_FIELDNAME)) {
				m_parentId = (String) value;
			} else if (field.equals(TIMESTAMP_FIELDNAME)) {
				m_timestamp = ((Integer) value).intValue();
			}
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(int col, Object value) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			set(COLUMNS[col], value);
		}
	}
	
	/**
	 * Checks for a given fieldname/type pair if it is a valid combination for
	 * this tuple.
	 * 
	 * @param field
	 *            The fieldname
	 * @param type
	 *            The data type
	 * @return Whether or not the pair is valid
	 */
	protected boolean isValidNameTypePair(String field, Class type) {
		if ((field.equals(STATEMENT_FIELDNAME)) && (type == STATEMENT_FIELDTYPE)) {
			return true;
		} else if ((field.equals(PARENTID_FIELDNAME)) && (type == PARENTID_FIELDTYPE)) {
			return true;
		} else if ((field.equals(TIMESTAMP_FIELDNAME)) && (type == TIMESTAMP_FIELDTYPE)) {
			return true;
		}

		return false;
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

		Statement statement = (Statement) o;

		if (m_timestamp != statement.m_timestamp) {
			return false;
		}
		if (m_parentId != null ? !m_parentId.equals(statement.m_parentId) : statement.m_parentId != null) {
			return false;
		}

		return !(m_statement != null ? !m_statement.equals(statement.m_statement) : statement.m_statement != null);
	}

	/**
	 * {@inheritDoc}
	 */
	public int hashCode() {
		int result;
		result = (m_statement != null ? m_statement.hashCode() : 0);
		result = HASH_CODE * result + (m_parentId != null ? m_parentId.hashCode() : 0);
		result = HASH_CODE * result + m_timestamp;
		return result;
	}
}
