package toolbus.tbterm;

import aterm.AFun;
import aterm.pure.PureFactory;

public class TBTermFactory extends PureFactory {
	 /**
     * A term of type VAR (variable)
     */
    public static final int VAR  = 8;
    
    /**
     * A term of type RESVAR (result variable)
     */
    public static final int RESVAR  = 9; 
    
    /**
     * A term of type TYPE (type)
     */
    public static final int TYPE  = 10; 
    
    protected PureFactory factory = new PureFactory();
    
    
    public TBTermVar makeVar() {}
    
    public TBTermResVar makeResVar() {}
    
    public AFun varAFun = factory.makeAFun("var", 2, false);
    
    public AFun resVarAFun = factory.makeAFun("rvar", 2, false);
}
