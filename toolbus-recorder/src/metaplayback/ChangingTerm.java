package metaplayback;

import aterm.*;

public class ChangingTerm {
	private String process;
	private String patternKind;
	private ATerm pattern;
	private MetaMessageList messageList;
	private ATermFactory factory;
	
	public ChangingTerm(ATermFactory factory, String process, ATerm pattern, MetaMessageList messageList){
		this.factory = factory;
		this.process = process;
		this.pattern = pattern;
		this.messageList = messageList;
		
		int endKind = pattern.toString().indexOf("(");
		if(endKind!=-1){
			patternKind = pattern.toString().substring(0,endKind + 1);
		}
		else{
			patternKind = pattern.toString();
		}
		
	}
	public boolean isChangingTerm(String incomingProcess, ATerm message){
		String line, stringNumber;
		String messageKind;
		int endKind;
		boolean sameKid, sameTerm;
		if(incomingProcess.equals(process)){
			endKind = message.toString().indexOf("(");
			if(endKind!=-1){
				messageKind = message.toString().substring(0,endKind + 1);
			}
			else{
				messageKind = message.toString();
			}
			if(patternKind.equals(messageKind)){
				if(message.getChildCount() == pattern.getChildCount()){
					MetaMessageList checkTerms = messageList.getUnpassedMessagesOfType(messageKind);
					
					MetaMessage test;
					String checkString;
					for(int j=0;j<checkTerms.getNumberOfMessages();j++){
						MetaMessage checkMessage = checkTerms.getMessageAt(j);
						sameTerm = true;
						for(int i=0;i<pattern.getChildCount();i++){
							sameKid = false;
							line = pattern.getChildAt(i).toString();
							if(pattern.getChildAt(i).equals(message.getChildAt(i))){
								sameKid = true;
							}
							else if(line.length()==18){
								line = line.substring(1, line.length()-1);
								
								if(line.equals("__changing_int__")){
									try{
										Integer testInteger = new Integer(message.getChildAt(i).toString());
										sameKid = true;
									}
									catch(Exception e){
										System.out.println("ERROR ON: " + message.getChildAt(i).toString());
									}
								}
								else if(line.equals("__changing_str__")){
									sameKid = true;
								}
								else if(line.equals("__constant_str__")){
									checkString = message.getChildAt(i).toString();
									if(checkMessage.checkStringChildAt(i,checkString)){
										sameKid = true;
									}
								}
							}
							if(!sameKid){
								sameTerm = false;
								break;
							}
						}
						if(sameTerm){
							messageList.setMessagePassed(checkMessage);
							return true;
						}
					}			
				}
			}
		}
		return false;
	}
}
