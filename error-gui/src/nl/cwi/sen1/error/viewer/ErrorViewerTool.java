// Java tool interface class ErrorViewerTool
// This file is generated automatically, please do not edit!
// generation time: Jan 30, 2007 7:11:53 AM

package nl.cwi.sen1.error.viewer;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

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
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PshowFeedbackSummary0;
  private ATerm PrefreshFeedbackSummary0;
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
    sigTable.add(factory.parse("rec-do(<error-viewer>,show-feedback-summary(<str>,<term>))"));
    sigTable.add(factory.parse("rec-do(<error-viewer>,remove-feedback-summary(<str>,<str>,<str>))"));
    sigTable.add(factory.parse("rec-do(<error-viewer>,remove-feedback-summary(<str>,<str>))"));
    sigTable.add(factory.parse("rec-do(<error-viewer>,refresh-feedback-summary(<str>,<term>))"));
    sigTable.add(factory.parse("rec-ack-event(<error-viewer>,<term>)"));
    sigTable.add(factory.parse("rec-terminate(<error-viewer>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowFeedbackSummary0 = factory.parse("rec-do(show-feedback-summary(<str>,<term>))");
    PrefreshFeedbackSummary0 = factory.parse("rec-do(refresh-feedback-summary(<str>,<term>))");
    PremoveFeedbackSummary0 = factory.parse("rec-do(remove-feedback-summary(<str>,<str>))");
    PremoveFeedbackSummary1 = factory.parse("rec-do(remove-feedback-summary(<str>,<str>,<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PshowFeedbackSummary0);
    if (result != null) {
      showFeedbackSummary((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PrefreshFeedbackSummary0);
    if (result != null) {
      refreshFeedbackSummary((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PremoveFeedbackSummary0);
    if (result != null) {
      removeFeedbackSummary((String)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PremoveFeedbackSummary1);
    if (result != null) {
      removeFeedbackSummary((String)result.get(0), (String)result.get(1), (String)result.get(2));
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
      if (!sigTable.contains(sig)) {
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
