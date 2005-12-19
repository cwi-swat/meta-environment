package metaplayback;

import aterm.ATerm;
import aterm.ATermFactory;

//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.InputStreamReader;
import java.util.Vector;
import java.io.*;

public class MetaFilter {
	private ATermFactory factory;
	private MetaMessageList messageList;
	private MetaMessageList unknownMessages;
	private Vector filterTable = new Vector();
	private String executeMap, originalExecuteMap;
	private ChangingTermList changingTermList;

	public MetaFilter(ATermFactory factory){
		this.factory = factory;
		unknownMessages = new MetaMessageList(factory);
	}
	public void setExecuteMaps(String executeMap, String originalExecuteMap){
		this.executeMap = executeMap;
		this.originalExecuteMap = originalExecuteMap;
	}
	public void setMessageList(MetaMessageList messageList){
		this.messageList = messageList;
	}
	public void addFilter(String filter, boolean hasImitatorTool){
		filterTable.add(new FilterElement(filter,true, hasImitatorTool));
	}
	public boolean filterTerm(ATerm term){
		FilterElement filterElem = null;
		boolean isFiltered = false;
		
		ATerm createTerm = factory.make("create");
		if(createTerm.isEqual((ATerm)term.getChildAt(1))){	
			if(isInFilter(term.getChildAt(2).getChildAt(0).toString())){
				isFiltered = true;
			}
			return saveProcess(term, factory, isFiltered);
		}
		else if(isInFilter(Integer.parseInt(term.getChildAt(0).toString()))){
			String communicationType = term.getChildAt(1).toString();
			if(communicationType.equals("snd-do") || communicationType.equals("rec-event") || communicationType.equals("snd-ack-event") || communicationType.equals("snd-eval") || communicationType.equals("rec-value")){
				return true;
			}
		}
		return false;
	}
	private boolean saveProcess(ATerm term, ATermFactory factory, boolean isFiltered){
		if(isFiltered){
			if(term.getChildAt(4).getChildCount()==1){
				//Bij in-output en editorhive
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
				//Bij de GUI
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(2).getChildAt(1).toString()), isFiltered);
			}
			return true;
		}
		else{
			if(term.getChildAt(4).getChildCount()==1){
				//Bij in-output en editorhive
				addProcess(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
				//Bij de GUI
				addProcess(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(2).getChildAt(1).toString()), isFiltered);
			}
			return false;
		}
	}
	private void addProcess(String processName, int pid, boolean isFiltered){
		FilterElement filterElem = new FilterElement(processName,pid);
		filterTable.add(filterElem);
	}
	private void addPid(String processName, int pid, boolean isFiltered){
		FilterElement filterElem = null;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(processName)){
				filterElem.setFilterPid(pid);
				filterElem.setFiltered(isFiltered);
				break;
			}
		}
	}
	private boolean isInFilter(String processName){
		FilterElement filterElem = null;
		boolean isFound = false;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(processName) && filterElem.isFiltered()){
				isFound = true;
				break;
			}
		}
		return isFound;
	}
	private boolean isInFilter(int pid){
		FilterElement filterElem = null;
		boolean isFound = false;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualPid(pid) && filterElem.isFiltered()){
				isFound = true;
				break;
			}
		}
		return isFound;
	}
	public void printTable(){
		FilterElement filterElem = null;
		System.out.println("***********************");
		System.out.println("** TABLE INFORMATION **");
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			System.out.println("** PID: " + filterElem.getPid());
			System.out.println("** filterName: " + filterElem.getFilterName());
			System.out.println("** Filtered: " + filterElem.isFiltered());
			System.out.println("** hasImitatorTool: " + filterElem.hasImitatorTool());
			System.out.println("**");
		}
		System.out.println("***********************");
	}
	public int getSize(){
		return filterTable.size();
	}
	public String getFilter(int place){
		FilterElement filterElem = (FilterElement)filterTable.get(place);
		return filterElem.getFilterName();
	}
	public void compareMessages(ATerm message){
		String messageType = message.getChildAt(1).toString();
		ATerm orMessage = factory.make(createMessage(message));
		int pid = Integer.parseInt(message.getChildAt(0).toString());
		String process = getProcessFromPid(pid);
		MetaMessage metaMessage;

		boolean messageFound = messageList.setMessageFound(process, messageType, orMessage);
		if(!messageFound){
			String messageString = message.toString();
			if(!changingTermList.checkChangingTerms(process, orMessage)){
				unknownMessages.addMessage(messageType,orMessage,process);
			}
		}
	}
	public String replacePath(String message, String currentPath, String originalPath){
		int startPoint = message.indexOf(currentPath);
		String newMessage = message;
		if(startPoint != -1){
			int endPoint = startPoint + currentPath.length();
			if(endPoint != -1){
				newMessage = message.substring(0,startPoint) + originalPath + message.substring(endPoint);
				startPoint = message.indexOf(currentPath);
				if(startPoint != -1){
					newMessage = replacePath(newMessage,currentPath, originalPath);
				}
			}
		}
		return newMessage;
	}
	private String createMessage(ATerm term){
		String varName, currentVar, line, value, result;
		int endPosFunction, endPosition;

		ATerm variables = (ATerm)term.getChildAt(4);
		ATerm pattern = (ATerm)term.getChildAt(2).getChildAt(1);
		String patternString = pattern.toString();
		endPosFunction = patternString.indexOf("(");

		if(endPosFunction != -1){
			result = patternString.substring(0,endPosFunction + 1);
			
			for(int j=0;j<pattern.getChildCount();j++){
				varName=pattern.getChildAt(j).toString();
				endPosition = varName.indexOf("$");
				
				if(endPosition!=-1){
					varName = varName.substring(0,endPosition);
					
					for(int i=0; i<variables.getChildCount();i++){
						line=variables.getChildAt(i).getChildAt(0).toString();
						endPosition = line.indexOf("$");
						
						if(endPosition!=-1){
							currentVar = line.substring(0,endPosition);
							
							if(varName.equals(currentVar)){
								result = result + variables.getChildAt(i).getChildAt(1).toString();
								if(j<pattern.getChildCount()-1){
									result = result + ",";
								}
							}	
						}
					}
				}
			}
			result = result + ")";
		}
		else{
			result = patternString;
		}
		return result;
	}
	public MetaMessageList getUnknownMessages(){
		return unknownMessages;
	}
	public int getPidFromProcessName(String process){
		FilterElement filterElem = null;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(process)){
				return filterElem.getPid();
			}
		}
		return 0;
	}
	public boolean getHasToolFromProcessName(String process){
		FilterElement filterElem = null;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(process)){
				return filterElem.hasImitatorTool();
			}
		}
		return false;
	}
	public String getProcessFromPid(int pid){
		FilterElement filterElem = null;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualPid(pid)){
				return filterElem.getFilterName();
			}
		}
		return null;
	}
	public void loadChangingTermList(File changingTerms){
		changingTermList = new ChangingTermList(changingTerms, factory, messageList);
	}
}

