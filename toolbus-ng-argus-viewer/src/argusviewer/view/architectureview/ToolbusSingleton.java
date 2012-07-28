package argusviewer.view.architectureview;


import prefuse.data.Schema;
import argusviewer.view.msc.data.AbstractTuple;

/**
 * Class created to create the square around the processes. Big singleton. Does
 * not want to be tempered with.
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 */
public class ToolbusSingleton  extends AbstractTuple{
	public static final String TABLE_NAME = "toolbusSingleton";
	public static final String TB_FIELDNAME = "toolbus";
	private static final Class<?> TB_FIELDTYPE = String.class;
	private static final String TB_DEFAULT_VALUE = "toolbus";
	private static final String[] COLUMNS = { TB_FIELDNAME };
	private static final int TABLE_COLUMNCOUNT = 1;
	
	public static final Schema TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
	static{
		TABLE_SCHEMA.addColumn(TB_FIELDNAME, TB_FIELDTYPE, TB_DEFAULT_VALUE);
	}
	
	/**
	 * ToolbusSingleton constructor. Does nothing of significance. 
	 */
	public ToolbusSingleton(){
		super();
	}
	
	/**
	 * Columns are needed, so the columns are given. Only one column in this
	 * class.
	 * @return COLUMNS
	 */
	protected String[] getColumns(){
		return COLUMNS;
	}

	/**
	 * 
	 * @param field not used
	 * @param type not used
	 * @return false
	 */
	protected boolean isValidNameTypePair(String field, Class type){
		return type.equals(TB_FIELDTYPE);
	}

	/**
	 * 
	 * @param field not used.
	 * @param value not used.
	 */
	public void set(String field, Object value){
		// Error
	}

	/**
	 * Invariantly returns the default value.
	 * @param field not used
	 * @return TB_DEFAULT_VALUE
	 */
	public Object get(String field){
		return TB_DEFAULT_VALUE;
	}
	
	/**
	 * Invariantly returns the default value.
	 * @param col not used.
	 * @return TB_DEFAULT_VALUE
	 */
	public Object get(int col){
		return TB_DEFAULT_VALUE;
	}

	/**
	 * Invariantly returns the field type String.class.
	 * @param field not used
	 * @return TB_FIELDTYPE
	 */
	public Class<?> getColumnType(String field){
		return TB_FIELDTYPE;
	}

	/**
	 * Invariantly returns the field type String.class.
	 * @param col not used
	 * @return TB_FIELDTYPE
	 */
	public Class<?> getColumnType(int col){
		return TB_FIELDTYPE;
	}

	/**
	 * Invariantly returns the default value.
	 * @param field not used
	 * @return TB_DEFAULT_VALUE
	 */
	public Object getDefault(String field){
		return TB_DEFAULT_VALUE;
	}

	/**
	 * returns the schema.
	 * @return the schema
	 */
	public Schema getSchema(){
		return TABLE_SCHEMA;
	}

	/**
	 * @param field not used
	 */
	public void revertToDefault(String field){
		// Error
	}

	/**
	 * @param col not used
	 * @param value not used
	 */
	public void set(int col, Object value){
		// Error
	}
}
