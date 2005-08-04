// Java tool interface class EditorPluginTool
// This file is generated automatically, please do not edit!
// generation time: Jun 13, 2005 12:50:25 PM

package nl.cwi.sen1.gui.plugin;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import toolbus.SwingTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class EditorPluginTool
  extends SwingTool
  implements EditorPluginTif
{
  // This table will hold the complete input signature
  private Map sigTable = new HashMap();

  //{{{  Patterns that are used to match against incoming terms

  private ATerm PisModified0;
  private ATerm PwriteContents0;
  private ATerm PsetFocus0;
  private ATerm PregisterTextCategories0;
  private ATerm PaddActions0;
  private ATerm PclearFocus0;
  private ATerm PdisplayMessage0;
  private ATerm PkillEditor0;
  private ATerm PsetCursorAtOffset0;
  private ATerm PeditFile0;
  private ATerm PhighlightSlices0;
  private ATerm PeditorToFront0;
  private ATerm PrereadContents0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  //}}}

  //{{{  protected EditorPluginTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected EditorPluginTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<editor-plugin>,edit-file(<term>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,add-actions(<term>,<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,write-contents(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,reread-contents(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,is-modified(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,set-focus(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,set-cursor-at-offset(<term>,<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,clear-focus(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,register-text-categories(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,highlight-slices(<term>,<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,display-message(<term>,<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,editor-to-front(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<editor-plugin>,kill-editor(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<editor-plugin>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<editor-plugin>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PisModified0 = factory.parse("rec-do(is-modified(<term>))");
    PwriteContents0 = factory.parse("rec-do(write-contents(<term>))");
    PsetFocus0 = factory.parse("rec-do(set-focus(<term>,<term>))");
    PregisterTextCategories0 = factory.parse("rec-do(register-text-categories(<term>,<term>))");
    PaddActions0 = factory.parse("rec-do(add-actions(<term>,<term>))");
    PclearFocus0 = factory.parse("rec-do(clear-focus(<term>))");
    PdisplayMessage0 = factory.parse("rec-do(display-message(<term>,<str>))");
    PkillEditor0 = factory.parse("rec-do(kill-editor(<term>))");
    PsetCursorAtOffset0 = factory.parse("rec-do(set-cursor-at-offset(<term>,<int>))");
    PeditFile0 = factory.parse("rec-do(edit-file(<term>,<str>))");
    PhighlightSlices0 = factory.parse("rec-do(highlight-slices(<term>,<term>))");
    PeditorToFront0 = factory.parse("rec-do(editor-to-front(<term>))");
    PrereadContents0 = factory.parse("rec-do(reread-contents(<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  //}}}

  //{{{  public ATerm handler(ATerm term)

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List result;

    result = term.match(PisModified0);
    if (result != null) {
      isModified((ATerm)result.get(0));
      return null;
    }
    result = term.match(PwriteContents0);
    if (result != null) {
      writeContents((ATerm)result.get(0));
      return null;
    }
    result = term.match(PsetFocus0);
    if (result != null) {
      setFocus((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PregisterTextCategories0);
    if (result != null) {
      registerTextCategories((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PaddActions0);
    if (result != null) {
      addActions((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PclearFocus0);
    if (result != null) {
      clearFocus((ATerm)result.get(0));
      return null;
    }
    result = term.match(PdisplayMessage0);
    if (result != null) {
      displayMessage((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PkillEditor0);
    if (result != null) {
      killEditor((ATerm)result.get(0));
      return null;
    }
    result = term.match(PsetCursorAtOffset0);
    if (result != null) {
      setCursorAtOffset((ATerm)result.get(0), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(PeditFile0);
    if (result != null) {
      editFile((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PhighlightSlices0);
    if (result != null) {
      highlightSlices((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PeditorToFront0);
    if (result != null) {
      editorToFront((ATerm)result.get(0));
      return null;
    }
    result = term.match(PrereadContents0);
    if (result != null) {
      rereadContents((ATerm)result.get(0));
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
