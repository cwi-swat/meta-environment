/*
 * Created on Sep 22, 2004
 */
package sglr.mept;

import java.util.Hashtable;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class LabelHash extends Hashtable {
	public LabelHash(Labels labelList) {
		super(labelList.getLength());
		Label current;
		for (int i = 0; i < labelList.getLength(); i++) {
			current = labelList.getLabelAt(i);
			add(current.getNumber(), current);
		}
	}
	
	public Label fetch(int key) {
		return (Label) super.get(new Integer(key));
	}
	
	public Label add(int key, Label value) {
		return (Label) super.put(new Integer(key), value);
	}
	
	public Label delete(int key) {
		return (Label) super.remove(new Integer(key));
	}
}
