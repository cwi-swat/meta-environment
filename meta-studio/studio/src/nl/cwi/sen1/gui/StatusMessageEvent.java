package nl.cwi.sen1.gui;

import nl.cwi.sen1.gui.component.StudioComponent;

public class StatusMessageEvent extends StudioEvent {
	private String oldMessage;

	private String newMessage;

	public StatusMessageEvent(StudioComponent source, String oldMessage,
			String newMessage) {
		super(source);
		this.oldMessage = oldMessage;
		this.newMessage = newMessage;
	}

	public String getOldMessage() {
		return oldMessage;
	}

	public String getNewMessage() {
		return newMessage;
	}
}
