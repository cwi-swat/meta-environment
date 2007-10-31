package toolbus.adapter.wish;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.util.logging.StreamHandler;

import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import aterm.ATerm;

public class WishAdapter extends AbstractTool{
	private final static String WISH_COMMAND = "wish";
	
	private ToolBridge toolBridge = null;
	private String scriptName = null;
	private Process process = null;
	private OutputStreamHandler outputStreamHandler = null;
	private ErrorStreamHandler errorStreamHandler = null;
	
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
			}else if(arg.equals("-script")){
				scriptName = args[++i];
			}
		}

		if(type == null || toolName == null) throw new RuntimeException("Missing tool identification.");
		if(scriptName == null) throw new RuntimeException("No script name supplied.");
		
		executeScript();

		toolBridge = new WishAdapterBridge(type, this, toolName, toolID, host, port);
		toolBridge.run();
		
		startHandlingIO();
	}
	
	private void executeScript() throws IOException{
		StringBuilder sb = new StringBuilder();
		sb.append(WISH_COMMAND);
		sb.append(' ');
		sb.append("-name ");
		sb.append(scriptName);
		String command = sb.toString();
		
		ProcessBuilder pb = new ProcessBuilder(command);
		
		process = pb.start();
		
		outputStreamHandler = new OutputStreamHandler(process.getInputStream());
		
		errorStreamHandler = new ErrorStreamHandler(process.getErrorStream());
	}
	
	private void startHandlingIO(){
		Thread outputStreamHandlerThread = new Thread(outputStreamHandler);
		outputStreamHandlerThread.setName("Output stream handler");
		outputStreamHandlerThread.setDaemon(true);
		outputStreamHandlerThread.start();

		Thread errorStreamHandlerThread = new Thread(errorStreamHandler);
		errorStreamHandlerThread.setName("Error stream handler");
		errorStreamHandlerThread.setDaemon(true);
		errorStreamHandlerThread.start();
	}
	
	private void killProcess(){
		process.destroy();
	}
	
	public void receiveDo(ATerm aTerm){
		// TODO Implement.
	}
	
	public ATerm receiveEval(ATerm aTerm){
		// TODO Implement.
		return null; // Temp
	}
	
	public void receiveTerminate(ATerm aTerm){
		// TODO Implement.
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// TODO Implement.
	}
	
	private class OutputStreamHandler implements Runnable{
		private final InputStream inputStream;
		
		public OutputStreamHandler(InputStream inputStream){
			this.inputStream = inputStream;
		}
		
		public void run(){
			BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
			
			String line = null;
			try{
				while((line = reader.readLine()) != null){
					System.out.println(line); // TODO do something usefull with this.
				}
			}catch(IOException ioex){
				ioex.printStackTrace();
			}catch(RuntimeException rex){
				rex.printStackTrace();
			}finally{
				// Close the reader.
				try{
					reader.close();
				}catch(IOException ioex){
					ioex.printStackTrace();
				}
			}
		}
	}
	
	private class ErrorStreamHandler implements Runnable{
		private final InputStream inputStream;
		
		public ErrorStreamHandler(InputStream inputStream){
			this.inputStream = inputStream;
		}
		
		public void run(){
			BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
			
			String line = null;
			try{
				while((line = reader.readLine()) != null){
					System.err.println(line);
				}
			}catch(IOException ioex){
				ioex.printStackTrace();
			}catch(RuntimeException rex){
				rex.printStackTrace();
			}finally{
				// Close the reader.
				try{
					reader.close();
				}catch(IOException ioex){
					ioex.printStackTrace();
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		WishAdapter wishAdapter = new WishAdapter();
		wishAdapter.connect(args);
	}
}
