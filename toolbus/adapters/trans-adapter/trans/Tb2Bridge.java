// Java tool bridge Tb2Bridge
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:05 PM

package trans;
import aterm.*;

public class Tb2Bridge extends Tb2Tool {
	private Tb2Tif tool;

	public Tb2Bridge(ATermFactory factory, Tb2Tif tool) {
		super(factory);
		this.tool = tool;
	}

	public void postEventCon1(ATerm term) {
		if (tool != null) {
			tool.postEventCon1(term);
		} else {
			throw new UnsupportedOperationException("method `postEventCon1' not supported.");
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
