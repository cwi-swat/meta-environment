// Java tool interface class Tb2Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:04 PM

package trans;
import aterm.*;
import toolbus.*;

abstract public class Tb2Tool extends AbstractTool implements Tb2Tif {
	// Mimic the constructor from the AbstractTool class
	protected Tb2Tool(ATermFactory factory) {
		super(factory);
	}

	// The generic handler calls the specific handlers
	public ATerm handler(ATerm term) {
		postEventCon1(term);
		return null;		
	}

	// Check the input signature
	public void checkInputSignature(ATermList sigs) {
	}
}
