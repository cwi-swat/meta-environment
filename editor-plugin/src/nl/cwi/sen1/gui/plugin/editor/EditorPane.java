package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Color;
import java.awt.Component;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JTextPane;
import javax.swing.KeyStroke;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.event.UndoableEditListener;
import javax.swing.plaf.ComponentUI;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultEditorKit;
import javax.swing.text.Element;
import javax.swing.text.Highlighter;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;
import javax.swing.text.DefaultHighlighter.DefaultHighlightPainter;
import javax.swing.text.Highlighter.HighlightPainter;

public class EditorPane extends JTextPane {
    private Style defaultStyle;

    private Object focusTag;

    private HighlightPainter focusPainter;

    private int bracketOffset;

    private Object bracketTag;

    private BracketHighlightPainter bracketPainter;

    private boolean modified;

    private JMenu menu;

    private Color bracketHighlightColor = Color.GRAY;

    private Color lineHighlightColor = new Color(232, 242, 254);

    private Color backgroundColor = Color.WHITE;

    private Rectangle lineHighlight = new Rectangle(0, 0, 0, 0);

    private int focusStartOffset;

    private int focusEndOffset;

    public EditorPane() {
        setEditorKit(new EditorKit());

        setOpaque(false);
        focusPainter = new DefaultHighlightPainter(Color.BLACK);
        bracketPainter = new BracketHighlightPainter(bracketHighlightColor);

        defaultStyle = StyleContext.getDefaultStyleContext().getStyle(
                StyleContext.DEFAULT_STYLE);
        defaultStyle.addAttribute(StyleConstants.Background, backgroundColor);

        getStyledDocument().setLogicalStyle(0, defaultStyle);

        modified = false;

        addBindings();
        addDocumentListener();
        addCaretListener();
        addMouseMotionListener();
    }

    protected void addBindings() {
        menu = new JMenu("Edit");

        addBinding(menu, KeyEvent.VK_Z, EditorKit.undoAction);
        addBinding(menu, KeyEvent.VK_Y, EditorKit.redoAction);
        addBinding(menu, KeyEvent.VK_F, EditorKit.findAction);
        addBinding(menu, KeyEvent.VK_G, EditorKit.gotoLineAction);
        addBinding(menu, KeyEvent.VK_C, DefaultEditorKit.copyAction);
        addBinding(menu, KeyEvent.VK_X, DefaultEditorKit.cutAction);
        addBinding(menu, KeyEvent.VK_V, DefaultEditorKit.pasteAction);
        addBinding(menu, KeyEvent.VK_D, EditorKit.deleteLineAction);
        addBinding(menu, KeyEvent.VK_5, EditorKit.gotoMatchingBracketAction);
        addBinding(menu, KeyEvent.VK_J, EditorKit.selectFocusAction);
    }

    protected void addBinding(JMenu menu, int key, String name) {
        Action action = ((EditorKit) getEditorKit()).getAction(name);
        KeyStroke keyStroke = KeyStroke.getKeyStroke(key, Event.CTRL_MASK);

        getInputMap().put(keyStroke, name);
        JMenuItem item = new JMenuItem(action);
        item.setAccelerator(keyStroke);
        menu.add(item);
    }

