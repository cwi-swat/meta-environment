package nl.dancingbear.visplugin;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * The ContainerPanel class forms a container panel for
 * a contentpanel and a warning panel.
 *
 * @author Arjen van Schie
 * @date 16-3-2007
 */
public class ContainerPanel extends JPanel{
	private static final long serialVersionUID = 5261167507099071514L;
	
	private JPanel m_contentPanel = null;
    private JPanel m_warningPanel = null;
    private JLabel m_warningLabel = null;

    private static final String constWarningChanged = "The RStore has changed, this view might be outdated.";
    private static final String constWarningUnloaded = "The RStore of this fact has been unloaded!";

    /**
     * Generate a container panel for the warningpanel
     * and the content panel and hide the warningpanel by default
     *
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public ContainerPanel(JPanel content){
    // make the panel fullscreen
    this.makePanelFullscreen();

        // get the child panel-references
        m_warningPanel = this.generateWarningPanel();
        m_contentPanel = content;

        // add the panels
        this.add( m_warningPanel, BorderLayout.NORTH );
        this.add( m_contentPanel, BorderLayout.CENTER );

        // hide the warning panel by default
    this.hideWarning();
    }

    /**
     * Show a warning-message for the RStore-changed event
     *
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public void showRstoreChangedWarning(){
        m_warningLabel.setText( constWarningChanged );
        m_warningPanel.setVisible(true);
    }

    /**
     * Show a warning-message for the RStore-unloaded event
     *
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public void showRstoreUnloadedWarning(){
        m_warningLabel.setText( constWarningUnloaded );
        m_warningPanel.setVisible(true);
    }

    /**
     * Hide the warning messages of a window
     *
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public void hideWarning(){
        m_warningPanel.setVisible(false);
    }

    /**
     * Make the panel fullscreen
     *
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    private void makePanelFullscreen(){
        BorderLayout layout = new BorderLayout();
        this.setLayout(layout);
    }

    /**
     * Generate a panel for the warning messages
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    private JPanel generateWarningPanel(){
        // create a label and panel
        JPanel warningArea = new JPanel();
        m_warningLabel=new JLabel();
         m_warningLabel.setForeground(java.awt.Color.red);

         // add a button to hide the warnings
         JButton hideWarningButton = new JButton();
         hideWarningButton.setText("Hide Warning");
         hideWarningButton.addActionListener(new ActionListener() {
             public void actionPerformed(ActionEvent event) {
                 hideWarning();
             }
         });

        // connect the label & button
        warningArea.add(m_warningLabel);
        warningArea.add(hideWarningButton);

        return warningArea;
    }

    /**
     * return a reference to the contentpanel
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public JPanel getContentPanel() {
        return m_contentPanel;
    }

    /**
     * returns the current warning message (or "empty" in case it is invisible)
     * @author Arjen van Schie
     * @date 16-3-2007
     */
    public String getCurrentWarning(){
        String warning="empty";
        if( m_warningPanel.isVisible() ){
            warning = m_warningLabel.getText();
        }
        return warning;
    }

}
