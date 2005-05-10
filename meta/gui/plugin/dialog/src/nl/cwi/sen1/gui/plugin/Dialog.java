package nl.cwi.sen1.gui.plugin;

import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.ProgressMonitor;
import javax.swing.SwingUtilities;
import javax.swing.filechooser.FileSystemView;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;

public class Dialog implements StudioPlugin, DialogTif {

	private static final String TOOL_NAME = "dialog";

	private Studio studio;

	private ProgressList progressList;

	private ProgressMonitor progressMonitor;

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		DialogBridge bridge = new DialogBridge(studio.getATermFactory(), this);
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
			return studio.getATermFactory().make(
					"snd-value(file-dialog-approve(<str>))", path);
		}
		return studio.getATermFactory().make("snd-value(file-dialog-cancel)");
	}

	public void recTerminate(ATerm t0) {
	}

	public void showProgressMessage(String message) {
		if (progressList != null) {
			progressList.addMessage(message);
		}
	}

	public void showProgressList(final String title) {
		progressList = new ProgressList((JFrame) null, title, true);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				progressList.setVisible(true);
			}
		});
	}

	public void closeProgressList() {
		if (progressList != null) {
			progressList.dispose();
		}
	}

	public void showProgressMessageWithArguments(String format, ATerm args) {
		String message = StringFormatter.format(format, (ATermList) args);
		if (progressList != null) {
			progressList.addMessage(message);
		}
	}

	public ATerm showQuestionDialog(String question) {
		int choice = JOptionPane.showConfirmDialog(null, question);

		if (choice == JOptionPane.YES_OPTION) {
			return studio.getATermFactory().make("snd-value(answer(yes))");
		}
		if (choice == JOptionPane.NO_OPTION) {
			return studio.getATermFactory().make("snd-value(answer(no))");
		}

		return studio.getATermFactory().make("snd-value(answer(cancel))");
	}

	public void showErrorDialog(String errorMessage) {
		JOptionPane.showMessageDialog(null,
				errorMessage, "Error", JOptionPane.ERROR_MESSAGE);
	}

	public void showErrorDialogWithArguments(String errorMessage, ATerm args) {
		String message = StringFormatter.format(errorMessage, (ATermList) args);
		JOptionPane.showMessageDialog(null,
				message, "Error", JOptionPane.ERROR_MESSAGE);
	}
}
