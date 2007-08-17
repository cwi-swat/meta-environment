// Java tool interface NavigatorTif
// This file is generated automatically, please do not edit!
// generation time: Aug 17, 2007 11:11:44 AM

package nl.cwi.sen1.gui.plugin;

import aterm.*;

public interface NavigatorTif
{
  public void selectModule(ATerm t0);
  public void updateModule(ATerm t0, ATerm t1);
  public void markModuleNormal(ATerm t0);
  public void markModuleError(ATerm t0);
  public void deleteModule(ATerm t0);
  public void showPopup(ATerm t0, ATerm t1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
