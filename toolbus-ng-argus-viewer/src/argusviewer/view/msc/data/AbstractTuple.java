package argusviewer.view.msc.data;

import java.util.Date;

import prefuse.data.Table;
import prefuse.data.Tuple;

/**
 * Base class for table tuples in the Prefuse MSC data model.
 * 
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * 
 */
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public abstract class AbstractTuple implements Tuple {

	/**
	 * Returns an array of the Columns
	 * 
	 * @return String Array of the columns.
	 */
	protected abstract String[] getColumns();
	
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
	protected abstract boolean isValidNameTypePair(String field, Class type);

	/**
	 * {@inheritDoc}
	 */
	public boolean canGet(String field, Class type) {
		return isValidNameTypePair(field, type);
	}
	
	/**
	 * {@inheritDoc}
	 */
	public boolean canGetBoolean(String field) {
		return canGet(field, boolean.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetDate(String field) {
		return canGet(field, Date.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetDouble(String field) {
		return canGet(field, Double.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetFloat(String field) {
		return canGet(field, float.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetInt(String field) {
		return canGet(field, int.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetLong(String field) {
		return canGet(field, long.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canGetString(String field) {
		return canGet(field, String.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSet(String field, Class type) {
		return isValidNameTypePair(field, type);
	}
	
	/**
	 * {@inheritDoc}
	 */
	public boolean canSetBoolean(String field) {
		return canSet(field, boolean.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetDate(String field) {
		return canSet(field, Date.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetDouble(String field) {
		return canSet(field, double.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetFloat(String field) {
		return canSet(field, float.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetInt(String field) {
		return canSet(field, int.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetLong(String field) {
		return canSet(field, long.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean canSetString(String field) {
		return canSet(field, String.class);
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean getBoolean(String field) {

		if (canGetBoolean(field)) {
			return ((Boolean) get(field)).booleanValue();
		}

		throw new ClassCastException("The requested field is not a Boolean");
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean getBoolean(int col) {
		if (canGetBoolean(getColumnName(col))) {
			return ((Boolean) get(col)).booleanValue();
		}

		throw new ClassCastException("The requested field is not a Boolean");
	}

	/**
	 * {@inheritDoc}
	 */
	public Date getDate(String field) {
		if (canGetDate(field)) {
			return (Date) get(field);
		}

		throw new ClassCastException("The requested field is not a Date");
	}

	/**
	 * {@inheritDoc}
	 */
	public Date getDate(int col) {
		if (canGetDate(getColumnName(col))) {
			return (Date) get(col);
		}

		throw new ClassCastException("The requested field is not a Date");
	}

	/**
	 * {@inheritDoc}
	 */
	public double getDouble(String field) {
		if (canGetDouble(field)) {
			return ((Double) get(field)).doubleValue();
		}

		throw new ClassCastException("The requested field is not a Double");
	}

	/**
	 * {@inheritDoc}
	 */
	public double getDouble(int col) {
		if (canGetDouble(getColumnName(col))) {
			return ((Double) get(col)).doubleValue();
		}

		throw new ClassCastException("The requested field is not a Double");
	}

	/**
	 * {@inheritDoc}
	 */
	public float getFloat(String field) {
		if (canGetFloat(field)) {
			return ((Float) get(field)).floatValue();
		}

		throw new ClassCastException("The requested field is not a Float");
	}

	/**
	 * {@inheritDoc}
	 */
	public float getFloat(int col) {
		if (canGetFloat(getColumnName(col))) {
			return ((Float) get(col)).floatValue();
		}

		throw new ClassCastException("The requested field is not a Float");
	}

	/**
	 * {@inheritDoc}
	 */
	public int getInt(String field) {
		if (canGetInt(field)) {
			return ((Integer) get(field)).intValue();
		}

		throw new ClassCastException("The requested field is not a Integer");
	}

	/**
	 * {@inheritDoc}
	 */
	public int getInt(int col) {
		if (canGetInt(getColumnName(col))) {
			return ((Integer) get(col)).intValue();
		}

		throw new ClassCastException("The requested field is not a Int");
	}

	/**
	 * {@inheritDoc}
	 */
	public long getLong(String field) {
		if (canGetLong(field)) {
			return ((Long) get(field)).longValue();
		}

		throw new ClassCastException("The requested field is not a Long");
	}

	/**
	 * {@inheritDoc}
	 */
	public long getLong(int col) {
		if (canGetLong(getColumnName(col))) {
			return ((Long) get(col)).longValue();
		}

		throw new ClassCastException("The requested field is not a Long");
	}

	/**
	 * {@inheritDoc}
	 */
	public int getRow() {
		// no backing table exists
		return -1;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getString(String field) {
		if (canGetString(field)) {
			return (String) get(field);
		}

		throw new ClassCastException("The requested field is not a String");
	}

	/**
	 * {@inheritDoc}
	 */
	public String getString(int col) {
		if (canGetString(getColumnName(col))) {
			return (String) get(col);
		}

		throw new ClassCastException("The requested field is not a String");
	}

	/**
	 * {@inheritDoc}
	 */
	public Table getTable() {
		// no backing table exists
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean isValid() {
		// ignored
		return true;
	}

	/**
	 * Sets the value of a specified column for a Fieldname
	 * 
	 * @param field
	 *            Fieldname
	 * @param value
	 *            Object value
	 */
	public abstract void set(String field, Object value);

	/**
	 * Set the value of a specified column for a Column Id
	 * 
	 * @param col
	 *            Column Id
	 * @param type
	 *            Class type of the value
	 * @param value
	 *            Object value
	 */
	public void set(int col, Class type, Object value) {
		set(getColumnName(col), value);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setBoolean(String field, boolean val) {
		set(field, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setBoolean(int col, boolean val) {
		set(col, boolean.class, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setDate(String field, Date val) {
		set(field, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setDate(int col, Date val) {
		set(col, Date.class, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setDouble(String field, double val) {
		set(field, val);

	}

	/**
	 * {@inheritDoc}
	 */
	public void setDouble(int col, double val) {
		set(col, double.class, val);

	}

	/**
	 * {@inheritDoc}
	 */
	public void setFloat(String field, float val) {
		set(field, new Float(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setFloat(int col, float val) {
		set(col, float.class, new Float(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setInt(String field, int val) {
		set(field, Integer.valueOf(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setInt(int col, int val) {
		set(col, int.class, Integer.valueOf(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setLong(String field, long val) {
		set(field, Long.valueOf(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setLong(int col, long val) {
		set(col, long.class, Long.valueOf(val));
	}

	/**
	 * {@inheritDoc}
	 */
	public void setString(String field, String val) {
		set(field, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setString(int col, String val) {
		set(col, String.class, val);
	}

	/**
	 * {@inheritDoc}
	 */
	public int getColumnIndex(String field) {

		for (int i = 0; i < getColumnCount(); i++) {
			if (getColumns()[i].equals(field)) {
				return i;
			}
		}

		return -1;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getColumnName(int col) {
		return getColumns()[col];
	}

	/**
	 * {@inheritDoc}
	 */
	public int getColumnCount() {
		return getColumns().length;
	}

}
