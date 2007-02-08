// Java tool interface class GraphPainterTool
// This file is generated automatically, please do not edit!
// generation time: Jan 8, 2007 10:36:07 AM

package nl.cwi.sen1.gui.plugin;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.SwingTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class GraphPainterTool
  extends SwingTool
  implements GraphPainterTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PdisplayGraph0;
  private ATerm PselectNode0;
  private ATerm PupdateGraph0;
  private ATerm PshowPopup0;
  private ATerm PcreatePanel0;
  private ATerm PsizeGraph0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected GraphPainterTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-do(<graph-painter>,display-graph(<str>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<graph-painter>,update-graph(<str>,<term>,<term>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-eval(<graph-painter>,create-panel(<str>,<term>,<bool>,<bool>))"));
    sigTable.add(factory.parse("rec-eval(<graph-painter>,size-graph(<str>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<graph-painter>,select-node(<str>,<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<graph-painter>,show-popup(<str>,<term>,<term>,<list>))"));
    sigTable.add(factory.parse("rec-ack-event(<graph-painter>,<term>)"));
    sigTable.add(factory.parse("rec-terminate(<graph-painter>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdisplayGraph0 = factory.parse("rec-do(display-graph(<str>,<term>,<term>))");
    PselectNode0 = factory.parse("rec-do(select-node(<str>,<term>,<term>))");
    PupdateGraph0 = factory.parse("rec-do(update-graph(<str>,<term>,<term>,<term>,<term>))");
    PshowPopup0 = factory.parse("rec-do(show-popup(<str>,<term>,<term>,<term>))");
    PcreatePanel0 = factory.parse("rec-eval(create-panel(<str>,<term>,<term>,<term>))");
    PsizeGraph0 = factory.parse("rec-eval(size-graph(<str>,<term>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PdisplayGraph0);
    if (result != null) {
      displayGraph((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PselectNode0);
    if (result != null) {
      selectNode((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PupdateGraph0);
    if (result != null) {
      updateGraph((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3), (ATerm)result.get(4));
      return null;
    }
    result = term.match(PshowPopup0);
    if (result != null) {
      showPopup((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3));
      return null;
    }
    result = term.match(PcreatePanel0);
    if (result != null) {
      return createPanel((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3));
    }
    result = term.match(PsizeGraph0);
    if (result != null) {
      return sizeGraph((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
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
