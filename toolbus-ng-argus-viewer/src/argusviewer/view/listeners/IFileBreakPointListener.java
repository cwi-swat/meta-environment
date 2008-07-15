package argusviewer.view.listeners;

/**
 * Listener for BreakPoint settings
 * 
 * @author Tim Van Laer
 */
public interface IFileBreakPointListener {

	/**
	 * A breakpoint is added at the given position.
	 * 
	 * @param fileName
	 *            The name of the t-script file.
	 * @param lineNumber
	 *            The line number of the breakpoint.
	 */
	void addBreakpoint(String fileName, int lineNumber);

	/**
	 * A breakpoint is removed at the given position.
	 * 
	 * @param fileName
	 *            The name of the t-script file.
	 * @param lineNumber
	 *            The line number of the breakpoint.
	 */
	void removeBreakpoint(String fileName, int lineNumber);
}
