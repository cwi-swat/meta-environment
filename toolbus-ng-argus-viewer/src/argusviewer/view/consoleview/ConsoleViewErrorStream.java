package argusviewer.view.consoleview;

import java.awt.Color;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

/**
 * @author M. van Beest
 * 
 */
public class ConsoleViewErrorStream extends OutputStream {
	public static final Color COLOR_RED = new Color(255, 0, 0);

	private ConsoleViewColorPane m_textPane;

	private PrintStream m_originalErrorStream;

	// we use a string as a buffer, because strings are immutable and so it
	// isn't
	// possible to mix output streams
	private String m_errorBuffer;

	/**
	 * Constructs the object with the preferred output textarea
	 * 
	 * @param textPane
	 *            The area to where the console output is projected
	 * @param originalErrorStream
	 *            The original errorstream to copy the exceptions to.
	 */
	public ConsoleViewErrorStream(ConsoleViewColorPane textPane,
			PrintStream originalErrorStream) {
		m_textPane = textPane;
		m_errorBuffer = "";

		m_originalErrorStream = originalErrorStream;
	}

	/**
	 * Overrides the write function of its parent so we can redirect the output.
	 * The output of the errors are also redirected to the console.
	 * 
	 * @throws IOException
	 *             throws an IOException when the buffer causes an error
	 * @param b
	 *            The value to be printed. This is a byte value
	 * @see java.io.OutputStream#write(int)
	 */
	@Override
	public void write(int b) throws IOException {		
		//check the original stream and copy the output to there.
		if (m_originalErrorStream != null) {
			m_originalErrorStream.write(b);
		}
		
		m_errorBuffer += String.valueOf((char) b);

		// check for an endline
		if (((char) b) == '\n') {
			// output the string buffer to the gui and clear the buffer			
			m_textPane.append(m_errorBuffer, COLOR_RED);
			m_errorBuffer = "";
		}
	}
}
