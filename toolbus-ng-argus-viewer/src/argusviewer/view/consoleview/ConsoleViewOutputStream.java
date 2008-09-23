/**
 * 
 */
package argusviewer.view.consoleview;

import java.awt.Color;
import java.io.IOException;
import java.io.OutputStream;

/**
 * @author M. van Beest
 */
public class ConsoleViewOutputStream extends OutputStream {
	public static final Color COLOR_BLACK = new Color(0, 0, 0);
	
	private final ConsoleViewColorPane textPane;
	
	private volatile StringBuilder outputBuffer;
	
	/**
	 * Constructs the object with the preferred output textarea
	 * @param textPane The area to where the console output is projected
	 */
	public ConsoleViewOutputStream(ConsoleViewColorPane textPane) {
		this.textPane = textPane;
		outputBuffer = new StringBuilder();
	}
	
	/**
	 * Overrides the write function of its parent so we can redirect the output.
	 * 
	 * @throws IOException throws an IOException when the buffer causes an error
	 * @param b	The value to be printed. This is a byte value
	 * @see java.io.OutputStream#write(int)
	 */
	public synchronized void write(int b) throws IOException{
		outputBuffer.append((char) b);
		
		//check for an endline
		if (((char) b) == '\n') {
			//output the string buffer to the gui and clear the buffer
			textPane.append(outputBuffer.toString(), COLOR_BLACK);
			outputBuffer = new StringBuilder();
		}
	}

}
