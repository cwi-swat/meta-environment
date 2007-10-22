package toolbus.logging;

/**
 * This interface specifies some log types that are specific for the ToolBusNG.
 * 
 * @author Arnold Lankamp
 */
public interface IToolBusLoggerConstants{
	public final static String TOOL = "tool";
	public final static String TOOLINSTANCE = "toolinstance";
	public final static String COMMUNICATION = "communication";

	public final static String PARSING  = "parsing";
	public final static String MESSAGES = "messages";
	public final static String NOTES    = "notes";	
	public final static String CALLS    = "calls";
	public final static String EXECUTE  = "execute";
	public final static String TOOLCOM  = "toolcom";
	
	// TODO add more log types and register them at the LoggerFactory when you want them to be logged.
}
