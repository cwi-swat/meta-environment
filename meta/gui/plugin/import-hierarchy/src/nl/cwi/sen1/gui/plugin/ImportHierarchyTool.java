// Java tool interface class ImportHierarchyTool
// This file is generated automatically, please do not edit!
// generation time: Apr 19, 2005 3:01:35 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class ImportHierarchyTool
  extends SwingTool
  implements ImportHierarchyTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PsetHierarchy0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected ImportHierarchyTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected ImportHierarchyTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<import-hierarchy>,set-hierarchy(<str>,<list>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<import-hierarchy>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<import-hierarchy>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PsetHierarchy0 = factory.parse("rec-do(set-hierarchy(<str>,<term>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PsetHierarchy0);
    if (result != null) {
      setHierarchy((String)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
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
