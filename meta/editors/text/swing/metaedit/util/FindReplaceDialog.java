package metaedit.util;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.util.Enumeration;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.border.TitledBorder;
import javax.swing.text.Document;


public class FindReplaceDialog extends JDialog {

  /** result value for this dialog */
  private int result;

  /** mode of dialog */
  private int mode;

  /** JEditorPane containing the document to search in */
  private JTextPane editor;
//  private JEditorPane editor;

  /** Document to search in */
  private Document doc;

  /** search text from the document */
  private String searchText;

  /** search phrase to find */
  private String phrase;

  /** new phrase to replace the searched phrase with */
  private String newPhrase;

  /** last start position, the search phrase was found at in the document */
  private int lastPos;

  /** two fields to correct position differences during replace operations */
  private int offset;
  private int replaceDiff;

  /** indicates if a find is already in progress */
  private boolean findInProgress = false;
  private boolean isReplace = false;

  /** indicates the current operation */
  private int operation;

  /** choice of replace operation */
  private int replaceChoice;

  /** the listeners for FindReplaceEvents */
  private Vector listeners = new Vector(0);

  /** separators for whole words only search */
  private static final char[] WORD_SEPARATORS = {' ', '\t', '\n',
      '\r', '\f', '.', ',', ':', '-', '(', ')', '[', ']', '{',
      '}', '<', '>', '/', '|', '\\', '\'', '\"'};

  /** options for replacing */
  private static final Object[] replaceOptions = { "Yes", "No", "All", "Done" };

  /* Constants for method toggleState */
  public static final boolean STATE_LOCKED = false;
  public static final boolean STATE_UNLOCKED = true;

  /* Constants for replaceOptions */
  public static final int RO_YES = 0;
  public static final int RO_NO = 1;
  public static final int RO_ALL = 2;
  public static final int RO_DONE = 3;

  /* Constants for dialog mode */
  public static final int MODE_DOCUMENT = 1;
  public static final int MODE_PROJECT = 2;

  /* Constants for operation */
  public static final int OP_NONE = 0;
  public static final int OP_FIND = 1;
  public static final int OP_REPLACE = 2;

  /* ---- GUI elements start ---------*/

  private TitledBorder titledBorder1;
  private JButton jbtnFindNext = new JButton();
  private JCheckBox jcbStartOnTop = new JCheckBox();
  private JRadioButton jrbDown = new JRadioButton();
  private JCheckBox jcbWholeWords = new JCheckBox();
  private JPanel jpnlBtn = new JPanel();
  private JPanel jpnlOptions = new JPanel();
  private JPanel jpnlFind = new JPanel();
  private JTextField jtfReplace = new JTextField();
  private JPanel jpnlMain = new JPanel();
  private JRadioButton jrbUp = new JRadioButton();
  private JTextField jtfPhrase = new JTextField();
  private JCheckBox jcbMatchCase = new JCheckBox();
  private JLabel jLabel3 = new JLabel();
  private JLabel jLabel4 = new JLabel();
  private GridBagLayout gridBagLayout4 = new GridBagLayout();
  private GridBagLayout gridBagLayout5 = new GridBagLayout();
  private JButton jbtnClose = new JButton();
  private GridBagLayout gridBagLayout6 = new GridBagLayout();
  private GridLayout gridLayout2 = new GridLayout();
  private JButton jbtnReplace = new JButton();
  private JButton jbtnCancel = new JButton();
  private JCheckBox jcbUnused = new JCheckBox();
  private JCheckBox jcbProject = new JCheckBox();

  /* ---- GUI elements end ---------*/

  /* ---- Constructor(s) start -----------*/

