// Java tool interface class SwingEditorTool
// This file is generated automatically, please do not edit!
// generation time: Jan 4, 2005 10:48:01 AM

package metaedit.toolbus;

import aterm.*;
import toolbus.*;
import java.util.*;

abstract public class SwingEditorTool
  extends SwingTool
  implements SwingEditorTif
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

  //{{{  protected SwingEditorTool(ATermFactory factory)

  // Mimic the constructor from the AbstractTool class
  protected SwingEditorTool(ATermFactory factory)
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
    sigTable.put(factory.parse("rec-do(<swing-editor>,edit-file(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,add-actions(<list>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,write-contents)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,reread-contents)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,is-modified)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,set-focus(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,set-cursor-at-offset(<int>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,clear-focus)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,register-text-categories(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,highlight-slices(<term>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,display-message(<str>))"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,editor-to-front)"), new Boolean(true));
    sigTable.put(factory.parse("rec-do(<swing-editor>,kill-editor)"), new Boolean(true));
    sigTable.put(factory.parse("rec-ack-event(<swing-editor>,<term>)"), new Boolean(true));
    sigTable.put(factory.parse("rec-terminate(<swing-editor>,<term>)"), new Boolean(true));
  }

  //}}}
  //{{{  private void initPatterns()

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PisModified0 = factory.parse("rec-do(is-modified)");
    PwriteContents0 = factory.parse("rec-do(write-contents)");
    PsetFocus0 = factory.parse("rec-do(set-focus(<term>))");
    PregisterTextCategories0 = factory.parse("rec-do(register-text-categories(<term>))");
    PaddActions0 = factory.parse("rec-do(add-actions(<term>))");
    PclearFocus0 = factory.parse("rec-do(clear-focus)");
    PdisplayMessage0 = factory.parse("rec-do(display-message(<str>))");
    PkillEditor0 = factory.parse("rec-do(kill-editor)");
    PsetCursorAtOffset0 = factory.parse("rec-do(set-cursor-at-offset(<int>))");
    PeditFile0 = factory.parse("rec-do(edit-file(<str>))");
    PhighlightSlices0 = factory.parse("rec-do(highlight-slices(<term>))");
    PeditorToFront0 = factory.parse("rec-do(editor-to-front)");
    PrereadContents0 = factory.parse("rec-do(reread-contents)");
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
      isModified();
      return null;
    }
    result = term.match(PwriteContents0);
    if (result != null) {
      writeContents();
      return null;
    }
    result = term.match(PsetFocus0);
    if (result != null) {
      setFocus((ATerm)result.get(0));
      return null;
    }
    result = term.match(PregisterTextCategories0);
    if (result != null) {
      registerTextCategories((ATerm)result.get(0));
      return null;
    }
    result = term.match(PaddActions0);
    if (result != null) {
      addActions((ATerm)result.get(0));
      return null;
    }
    result = term.match(PclearFocus0);
    if (result != null) {
      clearFocus();
      return null;
    }
    result = term.match(PdisplayMessage0);
    if (result != null) {
      displayMessage((String)result.get(0));
      return null;
    }
    result = term.match(PkillEditor0);
    if (result != null) {
      killEditor();
      return null;
    }
    result = term.match(PsetCursorAtOffset0);
    if (result != null) {
      setCursorAtOffset(((Integer)result.get(0)).intValue());
      return null;
    }
    result = term.match(PeditFile0);
    if (result != null) {
      editFile((String)result.get(0));
      return null;
    }
    result = term.match(PhighlightSlices0);
    if (result != null) {
      highlightSlices((ATerm)result.get(0));
      return null;
    }
    result = term.match(PeditorToFront0);
    if (result != null) {
      editorToFront();
      return null;
    }
    result = term.match(PrereadContents0);
    if (result != null) {
      rereadContents();
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
