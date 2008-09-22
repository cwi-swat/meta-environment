package argusviewer.gui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import argusviewer.toolbus.DataComm;
import argusviewer.util.ArgusSettings;
import argusviewer.view.listeners.IStateControlListener;


/**
 * ControlPanel
 * 
 * Contains buttons to control the Toolbus. Shows status.
 * 
 * @author J.Flint
 * @author T.van Laer
 * @author R.Schuddeboom
 * @author S.Preeker
 * @author J. van den Bos
 * @author M. van Beest
 */
public class ControlPanel extends JPanel implements ActionListener, IStateControlListener, ChangeListener {
	private static final long serialVersionUID = -4188073307544842081L;

	private final JSlider m_runSpeedSlider;
	private final JButton m_startButton;
	private final JButton m_stepButton;
	private final JButton m_stopButton;
	private final JButton m_terminateButton;
	private final JLabel m_statusLabel;
	private final JLabel m_sliderLabel;
	private final JLabel m_sliderValueLabel;
	
	private static final int BUTTON_HORIZONTAL_PADDING = 7;
	private static final int BUTTON_VERTICAL_PADDING = 4;	

	public final static int RUN_SPEED_MAX = 0; // 0 msec
	public final static int RUN_SPEED_MIN = 5000; // 5 seconds
	public final static int RUN_SPEED_INIT = RUN_SPEED_MAX;
	private final static int RUN_SPEED_SPACING_MAJOR = 1000; // 1 seconds
	private final static int RUN_SPEED_SPACING_MINOR = 100; // 10th second
	private final static int SLIDER_HUNDRED_MSEC = 100;
	private final static int SLIDER_DECIMAL_DIVIDER = 10;
	
	private final DataComm m_dataComm;
	private final ArgusViewerGUI m_gui;

	/**
	 * Creates a new ControlPanel with buttons to control the debugging.
	 * 
	 * @param dataComm a reference to our DataComm instance
	 * @param gui a reference to the gui
	 */
	public ControlPanel(DataComm dataComm, ArgusViewerGUI gui) {
		m_dataComm = dataComm;
		m_dataComm.getControlSync().register(this);

		m_gui = gui;

		// get the value from the settings or refer to standard settings
		String runSpeedSlider = ArgusSettings.getInstance().getAttribute(
				"controlpanel.runspeedslider", String.valueOf(RUN_SPEED_INIT));
		
		m_dataComm.getControlSync().setSteppingDelay(
				Integer.parseInt(runSpeedSlider));

		setLayout(new BorderLayout());

		JPanel statusPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
		JLabel statusInfoLabel = new JLabel("Status: ");
		m_statusLabel = new JLabel("waiting");
		Font f = m_statusLabel.getFont();
		m_statusLabel.setFont(f.deriveFont(f.getStyle() ^ Font.BOLD));
		statusInfoLabel.setVerticalTextPosition(SwingConstants.CENTER);
		m_statusLabel.setVerticalTextPosition(SwingConstants.CENTER);
		statusPanel.add(statusInfoLabel);
		statusPanel.add(m_statusLabel);

		JPanel controlPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));

		m_sliderLabel = new JLabel("Delay:");
		controlPanel.add(m_sliderLabel);

		m_sliderValueLabel = new JLabel();		
		controlPanel.add(m_sliderValueLabel);

		m_runSpeedSlider = new JSlider(SwingConstants.HORIZONTAL, RUN_SPEED_MAX,
				RUN_SPEED_MIN, RUN_SPEED_INIT);
		m_runSpeedSlider.setMajorTickSpacing(RUN_SPEED_SPACING_MAJOR);
		m_runSpeedSlider.setMinorTickSpacing(RUN_SPEED_SPACING_MINOR);
		m_runSpeedSlider.setPaintTicks(true);
		m_runSpeedSlider.addChangeListener(this);
		setSliderValue();
		controlPanel.add(m_runSpeedSlider);

		Insets buttonInsets = new Insets(BUTTON_VERTICAL_PADDING, BUTTON_HORIZONTAL_PADDING, BUTTON_VERTICAL_PADDING, BUTTON_HORIZONTAL_PADDING);
		
		m_startButton = new JButton("Run");
		m_startButton.addActionListener(this);
		m_startButton.setMargin(buttonInsets);
		controlPanel.add(m_startButton);

		m_stepButton = new JButton("Step");
		m_stepButton.addActionListener(this);
		m_stepButton.setMargin(buttonInsets);
		controlPanel.add(m_stepButton);

		m_stopButton = new JButton("Stop");
		m_stopButton.addActionListener(this);
		m_stopButton.setMargin(buttonInsets);
		controlPanel.add(m_stopButton);

		m_terminateButton = new JButton("Terminate");
		m_terminateButton.addActionListener(this);
		m_terminateButton.setMargin(buttonInsets);
		controlPanel.add(m_terminateButton);

		add(statusPanel, BorderLayout.LINE_START);
		add(controlPanel, BorderLayout.LINE_END);
	}

	/**
	 * Invoked when an action occurs.
	 * 
	 * @param e
	 *            ActionEvent
	 */
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == m_startButton) {
			// use the value set with the slider
			m_dataComm.getControlSync().doSteppingRun();
		} else if (e.getSource() == m_stepButton) {
			m_dataComm.getControlSync().doStep();
		} else if (e.getSource() == m_stopButton) {
			m_dataComm.getControlSync().doStop();
		} else if (e.getSource() == m_terminateButton) {
			m_gui.shutdown();
		} else {
			throw new RuntimeException(
					"ControlPanel:actionPerformed called with invalid parameter");
		}
	}

	private void setSliderValue() {
		float value = (m_dataComm.getControlSync()
				.getSteppingDelay() / SLIDER_HUNDRED_MSEC)
				/ (float) SLIDER_DECIMAL_DIVIDER;
			
		m_sliderValueLabel.setText(String.valueOf(value)
				+ " sec");
		m_runSpeedSlider.setValue(m_dataComm.getControlSync().getSteppingDelay());
	}

	/**
	 * Invoked when a slider event occurs
	 * 
	 * @param e
	 *            The ChangeEvent with event information
	 */
	public void stateChanged(ChangeEvent e) {
		if (e.getSource() == m_runSpeedSlider) {
			m_dataComm.getControlSync().setSteppingDelay(
					m_runSpeedSlider.getValue());
			setSliderValue();
			ArgusSettings.getInstance().setAttribute(
					"controlpanel.runspeedslider",
					String.valueOf(m_dataComm.getControlSync().getSteppingDelay()));
		} else {
			// update the label and the slider.
			m_runSpeedSlider.setValue(m_dataComm.getControlSync()
					.getSteppingDelay());
		}

	}

	/**
	 * {@inheritDoc}
	 */
	public void setState(int state) {
		String[] states = new String[] { "unknown", "stopping", "waiting",
				"ready", "running", "stepping" };
		m_statusLabel.setText(states[state + 1]);
	}

	/**
	 * @return our preferred screen position
	 */
	public String getPreferredPosition() {
		return "BottomRight";
	}
}
