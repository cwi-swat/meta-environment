package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridBagLayout;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.AncestorEvent;
import javax.swing.event.AncestorListener;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;

import errorapi.types.Area;

public class EditorPanel extends JPanel {
    private String id;

    private String filename;

    private EditorTextArea textArea;

    private boolean modified;

    public EditorPanel(String id, String filename) throws IOException {
        this.id = id;
        this.filename = filename;
        
        

        setLayout(new BorderLayout());
        //setLayout(new GridBagLayout());

        // SyntaxDocument document = new SyntaxDocument();
        textArea = new EditorTextArea();
        // textArea.setDocument(document);

        textArea.getDocument().addUndoableEditListener(
                new UndoableEditListener() {
                    public void undoableEditHappened(UndoableEditEvent e) {
                        setModified(true);
                    }
                });

        textArea.setText(readContents(filename));
        modified = false;
        textArea.setCaretPosition(0);
        
        JScrollPane scroller = new JScrollPane(textArea);
        
        add(scroller, BorderLayout.CENTER);
    }

    public EditorTextArea getTextArea() {
        return textArea;
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
        String text = textArea.getText();

        FileOutputStream fos = new FileOutputStream(filename);
        fos.write(text.getBytes());
        
        textArea.getDocument().stopUndo();
        textArea.getDocument().startUndo();
    }

    public void setCursorAtOffset(int offset) {
    	int length = getTextArea().getText().length();
    	getTextArea().setCaretPosition(offset > length ? length : offset);
    }
    
    public void setFocus(Area focus) {
        textArea.setFocus(focus);
    }

    public String getId() {
        return id;
    }

    public void setModified(boolean modified) {
        this.modified = modified;
        textArea.setFocus(null);
    }

    public boolean isModified() {
        return modified;
    }
}
