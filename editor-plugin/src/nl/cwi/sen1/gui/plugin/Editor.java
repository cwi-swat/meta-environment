package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JMenu;

import nl.cwi.sen1.configapi.types.PropertyList;
import aterm.ATerm;
import errorapi.types.Area;

public interface Editor {

	public void addMouseListener(MouseListener l);
    
    public void addEditorModifiedListener(EditorModifiedListener l);
    
    public void removeEditorModifiedListener(EditorModifiedListener l);

	public void writeContents(String filename) throws IOException;
	
	public void setCursorAtOffset(int offset);

	public void setFocus(Area focus);

	public String getId();

	public String getFilename();

	public void setModified(boolean modified);

	public boolean isModified();

	public void registerCategories(PropertyList properties);

	public void registerSlices(ATerm slices);

	public int getMouseOffset(int x, int y);

	public JMenu getEditMenu();
	
	public void rereadContents();
    
    public void setEditable(boolean b);
    
    public boolean isEditable();

	public String getContents();

	public void setContents(String contents);

	public void setSelection(Area area);
}