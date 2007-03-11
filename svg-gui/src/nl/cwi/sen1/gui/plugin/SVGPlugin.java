package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import aterm.ATerm;

public class SVGPlugin extends DefaultStudioPlugin implements SvgTif {
	private Studio studio;
	private SvgBridge bridge;

	public void display(String title, String svgFileName) {
		SVGCanvas canvas = new SVGCanvas(title, svgFileName);
		((StudioImplWithPredefinedLayout) studio).addComponent(canvas, 
				StudioImplWithPredefinedLayout.TOP_RIGHT);
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();		
	}

	public String getName() {
		return "svg";
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new SvgBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

}
