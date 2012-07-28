package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;

import javax.swing.JFrame;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import aterm.ATerm;

public class SVGPlugin extends DefaultStudioPlugin implements SvgTif {
	private static final String TOOL_NAME = "svg";

	private SvgBridge bridge;

	private Studio studio;
	
	public void display(String title, String svgFileName) {
		SVGCanvas canvas = new SVGCanvas(title, svgFileName);
		((StudioImplWithPredefinedLayout) studio).addComponent(canvas, 
				StudioImplWithPredefinedLayout.TOP_RIGHT);
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();		
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new SvgBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}
	
	public static void main(String[] args) {
		SVGCanvas canvas = new SVGCanvas("Test", args[0]);
		JFrame f = new JFrame();
		f.setLayout(new BorderLayout());
		f.add(canvas.getViewComponent(), BorderLayout.CENTER);
		f.setSize(200,200);
		f.setVisible(true);
	}
}
