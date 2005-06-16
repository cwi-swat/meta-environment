package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Graphics;

import org.ujac.ui.editor.TextArea;

import errorapi.types.Area;

public class EditorTextArea extends TextArea {
    private static final Color focusColor = new Color(255, 165, 0);

    private Area focus;

    public EditorTextArea() {
        super();
        setEOLMarkersPainted(false);
    }

    /* 
     * 1. Highlight current line
     * 2. Paint focus
     * 3. Paint selection
     * 4. Paint highlight
     * 5. Paint brackethighlight
     * 6. Paint caret
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
                gfx.setColor(focusColor);
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

        if (bracketHighlight && line == getBracketLine())
            paintBracketHighlight(gfx, line, y);

        if (line == getCaretLine())
            paintCaret(gfx, line, y);
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
