package nl.cwi.editor.toolbus;

// Java tool bridge SwingEditorBridge
// This file is generated automatically, please do not edit!
// generation time: Jul 1, 2004 4:53:36 PM


import aterm.*;

public class SwingEditorBridge
  extends SwingEditorTool
{
  private SwingEditorTif tool;

  //{{{  public SwingEditorBridge(ATermFactory factory, SwingEditorTif tool)

  public SwingEditorBridge(ATermFactory factory, SwingEditorTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public void getContents()

  public void getContents()
  {
    if (tool != null) {
      tool.getContents();
    }
    else {
      throw new UnsupportedOperationException("method `getContents' not supported.");
    }
  }

  //}}}
  //{{{  public void isModified()

  public void isModified()
  {
    if (tool != null) {
      tool.isModified();
    }
    else {
      throw new UnsupportedOperationException("method `isModified' not supported.");
    }
  }

  //}}}
  //{{{  public void writeContents()

  public void writeContents()
  {
    if (tool != null) {
      tool.writeContents();
    }
    else {
      throw new UnsupportedOperationException("method `writeContents' not supported.");
    }
  }

  //}}}
  //{{{  public void setFocus(ATerm t0)

  public void setFocus(ATerm t0)
  {
    if (tool != null) {
      tool.setFocus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `setFocus' not supported.");
    }
  }

  //}}}
  //{{{  public void registerTextCategories(ATerm t0)

  public void registerTextCategories(ATerm t0)
  {
    if (tool != null) {
      tool.registerTextCategories(t0);
    }
    else {
      throw new UnsupportedOperationException("method `registerTextCategories' not supported.");
    }
  }

  //}}}
  //{{{  public void clearFocus()

  public void clearFocus()
  {
    if (tool != null) {
      tool.clearFocus();
    }
    else {
      throw new UnsupportedOperationException("method `clearFocus' not supported.");
    }
  }

  //}}}
  //{{{  public void addActions(ATerm t0)

  public void addActions(ATerm t0)
  {
    if (tool != null) {
      tool.addActions(t0);
    }
    else {
      throw new UnsupportedOperationException("method `addActions' not supported.");
    }
  }

  //}}}
  //{{{  public void displayMessage(String s0)

  public void displayMessage(String s0)
  {
    if (tool != null) {
      tool.displayMessage(s0);
    }
    else {
      throw new UnsupportedOperationException("method `displayMessage' not supported.");
    }
  }

  //}}}
  //{{{  public void killEditor()

  public void killEditor()
  {
    if (tool != null) {
      tool.killEditor();
    }
    else {
      throw new UnsupportedOperationException("method `killEditor' not supported.");
    }
  }

  //}}}
  //{{{  public void setCursorAtOffset(int i0)

  public void setCursorAtOffset(int i0)
  {
    if (tool != null) {
      tool.setCursorAtOffset(i0);
    }
    else {
      throw new UnsupportedOperationException("method `setCursorAtOffset' not supported.");
    }
  }

  //}}}
  //{{{  public void editFile(String s0)

  public void editFile(String s0)
  {
    if (tool != null) {
      tool.editFile(s0);
    }
    else {
      throw new UnsupportedOperationException("method `editFile' not supported.");
    }
  }

  //}}}
  //{{{  public void highlightSlices(ATerm t0)

  public void highlightSlices(ATerm t0)
  {
    if (tool != null) {
      tool.highlightSlices(t0);
    }
    else {
      throw new UnsupportedOperationException("method `highlightSlices' not supported.");
    }
  }

  //}}}
  //{{{  public void editorToFront()

  public void editorToFront()
  {
    if (tool != null) {
      tool.editorToFront();
    }
    else {
      throw new UnsupportedOperationException("method `editorToFront' not supported.");
    }
  }

  //}}}
  //{{{  public void rereadContents()

  public void rereadContents()
  {
    if (tool != null) {
      tool.rereadContents();
    }
    else {
      throw new UnsupportedOperationException("method `rereadContents' not supported.");
    }
  }

  //}}}
  //{{{  public void recAckEvent(ATerm t0)

  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
