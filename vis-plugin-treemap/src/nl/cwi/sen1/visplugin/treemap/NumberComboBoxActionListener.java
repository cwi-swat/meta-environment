package nl.cwi.sen1.visplugin.treemap;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 * handles the events of the number combo box
 * @author Qais
 *
 */
public class NumberComboBoxActionListener implements ActionListener{
	private static TreeMapVisualization m_treemap;
	
	/**
	 * @param treemap the treemap visualization
	 */
	public NumberComboBoxActionListener( TreeMapVisualization treemap){
		m_treemap = treemap;
	}
	
    /* (non-Javadoc)
     * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {
    	JComboBox combo = (JComboBox)e.getSource();
    	TreeMapNodeRenderer tnr =  m_treemap.getTreeMapNodeRenderer();
    	tnr.setLeavesNumberRepresentation(combo.getSelectedItem().toString());
    }
    
}
