package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.Studio;
import aterm.ATerm;

public class SVGPlugin extends DefaultStudioPlugin implements SvgTif {
	private Studio studio;
	private SvgBridge bridge;

	public void display(String s0, String s1) {
		// TODO Auto-generated method stub
		
	}

	public void recTerminate(ATerm t0) {
		// TODO Auto-generated method stub		
	}

	public String getName() {
		return "SVG";
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new SvgBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

}
