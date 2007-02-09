package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Shape;

import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.JTextComponent;
import javax.swing.text.Position;
import javax.swing.text.View;

public class JaggedHighlighter extends
		DefaultHighlighter.DefaultHighlightPainter {
	private Color color;
	
	public JaggedHighlighter(Color color) {
		super(color);
		this.color = color;
	}

	public Shape paintLayer(Graphics g, int offs0, int offs1, Shape bounds,
			JTextComponent c, View view) {
		try {
			Shape shape = view.modelToView(offs0, Position.Bias.Forward, offs1,
					Position.Bias.Backward, bounds);

			int y = (int) (shape.getBounds().getY() + shape.getBounds()
					.getHeight());
			int x1 = (int) shape.getBounds().getX();
			int x2 = (int) (shape.getBounds().getX() + shape.getBounds()
					.getWidth());

			Color old = g.getColor();
			g.setColor(color);
			for (int i = x1; i <= x2; i += 6) {
				g.drawArc(i + 3, y - 3, 3, 3, 0, 180);
				g.drawArc(i + 6, y - 3, 3, 3, 180, 181);
			}
			g.setColor(old);
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		return null;
	}
}