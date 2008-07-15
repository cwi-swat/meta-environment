package argusviewer.view.msc;

import prefuse.Display;
import prefuse.visual.VisualItem;

import javax.swing.JPanel;
import javax.swing.ToolTipManager;
import argusviewer.view.msc.control.HorizontalSyncedPanControl;
import argusviewer.view.msc.control.MSCToolTipControl;
import argusviewer.view.msc.control.SyncedHorizontalPanControl;
import argusviewer.view.msc.control.SyncedZoomControl;
import argusviewer.view.msc.control.WheelScrollControl;
import argusviewer.view.msc.visual.EntityRenderer;
import argusviewer.view.msc.visual.MSCItemSorter;
import argusviewer.view.msc.visual.MSCVisualization;
import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.geom.Point2D;

/**
 * Create a View on the Message Sequence Chart. The View consists
 * of two displays on the Visualization of the Message Sequence Chart.
 *
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Arne Timmerman
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author Alexander Bij
 * @author Roberto vd Linden
 */
@SuppressWarnings("serial")
public class MSCView extends JPanel {

	protected static final int FOCUS_ANIMATE_MILLISECONDS = 100;
	private static final int TOOLTIP_DELAY = 50;

	private static final double HORIZONTAL_DISPLAY_OFFSET = 40;
	private static final double VERTICAL_TOP_DISPLAY_OFFSET = 15;
	private static final int TOP_DISPLAY_WIDTH = -1;

	protected static final double HORIZONTAL_DISPLAY_PAN;
	protected static final double VERTICAL_TOP_DISPLAY_PAN;
	protected static final double VERTICAL_MAIN_DISPLAY_PAN;

	protected static final int TOP_DISPLAY_HEIGHT;

	// Calculate the initial panning values of the displays
	static {
		double entityHalfSize = EntityRenderer.ENTITY_BASESIZE / 2.0;
		HORIZONTAL_DISPLAY_PAN = entityHalfSize + HORIZONTAL_DISPLAY_OFFSET;
		VERTICAL_TOP_DISPLAY_PAN = entityHalfSize + VERTICAL_TOP_DISPLAY_OFFSET;
		VERTICAL_MAIN_DISPLAY_PAN = -entityHalfSize;
		TOP_DISPLAY_HEIGHT = (int) (EntityRenderer.ENTITY_BASESIZE + VERTICAL_TOP_DISPLAY_OFFSET);
	}

	private Display m_topDisplay;
	private Display m_mainDisplay;

	private MSCVisualization m_mscVisualization;

	/**
	 * Create the View on the visualization of the Message Sequence Chart.
	 * @param mscVisualization the visualization of the Message Sequence Chart
	 */
	public MSCView(MSCVisualization mscVisualization) {
		this.m_mscVisualization = mscVisualization;

		createMainDisplay();
		createTopDisplay();
		
		createDisplayControls();

		setLayout(new BorderLayout());
		add(m_topDisplay, BorderLayout.NORTH);
		add(m_mainDisplay, BorderLayout.CENTER);
	}

	/**
	 * Sets up the main display component for the visualization.
	 * The main display only shows the swimlanes and executed statements.
	 */
	private void createMainDisplay() {
		m_mainDisplay = new Display(m_mscVisualization.getVisualization());
		m_mainDisplay.setItemSorter(new MSCItemSorter());
		m_mainDisplay.setDoubleBuffered(true);
		m_mainDisplay.panAbs(HORIZONTAL_DISPLAY_PAN, VERTICAL_MAIN_DISPLAY_PAN);
	}

	/**
	 * Sets up the top display component for the visualization.
	 * The top display only shows the processes and tools.
	 */
	private void createTopDisplay() {
		m_topDisplay = new Display(m_mscVisualization.getVisualization());
		m_topDisplay.setItemSorter(new MSCItemSorter());
		m_topDisplay.setDoubleBuffered(true);
		m_topDisplay.panAbs(HORIZONTAL_DISPLAY_PAN, VERTICAL_TOP_DISPLAY_PAN);
		m_topDisplay.setSize(TOP_DISPLAY_WIDTH, TOP_DISPLAY_HEIGHT);
	}

