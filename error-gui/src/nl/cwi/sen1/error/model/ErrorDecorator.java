package nl.cwi.sen1.error.model;

import java.util.Enumeration;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.MutableTreeNode;

import errorapi.types.Error;
import errorapi.types.ErrorList;
import errorapi.types.Location;
import errorapi.types.Subject;
import errorapi.types.SubjectList;
import errorapi.types.Summary;

public class ErrorDecorator {
    public LocationNode decorateLocation(final Location location) {
        return new LocationNode(location);
    }

    public SubjectNode decorateSubject(final Subject subject) {
        SubjectNode node = new SubjectNode(subject);

        if (subject.hasLocation()) {
            node.add(decorateLocation(subject.getLocation()));
        }

        return node;
    }

    public ErrorNode decorateError(final Error error, String producer, String id) {
        ErrorNode node = new ErrorNode(error, producer, id);
        SubjectList subjectList = error.getList();

        while (!subjectList.isEmpty()) {
            Subject head = subjectList.getHead();
            node.add(decorateSubject(head));
            if (head.hasLocation()) {
                node.setLocation(head.getLocation());
            }
            subjectList = subjectList.getTail();
        }

        return node;
    }

    public void addErrors(DefaultMutableTreeNode top, Summary summary) {
        String producer = summary.getProducer();
        String id = summary.getId();
        boolean errorExists = false;

        for (ErrorList errorList = summary.getList(); !errorList.isEmpty(); errorList = errorList
                .getTail()) {
            Error head = errorList.getHead();
            for (int i = 0; i < top.getChildCount(); i++) {
                ErrorNode error = (ErrorNode) top.getChildAt(i);
                if (error.equals(decorateError(head, producer, id))) {
                    errorExists = true;
                }
            }

            if (!errorExists) {
                top.add(decorateError(head, producer, id));
            } 
        }
    }

    public void removeAllMatchingErrors(DefaultMutableTreeNode top,
            String producer, String id) {
        Enumeration errors = top.children();
        // the enumeration is broken if we start deleting nodes from the root,
        // so we have to make a worklist first.
        List toBeRemoved = new LinkedList();

        while (errors.hasMoreElements()) {
            ErrorNode error = (ErrorNode) errors.nextElement();
            if (producer.equals(error.getProducer())
                    && id.equals(error.getId())) {
                toBeRemoved.add(error);
            }
        }

        Iterator iter = toBeRemoved.iterator();
        while (iter.hasNext()) {
            top.remove((MutableTreeNode) iter.next());
        }
    }

    public void removeAllMatchingErrors(DefaultMutableTreeNode top, String path) {
        Enumeration errors = top.children();
        // the enumeration is broken if we start deleting nodes from the root,
        // so we have to make a worklist first.
        List toBeRemoved = new LinkedList();

        while (errors.hasMoreElements()) {
            ErrorNode error = (ErrorNode) errors.nextElement();
            if (path.equals(error.getLocation().getFilename())) {
                toBeRemoved.add(error);
            }
        }

        Iterator iter = toBeRemoved.iterator();
        while (iter.hasNext()) {
            top.remove((MutableTreeNode) iter.next());
        }
    }

}
