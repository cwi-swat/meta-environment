// Java tool interface class UserInterfaceTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 1:32:06 PM

package metastudio;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class UserInterfaceTool
  extends SwingTool
  implements UserInterfaceTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PdisplayGraph0;
  private ATerm PaddEvents0;
  private ATerm PaddEvents1;
  private ATerm PrenderGraph0;
  private ATerm PinitializeUi0;
  private ATerm PclearHistory0;
  private ATerm PdisplayTreelist0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected UserInterfaceTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected UserInterfaceTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<user-interface>,initialize-ui(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,display-graph(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,display-treelist(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,render-graph(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,add-events(<term>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,add-events(<term>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,clear-history)"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<user-interface>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<user-interface>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdisplayGraph0 = factory.parse("rec-do(display-graph(<str>,<term>))");
    PaddEvents0 = factory.parse("rec-do(add-events(<term>,<str>,<term>))");
    PaddEvents1 = factory.parse("rec-do(add-events(<term>,<term>))");
    PrenderGraph0 = factory.parse("rec-do(render-graph(<str>,<term>))");
    PinitializeUi0 = factory.parse("rec-do(initialize-ui(<str>))");
    PclearHistory0 = factory.parse("rec-do(clear-history)");
    PdisplayTreelist0 = factory.parse("rec-do(display-treelist(<str>,<term>))");
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
    result = term.match(PaddEvents0);
    if (result != null) {
      addEvents((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PaddEvents1);
    if (result != null) {
      addEvents((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PrenderGraph0);
    if (result != null) {
      renderGraph((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PinitializeUi0);
    if (result != null) {
      initializeUi((String)result.get(0));
      return null;
    }
    result = term.match(PclearHistory0);
    if (result != null) {
      clearHistory();
      return null;
    }
    result = term.match(PdisplayTreelist0);
    if (result != null) {
      displayTreelist((String)result.get(0), (ATerm)result.get(1));
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
