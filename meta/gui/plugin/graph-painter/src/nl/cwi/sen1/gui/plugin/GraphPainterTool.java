// Java tool interface class GraphPainterTool
// This file is generated automatically, please do not edit!
// generation time: May 30, 2005 2:02:01 PM

package nl.cwi.sen1.gui.plugin;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PdisplayGraph0;
  private ATerm PselectNode0;
  private ATerm PshowPopup0;
  private ATerm PsizeGraph0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected GraphPainterTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected GraphPainterTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<graph-painter>,display-graph(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<graph-painter>,size-graph(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<graph-painter>,select-node(<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<graph-painter>,show-popup(<str>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<graph-painter>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<graph-painter>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdisplayGraph0 = factory.parse("rec-do(display-graph(<str>,<term>))");
    PselectNode0 = factory.parse("rec-do(select-node(<str>,<str>))");
    PshowPopup0 = factory.parse("rec-do(show-popup(<str>,<str>,<term>))");
    PsizeGraph0 = factory.parse("rec-eval(size-graph(<str>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PdisplayGraph0);
    if (result != null) {
      displayGraph((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PselectNode0);
    if (result != null) {
      selectNode((String)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PshowPopup0);
    if (result != null) {
      showPopup((String)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PsizeGraph0);
    if (result != null) {
      return sizeGraph((String)result.get(0), (ATerm)result.get(1));
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
