/*
 * Created on Sep 22, 2004
 */
package sglr.mept;

import java.util.Hashtable;

import sglr.ptable.types.State;
import sglr.ptable.types.States;

/**
 * @author Cathal Boogerd
 */
public class StateHash extends Hashtable {
	public StateHash(States stateList) {
		super(stateList.getLength());
		State current;
		
		for (int i = 0; i < stateList.getLength(); i++) {
			current = stateList.getStateAt(i);
			add(current.getNumber(), new PTableState(current));
		}
	}
	
	public PTableState fetch(int key) {
		return (PTableState) super.get(new Integer(key));
	}
	
	public PTableState add(int key, PTableState value) {
		return (PTableState) super.put(new Integer(key), value);
	}
	
	public PTableState delete(int key) {
		return (PTableState) super.remove(new Integer(key));
	}
}
