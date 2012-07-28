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

public class JaggedHighlightPainter extends
		DefaultHighlighter.DefaultHighlightPainter {

	public JaggedHighlightPainter(Color color) {
		super(color);
	}

	public Shape paintLayer(Graphics g, int offs0, int offs1, Shape bounds,
			JTextComponent c, View view) {
		try {
			Shape shape = view.modelToView(offs0, Position.Bias.Forward, offs1,
					Position.Bias.Backward, bounds);

			Rectangle r = (shape instanceof Rectangle) ? (Rectangle) shape
					: shape.getBounds();

			int y = (int) (shape.getBounds().getY() + shape.getBounds()
					.getHeight());
			int x1 = (int) shape.getBounds().getX();
			int x2 = (int) (shape.getBounds().getX() + shape.getBounds()
					.getWidth());

			g.setColor(getColor());
			for (int i = x1; i < x2 - 6; i += 6) {
				g.drawArc(i, y - 3, 3, 2, 0, 180);
				g.drawArc(i + 3, y - 3, 3, 2, 180, 181);
			}
			return r;
		} catch (BadLocationException e) {
		}

		return null;
	}
}