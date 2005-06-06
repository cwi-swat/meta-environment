package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.swing.JPanel;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;

import org.syntax.jedit.JEditTextArea;
import org.syntax.jedit.SyntaxDocument;

public class EditorPanel extends JPanel {
    private String id;

    private String filename;
    
    private JEditTextArea textArea;
    
    private boolean modified;

    public EditorPanel(String id, String filename) throws IOException {
        this.id = id;
        this.filename = filename;

        setLayout(new BorderLayout());

        SyntaxDocument document = new SyntaxDocument();
        document.addUndoableEditListener(new UndoableEditListener() {
            public void undoableEditHappened(UndoableEditEvent e) {
                setModified();
            }
        });

        textArea = new JEditTextArea();
        textArea.setDocument(document);
        textArea.setText(readContents(filename));
        modified = false;
        textArea.setCaretPosition(0);
        add(textArea, BorderLayout.CENTER);
    }

    private String readContents(String filename) throws IOException {
        FileInputStream fis = new FileInputStream(filename);
        int x = fis.available();
        byte b[] = new byte[x];
        fis.read(b);
        String content = new String(b);
        return content;
    }
    
    public void writeContents() throws IOException {
        String text = textArea.getText();
        
        FileOutputStream fos = new FileOutputStream(filename);
        fos.write(text.getBytes());
    }
    
    public void setFocus() {
    }

    public String getId() {
        return id;
    }

    public void setModified() {
        modified = true;
    }

    public boolean isModified() {
        return modified;
    }
}
