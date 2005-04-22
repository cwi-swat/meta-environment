package nl.cwi.sen1.gui;

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
