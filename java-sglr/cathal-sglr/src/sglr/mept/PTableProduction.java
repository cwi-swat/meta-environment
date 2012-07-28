/*
 * Created on 11-sep-2004
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableProduction {
	private Production prod;
	
	public PTableProduction(Production pr) {
		prod = pr;
	}
	
	public boolean isReject() {
		Attrs attributes;
		if (prod.hasAttributes() && prod.getAttributes().hasAttrs()) {
			attributes = prod.getAttributes().getAttrs();
			for (int i = 0; i < attributes.getLength(); i++) {
				if (attributes.getAttrAt(i).isReject()) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	public boolean isLiteral() {
		return prod.getRhs().isLit();
	}
	
	public boolean hasLeftPrio() {
		Attrs attributes;
		Attr attribute;
		
		if (prod.getAttributes().hasAttrs()) {
			attributes = prod.getAttributes().getAttrs();
			for (int i = 0; i < attributes.getLength(); i++) {
				attribute = attributes.getAttrAt(i);
				if (attribute.hasAssoc() && attribute.getAssoc().isLeft()) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	public boolean hasRightPrio() {
		Attrs attributes;
		Attr attribute;
		
		if (prod.getAttributes().hasAttrs()) {
			attributes = prod.getAttributes().getAttrs();
			for (int i = 0; i < attributes.getLength(); i++) {
				attribute = attributes.getAttrAt(i);
				if (attribute.hasAssoc() && attribute.getAssoc().isRight()) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	public String getLiteral() {
		return prod.getRhs().getString();
	}
	
	public int getLhsLength() {
		int length = 0;
		Symbols symbs = prod.getLhs();
		
		while (!symbs.isEmpty()) {
			length++;
			symbs = symbs.getTail();
		}
		
		return length;
	}
	
	public Symbol getSymbolAt(int index) {
		return prod.getLhs().getSymbolAt(index);
	}
	
	public Production getProduction() {
		return prod;
	}
	
	public String toString() {
		return prod.toString();
	}
}
