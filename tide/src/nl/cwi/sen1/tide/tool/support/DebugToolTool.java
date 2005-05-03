// Java tool interface class DebugToolTool
// This file is generated automatically, please do not edit!
// generation time: Jun 10, 2004 3:05:13 PM

package nl.cwi.sen1.tide.tool.support;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class DebugToolTool
  extends SwingTool
  implements DebugToolTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PprocessDestroyed0;
  private ATerm PadapterDisconnected0;
  private ATerm Pevent0;
  private ATerm PprocessCreated0;
  private ATerm PadapterConnected0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected DebugToolTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected DebugToolTool(ATermFactory factory)
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
    PprocessDestroyed0 = factory.parse("rec-do(process-destroyed(<term>))");
    PadapterDisconnected0 = factory.parse("rec-do(adapter-disconnected(<term>))");
    Pevent0 = factory.parse("rec-do(event(<term>,<int>,<term>))");
    PprocessCreated0 = factory.parse("rec-do(process-created(<term>,<str>))");
    PadapterConnected0 = factory.parse("rec-do(adapter-connected(<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PprocessDestroyed0);
    if (result != null) {
      processDestroyed((ATerm)result.get(0));
      return null;
    }
    result = term.match(PadapterDisconnected0);
    if (result != null) {
      adapterDisconnected((ATerm)result.get(0));
      return null;
    }
    result = term.match(Pevent0);
    if (result != null) {
      event((ATerm)result.get(0), ((Integer)result.get(1)).intValue(), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PprocessCreated0);
    if (result != null) {
      processCreated((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PadapterConnected0);
    if (result != null) {
      adapterConnected((ATerm)result.get(0));
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
