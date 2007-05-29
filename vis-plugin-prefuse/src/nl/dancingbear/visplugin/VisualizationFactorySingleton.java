package nl.dancingbear.visplugin;

import nl.cwi.sen1.relationstores.Factory;
import aterm.pure.PureFactory;

/**
 * A Singleton class to share a single factory instance.
 * @author A. Belgraver
 * @author R. van Remortel
 * @date 20-2-2007
 */
public class VisualizationFactorySingleton {

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

    /**
     * Allows for initialization of the factories with the factories given by
     * the MetaStudio.
     *
     * @param pureFactory Pure factory.
     * @param factory RStore factory.
     *
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public static void initInstances(PureFactory pureFactory, Factory factory) {
        m_pureFactory = pureFactory;
        m_factory = factory;
    }

    private static void createInstances() {
        if (m_factory == null) {
            m_pureFactory = new PureFactory();
            m_factory = Factory.getInstance(m_pureFactory);
        }
    }

}