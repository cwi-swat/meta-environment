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
import toolbus.atom.note.RecNote;
import toolbus.atom.note.SndNote;
import toolbus.atom.note.Subscribe;
import toolbus.process.ProcessInstance;
import toolbus.util.collections.ConcurrentHashMap;
import toolbus.util.collections.ConcurrentHashMap.ReadOnlyHashMapEntryHandler;
import aterm.ATerm;

public class MatchStore{
	private final static List<RecMsg> NOMESSAGEPARTNERS = new ArrayList<RecMsg>(0);
	private final static Set<ProcessInstance> NONOTEPARTNERS = new HashSet<ProcessInstance>(0);
	
	private final TBTermFactory tbFactory;
	private volatile List<Atom> atomSet;
	
	private final ConcurrentHashMap<ATerm, List<ATerm>> messageLinks;
	private final ConcurrentHashMap<ATerm, List<ATerm>> noteLinks;
	
	private final Map<ATerm, List<RecMsg>> messageMappings;
	private final Map<ATerm, Map<ProcessInstance, MappingRefCount>> noteMappings;
	
	private final Object messageLock = new Object();
	private final Object noteLock = new Object();
	
	public MatchStore(TBTermFactory tbTermFactory){
		super();
		
		this.tbFactory = tbTermFactory;
		
		messageLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		noteLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		
		messageMappings = new HashMap<ATerm, List<RecMsg>>();
		noteMappings = new HashMap<ATerm, Map<ProcessInstance, MappingRefCount>>();
	}
	
	public void intialize(List<Atom> atomSet){
		this.atomSet = atomSet;
		
		calculateMatches();
	}
	
	private void calculateMatches(){
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
	
	public void printPartnerlessCommunicationAtoms(){
		printPartnerlessSenders();
		printPartnerlessReceivers();
	}
	
	private void findDeadReceiveAtoms(List<Atom> deadSendAtoms){
		List<ATerm> receiveMessages = new LinkedList<ATerm>();
		List<ATerm> subscribeNotes = new LinkedList<ATerm>();

		Iterator<Atom> atomsIteratorForRecMsg = atomSet.iterator();
		while(atomsIteratorForRecMsg.hasNext()){
			Atom atom = atomsIteratorForRecMsg.next();
			if(atom instanceof RecMsg){
				receiveMessages.add(((RecMsg) atom).msg);
			}else if(atom instanceof Subscribe){
				subscribeNotes.add(((Subscribe) atom).notePattern);
			}
		}
		
		Iterator<Atom> atomsIteratorForSndMsg = atomSet.iterator();
		while(atomsIteratorForSndMsg.hasNext()){
			Atom atom = atomsIteratorForSndMsg.next();
			if(atom instanceof SndMsg){
				SndMsg sendMessage = (SndMsg) atom;
				ATerm matchPattern = sendMessage.msg;
				
				boolean added = false;
				
				Iterator<ATerm> receiveMessagePatternIterator = receiveMessages.iterator();
				while(receiveMessagePatternIterator.hasNext()){
					ATerm receiveMessagePattern = receiveMessagePatternIterator.next();
					
					if(tbFactory.mightMatch(matchPattern, receiveMessagePattern)){
						added = true;
						break;
					}
				}
				
				if(!added) deadSendAtoms.add(sendMessage);
			}else if(atom instanceof SndNote){
				SndNote sendNote = (SndNote) atom;
				ATerm matchPattern = sendNote.notePattern;

				boolean added = false;
				
				Iterator<ATerm> subscribeNotePatternIterator = subscribeNotes.iterator();
				while(subscribeNotePatternIterator.hasNext()){
					ATerm subscribeNotePattern = subscribeNotePatternIterator.next();
					
					if(tbFactory.mightMatch(matchPattern, subscribeNotePattern)){
						added = true;
						break;
					}
				}
				
				if(!added) deadSendAtoms.add(sendNote);
			}
		}
	}
	
	private void printPartnerlessSenders(){
		List<Atom> deadSendAtoms = new ArrayList<Atom>();
		findDeadReceiveAtoms(deadSendAtoms);
		
		Set<Atom> partnerlessAtoms = new HashSet<Atom>();
		
		Iterator<Atom> deadSendAtomsIterator = deadSendAtoms.iterator();
		while(deadSendAtomsIterator.hasNext()){
			partnerlessAtoms.add(deadSendAtomsIterator.next());
		}
		
		if((partnerlessAtoms.size()) == 0){
			System.out.println("No partnerless send atoms found.");
		}else{
			System.out.println("Partnerless send atoms:");
			System.out.println("{");
			
			Iterator<Atom> partnerlessMessagesIterator = partnerlessAtoms.iterator();
			while(partnerlessMessagesIterator.hasNext()){
				Atom sendAtom = partnerlessMessagesIterator.next();
				System.out.println("\t"+sendAtom.getPosInfo()+"\t\t: "+sendAtom);
			}
			
			System.out.println("}");
		}
	}
	
	private void printPartnerlessReceivers(){
		final Set<ATerm> partnerlessMessages = new HashSet<ATerm>();
		final Set<ATerm> partnerlessNotes = new HashSet<ATerm>();
		
		messageLinks.iterate(new ReadOnlyHashMapEntryHandler<ATerm, List<ATerm>>(){
			public int handle(ATerm receiveMessage, List<ATerm> value){
				if(messageLinks.get(receiveMessage).isEmpty()){
					partnerlessMessages.add(receiveMessage);
				}
				
				return CONTINUE;
			}
		});

		noteLinks.iterate(new ReadOnlyHashMapEntryHandler<ATerm, List<ATerm>>(){
			public int handle(ATerm receiveNote, List<ATerm> value){
				if(noteLinks.get(receiveNote).isEmpty()){
					partnerlessNotes.add(receiveNote);
				}
				
				return CONTINUE;
			}
		});
		
		if((partnerlessMessages.size() + partnerlessNotes.size()) == 0){
			System.out.println("No partnerless receivers found.");
		}else{
			System.out.println("Partnerless receive atoms:");
			System.out.println("{");
			
			Iterator<Atom> atomsIterator = atomSet.iterator();
			while(atomsIterator.hasNext()){
				Atom atom = atomsIterator.next();
				if(atom instanceof RecMsg){
					if(partnerlessMessages.contains(((RecMsg) atom).msg)) System.out.println("\t"+atom.getPosInfo()+"\t\t: "+atom);
				}else if(atom instanceof RecNote){
					if(partnerlessMessages.contains(((RecNote) atom).notePattern)) System.out.println("\t"+atom.getPosInfo()+"\t\t: "+atom);
				}
			}
			
			System.out.println("}");
		}
	}
}
