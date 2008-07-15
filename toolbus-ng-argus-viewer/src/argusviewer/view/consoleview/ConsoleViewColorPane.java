/**
 * 
 */
package argusviewer.view.consoleview;

import java.awt.Color;

import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import argusviewer.ExceptionReporter;


/**
 * This class gives the ability to do colored output for the ConsoleView
 * 
 * @author M. van Beest
 * 
 */
@SuppressWarnings("serial")
public class ConsoleViewColorPane extends JTextPane {
	/**
	 * Appends the text to the component in the given color
	 * 
	 * @param text
	 *            Append the given text to the component
	 * @param color
	 *            The color to be used for the text
	 */
	public void append(String text, Color color) {
		StyledDocument styleDocument = this.getStyledDocument();

		/*
		 * according to the JavaDoc in the addStyle function a style name must be unique.
		 * if the name isnt unique, it will be overwritten. this is good for us, because
		 * the styles wont keep piling up, hogging memory.
		 */ 
		Style style = styleDocument.addStyle("Style", null);
		StyleConstants.setForeground(style, color);
		
		try {
			styleDocument.insertString(styleDocument.getLength(), text, style);
		} catch (BadLocationException e) {
			ExceptionReporter.report(e.getMessage());
		}
		
		this.setDocument(styleDocument);
		
		//for scrolling purposes
		this.setCaretPosition(styleDocument.getLength());
	}
}
