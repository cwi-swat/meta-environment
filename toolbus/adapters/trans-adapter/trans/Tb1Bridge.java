package trans;

// Java tool bridge Tb1Bridge
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:27:06 PM

import aterm.*;

public class Tb1Bridge extends Tb1Tool {
	private Tb1Tif tool;

	public Tb1Bridge(ATermFactory factory, Tb1Tif tool) {
		super(factory);
		this.tool = tool;
	}

	public void postEventCon2(ATerm term) {
		if (tool != null) {
			tool.postEventCon2(term);
		} else {
			throw new UnsupportedOperationException("method `postEventCon2' not supported.");
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
