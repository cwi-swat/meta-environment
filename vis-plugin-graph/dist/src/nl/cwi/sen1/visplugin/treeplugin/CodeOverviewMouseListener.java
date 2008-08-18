package nl.cwi.sen1.visplugin.treeplugin;
import java.awt.event.MouseEvent;

import javax.swing.JTextPane;

import prefuse.controls.ControlAdapter;
import prefuse.visual.VisualItem;

/**
 * class CodeOverviewMouseListener is a control adapter for codeoverview window
 * @author Qais
 *
 */

public class CodeOverviewMouseListener extends ControlAdapter {
	private static JTextPane m_codeOverviewArea;
	TreeNodeControlAdapter m_treeMapNodeControlAdapter;
	private VisualItem m_visualItem = null;
	
	/**
	 * @param codeOverviewArea textpane shows the code-overview
	 * @param treeMapNodeControlAdapter the treemap control adapter
	 */
	public CodeOverviewMouseListener(JTextPane codeOverviewArea, TreeNodeControlAdapter treeMapNodeControlAdapter){
		m_codeOverviewArea = codeOverviewArea;
		m_treeMapNodeControlAdapter = treeMapNodeControlAdapter;
	}
	
	/* (non-Javadoc)
	 * @see prefuse.controls.ControlAdapter#mouseClicked(java.awt.event.MouseEvent)
	 */	
	public void mouseClicked(MouseEvent e){
    	if(e.getClickCount() == 2){		
			//String filePath = m_treeMapNodeControlAdapter.getFilePath();
    		JTextPane codeDoc = m_treeMapNodeControlAdapter.getCodeDoc();
    		String filePath = m_treeMapNodeControlAdapter.getFilePath();
			TreeFileContentViewer treeFileContentViewer = new TreeFileContentViewer(codeDoc, filePath);
			treeFileContentViewer.scrollTo(m_codeOverviewArea.getCaretPosition());
    	}
	}
	

    	

	
}
