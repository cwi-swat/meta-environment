package metaedit;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;

import javax.swing.JMenuItem;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.undo.UndoManager;

import metaedit.action.RedoAction;
import metaedit.action.UndoAction;
import metaedit.toolbus.SwingEditorBridge;
import metaedit.toolbus.SwingEditorTif;
import metaedit.util.FindReplaceDialog;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: cwi.nl</p>
 * @author Said Lakhloufi
 * @version 1.0
 */

public class Controller
    implements ActionListener, MouseListener,
    WindowListener, SwingEditorTif, UndoableEditListener {
  private SwingEditorBridge bridge;
  private EditorModel model;
  private SwingEditor swingEditor;
  private ATermFactory factory;
  private FindReplaceDialog dialog;
  protected UndoManager undoManager;
  protected UndoAction undoAction;
  protected RedoAction redoAction;
  private boolean  editHappened=false;
  private boolean contentsChangeHappened=false;
  private int offset;
  private String contents;
 

  public Controller(EditorModel model, ATermFactory factory) throws IOException {
    this.factory = factory;
    this.undoManager= new UndoManager();
    this.undoAction=new UndoAction(undoManager, redoAction);
    this.redoAction= new RedoAction(undoManager, undoAction);

    this.model = model;
    swingEditor = new SwingEditor();
    model.addObserver(swingEditor);
    swingEditor.setController(this);
    swingEditor.setListener();
    bridge = new SwingEditorBridge(factory, this);

  }

  public SwingEditor getView() {
    return swingEditor;
  }

  public void runBridge(String[] args) throws IOException { 
      String fileName;
      for(int i=0; i<args.length; i++){
	 	 if (args[i].equals("--filename")){
	     fileName=args[i+1];
	     editFile(fileName);
	 	 }
	 	
      }
      bridge.init(args);
      bridge.connect();
      bridge.run();
  }

//this handles the buttons events
  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == swingEditor.exitMenuItem) {
      System.exit(0);
    }else if (e.getSource() == swingEditor.findMenuItem) {
      dialog = new FindReplaceDialog(swingEditor, swingEditor.swingEditorPane, false);
    }else if (e.getSource() == swingEditor.replaceMenuItem) {
      dialog = new FindReplaceDialog(swingEditor, swingEditor.swingEditorPane, true);
    } else if (e.getSource() == swingEditor.saveMenuItem) {
    	writeContents();
    	editHappened=true;
    	model.sendMessage("File saved");
    }else if (e.getSource() == swingEditor.copyMenuItem || e.getSource() == swingEditor.copyButton) {
      swingEditor.swingEditorPane.copy();
    }else if (e.getSource() == swingEditor.cutMenuItem || e.getSource() == swingEditor.cutButton) {
      swingEditor.swingEditorPane.cut();
    }else if (e.getSource() == swingEditor.pasteMenuItem ||e.getSource() == swingEditor.pasteButton) {
      swingEditor.swingEditorPane.paste();
    }else if (e.getSource() == swingEditor.redoButton ||
             e.getSource() == swingEditor.redoMenuItem) {
      if (undoManager.canRedo()) {
        redoAction.actionPerformed(e);
        contentsChanged();
      }
      else {
        model.sendMessage("Cann't redo");
      }
    }
    else if (e.getSource() == swingEditor.undoButton ||
             e.getSource() == swingEditor.undoMenuItem) {
      if (undoManager.canUndo()) {
        undoAction.actionPerformed(e);
        contentsChanged();
      }
      else {
        model.sendMessage("Cann't undo");
      }
    }
    else {
      JMenuItem action = (JMenuItem) e.getSource();
      String actionName = action.getActionCommand();
      String menuItem = action.getText();
      ATerm menuEvent= model.getMenuEvent(actionName, menuItem);
      bridge.postEvent(menuEvent);
    }
  }

//this handles the mouse events
  public void mouseClicked(MouseEvent e) {
    if (e.getSource() == swingEditor.swingEditorPane) {
      offset = swingEditor.swingEditorPane.getSelectionStart();
      ATerm mouseEvent = model.getMouseEvent(offset);
      bridge.postEvent(mouseEvent);
    }
  }

  public void undoableEditHappened(UndoableEditEvent e) {
  if (!e.getEdit().getPresentationName().equals("style change") && editHappened==true){
 	 undoManager.addEdit(e.getEdit());
 	 undoAction.updateUndoState();
 	 redoAction.updateRedoState();
  	 contentsChanged();
  }
  editHappened=true;
}


  public void contentsChanged(){
	if (contentsChangeHappened==false){
    	ATerm term=model.contentsChanged();
    	bridge.postEvent(model.contentsChanged());
		contentsChangeHappened=true;
	}
  }
 
  public void isModified() {
    ATerm isModified;
    if(undoManager.canUndoOrRedo()){
       isModified = model.isModified(1);
     } else{
       isModified = model.isModified(0);
     }
     bridge.postEvent(isModified);
  }

  public void writeContents() {
   model.writeContents(); 
   bridge.postEvent(model.isWritten());
   contentsChangeHappened=false;
  }

  public void setFocus(ATerm area) {
      model.setArea(area);
      model.setFocus();
  }

  public void editFile(String fileName) {
      model.editFile(fileName);
  }

  public void addActions(ATerm actionTerm) {
    ATermList actionList = (ATermList) actionTerm;
    model.addActions(actionList, this);
  }

  public void rereadContents() {
    model.rereadContents();
  }

  public void setCursorAtOffset(int offset) {
    if (offset >= 0) {
      swingEditor.swingEditorPane.select(offset, offset);
    }
  }

  public void clearFocus() {
   	model.clearFocus();
  }
  
  public void registerTextCategories(ATerm categories) {
 		model.setRegisterTextCategories(categories);
  } 
  
  public void highlightSlices(ATerm slices) {
  	model.setHighlightSlices((ATermList)slices);
  	model.makeStyles();
		model.setStyle();
		editHappened=true;
  }

  public void displayMessage(String message) {
    if (message != null) {
      model.sendMessage(message);
    }

  }

  public void editorToFront() {
     swingEditor.toFront();
  }

  public void killEditor() {
    System.exit(0);
  }

  public void recAckEvent(ATerm event) {
  }

  public void recTerminate(ATerm arg) {
    System.exit(0);

  }

//all other implements.....
  public void mouseReleased(MouseEvent e) {
  }

  public void mouseEntered(MouseEvent e) {
  }

  public void mouseExited(MouseEvent e) {
  }

  public void windowOpened(WindowEvent windowEvent) {
  }

  public void windowClosing(WindowEvent windowEvent) {
    System.exit(0);
  }

  public void windowClosed(WindowEvent windowEvent) {
    System.exit(0);
  }

  public void windowIconified(WindowEvent windowEvent) {
  }

  public void windowDeiconified(WindowEvent windowEvent) {
  }

  public void windowActivated(WindowEvent windowEvent) {
  }

  public void windowDeactivated(WindowEvent windowEvent) {
  }

  public void mousePressed(MouseEvent e) {
  }

}
