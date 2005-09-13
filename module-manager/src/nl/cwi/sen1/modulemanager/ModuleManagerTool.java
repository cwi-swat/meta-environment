// Java tool interface class ModuleManagerTool
// This file is generated automatically, please do not edit!
// generation time: Sep 13, 2005 12:00:34 PM

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
  private ATerm PgetDependenciesByAttribute0;
  private ATerm PcreateModule0;
  private ATerm PcreateModule1;
  private ATerm PgetAttribute0;
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
    sigTable.put(factory.parse("rec-eval(<module-manager>,create-module(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-module(<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,add-attribute(<int>,<term>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-attribute(<int>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-attribute(<int>,<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,add-dependency(<int>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-dependency(<int>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<module-manager>,delete-dependencies(<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-eval(<module-manager>,get-dependencies-by-attribute(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<module-manager>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PdeleteDependencies0 = factory.parse("rec-do(delete-dependencies(<int>))");
    PaddDependency0 = factory.parse("rec-do(add-dependency(<int>,<int>))");
    PdeleteModule0 = factory.parse("rec-do(delete-module(<int>))");
    PdeleteAttribute0 = factory.parse("rec-do(delete-attribute(<int>,<term>,<term>))");
    PdeleteDependency0 = factory.parse("rec-do(delete-dependency(<int>,<int>))");
    PaddAttribute0 = factory.parse("rec-do(add-attribute(<int>,<term>,<term>,<term>))");
    PgetDependenciesByAttribute0 = factory.parse("rec-eval(get-dependencies-by-attribute(<term>,<term>))");
    PcreateModule0 = factory.parse("rec-eval(create-module)");
    PcreateModule1 = factory.parse("rec-eval(create-module(<term>))");
    PgetAttribute0 = factory.parse("rec-eval(get-attribute(<int>,<term>,<term>))");
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
      deleteDependencies(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PaddDependency0);
    if (result != null) {
      addDependency(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(PdeleteModule0);
    if (result != null) {
      deleteModule(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PdeleteAttribute0);
    if (result != null) {
      deleteAttribute(((Integer)result.get(0)).intValue(), (ATerm)result.get(1), (ATerm)result.get(2));
      return null;
    }
    result = term.match(PdeleteDependency0);
    if (result != null) {
      deleteDependency(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(PaddAttribute0);
    if (result != null) {
      addAttribute(((Integer)result.get(0)).intValue(), (ATerm)result.get(1), (ATerm)result.get(2), (ATerm)result.get(3));
      return null;
    }
    result = term.match(PgetDependenciesByAttribute0);
    if (result != null) {
      return getDependenciesByAttribute((ATerm)result.get(0), (ATerm)result.get(1));
    }
    result = term.match(PcreateModule0);
    if (result != null) {
      return createModule();
    }
    result = term.match(PcreateModule1);
    if (result != null) {
      return createModule((ATerm)result.get(0));
    }
    result = term.match(PgetAttribute0);
    if (result != null) {
      return getAttribute(((Integer)result.get(0)).intValue(), (ATerm)result.get(1), (ATerm)result.get(2));
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
