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

    public Location getLocation() {
        return location;
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

    public boolean isError() {
        return error.isError();
    }

    public boolean isWarning() {
        return error.isWarning();
    }

    public boolean isFatal() {
        return error.isFatal();
    }

    public boolean isInfo() {
        return error.isInfo();
    }

    public boolean equals(Object o) {
        ErrorNode node = (ErrorNode) o;
        
        return (node.producer.equals(producer) && node.error.equals(error)
                && node.location.equals(location) && node.id.equals(id));
    }
}
