/*
 * Created on Sep 15, 2004
 */
package sglr.gss;

import java.util.ArrayList;

/**
 * @author Cathal Boogerd
 */
public class ParseList extends ArrayList {
	public ParseList() {
		super();
	}
	
	public ParseList(ParseStack st) {
		new ParseList();
		add(st);
	}
	
	public ParseStack fetch(int index) {
		return (ParseStack) super.get(index);
	}
	
	public ParseStack fetchFirst() {
		return fetch(0);
	}
	
	public ParseStack fetchLast() {
		return fetch(this.size() - 1);
	}
	
	public void addFirst(ParseStack st) {
		this.add(0, st);
	}
	
	public ParseStack pop() {
		return (ParseStack) this.remove(0);
	}
	
	public void append(ParseList list) {
		ensureCapacity(size() + list.size());
		this.addAll(list);
	}
	
	public ParseStack getByState(int stateNumber) {
		ParseStack current;
		
		for (int i = 0; i < size(); i++) {
			current = fetch(i);
			if (current.peek() == stateNumber) {
				return current;
			}
		}
		
		return null;
	}
}
