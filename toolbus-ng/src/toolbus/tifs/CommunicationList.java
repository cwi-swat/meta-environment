package toolbus.tifs;

import java.util.ArrayList;

import aterm.ATermAppl;
import aterm.ATermList;

public class CommunicationList extends ArrayList<Communication>{
	private static final long serialVersionUID = 3769950404719988943L;
	
	public CommunicationList(ATermList representation){
		initCommunicationList(representation);
	}
	
	private void initCommunicationList(ATermList representation){
		ATermList iter = representation;
		while(!iter.isEmpty()){
			add(Communication.create((ATermAppl) iter.getFirst()));
			iter = iter.getNext();
		}
	}
}
