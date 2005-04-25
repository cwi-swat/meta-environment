package nl.cwi.sen1.error.model;

import javax.swing.tree.DefaultMutableTreeNode;

import errorapi.types.Area;
import errorapi.types.Error;
import errorapi.types.ErrorList;
import errorapi.types.Location;
import errorapi.types.Subject;
import errorapi.types.SubjectList;
import errorapi.types.Summary;

public class ErrorDecorator {
	public ErrorNode decorateLocation(final Location location, Summary summary) {
		ErrorNode node = new ErrorNode(location, summary);
		if (location.hasFilename()) {
			node.add(new ErrorNode(location.getFilename(), false, summary));
		}
		if (location.hasArea()) {
			node.add(new ErrorNode(location.getArea(), false, summary));
		}
		return node;
	}

	public ErrorNode decorateSubject(final Subject subject, Summary summary) {
		ErrorNode node = new ErrorNode(subject, summary) {
			public String toString() {
				return subject.getDescription();
			}
		};

		if (subject.hasLocation()) {
			Location location = subject.getLocation();
			if (location.hasFilename()) {
				node.add(new ErrorNode(location.getFilename(), false, summary));
			}
			if (location.hasArea()) {
				final Area area = location.getArea();
				node.add(new ErrorNode(area, false, summary) {
					public String toString() {
						StringBuffer buf = new StringBuffer();
						buf.append("line: ").append(area.getBeginLine());
						buf.append(", column: ").append(area.getBeginColumn());
						return buf.toString();
					}
				});
			}

			// node.add(decorateLocation(subject.getLocation(), summary));
		}

		return node;
	}

	public ErrorNode decorateError(final Error error, Summary summary) {
		ErrorNode node = new ErrorNode(error, summary) {
			public String toString() {
				StringBuffer buf = new StringBuffer(error.getDescription());
				buf.append(": ");
				SubjectList subjectList = error.getList();
				while (!subjectList.isEmpty()) {
					Subject subject = subjectList.getHead();
					buf.append(subject.getDescription());
					if (subject.hasLocation()) {
						Location location = subject.getLocation();
						if (location.hasFilename()) {
							buf.append(", ");
							buf.append(location.getFilename());
						}
					}
					subjectList = subjectList.getTail();
					if (!subjectList.isEmpty()) {
						buf.append(", ");
					}
				}
				return buf.toString();
			}
		};

		SubjectList subjectList = error.getList();
		while (!subjectList.isEmpty()) {
			Subject head = subjectList.getHead();
			node.add(decorateSubject(head, summary));
			subjectList = subjectList.getTail();
		}

		return node;
	}

	public void addErrors(DefaultMutableTreeNode top, Summary summary) {
		ErrorList errorList = summary.getList();
		while (!errorList.isEmpty()) {
			Error head = errorList.getHead();
			top.add(decorateError(head, summary));
			errorList = errorList.getTail();
		}
	}

	public ErrorNode decorateSummary(final Summary summary) {
		ErrorNode node = new ErrorNode(summary, summary) {
			public String toString() {
				return summary.getProducer() + " " + summary.getId();
			}
		};

		addErrors(node, summary);

		return node;
	}
}