    private void addMouseMotionListener() {
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                clearFocus();
            }
        });
    }

    private void addCaretListener() {
        addCaretListener(new CaretListener() {
            public void caretUpdate(CaretEvent e) {
                if (getSelectionStart() != getSelectionEnd()) {
                    clearFocus();
                }
                try {
                    paintLineHighlight();
                    paintBracketHighlight();
                } catch (BadLocationException e1) {
                }
            }

        });
    }

    private void addDocumentListener() {
        getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {
            }

            public void insertUpdate(DocumentEvent e) {
                modified = true;
            }

            public void removeUpdate(DocumentEvent e) {
                modified = true;
            }
        });
    }

    private void paintLineHighlight() {
        Element root = this.getDocument().getDefaultRootElement();
        int line = root.getElementIndex(getCaretPosition());
        Element lineElement = root.getElement(line);
        int offset = lineElement.getStartOffset();

        highlight(offset);
    }

    private void paintBracketHighlight() throws BadLocationException {
        bracketOffset = TextUtilities.findMatchingBracket(getDocument(),
                getCaretPosition() - 1);
        if (bracketTag != null) {
            getHighlighter().removeHighlight(bracketTag);
        }
        if (bracketOffset != -1) {
            Highlighter.HighlightPainter p = bracketPainter;
            bracketTag = getHighlighter().addHighlight(bracketOffset,
                    bracketOffset + 1, p);
        }
    }

    public void highlight(int offset) {
        try {
            Rectangle r = modelToView(offset);
            r.x = 0;
            r.width = getWidth();
            if (!r.equals(lineHighlight)) {
                // remove previous linehighlight
                repaint(lineHighlight);
                lineHighlight = r;
                repaint(lineHighlight);
            }
        } catch (Exception e) {
        }
    }

    public void paintComponent(Graphics gfx) {
        gfx.setColor(backgroundColor);
        Rectangle r = getVisibleRect();
        gfx.fillRect(r.x, r.y, r.width, r.height);

        Graphics2D g2 = (Graphics2D) gfx;
        g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        g2.setRenderingHint(RenderingHints.KEY_RENDERING,
                RenderingHints.VALUE_RENDER_QUALITY);

        gfx.setColor(lineHighlightColor);
        gfx.fillRect(lineHighlight.x, lineHighlight.y, lineHighlight.width,
                lineHighlight.height);

        super.paintComponent(g2);
    }

    public boolean getScrollableTracksViewportWidth() {
        Component parent = getParent();
        ComponentUI ui = getUI();

        return parent != null ? (ui.getPreferredSize(this).width <= parent
                .getSize().width) : true;
    }

    public void setFocusColor(Color color) {
        focusPainter = new DefaultHighlightPainter(color);
    }

    public Style getDefaultStyle() {
        return defaultStyle;
    }

    public void setStyle(int offset, int length, String name) {
        Style style = getStyle(name);
        getStyledDocument().setCharacterAttributes(offset, length, style, true);
    }

    public void unsetStyles() {
        getStyledDocument().setCharacterAttributes(0,
                getDocument().getLength(), defaultStyle, true);
    }

    public void focus(int offset, int length) {
        clearFocus();

        try {
            focusTag = getHighlighter().addHighlight(offset, length,
                    focusPainter);
            focusStartOffset = offset;
            focusEndOffset = length;
        } catch (BadLocationException e) {
            // happens when you give an offset/length outside the editor
        }
    }

    public void clearFocus() {
        if (focusTag != null) {
            getHighlighter().removeHighlight(focusTag);
        }
        focusTag = null;
    }

    public JMenu getEditorMenu() {
        return menu;
    }

    public int getFocusStartOffset() {
        if (focusTag != null) {
            return focusStartOffset;
        }
        return -1;
    }
    
    public int getFocusEndOffset() {
        if (focusTag != null) {
            return focusEndOffset;
        }
        return -1;
    }
    
    public void setText(String t) {
        UndoableEditListener undoListener = ((EditorKit) getEditorKit())
                .getUndoListener();
        getDocument().removeUndoableEditListener(undoListener);
        super.setText(t);
        modified = false;
        getDocument().addUndoableEditListener(undoListener);
    }

    public void setCaretPositionAtEnd() {
        setCaretPosition(getDocument().getLength());
    }

    public void setModified(boolean modified) {
        this.modified = modified;
    }

    public boolean isModified() {
        return modified;
    }

    public boolean find(String toBeFound, boolean caseInsensitive,
            boolean wrapAround, boolean forward) {
        String text = getText();

        if (caseInsensitive) {
            toBeFound = toBeFound.toLowerCase();
            text = text.toLowerCase();
        }

        int from;

        if (forward) {
            from = getCaretPosition();
        } else {
            from = getSelectionStart() - 1;
        }

        int index = findFromInText(text, toBeFound, from, forward);
        if (wrapAround && index == -1) {
            if (forward) {
                findFromInText(text, toBeFound, 0, forward);
            } else {
                findFromInText(text, toBeFound, getDocument().getLength(),
                        forward);
            }
        }

        return index != -1;
    }

    private int findFromInText(String text, String toBeFound, int from,
            boolean forward) {
        int index = -1;

        if (forward) {
            index = text.indexOf(toBeFound, from);
        } else {
            index = text.lastIndexOf(toBeFound, from);
        }

        if (index != -1) {
            setSelectionStart(index);
            setSelectionEnd(index + toBeFound.length());
        }
        return index;
    }

    public boolean replace(String toBeFound, String toReplaceWith,
            boolean caseInsensitive, boolean wrapAround, boolean forward) {
        if (find(toBeFound, caseInsensitive, wrapAround, forward)) {
            replaceSelection(toReplaceWith);
            return true;
        }
        return false;
    }

    public void replaceAll(String toBeFound, String toReplaceWith,
            boolean caseInsensitive) {
        int cursor = getCaretPosition();
        setCaretPosition(0);
        while (replace(toBeFound, toReplaceWith, caseInsensitive, false, true)) {
        }
        setCaretPosition(cursor);
    }

    public void gotoLine(int line) {
        String text = getText();
        int index = -1;
        int i = 1;

        if (line == -1) {
            return;
        }

        if (line != 1) {
            do {
                index = text.indexOf('\n', index + 1);
                if (index != -1) {
                    i++;
                }
            } while (index != -1 && i < line);
            if (index != -1) {
                index++;
            }
        } else {
            index = 0;
        }

        if (index != -1) {
            setCaretPosition(index < text.length() ? index : index - 1);
        }

    }
}
