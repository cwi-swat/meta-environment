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

    /**
     * Get the factory instance.
     * @author A. Belgraver
     * @author R. van Remortel
     * @return a new Factory (if none is present)
     * @date 20-2-2007
     */
    public static Factory getFactoryInstance() {
        return InstanceKeeper.m_factory;
    }

    /**
     * Get the factory instance.
     * @author A. Belgraver
     * @author R. van Remortel
     * @return a new Factory (if none is present)
     * @date 20-2-2007
     */
    public static PureFactory getPureFactoryInstance() {
        return InstanceKeeper.m_pureFactory;
    }
    
    private static class InstanceKeeper{
    	public final static Factory m_factory;
    	private final static PureFactory m_pureFactory;
    	
    	static{
    		m_pureFactory = new PureFactory();
            m_factory = Factory.getInstance(m_pureFactory);
    	}
    }

}