/*
 * Created on Sep 15, 2004
 */
package sglr.gss;

import sglr.mept.PTable;
import sglr.mept.PTableChoice;
import sglr.mept.PTableChoiceList;
import sglr.mept.PTableLabel;
import sglr.mept.PTree;
import sglr.mept.PTreeList;
import sglr.ParseInput;
import sglr.ptable.*;
import sglr.util.*;

/**
 * @author Cathal Boogerd
 */
public class GSS {
	private Factory factory;
	private ParseStack initialStack;
	private ParseStack acceptingStack;
	private ParseList activeStacks;
	private ParseList forActor;
	private ParseList forActorDelayed;
	private ShiftList forShifter;
	private PTable parseTable;
	private int currentToken;
	private String parseTreeFormat;
	private ParseInput input;
	private Log statistics;
	private boolean hybrid;
	
	public GSS(PTable pt, Factory fac, ParseInput in, Log stats, boolean flagHybrid) {
		factory = fac;
		parseTable = pt;
		currentToken = PTable.TOKEN_NONE;
		initialStack = new ParseStack(parseTable.getInitialStateNumber());
		activeStacks = new ParseList(initialStack);
		input = in;
		statistics = stats;
		hybrid = flagHybrid;
	}
	
	public GSS(PTable pt, Factory fac, ParseInput in, String ptreeFormat, Log stats, boolean flagHybrid) {
		factory = fac;
		parseTable = pt;
		currentToken = PTable.TOKEN_NONE;
		initialStack = new ParseStack(parseTable.getInitialStateNumber());
		activeStacks = new ParseList(initialStack);
		input = in;
		statistics = stats;
		hybrid = flagHybrid;
		
		if (PTree.isSupportedFormat(ptreeFormat)) {
			parseTreeFormat = ptreeFormat;
		}
		else {
			throw new UnsupportedOperationException(ptreeFormat + " is not a supported parsetree format");
		}
	}
		
	public void parseCharacter(int token) {
		ParseStack st;
		forActor = (ParseList) activeStacks.clone();
		forActorDelayed = new ParseList();
		forShifter = new ShiftList();
		currentToken = token;
		
		while (!forActor.isEmpty() || !forActorDelayed.isEmpty()) {
			if (forActor.isEmpty()) {
				forActor = forActorDelayed;
				forActorDelayed = new ParseList();
			}
			while (!forActor.isEmpty()) {
				st = forActor.pop();
				if (!st.isRejected()) {
					actor(st);
				}
			}
		}
	}
	
	public void actor(ParseStack st) {
		PTableChoice act;
		PTableChoiceList actions = parseTable.getCurrentChoices(st.peek(), currentToken);
		
		while (!actions.isEmpty()) {
			act = actions.pop();
			if (act.isShift()) {
				forShifter.addFirst(st, act.getStateNumber());
			}
			else if (act.isReduce() || (act.isLookaheadReduce() && input.lookAhead(act.getLookaheads()))) {
				doReductions(st, act);
			}
			else if (act.isAccept() && !st.isRejected()) {
				acceptingStack = st;
			}
		}
	}
	
	public void doReductions(ParseStack st, PTableChoice act) {
		if (hybrid && st.getDeterministicDepth() >= act.getLength()) {
			ParseStack current = st;
			PTreeList trees = new PTreeList();
			for (int i = 0; i < act.getLength(); i++) {
				trees.addFirst(current.getLinkedTree());
				current = current.getLinkedStack();
			}
			
			reducer(current, parseTable.getNextStateNumber(current.peek(), act.getLabel()), parseTable.getLabelByNumber(act.getLabel()), trees);
			statistics.appendReduction(act.getLength(), true);
		}
		else if (act.getLength() == 0) {
			reducer(st, parseTable.getNextStateNumber(st.peek(), act.getLabel()), parseTable.getLabelByNumber(act.getLabel()), new PTreeList());
			statistics.appendReduction(0, true);
		}
		else {
			TraversalList trav = traverse(st, act.getLength());
			ParseStack curStack;
			
			for (int i = 0; i < trav.size(); i++) {
				curStack = trav.fetchStack(i);
				reducer(curStack, parseTable.getNextStateNumber(curStack.peek(), act.getLabel()), parseTable.getLabelByNumber(act.getLabel()), trav.fetchTrees(i));
			}
			statistics.appendReduction(act.getLength(), trav.size() == 1);
		}
		
	}
	