  /**
   * Construct a <code>FindReplaceDialog</code>.
   *
   * <p>Does not show the dialog window, as fields 'editor' and 'doc'
   * have to be set separately before the dialog is operable.</p>
   *
   * @see javax.swing.JEditorPane
   * @see javax.swing.text.Document
   * @see java.awt.Frame
   */
  public FindReplaceDialog() {
    try {
      jbInit();
      initDialogContents();
      pack();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  /**
   * Construct a <code>FindReplaceDialog</code>.
   *
   * <p>Shows the dialog window modal, packed and centered over the owning
   * <code>Frame</code> after construction.</p>
   *
   * <p>Using this constructor implies the dialog shall be used in mode
   * MODE_DOCUMENT</p>
   *
   * @param owner  the <code>Frame</code> that owns this dialog
   * @param editor  <code>JEditorPane</code> displaying the
   *                    <code>Document</code> to seach in
   *
   * @see javax.swing.JEditorPane
   * @see javax.swing.text.Document
   * @see java.awt.Frame
   */
  public FindReplaceDialog(Frame owner, JTextPane editor, boolean isReplace)
  {
    setEditor(editor);
    this.isReplace=isReplace;
    setMode(MODE_DOCUMENT);
    try {
      jbInit();
      initDialogContents();
      centerDialog(owner);
      pack();
      setVisible(true);
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  /**
   * Construct a <code>FindReplaceDialog</code>.
   *
   * <p>Shows the dialog window modal, packed and centered over the owning
   * <code>Frame</code> after construction.</p>
   *
   * <p>Using this constructor implies the dialog shall be used in mode
   * MODE_PROJECT</p>
   *
   * @param owner  the <code>Frame</code> that owns this dialog
   * @param editor  <code>JEditorPane</code> displaying the
   *                    <code>Document</code> to seach in
   * @param listener  listener for handling FindReplaceEvents
   *
   * @see javax.swing.JEditorPane
   * @see javax.swing.text.Document
   * @see java.awt.Frame
   */
  public FindReplaceDialog(Frame owner, JTextPane editor,
              FindReplaceListener listener)
  {
    setEditor(editor);
    setMode(MODE_PROJECT);
    addFindReplaceListener(listener);
    try {
      jbInit();
      initDialogContents();
      centerDialog(owner);
      pack();
      setVisible(true);
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  
  public void addFindReplaceListener(FindReplaceListener listener) {
    listeners.addElement(listener);
  }
public void removeFindReplaceListener(FindReplaceListener listener) {
    listeners.removeElement(listener);
  }

  
  private void fireGetNextDocument() {
    Enumeration listenerList = listeners.elements();
    while(listenerList.hasMoreElements()) {
      ((FindReplaceListener) listenerList.nextElement()).getNextDocument(
                                          new FindReplaceEvent(this));
    }
  }

  private void fireGetFirstDocument() {
    Enumeration listenerList = listeners.elements();
    while(listenerList.hasMoreElements()) {
      ((FindReplaceListener) listenerList.nextElement()).getFirstDocument(
                                          new FindReplaceEvent(this));
    }
  }

  public void resumeOperation() {
    this.doc = editor.getDocument();
    findInProgress = false;
    initFind();
    switch(operation) {
      case OP_FIND:
        find();
        break;
      case OP_REPLACE:
        replace();
        break;
    }
  }

  public void terminateOperation() {
    switch(operation) {
      case OP_FIND:
        message("No (more) occurrences found.");
        toggleState(STATE_UNLOCKED);
        jbtnReplace.setEnabled(true);
        break;
      case OP_REPLACE:
        switch(replaceChoice) {
          case RO_YES:
          case RO_NO:
            message("No (more) occurrences found.");
            break;
          case RO_ALL:
            message("All occurrences replaced");
            break;
        }
        toggleState(STATE_UNLOCKED);
        show();
        break;
    }
    operation = OP_NONE;
  }

  /**
   * perform a find, when button 'find next' is pressed
   */
  private void jbtnFindNext_actionPerformed(ActionEvent e) {
    operation = OP_FIND;
    jbtnReplace.setEnabled(false);
    if( mode == MODE_PROJECT &&
        jcbProject.isSelected() &&
        listeners.size() > 0 &&
        !findInProgress)
    {
      fireGetFirstDocument();
    }
    else {
      initFind();
      find();
    }
  }

  /**
   * perform a replace, when button 'replace' is pressed
   */
  private void jbtnReplace_actionPerformed(ActionEvent e) {
    operation = OP_REPLACE;
    replaceChoice = RO_YES;
    hide();
    if( mode == MODE_PROJECT &&
        jcbProject.isSelected() &&
        listeners.size() > 0)
    {
      fireGetFirstDocument();
    }
    else {
      initFind();
      replace();
    }
  }

  /**
   * Cancels the current find operation and switches the dialog back to
   * normal.
   */
  private void jbtnCancel_actionPerformed(ActionEvent e) {
    toggleState(STATE_UNLOCKED);
    jbtnReplace.setEnabled(true);
  }

  /**
   * When Close is pressed, store the pressed button in the result
   * of this dialog and dispose the dialog.
   */
  private void jbtnClose_actionPerformed(ActionEvent e) {
    result = JOptionPane.OK_OPTION;
    dispose();
  }

  public void setEditor(JTextPane editor) {
    this.editor = editor;
    this.doc = editor.getDocument();
  }

  public void setMode(int mode) {
    this.mode = mode;
    if(mode == MODE_PROJECT) {
      jcbProject.setVisible(true);
    }
    else {
      jcbProject.setVisible(false);
    }
  }

  private void initFind() {
    if(!findInProgress) {
      try {
        searchText = doc.getText(0, doc.getLength());
      }
      catch(Exception e) {
        e.printStackTrace();
      }
      phrase = jtfPhrase.getText();
      newPhrase = jtfReplace.getText();
      replaceDiff = newPhrase.length() - phrase.length();
      offset = 0;
      if(!jcbMatchCase.isSelected()) {
        phrase = phrase.toLowerCase();
        searchText = searchText.toLowerCase();
      }
      if(jcbStartOnTop.isSelected()) {
        if(jrbUp.isSelected()) {
          lastPos = doc.getLength();
        }
        else {
          lastPos = 0;
        }
      }
      else {
        lastPos = editor.getSelectionStart();
      }
      toggleState(STATE_LOCKED);
    }
  }

  private void find() {
    if(!doFind()) {
      if( mode == MODE_PROJECT &&
          jcbProject.isSelected() &&
          listeners.size() > 0)
      {
        fireGetNextDocument();
      }
      else {
        terminateOperation();
      }
    }
  }

  private boolean doFind() {
    boolean found = false;
    int start = findNext();
    if(jcbWholeWords.isSelected()) {
      start = findWholeWords(start);
    }
    if(start > 0) {
      lastPos = start;
      if(jrbDown.isSelected()) {
        start += offset;
      }
      editor.select(start, start + phrase.length());
      found = true;
    }
    return found;
  }

  private int findNext() {
    int start;
    if(jrbUp.isSelected()) {
      if(lastPos < doc.getLength()) {
        start = searchText.lastIndexOf(phrase, lastPos - 1);
      }
      else {
        start = searchText.lastIndexOf(phrase, lastPos);
      }
    }
    else {
      if(lastPos > 0) {
        start = searchText.indexOf(phrase, lastPos + phrase.length());
      }
      else {
        start = searchText.indexOf(phrase, lastPos);
      }
    }
    return start;
  }

  private int findWholeWords(int start) {
    while(  (start > 0) &&
            ((!isSeparator(searchText.charAt(start-1))) ||
            (!isSeparator(searchText.charAt(start + phrase.length())))))
    {
      lastPos = start;
      start = findNext();
    }
    return start;
  }

  
    private void replace() {
    while(doFind() && replaceChoice != RO_DONE) {
      if(replaceChoice != RO_ALL) {
        replaceChoice = getReplaceChoice();
      }
      switch(replaceChoice) {
        case RO_YES:
          replaceOne();
          break;
        case RO_ALL:
          replaceOne();
          while(doFind()) {
            replaceOne();
          }
          break;
      }
    }
    if( mode == MODE_PROJECT &&
        jcbProject.isSelected() &&
        listeners.size() > 0)
    {
      switch(replaceChoice) {
        case RO_YES:
        case RO_NO:
        case RO_ALL:
          fireGetNextDocument();
          break;
        case RO_DONE:
          terminateOperation();
          break;
      }
    }
    else {
      terminateOperation();
    }
  }

  /**
   * Show an option window asking the user for a decision about what to
   * do with the found occurrence during a replace operation.
   *
   * @return the chosen option, one of RO_YES, RO_NO, RO_DONE and RO_ALL
   */
  private int getReplaceChoice() {
    String msg = "Replace this occurrence of '" + phrase + "'?";
    return JOptionPane.showOptionDialog(
                this,
                msg,
                "Find and Replace",
                JOptionPane.YES_NO_CANCEL_OPTION,
                JOptionPane.QUESTION_MESSAGE,
                null,
                replaceOptions,
                null);
  }

  /**
   * Replace the currently selected occurrence of the search phrase
   */
  private void replaceOne() {
    editor.replaceSelection(newPhrase);
    offset += replaceDiff;
  }

  /* ----------- Replace implementation end ------- */

  /* ----------- Helper methods start ------- */

  /**
   * Set dialog components to their inital state
   */
  private void initDialogContents() {
    jbtnCancel.setEnabled(false);
    jrbUp.setSelected(false);
    jrbDown.setSelected(true);
    jcbWholeWords.setSelected(false);
    jcbMatchCase.setSelected(false);
    jcbStartOnTop.setSelected(true);
    jcbProject.setSelected(false);
    jtfPhrase.setText("");
    jtfReplace.setText("");
  }

  /**
   * Center this dialog window relative to its owning <code>Frame</code>.
   *
   * @param owner  <code>Frame</code> owning this dialog
   *
   * @see java.awt.Frame
   */
  public void centerDialog(Frame owner) {
    Dimension dlgSize = getPreferredSize();
    Dimension frmSize = owner.getSize();
    Point loc = owner.getLocation();
    setLocation((frmSize.width - dlgSize.width) / 2 + loc.x,
                            (frmSize.height - dlgSize.height) / 2 + loc.y);
  }

  /**
   * Toggle the state of the dialog window.
   *
   * <p>The state of the dialog is either unlocked (no find in progress) or
   * locked (find in progress).</p>
   *
   * @param unlocked  one of FindReplaceDialog.STATE_LOCKED and
   *      FindReplaceDialog.STATE_UNLOCKED
   */
  private void toggleState(boolean unlocked) {
    jbtnCancel.setEnabled(!unlocked);
    jtfPhrase.setEnabled(unlocked);
    jLabel3.setEnabled(unlocked);
    jLabel4.setEnabled(unlocked);
    jcbWholeWords.setEnabled(unlocked);
    jcbMatchCase.setEnabled(unlocked);
    jcbStartOnTop.setEnabled(unlocked);
    jrbUp.setEnabled(unlocked);
    jrbDown.setEnabled(unlocked);
    jcbProject.setEnabled(unlocked);
    findInProgress = !unlocked;
  }

  /**
   * method for determining whether or not a character is a
   * word separator.
   */
  private boolean isSeparator(char ch) {
    int i = 0;
    while((i<WORD_SEPARATORS.length) && (ch != WORD_SEPARATORS[i])) {
      i++;
    }
    return (i<WORD_SEPARATORS.length);
  }

  /**
   * Show an information message
   */
  private void message(String msgText) {
    JOptionPane.showMessageDialog(
                this,
                msgText,
                "Find and Replace",
                JOptionPane.INFORMATION_MESSAGE);
  }

  /* ----------- Helper methods end ------- */

  /** GUI builder init */
  private void jbInit() throws Exception {
    titledBorder1 = new TitledBorder(BorderFactory.createEtchedBorder(Color.white,new Color(142, 142, 142)),"Options");
    ButtonGroup bgSearchDirection = new ButtonGroup();
    jbtnFindNext.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        jbtnFindNext_actionPerformed(e);
      }
    });
    jbtnFindNext.setText("Find Next");
    jbtnFindNext.setPreferredSize(new Dimension(100, 27));
    jbtnFindNext.setMinimumSize(new Dimension(100, 27));
    jbtnFindNext.setMaximumSize(new Dimension(100, 27));
    jcbStartOnTop.setText("Search from start");
    jcbStartOnTop.setToolTipText("");
    jrbDown.setText("Search down");
    jcbWholeWords.setText("Whole words only");
    jpnlBtn.setLayout(gridBagLayout4);
    jpnlOptions.setBorder(titledBorder1);
    jpnlOptions.setLayout(gridLayout2);
    jpnlFind.setLayout(gridBagLayout5);
    jtfReplace.setMinimumSize(new Dimension(4, 12));
    jtfReplace.setPreferredSize(new Dimension(59, 12));
    jtfReplace.setText("jtfReplace");
    jpnlMain.setLayout(gridBagLayout6);
    jrbUp.setText("Search up");
    jtfPhrase.setMinimumSize(new Dimension(4, 12));
    jtfPhrase.setPreferredSize(new Dimension(63, 12));
    jtfPhrase.setText("jtfPhrase");
    jcbMatchCase.setText("Match case");
    jLabel3.setText("Replace with:");
    jLabel4.setText("Text to find:");
    jbtnClose.setMaximumSize(new Dimension(100, 27));
    jbtnClose.setMinimumSize(new Dimension(100, 27));
    jbtnClose.setPreferredSize(new Dimension(100, 27));
    jbtnClose.setText("Close");
    jbtnClose.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        jbtnClose_actionPerformed(e);
      }
    });
    gridLayout2.setRows(4);
    gridLayout2.setColumns(2);
    this.setModal(true);
    this.setTitle("Find and Replace");
    jbtnReplace.setMaximumSize(new Dimension(100, 27));
    jbtnReplace.setMinimumSize(new Dimension(100, 27));
    jbtnReplace.setPreferredSize(new Dimension(100, 27));
    jbtnReplace.setText("Replace...");
    jbtnReplace.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        jbtnReplace_actionPerformed(e);
      }
    });
    jbtnCancel.setMaximumSize(new Dimension(100, 27));
    jbtnCancel.setMinimumSize(new Dimension(100, 27));
    jbtnCancel.setPreferredSize(new Dimension(100, 27));
    jbtnCancel.setText("Cancel");
    jbtnCancel.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        jbtnCancel_actionPerformed(e);
      }
    });
    jcbUnused.setText("jcbUnused");
    jcbUnused.setVisible(false);
    jcbProject.setText("Search whole project");
    this.getContentPane().add(jpnlMain, BorderLayout.NORTH);
    jpnlBtn.add(jbtnFindNext,   new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
            ,GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(4, 4, 0, 4), 0, 0));
    jpnlBtn.add(jbtnClose,    new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0
            ,GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(0, 4, 4, 4), 0, 0));
    
    if (isReplace==true){
    		jpnlBtn.add(jbtnReplace,    new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0
            ,GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(4, 4, 4, 4), 0, 0));
    }
    
    jpnlBtn.add(jbtnCancel,  new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0
            ,GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(4, 4, 4, 4), 0, 0));
    jpnlMain.add(jpnlOptions, new GridBagConstraints(0, 1, 1, 1, 1.0, 1.0
            ,GridBagConstraints.SOUTHWEST, GridBagConstraints.NONE, new Insets(8, 2, 0, 6), 0, 0));
    jpnlMain.add(jpnlFind, new GridBagConstraints(0, 0, 1, 1, 1.0, 1.0
            ,GridBagConstraints.NORTHWEST, GridBagConstraints.BOTH, new Insets(4, 4, 4, 4), 0, 0));
    jpnlMain.add(jpnlBtn,  new GridBagConstraints(1, 0, 1, 2, 1.0, 1.0
            ,GridBagConstraints.NORTHEAST, GridBagConstraints.NONE, new Insets(4, 4, 4, 4), 0, 0));
    jpnlFind.add(jtfPhrase,  new GridBagConstraints(1, 0, 1, 1, 1.0, 0.0
            ,GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, new Insets(4, 4, 4, 4), 0, 12));
    jpnlFind.add(jLabel4, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
            ,GridBagConstraints.EAST, GridBagConstraints.NONE, new Insets(4, 4, 4, 4), 0, 0));
    if (isReplace==true){
    	jpnlFind.add(jtfReplace,       new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0
            ,GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, new Insets(4, 4, 4, 4), 0, 12));
    	jpnlFind.add(jLabel3, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0
            ,GridBagConstraints.EAST, GridBagConstraints.NONE, new Insets(4, 4, 4, 4), 0, 0));
    }
    
    jpnlOptions.add(jcbWholeWords, null);
    jpnlOptions.add(jrbUp, null);
    jpnlOptions.add(jcbMatchCase, null);
    jpnlOptions.add(jrbDown, null);
    jpnlOptions.add(jcbStartOnTop, null);
    jpnlOptions.add(jcbUnused, null);
    jpnlOptions.add(jcbProject, null);
    bgSearchDirection.add(jrbUp);
    bgSearchDirection.add(jrbDown);
  }
}
