// Java tool interface class ModuleManagerTool
// This file is generated automatically, please do not edit!
// generation time: Sep 19, 2005 3:27:52 PM

package nl.cwi.sen1.modulemanager;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class ModuleManagerTool
  extends SwingTool
  implements ModuleManagerTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PdeleteDependencies0;
  private ATerm PaddDependency0;
  private ATerm PdeleteModule0;
  private ATerm PdeleteAttribute0;
  private ATerm PdeleteDependency0;
  private ATerm PaddAttribute0;
  private ATerm PcreateModule0;
  private ATerm PgetDependencies0;
  private ATerm PgetAttribute0;
  private ATerm PgetModuleAttributeMap0;
  private ATerm PgetModuleIdByAttribute0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected ModuleManagerTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected ModuleManagerTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-module-id-by-attribute(<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,create-module)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-module(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,add-attribute(<term>,<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-attribute(<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-module-attribute-map(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-attribute(<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,add-dependency(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-dependency(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-dependencies(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-dependencies)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<module-manager>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdeleteDependencies0 = factory.parse("rec-do(delete-dependencies(<term>))");
    PaddDependency0 = factory.parse("rec-do(add-dependency(<term>,<term>))");
    PdeleteModule0 = factory.parse("rec-do(delete-module(<term>))");
    PdeleteAttribute0 = factory.parse("rec-do(delete-attribute(<term>,<term>,<term>))");
    PdeleteDependency0 = factory.parse("rec-do(delete-dependency(<term>,<term>))");
    PaddAttribute0 = factory.parse("rec-do(add-attribute(<term>,<term>,<term>,<term>))");
    PcreateModule0 = factory.parse("rec-eval(create-module)");
    PgetDependencies0 = factory.parse("rec-eval(get-dependencies)");
    PgetAttribute0 = factory.parse("rec-eval(get-attribute(<term>,<term>,<term>))");
    PgetModuleAttributeMap0 = factory.parse("rec-eval(get-module-attribute-map(<term>,<term>))");
    PgetModuleIdByAttribute0 = factory.parse("rec-eval(get-module-id-by-attribute(<term>,<term>,<term>))");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PdeleteDependencies0);
    if (result != null) {
      deleteDependencies((ATerm)result.get(0));
      return null;
    }
    result = term.match(PaddDependency0);
    if (result != null) {
      addDependency((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PdeleteModule0);
    if (result != null) {
      deleteModule((ATerm)result.get(0));
      return null;
    }
    result = term.match(PdeleteAttribute0);
    if (result != null) {
      deleteAttribute((ATerm)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PdeleteDependency0);
    if (result != null) {
      deleteDependency((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PaddAttribute0);
    if (result != null) {
      addAttribute((ATerm)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3));
      return null;
    }
    result = term.match(PcreateModule0);
    if (result != null) {
      return createModule();
    }
    result = term.match(PgetDependencies0);
    if (result != null) {
      return getDependencies();
    }
    result = term.match(PgetAttribute0);
    if (result != null) {
      return getAttribute((ATerm)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
    }
    result = term.match(PgetModuleAttributeMap0);
    if (result != null) {
      return getModuleAttributeMap((ATerm)result.get(0), (ATerm)result.get(1));
    }
    result = term.match(PgetModuleIdByAttribute0);
    if (result != null) {
      return getModuleIdByAttribute((ATerm)result.get(0), (ATerm)result.get(1), (ATerm)result.get(2));
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
