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

	public void postMaskeradeEvent(ATerm term) {
		if (tool != null) {
			tool.postMaskeradeEvent(term);
		} else {
			throw new UnsupportedOperationException("method `postMaskeradeEvent' not supported.");
		}
	}
	
	public void postMaskeradeTerminate(ATerm term) {
		if (tool != null) {
			tool.postMaskeradeTerminate(term);
		} else {
			throw new UnsupportedOperationException("method `postMaskeradeTerminate' not supported.");
		}
	}
	
	public void postMaskeradeValue(ATerm term) {
		if (tool != null) {
			tool.postMaskeradeValue(term);
		} else {
			throw new UnsupportedOperationException("method `postMaskeradeValue' not supported.");			
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
