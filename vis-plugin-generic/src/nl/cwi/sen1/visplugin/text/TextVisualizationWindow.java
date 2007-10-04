package nl.cwi.sen1.visplugin.text;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;

public class TextVisualizationWindow extends VisualizationPluginWindow {
    private JTextArea m_text;
	private VisPluginTextUnparsing unparser;
    private static final long serialVersionUID = 1;
    
    public TextVisualizationWindow(VisPluginTextUnparsing unparser) {
    	this.unparser = unparser;
	}
    
    public JPanel render(RTuple fact) {
        JPanel controlArea = new JPanel(new BorderLayout());

        try {
            m_text = new JTextArea();
            m_text.setEditable(false);
            m_text.setWrapStyleWord(true);
            m_text.setLineWrap(true);
            
            /* asynchronous call to unparser, will continue with @see setText() */
            unparser.unparseRTuple(this, fact); 
            
            // finally add the table to a pane and add it to the JPanel
            JScrollPane pane = new JScrollPane(m_text);
            controlArea.add(pane, BorderLayout.CENTER);
        } catch (Exception ex) {
            System.err.println(ex);
        }

        return controlArea;
    }
    
    public void setText(String text) {
    	m_text.setText(text);
    }
}
