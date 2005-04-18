package nl.cwi.sen1.gui.plugin;

import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileSystemView;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import aterm.ATerm;

public class Dialog implements StudioPlugin, DialogTif {

	private static final String TOOL_NAME = "dialog";

	private DialogBridge bridge;

	private Studio studio;

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		DialogBridge bridge = new DialogBridge(studio.getFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	public ATerm showFileDialog(String title, String path, String filter) {
		File dir;
		if ("".equals(path)) {
			dir = FileSystemView.getFileSystemView().getHomeDirectory();
		} else {
			dir = new File(path);
		}
		JFileChooser chooser = new JFileChooser(dir);
		if (chooser.showDialog(null, title) == JFileChooser.APPROVE_OPTION) {
			path = chooser.getSelectedFile().getAbsolutePath();
			return studio.getFactory().make(
					"snd-value(file-dialog-approve(<str>))", path);
		} else {
			return studio.getFactory().make("snd-value(file-dialog-cancel)");
		}
	}

	public void recTerminate(ATerm t0) {
	}
}
