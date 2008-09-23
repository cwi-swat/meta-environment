package argusviewer.view.consoleview;

import java.awt.Color;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

/**
 * @author M. van Beest
 */
public class ConsoleViewErrorStream extends OutputStream {
	public static final Color COLOR_RED = new Color(255, 0, 0);

	private final ConsoleViewColorPane textPane;

	private final PrintStream originalErrorStream;
	
	private volatile StringBuilder errorBuffer;

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
		this.textPane = textPane;
		this.originalErrorStream = originalErrorStream;
		
		errorBuffer = new StringBuilder();
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
	public synchronized void write(int b) throws IOException {		
		//check the original stream and copy the output to there.
		if (originalErrorStream != null) {
			originalErrorStream.write(b);
		}
		
		errorBuffer.append((char) b);

		// check for an endline
		if (((char) b) == '\n') {
			// output the string buffer to the gui and clear the buffer			
			textPane.append(errorBuffer.toString(), COLOR_RED);
			errorBuffer = new StringBuilder();
		}
	}
}
