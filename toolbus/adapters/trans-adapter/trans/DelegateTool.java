// Java tool interface class Tb2Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:04 PM

package trans;
import aterm.*;
import toolbus.*;

abstract public class DelegateTool extends AbstractTool implements DelegateTif {
	// Mimic the constructor from the AbstractTool class
	protected DelegateTool(ATermFactory factory) {
		super(factory);
	}

	// The generic handler calls the specific handlers
	public ATerm handler(ATerm term) {
		postMaskeradeEvent(term);
		return null;		
	}

	// Check the input signature
	public void checkInputSignature(ATermList sigs) {
	}
}
