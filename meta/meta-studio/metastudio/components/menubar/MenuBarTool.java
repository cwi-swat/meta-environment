// Java tool interface class MenuBarTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 2:06:21 PM

package metastudio.components.menubar;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class MenuBarTool
  extends SwingTool
  implements MenuBarTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PaddEvents0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected MenuBarTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected MenuBarTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<menu-bar>,add-events(<term>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<menu-bar>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<menu-bar>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PaddEvents0 = factory.parse("rec-do(add-events(<term>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PaddEvents0);
    if (result != null) {
      addEvents((ATerm)result.get(0), (ATerm)result.get(1));
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
