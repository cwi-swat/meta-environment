package argusviewer.view.msc.visual;

import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;
import prefuse.visual.sort.ItemSorter;

/**
 * Custom Prefuse ItemSorter which puts the swimlanes under the entities in the background.
 * 
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 *
 */
public class MSCItemSorter extends ItemSorter {

	protected static final int DECORATOR_SCORE = 1;
	protected static final int MESSAGE_SCORE = 2;
	protected static final int DEFAULT_SCORE = 3;
	
	/**
	 * Return a score for the VisualItem.
	 * The current order for Visual Items from low to high is:
	 * 
	 * 1. Decorator Items
	 * 2. Messages between processes and tools
	 * 3. Other Items
	 * 
	 * Items with a lower score will be drawn first, meaning items with higher scores will appear
	 * above the items with lower scores.
	 * 
	 * @param item The VisualItem for which the score will be calculated
	 * @return The score for the given VisualItem
	 * 
	 */
	public int score(VisualItem item) {
    	
    	if (item instanceof DecoratorItem) {
    		return DECORATOR_SCORE;
    	} else if (item.getRenderer() instanceof MessageRenderer) {
    		return MESSAGE_SCORE;
    	} else {
    		return DEFAULT_SCORE;
    	}
    }
}
