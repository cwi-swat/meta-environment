// Java tool interface class NavigatorTool
// This file is generated automatically, please do not edit!
// generation time: Apr 22, 2005 1:03:35 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class NavigatorTool
  extends SwingTool
  implements NavigatorTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PselectModule0;
  private ATerm PsetModules0;
  private ATerm PshowPopup0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected NavigatorTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected NavigatorTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<navigator>,set-modules(<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<navigator>,select-module(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<navigator>,show-popup(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<navigator>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<navigator>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PselectModule0 = factory.parse("rec-do(select-module(<str>))");
    PsetModules0 = factory.parse("rec-do(set-modules(<term>))");
    PshowPopup0 = factory.parse("rec-do(show-popup(<str>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PselectModule0);
    if (result != null) {
      selectModule((String)result.get(0));
      return null;
    }
    result = term.match(PsetModules0);
    if (result != null) {
      setModules((ATerm)result.get(0));
      return null;
    }
    result = term.match(PshowPopup0);
    if (result != null) {
      showPopup((String)result.get(0), (ATerm)result.get(1));
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
