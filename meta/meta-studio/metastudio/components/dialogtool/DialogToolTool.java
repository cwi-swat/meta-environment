// Java tool interface class DialogToolTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:31:23 PM

package metastudio.components.dialogtool;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class DialogToolTool
  extends SwingTool
  implements DialogToolTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PshowListChoice0;
  private ATerm PshowQuestionDialog0;
  private ATerm PshowFileDialog0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected DialogToolTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected DialogToolTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  //}}}

  //{{{  private void initSigTable()

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.put(factory.parse("rec-eval(<dialog-tool>,show-file-dialog(<str>,<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<dialog-tool>,show-question-dialog(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<dialog-tool>,show-list-choice(<str>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<dialog-tool>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<dialog-tool>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowListChoice0 = factory.parse("rec-do(show-list-choice(<str>,<str>,<term>))");
    PshowQuestionDialog0 = factory.parse("rec-eval(show-question-dialog(<str>))");
    PshowFileDialog0 = factory.parse("rec-eval(show-file-dialog(<str>,<str>,<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PshowListChoice0);
    if (result != null) {
      showListChoice((String)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PshowQuestionDialog0);
    if (result != null) {
      return showQuestionDialog((String)result.get(0));
    }
    result = term.match(PshowFileDialog0);
    if (result != null) {
      return showFileDialog((String)result.get(0), (String)result.get(1), (String)result.get(2));
    }
    result = term.match(PrecAckEvent0);
    if (result != null) {
      recAckEvent((ATerm)result.get(0));
      return null;
    }
    result = term.match(PrecTerminate0);
    if (result != null) {
      recTerminate((ATerm)result.get(0));
      return null;
    }

      notInInputSignature(term);
    return null;
  }

  //}}}
  //{{{  public void checkInputSignature(ATermList sigs)

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

  //}}}
  //{{{  void notInInputSignature(ATerm t)

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATerm t)
  {
    throw new RuntimeException("term not in input signature: "+t);
  }

  //}}}
}
