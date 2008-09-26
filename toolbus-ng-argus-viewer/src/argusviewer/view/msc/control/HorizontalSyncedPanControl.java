package argusviewer.view.msc.control;

import java.awt.event.MouseEvent;

import prefuse.Display;
import prefuse.controls.Control;
import prefuse.controls.PanControl;
import prefuse.util.ui.UILib;
import prefuse.visual.VisualItem;

/**
 * Mouse Pan Control that optionally synchronizes Horizontal Panning to another Display.
 *
 * @author: Arne Timmerman
 */
public class HorizontalSyncedPanControl extends PanControl{
	private final Display m_synchronizedDisplay;
	private final double m_initialVerticalPosition;

	private int m_horizontalMouseDownPosition;
	private int m_verticalMouseDownPosition;

	protected static final int MOUSE_PANNING_BUTTON = Control.LEFT_MOUSE_BUTTON;

	/**
	 * Create a Pan Control that allows Mouse Panning of the attached Display,
	 * without synchronizing the Panning events to another Display.
	 * The vertical Panning will never exceed the initial pan.
	 *
	 * @param initialVerticalPan the amount of vertical pan of the display where this control is enabled on
	 */
	public HorizontalSyncedPanControl(double initialVerticalPan){
		this(null, initialVerticalPan);
	}

	/**
	 * Create a Pan Control that allows Mouse Panning of the attached Display and
	 * synchronizes Panning events to the given other Display.
	 * The vertical Panning will never exceed the initial pan.
	 *
	 * @param synchronizedDisplay the display that must be synchronized with Horizontal Panning
	 * @param initialVerticalPan the amount of vertical pan of the display where this control is enabled on
	 */
	public HorizontalSyncedPanControl(Display synchronizedDisplay, double initialVerticalPan){
		super(MOUSE_PANNING_BUTTON);

		// Vertical panning of a Prefuse Display is negated compared to the vertical postion
		this.m_initialVerticalPosition = -initialVerticalPan;
		this.m_synchronizedDisplay = synchronizedDisplay;
	}

	/**
	 * {@inheritDoc}
	 */
	public void mousePressed(MouseEvent mouseEvent){
		if(UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			m_horizontalMouseDownPosition = mouseEvent.getX();
			m_verticalMouseDownPosition = mouseEvent.getY();
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseDragged(MouseEvent mouseEvent){
		if (UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			Display pannedDisplay = (Display) mouseEvent.getSource();

			int horizontalMousePosition = mouseEvent.getX();
			int horizontalMovement = horizontalMousePosition - m_horizontalMouseDownPosition;

			int verticalMousePosition = mouseEvent.getY();
			int verticalMovement =  verticalMousePosition - m_verticalMouseDownPosition;

			double currentVerticalPosition = pannedDisplay.getDisplayY();
			double newVerticalPosition = currentVerticalPosition - verticalMovement;

			// The maximum vertical position changes according to the scale of the display
			double maxVerticalPosition = m_initialVerticalPosition * pannedDisplay.getScale();

			// Pan both directions if the new vertical position does not exceeds the initial position
			if(newVerticalPosition >= maxVerticalPosition){
				panDisplay(pannedDisplay, horizontalMovement, verticalMovement);

			// Pan partial vertical if the new vertical position exceeds the initial position
			}else if((verticalMovement > 0) && (currentVerticalPosition != maxVerticalPosition)){
	   			int partialVerticalMovement = (int) (currentVerticalPosition - maxVerticalPosition);
				panDisplay(pannedDisplay, horizontalMovement, partialVerticalMovement);

			// Pan only horizontal
			}else{
				panDisplay(pannedDisplay, horizontalMovement, 0);
			}

			m_horizontalMouseDownPosition = horizontalMousePosition;
			m_verticalMouseDownPosition = verticalMousePosition;
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseReleased(MouseEvent mouseEvent){
		if(UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			m_horizontalMouseDownPosition = -1;
			m_verticalMouseDownPosition = -1;
		}
	}

	/**
	 * Pan the given display with the given amount of pan.
	 * Synchronize the synchronized Display horizontal if there is one.
	 *
	 * @param pannedDisplay the display that has te be panned
	 * @param verticalMovement the amount of vertical pan that has to be scrolled
	 * @param horizontalMovement the amount of horizontal pan that has to be scrolled
	 */
	private void panDisplay(Display pannedDisplay, int horizontalMovement, int verticalMovement){
		pannedDisplay.pan(horizontalMovement, verticalMovement);
		pannedDisplay.repaint();

		if(m_synchronizedDisplay != null){
			m_synchronizedDisplay.pan(horizontalMovement, 0);
			m_synchronizedDisplay.repaint();
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void itemPressed(VisualItem item, MouseEvent e){
        mousePressed(e);
    }

    /**
	 * {@inheritDoc}
	 */
	public void itemDragged(VisualItem item, MouseEvent e){
    	mouseDragged(e);
    }

	/**
	 * {@inheritDoc}
	 */
	public void itemReleased(VisualItem item, MouseEvent e){
    	mouseReleased(e);
    }
}
