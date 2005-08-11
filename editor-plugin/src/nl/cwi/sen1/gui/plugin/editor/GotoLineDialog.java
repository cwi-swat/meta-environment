package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;

import javax.swing.AbstractAction;
import javax.swing.ActionMap;
import javax.swing.InputMap;
import javax.swing.JComponent;
import javax.swing.KeyStroke;

public class GotoLineDialog extends BaseDialog {

	private javax.swing.JPanel buttonPanel;

	private javax.swing.JButton cancelButton;

	private javax.swing.JTextField lineNumberField;

	private javax.swing.JLabel lineNumberLabel;

	private javax.swing.JPanel mainPanel;

	private javax.swing.JButton okButton;

	public int getLineNumber() {
		String line = lineNumberField.getText();
		try {
			return Integer.parseInt(line);
		} catch (NumberFormatException ex) {
			return -1;
		}
	}
	
	public void setLineNumber(int lineNumber) {
		lineNumberField.setText(Integer.toString(lineNumber + 1));
	}

	public GotoLineDialog(Container parent) {
		// super(textArea.getFrame(), false);
		super();
		setModal(true);
		setTitle("Goto line");
		initComponents();

		// defining key bindings
		InputMap inputMap = this.getRootPane().getInputMap(
				JComponent.WHEN_IN_FOCUSED_WINDOW);
		inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), "escape");
		inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "enter");

		ActionMap actionMap = this.getRootPane().getActionMap();
		actionMap.put("escape", new AbstractAction() {
			public void actionPerformed(ActionEvent evt) {
				GotoLineDialog.this.hide();
			}
		});
		actionMap.put("enter", new AbstractAction() {
			public void actionPerformed(ActionEvent evt) {
				GotoLineDialog.this.hide();
			}
		});

		centerDialog(parent);
	}

	private void initComponents() {
		java.awt.GridBagConstraints gridBagConstraints;

		mainPanel = new javax.swing.JPanel();
		lineNumberLabel = new javax.swing.JLabel();
		lineNumberField = new javax.swing.JTextField();
		buttonPanel = new javax.swing.JPanel();
		okButton = new javax.swing.JButton();
		cancelButton = new javax.swing.JButton();

		addWindowListener(new java.awt.event.WindowAdapter() {
			public void windowClosing(java.awt.event.WindowEvent evt) {
				closeDialog(evt);
			}
		});

		mainPanel.setLayout(new java.awt.GridBagLayout());

		lineNumberLabel.setText("Line number");
		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.anchor = java.awt.GridBagConstraints.EAST;
		gridBagConstraints.insets = new java.awt.Insets(3, 3, 3, 3);
		mainPanel.add(lineNumberLabel, gridBagConstraints);

		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.fill = java.awt.GridBagConstraints.HORIZONTAL;
		gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.insets = new java.awt.Insets(3, 3, 3, 3);
		mainPanel.add(lineNumberField, gridBagConstraints);

		getContentPane().add(mainPanel, java.awt.BorderLayout.CENTER);

		buttonPanel
				.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.RIGHT));

		okButton.setText("OK");
		okButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				GotoLineDialog.this.hide();
			}
		});

		buttonPanel.add(okButton);

		cancelButton.setText("Cancel");
		cancelButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				GotoLineDialog.this.hide();
			}
		});

		buttonPanel.add(cancelButton);

		getContentPane().add(buttonPanel, java.awt.BorderLayout.SOUTH);

		pack();
	}
}
