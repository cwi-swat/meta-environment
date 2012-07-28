// Java tool interface class VisPluginTextUnparsingTool
// This file is generated automatically, please do not edit!
// generation time: Aug 22, 2007 2:40:01 PM

package nl.cwi.sen1.visplugin.text;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.SwingTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class VisPluginTextUnparsingTool
  extends SwingTool
  implements VisPluginTextUnparsingTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PdisplayUnparsedRtuple0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected VisPluginTextUnparsingTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-eval(<lift-rstore>,lift-rstore(<term>))"));
    sigTable.add(factory.parse("rec-eval(<lift-rstore>,lift-rtuple(<term>))"));
    sigTable.add(factory.parse("rec-terminate(<lift-rstore>,<term>)"));
    sigTable.add(factory.parse("rec-eval(<unparser>,unparse-asfix(<term>))"));
    sigTable.add(factory.parse("rec-terminate(<unparser>,<term>)"));
    sigTable.add(factory.parse("rec-ack-event(<vis-plugin-text-unparsing>,<term>)"));
    sigTable.add(factory.parse("rec-do(<vis-plugin-text-unparsing>,display-unparsed-rtuple(<str>))"));
    sigTable.add(factory.parse("rec-terminate(<vis-plugin-text-unparsing>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdisplayUnparsedRtuple0 = factory.parse("rec-do(display-unparsed-rtuple(<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PdisplayUnparsedRtuple0);
    if (result != null) {
      displayUnparsedRtuple((String)result.get(0));
      return null;
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
