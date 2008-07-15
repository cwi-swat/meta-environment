package argusviewer.view.sourcefile;



import javax.swing.table.AbstractTableModel;


/**
 * Classname SourceFileTableModel
 * Represents the model (breakpoint/line-number/script-source) and is used in the SourceFilePanel
 * 
 * Date 13/2/2008
 *  
 * @author Qais & Bas
 *
 */
public class SourceFileTableModel extends AbstractTableModel {
	private static final long serialVersionUID = -7623082694279943410L;
	
	private static final int COLUMN_COUNT = 3;
	private int m_lineNumbers; 
	
	private String[] m_columnNames = {"", "", "" };
	private Object[][] m_sourceLines;

	/**
	 * Constructs a new SourceFileTableModel. It is used to display the source
	 * code, break points, line numbers, etc.
	 * @param source the source of an toolbus file. The constructor expects
	 * source code to be displayed.
	 */
	public SourceFileTableModel(String source) {
				
		String sourceFile = source;
		m_lineNumbers = getTextLineNumber(sourceFile);
		m_sourceLines = new Object [m_lineNumbers][COLUMN_COUNT];
		int index = 0;
		final int breakPointPosition = 0;
		final int sourceCodeLineNumber = 1;
		final int text = 2;
		int firstEndLine = 0;
		int nextLine = 0;
		while (sourceFile.length() != 0) {
			if (sourceFile.contains("\n")) {
				firstEndLine = sourceFile.indexOf("\n");
				nextLine = firstEndLine + 1;
			} else {
				firstEndLine = sourceFile.length();
				nextLine = firstEndLine;
			}
			String firstLine = sourceFile.substring(0, firstEndLine);
			m_sourceLines[index][breakPointPosition] = Boolean.FALSE;
			m_sourceLines[index][sourceCodeLineNumber] = Integer.valueOf(index + 1);
			firstLine = firstLine.replaceAll("\t", "    "); // object array ignores tab keys  
			m_sourceLines[index][text] = firstLine;		
			sourceFile = sourceFile.substring(nextLine, sourceFile.length());
			index++;
		}
	}

	/**
	 * Returns the total line numbers.
	 * @param source the source of an toolbus file
	 * @return total line numbers of the source 
	 */
	public int getTextLineNumber(String source) {
		
		String sourceFile = source;
		int lineNumbers = 0;
		int firstEndLine = 0;
		int nextLine = 0;
		while (sourceFile.length() != 0) {
			if (sourceFile.contains("\n")) {
				firstEndLine = sourceFile.indexOf("\n");
				nextLine = firstEndLine + 1;
			} else {
				firstEndLine = sourceFile.length();
				nextLine = firstEndLine;
			}
			sourceFile = sourceFile.substring(nextLine, sourceFile.length());
			lineNumbers++;
		}	
		return lineNumbers;
	}
	
	/**
	 * {@inheritDoc}
	 */
	public int getColumnCount() {
		return m_columnNames.length;
	}


	/**
	 * {@inheritDoc}
	 */
	public int getRowCount() {
		return m_sourceLines.length;
	}


	/**
	 * {@inheritDoc}
	 */
	public String getColumnName(int col) {
		return m_columnNames[col];
	}


	/**
	 * {@inheritDoc}
	 */
	public Object getValueAt(int row, int col) {
		return m_sourceLines[row][col];
	}

	/**
	 * {@inheritDoc}
	 */
	public boolean getBreakPoint(int lineNumber) {
		boolean result = false;
		if (lineNumber < m_lineNumbers && lineNumber >= 0) {
			result = ((Boolean) m_sourceLines[lineNumber][0]).booleanValue();
		}
		return result;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnClass(int c) {
		return getValueAt(0, c).getClass();

	}


	/**
	 * {@inheritDoc}
	 * Put the first column on editable, and the others on non-editable
	 */
	public boolean isCellEditable(int row, int col) {
		boolean result = true;
		int firstColumn = 0;
		if (col != firstColumn) {
			result = false;
		}
		return result;
	}
		
	
	/**
	 * {@inheritDoc}
	 */
	public void setValueAt(Object value, int row, int col) {
		if (row < m_lineNumbers && col < COLUMN_COUNT) {
			m_sourceLines[row][col] = value;
			fireTableCellUpdated(row, col);
		}
	}
	

	/**
	 * Sets a Breackpoint on an given line.
	 * @param value represents: is the checkbox checked or unchecked
	 * @param row represents: the position of the checkbox / breakpoint
	 */
	public void setBreakPoint(boolean value, int row) {
		if (row < m_lineNumbers && row >= 0) {
			m_sourceLines[row][0] = Boolean.valueOf(value);
			fireTableCellUpdated(row, 0);
		}
	}
	
	/** returns the total lineNumbers of the script
	 * @return lineNumbers
	 */
	public int getLineNumbers() {
		return m_lineNumbers;
	}
	
}