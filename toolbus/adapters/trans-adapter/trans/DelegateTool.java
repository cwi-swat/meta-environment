// Java tool interface class Tb2Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:04 PM

package trans;
import java.util.List;

import aterm.*;
import toolbus.*;

abstract public class DelegateTool extends AbstractTool implements DelegateTif {
	private ATerm PrecValue;
	private ATerm PrecEvent;
	
	// Mimic the constructor from the AbstractTool class
	protected DelegateTool(ATermFactory factory) {
		super(factory);
		initPatterns();
	}
	
	private void initPatterns()
	  {
		PrecValue = factory.parse("rec-do(fun(value(<term>)))");
		PrecEvent = factory.parse("rec-do(fun(event(<term>)))");
//		PrecAckEvent = factory.parse("rec-ack-event(<term>)");
//		PrecTerminate = factory.parse("rec-terminate(<term>)");
	  }
	
	// The generic handler calls the specific handlers
	public ATerm handler(ATerm term) {
		List result;
		
		result = term.match(PrecEvent);
		if (result != null) {
			postMaskeradeEvent((ATerm)result.get(0));
			return null;		
		}
		result = term.match(PrecValue);
		if (result != null) {
			postMaskeradeValue((ATerm)result.get(0));
			return null;
		}
		
		return null;
	}

	// Check the input signature
	public void checkInputSignature(ATermList sigs) {
	}
}
