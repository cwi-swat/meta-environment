package argusviewer.view;

import java.awt.Container;
import java.util.Map;

/**
 * All views must implement this interface.
 * 
 * @author J. van den Bos
 * @author M. van Beest
 * 
 */
public interface IView {
	/**
	 * Returns the preferred position of the view's visual components.
	 * 
	 * @return A string representing the preferred position for the visual
	 *         components.
	 */
	String getPreferredPosition();

	/**
	 * The plugin manager will use this method to request the name and component
	 * of the view.
	 * 
	 * @return map with names for every component
	 */
	Map<String, Container> getVisualComponents();

}
