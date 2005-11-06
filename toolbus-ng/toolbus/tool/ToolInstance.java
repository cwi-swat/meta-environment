 package toolbus.tool;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.LinkedList;
import java.util.List;

import toolbus.Environment;
import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * @author paulk, Jul 29, 2002
 * 
 * Tool Instance creates the environment for running an arbitrary tool.
 * This includes:
 * - creating a ToolShield to run the actual tool.
 * - managing the Tool Control Protocol
 */

public class ToolInstance {
  private ToolDefinition toolDef;
  private ToolBus toolbus;
 
  private int toolCount = 0;        // id of current tool as integer
  private ATerm toolId;				// id of current tool: toolname(<int>)
  
  private LinkedList valuesFromTool;
  private LinkedList eventsFromTool;
  private LinkedList pendingEvents;
  
  private ToolShield toolShield;     // The ToolShield that handles this tool

  public static final Integer EVAL = new Integer(1);
  public static final Integer DO = new Integer(2);
  public static final Integer ACK = new Integer(3);
  public static final Integer TERMINATE = new Integer(4);
  
  public static final String[] OperatorForTool = {"dummy", "rec-eval", "rec-do", "rec-ack-event", "rec-terminate"};
  
  ATerm termSndVoid;

  /**
   * Construct a ToolInstance. 
 * @param myToolBus TODO
 * @param toolDefinition definition of the tool
   */

  public ToolInstance(ToolDefinition toolDef, ToolBus myToolBus, int toolCount, boolean alreadyExecuting) throws ToolBusException {
    System.err.println("ToolInstance");
    this.toolDef = toolDef;   
    this.toolbus = myToolBus;
    this.toolCount = toolCount;
    valuesFromTool = new LinkedList();
    eventsFromTool = new LinkedList();
    pendingEvents = new LinkedList();
	
	termSndVoid = TBTerm.factory.parse("snd-void");
	
    AFun afun = TBTerm.factory.makeAFun(toolDef.getName(), 1, false);
 
    toolId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(toolCount));

