package toolbus.parsercup;

/**
 * Like the name implies, this class contains position information (filename + begin and end line /
 * column).
 * 
 * @author Arnold Lankamp
 */
public class PositionInformation{
	private final String fileName;
	private final int offset;
	private final int beginLine;
	private final int beginColumn;
	private final int endLine;
	private final int endColumn;
	
	/**
	 * Constructor.
	 * 
	 * @param fileName
	 *            The name of the file the position is in.
	 * @param beginLine
	 *            The begin line.
	 * @param beginColumn
	 *            The begin column.
	 * @param endLine
	 *            The end line.
	 * @param endColumn
	 *            The end column.
	 */
	public PositionInformation(String fileName, int offset, int beginLine, int beginColumn, int endLine, int endColumn){
		this.offset = offset;
		this.fileName = fileName;
		this.beginLine = beginLine;
		this.beginColumn = beginColumn;
		this.endLine = endLine;
		this.endColumn = endColumn;
	}
	
	/**
	 * 
	 * @return the character offset of the file this position is in
	 */
	public int getOffset() {
		return offset;
	}
	/**
	 * Returns the name of the file this position is in.
	 * 
	 * @return The name of the file this position is in.
	 */
	public String getFileName(){
		return fileName;
	}
	
	/**
	 * Returns the begin line of the position.
	 * 
	 * @return The begin line of the position.
	 */
	public int getBeginLine(){
		return beginLine;
	}
	
	/**
	 * Returns the begin column of the position.
	 * 
	 * @return The begin column of the position.
	 */
	public int getBeginColumn(){
		return beginColumn;
	}
	
	/**
	 * Retuns the end line of the position.
	 * 
	 * @return The end line of the position.
	 */
	public int getEndLine(){
		return endLine;
	}
	
	/**
	 * Retuns the end column of the position.
	 * 
	 * @return The end column of the position.
	 */
	public int getEndColumn(){
		return endColumn;
	}
	
	/**
	 * Returns the serial representation of this position in the following format: filename :
	 * beginline,begincolumn - endline,endcolumn
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(fileName);
		sb.append(" @ ");
		sb.append(beginLine);
		sb.append(",");
		sb.append(beginColumn);
		sb.append(" - ");
		sb.append(endLine);
		sb.append(",");
		sb.append(endColumn);
		return sb.toString();
	}
}
