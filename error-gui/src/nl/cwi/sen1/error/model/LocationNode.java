package nl.cwi.sen1.error.model;

import nl.cwi.sen1.error.viewer.ErrorViewerBridge;
import nl.cwi.sen1.gui.Studio;
import errorapi.types.Location;
import errorapi.types.Summary;

public class LocationNode extends ErrorNode {
	public LocationNode(Location location, Summary summary) {
		super(location, summary);
	}

	public void selected(Studio studio, ErrorViewerBridge bridge) {
		Location location = (Location) getUserObject();
		bridge.postEvent(studio.getATermFactory().make(
				"location-selected(<term>)", location.toTerm()));
	}
}
