package nl.cwi.sen1.visplugin.treemap;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 * handles the events of color combo box
 * @author Qais
 *
 */
public class ColorComboBoxActionListener implements ActionListener{
	private static TreeMapVisualization m_treemap;
	private static TreeMapNodeControlAdapter m_treeMapNodeControlAdapter;
	

	/**
	 * @param treemap the treemap visualization
	 * @param treeMapNodeControlAdapter the treemap control adapter
	 */
	public ColorComboBoxActionListener( TreeMapVisualization treemap, TreeMapNodeControlAdapter treeMapNodeControlAdapter){
		m_treemap = treemap;
        m_treeMapNodeControlAdapter = treeMapNodeControlAdapter;
	}
	
    /* (non-Javadoc)
     * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {
    	JComboBox combo = (JComboBox)e.getSource();
    	TreeMapNodeRenderer tnr =  m_treemap.getTreeMapNodeRenderer();
    	tnr.setLeavesColorRepresentation(combo.getSelectedItem().toString());
    	m_treeMapNodeControlAdapter.setLeavesColorRepresentation(combo.getSelectedItem().toString());
    }
    
}
