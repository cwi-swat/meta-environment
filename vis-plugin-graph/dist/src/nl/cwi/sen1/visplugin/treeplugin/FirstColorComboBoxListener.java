package nl.cwi.sen1.visplugin.treeplugin;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 * handles the events of first color combo box
 * @author ali
 *
 */
public class FirstColorComboBoxListener implements ActionListener{
	private static TreeVisualization m_treemap;
	private static TreeNodeControlAdapter m_treeNodeControlAdapter;

	/**
	 * @param treemap the tree visualization
	 * @param treeMapNodeControlAdapter the tree control adapter
	 */
	public FirstColorComboBoxListener( TreeVisualization treemap, TreeNodeControlAdapter treeMapNodeControlAdapter){
		m_treemap = treemap;
        m_treeNodeControlAdapter = treeMapNodeControlAdapter;
	}

    /* (non-Javadoc)
     * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {
    	JComboBox combo = (JComboBox)e.getSource();
    	TreeNodeRenderer tnr =  m_treemap.getTreeNodeRenderer();
    	tnr.setLeafLeftColorRepresentation(combo.getSelectedItem().toString());
    	m_treeNodeControlAdapter.setLeafLeftColorRepresentation(combo.getSelectedItem().toString());
    }
    
}
