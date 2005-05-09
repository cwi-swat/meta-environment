package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Insets;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class ProgressList extends JDialog {
	private JTextArea taskOutput;

	private String newline = "\n";

	public ProgressList(JFrame owner, String title, boolean modal) {
		super(owner, title, modal);
		taskOutput = new JTextArea(10, 60);
		taskOutput.setMargin(new Insets(5, 5, 5, 5));
		taskOutput.setEditable(false);

		JPanel panel = new JPanel();

		getContentPane().add(panel, BorderLayout.PAGE_START);
		getContentPane().add(new JScrollPane(taskOutput), BorderLayout.CENTER);
		pack();
	}
	
	public void addMessage(String message) {
		taskOutput.append(message + newline);
		taskOutput.setCaretPosition(taskOutput.getDocument().getLength());
	}
}