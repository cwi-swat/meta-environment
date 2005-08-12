package nl.cwi.sen1.gui.plugin.editor;

import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.event.MouseListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.swing.JMenu;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import nl.cwi.sen1.gui.plugin.Editor;

import metaconfig.types.Properties;
import aterm.ATerm;
import aterm.ATermList;
import errorapi.types.Area;

public class SwingEditor extends JPanel implements Editor {
	private String id;

	private String filename;

	private EditorPane editorPane;

	public SwingEditor(String id, String filename) throws IOException {
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
		System.err.println("reading contents of " + filename);
		try {
			readFileContents(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private void readFileContents(String filename) throws IOException {
		editorPane.setText(readContents(filename));
	}

	public void addMouseListener(MouseListener l) {
		editorPane.addMouseListener(l);
	}
	
	

	private String readContents(String filename) throws IOException {
		try {
			FileInputStream fis = new FileInputStream(filename);
			int x = fis.available();
			byte b[] = new byte[x];
			fis.read(b);
			String content = new String(b);
			return content;
		} catch (FileNotFoundException e) {
			return "";
		}
	}

	public void writeContents() throws IOException {
		String text = editorPane.getText();

		FileOutputStream fos = new FileOutputStream(filename);
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

	public void registerCategories(Properties properties) {
		StyleRegistrar.registerTextCategories(editorPane, properties);
	}

	public void registerSlices(ATerm slices) {
		SliceRegistrar.registerSlices(editorPane, (ATermList) slices);
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

}
