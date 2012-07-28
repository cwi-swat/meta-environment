package nl.cwi.sen1.visplugin;

import javax.swing.JPanel;
import junit.framework.TestCase;


/**
 * Unit test for ContainerPanel class
 *
 * @author Arjen van Schie
 * @date 16-3-2007
 */
public class ContainerPanelTest extends TestCase {

    private ContainerPanel m_containerPanel=null;
    private JPanel m_contentPanel=null;

    public ContainerPanelTest(String name) {
        super(name);
    }

    protected void setUp() throws Exception {
        super.setUp();
        m_contentPanel = new JPanel();
        m_containerPanel = new ContainerPanel(m_contentPanel);
    }

    protected void tearDown() throws Exception {
        super.tearDown();
        m_contentPanel=null;
        m_containerPanel=null;
    }

    /*
     * Test method for 'ContainerPanel.ContainerPanel(JPanel)'
     */
    public void testContainerPanel() {
        m_containerPanel =null;
        m_containerPanel = new ContainerPanel(m_contentPanel);
        assertNotNull(m_containerPanel);
    }

    /*
     * Test method for 'ContainerPanel.showRstoreChangedWarning()'
     */
    public void testShowRstoreChangedWarning() {
        // check first to see there is no warning
        m_containerPanel.hideWarning();
        assertEquals(true, m_containerPanel.getCurrentWarning().equals("empty") );

        // check if the warning gets set
        m_containerPanel.showRstoreChangedWarning();
        assertEquals(false, m_containerPanel.getCurrentWarning().equals("empty") );
    }

    /*
     * Test method for 'ContainerPanel.showRstoreUnloadedWarning()'
     */
    public void testShowRstoreUnloadedWarning() {
        // check first to see there is no warning
        m_containerPanel.hideWarning();
        assertEquals(true, m_containerPanel.getCurrentWarning().equals("empty") );

        // check if the warning gets set
        m_containerPanel.showRstoreUnloadedWarning();
        assertEquals(false, m_containerPanel.getCurrentWarning().equals("empty") );
    }

    /*
     * Test method for 'ContainerPanel.hideWarning()'
     */
    public void testHideWarning() {
        // check first if the warning gets set
        m_containerPanel.showRstoreUnloadedWarning();
        assertEquals(false, m_containerPanel.getCurrentWarning().equals("empty") );

        // check to see there is no warning after hiding it
        m_containerPanel.hideWarning();
        assertEquals(true, m_containerPanel.getCurrentWarning().equals("empty") );
    }

    /*
     * Test method for 'ContainerPanel.getContentPanel()'
     */
    public void testGetContentPanel() {
        assertEquals(true, m_contentPanel == m_containerPanel.getContentPanel() );
    }

}
