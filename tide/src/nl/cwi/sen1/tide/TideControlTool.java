// Java tool interface class TideControlTool
// This file is generated automatically, please do not edit!
// generation time: Feb 20, 2007 2:36:36 PM

package nl.cwi.sen1.tide;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.AbstractTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class TideControlTool
  extends AbstractTool
  implements TideControlTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected TideControlTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-terminate(<tide-control>,<term>)"));
    sigTable.add(factory.parse("rec-ack-event(<debug-tool>,<term>)"));
    sigTable.add(factory.parse("rec-do(<debug-tool>,adapter-connected(<debug-adapter>))"));
    sigTable.add(factory.parse("rec-do(<debug-tool>,adapter-disconnected(<debug-adapter>))"));
    sigTable.add(factory.parse("rec-do(<debug-tool>,process-created(<proc(<debug-adapter>,<int>)>,<str>))"));
    sigTable.add(factory.parse("rec-do(<debug-tool>,process-destroyed(<proc(<debug-adapter>,<int>)>))"));
    sigTable.add(factory.parse("rec-do(<debug-tool>,event(<proc(<debug-adapter>,<int>)>,<int>,<term>))"));
    sigTable.add(factory.parse("rec-terminate(<debug-tool>,<term>)"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,evaluate(<int>,<term>))"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,create-rule(<int>,<term>,<term>,<term>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,enable-rule(<int>,<int>))"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,disable-rule(<int>,<int>))"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,modify-rule(<int>,<int>,<term>,<term>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-eval(<debug-adapter>,delete-rule(<int>,<int>))"));
    sigTable.add(factory.parse("rec-ack-event(<debug-adapter>,<term>)"));
    sigTable.add(factory.parse("rec-terminate(<debug-adapter>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

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
