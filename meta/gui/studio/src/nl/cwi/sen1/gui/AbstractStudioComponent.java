package nl.cwi.sen1.gui;

import javax.swing.event.EventListenerList;

abstract public class AbstractStudioComponent implements StudioComponent {
	private String statusMessage;

	private EventListenerList listenerList = new EventListenerList();

	public void addStudioComponentListener(StudioComponentListener l) {
		listenerList.add(StudioComponentListener.class, l);
	}

	public void removeStudioComponentListener(StudioComponentListener l) {
		listenerList.remove(StudioComponentListener.class, l);
	}

	// Take from javax.swing.event.EventListenerList example
	protected void fireMenuChanged() {
		Object[] listeners = listenerList.getListenerList();
		for (int i = listeners.length - 2; i >= 0; i -= 2) {
			if (listeners[i] == StudioComponentListener.class) {
				((StudioComponentListener) listeners[i + 1]).menuChanged(null);
			}
		}

	}

	protected void fireStatusMessageChanged(String oldMessage, String newMessage) {
		StatusMessageEvent event = new StatusMessageEvent(this, oldMessage,
				newMessage);
		Object[] listeners = listenerList.getListenerList();
		for (int i = listeners.length - 2; i >= 0; i -= 2) {
			if (listeners[i] == StudioComponentListener.class) {
				((StudioComponentListener) listeners[i + 1])
						.statusMessageChanged(event);
			}
		}
	}

	public String getStatusMessage() {
		return statusMessage;
	}

	public void setStatusMessage(String newMessage) {
		String oldMessage = statusMessage;
		statusMessage = newMessage;
		if (newMessage == null || !newMessage.equals(oldMessage)) {
			fireStatusMessageChanged(oldMessage, newMessage);
		}
	}
}
