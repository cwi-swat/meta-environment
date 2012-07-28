package nl.cwi.bus.client.test;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.term.serializable.SerializableStringTerm;

public class SpamAcceptingClient implements ITool{
	private ToolBridge toolBridge = null;

	public SpamAcceptingClient(){
		super();

		init();
	}

	/**
	 * Initializes the client
	 */
	private void init(){
		toolBridge = ToolRegistery.getInstance().createBridge(this);
		toolBridge.start();
	}
	long total = 0;
	public void string(SerializableStringTerm string){
		// Print timestamp
		//System.out.println("Received: "+System.currentTimeMillis());
		total += System.currentTimeMillis();
		System.out.println(total);
	}

	/**
	 * Called when a tool is requested to shut down.
	 */
	public void terminate(){
		toolBridge.stopRunning();
	}

	/**
	 * Entrypoint
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception{
		new SpamAcceptingClient();
	}
}