	/**
	 * Create the control listeners for the display components.
	 * The control listeners handles mouse, key and tooltip controls.
	 */
	private void createDisplayControls() {
		m_mainDisplay.addControlListener(new WheelScrollControl(VERTICAL_MAIN_DISPLAY_PAN));
		m_mainDisplay.addControlListener(new HorizontalSyncedPanControl(m_topDisplay, VERTICAL_MAIN_DISPLAY_PAN));
		m_mainDisplay.addControlListener(new SyncedZoomControl(m_topDisplay,
			new Point(0, 0), new Point(0, TOP_DISPLAY_HEIGHT)));
		m_mainDisplay.addControlListener(new MSCToolTipControl());

		m_topDisplay.addControlListener(new SyncedHorizontalPanControl(m_mainDisplay));
		m_topDisplay.addControlListener(new SyncedZoomControl(m_mainDisplay,
			new Point(0, TOP_DISPLAY_HEIGHT), new Point(0, 0)));
		m_topDisplay.addControlListener(new MSCToolTipControl());

		ToolTipManager.sharedInstance().setInitialDelay(TOOLTIP_DELAY);
	}

	/**
	 * Refresh the view on the contents of the Message Sequence Chart.
	 */
	public void refreshDisplays() {
		if (m_mainDisplay != null) {
			m_mainDisplay.invalidate();
			m_mainDisplay.repaint();
		}

		if (m_topDisplay != null) {
			m_topDisplay.invalidate();
			m_topDisplay.repaint();
		}
	}

	/**
	 * Set the horizontal focus to the given entity.
	 * @param entity the entity to set focus on
	 */
	public void setEntityFocus(VisualItem entity) {
		double horizontalFocusPosition = entity.getX();

		setHorizontalFocus(m_mainDisplay, horizontalFocusPosition);
		setHorizontalFocus(m_topDisplay, horizontalFocusPosition);
	}

	/**
	 * Set the vertical focus to the given statement.
	 * @param statement the statement to focus on
	 */
	public void setStatementFocus(VisualItem statement) {
		double verticalFocusPosition = statement.getY();

		setVerticalFocus(m_mainDisplay, verticalFocusPosition, VERTICAL_MAIN_DISPLAY_PAN);	
	}

	/**
	 * Set the horizontal focus of the given Display to the given horizontal position.
	 * The position will be focused in the center of the Display.
	 * 
	 * @param display the display to set the focus to
	 * @param horizontalFocusPosition the horizontal position to focus
	 */
	protected void setHorizontalFocus(Display display, double horizontalFocusPosition) {

		// Determine the horizontal center of the display
		double horizontalScreenCenter = display.getWidth() / 2.0;
		Point2D.Double horizontalDisplayCenter = new Point2D.Double(horizontalScreenCenter, 0);
		display.getAbsoluteCoordinate(horizontalDisplayCenter, horizontalDisplayCenter);

		// Determine the horizontal movement to pan the item to the center of the display
		double horizontalMovement = horizontalDisplayCenter.getX() - horizontalFocusPosition;

		display.animatePanAbs(horizontalMovement, 0, FOCUS_ANIMATE_MILLISECONDS);
	}

	/**
	 * Set the vertical focus of the given Display to the given vertical position.
	 * The position is focussed in the middle of the display, if this not exceeds
	 * the given initial vertical pan of the display.
	 *
	 * @param display the display to set the focus to
	 * @param verticalFocusPosition the vertical position to focus
	 * @param initialVerticalPan the amount of initial vertical pan of the display
	 */
	protected void setVerticalFocus(Display display, double verticalFocusPosition, double initialVerticalPan) {

		// Determine the vertical center of the display
		double verticalScreenCenter = display.getHeight() / 2.0;
		Point2D.Double verticalDisplayCenter = new Point2D.Double(0, verticalScreenCenter);
		display.getAbsoluteCoordinate(verticalDisplayCenter, verticalDisplayCenter);

		// Determine the vertical movement to pan the item to the center of the display
		double verticalMovement = verticalDisplayCenter.getY() - verticalFocusPosition;

		Point2D.Double displayOffset = new Point2D.Double(0, 0);
		display.getAbsoluteCoordinate(displayOffset, displayOffset);

		// Pan only if the new vertical position does not exceeds the initial position
		double newVerticalPosition = displayOffset.getY() - verticalMovement;
		double maxVerticalPosition = (-initialVerticalPan) * display.getScale();

		if (newVerticalPosition >= maxVerticalPosition) {
			display.animatePanAbs(0, verticalMovement, FOCUS_ANIMATE_MILLISECONDS);
		}
	}

	/**
	 * @return the main display camera
	 */
	protected Display getMainDisplay() {
		return m_mainDisplay;
	}

	/**
	 * @return the top display camera
	 */
	protected Display getTopDisplay() {
		return m_topDisplay;
	}
}
