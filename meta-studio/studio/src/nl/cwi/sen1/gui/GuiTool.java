// Java tool interface class GuiTool
// This file is generated automatically, please do not edit!
// generation time: Mar 29, 2006 1:02:23 PM

package nl.cwi.sen1.gui;

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
  private Map<ATerm, Boolean> sigTable = new HashMap<ATerm, Boolean>();

  // Patterns that are used to match against incoming terms
  private ATerm PloadJarUrls0;
  private ATerm PloadJar0;
  private ATerm PaddMenuEvents0;
  private ATerm PloadJarClasspath0;
  private ATerm PjobDone0;
  private ATerm PaddJob0;
  private ATerm PsetStatus0;
  private ATerm PsetTitle0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected GuiTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    Boolean btrue = new Boolean(true);
    sigTable.put(factory.parse("rec-do(<gui>,set-title(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,load-jar(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,load-jar-classpath(<str>,<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,load-jar-urls(<str>,<list>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,set-status(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,add-job(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,job-done(<str>))"), btrue);
    sigTable.put(factory.parse("rec-do(<gui>,add-menu-events(<list>))"), btrue);
    sigTable.put(factory.parse("rec-ack-event(<gui>,<term>)"), btrue);
    sigTable.put(factory.parse("rec-terminate(<gui>,<term>)"), btrue);
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PloadJarUrls0 = factory.parse("rec-do(load-jar-urls(<str>,<term>))");
    PloadJar0 = factory.parse("rec-do(load-jar(<str>))");
    PaddMenuEvents0 = factory.parse("rec-do(add-menu-events(<term>))");
    PloadJarClasspath0 = factory.parse("rec-do(load-jar-classpath(<str>,<str>))");
    PjobDone0 = factory.parse("rec-do(job-done(<str>))");
    PaddJob0 = factory.parse("rec-do(add-job(<str>))");
    PsetStatus0 = factory.parse("rec-do(set-status(<str>))");
    PsetTitle0 = factory.parse("rec-do(set-title(<str>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PloadJarUrls0);
    if (result != null) {
      loadJarUrls((String)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PloadJar0);
    if (result != null) {
      loadJar((String)result.get(0));
      return null;
    }
    result = term.match(PaddMenuEvents0);
    if (result != null) {
      addMenuEvents((ATerm)result.get(0));
      return null;
    }
    result = term.match(PloadJarClasspath0);
    if (result != null) {
      loadJarClasspath((String)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PjobDone0);
    if (result != null) {
      jobDone((String)result.get(0));
      return null;
    }
    result = term.match(PaddJob0);
    if (result != null) {
      addJob((String)result.get(0));
      return null;
    }
    result = term.match(PsetStatus0);
    if (result != null) {
      setStatus((String)result.get(0));
      return null;
    }
    result = term.match(PsetTitle0);
    if (result != null) {
      setTitle((String)result.get(0));
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

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATerm t)
  {
    throw new RuntimeException("term not in input signature: " + t);
  }
}
