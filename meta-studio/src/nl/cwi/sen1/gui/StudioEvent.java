package nl.cwi.sen1.gui;

import nl.cwi.sen1.gui.component.StudioComponent;

public class StudioEvent {
	private StudioComponent source;

	public StudioEvent(StudioComponent source) {
		this.source = source;
	}
	
	public StudioComponent getSource() {
		return source;
	}
}
