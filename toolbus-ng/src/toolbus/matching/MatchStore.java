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

/**
 * This store keeps track of all links between sending and receiving communication atoms.
 * 
 * @author Arnold Lankamp
 */
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
	
	/**
	 * Constructor.
	 * 
	 * @param tbTermFactory
	 *            The term factory to use for matching.
	 */
	public MatchStore(TBTermFactory tbTermFactory){
		super();
		
		this.tbFactory = tbTermFactory;
		
		messageLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		noteLinks = new ConcurrentHashMap<ATerm, List<ATerm>>();
		
		messageMappings = new HashMap<ATerm, List<RecMsg>>();
		noteMappings = new HashMap<ATerm, Map<ProcessInstance, MappingRefCount>>();
	}
	
	/**
	 * Initializes this match store with the given set of atoms.
	 * 
	 * @param atomSet
	 *            The complete collection of atoms, for which the relations must to be calculated.
	 */
	public void initialize(List<Atom> atomSet){
		this.atomSet = atomSet;
		
		calculateMatches();
	}
	
	/**
	 * Staticly determains all (potential) relations between the atoms.
	 */
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
	
	/**
	 * Indexes the given receive message atom.
	 * 
	 * @param message
	 *            The receive message atom.
	 * @param receiveMessages
	 *            The list to add the message's match pattern to.
	 */
	private void addReceiveMessagePattern(RecMsg message, List<ATerm> receiveMessages){
		ATerm matchPattern = message.msg;
		receiveMessages.add(matchPattern);
		messageLinks.put(matchPattern, new ArrayList<ATerm>());
	}
	
	/**
	 * Indexes the given send message atom. NOTE: All receive message atoms need to have been added
	 * prior to the invokation of this method, otherwise the the ToolBus may exhibit undefined
	 * runtime behaviour.
	 * 
	 * @param message
	 *            The send message atom.
	 * @param receiveMessages
	 *            The complete list of receive messages.
	 */
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
	
	/**
	 * Indexes the given subscribe atom.
	 * 
	 * @param subscribeNote
	 *            The subscribe atom.
	 * @param subscribeNotes
	 *            The list to add the subscribe's match pattern to.
	 */
	private void addSubscribeNotePattern(Subscribe subscribeNote, List<ATerm> subscribeNotes){
		ATerm matchPattern = subscribeNote.notePattern;
		subscribeNotes.add(matchPattern);
		noteLinks.put(matchPattern, new ArrayList<ATerm>());
	}
	
	/**
	 * Indexes the given send note atom. NOTE: All subscribe atoms need to have been added prior to
	 * the invokation of this method, otherwise the the ToolBus may exhibit undefined runtime
	 * behaviour.
	 * 
	 * @param message
	 *            The send note atom.
	 * @param subscribeNotes
	 *            The complete list of subscribes.
	 */
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
	
	/**
	 * Registers the given, instantiated, receive message atom.
	 * 
	 * @param receiveMessage
	 *            The receive message atom to register.
	 */
	public void registerReceiveMessage(RecMsg receiveMessage){
		List<ATerm> matches = messageLinks.get(receiveMessage.msg);
		if(matches == null) return;
		
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
	
	/**
	 * Deregisteres the given, instantiated, receive message atom.
	 * 
	 * @param receiveMessage
	 *            The receive message atom to deregister.
	 */
	public void deregisterReceiveMessage(RecMsg receiveMessage){
		List<ATerm> matches = messageLinks.get(receiveMessage.msg);
		if(matches == null) return;
		
		Iterator<ATerm> matchesIterator = matches.iterator();
		
		synchronized(messageLock){
			while(matchesIterator.hasNext()){
				ATerm pattern = matchesIterator.next();
				List<RecMsg> receiveMessageList = messageMappings.get(pattern);
				receiveMessageList.remove(receiveMessage);
			}
		}
	}
	
	/**
	 * Gathers the potential partners for the given send message pattern.
	 * 
	 * @param pattern
	 *            The send message pattern.
	 * @return The collections of potentially matching partners.
	 */
	public List<RecMsg> getPossibleMessagePartners(ATerm pattern){
		List<RecMsg> recMessages;
		
		synchronized(messageLock){
			recMessages = messageMappings.get(pattern);
		}
		
		if(recMessages == null) return NOMESSAGEPARTNERS;
		
		return recMessages;
	}
	
	/**
	 * Reference count structure.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class MappingRefCount{
		public int nrOfMappings;
	}
	
	/**
	 * Registers the given, instantiated, subscribe atom.
	 * 
	 * @param subscribeNote
	 *            The subscribe atom to register.
	 */
	public void registerSubscribeNote(Subscribe subscribeNote){
		List<ATerm> matches = noteLinks.get(subscribeNote.notePattern);
		if(matches == null) return;
		
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
	
	/**
	 * Deregisters the given, instantiated, subscribe atom.
	 * 
	 * @param subscribeNote
	 *            The subscribe atom to deregister.
	 */
	public void deregisterSubscribeNote(Subscribe subscribeNote){
		List<ATerm> matches = noteLinks.get(subscribeNote.notePattern);
		if(matches == null) return;
		
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
	
	/**
	 * Gathers the potential partners for the given send note pattern.
	 * 
	 * @param pattern
	 *            The send message pattern.
	 * @return The collections of potentially matching partners.
	 */
	public Set<ProcessInstance> getPossibleNotePartners(ATerm pattern){
		synchronized(noteLock){
			Map<ProcessInstance, MappingRefCount> subNotesMappings = noteMappings.get(pattern);
			if(subNotesMappings == null) return NONOTEPARTNERS;
			
			return subNotesMappings.keySet();
		}
	}
	
	/**
	 * Dumps a list of partnerless communication atoms to standard out.
	 */
	public void printPartnerlessCommunicationAtoms(){
		printPartnerlessSenders();
		printPartnerlessReceivers();
	}
	
	/**
	 * Gathers a list of partnerless message sending atoms.
	 * 
	 * @return A list of partnerless message sending atoms.
	 */
	public List<SndMsg> findPartnerlessSendMessageAtoms(){
		List<SndMsg> deadSendMessageAtoms = new ArrayList<SndMsg>();
		
		List<ATerm> receiveMessages = new LinkedList<ATerm>();

		Iterator<Atom> atomsIteratorForRecMsg = atomSet.iterator();
		while(atomsIteratorForRecMsg.hasNext()){
			Atom atom = atomsIteratorForRecMsg.next();
			if(atom instanceof RecMsg){
				receiveMessages.add(((RecMsg) atom).msg);
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
				
				if(!added) deadSendMessageAtoms.add(sendMessage);
			}
		}
		
		return deadSendMessageAtoms;
	}
	
	/**
	 * Gathers a list of partnerless note sending atoms.
	 * 
	 * @return A list of partnerless note sending atoms.
	 */
	public List<SndNote> findPartnerlessSendNoteAtoms(){
		List<SndNote> deadSendNoteAtoms = new ArrayList<SndNote>();
		
		List<ATerm> subscribeNotes = new LinkedList<ATerm>();

		Iterator<Atom> atomsIteratorForRecMsg = atomSet.iterator();
		while(atomsIteratorForRecMsg.hasNext()){
			Atom atom = atomsIteratorForRecMsg.next();
			if(atom instanceof Subscribe){
				subscribeNotes.add(((Subscribe) atom).notePattern);
			}
		}
		
		Iterator<Atom> atomsIteratorForSndMsg = atomSet.iterator();
		while(atomsIteratorForSndMsg.hasNext()){
			Atom atom = atomsIteratorForSndMsg.next();
			
			if(atom instanceof SndNote){
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
				
				if(!added) deadSendNoteAtoms.add(sendNote);
			}
		}
		
		return deadSendNoteAtoms;
	}
	
	/**
	 * Gathers a list of partnerless message receiving atoms.
	 * 
	 * @return A list of partnerless message receiving atoms.
	 */
	public List<RecMsg> findPartnerLessReceiveMessageAtoms(){
		List<RecMsg> deadReceiveMessageAtoms = new ArrayList<RecMsg>();
		
		Iterator<Atom> atomsIterator = atomSet.iterator();
		while(atomsIterator.hasNext()){
			Atom atom = atomsIterator.next();
			if(atom instanceof RecMsg){
				RecMsg recMsg = (RecMsg) atom;
				
				if(messageLinks.get(recMsg.msg).isEmpty()){
					deadReceiveMessageAtoms.add(recMsg);
				}
			}
		}
		
		return deadReceiveMessageAtoms;
	}
	
	/**
	 * Gathers a list of partnerless subscribe atoms.
	 * 
	 * @return A list of partnerless subscribe atoms.
	 */
	public List<Subscribe> findPartnerlessSubscribeAtoms(){
		List<Subscribe> deadSubscribeAtoms = new ArrayList<Subscribe>();
		
		Iterator<Atom> atomsIterator = atomSet.iterator();
		while(atomsIterator.hasNext()){
			Atom atom = atomsIterator.next();
			
			if(atom instanceof Subscribe){
				Subscribe subscribe = (Subscribe) atom;
				
				if(noteLinks.get(subscribe.notePattern).isEmpty()){
					deadSubscribeAtoms.add(subscribe);
				}
			}
		}
		
		return deadSubscribeAtoms;
	}
	
	/**
	 * Dumps a list of partnerless sending atoms to standard out.
	 */
	private void printPartnerlessSenders(){
		List<SndMsg> deadSendMessageAtoms = findPartnerlessSendMessageAtoms();
		List<SndNote> deadSendNoteAtoms = findPartnerlessSendNoteAtoms();
		
		List<Atom> deadSendAtoms = new ArrayList<Atom>();
		deadSendAtoms.addAll(deadSendMessageAtoms);
		deadSendAtoms.addAll(deadSendNoteAtoms);
		
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
	
	/**
	 * Dumps a list of partnerless receiving atoms to standard out.
	 */
	private void printPartnerlessReceivers(){
		List<RecMsg> partnerlessReceiveMessageAtoms = findPartnerLessReceiveMessageAtoms();
		List<Subscribe> partnerlessSubscribeAtoms = findPartnerlessSubscribeAtoms();
		
		List<Atom> partnerlessReceivers = new ArrayList<Atom>();
		partnerlessReceivers.addAll(partnerlessReceiveMessageAtoms);
		partnerlessReceivers.addAll(partnerlessSubscribeAtoms);
		
		if(partnerlessReceivers.size() == 0){
			System.out.println("No partnerless receivers found.");
		}else{
			System.out.println("Partnerless receive atoms:");
			System.out.println("{");
			
			Iterator<Atom> partnerlessReceiversIterator = partnerlessReceivers.iterator();
			while(partnerlessReceiversIterator.hasNext()){
				Atom atom = partnerlessReceiversIterator.next();
				
				System.out.println("\t"+atom.getPosInfo()+"\t\t: "+atom);
			}
			
			System.out.println("}");
		}
	}
}
