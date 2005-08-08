// Java tool interface class TideControlTool
// This file is generated automatically, please do not edit!
// generation time: Oct 18, 2004 7:30:51 PM

package nl.cwi.sen1.tide;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class TideControlTool
  extends SwingTool
  implements TideControlTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected TideControlTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected TideControlTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-terminate(<tide-control>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<debug-tool>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<debug-tool>,adapter-connected(<debug-adapter>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<debug-tool>,adapter-disconnected(<debug-adapter>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<debug-tool>,process-created(<proc(<debug-adapter>,<int>)>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<debug-tool>,process-destroyed(<proc(<debug-adapter>,<int>)>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<debug-tool>,event(<proc(<debug-adapter>,<int>)>,<int>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<debug-tool>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,evaluate(<int>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,create-rule(<int>,<term>,<term>,<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,enable-rule(<int>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,disable-rule(<int>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,modify-rule(<int>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<debug-adapter>,delete-rule(<int>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<debug-adapter>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<debug-adapter>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

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
