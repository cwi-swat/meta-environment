package toolbus.matching;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.msg.RecMsg;
import toolbus.atom.msg.SndMsg;
import toolbus.atom.note.SndNote;
import toolbus.atom.note.Subscribe;
import toolbus.process.ProcessInstance;
import toolbus.util.collections.ConcurrentHashMap;
import aterm.ATerm;

public class MatchStore{
	private final static List<RecMsg> NOMESSAGEPARTNERS = new ArrayList<RecMsg>(0);
	private final static Set<ProcessInstance> NONOTEPARTNERS = new HashSet<ProcessInstance>(0);
	
	private final TBTermFactory tbFactory;
	
	private final ConcurrentHashMap<ATerm, List<ATerm>> messageLinks;
	private final ConcurrentHashMap<ATerm, List<ATerm>> noteLinks;
	
	private final Map<ATerm, List<RecMsg>> messageMappings;
	private final Map<ATerm, Map<ProcessInstance, MappingRefCount>> noteMappings;
	
	private final Object messageLock = new Object();
	private final Object noteLock = new Object();
	
	public MatchStore(TBTermFactory tbFactory){
		super();
		
		this.tbFactory = tbFactory;
		
		messageLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		noteLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		
		messageMappings = new HashMap<ATerm, List<RecMsg>>();
		noteMappings = new HashMap<ATerm, Map<ProcessInstance, MappingRefCount>>();
	}
	
	public void calculateMatches(List<Atom> atomSet){
		List<ATerm> receiveMessages = new LinkedList<ATerm>();
		List<ATerm> subscribeNotes = new LinkedList<ATerm>();
		
		Iterator<Atom> atomsIteratorForRecMsg = atomSet.iterator();
		while(atomsIteratorForRecMsg.hasNext()){
			Atom atom = atomsIteratorForRecMsg.next();
			if(atom instanceof RecMsg){
				addReceiveMessagePattern((RecMsg) atom, receiveMessages);
			}else if(atom instanceof Subscribe){
				addSubscribeNotePattern((Subscribe) atom, subscribeNotes);
			}
		}
		
		Iterator<Atom> atomsIteratorForSndMsg = atomSet.iterator();
		while(atomsIteratorForSndMsg.hasNext()){
			Atom atom = atomsIteratorForSndMsg.next();
			if(atom instanceof SndMsg){
				addSendMessagePattern((SndMsg) atom, receiveMessages);
			}else if(atom instanceof SndNote){
				addSendNotePattern((SndNote) atom, subscribeNotes);
			}
		}
	}
	
	private void addReceiveMessagePattern(RecMsg message, List<ATerm> receiveMessages){
		ATerm matchPattern = message.msg;
		receiveMessages.add(matchPattern);
		messageLinks.put(matchPattern, new ArrayList<ATerm>());
	}
	
	private void addSendMessagePattern(SndMsg message, List<ATerm> receiveMessages){
		ATerm matchPattern = message.msg;
		
		Iterator<ATerm> receiveMessagePatternIterator = receiveMessages.iterator();
		while(receiveMessagePatternIterator.hasNext()){
			ATerm receiveMessagePattern = receiveMessagePatternIterator.next();
			
			if(tbFactory.mightMatch(matchPattern, receiveMessagePattern)){
				List<ATerm> sendMessageList = messageLinks.get(receiveMessagePattern);
				sendMessageList.add(matchPattern);
			}
		}
	}
	
	private void addSubscribeNotePattern(Subscribe subscribeNote, List<ATerm> subscribeNotes){
		ATerm matchPattern = subscribeNote.notePattern;
		subscribeNotes.add(matchPattern);
		noteLinks.put(matchPattern, new ArrayList<ATerm>());
	}
	
	private void addSendNotePattern(SndNote message, List<ATerm> subscribeNotes){
		ATerm matchPattern = message.notePattern;
		
		Iterator<ATerm> subscribeNotePatternIterator = subscribeNotes.iterator();
		while(subscribeNotePatternIterator.hasNext()){
			ATerm subscribeNotePattern = subscribeNotePatternIterator.next();
			
			if(tbFactory.mightMatch(matchPattern, subscribeNotePattern)){
				List<ATerm> sendNoteList = noteLinks.get(subscribeNotePattern);
				sendNoteList.add(matchPattern);
			}
		}
	}
	
