package argusviewer.view.listeners;

/**
 * Listener for ProcessInstance related control notifications.
 * 
 * @author J. van den Bos
 * @author T. Van Laer
 */
public interface IStateControlListener{
	/**
	 * The state of the debugToolbus has changed.
	 * 
	 * @param state
	 *            the current state of the debugToolbus.
	 */
	void setState(int state);
}
