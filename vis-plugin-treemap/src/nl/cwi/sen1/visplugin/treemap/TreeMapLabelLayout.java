package nl.cwi.sen1.visplugin.treemap;
import java.awt.geom.Rectangle2D;
import java.util.Iterator;
import prefuse.action.layout.Layout;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;


  /**
   * Set label positions. Labels are assumed to be DecoratorItem instances,
   * decorating their respective nodes. The layout simply gets the bounds
   * of the decorated node and assigns the label coordinates to the center
   * of those bounds.
   * @author Qais
   */

	public class TreeMapLabelLayout extends Layout {
		private double m_HorizontalSpacing = 0;
		private double m_VerticalSpacing = 0;
      
	/**
  	 * @param group group to add labels too
  	 * @param horizontalSpacing horizontal padding of the label 
   	 * @param verticalSpacing vertical padding of the label
   	 */
   	public TreeMapLabelLayout(String group, double horizontalSpacing, double verticalSpacing) {
   		super(group);
        m_HorizontalSpacing = horizontalSpacing;
        m_VerticalSpacing = verticalSpacing;
    }
   	
    /* (non-Javadoc)
     * @see prefuse.action.GroupAction#run(double)
     */
    @SuppressWarnings("unchecked")
	public void run(double frac) {
    	Iterator<DecoratorItem> iter = m_vis.items(m_group);
    	while ( iter.hasNext() ) {
    		DecoratorItem item = (DecoratorItem)iter.next();
    		VisualItem node = item.getDecoratedItem();
    		Rectangle2D bounds = node.getBounds();
    		setX(item, null, bounds.getCenterX()+ m_HorizontalSpacing);
    		setY(item, null, bounds.getY()+ m_VerticalSpacing);   
            }
        }
    } // end of inner class LabelLayout