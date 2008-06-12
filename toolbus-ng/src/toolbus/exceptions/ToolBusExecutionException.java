package toolbus.exceptions;

import toolbus.parsercup.PositionInformation;

public class ToolBusExecutionException extends ToolBusException{
	private static final long serialVersionUID = -8118600513367912483L;
	
	private final PositionInformation posInfo;
	
	public ToolBusExecutionException(String message, PositionInformation posInfo){
		super(message+" @ "+posInfo);
		
		this.posInfo = posInfo;
	}
	
	public PositionInformation getPositionInformation(){
		return posInfo;
	}
}
