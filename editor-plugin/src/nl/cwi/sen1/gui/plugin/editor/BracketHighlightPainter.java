package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Shape;

import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.JTextComponent;
import javax.swing.text.Position;
import javax.swing.text.View;

class BracketHighlightPainter extends
        DefaultHighlighter.DefaultHighlightPainter {

    BracketHighlightPainter(Color color) {
        super(color);
    }

    public Shape paintLayer(Graphics g, int offs0, int offs1, Shape bounds,
            JTextComponent c, View view) {

        try {
            Shape shape = view.modelToView(offs0, Position.Bias.Forward, offs1,
                    Position.Bias.Backward, bounds);
            Rectangle r = (shape instanceof Rectangle) ? (Rectangle) shape
                    : shape.getBounds();
            g.setColor(getColor());
            g.drawRect(r.x, r.y, r.width - 1, r.height - 1);
            return r;
        } catch (BadLocationException e) {
        }

        return null;
    }
}
