package trans;

// Java tool interface class Tb1Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:27:06 PM

import aterm.*;
import toolbus.*;

abstract public class Tb1Tool extends AbstractTool implements Tb1Tif {
	// Mimic the constructor from the AbstractTool class
	protected Tb1Tool(ATermFactory factory) {
		super(factory);
	}

	// The generic handler calls the specific handlers
	public ATerm handler(ATerm term) {
		postEventCon2(term);
		return null;		
	}

	//}}}
	//{{{  public void checkInputSignature(ATermList sigs)

	// Check the input signature
	public void checkInputSignature(ATermList sigs) {
	}

	//}}}
	//{{{  void notInInputSignature(ATerm t)

	// This function is called when an input term
	// was not in the input signature.
	void notInInputSignature(ATerm t) {
		throw new RuntimeException("term not in input signature: " + t);
	}

	//}}}
}
