package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Event;
import java.awt.event.KeyEvent;

import javax.swing.Action;
import javax.swing.InputMap;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.KeyStroke;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultEditorKit;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.Keymap;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;
import javax.swing.text.StyledDocument;
import javax.swing.text.DefaultHighlighter.DefaultHighlightPainter;
import javax.swing.text.Highlighter.HighlightPainter;

public class EditorPane extends JEditorPane {
	private StyledDocument doc;
	private Style defaultStyle;
	
	private Object focusTag;
	private HighlightPainter focusPainter;

	public EditorPane() {
		// Warning do not change the magic order of the following statements
		UndoableEditorKit kit = new UndoableEditorKit();
		setEditorKit(kit);
		doc = new DefaultStyledDocument();
		setDocument(doc);
		addBindings();
		kit.install(this);
		
		focusPainter = new DefaultHighlightPainter(new Color(255, 0, 0));
		defaultStyle = StyleContext.getDefaultStyleContext().getStyle(StyleContext.DEFAULT_STYLE);
		StyleConstants.setFontSize(defaultStyle, 14);
	}

	protected void addBindings() {
		InputMap inputMap = getInputMap();
		KeyStroke key;
		
		key = KeyStroke.getKeyStroke(KeyEvent.VK_Z, Event.CTRL_MASK);
		inputMap.put(key, UndoableEditorKit.undoAction);
		
		key = KeyStroke.getKeyStroke(KeyEvent.VK_Y, Event.CTRL_MASK);
		inputMap.put(key, UndoableEditorKit.redoAction);
	}

	public Style getDefaultStyle() {
		return defaultStyle;
	}

	public Style addStyle(String name, Style style) {
		return doc.addStyle(name, style);
	}

	public void setStyle(int offset, int length, String name) {
		Style style = doc.getStyle(name);
		doc.setCharacterAttributes(offset, length, style, true);
	}

	public void unsetStyles() {
		doc.setCharacterAttributes(0, doc.getLength(), defaultStyle, true);
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
		UndoableEditorKit kit = (UndoableEditorKit) getEditorKit();
		
		menu.add(kit.getAction(UndoableEditorKit.undoAction));
		menu.add(kit.getAction(UndoableEditorKit.redoAction));
		menu.add(kit.getAction(DefaultEditorKit.copyAction));
		menu.add(kit.getAction(DefaultEditorKit.pasteAction));
		menu.add(kit.getAction(DefaultEditorKit.cutAction));
		
		return menu;
	}
	
	public void pauseUndo() {
		((UndoableEditorKit) getEditorKit()).pauseUndo(this);
	}
	
	public void resumeUndo() {
		((UndoableEditorKit) getEditorKit()).resumeUndo(this);
	}
}
