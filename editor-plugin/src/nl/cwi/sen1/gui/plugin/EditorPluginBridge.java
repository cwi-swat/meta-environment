// Java tool bridge EditorPluginBridge
// This file is generated automatically, please do not edit!
// generation time: Mar 7, 2007 4:16:27 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public class EditorPluginBridge
  extends EditorPluginTool
{
  private EditorPluginTif tool;

  public EditorPluginBridge(ATermFactory factory, EditorPluginTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  public void getContents(ATerm t0)
  {
    if (tool != null) {
      tool.getContents(t0);
    }
    else {
      throw new UnsupportedOperationException("method `getContents' not supported.");
    }
  }
  public void editFile(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.editFile(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `editFile' not supported.");
    }
  }
  public void setFocus(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.setFocus(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `setFocus' not supported.");
    }
  }
  public void isModified(ATerm t0)
  {
    if (tool != null) {
      tool.isModified(t0);
    }
    else {
      throw new UnsupportedOperationException("method `isModified' not supported.");
    }
  }
  public void killEditor(ATerm t0)
  {
    if (tool != null) {
      tool.killEditor(t0);
    }
    else {
      throw new UnsupportedOperationException("method `killEditor' not supported.");
    }
  }
  public void displayMessage(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.displayMessage(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `displayMessage' not supported.");
    }
  }
  public void setTooltip(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.setTooltip(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `setTooltip' not supported.");
    }
  }
  public void registerTextCategories(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.registerTextCategories(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `registerTextCategories' not supported.");
    }
  }
  public void setSelection(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.setSelection(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `setSelection' not supported.");
    }
  }
  public void writeContents(ATerm t0)
  {
    if (tool != null) {
      tool.writeContents(t0);
    }
    else {
      throw new UnsupportedOperationException("method `writeContents' not supported.");
    }
  }
  public void editorToFront(ATerm t0)
  {
    if (tool != null) {
      tool.editorToFront(t0);
    }
    else {
      throw new UnsupportedOperationException("method `editorToFront' not supported.");
    }
  }
  public void setEditable(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.setEditable(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `setEditable' not supported.");
    }
  }
  public void setContents(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.setContents(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `setContents' not supported.");
    }
  }
  public void highlightSlices(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.highlightSlices(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `highlightSlices' not supported.");
    }
  }
  public void setCursorAtOffset(ATerm t0, int i1)
  {
    if (tool != null) {
      tool.setCursorAtOffset(t0, i1);
    }
    else {
      throw new UnsupportedOperationException("method `setCursorAtOffset' not supported.");
    }
  }
  public void showPopup(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.showPopup(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `showPopup' not supported.");
    }
  }
  public void addActions(ATerm t0, ATerm t1)
  {
    if (tool != null) {
      tool.addActions(t0, t1);
    }
    else {
      throw new UnsupportedOperationException("method `addActions' not supported.");
    }
  }
  public void setInfo(ATerm t0, String s1)
  {
    if (tool != null) {
      tool.setInfo(t0, s1);
    }
    else {
      throw new UnsupportedOperationException("method `setInfo' not supported.");
    }
  }
  public void clearFocus(ATerm t0)
  {
    if (tool != null) {
      tool.clearFocus(t0);
    }
    else {
      throw new UnsupportedOperationException("method `clearFocus' not supported.");
    }
  }
  public void rereadContents(ATerm t0)
  {
    if (tool != null) {
      tool.rereadContents(t0);
    }
    else {
      throw new UnsupportedOperationException("method `rereadContents' not supported.");
    }
  }
  public void recAckEvent(ATerm t0)
  {
    if (tool != null) {
      tool.recAckEvent(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recAckEvent' not supported.");
    }
  }
  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }
}
