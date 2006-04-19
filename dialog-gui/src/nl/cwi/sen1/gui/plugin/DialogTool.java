// Java tool interface class DialogTool
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 9:54:56 AM

package nl.cwi.sen1.gui.plugin;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class DialogTool
  extends SwingTool
  implements DialogTif
{
  // This table will hold the complete input signature
  private Map<ATerm, Boolean> sigTable = new HashMap<ATerm, Boolean>();

  // Patterns that are used to match against incoming terms
  private ATerm PshowProgressMessage0;
  private ATerm PshowErrorDialogWithArguments0;
  private ATerm PshowProgressList0;
  private ATerm PshowProgressMessageWithArguments0;
  private ATerm PshowErrorDialog0;
  private ATerm PcloseProgressList0;
  private ATerm PshowQuestionDialog0;
  private ATerm PshowDirectoryDialog0;
  private ATerm PshowFileDialog0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected DialogTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    Boolean btrue = new Boolean(true);
    sigTable.put(factory.parse("rec-do(<dialog>,show-error-dialog(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<dialog>,show-error-dialog-with-arguments(<str>,<list>))"), btrue);
    sigTable.put(factory.parse("rec-eval(<dialog>,show-directory-dialog(<str>,<list>))"), btrue);
    sigTable.put(factory.parse("rec-eval(<dialog>,show-file-dialog(<str>,<list>,<str>))"), btrue);
    sigTable.put(factory.parse("rec-eval(<dialog>,show-question-dialog(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-list(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-message(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-message-with-arguments(<str>,<list>))"), btrue);
    sigTable.put(factory.parse("rec-do(<dialog>,close-progress-list)"), btrue);
    sigTable.put(factory.parse("rec-terminate(<dialog>,<term>)"), btrue);
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowProgressMessage0 = factory.parse("rec-do(show-progress-message(<str>))");
    PshowErrorDialogWithArguments0 = factory.parse("rec-do(show-error-dialog-with-arguments(<str>,<term>))");
    PshowProgressList0 = factory.parse("rec-do(show-progress-list(<str>))");
    PshowProgressMessageWithArguments0 = factory.parse("rec-do(show-progress-message-with-arguments(<str>,<term>))");
    PshowErrorDialog0 = factory.parse("rec-do(show-error-dialog(<str>))");
    PcloseProgressList0 = factory.parse("rec-do(close-progress-list)");
    PshowQuestionDialog0 = factory.parse("rec-eval(show-question-dialog(<str>))");
    PshowDirectoryDialog0 = factory.parse("rec-eval(show-directory-dialog(<str>,<term>))");
    PshowFileDialog0 = factory.parse("rec-eval(show-file-dialog(<str>,<term>,<str>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PshowProgressMessage0);
    if (result != null) {
      showProgressMessage((String)result.get(0));
      return null;
    }
    result = term.match(PshowErrorDialogWithArguments0);
    if (result != null) {
      showErrorDialogWithArguments((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PshowProgressList0);
    if (result != null) {
      showProgressList((String)result.get(0));
      return null;
    }
    result = term.match(PshowProgressMessageWithArguments0);
    if (result != null) {
      showProgressMessageWithArguments((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PshowErrorDialog0);
    if (result != null) {
      showErrorDialog((String)result.get(0));
      return null;
    }
    result = term.match(PcloseProgressList0);
    if (result != null) {
      closeProgressList();
      return null;
    }
    result = term.match(PshowQuestionDialog0);
    if (result != null) {
      return showQuestionDialog((String)result.get(0));
    }
    result = term.match(PshowDirectoryDialog0);
    if (result != null) {
      return showDirectoryDialog((String)result.get(0), (ATerm)result.get(1));
    }
    result = term.match(PshowFileDialog0);
    if (result != null) {
      return showFileDialog((String)result.get(0), (ATerm)result.get(1), (String)result.get(2));
    }
    result = term.match(PrecTerminate0);
    if (result != null) {
      recTerminate((ATerm)result.get(0));
      return null;
    }

    notInInputSignature(term);
    return null;
  }

  // Check the input signature
  public void checkInputSignature(ATermList sigs)
  {
    while(!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl)sigs.getFirst();
      sigs = sigs.getNext();
      if (!sigTable.containsKey(sig)) {
        // Sorry, but the term is not in the input signature!
        notInInputSignature(sig);
      }
    }
  }

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATerm t)
  {
    throw new RuntimeException("term not in input signature: " + t);
  }
}
