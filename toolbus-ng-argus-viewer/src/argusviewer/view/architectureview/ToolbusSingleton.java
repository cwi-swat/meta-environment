package argusviewer.view.architectureview;


import org.apache.log4j.Logger;
import argusviewer.view.msc.data.AbstractTuple;

import prefuse.data.Schema;

/**
 * Class created to create the square around the processes. Big singleton. Does
 * not want to be tempered with.
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 */
public class ToolbusSingleton  extends AbstractTuple {
	public static final String TABLE_NAME = "toolbusSingleton";
	public static final String TB_FIELDNAME = "toolbus";
	private static final Class < ? > TB_FIELDTYPE = String.class;
	private static final String TB_DEFAULT_VALUE = "toolbus";
	private static final String[] COLUMNS = { TB_FIELDNAME };
	private static final int TABLE_COLUMNCOUNT = 1;
	private static Logger log = Logger.getLogger(ToolbusSingleton.class);

	public static final Schema TABLE_SCHEMA;
	static {
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(TB_FIELDNAME, TB_FIELDTYPE, TB_DEFAULT_VALUE);
	}
	
	/**
	 * ToolbusSingleton constructor. Does nothing of significance. 
	 */
	public ToolbusSingleton() {
		log.debug("ToolbusSignleton created.");
	}
	
	
	/**
	 * Columns are needed, so the columns are given. Only one column in this
	 * class.
	 * @return COLUMNS
	 */
	@Override
	protected String[] getColumns() {
		log.debug("getColumns called");
		return COLUMNS;
	}

	/**
	 * Assert false, returns false. Do not temper.
	 * @param field not used
	 * @param type not used
	 * @return false
	 */
	protected boolean isValidNameTypePair(String field, Class type) {
		return type.equals(TB_FIELDTYPE);
	}

	/**
	 * Assert false. Do not temper.
	 * @param field not used.
	 * @param value not used.
	 */
	public void set(String field, Object value) {
		assert false;
	}

	/**
	 * Invariantly returns the default value.
	 * @param field not used
	 * @return TB_DEFAULT_VALUE
	 */
	public Object get(String field) {
		log.debug("get string called");
		return TB_DEFAULT_VALUE;
	}
	
	/**
	 * Invariantly returns the default value.
	 * @param col not used.
	 * @return TB_DEFAULT_VALUE
	 */
	public Object get(int col) {
		log.debug("get int called");
		return TB_DEFAULT_VALUE;
	}

	/**
	 * Invariantly returns the field type String.class.
	 * @param field not used
	 * @return TB_FIELDTYPE
	 */
	public Class < ? > getColumnType(String field) {
		log.debug("getColumnTypeString called");
		return TB_FIELDTYPE;
	}

	/**
	 * Invariantly returns the field type String.class.
	 * @param col not used
	 * @return TB_FIELDTYPE
	 */
	public Class < ? > getColumnType(int col) {
		log.debug("getColumnTypeInt called");
		return TB_FIELDTYPE;
	}

	/**
	 * Invariantly returns the default value.
	 * @param field not used
	 * @return TB_DEFAULT_VALUE
	 */
	public Object getDefault(String field) {
		log.debug("getDefault called");
		return TB_DEFAULT_VALUE;
	}

	/**
	 * returns the schema.
	 * @return the schema
	 */
	public Schema getSchema() {
		log.debug("getSchema called");
		return TABLE_SCHEMA;
	}

	/**
	 * Assert false. Do not temper.
	 * @param field not used
	 */
	public void revertToDefault(String field) {
		assert false;
	}

	/**
	 * Assert false. Do not temper.
	 * @param col not used
	 * @param value not used
	 */
	public void set(int col, Object value) {
		assert false;
	}
}
