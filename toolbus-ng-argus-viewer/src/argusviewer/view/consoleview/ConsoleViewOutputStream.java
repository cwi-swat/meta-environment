/**
 * 
 */
package argusviewer.view.consoleview;

import java.awt.Color;
import java.io.IOException;
import java.io.OutputStream;

/**
 * @author M. van Beest
 *
 */
public class ConsoleViewOutputStream extends OutputStream {
	public static final Color COLOR_BLACK = new Color(0, 0, 0);
	
	private ConsoleViewColorPane m_textPane;
	
	//we use a string as a buffer, because strings are immutable and so it isn't
	//possible to mix output streams
	private String m_outputBuffer;
	
	/**
	 * Constructs the object with the preferred output textarea
	 * @param textPane The area to where the console output is projected
	 */
	public ConsoleViewOutputStream(ConsoleViewColorPane textPane) {
		m_textPane = textPane;
		m_outputBuffer = "";
	}
	
	/**
	 * Overrides the write function of its parent so we can redirect the output.
	 * 
	 * @throws IOException throws an IOException when the buffer causes an error
	 * @param b	The value to be printed. This is a byte value
	 * @see java.io.OutputStream#write(int)
	 */
	@Override
	public void write(int b) throws IOException {
		m_outputBuffer += String.valueOf((char) b);
		
		//check for an endline
		if (((char) b) == '\n') {
			//output the string buffer to the gui and clear the buffer
			m_textPane.append(m_outputBuffer, COLOR_BLACK);
			m_outputBuffer = "";
		}
	}

}
