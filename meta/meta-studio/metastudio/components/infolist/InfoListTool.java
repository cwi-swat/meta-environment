// Java tool interface class InfoListTool
// This file is generated automatically, please do not edit!
// generation time: Nov 25, 2004 11:22:37 AM

package metastudio.components.infolist;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class InfoListTool
  extends SwingTool
  implements InfoListTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm Perrorf0;
  private ATerm Perror0;
  private ATerm Pwarningf0;
  private ATerm Pwarning0;
  private ATerm Pmessage0;
  private ATerm Pmessagef0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected InfoListTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected InfoListTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<info-list>,error(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<info-list>,errorf(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<info-list>,warning(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<info-list>,warningf(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<info-list>,message(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<info-list>,messagef(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<info-list>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    Perrorf0 = factory.parse("rec-do(errorf(<str>,<term>))");
    Perror0 = factory.parse("rec-do(error(<str>))");
    Pwarningf0 = factory.parse("rec-do(warningf(<str>,<term>))");
    Pwarning0 = factory.parse("rec-do(warning(<str>))");
    Pmessage0 = factory.parse("rec-do(message(<str>))");
    Pmessagef0 = factory.parse("rec-do(messagef(<str>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(Perrorf0);
    if (result != null) {
      errorf((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(Perror0);
    if (result != null) {
      error((String)result.get(0));
      return null;
    }
    result = term.match(Pwarningf0);
    if (result != null) {
      warningf((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(Pwarning0);
    if (result != null) {
      warning((String)result.get(0));
      return null;
    }
    result = term.match(Pmessage0);
    if (result != null) {
      message((String)result.get(0));
      return null;
    }
    result = term.match(Pmessagef0);
    if (result != null) {
      messagef((String)result.get(0), (ATerm)result.get(1));
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
