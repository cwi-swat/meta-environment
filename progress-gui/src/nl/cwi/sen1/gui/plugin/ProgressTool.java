// Java tool interface class ProgressTool
// This file is generated automatically, please do not edit!
// generation time: Apr 24, 2006 11:34:29 PM

package nl.cwi.sen1.gui.plugin;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class ProgressTool
  extends SwingTool
  implements ProgressTif
{
  // This table will hold the complete input signature
  private Map<ATerm, Boolean> sigTable = new HashMap<ATerm, Boolean>();

  // Patterns that are used to match against incoming terms
  private ATerm PremoveStatus0;
  private ATerm PclearStatusWindow0;
  private ATerm PsetStatus0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected ProgressTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    Boolean btrue = new Boolean(true);
    sigTable.put(factory.parse("rec-do(<progress>,set-status(<str>,<str>,<term>))"), btrue);
    sigTable.put(factory.parse("rec-do(<progress>,remove-status(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<progress>,clear-status-window)"), btrue);
    sigTable.put(factory.parse("rec-terminate(<progress>,<term>)"), btrue);
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PremoveStatus0 = factory.parse("rec-do(remove-status(<str>))");
    PclearStatusWindow0 = factory.parse("rec-do(clear-status-window)");
    PsetStatus0 = factory.parse("rec-do(set-status(<str>,<str>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PremoveStatus0);
    if (result != null) {
      removeStatus((String)result.get(0));
      return null;
    }
    result = term.match(PclearStatusWindow0);
    if (result != null) {
      clearStatusWindow();
      return null;
    }
    result = term.match(PsetStatus0);
    if (result != null) {
      setStatus((String)result.get(0), (String)result.get(1), (ATerm)result.get(2));
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
