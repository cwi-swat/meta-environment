// Java tool interface class StatusHistoryTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:47:58 PM

package metastudio.components.statushistory;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class StatusHistoryTool
  extends SwingTool
  implements StatusHistoryTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PlogStatus0;
  private ATerm PlogEndStatus0;
  private ATerm PlogStatusf0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected StatusHistoryTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected StatusHistoryTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<status-history>,log-status(<term>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<status-history>,log-statusf(<term>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<status-history>,log-end-status(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<status-history>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PlogStatus0 = factory.parse("rec-do(log-status(<term>,<str>))");
    PlogEndStatus0 = factory.parse("rec-do(log-end-status(<term>))");
    PlogStatusf0 = factory.parse("rec-do(log-statusf(<term>,<str>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PlogStatus0);
    if (result != null) {
      logStatus((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PlogEndStatus0);
    if (result != null) {
      logEndStatus((ATerm)result.get(0));
      return null;
    }
    result = term.match(PlogStatusf0);
    if (result != null) {
      logStatusf((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
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
