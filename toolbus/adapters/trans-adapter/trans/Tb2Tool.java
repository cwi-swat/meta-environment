// Java tool interface class Tb2Tool
// This file is generated automatically, please do not edit!
// generation time: Jun 26, 2003 4:12:04 PM


package trans;
import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class Tb2Tool
  extends AbstractTool
  implements Tb2Tif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm Pcount20;
  private ATerm Pcount10;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected Tb2Tool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected Tb2Tool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<tb2>,count1(<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<tb2>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<tb2>,count2(<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<tb2>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    Pcount20 = factory.parse("rec-do(count2(<int>))");
    Pcount10 = factory.parse("rec-do(count1(<int>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(Pcount20);
    if (result != null) {
      count2(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(Pcount10);
    if (result != null) {
      count1(((Integer)result.get(0)).intValue());
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
