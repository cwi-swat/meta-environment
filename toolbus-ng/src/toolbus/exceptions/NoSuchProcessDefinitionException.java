package toolbus.exceptions;

public class NoSuchProcessDefinitionException extends ToolBusError{
	private static final long serialVersionUID = 7082887502132507643L;
	
	public NoSuchProcessDefinitionException(String message){
		super(message);
	}
}
