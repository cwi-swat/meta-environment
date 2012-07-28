package nl.cwi.bus.client.test;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.term.serializable.SerializableStringTerm;

/**
 * A dummy client application / tool
 * 
 * @author Arnold Lankamp
 */
public class Client extends Thread implements ITool{
	private ToolBridge toolBridge = null;

	/**
	 * Default constructor
	 */
	public Client(){
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

	/**
	 * Sends a message
	 */
	public void run(){
		try{
			toolBridge.send(new SerializableStringTerm("string(test)"));
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	
	/**
	 * Called when a tool is requested to shut down.
	 */
	public void terminate(){
		//Do nothing, this is just a notification
	}

	/**
	 * Entrypoint
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception{
		Client clientApp = new Client();
		Thread.sleep(1000);
		clientApp.start();
	}
}
