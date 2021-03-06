// Java tool interface class SvgTool
// This file is generated automatically, please do not edit!
// generation time: Mar 11, 2007 3:42:54 PM

package nl.cwi.sen1.gui.plugin;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class SvgTool
  extends SwingTool
  implements SvgTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm Pdisplay0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected SvgTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-do(<svg>,display(<str>,<str>))"));
    sigTable.add(factory.parse("rec-terminate(<svg>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    Pdisplay0 = factory.parse("rec-do(display(<str>,<str>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(Pdisplay0);
    if (result != null) {
      display((String)result.get(0), (String)result.get(1));
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
