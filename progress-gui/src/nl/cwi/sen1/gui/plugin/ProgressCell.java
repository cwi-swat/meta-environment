package nl.cwi.sen1.gui.plugin;

import aterm.ATerm;

public class ProgressCell {
	private String label;
	private ATerm id;
	
	public ProgressCell(ATerm id, String label) {
		this.label = label;
		this.id = id;
	}
	
	public ProgressCell(String label) {
		this.label=label;
		this.id = null;
	}
	
	public String toString() {
		return label;
	}
	
	public ATerm getId() {
		if (id != null) {
		  return id;
		}
		throw new UnsupportedOperationException("this cell has no id");
	}
	
	public String getLabel() {
		return label;
	}
}
