package nl.cwi.sen1.gui.plugin;

import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.InputEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

import javax.swing.text.BadLocationException;

import org.syntax.jedit.JEditTextArea;
import org.syntax.jedit.TextAreaDefaults;
import org.syntax.jedit.TextUtilities;

import errorapi.types.Area;

public class EditorTextArea extends JEditTextArea {
    public EditorTextArea() {
        this(TextAreaDefaults.getDefaults());
    }

    public EditorTextArea(TextAreaDefaults defaults) {
        super(defaults);

        painter = new EditorPainter(this, defaults);
        painter.addComponentListener(new ComponentHandler());
        painter.addMouseListener(new MouseHandler());
        painter.addMouseMotionListener(new DragHandler());

        add(CENTER, painter);
    }

    public void setFocus(Area focus) {
        EditorPainter p = (EditorPainter) painter;
        p.setFocus(focus);
    }

    class ComponentHandler extends ComponentAdapter {
        public void componentResized(ComponentEvent evt) {
            recalculateVisibleLines();
            scrollBarsInitialized = true;
        }
    }

    class DragHandler implements MouseMotionListener {
        public void mouseDragged(MouseEvent evt) {
            if (popup != null && popup.isVisible())
                return;

            setSelectionRectangular((evt.getModifiers() & InputEvent.CTRL_MASK) != 0);
            select(getMarkPosition(), xyToOffset(evt.getX(), evt.getY()));
        }

        public void mouseMoved(MouseEvent evt) {
        }
    }

    class MouseHandler extends MouseAdapter {
        public void mousePressed(MouseEvent evt) {
            requestFocus();

            // Focus events not fired sometimes?
            setCaretVisible(true);
            focusedComponent = EditorTextArea.this;

            if ((evt.getModifiers() & InputEvent.BUTTON3_MASK) != 0
                    && popup != null) {
                popup.show(painter, evt.getX(), evt.getY());
                return;
            }

            int line = yToLine(evt.getY());
            int offset = xToOffset(line, evt.getX());
            int dot = getLineStartOffset(line) + offset;

            switch (evt.getClickCount()) {
            case 1:
                doSingleClick(evt, line, offset, dot);
                break;
            case 2:
                doDoubleClick(evt, line, offset, dot);
                break;
            case 3:
                doTripleClick(evt, line, offset, dot);
                break;
            }
        }

        private void doSingleClick(MouseEvent evt, int line, int offset, int dot) {
            if ((evt.getModifiers() & InputEvent.SHIFT_MASK) != 0) {
                rectSelect = (evt.getModifiers() & InputEvent.CTRL_MASK) != 0;
                select(getMarkPosition(), dot);
            } else
                setCaretPosition(dot);
        }

        private void doDoubleClick(MouseEvent evt, int line, int offset, int dot) {
            // Ignore empty lines
            if (getLineLength(line) == 0)
                return;

            try {
                int bracket = TextUtilities.findMatchingBracket(document, Math
                        .max(0, dot - 1));
                if (bracket != -1) {
                    int mark = getMarkPosition();
                    // Hack
                    if (bracket > mark) {
                        bracket++;
                        mark--;
                    }
                    select(mark, bracket);
                    return;
                }
            } catch (BadLocationException bl) {
                bl.printStackTrace();
            }

            // Ok, it's not a bracket... select the word
            String lineText = getLineText(line);
            char ch = lineText.charAt(Math.max(0, offset - 1));

            String noWordSep = (String) document.getProperty("noWordSep");
            if (noWordSep == null)
                noWordSep = "";

            // If the user clicked on a non-letter char,
            // we select the surrounding non-letters
            boolean selectNoLetter = (!Character.isLetterOrDigit(ch) && noWordSep
                    .indexOf(ch) == -1);

            int wordStart = 0;

            for (int i = offset - 1; i >= 0; i--) {
                ch = lineText.charAt(i);
                if (selectNoLetter
                        ^ (!Character.isLetterOrDigit(ch) && noWordSep
                                .indexOf(ch) == -1)) {
                    wordStart = i + 1;
                    break;
                }
            }

            int wordEnd = lineText.length();
            for (int i = offset; i < lineText.length(); i++) {
                ch = lineText.charAt(i);
                if (selectNoLetter
                        ^ (!Character.isLetterOrDigit(ch) && noWordSep
                                .indexOf(ch) == -1)) {
                    wordEnd = i;
                    break;
                }
            }

            int lineStart = getLineStartOffset(line);
            select(lineStart + wordStart, lineStart + wordEnd);
        }

        private void doTripleClick(MouseEvent evt, int line, int offset, int dot) {
            select(getLineStartOffset(line), getLineEndOffset(line) - 1);
        }
    }

}
