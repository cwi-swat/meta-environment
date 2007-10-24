package nl.cwi.sen1.visplugin.text;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.types.RTuple;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class VisPluginTextUnparsing extends DefaultStudioPlugin implements
		VisPluginTextUnparsingTif {
	private VisPluginTextUnparsingBridge bridge;

	private PureFactory factory;

	private TextVisualizationWindow lastWindow;

	public void unparseRTuple(TextVisualizationWindow window, RTuple tuple) {
		lastWindow = window;
		ATerm event = factory.make("unparse-rtuple(<term>)", tuple.toTerm());
		bridge.postEvent(event);
	}

	public void recTerminate(ATerm t0) {
		//System.exit(0);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void displayUnparsedRtuple(String text) {
		/* \TODO find a better way! */
		lastWindow.setText(text);
		lastWindow = null;
	}

	public String getName() {
		return "vis-plugin-text-unparsing";
	}

	public void initStudioPlugin(Studio studio) {
		factory = (PureFactory) studio.getATermFactory();
		bridge = new VisPluginTextUnparsingBridge(factory, this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}
}
