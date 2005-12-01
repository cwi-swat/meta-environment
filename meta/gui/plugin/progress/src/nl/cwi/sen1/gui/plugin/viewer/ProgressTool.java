// Java tool interface class ProgressTool
// This file is generated automatically, please do not edit!
// generation time: Nov 28, 2005 8:06:26 AM

package nl.cwi.sen1.gui.plugin.viewer;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class ProgressTool
  extends SwingTool
  implements ProgressTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PclearStatusWindow0;
  private ATerm PsetStatus0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected ProgressTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected ProgressTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<progress>,set-status(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<progress>,clear-status-window)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<progress>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PclearStatusWindow0 = factory.parse("rec-do(clear-status-window)");
    PsetStatus0 = factory.parse("rec-do(set-status(<str>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PclearStatusWindow0);
    if (result != null) {
      clearStatusWindow();
      return null;
    }
    result = term.match(PsetStatus0);
    if (result != null) {
      setStatus((String)result.get(0), (ATerm)result.get(1));
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
