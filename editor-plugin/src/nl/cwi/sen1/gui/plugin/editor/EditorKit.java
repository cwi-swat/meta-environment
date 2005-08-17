package nl.cwi.sen1.gui.plugin.editor;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JEditorPane;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.StyledEditorKit;
import javax.swing.text.TextAction;
import javax.swing.text.Utilities;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;

public class EditorKit extends StyledEditorKit {
    private static final int UNDO_LIMIT = 1000;

    private static UndoManager undoManager = new EditorUndoManager();

    private UndoAction undo;

    private RedoAction redo;

    private DeleteLineAction deleteLine;

    private FindAction find;

    private GotoLineAction gotoLine;

    private GotoMatchingBracketAction gotoMatchingBracket;

    public static final String undoAction = "undo";

    public static final String redoAction = "redo";

    public static final String findAction = "find";

    public static final String gotoLineAction = "goto-line";

    public static final String deleteLineAction = "delete-line";

    public static final String gotoMatchingBracketAction = "goto-matching-bracket";

    private UndoableEditListener undoListener;

    public EditorKit() {
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

    public UndoableEditListener getUndoListener() {
        return undoListener;
    }

    private void createActions() {
        undo = new UndoAction();
        redo = new RedoAction();
        find = new FindAction();
        gotoLine = new GotoLineAction();
        gotoMatchingBracket = new GotoMatchingBracketAction();
        deleteLine = new DeleteLineAction();
    }

    public Action[] getActions() {
        return TextAction.augmentList(super.getActions(), new Action[] { undo,
                redo, find, gotoLine, deleteLine, gotoMatchingBracket });
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

    public abstract static class EditorTextAction extends StyledTextAction {
        public EditorTextAction(String nm) {
            super(nm);
        }

        protected final EditorPane getEditorPane(ActionEvent e) {
            JEditorPane editorPane = getEditor(e);
            if (editorPane instanceof EditorPane) {
                return (EditorPane) editorPane;
            }
            return null;
        }
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

    public class FindAction extends EditorTextAction {
        private SearchReplaceDialog searchReplaceDialog;

        public FindAction() {
            super(findAction);
        }

        public void actionPerformed(ActionEvent e) {
            EditorPane editor = getEditorPane(e);
            if (editor != null) {
                if (searchReplaceDialog == null) {
                    searchReplaceDialog = new SearchReplaceDialog(editor);
                }
                searchReplaceDialog.setVisible(true);
            }
        }
    }

    public class GotoLineAction extends EditorTextAction {
        public GotoLineAction() {
            super(gotoLineAction);
        }

        public void actionPerformed(ActionEvent e) {
            GotoLineDialog d = new GotoLineDialog();
            d.setVisible(true);
            EditorPane editor = getEditorPane(e);
            if (editor != null) {
                editor.gotoLine(d.getLineNumber());
            }
        }
    }

    public class GotoMatchingBracketAction extends EditorTextAction {
        public GotoMatchingBracketAction() {
            super(gotoMatchingBracketAction);
        }

        public void actionPerformed(ActionEvent e) {
            EditorPane editor = getEditorPane(e);
            if (editor != null) {
                try {
                    int offset = TextUtilities.findMatchingBracket(editor
                            .getDocument(), editor.getCaretPosition() - 1);
                    if (offset != -1) {
                        editor.setCaretPosition(offset + 1);
                    }
                } catch (BadLocationException e1) {
                }
            }
        }
    }

    public class DeleteLineAction extends EditorTextAction {
        public DeleteLineAction() {
            super(deleteLineAction);

        }

        public void actionPerformed(ActionEvent e) {
            EditorPane editor = getEditorPane(e);
            if (editor != null) {
                try {
                    selectLine(editor);

                    int selectionStart = editor.getSelectionStart();
                    int selectionEnd = editor.getSelectionEnd();
                    int offset = selectionStart;
                    int length = selectionEnd - selectionStart;

                    if ((selectionEnd + 1) < editor.getDocument().getLength()) {
                        length++;
                    } else {
                        if (selectionStart - 1 > 0) {
                            offset = selectionStart - 1;
                            length++;
                        } 
                    }
                    
                    editor.getDocument().remove(offset, length);
                } catch (BadLocationException e1) {
                    e1.printStackTrace();
                }

            }
        }

        private void selectLine(EditorPane editor) throws BadLocationException {
            int offset = editor.getCaretPosition();
            int beginOffset = Utilities.getRowStart(editor, offset);
            editor.setSelectionStart(beginOffset);

            int endOffset = Utilities.getRowEnd(editor, offset);
            editor.setSelectionEnd(endOffset);
        }
    }
}
