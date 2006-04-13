package nl.cwi.sen1.error.model;

import java.util.Enumeration;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.MutableTreeNode;

import errorapi.types.Error;
import errorapi.types.ErrorList;
import errorapi.types.Location;
import errorapi.types.Subject;
import errorapi.types.SubjectList;
import errorapi.types.Summary;

public class ErrorDecorator {


	private LocationNode decorateLocation(final Location location) {
		return new LocationNode(location);
	}

	private SubjectNode decorateSubject(final Subject subject) {
		SubjectNode node = new SubjectNode(subject);

		if (subject.hasLocation()) {
			node.add(decorateLocation(subject.getLocation()));
		}

		return node;
	}

	private ErrorNode decorateError(final Error error, String producer,
			String id) {
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

	private boolean collectNodes(DefaultMutableTreeNode top, List<ErrorNode> list) {
		boolean grouped = false;
		
		for (Enumeration e = top.children(); e.hasMoreElements();) {
			DefaultMutableTreeNode node = (DefaultMutableTreeNode) e
					.nextElement();

			if (node instanceof GroupNode) {
				grouped = true;
				collectNodes(node, list);
			} else if (node instanceof ErrorNode) {
				list.add(0, (ErrorNode) node);
			}
		}
		
		return grouped;
	}

	private void setGrouping(DefaultMutableTreeNode top, int grouping) {
		List<ErrorNode> list = new LinkedList<ErrorNode>();
		collectNodes(top, list);
		top.removeAllChildren();
		Iterator newChildren;

		if (grouping != GroupNode.NO_GROUP) {
			Map<String, GroupNode> groups = new HashMap<String, GroupNode>();
			groupNodes(list, groups, grouping);
			newChildren = groups.values().iterator();
		}
		else {
			newChildren = list.iterator();
		}

		while (newChildren.hasNext()) {
			MutableTreeNode node = (MutableTreeNode) newChildren.next();
			top.insert(node, 0);
		}
	}

	private void addToGroup(int grouping, Map<String, GroupNode> groups, String name, ErrorNode node) {
		GroupNode group = groups.get(name);
		if (group == null) {
			group = new GroupNode(name, grouping);
		}
		group.insert(node, 0);
		groups.put(name, group);
	}
	
	private void groupNodes(List<ErrorNode> list, Map<String, GroupNode> groups, int grouping) {
		for (Iterator iter = list.iterator(); iter.hasNext(); ) {
			ErrorNode node = (ErrorNode) iter.next();
			addToGroup(grouping, groups, getErrorGroup(node, grouping), node);
		}
	}	
	
	public void addErrors(DefaultMutableTreeNode top, Summary summary) {
		String producer = summary.getProducer();
		String id = summary.getId();

		for (ErrorList errorList = summary.getList(); !errorList.isEmpty(); errorList = errorList
				.getTail()) {
			Error head = errorList.getHead();

			insert(top, decorateError(head, producer, id));
		}
	}

	private String getErrorGroup(ErrorNode node, int grouping) {
		switch (grouping) {
		case GroupNode.FILE_GROUP:
			Location loc = node.getLocation();
			return loc != null ? loc.getFilename() : "Unknown file";
		case GroupNode.DESCRIPTION_GROUP:
			return node.toString();
			default:
				return "";
		}
	}
	
	private void insert(DefaultMutableTreeNode top, ErrorNode node) {
		int grouping = GroupNode.NO_GROUP;
		
		for (Enumeration e = top.children(); e.hasMoreElements(); ) {
			DefaultMutableTreeNode child = (DefaultMutableTreeNode) e.nextElement();
			
			if (child instanceof GroupNode) {
				GroupNode group = (GroupNode) child;
				grouping = group.getGroupType();
				if (group.getGroupName().equals(getErrorGroup(node, grouping))) {
					group.insert(node, 0);
					return;
				}
			}
		}
		
		if (grouping != GroupNode.NO_GROUP) {
			GroupNode group = new GroupNode(getErrorGroup(node, grouping), grouping);
			group.insert(node,0);
			top.insert(group,0);
		}
		else {
			top.insert(node,0);
		}
	}


	private void removeNodes(DefaultMutableTreeNode top, List<ErrorNode> toBeRemoved) {
		Iterator<ErrorNode> iter = toBeRemoved.iterator();
		while (iter.hasNext()) {
			DefaultMutableTreeNode node = iter.next();
			if (top.isNodeChild(node))
			top.remove(node);
		}
	}
	
	public void removeAllMatchingErrors(DefaultMutableTreeNode top, String path) {
		List<ErrorNode> allNodes = new LinkedList<ErrorNode>();
		boolean grouped = collectNodes(top, allNodes);
		List<ErrorNode> toBeRemoved = new LinkedList<ErrorNode>();

		Iterator errors = allNodes.iterator();
		while (errors.hasNext()) {
			ErrorNode error = (ErrorNode) errors.next();
			Location loc = error.getLocation();

			if (loc != null && loc.hasFilename()
					&& path.equals(loc.getFilename())) {
				toBeRemoved.add(error);
			}
		}
		
		if (grouped) {
			List<GroupNode> groupToBeRemoved = new LinkedList<GroupNode>();
			
			for (Enumeration e = top.children(); e.hasMoreElements(); ) {
				GroupNode group = (GroupNode) e.nextElement();
				removeNodes(group, toBeRemoved);
				if (group.isLeaf()) {
					groupToBeRemoved.add(group);
				}
			}
		}
		else {
			removeNodes(top, toBeRemoved);
		}
	}

	public void removeAllMatchingErrors(DefaultMutableTreeNode top, String producer, String id) {
		List<ErrorNode> allNodes = new LinkedList<ErrorNode>();
		boolean grouped = collectNodes(top, allNodes);
		List<ErrorNode> toBeRemoved = new LinkedList<ErrorNode>();

		Iterator errors = allNodes.iterator();
		while (errors.hasNext()) {
			ErrorNode error = (ErrorNode) errors.next();

			if (producer.equals(error.getProducer())
					&& id.equals(error.getId())) {
				toBeRemoved.add(error);
			}
		}
		
		if (grouped) {
			List<GroupNode> groupToBeRemoved = new LinkedList<GroupNode>();
			
			for (Enumeration e = top.children(); e.hasMoreElements(); ) {
				GroupNode group = (GroupNode) e.nextElement();
				removeNodes(group, toBeRemoved);
				if (group.isLeaf()) {
					groupToBeRemoved.add(group);
				}
			}
			
			for (Iterator iter = groupToBeRemoved.iterator(); iter.hasNext(); ) {
				top.remove((DefaultMutableTreeNode) iter.next());
			}
		}
		else {
			removeNodes(top, toBeRemoved);
		}
	}

	public void groupOnDescription(DefaultMutableTreeNode top) {
		setGrouping(top, GroupNode.DESCRIPTION_GROUP);
	}
	
	public void groupOnFile(DefaultMutableTreeNode top) {
		setGrouping(top, GroupNode.FILE_GROUP);
	}
	
	public void unGroup(DefaultMutableTreeNode top) {
		setGrouping(top, GroupNode.NO_GROUP);
	}
}
