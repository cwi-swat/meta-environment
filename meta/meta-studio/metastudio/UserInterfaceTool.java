// Java tool interface class UserInterfaceTool
// This file is generated automatically, please do not edit!
// generation time: Jul 10, 2003 9:32:42 PM

package metastudio;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class UserInterfaceTool
  extends SwingTool
  implements UserInterfaceTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PaddStatus0;
  private ATerm PmoduleInfo0;
  private ATerm PaddStatusf0;
  private ATerm Perrorf0;
  private ATerm PgraphLayouted0;
  private ATerm PinitializeUi0;
  private ATerm PbuttonsFound0;
  private ATerm PclearHistory0;
  private ATerm PdeleteModules0;
  private ATerm Perror0;
  private ATerm PdisplayGraph0;
  private ATerm PnewGraph0;
  private ATerm PupdateList0;
  private ATerm PendStatus0;
  private ATerm PdeconsFilename0;
  private ATerm PshowQuestionDialog0;
  private ATerm PshowFileDialog0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected UserInterfaceTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected UserInterfaceTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<user-interface>,add-status(<term>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,add-statusf(<term>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,end-status(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,error(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,errorf(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,initialize-ui(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,display-graph(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,delete-modules(<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,module-info(<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,new-graph(<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,graph-layouted(<str>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,buttons-found(<term>,<str>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<user-interface>,show-file-dialog(<str>,<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<user-interface>,show-question-dialog(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<user-interface>,decons-filename(<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,clear-history)"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<user-interface>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<user-interface>,update-list(<str>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<user-interface>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PaddStatus0 = factory.parse("rec-do(add-status(<term>,<str>))");
    PmoduleInfo0 = factory.parse("rec-do(module-info(<str>,<term>))");
    PaddStatusf0 = factory.parse("rec-do(add-statusf(<term>,<str>,<term>))");
    Perrorf0 = factory.parse("rec-do(errorf(<str>,<term>))");
    PgraphLayouted0 = factory.parse("rec-do(graph-layouted(<str>,<term>))");
    PinitializeUi0 = factory.parse("rec-do(initialize-ui(<str>))");
    PbuttonsFound0 = factory.parse("rec-do(buttons-found(<term>,<str>,<term>))");
    PclearHistory0 = factory.parse("rec-do(clear-history)");
    PdeleteModules0 = factory.parse("rec-do(delete-modules(<term>))");
    Perror0 = factory.parse("rec-do(error(<str>))");
    PdisplayGraph0 = factory.parse("rec-do(display-graph(<str>,<term>))");
    PnewGraph0 = factory.parse("rec-do(new-graph(<term>))");
    PupdateList0 = factory.parse("rec-do(update-list(<str>,<str>))");
    PendStatus0 = factory.parse("rec-do(end-status(<term>))");
    PdeconsFilename0 = factory.parse("rec-eval(decons-filename(<str>,<str>))");
    PshowQuestionDialog0 = factory.parse("rec-eval(show-question-dialog(<str>))");
    PshowFileDialog0 = factory.parse("rec-eval(show-file-dialog(<str>,<str>,<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
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
    result = term.match(PmoduleInfo0);
    if (result != null) {
      moduleInfo((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PaddStatusf0);
    if (result != null) {
      addStatusf((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(Perrorf0);
    if (result != null) {
      errorf((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PgraphLayouted0);
    if (result != null) {
      graphLayouted((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PinitializeUi0);
    if (result != null) {
      initializeUi((String)result.get(0));
      return null;
    }
    result = term.match(PbuttonsFound0);
    if (result != null) {
      buttonsFound((ATerm)result.get(0), (String)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PclearHistory0);
    if (result != null) {
      clearHistory();
      return null;
    }
    result = term.match(PdeleteModules0);
    if (result != null) {
      deleteModules((ATerm)result.get(0));
      return null;
    }
    result = term.match(Perror0);
    if (result != null) {
      error((String)result.get(0));
      return null;
    }
    result = term.match(PdisplayGraph0);
    if (result != null) {
      displayGraph((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PnewGraph0);
    if (result != null) {
      newGraph((ATerm)result.get(0));
      return null;
    }
    result = term.match(PupdateList0);
    if (result != null) {
      updateList((String)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PendStatus0);
    if (result != null) {
      endStatus((ATerm)result.get(0));
      return null;
    }
    result = term.match(PdeconsFilename0);
    if (result != null) {
      return deconsFilename((String)result.get(0), (String)result.get(1));
    }
    result = term.match(PshowQuestionDialog0);
    if (result != null) {
      return showQuestionDialog((String)result.get(0));
    }
    result = term.match(PshowFileDialog0);
    if (result != null) {
      return showFileDialog((String)result.get(0), (String)result.get(1), (String)result.get(2));
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
