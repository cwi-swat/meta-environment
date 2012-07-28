package trans;

// Java tool interface class Tb1Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:27:06 PM

import aterm.*;
import toolbus.*;

abstract public class MasqueradeTool extends AbstractTool implements MasqueradeTif {
	// Mimic the constructor from the AbstractTool class
	protected MasqueradeTool(ATermFactory factory) {
		super(factory);
	}

	// The generic handler calls the specific handlers
	public ATerm handler(ATerm term) {
		postDelegateEvent(term);
		return null;		
	}

	// Check the input signature
	public void checkInputSignature(ATermList sigs) {
	}
}
