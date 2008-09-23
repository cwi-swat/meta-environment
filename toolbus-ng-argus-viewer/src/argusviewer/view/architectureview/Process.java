package argusviewer.view.architectureview;

import argusviewer.view.msc.data.AbstractTuple;
import prefuse.data.Schema;

/**
 * This class represents a tuple in the Statements table (a statement executed by a process).
 * 
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 */
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Process extends AbstractTuple {
	public static final String PROCESS_FIELDNAME = "process";
	public static final Class<?> PROCESS_FIELDTYPE = String.class;
	public static final String PROCESS_DEFAULT_VALUE = "";
	
	public static final String TABLE_NAME = "processes";
	private static final int TABLE_COLUMNCOUNT = 1;
	public static final Schema TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
	static{
		TABLE_SCHEMA.addColumn(PROCESS_FIELDNAME, PROCESS_FIELDTYPE, PROCESS_DEFAULT_VALUE);
	}

	private static final String[] COLUMNS = {PROCESS_FIELDNAME};
	
	private volatile String m_process;
	
	/**
	 * Create a Process tuple with the given process name
	 * 
	 * @param process The process
	 */
	public Process(String process){
		super();
		
		m_process = process;
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
		if (field.equals(PROCESS_FIELDNAME)) {
			return m_process;
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
		if (field.equals(PROCESS_FIELDNAME)) {
			return PROCESS_FIELDTYPE;
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
		if (field.equals(PROCESS_FIELDNAME)) {
			return PROCESS_DEFAULT_VALUE;
		}
		
		// This shouldn't happen
		return null;
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
		if (field.equals(PROCESS_FIELDNAME)) {
			set(field, PROCESS_DEFAULT_VALUE);
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value) {
		Class<?> valueType = value.getClass();

		if ((canSet(field, valueType)) 
			&& (field.equals(PROCESS_FIELDNAME))) {
			m_process = (String) value;			
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
		return (field.equals(PROCESS_FIELDNAME)) && (type == PROCESS_FIELDTYPE);
	}

}
