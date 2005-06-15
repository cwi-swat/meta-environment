// Java tool interface EditorPluginTif
// This file is generated automatically, please do not edit!
// generation time: Jun 13, 2005 12:50:25 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface EditorPluginTif
{
  public void isModified(ATerm t0);
  public void writeContents(ATerm t0);
  public void setFocus(ATerm t0, ATerm t1);
  public void registerTextCategories(ATerm t0, ATerm t1);
  public void addActions(ATerm t0, ATerm t1);
  public void clearFocus(ATerm t0);
  public void displayMessage(ATerm t0, String s1);
  public void killEditor(ATerm t0);
  public void setCursorAtOffset(ATerm t0, int i1);
  public void editFile(ATerm t0, String s1);
  public void highlightSlices(ATerm t0, ATerm t1);
  public void editorToFront(ATerm t0);
  public void rereadContents(ATerm t0);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
