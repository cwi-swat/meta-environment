package nl.cwi.bus.client.test;

import java.net.InetAddress;
import java.net.InetSocketAddress;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.config.Config;
import nl.cwi.bus.variable.Variable;
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
			Variable v = new Variable(new SerializableStringTerm("string(test)"), new InetSocketAddress(InetAddress.getLocalHost(), Config.getUsingPort()), 1);
			PutOperation po = PutOperation.create(v);
			toolBridge.send(po);
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
