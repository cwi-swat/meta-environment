package toolbus;

public class ToolBusTscriptError extends ToolBusException {
	
	  public ToolBusTscriptError(String arg0) {
	    super("Error in Tscript: " + arg0);
	  }
}
