package nl.cwi.sen1.gui.plugin.editor;

import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.event.MouseListener;
import java.awt.geom.Area;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.swing.JMenu;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import nl.cwi.sen1.gui.plugin.Editor;
import nl.cwi.sen1.gui.plugin.EditorModifiedListener;
import aterm.ATerm;
import aterm.ATermList;

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

		readFileContents();
		editorPane.setCaretPosition(0);

		JScrollPane scroller = new JScrollPane(editorPane);

		add(scroller, BorderLayout.CENTER);
	}

	public void rereadContents() {
		try {
			readFileContents();
			// ((EditorKit) editorPane.getEditorKit()).getUndoManager()
			// .discardAllEdits();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (FileToBigException e) {
			e.printStackTrace();
		}
	}

	private void readFileContents() throws IOException,
			FileToBigException {
		editorPane.setText(readContents());
	}

	private String readContents() throws IOException,
			FileToBigException {
		InputStream fis = null;

		try {
			File file = new File(filename);
			fis = new BufferedInputStream(new FileInputStream(filename));
			long x = file.length();

			if (x > 1024 * 1024 /* 1 Mbyte */) {
				throw new FileToBigException(filename);
			}

			byte b[] = new byte[(int) x];
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

		OutputStream fos = null;
		try{
			fos = new BufferedOutputStream(new FileOutputStream(filename));
			fos.write(text.getBytes());
		}finally{
			if(fos != null){
				fos.close();
			}
		}

		editorPane.setModified(false);
		editorPane.clearJaggedSelection();
	}

	public void writeCopy(String filename) throws IOException {
		String text = editorPane.getText();

		FileOutputStream fos = null;
		try{
			fos = new FileOutputStream(filename);
			fos.write(text.getBytes());
		}finally{
			if(fos != null){
				fos.close();
			}
		}
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

	public void setSelection(Area area) {
		editorPane.jag(area.getOffset(), area.getOffset()
				+ area.getLength());
	}

	public String getId() {
		return id;
	}

	public String getFilename() {
		return filename;
	}

	public void setModified(boolean modified) {
		editorPane.setModified(modified);
		clearSelections();
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
	
	public boolean isEditable() {
		return editorPane.isEditable();
	}
	
	public void clearSelections() {
		editorPane.clearFocus();
		editorPane.clearJaggedSelection();
	}
}
