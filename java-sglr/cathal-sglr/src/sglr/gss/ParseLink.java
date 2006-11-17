/*
 * Created on Sep 15, 2004
 */
package sglr.gss;

import sglr.mept.PTree;

/**
 * @author Cathal Boogerd
 */
public class ParseLink {
	private boolean reject;
	private PTree parseTree;
	private ParseStack linkedStack;
	
	public ParseLink() {
		reject = false;
		linkedStack = new ParseStack();
	}
	
	public ParseLink(ParseStack st) {
		reject = false;
		linkedStack = st;
	}
	
	public ParseLink(ParseStack st, PTree tree) {
		reject = false;
		linkedStack = st;
		parseTree = tree;
	}
	
	public boolean isRejected() {
		return reject;
	}
	
	public boolean isLinkedTo(ParseStack st) {
		return linkedStack.equals(st);
	}
	
	public PTree getTree() {
		return parseTree;
	}
	
	public void setTree(PTree pt) {
		parseTree = pt;
	}
	
	public ParseStack getLinkedStack() {
		return linkedStack;
	}
	
	public String toString() {
		return "[" + reject + "," + linkedStack + "," + parseTree + "]";
	}

	public void setReject(boolean bool) {
		reject = bool;
	}
	
	public void addAmbiguity(PTree tr) {
		parseTree.addAmbiguity(tr);
	}
}
