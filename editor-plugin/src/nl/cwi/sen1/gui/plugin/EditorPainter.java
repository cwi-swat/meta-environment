package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Graphics;

import org.syntax.jedit.JEditTextArea;
import org.syntax.jedit.TextAreaDefaults;
import org.syntax.jedit.TextAreaPainter;

import errorapi.types.Area;

public class EditorPainter extends TextAreaPainter {
    private static final Color focusColor = new Color(255,165,0);
    private Area focus;

    public EditorPainter(JEditTextArea textArea, TextAreaDefaults defaults) {
        super(textArea, defaults);
    }

    protected void paintHighlight(Graphics gfx, int line, int y) {
        if (line >= textArea.getSelectionStartLine()
                && line <= textArea.getSelectionEndLine()) {
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

        if (bracketHighlight && line == textArea.getBracketLine())
            paintBracketHighlight(gfx, line, y);

        if (line == textArea.getCaretLine())
            paintCaret(gfx, line, y);
    }

    private void paintArea(Graphics gfx, int line, int y, int startLine,
            int endLine, int startCol, int endCol) {
        int height = fm.getHeight();
        y += fm.getLeading() + fm.getMaxDescent();

        int x1, x2;
        if (startLine == endLine) {
            x1 = textArea._offsetToX(line, startCol);
            x2 = textArea._offsetToX(line, endCol);
        } else if (line == startLine) {
            x1 = textArea._offsetToX(line, startCol);
            x2 = getWidth();
        } else if (line == endLine) {
            x1 = 0;
            x2 = textArea._offsetToX(line, endCol);
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