	public void reducer(ParseStack st, int stateNumber, PTableLabel lab, PTreeList trees) {
		ParseStack newStack;
		ParseLink newLink;
		PTree newTree = constructTree(lab, trees);
		
		if (stateNumber == PTable.STATE_NONE) {
			return;
		}
		
		if ((newStack = activeStacks.getByState(stateNumber)) != null) {
			if ((newLink = newStack.getLinkTo(st)) != null) {
				if (lab.isReject()) {
					newLink.setReject(true);
				}
				addAmbTree(newLink, newTree);
			}
			else {
				newLink = new ParseLink(st, newTree);
				if (lab.isReject()) {
					newLink.setReject(true);
				}
				newStack.addLink(newLink);
				
				ParseStack curStack;
				PTableChoiceList actions;
				PTableChoice act;
				
				for (int i = 0; i < activeStacks.size(); i++) {
					curStack = activeStacks.fetch(i);
					if (!curStack.isRejected() && !forActor.contains(curStack) && !forActorDelayed.contains(curStack)) {
						actions = parseTable.getCurrentChoices(stateNumber, currentToken);
						for (int j = 0; j < actions.size(); j++) {
							act = actions.fetch(j);
							if ((act.isReduce() || (act.isLookaheadReduce() && input.lookAhead(act.getLookaheads()))) && act.getLength() != 0) {
								doLimitedReductions(curStack, act, newLink);
							}
						}
					}
				}
			}
		}
		else {
			newLink = constructLink(st, newTree);
			if (lab.isReject()) {
				newLink.setReject(true);
			}
			newStack = new ParseStack(stateNumber);
			newStack.addLink(newLink);
			activeStacks.addFirst(newStack);
			forActorDelayed.addFirst(newStack);
		}
	}
	
	public void doLimitedReductions(ParseStack st, PTableChoice act, ParseLink link) {
		ParseStack curStack;
		TraversalList trav = traverseLink(st, link, act.getLength());
		for (int i = 0; i < trav.size(); i++) {
			curStack = trav.fetchStack(i);
			reducer(curStack, parseTable.getNextStateNumber(curStack.peek(), act.getLabel()), parseTable.getLabelByNumber(act.getLabel()), trav.fetchTrees(i));
		}
		
		statistics.appendReduction(act.getLength(), trav.size() == 1);
	}
	
	public void shifter() {
		int curTarget;
		ParseStack curStack, newStack;
		PTree newTree = constructTree(currentToken);
		activeStacks = new ParseList();
		
		for (int i = 0; i < forShifter.size(); i++) {
			curStack = forShifter.getStackAt(i);
			if (!curStack.isRejected()) {
				curTarget = forShifter.getShiftTargetAt(i);
				if ((newStack = activeStacks.getByState(curTarget)) != null) {
					newStack.addLink(constructLink(curStack, newTree));
				}
				else {
					newStack = new ParseStack(curTarget);
					newStack.addLink(constructLink(curStack, newTree));
					activeStacks.addFirst(newStack);
				}
			}
		}
	}

	public PTree getParseTree() {
		if (accept() && parseTreeFormat != null) {
			return acceptingStack.getLinkTo(initialStack).getTree();
		}

		return null;
	}
	
	public boolean hasActiveStacks() {
		return !activeStacks.isEmpty();
	}
	
	public boolean accept() {
		if (acceptingStack != null && acceptingStack.hasLinkTo(initialStack)) {
			return true;
		}
		
		return false;
	}
	
	private TraversalList traverse(ParseStack st, int length) {
		TraversalList trav = new TraversalList();
		ParseLinkList links = st.getLinks();
		
		for (int i = 0; i < links.size(); i++) {
			trav.append(traverseLink(st, links.fetch(i), length));
		}
		
		return trav;
	}	
	
	private TraversalList traverseLink(ParseStack st, ParseLink link, int length) {
		TraversalList currentStacks = new TraversalList();
		TraversalList newStacks = new TraversalList();
		currentStacks.addFirst(new ParseStack(link), new PTreeList());
		ParseStack curStack, linkedStack;
		PTreeList curTrees, linkedTrees;
		ParseLinkList curLinks;
		
		if (!st.hasLink(link)) {
			return new TraversalList();
		}
		
		for (int i = 0; i < length; i++) { // for the length of the reduce
			newStacks = new TraversalList();
			for (int j = 0; j < currentStacks.size(); j++) { // traverse the list of current stacks
				curStack = currentStacks.fetchStack(j);
				curTrees = currentStacks.fetchTrees(j);
				curLinks = curStack.getLinks();
				for (int k = 0; k < curLinks.size(); k++) { // follow all their links
					linkedStack = curLinks.fetch(k).getLinkedStack();
					linkedTrees = (PTreeList) curTrees.clone();
					linkedTrees.addFirst(curLinks.fetch(k).getTree());
					newStacks.addLast(linkedStack, linkedTrees);
				}
			}
			currentStacks = (TraversalList) newStacks.clone();
		}
		
		return currentStacks;
	}
	
	private PTree constructTree(int token) {
		if (parseTreeFormat != null) {
			return new PTree(token, factory, parseTreeFormat);
		}
		return null;
	}
	
	private PTree constructTree(PTableLabel lab, PTreeList trees) {
		if (parseTreeFormat != null) {
			PTree newTree;
			
			if (lab.getLhsLength() == 0 && lab.isLiteral()) {
				newTree = new PTree(currentToken, factory, parseTreeFormat);
			}
			else {
				newTree = new PTree(lab, trees, factory, parseTreeFormat);
			}
			
			return newTree;
		}
	
		return null;
	}
	
	private void addAmbTree(ParseLink link, PTree tree) {
		if (parseTreeFormat != null) {
			link.addAmbiguity(tree);
		}
	}
	
	private ParseLink constructLink(ParseStack st, PTree newTree) {
		if (parseTreeFormat != null) {
			return new ParseLink(st, newTree);
		}
		
		return new ParseLink(st);
	}
}
