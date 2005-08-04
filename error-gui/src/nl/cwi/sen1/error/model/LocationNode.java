package nl.cwi.sen1.error.model;

import nl.cwi.sen1.error.viewer.ErrorViewerBridge;
import nl.cwi.sen1.gui.Studio;
import errorapi.types.Area;
import errorapi.types.Location;

public class LocationNode extends SelectableNode {
	private Location location;

	public LocationNode(Location location) {
		super(location);
		this.location = location;
	}

	public void selected(Studio studio, ErrorViewerBridge bridge) {
		bridge.postEvent(studio.getATermFactory().make(
				"location-selected(<term>)", location.toTerm()));
	}

	public String toString() {
		StringBuffer buf = new StringBuffer();

		if (location.hasFilename()) {
			buf.append("file: ").append(location.getFilename());
		}

		if (location.hasArea()) {
			Area area = location.getArea();
			buf.append(", line: ").append(area.getBeginLine());
			buf.append(", column: ").append(area.getBeginColumn());
		}
		return buf.toString();
	}
}
