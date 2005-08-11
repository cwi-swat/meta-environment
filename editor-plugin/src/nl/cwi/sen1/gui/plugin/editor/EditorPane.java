package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Color;
import java.awt.Event;
import java.awt.event.KeyEvent;

import javax.swing.InputMap;
import javax.swing.JMenu;
import javax.swing.JTextPane;
import javax.swing.KeyStroke;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultEditorKit;
import javax.swing.text.Style;
import javax.swing.text.StyleContext;
import javax.swing.text.DefaultHighlighter.DefaultHighlightPainter;
import javax.swing.text.Highlighter.HighlightPainter;

public class EditorPane extends JTextPane {
	private Style defaultStyle;

	private Object focusTag;

	private HighlightPainter focusPainter;

	private boolean modified;

	public EditorPane() {
		setEditorKit(new EditorKit());
		pauseUndo();

		addBindings();

		focusPainter = new DefaultHighlightPainter(new Color(255, 0, 0));
		defaultStyle = StyleContext.getDefaultStyleContext().getStyle(
				StyleContext.DEFAULT_STYLE);
		// StyleConstants.setFontSize(defaultStyle, 14);
		modified = false;
		resumeUndo();
	}

	protected void addBindings() {
		InputMap inputMap = getInputMap();
		KeyStroke key;

		key = KeyStroke.getKeyStroke(KeyEvent.VK_Z, Event.CTRL_MASK);
		inputMap.put(key, EditorKit.undoAction);

		key = KeyStroke.getKeyStroke(KeyEvent.VK_Y, Event.CTRL_MASK);
		inputMap.put(key, EditorKit.redoAction);

		key = KeyStroke.getKeyStroke(KeyEvent.VK_F, Event.CTRL_MASK);
		inputMap.put(key, EditorKit.findAction);

		key = KeyStroke.getKeyStroke(KeyEvent.VK_G, Event.CTRL_MASK);
		inputMap.put(key, EditorKit.gotoLineAction);
	}

	public Style getDefaultStyle() {
		return defaultStyle;
	}

	public void setStyle(int offset, int length, String name) {
		pauseUndo();
		Style style = getStyle(name);
		getStyledDocument().setCharacterAttributes(offset, length, style, true);
		resumeUndo();
	}

	public void unsetStyles() {
		getStyledDocument().setCharacterAttributes(0,
				getDocument().getLength(), defaultStyle, true);
	}

	public void setCaretPositionAtEnd() {
		setCaretPosition(getDocument().getLength());
	}

	public void focus(int offset, int i) {
		clearFocus();

		try {
			focusTag = getHighlighter().addHighlight(offset, i, focusPainter);
		} catch (BadLocationException e) {
			// happens when you give an offset/length outside the editor
		}
	}

	public void clearFocus() {
		if (focusTag != null) {
			getHighlighter().removeHighlight(focusTag);
		}
	}

	public JMenu getEditorMenu() {
		JMenu menu = new JMenu("Edit");
		EditorKit kit = (EditorKit) getEditorKit();

		menu.add(kit.getAction(EditorKit.undoAction));
		menu.add(kit.getAction(EditorKit.redoAction));
		menu.add(kit.getAction(DefaultEditorKit.copyAction));
		menu.add(kit.getAction(DefaultEditorKit.pasteAction));
		menu.add(kit.getAction(DefaultEditorKit.cutAction));

		return menu;
	}

	private void pauseUndo() {
		((EditorKit) getEditorKit()).pauseUndo(this);
	}

	private void resumeUndo() {
		((EditorKit) getEditorKit()).resumeUndo(this);
	}

	public void setText(String t) {
		pauseUndo();
		super.setText(t);

		resumeUndo();
	}

	public void setCaretPosition(int position) {
		pauseUndo();
		super.setCaretPosition(position);
		resumeUndo();
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
		while (replace(toBeFound, toReplaceWith, caseInsensitive, false, true))
			;
		setCaretPosition(cursor);
	}

	public void gotoLine(int line) {
		String text = getText();
		int index = -1;
		int i = 0;

		if (line != -1) {
			do {
				index = text.indexOf('\n', index + 1);
				if (index != -1) {
					i++;
					if (line == i + 1) {
						break;
					}
				}
			} while (index != -1);

			if (index != -1) {
				setCaretPosition(index < text.length() ? index + 1 : index);
			}
		}
	}
}
