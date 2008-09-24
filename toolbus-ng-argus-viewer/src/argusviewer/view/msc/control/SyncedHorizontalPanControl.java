package argusviewer.view.msc.control;

import java.awt.event.MouseEvent;

import prefuse.Display;
import prefuse.controls.Control;
import prefuse.controls.PanControl;
import prefuse.util.ui.UILib;
import prefuse.visual.VisualItem;

/**
 * Mouse Pan Control that only allows Horizontal Panning of the attached Display.
 * The Horizontal Panning can be synchronized to another Display. 
 *
 * @author: Arne Timmerman
 */
public class SyncedHorizontalPanControl extends PanControl{
	protected static final int MOUSE_PANNING_BUTTON = Control.LEFT_MOUSE_BUTTON;
	
	private final Display m_synchronizedDisplay;

	private int m_horizontalMouseDownPosition;

	/**
	 * Create a Horizontal Pan Control that only allows Horizontal Panning and
	 * synchronises Panning events to the given other Display.
	 *
	 * @param synchronizedDisplay the display that must be synchronized with Horizontal Panning
	 */
	public SyncedHorizontalPanControl(Display synchronizedDisplay){
		super(MOUSE_PANNING_BUTTON);
		
		this.m_synchronizedDisplay = synchronizedDisplay;
	}

	/**
	 * {@inheritDoc}
	 */
	public void mousePressed(MouseEvent mouseEvent){
		if(UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			m_horizontalMouseDownPosition = mouseEvent.getX();
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseDragged(MouseEvent mouseEvent){
		if(UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			Display pannedDisplay = (Display) mouseEvent.getSource();

			int currentHorizontalMousePosition = mouseEvent.getX();
			int horizontalMovement = currentHorizontalMousePosition - m_horizontalMouseDownPosition;

			pannedDisplay.pan(horizontalMovement, 0);
			pannedDisplay.repaint();

			if(m_synchronizedDisplay != null){
				m_synchronizedDisplay.pan(horizontalMovement, 0);
				m_synchronizedDisplay.repaint();
			}

			m_horizontalMouseDownPosition = currentHorizontalMousePosition;
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseReleased(MouseEvent mouseEvent){
		if(UILib.isButtonPressed(mouseEvent, MOUSE_PANNING_BUTTON)){
			m_horizontalMouseDownPosition = -1;
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
