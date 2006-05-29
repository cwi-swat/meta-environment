package nl.cwi.bus.client.test;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.term.serializable.SerializableStringTerm;

public class SpamClient implements ITool{
	private ToolBridge toolBridge = null;

	public SpamClient(){
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
	
	public String generateRandomString(){
		StringBuilder randomStringBuilder = new StringBuilder();
		
		int length = 5000000;
		byte[] randomBytes = new byte[length];
		for(int i = 0; i < length; i++){
			randomBytes[i] = (byte)(Math.random() * 57 + 65);
		}
		randomStringBuilder.append(new String(randomBytes));
		
		return randomStringBuilder.toString();
	}
	long total = 0;
	public void startSpamming(){
		//while(true){
		for(int i = 0; i < 10; i++){
			try{
				String text = generateRandomString();
				
				total += System.currentTimeMillis();
				//System.out.println("Sending: "+variable.getVariableID()+" @ "+System.currentTimeMillis());
				toolBridge.send(new SerializableStringTerm(text));
				
				Thread.sleep(5000);
				Thread.yield();
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		System.out.println(total);
		
		terminate();
	}

	public void string(SerializableStringTerm message){
		// Do nothing
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
		SpamClient spamClient = new SpamClient();
		spamClient.startSpamming();
	}
}
