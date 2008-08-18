package nl.cwi.sen1.visplugin.treeplugin;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 * handles the events of the texture combo box
 * @author Qais
 *
 */
public class TextureComboBoxActionListener implements ActionListener{
	private static TreeVisualization m_tree;
	
	/**
	 * @param treemap the display treemap 
	 */
	public TextureComboBoxActionListener( TreeVisualization tree, TreeNodeControlAdapter treeMapNodeControlAdapter){
		m_tree = tree;
	}

    /* (non-Javadoc)
     * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {
    	JComboBox combo = (JComboBox)e.getSource();
    	TreeNodeRenderer tnr =  m_tree.getTreeNodeRenderer();
    	tnr.setLeavesTextureRepresentation(combo.getSelectedItem().toString());
    }
    
}
