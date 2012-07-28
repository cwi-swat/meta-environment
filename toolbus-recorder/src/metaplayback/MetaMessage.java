package metaplayback;

import aterm.*;

public class MetaMessage {
	private String processName;
	private String messageType;
	private String messageKind;
	private ATerm messageBody;
	private boolean messagePassed;
	
	public MetaMessage(String processName, String messageType, ATerm messageBody){
		this.processName = processName;
		this.messageType = messageType;
		this.messageBody = messageBody;
		
		int endKind = messageBody.toString().indexOf("(");
		if(endKind!=-1){
			messageKind = messageBody.toString().substring(0,endKind);
		}
		else{
			messageKind = messageBody.toString();
		}
		messagePassed = false;
	}
	public boolean isMessageKind(String processName, String messageType){
		if(this.processName.equals(processName) && this.messageType.equals(messageType)){
			return true;
		}
		return false;
	}
	public boolean isMessage(ATerm message){
		if(messageBody.isEqual(message)){
			return true;
		}
		else{
			return false;
		}
	}
	public boolean checkStringChildAt(int childNo, String checkString){
		MetaMessage metaMessage;
		String line;
		if(messageBody.getChildCount()>=childNo){
			line = messageBody.getChildAt(childNo).toString();
			if(line.equals(checkString)){
				return true;
			}
		}
		return false;
	}
	public void messagePassed(){
		messagePassed = true;
	}
	public String getProcessName(){
		return processName;
	}
	public String getMessageType(){
		return messageType;
	}
	public boolean getMessagePassed(){
		return messagePassed;
	}
	public ATerm getMessageBody(){
		return messageBody;
	}
	public String getMessageKind(){
		return messageKind;
	}
}
