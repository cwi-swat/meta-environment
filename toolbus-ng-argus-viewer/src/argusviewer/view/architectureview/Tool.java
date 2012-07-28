package argusviewer.view.architectureview;

import prefuse.data.Schema;
import argusviewer.view.msc.data.AbstractTuple;

/**
 * This class represents a tuple in the Statements table (a statement executed by a tool).
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 */
public class Tool extends AbstractTuple{
	public final static String TOOL_FIELDNAME = "tool";
	public final static Class<?> TOOL_FIELDTYPE = String.class;
	public final static String TOOL_DEFAULT_VALUE = "";
	
	public final static String TABLE_NAME = "tools";
	private final static int TABLE_COLUMNCOUNT = 1;
	
	public final static Schema TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
	static{
		TABLE_SCHEMA.addColumn(TOOL_FIELDNAME, TOOL_FIELDTYPE, TOOL_DEFAULT_VALUE);
	}
	
	private static final String[] COLUMNS = {TOOL_FIELDNAME};
	
	private volatile String m_tool;
	
	/**
	 * Create a Tool tuple with the given tool name
	 * 
	 * @param tool The tool
	 */
	public Tool(String tool){
		m_tool = tool;
	}
	
	/**
	 * {@inheritDoc}
	 */
	protected String[] getColumns(){
		return COLUMNS;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field){
		if (field.equals(TOOL_FIELDNAME)){
			return m_tool;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(int col){
		if((0 <= col) && (col < COLUMNS.length)){
			return get(COLUMNS[col]);
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(String field){
		if(field.equals(TOOL_FIELDNAME)){
			return TOOL_FIELDTYPE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(int col){
		if((0 <= col) && (col < COLUMNS.length)){
			return getColumnType(COLUMNS[col]);
		}
		
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field){
		if(field.equals(TOOL_FIELDNAME)){
			return TOOL_DEFAULT_VALUE;
		}
		
		// This shouldn't happen
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Schema getSchema(){
		return TABLE_SCHEMA;
	}

	/**
	 * {@inheritDoc}
	 */
	public void revertToDefault(String field){
		if(field.equals(TOOL_FIELDNAME)){
			set(field, TOOL_DEFAULT_VALUE);
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value){
		Class<?> valueType = value.getClass();

		if((canSet(field, valueType)) && (field.equals(TOOL_FIELDNAME))){
			m_tool = (String) value;			
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(int col, Object value){
		if((0 <= col) && (col < COLUMNS.length)){
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
	protected boolean isValidNameTypePair(String field, Class type){
		return (field.equals(TOOL_FIELDNAME)) && (type == TOOL_FIELDTYPE);
	}
}
