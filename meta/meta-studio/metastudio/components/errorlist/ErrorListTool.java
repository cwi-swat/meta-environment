// Java tool interface class ErrorListTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 10:59:26 AM

package metastudio.components.errorlist;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class ErrorListTool
  extends SwingTool
  implements ErrorListTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PshowFeedbackSummary0;
  private ATerm PremoveFeedbackSummary0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected ErrorListTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected ErrorListTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<error-list>,show-feedback-summary(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<error-list>,remove-feedback-summary(<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<error-list>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowFeedbackSummary0 = factory.parse("rec-do(show-feedback-summary(<term>))");
    PremoveFeedbackSummary0 = factory.parse("rec-do(remove-feedback-summary(<str>,<str>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

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
      removeFeedbackSummary((String)result.get(0), (String)result.get(1));
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
