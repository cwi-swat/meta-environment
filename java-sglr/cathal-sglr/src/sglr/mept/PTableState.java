/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableState {
	private int number;
	private PTableActionList actions;
	private PTableGotoList gotos;
	
	public PTableState(State state) {
		number = state.getNumber();
		actions = new PTableActionList(state.getActions());
		gotos = new PTableGotoList(state.getGotos());
	}
	
	public int getNumber() {
		return number;
	}

	public PTableAction getActionAt(int index) {
		return actions.fetch(index);
	}
	
	public PTableGoto getGotoAt(int index) {
		return gotos.fetch(index);
	}
	
	public PTableGoto getGotoByToken(int token) {
		PTableGoto gotoAction;
		for (int i = 0; i < gotos.size(); i++) {
			gotoAction = gotos.fetch(i);
			if (gotoAction.inRange(token)) {
				return gotoAction;
			}
		}
		
		return null;
	}
	
	public PTableAction getActionByToken(int token) {
		PTableAction act;
		for (int i = 0; i < actions.size(); i++) {
			act = actions.fetch(i);
			if (act.inRange(token)) {
				return act;
			}
		}
		
		return null;
	}
}
