package nl.cwi.sen1.gui;

public class StudioEvent {
	private StudioComponent source;

	public StudioEvent(StudioComponent source) {
		this.source = source;
	}
	
	public StudioComponent getSource() {
		return source;
	}
}
