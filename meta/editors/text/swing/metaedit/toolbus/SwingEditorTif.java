package nl.cwi.editor.toolbus;

// Java tool interface SwingEditorTif
// This file is generated automatically, please do not edit!
// generation time: Jul 1, 2004 4:53:36 PM


import aterm.*;

public interface SwingEditorTif
{
  public void isModified();
  public void writeContents();
  public void setFocus(ATerm t0);
  public void registerTextCategories(ATerm t0);
  public void clearFocus();
  public void addActions(ATerm t0);
  public void displayMessage(String s0);
  public void killEditor();
  public void setCursorAtOffset(int i0);
  public void editFile(String s0);
  public void highlightSlices(ATerm t0);
  public void editorToFront();
  public void rereadContents();
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
