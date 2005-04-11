/*
 * Created on 11-sep-2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.mept;

import sglr.ptable.types.Label;
import sglr.ptable.types.Production;
import sglr.ptable.types.Symbol;

/**
 * @author Cathal
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class PTableLabel {
	private PTableProduction prod;
	private int number;
	
	public PTableLabel(Label lab) {
		prod = new PTableProduction(lab.getProduction());
		number = lab.getNumber();
	}
	
	public boolean isLiteral() {
		return prod.isLiteral();
	}
	
	public boolean hasLhs() {
		return (getLhsLength() != 0);
	}
	public boolean hasLeftPrio() {
		return prod.hasLeftPrio();
	}
	
	public boolean hasRightPrio() {
		return prod.hasRightPrio();
	}
	
	public boolean isReject() {
		return prod.isReject();
	}
	
	public int getLhsLength() {
		return prod.getLhsLength();
	}
	
	public String getLiteral() {
		return prod.getLiteral();
	}
	
	public Symbol getSymbolAt(int index) {
		return prod.getSymbolAt(index);
	}
	
	public Production getProduction() {
		return prod.getProduction();
	}
	
	public String toString() {
		return prod.toString();
	}
}
