package nl.cwi.sen1.visplugin.table.model;

import javax.swing.table.DefaultTableModel;

import nl.cwi.sen1.relationstores.types.IdCon;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;

/**
 * Table model supporting column sortings. This model is able to work directly
 * with RTuples and its data should be set using the setRTupleData() function.
 * The original RElems can then be retrieved for every table row using the
 * getRElemForRow() function.
 * 
 * @author Anton Gerdessen
 * @date 12-03-2007
 */
public class SortableTableModel extends DefaultTableModel {

	private static final long serialVersionUID = 1L;

	private int[] m_indexes;

	private TableSorter m_sorter;

	private RTuple m_data;

	private IdCon m_rTupleVariable;

	private RType m_rTupleRType;

	public SortableTableModel() {
		super();

		m_data = null;
	}

	/**
	 * Retrieve the value for a given postion (row,col).
	 * 
	 * @param row
	 *            The (row,col) combination
	 * @param col
	 *            The (row,col) combination
	 * @author Anton Gerdessen
	 * @date 12-03-2007
	 */
	public Object getValueAt(int row, int col) {
		int rowIndex = row;
		if (m_indexes != null) {
			rowIndex = m_indexes[row];
		}
		return super.getValueAt(rowIndex, col);
	}

	/**
	 * Set the value for a given postion (row,col).
	 * 
	 * @param value
	 *            The value to set at the (row,col) combination
	 * @param row
	 *            The (row,col) combination
	 * @param col
	 *            The (row,col) combination
	 * @author Anton Gerdessen
	 * @date 12-03-2007
	 */
	public void setValueAt(Object value, int row, int col) {
		int rowIndex = row;
		if (m_indexes != null) {
			rowIndex = m_indexes[row];
		}
		super.setValueAt(value, rowIndex, col);
	}

	/**
	 * Retrieve the value for a given postion (row,col).
	 * 
	 * @param column
	 *            the column to base the sort on
	 * @param isAscent
	 *            ascending (true) or or decending (false) order
	 * @author Anton Gerdessen
	 * @date 12-03-2007
	 */
	public void sortByColumn(int column, boolean isAscent) {
		if (m_sorter == null) {
			m_sorter = new TableSorter(this);
		}
		m_sorter.sort(column, isAscent);
		fireTableDataChanged();
	}

	/**
	 * Returns the index mapping on which the current sort is based.
	 * 
	 * @return The index mapping as an array.
	 * 
	 * @author Anton Gerdessen
	 * @date 12-03-2007
	 */
	public int[] getIndexes() {
		int n = getRowCount();
		if (m_indexes != null) {
			if (m_indexes.length == n) {
				return m_indexes;
			}
		}
		m_indexes = new int[n];
		for (int i = 0; i < n; i++) {
			m_indexes[i] = i;
		}
		return m_indexes;
	}

	/**
	 * Return the type which is displayed in the given column.
	 * 
	 * @param column
	 *            The column to retrieve the type from
	 * @author Anton Gerdessen
	 * @date 12-03-2007
	 */
	@SuppressWarnings("unchecked")
	public Class getColumnClass(int column) {
		// Retrieve the first item of the column and base the type on that.
		return getValueAt(0, column).getClass();
	}

	/**
	 * Sets the data of the table model to the data contained in the RTuple.
	 * 
	 * @param data
	 *            The RTuple data to put in the table.
	 * 
	 */
	public void setRTupleData(RTuple data) {
		try {
			m_rTupleVariable = data.getVariable();
			m_rTupleRType = data.getRtype();
			RElem value = data.getValue();
			Object[][] dataVector = null;
			String[] columnIdentifiers = null;

			if (value.isBool() || value.isInt() || value.isLoc()
					|| value.isStr()) {
				columnIdentifiers = new String[] { "value" };
				dataVector = new Object[1][1];
				dataVector[0][0] = getValueFromRElem(value);
			} else if (value.isSet() || value.isBag()) {
				if (m_rTupleRType.hasColumnTypes()) {
					RElemElements es = value.getElements();
					RTypeColumnTypes columnTypes = m_rTupleRType
							.getColumnTypes();
					columnIdentifiers = convertColumnTypesToStrings(columnTypes);

					int numRows = es.getLength();
					int numColumns = columnTypes.getLength();

					// copies each of the values of the RTuple to the dataVector
					dataVector = new Object[numRows][numColumns];
					for (int r = 0; !es.isEmpty(); es = es.getTail(), r++) {
						RElem tuple = es.getHead();
						RElemElements fs = tuple.getElements();

						for (int c = 0; !fs.isEmpty(); fs = fs.getTail(), c++) {
							RElem elem = fs.getHead();
							dataVector[r][c] = getValueFromRElem(elem);
						}
					}
				} else if (value.hasElements()) {
					RElemElements es = value.getElements();
					dataVector = new Object[es.getLength()][1];
					columnIdentifiers = new String[] { "values" };

					for (int i = 0; !es.isEmpty(); es = es.getTail(), i++) {
						RElem val = es.getHead();
						dataVector[i][0] = getValueFromRElem(val);
					}
				} else {
					System.err
							.println("Apparently forgot to implement mapping for "
									+ m_rTupleRType.toTerm().toString());
				}
			} else {
				System.err
						.println("Apparently forgot to implement mapping for "
								+ m_rTupleRType.toTerm().toString());
				return;
			}

			setDataVector(dataVector, columnIdentifiers);
			m_data = data;
		} catch (Exception exception) {
			System.err.print(exception.getMessage());
			exception.printStackTrace();
		}
	}

