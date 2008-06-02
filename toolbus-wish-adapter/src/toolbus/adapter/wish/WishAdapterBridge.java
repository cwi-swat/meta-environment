package toolbus.adapter.wish;

import java.net.InetAddress;

import toolbus.adapter.ToolBridge;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class WishAdapterBridge extends ToolBridge{
	private final WishAdapter wishAdapter;
	
	public WishAdapterBridge(PureFactory termFactory, WishAdapter tool, String toolName, int toolID, InetAddress host, int port){
		super(termFactory, toolName, toolID, host, port);
		
		wishAdapter = tool;
	}
	
	public boolean checkSignature(ATerm signatures){
		// TODO Can't be bothered to implement.
		return true;
	}
	
	public void doDo(ATerm aTerm){
		wishAdapter.receiveDo(aTerm);
	}
	
	public ATerm doEval(ATerm aTerm){
		return wishAdapter.receiveEval(aTerm);
	}
	
	public ATerm doGetPerformanceStats(){
		PureFactory factory = getFactory();
		ATerm unsupportedOperation = factory.make("unsupported-operation");
		ATerm performanceStats = factory.makeAppl(factory.makeAFun("performance-stats", 3, false), unsupportedOperation, unsupportedOperation, unsupportedOperation);
		return performanceStats;
	}
	
	public void doReceiveAckEvent(ATerm aTerm){
		wishAdapter.receiveAckEvent(aTerm);
	}
	
	public void doTerminate(ATerm aTerm){
		wishAdapter.receiveTerminate(aTerm);
	}
}
