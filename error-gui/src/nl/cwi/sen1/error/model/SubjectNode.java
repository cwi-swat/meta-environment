package nl.cwi.sen1.error.model;

import nl.cwi.sen1.error.viewer.ErrorViewerBridge;
import nl.cwi.sen1.gui.Studio;
import errorapi.types.Subject;

public class SubjectNode extends SelectableNode {
	private Subject subject;

	public SubjectNode(Subject subject) {
		super(subject);
		this.subject = subject;
	}

	public void selected(Studio studio, ErrorViewerBridge bridge) {
		if (subject.hasLocation()) {
			bridge.postEvent(studio.getATermFactory()
					.make("location-selected(<term>)",
							subject.getLocation().toTerm()));
		}
	}
	
	public String toString() {
		return subject.getDescription();
	}
}
