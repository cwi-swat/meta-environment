package nl.cwi.sen1.visplugin.treemap;
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
	TreeMapVisualization m_treemap;
	
	
	/**
	 * @param treemap the treemap
	 * @param padding the space between a node and its parent
	 */
	public SliderChangeListener(TreeMapVisualization treemap, int padding) {
		m_treemap = treemap;
		m_padding = padding;
	}

	/* (non-Javadoc)
	 * @see javax.swing.event.ChangeListener#stateChanged(javax.swing.event.ChangeEvent)
	 */
	public void stateChanged(ChangeEvent e) {
        JSlider source = (JSlider)e.getSource();
        if (!source.getValueIsAdjusting()) {
        	m_padding = source.getValue();
        	m_treemap.updatePadding(m_padding);
        }
	}
	
	
}
