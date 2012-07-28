package nl.cwi.sen1.util;

import java.awt.event.MouseEvent;
import javax.swing.SwingUtilities;


import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import toolbus.AbstractTool;
import aterm.ATerm;

public class DefaultPopupImpl {
	private AbstractTool bridge;

	public DefaultPopupImpl(AbstractTool bridge) {
		this.bridge = bridge;
	}

	public void showPopup(final ATerm id, final ActionDescriptionList menuList) {
	  SwingUtilities.invokeLater(new Runnable() {
	    public void run() {
	      MouseEvent popupEvent = MouseAdapter.getPreviousPopupEvent();

	      if (popupEvent != null) {
		StudioPopupMenu popup = new StudioPopupMenu(id, bridge, menuList,
		    null);
		try {
		  popup.show(popupEvent.getComponent(), popupEvent.getX(),
		      popupEvent.getY());
		} catch (IllegalStateException e) {
		  // Happens when user selects another tab, so that the original
		  // component is not visible anymore
		}
	      } else {
		System.err.println("Popup got lost!");
	      }
	    }
	  });
	}
}
