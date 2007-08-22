package nl.dancingbear.visplugin.text;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import nl.cwi.sen1.relationstores.types.RTuple;
import nl.dancingbear.visplugin.VisualizationPluginWindow;

/**
 * The TableVisualizationWindows class. It Extends VisualizationPluginWindow.
 *
 * @author Srinivasan Tharmarajah
 * @author Wasim Alsaqaf
 * @date 08-03-2007
 */
public class TextVisualizationWindow extends VisualizationPluginWindow {

    private JTextArea m_text;

    private static final long serialVersionUID = 1;

    public JPanel render(RTuple fact) {
        JPanel controlArea = new JPanel(new BorderLayout());

        try {
            m_text = new JTextArea();

            m_text.setText(fact.toTerm().toString());
            
            // finally add the table to a pane and add it to the JPanel
            JScrollPane pane = new JScrollPane(m_text);
            controlArea.add(pane, BorderLayout.CENTER);

        } catch (Exception ex) {
            System.err.println(ex);
        }

        return controlArea;
    }
}
