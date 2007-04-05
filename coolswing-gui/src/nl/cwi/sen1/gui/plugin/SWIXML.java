package nl.cwi.sen1.gui.plugin;

import java.awt.Container;
import java.io.File;

import javax.swing.JDialog;

import nl.cwi.sen1.gui.Studio;

import org.swixml.SwingEngine;

import aterm.ATerm;

public class SWIXML extends DefaultStudioPlugin implements SwixmlTif {
	private static final String TOOL_NAME = "swixml";

	private SwingEngine engine;

	private SwixmlBridge bridge;

	public SWIXML() {
		engine = new SwingEngine(this);
	}

	public void initStudioPlugin(Studio studio) {
		bridge = new SwixmlBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);

		studio.connect(getName(), bridge);
	}

	public void swixmlDisplay(String path, String file) {
		JDialog dialog = new JDialog();
		try {
			File realFile = new File(file);
			Container c = engine.render(realFile);
			dialog.add(c);
			dialog.setSize(200,300);
			dialog.setVisible(true);
		} catch (Exception e) {
			System.out.println("Exception: " + e.toString());
		}
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}
}
