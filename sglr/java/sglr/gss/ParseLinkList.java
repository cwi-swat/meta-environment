/*
 * Created on Sep 15, 2004
 */
package sglr.gss;

import java.util.ArrayList;

/**
 * @author Cathal Boogerd
 */
public class ParseLinkList extends ArrayList {
	public ParseLinkList() {
		super();
	}
	
	public ParseLinkList(ParseLink link) {
		super();
		add(link);
	}
	
	public ParseLink fetch(int index) {
		return (ParseLink) get(index);
	}
	
	public ParseLink fetchFirst() {
		return fetch(0);
	}
	
	public ParseLink fetchLast() {
		return fetch(size() - 1);
	}
}

