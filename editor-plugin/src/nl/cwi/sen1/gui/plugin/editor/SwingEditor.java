package nl.cwi.sen1.gui.plugin.editor;

import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.event.MouseListener;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.swing.JMenu;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import nl.cwi.sen1.configapi.types.PropertyList;
import nl.cwi.sen1.gui.plugin.Editor;
import nl.cwi.sen1.gui.plugin.EditorModifiedListener;
import aterm.ATerm;
import aterm.ATermList;
import errorapi.types.Area;

public class SwingEditor extends JPanel implements Editor {
	private String id;

	private String filename;

	private EditorPane editorPane;

	public SwingEditor(String id, String filename) throws IOException,
			FileToBigException {
		this.id = id;
		this.filename = filename;

		setLayout(new BorderLayout());
		editorPane = new EditorPane();

		readFileContents(filename);
		editorPane.setCaretPosition(0);

		JScrollPane scroller = new JScrollPane(editorPane);

		add(scroller, BorderLayout.CENTER);
	}
	
	public void rereadContents() {
		try {
			readFileContents(filename);
//			((EditorKit) editorPane.getEditorKit()).getUndoManager()
//					.discardAllEdits();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (FileToBigException e) {
			e.printStackTrace();
		}
	}

	private void readFileContents(String filename) throws IOException,
			FileToBigException {
		editorPane.setText(readContents(filename));
	}

	private String readContents(String filename) throws IOException,
			FileToBigException {
		InputStream fis = null;
		
		try {
			fis = new BufferedInputStream(new FileInputStream(
					filename));
			int x = fis.available();

			if (x > 1024 * 1024 /* 1 Mbyte */) {
				throw new FileToBigException(filename);
			}

			byte b[] = new byte[x];
			fis.read(b);
			String content = new String(b);
			return content;
		} catch (FileNotFoundException e) {
			return "";
		} finally {
			if (fis != null) {
				fis.close();
			}
		}
	}

	public String getContents() {
		return editorPane.getText();
	}
	
	public void setContents(String contents) {
		editorPane.setText(contents);
	}
	
	public void writeContents(String filename) throws IOException {
		String text = editorPane.getText();

		OutputStream fos = new BufferedOutputStream(new FileOutputStream(
				filename));
		fos.write(text.getBytes());
		fos.close();

		editorPane.setModified(false);
	}

	public void writeCopy(String filename) throws IOException {
		String text = editorPane.getText();

		FileOutputStream fos;
		fos = new FileOutputStream(filename);
		fos.write(text.getBytes());
	}

	public void setCursorAtOffset(int offset) {
		try {
			editorPane.setCaretPosition(offset);
		} catch (IllegalArgumentException e) {
			editorPane.setCaretPositionAtEnd();
		}
	}

	public void setFocus(Area focus) {
		editorPane.focus(focus.getOffset(), focus.getOffset()
				+ focus.getLength());
	}

	public String getId() {
		return id;
	}

	public String getFilename() {
		return filename;
	}

	public void setModified(boolean modified) {
		editorPane.setModified(modified);
		editorPane.clearFocus();
	}

	public boolean isModified() {
		return editorPane.isModified();
	}

	public void registerCategories(PropertyList properties) {
		StyleRegistrar.registerTextCategories(editorPane, properties);
	}

	public void registerSlices(ATerm slices) {
		if (((ATermList) slices).getLength() < 10000) {
			SliceRegistrar.registerSlices(editorPane, (ATermList) slices);
		} else {
			System.err
					.println("Ignoring syntax highlighting for safety (too big)");
		}
	}

	public int getMouseOffset(int x, int y) {
		return editorPane.viewToModel(new Point(x, y));
	}

	public JMenu getEditMenu() {
		return editorPane.getEditorMenu();
	}

	public void requestFocus() {
		editorPane.requestFocus();
	}

	public void addMouseListener(MouseListener l) {
		editorPane.addMouseListener(l);
	}

	public void removeMouseListener(MouseListener l) {
		editorPane.removeMouseListener(l);
	}

	public void addEditorModifiedListener(EditorModifiedListener l) {
		editorPane.addEditorModifiedListener(l);
	}

	public void removeEditorModifiedListener(EditorModifiedListener l) {
		editorPane.removeEditorModifiedListener(l);
	}

	public void setEditable(boolean b) {
		editorPane.setEditable(b);
	}
}
