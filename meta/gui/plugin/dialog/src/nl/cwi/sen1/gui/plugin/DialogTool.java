// Java tool interface class DialogTool
// This file is generated automatically, please do not edit!
// generation time: May 9, 2005 1:31:59 PM

package nl.cwi.sen1.gui.plugin;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class DialogTool
  extends SwingTool
  implements DialogTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PshowProgressMessage0;
  private ATerm PshowProgressList0;
  private ATerm PshowProgressMessageWithArguments0;
  private ATerm PcloseProgressList0;
  private ATerm PshowFileDialog0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected DialogTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected DialogTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-eval(<dialog>,show-file-dialog(<str>,<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-list(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-message(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<dialog>,show-progress-message-with-arguments(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<dialog>,close-progress-list)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<dialog>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PshowProgressMessage0 = factory.parse("rec-do(show-progress-message(<str>))");
    PshowProgressList0 = factory.parse("rec-do(show-progress-list(<str>))");
    PshowProgressMessageWithArguments0 = factory.parse("rec-do(show-progress-message-with-arguments(<str>,<term>))");
    PcloseProgressList0 = factory.parse("rec-do(close-progress-list)");
    PshowFileDialog0 = factory.parse("rec-eval(show-file-dialog(<str>,<str>,<str>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PshowProgressMessage0);
    if (result != null) {
      showProgressMessage((String)result.get(0));
      return null;
    }
    result = term.match(PshowProgressList0);
    if (result != null) {
      showProgressList((String)result.get(0));
      return null;
    }
    result = term.match(PshowProgressMessageWithArguments0);
    if (result != null) {
      showProgressMessageWithArguments((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PcloseProgressList0);
    if (result != null) {
      closeProgressList();
      return null;
    }
    result = term.match(PshowFileDialog0);
    if (result != null) {
      return showFileDialog((String)result.get(0), (String)result.get(1), (String)result.get(2));
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
