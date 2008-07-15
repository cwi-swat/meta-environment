package argusviewer.view.architectureview;

import org.apache.log4j.Logger;
import argusviewer.view.msc.data.AbstractTuple;

import prefuse.data.Schema;

/**
 * This class represents a tuple in the Statements table (a statement executed by a tool).
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 *
 */
@SuppressWarnings("unchecked")
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Tool extends AbstractTuple {

	public static final String TOOL_FIELDNAME = "tool";
	public static final Class TOOL_FIELDTYPE = String.class;
	public static final String TOOL_DEFAULT_VALUE = "";
	private static Logger log = Logger.getLogger(Tool.class);
	private String m_tool;
	
		
	public static final String TABLE_NAME = "tools";
	private static final int TABLE_COLUMNCOUNT = 1;
	public static final Schema TABLE_SCHEMA;
	static {
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(TOOL_FIELDNAME, TOOL_FIELDTYPE, TOOL_DEFAULT_VALUE);
	}

	private static final String[] COLUMNS = {TOOL_FIELDNAME};
	
	/**
	 * Create a Tool tuple with the given tool name
	 * 
	 * @param tool The tool
	 */
	public Tool(String tool) {
		log.info("tool created");
		m_tool = tool;
	}
	
	/**
	 * {@inheritDoc}
	 */
	@Override
	protected String[] getColumns() {
		return COLUMNS;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field) {
		if (field.equals(TOOL_FIELDNAME)) {
			return m_tool;
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
	public Class getColumnType(String field) {
		if (field.equals(TOOL_FIELDNAME)) {
			return TOOL_FIELDTYPE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class getColumnType(int col) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			return getColumnType(COLUMNS[col]);
		}
		
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field) {
		if (field.equals(TOOL_FIELDNAME)) {
			return TOOL_DEFAULT_VALUE;
		} else {
			// This shouldn't happen
			assert false;
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
		if (field.equals(TOOL_FIELDNAME)) {
			set(field, TOOL_DEFAULT_VALUE);
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value) {
		Class valueType = value.getClass();

		if ((canSet(field, valueType))
			&&  (field.equals(TOOL_FIELDNAME))) {
			m_tool = (String) value;			
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
		return (field.equals(TOOL_FIELDNAME)) && (type == TOOL_FIELDTYPE);
	}

}
