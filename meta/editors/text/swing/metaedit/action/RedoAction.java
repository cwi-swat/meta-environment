package metaedit.action;

import javax.swing.AbstractAction;
import java.awt.event.ActionEvent;
import javax.swing.Action;
import javax.swing.undo.UndoManager;
import javax.swing.undo.CannotRedoException;

/**
 * Redo actions for Swing Editor pane
 */
public class RedoAction
    extends AbstractAction {

  private UndoManager undoManager;
  private UndoAction undoAction;
  public RedoAction(UndoManager undoManager, UndoAction undoAction) {
    super("Redo");
    this.undoManager=undoManager;
    this.undoAction=undoAction;
    setEnabled(false);
  }

  public void actionPerformed(ActionEvent event) {
    try {
      undoManager.redo();
    }
    catch (CannotRedoException ex) {
     //ex.printStackTrace();
    }
    updateRedoState();
    undoAction.updateUndoState();
  }

  public void updateRedoState() {
    if (undoManager.canRedo()) {
      setEnabled(true);
      putValue(Action.NAME, undoManager.getRedoPresentationName());
    }
    else {
      setEnabled(false);
      putValue(Action.NAME, "Redo");
    }
  }

}
