package metaplayback;

import java.util.Vector;
import java.io.*;

import aterm.*;

public class MetaMessageList {
	private Vector messageList;
	private ATermFactory factory;
	
	public MetaMessageList(ATermFactory factory){
		this.factory = factory;
		messageList = new Vector();
	}
	public void addMessagesFromFile(File importFile){
		try{
			FileInputStream readermain = new FileInputStream(importFile);
			BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
			String line;
			String fileName = importFile.getName();
			int pos;
			String communicationType;
			int endPosition = fileName.indexOf(".");
			String process = fileName.substring(0, endPosition);
			while((line = buffermain.readLine()) != null){
				pos = line.indexOf(";");
				communicationType = line.substring(0,pos);
				if(communicationType.equals("snd-do") || communicationType.equals("rec-event") || communicationType.equals("snd-ack-event") || communicationType.equals("snd-eval") || communicationType.equals("rec-value")){
					addMessage(line, process);
				}
			}
		}
		catch(Exception e){
			System.out.println("ERROR: importing messagelist.");
		}
	}
	public void addMessagesFromFileElement(Vector fileList){
		FileElement fileElement;
		for(int i=0;i<fileList.size();i++){
			fileElement = (FileElement)fileList.get(i);
			if(fileElement.getFileType().equals("processFile")){
				addMessagesFromFile(fileElement.getFile());
			}
		}
	}
	public void addMessage(String messageType, ATerm message, String process){
		messageList.add(new MetaMessage(process,messageType,message));
	}
	public void addMessage(MetaMessage message){
		messageList.add(message);
	}
	public void addMessage(String line, String process){
		int startPosition = line.indexOf(";");
		String messageType = line.substring(0, startPosition);
		ATerm message = factory.make(line.substring(startPosition+1));
		messageList.add(new MetaMessage(process,messageType,message));
	}
	public void printMessageInfo(){
		MetaMessage metaMessage;
		System.out.println("************************************");
		System.out.println("* Number of messages: " + messageList.size());
		System.out.println("************************************");
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(metaMessage.getMessagePassed()){
				System.out.println("V " + metaMessage.getProcessName() + " : " + metaMessage.getMessageType());
			}
			else{
				System.out.println("X " + metaMessage.getProcessName() + " : " + metaMessage.getMessageType());
			}	
		}
	}
	public void printMessages(){
		int spaces = 17;
		String noOfMessages;
		MetaMessage metaMessage;
		System.out.print("* Number of messages: " + getNoUnpassedMessages());
		noOfMessages = "" + getNoUnpassedMessages();
		spaces -= noOfMessages.length();
		for(int j=0;j<spaces;j++){
			System.out.print(" ");
		}
		System.out.println("*");
		System.out.println("****************************************");
		
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(!metaMessage.getMessagePassed()){
				System.out.println("PROCESS: " + metaMessage.getProcessName());
				System.out.println(metaMessage.getMessageBody().toString() + "\n");
			}
		}
		System.out.println("\n");
	}
	public MetaMessageList getUnpassedMessagesOfType(String type){
		MetaMessage metaMessage;
		MetaMessageList returnList = new MetaMessageList(factory);
		String line;
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			line = metaMessage.getMessageBody().toString();
			if(line.length()>=type.length() && line.substring(0,type.length()).equals(type) && !metaMessage.getMessagePassed()){
				returnList.addMessage(metaMessage);
			}
		}
		return returnList;
	}
	
	public int getNoUnpassedMessages(){
		MetaMessage metaMessage;
		int unPassedMessages = 0;
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(!metaMessage.getMessagePassed()){
				unPassedMessages++;
			}
		}
		return unPassedMessages;
	}
	public int getNumberOfMessages(){
		return messageList.size();
	}
	public MetaMessage getMessageAt(int childNo){
		return (MetaMessage)messageList.get(childNo);
	}
	public Vector getMessageList(){
		return messageList;
	}
	public ATerm getNextMetaMessage(String process, String type){
		MetaMessage metaMessage;
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(metaMessage.isMessageKind(process, type) && !metaMessage.getMessagePassed()){
				return metaMessage.getMessageBody();
			}
		}
		return null;
	}
	public void setNextMessageKindFound(ATerm messageBody){
		String messageKind;
		int endKind = messageBody.toString().indexOf("(");
		
		if(endKind!=-1){
			messageKind = messageBody.toString().substring(0,endKind);
		}
		else{
			messageKind = messageBody.toString();
		}
		
		MetaMessage metaMessage;
		for(int i=0; i<messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(metaMessage.getMessageKind().equals(messageKind) && !metaMessage.getMessagePassed()){
				metaMessage.messagePassed();
				break;
			}
		}
	}
	public boolean setMessageFound(String process, String messageType, ATerm orMessage){
		MetaMessage metaMessage;
		boolean messageFound = false;
		for(int i=0;i < messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(metaMessage.isMessageKind(process,messageType) && !metaMessage.getMessagePassed()){
				if(metaMessage.isMessage(orMessage)){
					metaMessage.messagePassed();
					messageFound = true;
					break;
				}
			}
		}
		return messageFound;
	}
	public boolean setMessagePassed(MetaMessage message){
		MetaMessage metaMessage;
		for(int i=0;i < messageList.size();i++){
			metaMessage = (MetaMessage)messageList.get(i);
			if(metaMessage.equals(message)){
				metaMessage.messagePassed();
				return true;
			}
		}
	return false;
	}
}
