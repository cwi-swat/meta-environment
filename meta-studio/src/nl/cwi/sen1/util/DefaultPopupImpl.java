package nl.cwi.sen1.util;

import java.awt.event.MouseEvent;

import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import toolbus.AbstractTool;
import aterm.ATerm;

public class DefaultPopupImpl  {
	private AbstractTool bridge;

	public DefaultPopupImpl(AbstractTool bridge) {
		this.bridge = bridge;
	}

	public void showPopup(final ATerm id, ActionDescriptionList menuList) {
		MouseEvent popupEvent = MouseAdapter.getPreviousPopupEvent();

		if (popupEvent != null) {
			StudioPopupMenu popup = new StudioPopupMenu(id, bridge, menuList, null);
			popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent.getY());
		}
		else {
			System.err.println("Popup got lost!");
		}
	}
}
