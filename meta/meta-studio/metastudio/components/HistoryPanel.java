package metastudio.components;

import java.awt.Color;
import java.awt.Font;
import java.awt.Rectangle;

import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.JViewport;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;

import metastudio.MultiBridge;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;

public class HistoryPanel extends ToolComponent {
    private JScrollPane historyPane;
    private StyleContext historyStyles;
    private DefaultStyledDocument historyDoc;
    private JTextPane history;
    
    public Style styleError;
    public Style styleWarning;
    public Style styleMessage;
    
    public HistoryPanel(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        
        createHistoryDocument();
        
        historyPane = new JScrollPane(history);
        add(historyPane);
    }
    
    private void createHistoryDocument() {
        Color color;

        historyStyles = new StyleContext();
        styleMessage = initStyle("messagepane.message");
        styleWarning = initStyle("messagepane.warning");
        styleError = initStyle("messagepane.error");

        historyDoc = new DefaultStyledDocument(historyStyles);
        history = new JTextPane(historyDoc);
        history.setEditable(false);

        color = Preferences.getColor(Preferences.PREF_MSGPANE_BACKGROUND);
        history.setBackground(color);
    }
    
    private Style initStyle(String prop) {
        Style style = historyStyles.addStyle(null, null);

        Font font = Preferences.getFont(prop + ".font");

        StyleConstants.setFontFamily(style, font.getFamily());
        StyleConstants.setFontSize(style, font.getSize());
        StyleConstants.setItalic(style, font.isItalic());
        StyleConstants.setBold(style, font.isBold());

        Color background = Preferences.getColor(prop + ".background");
        StyleConstants.setBackground(style, background);
        Color foreground = Preferences.getColor(prop + ".foreground");
        StyleConstants.setForeground(style, foreground);

        return style;
    }
    
    private void addMessage(Style style, String id, String message) {
        Object lock = history.getTreeLock();
        synchronized (lock) {
            try {
                historyDoc.insertString(historyDoc.getLength(), message + "\n", style);
                int start = historyDoc.getLength();
                Rectangle rect = history.modelToView(start);
                if (rect != null) {
                    JViewport viewport = historyPane.getViewport();

                    // Make rectangle relative to viewport
                    rect.x -= viewport.getViewPosition().x;
                    rect.y -= viewport.getViewPosition().y;
                    viewport.scrollRectToVisible(rect);
                }
            } catch (BadLocationException e) {
                System.err.println("bad location: " + e.getMessage());
            }
        }
    }
    
    public void errorf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addMessage(styleError, null, message);
    }

    public void error(String message) {
        addMessage(styleError, null, message);
    }

    public void messagef(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addMessage(styleMessage, null, message);
    }

    public void message(String message) {
        addMessage(styleMessage, null, message);
    }

    public void warningf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addMessage(styleWarning, null, message);
    }

    public void warning(String message) {
        addMessage(styleWarning, null, message);
    }
    
    public void clearHistory() {
        try {
            historyDoc.remove(0, historyDoc.getLength());
        } catch (BadLocationException e) {
            System.err.println(e.getMessage());
        }
    }
}
