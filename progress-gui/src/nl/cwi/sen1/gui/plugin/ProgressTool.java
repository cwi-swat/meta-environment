// Java tool interface class ProgressTool
// This file is generated automatically, please do not edit!
// generation time: Jan 4, 2007 3:18:21 PM

package nl.cwi.sen1.gui.plugin;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

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
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PsetMessage0;
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
    sigTable.add(factory.parse("rec-do(<progress>,set-status(<term>,<str>,<term>))"));
    sigTable.add(factory.parse("rec-do(<progress>,set-message(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<progress>,remove-status(<term>))"));
    sigTable.add(factory.parse("rec-do(<progress>,clear-status-window)"));
    sigTable.add(factory.parse("rec-terminate(<progress>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PsetMessage0 = factory.parse("rec-do(set-message(<term>,<str>))");
    PremoveStatus0 = factory.parse("rec-do(remove-status(<term>))");
    PclearStatusWindow0 = factory.parse("rec-do(clear-status-window)");
    PsetStatus0 = factory.parse("rec-do(set-status(<term>,<str>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PsetMessage0);
    if (result != null) {
      setMessage((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PremoveStatus0);
    if (result != null) {
      removeStatus((ATerm)result.get(0));
      return null;
    }
    result = term.match(PclearStatusWindow0);
    if (result != null) {
      clearStatusWindow();
      return null;
    }
    result = term.match(PsetStatus0);
    if (result != null) {
      setStatus((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
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
