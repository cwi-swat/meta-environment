// Java tool interface class TestingTool
// This file is generated automatically, please do not edit!
// generation time: Jul 12, 2001 10:48:23 AM

package toolbus;

import aterm.*;
import toolbus.*;
import java.net.*;
import java.util.*;

abstract public class TestingTool
  extends AbstractTool
  implements TestingTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm Plisttest0;
  private ATerm Ptestit0;
  private ATerm Ptestit1;
  private ATerm Ptestit2;
  private ATerm Pquestion0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected TestingTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected TestingTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<testing>,testit(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<testing>,testit(<str>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<testing>,testit(<str>,f([<int>])))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<testing>,question(square))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<testing>,listtest(<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<testing>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<testing>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    Plisttest0 = factory.parse("rec-do(listtest(<term>))");
    Ptestit0 = factory.parse("rec-do(testit(<str>))");
    Ptestit1 = factory.parse("rec-do(testit(<str>,<term>))");
    Ptestit2 = factory.parse("rec-do(testit(<str>,<int>))");
    Pquestion0 = factory.parse("rec-eval(question(<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(Plisttest0);
    if (result != null) {
      listtest((ATerm)result.get(0));
      return null;
    }
    result = term.match(Ptestit0);
    if (result != null) {
      testit((String)result.get(0));
      return null;
    }
    result = term.match(Ptestit1);
    if (result != null) {
      testit((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(Ptestit2);
    if (result != null) {
      testit((String)result.get(0), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(Pquestion0);
    if (result != null) {
      return question((ATerm)result.get(0));
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
