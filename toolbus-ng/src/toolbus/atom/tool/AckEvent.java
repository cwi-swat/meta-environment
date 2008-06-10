package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * @author paulk, Jul 31, 2002
 */
public class AckEvent extends Atom{
	private final Ref toolId;
	private final Ref event;
	private final Ref callbackData;
	private ToolInstance toolInstance;
	
	public AckEvent(ATerm toolId, ATerm event, ATerm callbackData, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.event = new Ref(event);
		this.callbackData = new Ref(callbackData);
		setAtomArgs(new Ref[]{this.toolId, this.event});
		externalNameAsReceivedByTool = "rec-ack-event";
	}
	
	public ProcessExpression copy(){
		Atom a = new AckEvent(toolId.value, event.value, callbackData.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	public void activate(){
		toolInstance = null;
		super.activate();
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		if(toolInstance == null){
			ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
			toolInstance = getToolBus().getToolInstanceManager().get(tid);
			if(toolInstance == null) return false;
		}
		
		// Construct an ack appl with the right amount of arguments.
		AFun ackFun = ((ATermAppl) event.value).getAFun();
		int arity = ackFun.getArity();
		ATerm[] arguments = new ATerm[arity];
		for(int i = 0; i < arity; i++){
			arguments[i] = tbfactory.EmptyList;
		}
		ATermAppl ackAppl = tbfactory.makeAppl(ackFun, arguments);
		
		// Get the callback data if present.
		ATerm callbackTerm = callbackData.value;
		if(callbackTerm == null){
			callbackTerm = tbfactory.EmptyList;
		}else{
			callbackTerm = tbfactory.fullSubstitute(callbackTerm, getEnv());
			if(callbackTerm == null) throw new ToolBusException("Illegal callback term pattern: "+callbackTerm+".");
		}
		
		// Construct the ack event.
		ATermList ackEvent = tbfactory.makeList();
		ackEvent = ackEvent.insert(callbackTerm);
		ackEvent = ackEvent.insert(ackAppl);
		
		toolInstance.sendAckEvent(ackEvent);
		
		//LoggerFactory.log(this.getProcess().getProcessName(), "AckEvent " + event.value, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
}
