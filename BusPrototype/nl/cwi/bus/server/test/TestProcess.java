package nl.cwi.bus.server.test;

import nl.cwi.bus.server.AbstractProcessInstance;
import nl.cwi.bus.server.Bus;
import nl.cwi.bus.server.ToolInstance;
import nl.cwi.bus.variable.FinalizableVariable;
import nl.cwi.term.serializable.SerializableStringTerm;

/**
 * Dummy process.
 * 
 * @author Arnold Lankamp
 */
public class TestProcess extends AbstractProcessInstance{
	private ToolInstance toolInstance = null;
	private SerializableStringTerm signatureMatcher = null;
	private FinalizableVariable textMessage = null;

	public TestProcess(ToolInstance toolInstance){
		super();

		this.toolInstance = toolInstance;

		signatureMatcher = new SerializableStringTerm("");
		
		Bus.getInstance().getMessageQueue().subscribe(this, signatureMatcher.getSignature());
	}

	public synchronized boolean step(FinalizableVariable message){
		boolean handled = false;
		// If it's a string term, receive it and send it to the tool.
		if(signatureMatcher.match(message.getVariable().getSignature())){
			Bus.getInstance().getMessageQueue().sendNote(message);
			
			handled = true;
		}
		
		return handled;
	}

	public void receiveMessage(FinalizableVariable receivedMessage){
		textMessage = setVariable(textMessage, receivedMessage);
	}

	public void showMessage(){
		sendDo(toolInstance, textMessage);
	}
	
	public void terminate(){
		textMessage = setVariable(textMessage, null);
	}
	
	public void receiveNote(FinalizableVariable note){
		// If it's a string term, receive it and send it to the tool.
		if(signatureMatcher.match(note.getVariable().getSignature())){
			receiveMessage(note);
			showMessage();
		}
	}
}
