// Java tool interface class GraphNodeSizerTool
// This file is generated automatically, please do not edit!
// generation time: Nov 26, 2004 9:13:16 AM

package metastudio.components.graphnodesizer;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class GraphNodeSizerTool
  extends SwingTool
  implements GraphNodeSizerTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PsizeGraph0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected GraphNodeSizerTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected GraphNodeSizerTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-eval(<graph-node-sizer>,size-graph(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<graph-node-sizer>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PsizeGraph0 = factory.parse("rec-eval(size-graph(<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PsizeGraph0);
    if (result != null) {
      return sizeGraph((ATerm)result.get(0));
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
