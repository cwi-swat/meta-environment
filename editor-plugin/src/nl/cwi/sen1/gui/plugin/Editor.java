package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JMenu;

import metaconfig.types.Properties;
import aterm.ATerm;
import errorapi.types.Area;

public interface Editor {

	public void addMouseListener(MouseListener l);
    
    public void addEditorModifiedListener(EditorModifiedListener l);
    
    public void removeEditorModifiedListener(EditorModifiedListener l);

	public void writeContents() throws IOException;

	public void setCursorAtOffset(int offset);

	public void setFocus(Area focus);

	public String getId();

	public String getFilename();

	public void setModified(boolean modified);

	public boolean isModified();

	public void registerCategories(Properties properties);

	public void registerSlices(ATerm slices);

	public int getMouseOffset(int x, int y);

	public JMenu getEditMenu();
	
	public void rereadContents();
}