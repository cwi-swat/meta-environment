// Java tool bridge Tb2Bridge
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:05 PM

package trans;
import aterm.*;

public class DelegateBridge extends DelegateTool {
	private DelegateTif tool;

	public DelegateBridge(ATermFactory factory, DelegateTif tool) {
		super(factory);
		this.tool = tool;
	}

	public void postMasqueradeEvent(ATerm term) {
		if (tool != null) {
			tool.postMasqueradeEvent(term);
		} else {
			throw new UnsupportedOperationException("method `postMasqueradeEvent' not supported.");
		}
	}
	
	public void postMasqueradeTerminate(ATerm term) {
		if (tool != null) {
			tool.postMasqueradeTerminate(term);
		} else {
			throw new UnsupportedOperationException("method `postMasqueradeTerminate' not supported.");
		}
	}
	
	public void postMasqueradeValue(ATerm term) {
		if (tool != null) {
			tool.postMasqueradeValue(term);
		} else {
			throw new UnsupportedOperationException("method `postMasqueradeValue' not supported.");			
		}
	}
	
	public void recAckEvent(ATerm t0) {
		if (tool != null) {
			tool.recAckEvent(t0);
		} else {
			throw new UnsupportedOperationException("method `recAckEvent' not supported.");
		}
	}

	public void recTerminate(ATerm t0) {
		if (tool != null) {
			tool.recTerminate(t0);
		} else {
			throw new UnsupportedOperationException("method `recTerminate' not supported.");
		}
	}
}