    toolShield = toolDef.makeToolShield(this,alreadyExecuting);
  }
  
  public ToolInstance(ToolDefinition toolDef, ToolBus myToolBus, int toolCount) throws ToolBusException {
  	this(toolDef, myToolBus, toolCount, false);
  }

  public ATerm getToolId(){
  	return toolId;
  }
  
  public int getToolCount(){
  	return toolCount;
  }
  
  public String getToolName(){
  	return toolDef.getName();
  }
  
  public void connect(InputStream in, OutputStream out) throws IOException {
  	toolShield.connect(in, out);
  	toolShield.start();
  }
  
  /**
   * Handle any term that comes from the tool.
   * @param t 
   */
  public synchronized void handleTermFromTool(ATerm t) {	
		//System.err.println("tool " + toolId + " handling term from tool: " + t);
		
		if(t.isEqual(termSndVoid)){
			TCP_goConnected();
			return;
		}
		
		List matches = t.match("snd-value(<term>)"); //TODO; more args
		if (matches != null) {
			addValueFromTool(matches.get(0)); 
			return;
		}
		
		matches = t.match("snd-event(<term>)");
		if (matches != null) {
			ATerm t1 = (ATerm) matches.get(0);
			addEventFromTool(TBTerm.factory.makeList(t1));
			return;
		}
		matches = t.match("snd-event(<term>,<term>)"); //TODO: more than 2 args
		if (matches != null) {
			ATerm t1 = (ATerm) matches.get(0);
			ATerm t2 = (ATerm) matches.get(1);
			
			addEventFromTool(TBTerm.factory.makeList(t1, TBTerm.factory.makeList(t2)));
			return;
		}
		// connect
		// disconnect
		System.err.println("tool " + toolId + " not handled!");
}
  /*
   * Implementation of Eval
   * 
   */
  
  /**
   * ToolBus sends an evaluation request to the tool when evaluating the SndEval atom.
   * The answer will be returned by the ToolShield using addValueFromTool.
   * @return boolean
   */

  synchronized public boolean sndEvalToTool(ATermAppl call) {
  	if (TCP_goEvalDo()){
  		System.err.println("sndEvalToTool: true case");
  		toolShield.sndRequestToTool(EVAL, call);
  		return true;
  	} else {
  		System.err.println("sndEvalToTool: false case");
  		return false;
  	}
  }
  
  /**
   * addValueFromTool is called by ToolShield to add a value returned by the tool 
   * to valuesFromTool. It is eventually passed on to the ToolBus, when evaluation
   * of the RecValue atom calls getValueFromTool.
   * @param res the tresult returned by the tool
   */

  synchronized public void addValueFromTool(Object res) {
    valuesFromTool.addLast(res);
    System.err.println("ToolInstance.addValue: " + toolId + " res = " + res);
  }
  
  /**
   * ToolBus retrieves a value obtained from the tool while evaluating
   * the RecValue atom.
   * @param trm the term returned by the tool
   * @param env the local environment of the RecValue atom
   */

  synchronized public boolean getValueFromTool(ATerm trm, Environment env)
  throws ToolBusException {
  	//System.err.println("getValueFromTool " + toolId + ": " + trm);
  	if (valuesFromTool.isEmpty()) {
  		return false;
  	} else {
  		ATerm result = (ATerm) valuesFromTool.getFirst();
  		boolean matches = TBTerm.match(trm, env, result, new Environment());
  		if (matches) {
  			if (TCP_goConnected()){
  				valuesFromTool.removeFirst();
  				return true;
  			} else {
  				return false;
  			}
  		} else {
  			return false;
  		}
  	}
  }
  
  /*
  * Implementation of Do
  */

  /**
   * ToolBus sends a do request to the tool while evaluating the SndDo atom.
   * The answer (SndVoid) will be returned by the ToolShield using addValueFromTool.
   * @return TODO
   */

  synchronized public boolean sndDoToTool(ATermAppl call) {
 	if (TCP_goEvalDo()){
 		//System.err.println("sndDoToTool: true case");
 		toolShield.sndRequestToTool(DO, call);
 		return true;
 	} else {
		//System.err.println("sndDoToTool: false case");
 		return false;
 	}
  }
  
  /*
   * Implementation of Events
   */
  
  /**
   * ToolBus receives an event while evaluating the RecEvent atom.
   * 
   * @see toolbus.tool.ToolInstance#getEventFromTool(ATerm, Environment)
   */

  synchronized public boolean getEventFromTool(ATermList alist, Environment env) {
    //System.err.println("getEventFromTool: " + " " + trm);
    for (int i = 0; i < eventsFromTool.size(); i++) {
      try {
        ATermList eventArgs = (ATermList) eventsFromTool.get(i);
        boolean matches = TBTerm.match(alist, env, eventArgs, new Environment());
        System.err.println(matches + " " + eventArgs);
        if (matches) {
          if(ackWaiting(eventArgs.getFirst())){
          	return false;
          } else {
          	eventsFromTool.remove(i);
          	pendingEvents.addLast(eventArgs);
            System.err.println("pendingEvents.size = " + pendingEvents.size());
          	return true;
          }
        }
      } catch (ToolBusException e) {
        System.err.println("getEventFromTool: cannot happen :-)");
      }
    }
    //System.err.println("getEventFromTool returns false");
    return false;
  }
  
  private boolean ackWaiting(ATerm key){
    for (int i = 0; i < pendingEvents.size(); i++) {
        ATermList eventArgs = (ATermList) pendingEvents.get(i);
        ATerm keyEvent = eventArgs.getFirst();
        if(key == keyEvent)
        	return true;
    }
    return false;
  }
  
  private boolean ackPossible(ATerm key){
    for (int i = 0; i < pendingEvents.size(); i++) {
        ATermList eventArgs = (ATermList) pendingEvents.get(i);
        ATerm keyEvent = eventArgs.getFirst();
        System.err.println("eventArgs " + eventArgs);
        if(key == keyEvent){
        	pendingEvents.remove(i);
        	return true;
        }
    }
    return false;
  }
  
  /** 
   * addEventFromTool adds an event generated by the tool to the the eventsFromTool list
   * @param obj generated by tool
   */

  public void addEventFromTool(Object obj) {
    eventsFromTool.addLast(obj);
    System.err.println("ToolInstance.addEvenFromTool: obj = " + obj);
    synchronized (toolbus) {
    	toolbus.notifyAll();
	}
  }
 
  /**
   * ToolBus sends an acknowledgement to a previous event while executing the AckEvent atom.
   */

  synchronized public boolean sndAckToTool(ATerm eventTerm) throws ToolBusException {
    System.err.println("sndAckToTool:" + eventTerm);
    if (!ackPossible(eventTerm)) {
      return false;
    }
    toolShield.sndRequestToTool(ACK, eventTerm);
    return true;
  }

  /**
   * ToolBus terminates the execution of this tool while executing the Terminate atom.
   * @see toolbus.tool.ToolInstance#terminate(String)
   */
  public void terminate(String msg){
  	System.err.println("ToolInstance.terminate: " + toolId);
  	toolShield.terminate(msg);
  }
  
  /**
   * Transition functions for the Tool Control Protocol, the protocol that governs 
   * the ToolBus/tool communications (Not to be confused with the TCP/IP protocol!)
   * 
   * Note that the protocol is defined from the perspective of the *tool*, i.e., 
   * we use snd_value rather than rec_value.
   * event: the event 
   * update: true => update toolinstance, false => leave toolinstance unchanged
   * 
   * Returns: PHASE1, PHASE2, PHASE3 when legal transition -1 for illegal
   * transition
   * 
   * Note there is one deviation from the "official" TCP protocol. Similar to
   * the rec-eval/snd-value pair we introduce a new message snd-void to form the
   * pair rec-do/snd-void. Motivation: to avoid buffer overflow in the operating
   * system's kernel when *many* do's are being sent to the same tool.
   */
  
  
  private int phase = PHASE1;
  
  private static final int PHASE1 = 1; // unconnected
  private static final int PHASE2 = 2; // connected, start state
  private static final int PHASE3 = 3; // snd-eval received;
  
  public boolean unConnected() {
  	return phase == PHASE1;
  }
  
  public boolean TCP_goConnected(){
  	if(phase == 1 || phase == 3){
  		phase = PHASE2;
  		return true;
  	} else {
  		return false;
  	}
  }
  
  public boolean TCP_goDisConnected(){
  	phase = PHASE1;
  	return true;
  }
  
  public boolean TCP_goEvalDo(){
  	if(phase == PHASE2){
  		phase = PHASE3;
  		return true;
  	} else {
  		return false;
  	}
  }
}

