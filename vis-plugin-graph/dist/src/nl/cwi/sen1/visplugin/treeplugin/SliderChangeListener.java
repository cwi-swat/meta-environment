package nl.cwi.sen1.visplugin.treeplugin;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;


/**
 * handles the change events of the slider 
 * @author Qais
 *
 */
public class SliderChangeListener implements ChangeListener {
	static int m_padding;
	TreeVisualization m_treeVisualization;
	
	
	/**
	 * @param tree the tree
	 * @param padding the space between a node and its parent
	 */
	public SliderChangeListener(TreeVisualization tree) {
		m_treeVisualization = tree;
	}

	/* (non-Javadoc)
	 * @see javax.swing.event.ChangeListener#stateChanged(javax.swing.event.ChangeEvent)
	 */
	public void stateChanged(ChangeEvent e) {
        JSlider source = (JSlider)e.getSource();
        if (!source.getValueIsAdjusting()) {
        	int level = source.getValue();
        	m_treeVisualization.setViewHierarchyLevel(level);
        }
	}
	
	
}