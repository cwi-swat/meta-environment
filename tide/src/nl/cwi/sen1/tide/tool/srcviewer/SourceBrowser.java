package nl.cwi.sen1.tide.tool.srcviewer;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.Rectangle;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.JTextArea;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Element;

import nl.cwi.sen1.tide.tool.support.Expr;
import nl.cwi.sen1.tide.tool.support.Rule;

class SourceBrowser extends JTextArea {
	private static final Color COLOR_SELECTED_POSITION = Color.red;

	private int selectedPosition;

	private Map<Rule, Expr> breakpointLocations;
	private Map<Rule, Expr> watchpointLocations;

	//{{{ public SourceBrowser()

	public SourceBrowser() {
		selectedPosition = -1;
		breakpointLocations = new HashMap<Rule, Expr>();
		watchpointLocations = new HashMap<Rule, Expr>();
	}

	//}}}
	//{{{ public void switchToFile(String fileName)

	public void clear() {
		breakpointLocations.clear();
		watchpointLocations.clear();
	}

	//}}}

	//{{{ public void setSelectedPosition(int pos)

	public void setSelectedPosition(int pos) {
		selectedPosition = pos;
		repaint();
	}

	//}}}
	//{{{ public void clearSelectedPosition()

	public void clearSelectedPosition() {
		selectedPosition = -1;
		repaint();
	}

	//}}}

	//{{{ int getLine(int offset)

	int getLine(int offset) {
		Document doc = getDocument();
		Element root = doc.getDefaultRootElement();
		return root.getElementIndex(offset) + 1;
	}

	//}}}
	//{{{ int getColumn(int offset)

	int getColumn(int offset) {
		Document doc = getDocument();
		Element root = doc.getDefaultRootElement();
		Element line = root.getElement(root.getElementIndex(offset));

		return offset - line.getStartOffset();
	}

	//}}}

	//{{{ private void paintLocation(Graphics g, Expr loc)

	private void paintLocation(Graphics g, Expr loc) {
		try {
			int line = loc.getLocationStartLine();
			int col = loc.getLocationStartColumn();
			int pos = getLineStartOffset(line - 1);
			pos += col;
			Rectangle rect1 = modelToView(pos);
			Rectangle rect2 = modelToView(pos + 1);
			int x = rect1.x - 1;
			int y = rect1.y;
			int w = rect2.x - x - 1;
			int h = rect1.height;
			g.drawRect(x, y, w, h);
			g.drawRect(x + 1, y + 1, w - 2, h - 2);
		} catch (BadLocationException e) {}
	}

	//}}}
	//{{{ public void paint(Graphics g)

	public void paint(Graphics g) {
		super.paint(g);

		if (selectedPosition >= 0) {
			try {
				Rectangle rect = modelToView(selectedPosition);
				Rectangle rect_end = modelToView(selectedPosition + 1);

				g.setColor(COLOR_SELECTED_POSITION);

				g.drawOval(
					rect.x - 1,
					rect.y,
					rect_end.x - rect.x + 1,
					rect.height);
			} catch (BadLocationException e) {
				selectedPosition = -1;
			}
		}

		// Paint watchpoints and breakpoints
		Iterator<Expr> iter;

		g.setColor(SourceFileViewer.COLOR_WATCHPOINT);
		iter = watchpointLocations.values().iterator();
		while (iter.hasNext()) {
			paintLocation(g, iter.next());
		}

		g.setColor(SourceFileViewer.COLOR_BREAKPOINT);
		iter = breakpointLocations.values().iterator();
		while (iter.hasNext()) {
			paintLocation(g, iter.next());
		}
	}

	//}}}

	//{{{ public void addWatchpoint(Rule rule, Expr location)

	public void addWatchpoint(Rule rule, Expr location) {
		watchpointLocations.put(rule, location);
	}

	//}}}
	//{{{ public void removeWatchpoint(Rule rule)

	public void removeWatchpoint(Rule rule) {
		watchpointLocations.remove(rule);
	}

	//}}}
	//{{{ public void addBreakpoint(Rule rule, Expr location)

	public void addBreakpoint(Rule rule, Expr location) {
		breakpointLocations.put(rule, location);
	}

	//}}}
	//{{{ public void removeWatchpoint(Rule rule)

	public void removeBreakpoint(Rule rule) {
		breakpointLocations.remove(rule);
	}

	//}}}

	//{{{ public Rule getRuleAt(int x, int y)

	public Rule getRuleAt(int x, int y) {
		int pos = viewToModel(new Point(x, y));
		int linenr = getLine(pos);
		int column = getColumn(pos);

		Iterator<Rule> iter;
		iter = breakpointLocations.keySet().iterator();
		while (iter.hasNext()) {
			Rule rule = iter.next();
			Expr location = breakpointLocations.get(rule);
			if (location.getLocationStartLine() == linenr
				&& location.getLocationStartColumn() == column) {
				return rule;
			}
		}

		iter = watchpointLocations.keySet().iterator();
		while (iter.hasNext()) {
			Rule rule = iter.next();
			Expr location = watchpointLocations.get(rule);
			if (location.getLocationStartLine() == linenr
				&& location.getLocationStartColumn() == column) {
				return rule;
			}
		}

		return null;
	}

	//}}}
}
