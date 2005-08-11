package nl.cwi.sen1.gui.plugin;

import java.awt.event.ActionEvent;
import java.util.HashMap;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JEditorPane;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.StyledEditorKit;
import javax.swing.text.TextAction;
import javax.swing.text.DefaultStyledDocument.AttributeUndoableEdit;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;

public class UndoableEditorKit extends StyledEditorKit {
	private static UndoManager undoManager = new UndoManager();

	private static UndoAction undo = new UndoAction();

	private static RedoAction redo = new RedoAction();

	public static final String undoAction = "undo";

	public static final String redoAction = "redo";

	private UndoableEditListener undoListener;

	public UndoableEditorKit() {
		undoListener = new UndoableEditListener() {
			public void undoableEditHappened(UndoableEditEvent e) {
				undoManager.addEdit(e.getEdit());
				undo.updateUndoState();
				redo.updateRedoState();
			}
		};
	}

	public Action[] getActions() {
		return TextAction.augmentList(super.getActions(), new Action[] { undo,
				redo });
	}

	public Action getAction(String name) {
		Action[] actions = getActions();

		for (int i = 0; i < actions.length; i++) {
			if (actions[i].getValue(Action.NAME).equals(name)) {
				return actions[i];
			}
		}

		return null;
	}

	public static class UndoAction extends AbstractAction {

		public UndoAction() {
			super(undoAction);
			setEnabled(false);
		}

		public void actionPerformed(ActionEvent e) {
			try {
				undoManager.undo();
			} catch (CannotUndoException ex) {
				System.out.println("Unable to undo: " + ex);
				ex.printStackTrace();
			}
			updateUndoState();
			redo.updateRedoState();
		}

		protected void updateUndoState() {
			if (undoManager.canUndo()) {
				setEnabled(true);
				putValue(Action.NAME, undoAction);
			} else {
				setEnabled(false);
				putValue(Action.NAME, undoAction);
			}
		}
	}

	public static class RedoAction extends AbstractAction {

		public RedoAction() {
			super(redoAction);
			setEnabled(false);
		}

		public void actionPerformed(ActionEvent e) {
			try {
				undoManager.redo();
			} catch (CannotRedoException ex) {
				System.out.println("Unable to redo: " + ex);
				ex.printStackTrace();
			}
			updateRedoState();
			undo.updateUndoState();
		}

		protected void updateRedoState() {
			if (undoManager.canRedo()) {
				setEnabled(true);
				putValue(Action.NAME, redoAction);
			} else {
				setEnabled(false);
				putValue(Action.NAME, redoAction);
			}
		}
	}
	
	public void pauseUndo(JEditorPane editor) {
		editor.getDocument().removeUndoableEditListener(undoListener);
	}
	
	public void resumeUndo(JEditorPane editor) {
		editor.getDocument().addUndoableEditListener(undoListener);
	}

	public void install(JEditorPane editor) {
		super.install(editor);
		editor.getDocument().addUndoableEditListener(undoListener);
	}

	public void deinstall(JEditorPane editor) {
		super.deinstall(editor);
		editor.getDocument().removeUndoableEditListener(undoListener);
	}
}
