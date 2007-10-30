package toolbus.adapter.wish;

import java.net.InetAddress;

import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import aterm.ATerm;

public class WishAdapterBridge extends ToolBridge{
	
	public WishAdapterBridge(String type, AbstractTool tool, String toolName, int toolID, InetAddress host, int port){
		super(type, tool, toolName, toolID, host, port);
	}
	
	public void receive(byte operation, ATerm aTerm){
		switch(operation){
			case DO:
				// TODO Implement
				send(ACKDO, getFactory().makeList());
				break;
			case EVAL:
				ATerm result = null;
				// TODO Implement
				send(VALUE, result);
				break;
			default:
				super.receive(operation, aTerm);
		}
	}
}
