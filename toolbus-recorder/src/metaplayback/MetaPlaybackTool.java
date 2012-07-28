package metaplayback;
// Java tool interface class LoggerTool
// This file is generated automatically, please do not edit!
// generation time: Apr 12, 2005 3:16:09 PM


import aterm.*;
import java.util.*;
import toolbus.*;

abstract public class MetaPlaybackTool
  extends AbstractTool
  implements MetaPlaybackTif
{
	private final static int LENSPEC = 12;
	private final static int MAX_HANDSHAKE = 512;
	private final static int MIN_MSG_SIZE = 128;
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PrecMonitor0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected LoggerTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected MetaPlaybackTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-terminate(<logger>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-monitor(<logger>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PrecMonitor0 = factory.parse("rec-monitor(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
   List result;

    result = term.match(PrecMonitor0);
    if (result != null) {
      return recMonitor((ATerm)result.get(0));
      //return null;

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
