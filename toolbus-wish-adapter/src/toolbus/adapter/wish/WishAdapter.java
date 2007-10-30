package toolbus.adapter.wish;

import java.net.InetAddress;

import aterm.ATerm;
import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;

public class WishAdapter extends AbstractTool{
	private ToolBridge toolBridge = null;
	
	public WishAdapter(){
		super();
	}
	
	public void connect(String[] args) throws Exception{
		String type = null;

		String toolName = null;
		int toolID = -1;

		InetAddress host = null;
		int port = -1;

		for(int i = 0; i < args.length; i++){
			String arg = args[i];
			if(arg.equals("-TYPE")){
				type = args[++i];
			}else if(arg.equals("-TB_TOOL_NAME")){
				toolName = args[++i];
			}else if(arg.equals("-TB_TOOL_ID")){
				toolID = Integer.parseInt(args[++i]);
			}else if(arg.equals("-TB_HOST")){
				host = InetAddress.getByName(args[++i]);
			}else if(arg.equals("-TB_PORT")){
				port = Integer.parseInt(args[++i]);
			}
		}

		if(type == null || toolName == null) throw new RuntimeException("Missing tool identification.");

		toolBridge = new WishAdapterBridge(type, this, toolName, toolID, host, port);
		toolBridge.run();
	}
	
	public void receiveTerminate(ATerm aTerm){
		// TODO Implement.
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// TODO Implement.
	}
	
	public static void main(String[] args){
		WishAdapterBridge wishAdapterBridge = new WishAdapterBridge(null, null, null, 0, null, 0); // Temp
	}
}
