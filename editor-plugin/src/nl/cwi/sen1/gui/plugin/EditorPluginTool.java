// Java tool interface class EditorPluginTool
// This file is generated automatically, please do not edit!
// generation time: Feb 20, 2007 9:13:52 AM

package nl.cwi.sen1.gui.plugin;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

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
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PgetContents0;
  private ATerm PeditFile0;
  private ATerm PsetFocus0;
  private ATerm PisModified0;
  private ATerm PkillEditor0;
  private ATerm PdisplayMessage0;
  private ATerm PsetTooltip0;
  private ATerm PregisterTextCategories0;
  private ATerm PsetSelection0;
  private ATerm PwriteContents0;
  private ATerm PeditorToFront0;
  private ATerm PsetEditable0;
  private ATerm PsetContents0;
  private ATerm PhighlightSlices0;
  private ATerm PsetCursorAtOffset0;
  private ATerm PshowPopup0;
  private ATerm PaddActions0;
  private ATerm PsetInfo0;
  private ATerm PclearFocus0;
  private ATerm PrereadContents0;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected EditorPluginTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-do(<editor-plugin>,edit-file(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-tooltip(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-info(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-editable(<term>,<bool>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,add-actions(<term>,<list>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,get-contents(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-contents(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,write-contents(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,reread-contents(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,is-modified(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-focus(<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-selection(<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,set-cursor-at-offset(<term>,<int>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,clear-focus(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,register-text-categories(<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,highlight-slices(<term>,<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,display-message(<term>,<str>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,editor-to-front(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,kill-editor(<term>))"));
    sigTable.add(factory.parse("rec-do(<editor-plugin>,show-popup(<term>,<list>))"));
    sigTable.add(factory.parse("rec-ack-event(<editor-plugin>,<term>)"));
    sigTable.add(factory.parse("rec-terminate(<editor-plugin>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PgetContents0 = factory.parse("rec-do(get-contents(<term>))");
    PeditFile0 = factory.parse("rec-do(edit-file(<term>,<str>))");
    PsetFocus0 = factory.parse("rec-do(set-focus(<term>,<term>))");
    PisModified0 = factory.parse("rec-do(is-modified(<term>))");
    PkillEditor0 = factory.parse("rec-do(kill-editor(<term>))");
    PdisplayMessage0 = factory.parse("rec-do(display-message(<term>,<str>))");
    PsetTooltip0 = factory.parse("rec-do(set-tooltip(<term>,<str>))");
    PregisterTextCategories0 = factory.parse("rec-do(register-text-categories(<term>,<term>))");
    PsetSelection0 = factory.parse("rec-do(set-selection(<term>,<term>))");
    PwriteContents0 = factory.parse("rec-do(write-contents(<term>))");
    PeditorToFront0 = factory.parse("rec-do(editor-to-front(<term>))");
    PsetEditable0 = factory.parse("rec-do(set-editable(<term>,<term>))");
    PsetContents0 = factory.parse("rec-do(set-contents(<term>,<str>))");
    PhighlightSlices0 = factory.parse("rec-do(highlight-slices(<term>,<term>))");
    PsetCursorAtOffset0 = factory.parse("rec-do(set-cursor-at-offset(<term>,<int>))");
    PshowPopup0 = factory.parse("rec-do(show-popup(<term>,<term>))");
    PaddActions0 = factory.parse("rec-do(add-actions(<term>,<term>))");
    PsetInfo0 = factory.parse("rec-do(set-info(<term>,<str>))");
    PclearFocus0 = factory.parse("rec-do(clear-focus(<term>))");
    PrereadContents0 = factory.parse("rec-do(reread-contents(<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PgetContents0);
    if (result != null) {
      getContents((ATerm)result.get(0));
      return null;
    }
    result = term.match(PeditFile0);
    if (result != null) {
      editFile((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PsetFocus0);
    if (result != null) {
      setFocus((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PisModified0);
    if (result != null) {
      isModified((ATerm)result.get(0));
      return null;
    }
    result = term.match(PkillEditor0);
    if (result != null) {
      killEditor((ATerm)result.get(0));
      return null;
    }
    result = term.match(PdisplayMessage0);
    if (result != null) {
      displayMessage((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PsetTooltip0);
    if (result != null) {
      setTooltip((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PregisterTextCategories0);
    if (result != null) {
      registerTextCategories((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PsetSelection0);
    if (result != null) {
      setSelection((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PwriteContents0);
    if (result != null) {
      writeContents((ATerm)result.get(0));
      return null;
    }
    result = term.match(PeditorToFront0);
    if (result != null) {
      editorToFront((ATerm)result.get(0));
      return null;
    }
    result = term.match(PsetEditable0);
    if (result != null) {
      setEditable((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PsetContents0);
    if (result != null) {
      setContents((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PhighlightSlices0);
    if (result != null) {
      highlightSlices((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PsetCursorAtOffset0);
    if (result != null) {
      setCursorAtOffset((ATerm)result.get(0), ((Integer)result.get(1)).intValue());
      return null;
    }
    result = term.match(PshowPopup0);
    if (result != null) {
      showPopup((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PaddActions0);
    if (result != null) {
      addActions((ATerm)result.get(0), (ATerm)result.get(1));
      return null;
    }
    result = term.match(PsetInfo0);
    if (result != null) {
      setInfo((ATerm)result.get(0), (String)result.get(1));
      return null;
    }
    result = term.match(PclearFocus0);
    if (result != null) {
      clearFocus((ATerm)result.get(0));
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

  // Check the input signature
  public void checkInputSignature(ATermList sigs)
  {
    while(!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl)sigs.getFirst();
      sigs = sigs.getNext();
      if (!sigTable.contains(sig)) {
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
