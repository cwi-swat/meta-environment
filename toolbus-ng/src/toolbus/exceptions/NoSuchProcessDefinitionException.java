package toolbus.exceptions;

public class NoSuchProcessDefinitionException extends ToolBusError{
	private static final long serialVersionUID = 7082887502132507643L;
	
	private final String processName;
	private final int actuals; 
	
	public NoSuchProcessDefinitionException(String processName, int actuals){
		super("No definition for process " + processName + ", with " + actuals + " actuals\n");
		
		this.processName = processName;
		this.actuals = actuals;
	}

	public int getActuals() {
		return actuals;
	}

	public String getProcessName() {
		return processName;
	}
	
}
