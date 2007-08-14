// Java tool interface class FactbrowserTool
// This file is generated automatically, please do not edit!
// generation time: Aug 14, 2007 5:15:07 PM

package nl.dancingbear.visbase.factbrowser;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class FactbrowserTool
  extends SwingTool
  implements FactbrowserTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PfbRstoreUnloaded0;
  private ATerm PfbAddVisualizationPlugin0;
  private ATerm PfbShowRstoreFacts0;
  private ATerm PgetSelectedRstoreid0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected FactbrowserTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-do(<factbrowser>,fb-add-visualization-plugin(<term>,<int>,<str>))"));
    sigTable.add(factory.parse("rec-eval(<factbrowser>,get-selected-rstoreid)"));
    sigTable.add(factory.parse("rec-do(<factbrowser>,fb-show-rstore-facts(<str>,<int>,<list>))"));
    sigTable.add(factory.parse("rec-ack-event(<factbrowser>,<term>)"));
    sigTable.add(factory.parse("rec-do(<factbrowser>,fb-rstore-unloaded(<int>))"));
    sigTable.add(factory.parse("rec-terminate(<factbrowser>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PfbRstoreUnloaded0 = factory.parse("rec-do(fb-rstore-unloaded(<int>))");
    PfbAddVisualizationPlugin0 = factory.parse("rec-do(fb-add-visualization-plugin(<term>,<int>,<str>))");
    PfbShowRstoreFacts0 = factory.parse("rec-do(fb-show-rstore-facts(<str>,<int>,<term>))");
    PgetSelectedRstoreid0 = factory.parse("rec-eval(get-selected-rstoreid)");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PfbRstoreUnloaded0);
    if (result != null) {
      fbRstoreUnloaded(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PfbAddVisualizationPlugin0);
    if (result != null) {
      fbAddVisualizationPlugin((ATerm)result.get(0), ((Integer)result.get(1)).intValue(), (String)result.get(2));
      return null;
    }
    result = term.match(PfbShowRstoreFacts0);
    if (result != null) {
      fbShowRstoreFacts((String)result.get(0), ((Integer)result.get(1)).intValue(), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PgetSelectedRstoreid0);
    if (result != null) {
      return getSelectedRstoreid();
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
