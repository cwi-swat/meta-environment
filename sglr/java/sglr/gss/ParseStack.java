/*
 * Created on 5-sep-2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.gss;

import sglr.mept.*;

/**
 * @author Cathal
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class ParseStack {
	private int stateNumber;
	private int prio;
	private ParseLinkList links;
	
	private int deterministicDepth;
	private ParseStack linkedStack;
	private PTree linkedTree;
	private boolean linkRejected;
	
	public ParseStack() {
		stateNumber = PTable.STATE_NONE;
		prio = 0;
		links = new ParseLinkList();
		deterministicDepth = 1;
	}
	
	public ParseStack(int number) {
		stateNumber = PTable.STATE_NONE;
		prio = 0;
		links = new ParseLinkList();
		stateNumber = number;
		deterministicDepth = 1;
	}
	
	public ParseStack(ParseLink link) {
		stateNumber = PTable.STATE_NONE;
		prio = 0;
		links = new ParseLinkList();
		addLink(link);
		deterministicDepth = link.getLinkedStack().getDeterministicDepth() + 1;
	}
	
	public int peek() {
		return stateNumber;
	}
/*
	public int pop() {
		int res = stateNumber;
		stateNumber = PTable.STATE_NONE;
		return stateNumber;
	}
	
	public int pop(int times) {
		int lastPopped = PTable.STATE_NONE;
		for (int i = 0; i < times; i++) {
			lastPopped = pop();
		}
		
		return lastPopped;
	}

	public int push(int number) {
		stateNumber = number;
		return stateNumber;
	}
	
	public int size() {
		return 1;
	}
	
	public int getPriority() {
		return prio;
	}
	
	public void setPriority(int newprio) {
		prio = newprio;
	}
	*/
	
	public int getDeterministicDepth() {
		return deterministicDepth;
	}
	
	public int getOutDegree() {
		return links.size();
	}
		
	public void addLink(ParseLink link) {
		if (links.size() == 0) {
			linkedStack = link.getLinkedStack();
			linkedTree = link.getTree();
			linkRejected = link.isRejected();
			deterministicDepth = linkedStack.getDeterministicDepth() + 1; 
		}
		else {
			deterministicDepth = 0;
		}
		links.add(link);
	}
	
	public boolean isRejected() {
		if (links.size() == 0) {
			return false;
		}
		
		for (int i = 0; i < links.size(); i++) {
			if (!links.fetch(i).isRejected()) {
				return false;
			}
		}
		
		return true;
	}
	
	public boolean hasLinkTo(ParseStack pstack) {
		return (getLinkTo(pstack) != null);
	}
	
	public boolean hasLink(ParseLink link) {
		return links.contains(link);
	}
	
	public ParseLink getLinkTo(ParseStack pstack) {
		ParseLink curLink;
		
		for (int i = 0; i < links.size(); i++) {
			curLink = links.fetch(i); 
			if (curLink.isLinkedTo(pstack)) {
				return curLink;
			}
		}
		return null;
	}
	
	public ParseLinkList getLinks() {
		return links;
	}
	
	public ParseStack getLinkedStack() {
		return linkedStack;
	}
	
	public PTree getLinkedTree() {
		return linkedTree;
	}
	
	public PTreeList getLinkedTrees() {
		PTreeList trees = new PTreeList();
		
		for (int i = 0; i < links.size(); i++) {
			trees.add(links.fetch(i).getTree());
		}
		
		return trees;
	}
	
	public ParseList getLinkedStacks() {
		ParseList stacks = new ParseList();
		
		for (int i = 0; i < links.size(); i++) {
			stacks.add(links.fetch(i).getLinkedStack());
		}
		
		return stacks;
	}
	
	public String toString() {
		return "[" + stateNumber + "]";
	}
}
