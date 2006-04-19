// Java tool interface class ErrorViewerTool
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2006 9:56:30 AM

package nl.cwi.sen1.error.viewer;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class ErrorViewerTool
  extends SwingTool
  implements ErrorViewerTif
{
  // This table will hold the complete input signature
  private Map<ATerm, Boolean> sigTable = new HashMap<ATerm, Boolean>();

  // Patterns that are used to match against incoming terms
  private ATerm PshowFeedbackSummary0;
  private ATerm PremoveFeedbackSummary0;
  private ATerm PremoveFeedbackSummary1;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected ErrorViewerTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    Boolean btrue = new Boolean(true);
    sigTable.put(factory.parse("rec-do(<error-viewer>,show-feedback-summary(<term>))"), btrue);
    sigTable.put(factory.parse("rec-do(<error-viewer>,remove-feedback-summary(<str>,<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<error-viewer>,remove-feedback-summary(<str>))"), btrue);
    sigTable.put(factory.parse("rec-ack-event(<error-viewer>,<term>)"), btrue);
    sigTable.put(factory.parse("rec-terminate(<error-viewer>,<term>)"), btrue);
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowFeedbackSummary0 = factory.parse("rec-do(show-feedback-summary(<term>))");
    PremoveFeedbackSummary0 = factory.parse("rec-do(remove-feedback-summary(<str>))");
    PremoveFeedbackSummary1 = factory.parse("rec-do(remove-feedback-summary(<str>,<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PshowFeedbackSummary0);
    if (result != null) {
      showFeedbackSummary((ATerm)result.get(0));
      return null;
    }
    result = term.match(PremoveFeedbackSummary0);
    if (result != null) {
      removeFeedbackSummary((String)result.get(0));
      return null;
    }
    result = term.match(PremoveFeedbackSummary1);
    if (result != null) {
      removeFeedbackSummary((String)result.get(0), (String)result.get(1));
      return null;
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
