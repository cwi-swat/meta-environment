package nl.dancingbear.visplugin;

// Java tool interface class VisualizationPluginTool
// This file is generated automatically, please do not edit!
// generation time: Mar 14, 2007 12:48:38 PM


import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.AbstractTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class VisualizationPluginTool
  extends AbstractTool
  implements VisualizationPluginTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PvpFileDialogResult0;
  private ATerm PvpVisualizeFact0;
  private ATerm PvpRstoreUnloaded0;
  private ATerm PvpFileDialogCancel0;
  private ATerm PvpFactOutOfDate0;
  private ATerm PvpGetName0;
  private ATerm PvpIsTypeSupported0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected VisualizationPluginTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-eval(<visualizationPlugin>,vp-get-name)"));
    sigTable.add(factory.parse("rec-eval(<visualizationPlugin>,vp-is-type-supported(<term>))"));
    sigTable.add(factory.parse("rec-do(<visualizationPlugin>,vp-visualize-fact(<int>,<int>,<term>))"));
    sigTable.add(factory.parse("rec-do(<visualizationPlugin>,vp-fact-out-of-date(<int>,<int>))"));
    sigTable.add(factory.parse("rec-ack-event(<visualizationPlugin>,<term>)"));
    sigTable.add(factory.parse("rec-do(<visualizationPlugin>,vp-file-dialog-result(<int>,<str>))"));
    sigTable.add(factory.parse("rec-do(<visualizationPlugin>,vp-file-dialog-cancel(<int>))"));
    sigTable.add(factory.parse("rec-do(<visualizationPlugin>,vp-rstore-unloaded(<int>))"));
    sigTable.add(factory.parse("rec-terminate(<visualizationPlugin>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PvpFileDialogResult0 = factory.parse("rec-do(vp-file-dialog-result(<int>,<str>))");
    PvpVisualizeFact0 = factory.parse("rec-do(vp-visualize-fact(<int>,<int>,<term>))");
    PvpRstoreUnloaded0 = factory.parse("rec-do(vp-rstore-unloaded(<int>))");
    PvpFileDialogCancel0 = factory.parse("rec-do(vp-file-dialog-cancel(<int>))");
    PvpFactOutOfDate0 = factory.parse("rec-do(vp-fact-out-of-date(<int>,<int>))");
    PvpGetName0 = factory.parse("rec-eval(vp-get-name)");
    PvpIsTypeSupported0 = factory.parse("rec-eval(vp-is-type-supported(<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PvpFileDialogResult0);
    if (result != null) {
      vpFileDialogResult(((Integer)result.get(0)).intValue(), (String)result.get(1));
      return null;
    }
    result = term.match(PvpVisualizeFact0);
    if (result != null) {
      vpVisualizeFact(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue(), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PvpRstoreUnloaded0);
    if (result != null) {
      vpRstoreUnloaded(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PvpFileDialogCancel0);
    if (result != null) {
      vpFileDialogCancel(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PvpFactOutOfDate0);
    if (result != null) {
      vpFactOutOfDate(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(PvpGetName0);
    if (result != null) {
      return vpGetName();
    }
    result = term.match(PvpIsTypeSupported0);
    if (result != null) {
      return vpIsTypeSupported((ATerm)result.get(0));
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
