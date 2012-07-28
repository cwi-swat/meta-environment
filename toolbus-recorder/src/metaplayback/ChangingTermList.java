package metaplayback;

import java.io.File;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Vector;
import aterm.*;

public class ChangingTermList {
	private ATermFactory factory;
	private Vector changingTermsList;
	private MetaMessageList messageList;
	
	public ChangingTermList(File changingTerms, ATermFactory factory, MetaMessageList messageList){
		this.factory = factory;
		this.messageList = messageList;
		changingTermsList = new Vector();
		loadChangingTerms(changingTerms);
	}
	public void loadChangingTerms(File changingTerms){
		String line;
		String process;
		ATerm pattern;
		int seperator;
		try{
			FileInputStream readermain = new FileInputStream(changingTerms);
			BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				seperator = line.indexOf(";");
				process = line.substring(0,seperator);
				pattern = factory.make(line.substring(seperator+1));
				addChangingTerm(process, pattern);
			}
		}
		catch(Exception e){
			System.out.println("ERROR: processing changingTerms");
			System.out.println(e.getMessage());
		}
	}
	private void addChangingTerm(String process, ATerm pattern){
		ChangingTerm addTerm = new ChangingTerm(factory, process, pattern, messageList);
		changingTermsList.add(addTerm);
	}
	public boolean checkChangingTerms(String process, ATerm message){
		ChangingTerm checkTerm;
		boolean foundChangingTerm = false;
		for(int i=0;i<changingTermsList.size();i++){
			checkTerm = (ChangingTerm)changingTermsList.get(i);
			foundChangingTerm = checkTerm.isChangingTerm(process, message);
			if(foundChangingTerm){
				return true;
			}
		}
		return false;
	}
}
