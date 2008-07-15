package argusviewer.view.msc.control;

import prefuse.Display;
import prefuse.visual.VisualItem;
import prefuse.controls.PanControl;
import prefuse.util.ui.UILib;

import java.awt.event.MouseEvent;

/**
 * Mouse Pan Control that only allows Horizontal Panning of the attached Display.
 * The Horizontal Panning can be synchronized to another Display. 
 *
 * @author: Arne Timmerman
 */
public class SyncedHorizontalPanControl extends PanControl {

	private Display m_synchronizedDisplay;

	private int m_horizontalMouseDownPosition;
	protected static final int MOUSE_PANNING_BUTTON = PanControl.LEFT_MOUSE_BUTTON;

	/**
	 * Create a Pan Control that only allow Horizontal Panning of the attached Display,
	 * without synchronizing the Panning events to another Display.
	 */
	public SyncedHorizontalPanControl() {

		this(null);
	}

	/**
	 * Create a Horizontal Pan Control that only allows Horizontal Panning and
	 * synchronises Panning events to the given other Display.
	 *
	 * @param synchronizedDisplay the display that must be synchronized with Horizontal Panning
	 */
	public SyncedHorizontalPanControl(Display synchronizedDisplay) {

		super(MOUSE_PANNING_BUTTON);
		this.m_synchronizedDisplay = synchronizedDisplay;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void mousePressed(MouseEvent mouseEvent) {

		if (UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)) {
			m_horizontalMouseDownPosition = mouseEvent.getX();
		}
	}

	/**
	 * {@inheritDoc}
	 */
    @Override
	public void mouseDragged(MouseEvent mouseEvent) {

		if (UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)) {
			Display pannedDisplay = (Display) mouseEvent.getSource();

			int currentHorizontalMousePosition = mouseEvent.getX();
			int horizontalMovement = currentHorizontalMousePosition - m_horizontalMouseDownPosition;

			pannedDisplay.pan(horizontalMovement, 0);
			pannedDisplay.repaint();

			if (m_synchronizedDisplay != null) {
				m_synchronizedDisplay.pan(horizontalMovement, 0);
				m_synchronizedDisplay.repaint();
			}

			m_horizontalMouseDownPosition = currentHorizontalMousePosition;
		}
	}

	/**
	 * {@inheritDoc}
	 */
    @Override
	public void mouseReleased(MouseEvent mouseEvent) {

		if (UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)) {
			m_horizontalMouseDownPosition = -1;
		}
	}

	/**
	 * {@inheritDoc}
	 */
    @Override
	public void itemPressed(VisualItem item, MouseEvent e) {
        mousePressed(e);
    }

    /**
	 * {@inheritDoc}
	 */
    @Override
	public void itemDragged(VisualItem item, MouseEvent e) {
    	mouseDragged(e);
    }

	/**
	 * {@inheritDoc}
	 */
    @Override
	public void itemReleased(VisualItem item, MouseEvent e) {
    	mouseReleased(e);
    }

}
