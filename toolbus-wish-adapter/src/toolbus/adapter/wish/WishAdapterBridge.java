package toolbus.adapter.wish;

import java.net.InetAddress;

import toolbus.adapter.ToolBridge;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class WishAdapterBridge extends ToolBridge{
	private final WishAdapter wishAdapter;
	
	public WishAdapterBridge(String type, WishAdapter tool, String toolName, int toolID, InetAddress host, int port){
		super(type, tool, toolName, toolID, host, port);
		
		wishAdapter = tool;
	}
	
	public boolean checkSignature(ATerm signatures){
		// TODO Can't be bothered to implement.
		return true;
	}
	
	public void receive(byte operation, ATerm aTerm){
		switch(operation){
			case DO:
				wishAdapter.receiveDo(aTerm);
				send(ACKDO, getFactory().makeList());
				break;
			case EVAL:
				ATerm result = wishAdapter.receiveEval(aTerm);
				send(VALUE, result);
				break;
			case PERFORMANCESTATS:
				PureFactory factory = getFactory();
				ATerm unsupportedOperation = factory.make("unsupported-operation");
				ATerm performanceStats = factory.makeAppl(factory.makeAFun("performance-stats", 3, false), unsupportedOperation, unsupportedOperation, unsupportedOperation);
				send(PERFORMANCESTATS, performanceStats);
				break;
			default:
				super.receive(operation, aTerm);
		}
	}
}
