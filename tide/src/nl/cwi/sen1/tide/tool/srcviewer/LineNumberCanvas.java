package nl.cwi.sen1.tide.tool.srcviewer;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Rectangle;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JComponent;
import javax.swing.JTextArea;

import nl.cwi.sen1.tide.tool.support.Rule;

class LineNumberCanvas extends JComponent {
	private final static int BORDER = 2;
	private JTextArea text;
	private FontMetrics fontMetrics;
	private FontMetrics sourceMetrics;

	private int cpe;

	private Map<Rule, Integer> rulesByRule;
	private Map<Integer, Rule> rulesByLine;

	private Polygon rulePoly;

	public LineNumberCanvas(JTextArea text) {
		this.text = text;
		rulesByRule = new HashMap<Rule, Integer>();
		rulesByLine = new HashMap<Integer, Rule>();
	}

	private void checkMetrics() {
		if (fontMetrics != getFontMetrics(getFont())
				|| sourceMetrics != text.getFontMetrics(text.getFont())) {
			fontMetrics = getFontMetrics(getFont());
			sourceMetrics = text.getFontMetrics(text.getFont());

			rulePoly = new Polygon();
			rulePoly.addPoint(0, 0);
			rulePoly.addPoint(fontMetrics.stringWidth("1999"), sourceMetrics
					.getHeight() / 2);
			rulePoly.addPoint(0, sourceMetrics.getHeight());
		}
	}

	public void paint(Graphics g) {
		Dimension dim = getSize();
		Rectangle clip = g.getClipBounds();

		checkMetrics();

		g.setColor(getBackground());
		g.fillRect(clip.x, clip.y, clip.width, clip.height);

		int line = clip.y / sourceMetrics.getHeight();
		int y = line * sourceMetrics.getHeight();
		line++;

		while (y < (clip.y + clip.height)) {
			if (line == cpe) {
				g.setColor(SourceFileViewer.COLOR_CPE);
				g.fillRect(0, y, clip.width, sourceMetrics.getHeight());
			}

			Rule rule = rulesByLine.get(new Integer(line));
			if (rule != null) {
				g.setColor(getRuleColor(rule));
				Polygon rulePoly = getRulePoly(rule);
				rulePoly.translate(0, y);
				g.fillPolygon(rulePoly);
				rulePoly.translate(0, -y);
			}

			g.setColor(getForeground());
			String label = String.valueOf(line++);
			g.drawString(label, dim.width - fontMetrics.stringWidth(label)
					- BORDER, y + sourceMetrics.getMaxAscent());
			y += sourceMetrics.getHeight();
		}

	}

	public Dimension getPreferredSize() {
		checkMetrics();

		return new Dimension(fontMetrics.stringWidth("1999") + BORDER, 0);
	}

	public Dimension getMinimumSize() {
		return getPreferredSize();
	}

	public void setCpe(int line) {
		cpe = line;
		repaint();
	}

	public void clearCpe() {
		cpe = -1;
		repaint();
	}

	public void addLocationRule(Rule rule, int line) {
		rulesByRule.put(rule, new Integer(line));
		rulesByLine.put(new Integer(line), rule);
	}

	public void removeLocationRule(Rule rule) {
		Integer line = rulesByRule.remove(rule);
		if (line != null) {
			rulesByLine.remove(line);
		}
	}

	public Color getRuleColor(Rule rule) {
		if (rule.isBreakpoint()) {
			return SourceFileViewer.COLOR_BREAKPOINT;
		}

		return SourceFileViewer.COLOR_WATCHPOINT;
	}

	public Polygon getRulePoly(Rule rule) {
		return rulePoly;
	}
}
