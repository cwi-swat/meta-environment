package nl.cwi.sen1.gui.plugin.editor;

import javax.swing.event.DocumentEvent;
import javax.swing.text.AbstractDocument;
import javax.swing.undo.UndoManager;
import javax.swing.undo.UndoableEdit;

public class EditorUndoManager extends UndoManager {
    public synchronized boolean addEdit(UndoableEdit anEdit) {
        if (anEdit instanceof AbstractDocument.DefaultDocumentEvent) {
            AbstractDocument.DefaultDocumentEvent de = (AbstractDocument.DefaultDocumentEvent) anEdit;
            if (de.getType() == DocumentEvent.EventType.CHANGE) {
                return false;
            }
        }
        return super.addEdit(anEdit);
    }
}
