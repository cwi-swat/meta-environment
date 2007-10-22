// Java tool interface class DebugAdapterTool
// This file is generated automatically, please do not edit!
// generation time: Feb 20, 2007 2:40:17 PM

package nl.cwi.sen1.tide.adapters;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.AbstractTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class DebugAdapterTool
  extends AbstractTool
  implements DebugAdapterTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PmodifyRule0;
  private ATerm PdisableRule0;
  private ATerm PenableRule0;
  private ATerm PdeleteRule0;
  private ATerm PcreateRule0;
  private ATerm Pevaluate0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected DebugAdapterTool(ATermFactory factory)
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
    PmodifyRule0 = factory.parse("rec-eval(modify-rule(<int>,<int>,<term>,<term>,<term>,<term>))");
    PdisableRule0 = factory.parse("rec-eval(disable-rule(<int>,<int>))");
    PenableRule0 = factory.parse("rec-eval(enable-rule(<int>,<int>))");
    PdeleteRule0 = factory.parse("rec-eval(delete-rule(<int>,<int>))");
    PcreateRule0 = factory.parse("rec-eval(create-rule(<int>,<term>,<term>,<term>,<term>,<term>))");
    Pevaluate0 = factory.parse("rec-eval(evaluate(<int>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PmodifyRule0);
    if (result != null) {
      return modifyRule(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue(), (ATerm)result.get(2), (ATerm)result.get(3), (ATerm)result.get(4), (ATerm)result.get(5));
    }
    result = term.match(PdisableRule0);
    if (result != null) {
      return disableRule(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
    }
    result = term.match(PenableRule0);
    if (result != null) {
      return enableRule(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
    }
    result = term.match(PdeleteRule0);
    if (result != null) {
      return deleteRule(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
    }
    result = term.match(PcreateRule0);
    if (result != null) {
      return createRule(((Integer)result.get(0)).intValue(), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3), (ATerm)result.get(4), (ATerm)result.get(5));
    }
    result = term.match(Pevaluate0);
    if (result != null) {
      return evaluate(((Integer)result.get(0)).intValue(), (ATerm)result.get(1));
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