	public void registerReceiveMessage(RecMsg receiveMessage){
		List<ATerm> matches = messageLinks.get(receiveMessage.msg);
		Iterator<ATerm> matchesIterator = matches.iterator();
		
		synchronized(messageLock){
			while(matchesIterator.hasNext()){
				ATerm pattern = matchesIterator.next();
				List<RecMsg> receiveMessageList = messageMappings.get(pattern);
				if(receiveMessageList == null){
					receiveMessageList = new LinkedList<RecMsg>();
					messageMappings.put(pattern, receiveMessageList);
				}
				receiveMessageList.add(receiveMessage);
			}
		}
	}
	
	public void deregisterReceiveMessage(RecMsg receiveMessage){
		List<ATerm> matches = messageLinks.get(receiveMessage.msg);
		Iterator<ATerm> matchesIterator = matches.iterator();
		
		synchronized(messageLock){
			while(matchesIterator.hasNext()){
				ATerm pattern = matchesIterator.next();
				List<RecMsg> receiveMessageList = messageMappings.get(pattern);
				receiveMessageList.remove(receiveMessage);
			}
		}
	}
	
	public List<RecMsg> getPossibleMessagePartners(ATerm pattern){
		List<RecMsg> recMessages;
		
		synchronized(messageLock){
			recMessages = messageMappings.get(pattern);
		}
		
		if(recMessages == null) return NOMESSAGEPARTNERS;
		
		return recMessages;
	}
	
	private static class MappingRefCount{
		public int nrOfMappings;
	}
	
	public void registerSubscribeNote(Subscribe subscribeNote){
		List<ATerm> matches = noteLinks.get(subscribeNote.notePattern);
		Iterator<ATerm> matchesIterator = matches.iterator();
		
		synchronized(noteLock){
			while(matchesIterator.hasNext()){
				ProcessInstance pi = subscribeNote.getProcess();
				
				ATerm pattern = matchesIterator.next();
				Map<ProcessInstance, MappingRefCount> subscribeMappingsMap = noteMappings.get(pattern);
				if(subscribeMappingsMap == null){
					subscribeMappingsMap = new HashMap<ProcessInstance, MappingRefCount>(4);
					noteMappings.put(pattern, subscribeMappingsMap);
					

					MappingRefCount mrc = new MappingRefCount();
					mrc.nrOfMappings = 1;
					subscribeMappingsMap.put(pi, mrc);
				}else{
					MappingRefCount existingValue = subscribeMappingsMap.get(pi);
					if(existingValue != null){
						existingValue.nrOfMappings++;
					}else{
						MappingRefCount mrc = new MappingRefCount();
						mrc.nrOfMappings = 1;
						subscribeMappingsMap.put(pi, mrc);
					}
				}
			}
		}
	}
	
	public void deregisterSubscribeNote(Subscribe subscribeNote){
		List<ATerm> matches = noteLinks.get(subscribeNote.notePattern);
		Iterator<ATerm> matchesIterator = matches.iterator();
		
		synchronized(noteLock){
			while(matchesIterator.hasNext()){
				ATerm pattern = matchesIterator.next();
				Map<ProcessInstance, MappingRefCount> subscribeMappingsMap = noteMappings.get(pattern);
				
				MappingRefCount mapping = subscribeMappingsMap.get(subscribeNote.getProcess());
				if((--mapping.nrOfMappings) == 0){
					subscribeMappingsMap.remove(mapping);
				}
			}
		}
	}
	
	public Set<ProcessInstance> getPossibleNotePartners(ATerm pattern){
		synchronized(noteLock){
			Map<ProcessInstance, MappingRefCount> subNotesMappings = noteMappings.get(pattern);
			if(subNotesMappings == null) return NONOTEPARTNERS;
			
			return subNotesMappings.keySet();
		}
	}
}
