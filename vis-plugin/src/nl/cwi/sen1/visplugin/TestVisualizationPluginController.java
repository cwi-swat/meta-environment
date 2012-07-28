package nl.cwi.sen1.visplugin;


import aterm.pure.PureFactory;
import junit.framework.TestCase;

public class TestVisualizationPluginController extends TestCase {

    private ExampleVisualizationController m_pluginController;
    private PureFactory m_pureFactory;


    /**
     * Sets up the test fixture.
     * (Called before every test case method.)
     */
    protected void setUp() {
        m_pluginController = new ExampleVisualizationController();

        m_pureFactory = VisualizationFactorySingleton.getPureFactoryInstance();
        m_pluginController.initPluginController(m_pureFactory);
    }

    /**
     * Tears down the test fixture.
     * (Called after every test case method.)
     */
    protected void tearDown() {

    }

    /**
     * Test if the constructor call is done properly
     * @author Aldert Boerhoop
     * @date 21-2-2007
     */
    public void test_PluginControllerClass() {
        assertNotNull(m_pluginController);
    }

    /**
     * Test if vpGetName works
     * @author Aldert Boerhoop
     * @date 21-2-2007
     */
    public void test_vpGetName() {
          assertEquals(m_pluginController.vpGetName(),m_pureFactory.make("snd-value(vp-name(<str>))","Visualisatie Test Plugin"));
    }

    /**
     * Test if vpIsTypeSupported works
     * @author Aldert Boerhoop
     * @date 21-2-2007
     */
    public void test_vpIsTypeSupported() {
    	assertEquals(m_pluginController.vpIsTypeSupported(m_pureFactory.make("relation([str,str])")),m_pureFactory.make("snd-value(vp-type-supported(<bool>))",true));
        assertEquals(m_pluginController.vpIsTypeSupported(m_pureFactory.make("relation([int,str])")),m_pureFactory.make("snd-value(vp-type-supported(<bool>))",false));
    }
}
