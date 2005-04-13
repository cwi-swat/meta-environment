// Java tool interface class GuiTool
// This file is generated automatically, please do not edit!
// generation time: Apr 13, 2005 10:12:21 AM

package nl.cwi.sen1.studio;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class GuiTool
  extends SwingTool
  implements GuiTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PloadJar0;
  private ATerm PloadClass0;
  private ATerm PsetTitle0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected GuiTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected GuiTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<gui>,set-title(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<gui>,load-jar(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<gui>,load-class(<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<gui>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PloadJar0 = factory.parse("rec-do(load-jar(<str>))");
    PloadClass0 = factory.parse("rec-do(load-class(<str>,<str>))");
    PsetTitle0 = factory.parse("rec-do(set-title(<str>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PloadJar0);
    if (result != null) {
      loadJar((String)result.get(0));
      return null;
    }
    result = term.match(PloadClass0);
    if (result != null) {
      loadClass((String)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PsetTitle0);
    if (result != null) {
      setTitle((String)result.get(0));
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
