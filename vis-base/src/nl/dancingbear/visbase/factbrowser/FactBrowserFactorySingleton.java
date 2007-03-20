package nl.dancingbear.visbase.factbrowser;

import nl.cwi.sen1.relationstores.Factory;
import aterm.pure.PureFactory;

/**
 * A Singleton class to share a single factory instance.
 * @author A. Belgraver
 * @author R. van Remortel
 * @date 20-2-2007
 */
public class FactBrowserFactorySingleton {

    private static Factory m_factory = null;
    private static PureFactory m_pureFactory = null;

    /**
     * Get the factory instance.
     * @author A. Belgraver
     * @author R. van Remortel
     * @return a new Factory (if none is present)
     * @date 20-2-2007
     */
    public static Factory getFactoryInstance() {
        createInstances();
        return m_factory;
    }

    /**
     * Get the factory instance.
     * @author A. Belgraver
     * @author R. van Remortel
     * @return a new Factory (if none is present)
     * @date 20-2-2007
     */
    public static PureFactory getPureFactoryInstance() {
        createInstances();
        return m_pureFactory;
    }

    private static void createInstances() {
        if (m_factory == null) {
            m_pureFactory = new PureFactory();
            m_factory = Factory.getInstance(m_pureFactory);
        }
    }

}