// Java tool interface class StatusBarTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 10:08:49 AM

package metastudio.components.statusbar;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class StatusBarTool
  extends SwingTool
  implements StatusBarTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PaddStatus0;
  private ATerm PaddStatusf0;
  private ATerm PendStatus0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected StatusBarTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected StatusBarTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<status-bar>,add-status(<term>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<status-bar>,add-statusf(<term>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<status-bar>,end-status(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<status-bar>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PaddStatus0 = factory.parse("rec-do(add-status(<term>,<str>))");
    PaddStatusf0 = factory.parse("rec-do(add-statusf(<term>,<str>,<term>))");
    PendStatus0 = factory.parse("rec-do(end-status(<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PaddStatus0);
    if (result != null) {
      addStatus((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PaddStatusf0);
    if (result != null) {
      addStatusf((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PendStatus0);
    if (result != null) {
      endStatus((ATerm)result.get(0));
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
