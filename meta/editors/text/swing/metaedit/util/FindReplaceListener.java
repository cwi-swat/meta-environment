package nl.cwi.editor.util;

import java.util.EventListener;

/**
 * Interface for implementing a listener for <code>FindReplaceEvents</code>.
 *
 * <p>For implementing this interface, methods getFirstDocument and
 * getNextDocument need to be overridden by code providing a new document
 * for the a FindReplaceDialog. Once a new document is on hand,
 * methods resumeOperation or terminateOperation of the FindReplaceDialog
 * need to be called from out of this interfaces methods to resume or
 * terminate the find or replace operation,
 * which is waiting for the new document in the FindReplaceDialog.</p>
 *
 * @author Ulrich Hilger
 * @author CalCom
 * @author <a href="http://www.calcom.de">http://www.calcom.de</a>
 * @author <a href="mailto:info@calcom.de">info@calcom.de</a>
 *
 * @version 1.1, April 13, 2002
 */

public interface FindReplaceListener extends EventListener {

  /**
   * this events gets fired, when a FindReplaceDialog has reached
   * the end of the current document and requires the next document
   * of a group of documents.
   *
   * @param  e  the object having details for the event
   */
  public void getNextDocument(FindReplaceEvent e);

  /**
   * this events gets fired, when a FindReplaceDialog has initiated
   * an operation for a group of documents which requires to start at
   * the first document.
   *
   * @param  e  the object having details for the event
   */
  public void getFirstDocument(FindReplaceEvent e);

}
