// Java tool interface EditorPluginTif
// This file is generated automatically, please do not edit!
// generation time: Mar 7, 2007 4:16:27 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface EditorPluginTif
{
  public void getContents(ATerm t0);
  public void editFile(ATerm t0, String s1);
  public void setFocus(ATerm t0, ATerm t1);
  public void isModified(ATerm t0);
  public void killEditor(ATerm t0);
  public void displayMessage(ATerm t0, String s1);
  public void setTooltip(ATerm t0, String s1);
  public void registerTextCategories(ATerm t0, ATerm t1);
  public void setSelection(ATerm t0, ATerm t1);
  public void writeContents(ATerm t0);
  public void editorToFront(ATerm t0);
  public void setEditable(ATerm t0, ATerm t1);
  public void setContents(ATerm t0, String s1);
  public void highlightSlices(ATerm t0, ATerm t1);
  public void setCursorAtOffset(ATerm t0, int i1);
  public void showPopup(ATerm t0, ATerm t1);
  public void addActions(ATerm t0, ATerm t1);
  public void setInfo(ATerm t0, String s1);
  public void clearFocus(ATerm t0);
  public void rereadContents(ATerm t0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