	/**
	 * Returns the variable of the set RTuple data.
	 * 
	 * @return The RTuple variable.
	 * 
	 * @sa setRTupleData()
	 * 
	 * @author Anton Gerdessen
	 * @author Arend van Beelen
	 * @data 13-03-2007
	 */
	public IdCon getRTupleVariable() {
		return m_rTupleVariable;
	}

	/**
	 * Returns the RType of the set RTuple data.
	 * 
	 * @return The RTuple RType.
	 * 
	 * @sa setRTupleData()
	 * 
	 * @author Anton Gerdessen
	 * @author Arend van Beelen
	 * @data 13-03-2007
	 */
	public RType getRTupleRType() {
		return m_rTupleRType;
	}

	/**
	 * Returns an RElem containing the data for a row.
	 * 
	 * @param rowIndex
	 *            Index of the row. If sorting is enabled, the index will
	 *            automatically adjusted.
	 * @return An RElem from the RTuple data.
	 * 
	 * @author Anton Gerdessen
	 * @author Arend van Beelen
	 * @data 13-03-2007
	 */
	public RElem getRElemForRow(int rowIndex) {
		if (m_indexes != null) {
			rowIndex = m_indexes[rowIndex];
		}
		RElem value = m_data.getValue();
		RElemElements valueElements = value.getElements();
		return valueElements.getRElemAt(rowIndex);
	}

	/**
	 * Converts RElem value to an object. It supports only four types (str, int,
	 * bool, loc ) now.
	 * 
	 * @param element
	 * @return Object
	 * 
	 * @exception Exception
	 *                Throws and unknown RElem exception when the element is of
	 *                an unknown type.
	 * 
	 * @author Srinivasan Tharmarajah
	 * @date 08-03-2007
	 */
	private static Object getValueFromRElem(RElem element) throws Exception {
		Object value = null;

		if (element.isStr()) {
			value = element.getStrCon();
		} else if (element.isInt()) {
			value = new Integer(element.getInteger().getNatCon());
		} else if (element.isBool()) {
			value = element.getBoolCon();
		} else if (element.isLoc()) {
			value = element.getLocation();
		} else {
			value = element.toTerm().toString();
		}

		return value;
	}

	/**
	 * Converts RTypeColumnTypes to an array of Strings
	 * 
	 * @param columnTypes
	 * @return
	 * @author Antoine Savelkoul
	 * @date 08-03-2007
	 */
	private static String[] convertColumnTypesToStrings(
			RTypeColumnTypes columnTypes) {
		int numColumns = columnTypes.getLength();
		String[] columnNames = new String[numColumns];

		// copies each of the type names to the array
		for (int columnNum = 0; columnNum < numColumns; columnNum++) {
			RType columnType = columnTypes.getRTypeAt(columnNum);
			columnNames[columnNum] = columnType.toString() + " [" + columnNum
					+ "]";
		}

		return columnNames;
	}

	/**
	 * Returns
	 * 
	 * @c false so that the table cells are not editable.
	 * 
	 * @param rowIndex
	 *            Row index of the cell, ignored.
	 * @param columnIndex
	 *            Column index of the cell, ignored.
	 * 
	 * @return
	 * @c false.
	 * 
	 * @author Arend van Beelen
	 * @date 12-03-2007
	 */
	public boolean isCellEditable(int rowIndex, int columnIndex) {
		return false;
	}
}