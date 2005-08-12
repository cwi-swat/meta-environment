/*
 * Copyright (C) 2003 by Christian Lauer.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * If you didn't download this code from the following link, you should check if
 * you aren't using an obsolete version:
 * http://sourceforge.net/projects/ujac
 */

package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Container;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;

import javax.swing.AbstractAction;
import javax.swing.ActionMap;
import javax.swing.InputMap;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.KeyStroke;

/**
 * Name: BaseDialog<br>
 * Description: A base class for dialogs, adding common key bindings to the dialog, 
 * such as ESCAPE (-> cancel dialog) or ENTER (-> OK action). 
 * <br>Log: $Log$
 * <br>Log: Revision 1.2  2005/08/12 08:03:23  kooiker
 * <br>Log:  * src/**/*.java:
 * <br>Log:    - removed deprecated show/hide methods
 * <br>Log:    - removed unused events
 * <br>Log:    - fixed cancel in GotoLine dialog
 * <br>Log:
 * <br>Log: Revision 1.1  2005/08/11 12:52:47  jurgenv
 * <br>Log:    - added Search and Replace
 * <br>Log:    - added Goto Line
 * <br>Log:    - added Edit Menu
 * <br>Log:
 * <br>Log: Revision 1.1  2004/01/20 20:29:57  lauerc
 * <br>Log: Moved user interface components to sub project UJAC-UI.
 * <br>Log:
 * @author $Author$
 * @version $Revision$
 */
public class BaseDialog extends JDialog {

  /** Constant for the dialog state OK. */
  public static final int OK = 1;
  /** Constant for the dialog state CANCEL. */
  public static final int CANCEL = 0;

  /** The dialog state. */
  private int state = CANCEL;

  /**
   * Gets the dialog state.
   * @return The dialog state. 
   */
  public int getState() {
    return state;
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog() throws UnsupportedOperationException {
    super();
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param frame The parent frame.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Frame frame) throws UnsupportedOperationException {
    super(frame);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param frame The parent frame.
   * @param modal The modal flag.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Frame frame, boolean modal) throws UnsupportedOperationException {
    super(frame, modal);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param frame The parent frame.
   * @param title The dialog title.
   * @throws java.awt.HeadlessException if GraphicsEnvironment.isHeadless() returns true.
   */
  public BaseDialog(Frame frame, String title) throws UnsupportedOperationException {
    super(frame, title);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param frame The parent frame.
   * @param title The dialog title.
   * @param modal The modal flag.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Frame frame, String title, boolean modal) throws UnsupportedOperationException {
    super(frame, title, modal);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param parent The parent dialog.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Dialog parent) throws UnsupportedOperationException {
    super(parent);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param parent The parent dialog.
   * @param modal The modal flag.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Dialog parent, boolean modal) throws UnsupportedOperationException {
    super(parent, modal);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param parent The parent dialog.
   * @param title The dialog title.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Dialog parent, String title) throws UnsupportedOperationException {
    super(parent, title);
  }

  /**
   * Constructs a BaseDialog instance with specific attributes.
   * @param parent The parent dialog.
   * @param title The dialog title.
   * @param modal The modal flag.
   * @throws java.awt.HeadlessException
   */
  public BaseDialog(Dialog parent, String title, boolean modal) throws UnsupportedOperationException {
    super(parent, title, modal);
  }

  /**
   * Registers standard key bindings.
   */
  protected void registerStandardKeyBindings() {
    // defining key bindings
    InputMap inputMap = this.getRootPane().getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW);
    inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), "escape");
    inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "enter");

    ActionMap actionMap = this.getRootPane().getActionMap();
    actionMap.put("enter", new AbstractAction() {
      /**
       * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
       */
      public void actionPerformed(ActionEvent evt) {
        okButtonActionPerformed();
      }
    });
    actionMap.put("escape", new AbstractAction() {
      /**
       * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
       */
      public void actionPerformed(ActionEvent evt) {
        cancelButtonActionPerformed();
      }
    });
  }

  /**
   * Processes the action event, raised by the OK button.  
   * @param evt The raised action event.
   */
  private void okButtonActionPerformed() {
    this.state = OK;
    closeDialog();
  }

  /**
   * Processes the action event, raised by the Cancel button.  
   * @param evt The raised action event.
   */
  private void cancelButtonActionPerformed() {
    this.state = CANCEL;
    closeDialog();
  }


  /** 
   * Closes the dialog
   * @param evt The window event.  
   */
  protected void closeDialog() {
    setVisible(false);
    dispose();
  }

  /**
   * Centers the dialog over its parent component.
   */
  protected void centerDialog(Container parent) {
    Dimension parentSize = parent.getSize();
    Dimension dialogSize = this.getSize();
    Point parentLocn = parent.getLocationOnScreen();

    int locnX = parentLocn.x + (parentSize.width - dialogSize.width) / 2;
    int locnY = parentLocn.y + (parentSize.height - dialogSize.height) / 2;
    
    setLocation(locnX, locnY);
  }
}
