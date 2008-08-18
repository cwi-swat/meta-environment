package nl.cwi.sen1.visplugin.treeplugin;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 * handles the events of the number combo box
 * @author Qais
 *
 */
public class NumberComboBoxActionListener implements ActionListener{
	private static TreeVisualization m_treemap;
	
	/**
	 * @param treemap the treemap visualization
	 */	
	public NumberComboBoxActionListener( TreeVisualization treemap, TreeNodeControlAdapter treeMapNodeControlAdapter){
		m_treemap = treemap;
	}

    /* (non-Javadoc)
     * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {
    	JComboBox combo = (JComboBox)e.getSource();
    	TreeNodeRenderer tnr =  m_treemap.getTreeNodeRenderer();
    	tnr.setLeavesNumberRepresentation(combo.getSelectedItem().toString());
    }
    
}
