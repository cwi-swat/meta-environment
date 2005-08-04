package nl.cwi.sen1.error.model;

import nl.cwi.sen1.error.viewer.ErrorViewerBridge;
import nl.cwi.sen1.gui.Studio;
import errorapi.types.Error;
import errorapi.types.Location;

public class ErrorNode extends SelectableNode {
	private String producer;
	private String id;
	private Error error;
	private Location location;

	public ErrorNode(Error error, String producer, String id) {
		super(error);
		this.id = id;
		this.producer = producer;
		this.error = error;
	}

	public String getProducer() {
		return producer;
	}
	
	public String getId() {
		return id;
	}
	
	public String toString() {
		return error.getDescription();
	}
	
	public void setLocation(Location location) {
		this.location = location;
	}

	public void selected(Studio studio, ErrorViewerBridge bridge) {
		if (location != null) {
			bridge.postEvent(studio.getATermFactory().make(
					"location-selected(<term>)", location.toTerm()));
		}
	}
}
