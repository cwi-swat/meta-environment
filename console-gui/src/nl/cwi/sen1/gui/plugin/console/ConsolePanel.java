package nl.cwi.sen1.gui.plugin.console;

import java.awt.BorderLayout;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class ConsolePanel extends JPanel {
	PipedInputStream piOut;
	PipedInputStream piErr;
	PipedOutputStream poOut;
	PipedOutputStream poErr;
	JTextArea textArea = new JTextArea();

	public ConsolePanel() {
		textArea.setEditable(false);
		textArea.setRows(20);
		textArea.setColumns(50);
		add(new JScrollPane(textArea), BorderLayout.CENTER);
		setVisible(true);
	}

	public void addMessage(String message) {
		textArea.append(message);

		textArea.setCaretPosition(textArea.getDocument().getLength());

		int idealSize = 1000;
		int maxExcess = 500;
		int excess = textArea.getDocument().getLength() - idealSize;
		if (excess >= maxExcess) {
			textArea.replaceRange("", 0, excess);
		}
	}
}
