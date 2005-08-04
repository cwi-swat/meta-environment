package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.text.Segment;
import javax.swing.text.Utilities;

import org.ujac.ui.editor.TextArea;

import errorapi.types.Area;

public class EditorTextArea extends TextArea {
    private static final Color FOCUS_COLOR = new Color(255, 248, 147);

    private static final Color HIGHLIGHT_COLOR = new Color(232, 242, 254);

    private static final Color SELECTION_COLOR = new Color(68, 100, 172);

    private Area focus;

    public EditorTextArea() {
        super();

        setEOLMarkersPainted(false);
        setLineHighlightColor(HIGHLIGHT_COLOR);
        setSelectionColor(SELECTION_COLOR);
    }

    protected void paintLine(Graphics gfx, int line) {
        super.paintLine(gfx, line);

        if (line >= getSelectionStartLine() && line <= getSelectionEndLine()) {
            int selectionStartLine = getSelectionStartLine();
            int selectionEndLine = getSelectionEndLine();
            int lineStart = getLineStartOffset(line);

            int x1, x2;
            if (selectionStartLine == selectionEndLine) {
                x1 = selectionStart - lineStart;
                x2 = selectionEnd - lineStart;
            } else if (line == selectionStartLine) {
                x1 = selectionStart - lineStart;
                x2 = getLineText(line).length();
            } else if (line == selectionEndLine) {
                x1 = 0;
                x2 = selectionEnd - lineStart;
            } else {
                x1 = 0;
                x2 = getLineText(line).length();
            }

            // System.err.println("Line: " + line + "(" + x1 + "," + x2 + ")");

            gfx.setColor(Color.white);
            int x = _offsetToX(line, x1);
            int y = lineToY(line);
            y += fm.getHeight();
            String text = getLineText(line).substring(x1, x2);
            Segment segment = new Segment(text.toCharArray(), 0, text.length());
            Utilities.drawTabbedText(segment, x, y, gfx, this, 0);
        }
    }

    /*
     * 1. Highlight current line 2. Paint focus 3. Paint selection 4. Paint
     * highlight 5. Paint brackethighlight 6. Paint caret
     */
    protected void paintHighlight(Graphics gfx, int line, int y) {
        if (line >= getSelectionStartLine() && line <= getSelectionEndLine()) {
            paintLineHighlight(gfx, line, y);
        }

        // map lines in area to textarea lines (line in area start at 1, lines
        // in textarea start at 0
        if (focus != null) {
            int startLine = focus.getBeginLine() - 1;
            int endLine = focus.getEndLine() - 1;
            int startCol = focus.getBeginColumn();
            int endCol = focus.getEndColumn();
            if (line >= startLine && line <= endLine) {
                gfx.setColor(FOCUS_COLOR);
                paintArea(gfx, line, y, startLine, endLine, startCol, endCol);
            }
        }

        if (line >= getSelectionStartLine() && line <= getSelectionEndLine()
                && !(getSelectionStart() == getSelectionEnd())) {
            paintLineHighlight(gfx, line, y);
        }

        if (highlight != null) {
            highlight.paintHighlight(gfx, line, y);
        }

        if (bracketHighlight && line == getBracketLine()) {
            paintBracketHighlight(gfx, line, y);
        }

        if (line == getCaretLine()) {
            paintCaret(gfx, line, y);
        }
    }

    private void paintArea(Graphics gfx, int line, int y, int startLine,
            int endLine, int startCol, int endCol) {
        int height = fm.getHeight();
        y += fm.getLeading() + fm.getMaxDescent();

        int x1, x2;
        if (startLine == endLine) {
            x1 = _offsetToX(line, startCol);
            x2 = _offsetToX(line, endCol);
        } else if (line == startLine) {
            x1 = _offsetToX(line, startCol);
            x2 = getWidth();
        } else if (line == endLine) {
            x1 = 0;
            x2 = _offsetToX(line, endCol);
        } else {
            x1 = 0;
            x2 = getWidth();
        }

        gfx.fillRect(x1, y, x2 - x1, height);
    }

    public void setFocus(Area focus) {
        this.focus = focus;
        repaint();
    }
}
