package metaedit.action;

import javax.swing.undo.*;
import javax.swing.AbstractAction;
import javax.swing.Action;
import java.awt.event.ActionEvent;

/**
 * Undo actions for SwingEditorpane
 */
public class UndoAction
    extends AbstractAction {
  private UndoManager undoManager;
  private RedoAction redoAction;
  public UndoAction(UndoManager undoManager, RedoAction redoAction) {
    super("Undo");
    this.undoManager = undoManager;
    this.redoAction = redoAction;
    setEnabled(false);
  }

  public void actionPerformed(ActionEvent e) {
    try {
      undoManager.undo();
    }
    catch (CannotUndoException ex) {
    //  ex.printStackTrace();
    }
    updateUndoState();
	  redoAction.updateRedoState();
  }

  public void updateUndoState() {
    if (undoManager.canUndo()) {
      setEnabled(true);
      putValue(Action.NAME, undoManager.getUndoPresentationName());
    }
    else {
      setEnabled(false);
      putValue(Action.NAME, "Undo");
    }
  }

}
