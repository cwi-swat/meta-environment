package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.io.FileInputStream;
import java.io.IOException;

import javax.swing.JPanel;

import org.syntax.jedit.JEditTextArea;
import org.syntax.jedit.SyntaxDocument;

public class EditorPanel extends JPanel {
    private String id;

    private final JEditTextArea textArea;

    public EditorPanel(String id, String filename) throws IOException {
        this.id = id;

        setLayout(new BorderLayout());

        FileInputStream fis = new FileInputStream(filename);
        int x = fis.available();
        byte b[] = new byte[x];
        fis.read(b);
        String content = new String(b);

        textArea = new JEditTextArea();
        // setDocuments prevents every editor showing the text of the last
        // instatiation
        textArea.setDocument(new SyntaxDocument());
        textArea.setText(content);
        textArea.setCaretPosition(0);
        add(textArea, BorderLayout.CENTER);
    }

    public String getId() {
        return id;
    }

}
