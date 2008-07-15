package argusviewer.view.msc.control;

import java.awt.event.MouseEvent;
import java.awt.geom.Point2D;

import prefuse.Display;
import prefuse.controls.AbstractZoomControl;
import prefuse.controls.Control;
import prefuse.util.ui.UILib;
import prefuse.visual.VisualItem;

/**
 * @author: Arne Timmerman
 */
public class SyncedZoomControl extends AbstractZoomControl {

	private Display m_synchronizedDisplay;

	protected static final int MOUSE_ZOOM_BUTTON = Control.RIGHT_MOUSE_BUTTON;
	private static final double ZOOM_DIVIDER = 100.0;

	protected Point2D m_zoomCenter = new Point2D.Float();
	protected Point2D m_synchronizedZoomCenter = new Point2D.Float();

	protected int m_verticalMouseDownPosition;

	/**
	 * Create a Zoom Control that allows zooming with the Right mouse button and
	 * does not synchronise Zoom events to another Display.
	 *
	 * @param zoomCenter the position in the display to zoom to
	 */
	public SyncedZoomControl(Point2D zoomCenter) {
		this(null, zoomCenter, null);
	}

	/**
	 * Create a Zoom Control that allows zooming with the Right mouse button and
	 * synchronises Zoom events to the given other Display.
	 *
	 * @param synchronizedDisplay synchronizedDisplay the display that must be synchronized with Zooming
	 * @param zoomCenter the position in the display to zoom to
	 * @param synchronizedZoomCenter the position in the synchronized display to zoom to
	 */
	public SyncedZoomControl(Display synchronizedDisplay, Point2D zoomCenter, Point2D synchronizedZoomCenter) {
		this.m_synchronizedDisplay = synchronizedDisplay;
		this.m_zoomCenter = zoomCenter;
		this.m_synchronizedZoomCenter = synchronizedZoomCenter;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void mousePressed(MouseEvent mouseEvent) {

		if (UILib.isButtonPressed(mouseEvent, MOUSE_ZOOM_BUTTON)) {
			Display pannedDisplay = (Display) mouseEvent.getSource();
			if (pannedDisplay.isTranformInProgress()) {
				m_verticalMouseDownPosition = -1;
				return;
			}

			m_verticalMouseDownPosition = mouseEvent.getY();
			double horizontalZoomCenter = mouseEvent.getX();
			m_zoomCenter.setLocation(horizontalZoomCenter, m_zoomCenter.getY());

			if (m_synchronizedDisplay != null) {
				m_synchronizedZoomCenter.setLocation(horizontalZoomCenter, m_synchronizedZoomCenter.getY());
			}
		}
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void mouseDragged(MouseEvent mouseEvent) {

		if (UILib.isButtonPressed(mouseEvent, MOUSE_ZOOM_BUTTON)) {
			Display pannedDisplay = (Display) mouseEvent.getSource();
			if (pannedDisplay.isTranformInProgress() || m_verticalMouseDownPosition == -1) {
				m_verticalMouseDownPosition = -1;
				return;
			}

			int currentVerticalMousePosition = mouseEvent.getY();
			int verticalMovement = currentVerticalMousePosition - m_verticalMouseDownPosition;
			double zoomScale = calculateZoom(verticalMovement);

			zoom(pannedDisplay, m_zoomCenter, zoomScale, false);

			if (m_synchronizedDisplay != null) {
				zoom(m_synchronizedDisplay, m_synchronizedZoomCenter, zoomScale, false);
			}

			m_verticalMouseDownPosition = currentVerticalMousePosition;
		}
	}

	/**
	 * Calculate and return the amount of zoom according to the
	 * given verticalMovement of the mouse.
	 *
	 * @param verticalMovement the amount of pixel that the mouse vertically moved
	 * @return the scale factor
	 */
	protected static double calculateZoom(int verticalMovement) {
		return 1 + ((double) verticalMovement) / ZOOM_DIVIDER;
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

}
