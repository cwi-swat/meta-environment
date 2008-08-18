package nl.cwi.sen1.visplugin.treeplugin;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.text.Element;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;

/**
 * creates a window to view a textpane containing a file with a specific style 
 * @author Qais
 *
 */
public class TreeFileContentViewer {
	static JTextPane m_textArea;
	int size; 

	/**
	 * @param codeDoc the textpane that contains file
	 * @param filePath the absolute path to the file that the textpane contains
	 */
	public TreeFileContentViewer(JTextPane codeDoc, String filePath){
		m_textArea = codeDoc;
        JFrame frame = new JFrame(filePath);
        frame.setSize(500, 600);
		JPanel viewer = new JPanel(new BorderLayout());
	    JScrollPane fileArea = new JScrollPane(codeDoc);
	    viewer.add(fileArea, BorderLayout.CENTER);
        frame.setContentPane(viewer);
        frame.setVisible(true);
	}

	/**
	 * @param caretPosition the current mouse-clicks place 
	 */
	public void scrollTo(int caretPosition){
		m_textArea.setCaretPosition(caretPosition);

	}

}
