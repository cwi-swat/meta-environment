package argusviewer.gui;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import argusviewer.ApplicationSettings;
import argusviewer.util.ArgusSettings;


/**
 * The settings dialog for application wide settings.
 *
 * @author Hidde Baggelaar
 * @author Riccardo Lippolis
 * @author Arne Timmerman
 * @author Roberto van der Linden
 */
@SuppressWarnings("serial")
final class SettingsDialog extends JDialog implements ActionListener {

	private static final String FOCUSTITLE = "Message Sequence Chart";
	private static final String HISTORYTITLE = "History";
	private static final String TITLE = "Application Settings";
	private static final int INPUTFIELDCOLUMNS = 5;
	private JTextField m_limitField;
	private JCheckBox m_focusCheckBox;
	private JCheckBox m_autoCollapseCheckBox;
	private static JFrame parent;

	public static void setParent(JFrame parentFrame) {
		parent = parentFrame;
	}

	/**
	 * Constructs a settings dialog for application wide settings
	 */
	private SettingsDialog() {
		super(parent);

		setTitle(TITLE);
		setModal(true);
		setLayout(new BorderLayout());

		JPanel settingsPanel = new JPanel(new GridLayout(2, 1));
		JPanel historyPanel = createHistoryPanel();
		settingsPanel.add(historyPanel);

		JPanel mscSettingsPanel = createMscSettingsPanel();
		settingsPanel.add(mscSettingsPanel);
		add(settingsPanel, BorderLayout.CENTER);

		JPanel buttonPanel = createButtonPanel();
		add(buttonPanel, BorderLayout.SOUTH);
	}


	/**
	 * Create the panel for the Message Sequence Chart settings
	 *
	 * @return The Message Sequence Chart settings panel
	 */
	private JPanel createMscSettingsPanel() {
		JPanel mscPanel = new JPanel(new GridLayout(2, 1));
		m_focusCheckBox = new JCheckBox("Automatic statement focus");
		m_autoCollapseCheckBox = new JCheckBox("Collapse whitespace between statements");

		ArgusSettings settings = ArgusSettings.getInstance();
		boolean statementFocusEnabled = settings.getAttributeValue("MSC", "statementFocus", "false").equals("true");
		m_focusCheckBox.setSelected(statementFocusEnabled);

		boolean collapseEnabled = settings.getAttributeValue("MSC", "collapse", "true").equals("true");
		m_autoCollapseCheckBox.setSelected(collapseEnabled);

		mscPanel.setBorder(BorderFactory.createTitledBorder(FOCUSTITLE));
		mscPanel.add(m_focusCheckBox);
		mscPanel.add(m_autoCollapseCheckBox);
		return mscPanel;
	}

	/**
	 * Create the panel for the history setting
	 *
	 * @return The history setting panel
	 */
	private JPanel createHistoryPanel() {
		JPanel historyPanel = new JPanel();
		historyPanel.setBorder(BorderFactory.createTitledBorder(HISTORYTITLE));
		historyPanel.add(new JLabel("History limit:"));

		m_limitField = new JTextField();
		m_limitField.setColumns(INPUTFIELDCOLUMNS);
		m_limitField.setHorizontalAlignment(SwingConstants.TRAILING);
		m_limitField.setText("" + ApplicationSettings.getHistoryLimit());
		m_limitField.setActionCommand("Save");
		m_limitField.addActionListener(this);

		historyPanel.add(m_limitField);
		historyPanel.add(new JLabel("steps"));
		return historyPanel;
	}

	/**
	 * Create the panel for the Save and Cancel buttons
	 *
	 * @return The buttons panel
	 */
	private JPanel createButtonPanel() {
		JPanel buttonPanel = new JPanel();

		JButton save = new JButton("Save");
		save.setActionCommand("Save");
		save.addActionListener(this);
		buttonPanel.add(save);

		JButton cancel = new JButton("Cancel");
		cancel.setActionCommand("Cancel");
		cancel.addActionListener(this);
		buttonPanel.add(cancel);
		return buttonPanel;
	}


	/**
	 * Opens a settings dialog that can store the history settings
	 */
	public static void open() {
		SettingsDialog dialog = new SettingsDialog();
		dialog.pack();
		dialog.setLocationRelativeTo(parent);
		dialog.setVisible(true);
	}

	/**
	 * Processes a button clicked event
	 *
	 * @param e the event
	 */
	public void actionPerformed(ActionEvent e) {
		String command = e.getActionCommand();
		if (command.equals("Save")) {
			ArgusSettings settings = ArgusSettings.getInstance();
			saveHistorySettings();
			saveFocusSettings(settings);
			saveCollapseSettings(settings);

		} else if (command.equals("Cancel")) {
			dispose();
		}
	}

	/**
	 * Save the history settings with the new value.
	 */
	private void saveHistorySettings() {
		try {
			int steps = Integer.parseInt(m_limitField.getText());
			if (steps < 0) {
				throw new NumberFormatException("Integer should be a positive number");
			}
			ApplicationSettings.setHistoryLimit(steps);
			dispose();
		} catch (NumberFormatException e1) {
			JOptionPane.showMessageDialog(this, "You inserted an invalid value in the steps history field: " + e1.getMessage(), "Input Error", JOptionPane.WARNING_MESSAGE);
		}
	}

	/**
	 * Save the focus settings.
	 *
	 * @param settings instance of the ArgusSettings
	 */
	private void saveFocusSettings(ArgusSettings settings) {
		if (m_focusCheckBox.isSelected()) {
			settings.setAttribute("MSC", "statementFocus", "true");
		} else {
			settings.setAttribute("MSC", "statementFocus", "false");
		}
	}

	/**
	 * Save the collapse settings.
	 *
	 * @param settings instance of the ArgusSettings
	 */
	private void saveCollapseSettings(ArgusSettings settings) {
		if (m_autoCollapseCheckBox.isSelected()) {
			settings.setAttribute("MSC", "collapse", "true");
		} else {
			settings.setAttribute("MSC", "collapse", "false");
		}
	}
}
