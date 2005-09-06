 package toolbus.tool;

import java.util.Hashtable;
import java.util.LinkedList;
import java.util.List;

import toolbus.Environment;
import toolbus.TBTerm;
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
 
  private static int toolCount = 0; // global counter of tool instances
  private ATerm toolId;				// id of current tool: toolname(<int>)
  
  private LinkedList valuesFromTool;
  private LinkedList eventsFromTool;
  private LinkedList pendingEvents;  // ???
  
  private ToolShield toolShield;     // The ToolShield that handles this tool

  protected static final Integer EVAL = new Integer(1);
  protected static final Integer DO = new Integer(2);
  protected static final Integer TERMINATE = new Integer(3);
  public static final String[] OperatorForTool = {"dummy", "rec-eval", "rec-do", "rec-terminate"};
  
  public final int a_snd_connect = 0;
  public final int a_snd_disconnect = 1;
  public final int a_rec_terminate = 2;
  
  public final int a_rec_eval = 3;
  public final int a_snd_value = 4;
  public final int a_rec_cancel = 5;
  
  public final int a_rec_do = 6;
  public final int a_snd_void = 7;
  
  public final int a_snd_continue = 8;
  public final int a_snd_event = 9;
  public final int a_rec_ack_event = 10;
  
  String [] toolRequestAtoms = {
  		"connect", "disconnect", "terminate",
		"eval", "value", "cancel",
		"do", "void",
		"event", "ack_event",	
  };
  
  Hashtable reverseRole = new Hashtable();
  Hashtable toolRequestIndex = new Hashtable();
  
  ATerm termSndVoid;

  /**
   * Construct a ToolInstance. 
   * 
   * @param toolDefinition definition of the tool
   */

  public ToolInstance(ToolDefinition toolDef) throws ToolBusException {
    System.err.println("ToolInstance");
    valuesFromTool = new LinkedList();
    eventsFromTool = new LinkedList();
    pendingEvents = new LinkedList();
    
	for(int i = 0; i < toolRequestAtoms.length; i++){
		String s = toolRequestAtoms[i];
		reverseRole.put( "snd-" + s, "rec-" + s);
		reverseRole.put( "rec-" + s, "snd-" + s);
	}
	toolRequestIndex.put("snd-connect", new Integer(a_snd_connect));
	toolRequestIndex.put("snd-disconnect", new Integer(a_snd_disconnect));
	toolRequestIndex.put("rec-terminate", new Integer(a_rec_terminate));
	
	toolRequestIndex.put("rec-eval", new Integer(a_rec_eval));
	toolRequestIndex.put("snd-value", new Integer(a_snd_value));
	toolRequestIndex.put("rec-cancel", new Integer(a_rec_cancel));
	
	toolRequestIndex.put("rec-do", new Integer(a_rec_do));
	toolRequestIndex.put("snd-void", new Integer(a_snd_void));

	toolRequestIndex.put("snd-continue", new Integer(a_snd_continue));
	toolRequestIndex.put("snd-event", new Integer(a_snd_event));
	toolRequestIndex.put("rec-ack-event", new Integer(a_rec_ack_event));
	
	termSndVoid = TBTerm.factory.parse("snd-void");
	
    AFun afun = TBTerm.factory.makeAFun(toolDef.getName(), 1, false);
    toolId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(toolCount++));

    toolShield = toolDef.makeToolShield(this);
    toolShield.start();
    while(!toolShield.isRunning()){ //TODO Maybe another solution to force the completion of the tool connection?
    	try{
  	      Thread.sleep(100);
  	      }
  	      catch(InterruptedException e){
  	      System.out.println("Sleep Interrupted");
  	      }
    }
  }

  public ATerm getToolId(){
  	return toolId;
  }
  
  public int getToolCount(){
  	return toolCount;
  }
  
  /**
   * Send an evaluation request to the ToolShield when evaluating the SndEval atom.
   * The answer will be returned by the ToolShield using addValueFromTool.
 * @return boolean
   */

  synchronized public boolean sndEvalToTool(ATermAppl call) {
  	if (TCPtransition(a_rec_eval, call, true)){
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
   * of the RecValue atom calls getValueFromTool (below)
   * @param res the tresult returned by the tool
   */

  synchronized public void addValueFromTool(Object res) {
    valuesFromTool.addLast(res);
    System.err.println("ToolInstance.addValue: " + toolId + " res = " + res);
  }
  
  /**
   * Retrieve a value obtained from the ToolShield to the ToolBus while evaluating
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
  			if (TCPtransition(a_snd_value, trm, true)){
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

  /**
   * Send a do request to the tool while evaluating the SndDo atom.
   * The answer will be returned by the ToolShield using addValueFromTool.
   * @return TODO
   */

  synchronized public boolean sndDoToTool(ATermAppl call) {
 	if (TCPtransition(a_rec_do, call, true)){
 		//System.err.println("sndDoToTool: true case");
 		toolShield.sndRequestToTool(DO, call);
 		return true;
 	} else {
		//System.err.println("sndDoToTool: false case");
 		return false;
 	}
  }
  
  /**
   * Pass an event obtained from the ToolShield to the ToolBus
   * 
   * @see toolbus.tool.ToolInstance#getEventFromTool(ATerm, Environment)
   */

  synchronized public boolean getEventFromTool(ATerm trm, Environment env) {
    //System.err.println("getEventFromTool: " + " " + trm);
    for (int i = 0; i < eventsFromTool.size(); i++) {
      try {
        Object event[] = (Object[]) eventsFromTool.get(i);
        //ATerm eventId = (ATerm) event[0];
        ATerm eventTerm = (ATerm) event[1];
        boolean matches = TBTerm.match(trm, env, eventTerm, new Environment());
        //System.err.println(matches + " " + eventId + eventTerm);
        if (matches) {
          //env.assignVar(id, eventId);
          eventsFromTool.remove(i);
          pendingEvents.addLast(eventTerm);
          return true;
        }
      } catch (ToolBusException e) {
        System.err.println("getEventFromTool: cannot happen :-)");
      }
    }
    //System.err.println("getEventFromTool returns false");
    return false;
  }
  
  /** 
   * addEventFromTool adds an event generated by the tool to eventsFromTool
   * @param obj generated by tool
   */

  synchronized public ATerm addEventFromTool(Object obj) {
    Object event[] = new Object[] { TBTerm.newTransactionId(), obj };
    eventsFromTool.addLast(event);
    System.err.println("ToolInstance.addEvenFromTool: id = " + event[0] + " obj= = " + event[1]);
    return (ATerm) event[0];
  }
 
  /**
   * Send an acknowledgement to a previous event
   */

  synchronized public void sndAckToTool(ATerm eventTerm) throws ToolBusException {
    //System.err.println("sndAckToTool:" + eventTerm);
    int eventindex = pendingEvents.indexOf(eventTerm);
    if (eventindex < 0 ) {
      throw new ToolBusException("cannot acknowledge event: " + eventTerm);
    }
    AFun afun = TBTerm.factory.makeAFun("ackEvent", 1, false);
    ATermList args = TBTerm.factory.makeList(eventTerm);
    ATermAppl call = TBTerm.factory.makeAppl(afun, args);
    toolShield.sndRequestToTool(DO, call);
  }

  /**
   * Terminate the execution of this tool.
   * @see toolbus.tool.ToolInstance#terminate(String)
   */
  public void terminate(String msg){
  	System.err.println("ToolInstance.terminate: " + toolId);
  	toolShield.terminate(msg);
  }
  
  public synchronized void handleTermFromTool(ATerm t) {	
  		System.err.println("tool " + toolId + " handling term from tool: " + t);
  		
  		if(t.isEqual(termSndVoid)){
  			TCPtransition(a_snd_void, null, true);
  			return;
  		}
  		
  		List matches = t.match("snd-value(<term>)"); //TODO; more args
  		if (matches != null) {
  			addValueFromTool(matches.get(0));  
  		}
  		
  		List matches1 = t.match("snd-event(<term>,<term>)"); //TODO: more args
  		if (matches1 != null) {
  			addEventFromTool(matches1.get(1));
  		}
  		System.err.println("tool " + toolId + " not handled!");
  }
  
  /**
   * Transition function for the Tool Control Protocol, the protocol that governs 
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
  
  public boolean TCPtransition(int ri, ATerm term, boolean update) {
  	
  	//String requestName = ((ATermAppl) request).getName();
  	//int ri = ((Integer) toolRequestIndex.get(requestName)).intValue();
  	//System.err.println("TCPtransition: phase = " + phase + "; ri = " + ri);
  	
  	switch(phase){
  	case PHASE1:
  		if(ri == a_snd_connect) {
  			phase = PHASE2;
  			return true;	
  		} else {
  			return false;
  		}
  		
  	case PHASE2:
  		switch(ri){
  		case a_rec_do:
  		case a_rec_eval:
  			phase = PHASE3;
  			return true;
  			
  		case a_rec_terminate:
  		case a_snd_continue:
  			phase = PHASE2;
  			return true;
  			
  		case a_snd_event:
  			// TODO
  			phase = PHASE2;
  			return true;
  		case a_rec_ack_event:
  			// TODO
  		case a_snd_disconnect:
  			phase = PHASE1;
  			return true;
  		case a_rec_cancel:
  		case a_snd_value:
  		case a_snd_connect:
  			return false;
  		default:
  			// ERROR
  		}
  		
  	case PHASE3:
  		switch(ri){
  		case a_rec_cancel:
  		case a_snd_void:
  		case a_snd_value:
  			phase = PHASE2;
  			return true;
  		case a_snd_continue:
  		case a_rec_terminate:
  			phase = PHASE3;
  			return true;
  		case a_snd_event:
  			// TODO
  		case a_rec_ack_event:
  			// TODO
  		case a_rec_eval:
  		case a_rec_do:
  		case a_snd_connect:
  		case a_snd_disconnect:
  			return false;
  		default:
  			// ERROR	
  		}
  	default:
  		// ERROR
  		
  	}
  	return false;
  }
  
}
