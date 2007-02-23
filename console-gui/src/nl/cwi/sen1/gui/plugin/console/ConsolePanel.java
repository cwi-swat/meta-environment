package nl.cwi.sen1.gui.plugin.console;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class ConsolePanel extends JPanel {
	JTextArea textArea = new JTextArea();
	
	public ConsolePanel() {
		super(new BorderLayout());
		
		textArea.setEditable(false);
		textArea.setLineWrap(true);
		add(new JScrollPane(textArea), BorderLayout.CENTER);
		setVisible(true);
	}

	public void addMessage(String message) {
		textArea.append(message);
		textArea.append("\n");
		textArea.setCaretPosition(textArea.getDocument().getLength());

		int idealSize = 10000;
		int maxExcess = 500;
		int excess = textArea.getDocument().getLength() - idealSize;
		if (excess >= maxExcess) {
			textArea.replaceRange("", 0, excess);
		}
	}
}
