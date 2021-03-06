package trans;

// Java tool bridge Tb1Bridge
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:27:06 PM

import aterm.*;

public class MasqueradeBridge extends MasqueradeTool {
	private MasqueradeTif tool;

	public MasqueradeBridge(ATermFactory factory, MasqueradeTif tool) {
		super(factory);
		this.tool = tool;
	}

	public void postDelegateEvent(ATerm term) {
		if (tool != null) {
			tool.postDelegateEvent(term);
		} else {
			throw new UnsupportedOperationException("method `postDelegateEvent' not supported.");
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
