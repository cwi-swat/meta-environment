package nl.cwi.sen1.gui.plugin.editor;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.StyledEditorKit;
import javax.swing.text.TextAction;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;

public class EditorKit extends StyledEditorKit {
    private static final int UNDO_LIMIT = 1000;

    private static UndoManager undoManager = new EditorUndoManager();

    private EditorPane editor;

    private UndoAction undo;

    private RedoAction redo;

    private FindAction find;

    private GotoLineAction gotoLine;

    public static final String undoAction = "undo";

    public static final String redoAction = "redo";

    public static final String findAction = "find";

    public static final String gotoLineAction = "goto-line";

    private UndoableEditListener undoListener;

    private SearchReplaceDialog searchReplaceDialog;

    public EditorKit(EditorPane editor) {
        this.editor = editor;
        searchReplaceDialog = new SearchReplaceDialog(editor);

        undoListener = new UndoableEditListener() {
            public void undoableEditHappened(UndoableEditEvent e) {
                undoManager.addEdit(e.getEdit());
                undo.updateUndoState();
                redo.updateRedoState();
            }
        };
        undoManager.setLimit(UNDO_LIMIT);

        createActions();
    }

    private void createActions() {
        undo = new UndoAction();
        redo = new RedoAction();
        find = new FindAction();
        gotoLine = new GotoLineAction();
    }

    public Action[] getActions() {
        return TextAction.augmentList(super.getActions(), new Action[] { undo,
                redo, find, gotoLine });
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

    public class UndoAction extends AbstractAction {

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

    public class RedoAction extends AbstractAction {

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

    public class GotoLineAction extends AbstractAction {
        public GotoLineAction() {
            super(gotoLineAction);
        }

        public void actionPerformed(ActionEvent e) {
            GotoLineDialog d = new GotoLineDialog();
            d.setVisible(true);
            editor.gotoLine(d.getLineNumber());
        }
    }

    public class FindAction extends AbstractAction {
        public FindAction() {
            super(findAction);
        }

        public void actionPerformed(ActionEvent e) {
            searchReplaceDialog.setVisible(true);
        }
    }

    public UndoableEditListener getUndoListener() {
        return undoListener;
    }
}
