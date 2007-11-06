package toolbus.adapter.wish;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.List;

import toolbus.adapter.AbstractTool;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class WishAdapter extends AbstractTool{
	private final static String WISH_COMMAND = "wish";
	
	private String scriptName = null;
	private String tbtcl = null;
	private String libdir = null;
	private final List<String> arguments;
	
	private Process process = null;
	private OutputStream wishInputStream = null;
	private OutputStreamHandler outputStreamHandler = null;
	private ErrorStreamHandler errorStreamHandler = null;
	
	private final byte[] spaceBytes;
	private final byte[] startCallBytes;
	private final byte[] endCallBytes;
	private final byte[] startAckEventBytes;
	private final byte[] endAckEventBytes;
	private final byte[] startTerminateBytes;
	private final byte[] endTerminateBytes;
	
	private final Object valueLock = new Object();
	private ATerm value = null;
	
	public WishAdapter(){
		super();
		
		arguments = new ArrayList<String>();
		
		spaceBytes = " ".getBytes();
		startCallBytes = "if [catch {".getBytes();
		endCallBytes = "} msg] {TBerror $msg}\n".getBytes();
		startAckEventBytes = "rec-ack-event {".getBytes();
		endAckEventBytes = "}".getBytes();
		startTerminateBytes = "rec-terminate {".getBytes();
		endTerminateBytes = "}".getBytes();
	}
	
	public void connect(String[] args) throws Exception{
		String type = null;

		String toolName = null;
		int toolID = -1;

		InetAddress host = null;
		int port = -1;
		
		arguments.clear(); // Insurance, this isn't strictly needed.
		
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
			}else if(arg.equals("-tbtcl")){
				tbtcl = args[++i];
			}else if(arg.equals("-libdir")){
				libdir = args[++i];
			}else{
				arguments.add(args[i]);
			}
		}

		if(type == null || toolName == null) throw new RuntimeException("Missing tool identification.");
		if(scriptName == null) throw new RuntimeException("No script name supplied.");
		if(tbtcl == null || libdir == null) throw new RuntimeException("No library paths supplied.");
		
		toolBridge = new WishAdapterBridge(type, this, toolName, toolID, host, port);
		
		executeScript();
		
		toolBridge.run();
		
		startHandlingIO();
	}
	
	private void executeScript() throws IOException{
		String[] command = new String[3];
		command[0] = WISH_COMMAND;
		command[1] = "-name";
		command[2] = getToolBridge().getToolName();
		
		ProcessBuilder pb = new ProcessBuilder(command);
		
		process = pb.start();
		
		wishInputStream = process.getOutputStream();
		outputStreamHandler = new OutputStreamHandler(process.getInputStream());
		errorStreamHandler = new ErrorStreamHandler(process.getErrorStream());
		
		initWish();
	}
	
	private void initWish() throws IOException{
		wishInputStream.write("source ".getBytes());
		wishInputStream.write(tbtcl.getBytes());
		wishInputStream.write("\n".getBytes());
		
		wishInputStream.write("set argv { ".getBytes());
		int nrOfArguments = arguments.size();
		int i = 0;
		while(i++ < nrOfArguments){
			wishInputStream.write(arguments.get(i).getBytes());
			wishInputStream.write(spaceBytes);
		}
		wishInputStream.write("}\n".getBytes());
		
		wishInputStream.write("set argc ".getBytes());
		wishInputStream.write((""+nrOfArguments).getBytes());
		wishInputStream.write("\n".getBytes());
		
		wishInputStream.write("set TB_LIBDIR ".getBytes());
		wishInputStream.write(libdir.getBytes());
		wishInputStream.write("\n".getBytes());
		
		wishInputStream.write("source ".getBytes());
		wishInputStream.write(scriptName.getBytes());
		wishInputStream.write("\n".getBytes());
		
		wishInputStream.flush();
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
	
	protected void valueReady(ATerm v){
		value = v;
		synchronized(valueLock){
			valueLock.notify();
		}
	}
	
	public void receiveDo(ATerm aTerm){
		ATermAppl doTerm = (ATermAppl) aTerm;
		AFun fun = doTerm.getAFun();
		String functionName = fun.getName();
		ATerm[] arguments = doTerm.getArgumentArray();
		int nrOfArguments = arguments.length;
		
		try{
			wishInputStream.write(startCallBytes);
			wishInputStream.write(functionName.getBytes());
			wishInputStream.write(spaceBytes);
			int i = 0;
			while(i < nrOfArguments){
				wishInputStream.write(arguments[i++].toString().getBytes());
				wishInputStream.write(spaceBytes);
			}
			wishInputStream.write(endCallBytes);
		}catch(IOException ioex){
			ioex.printStackTrace();
			System.err.println("Something went terribly wrong with the TCL/TK tool. Committing suicide now ....");
			System.exit(0); // Kill yourself.
		}
	}
	
	public ATerm receiveEval(ATerm aTerm){
		ATermAppl evalTerm = (ATermAppl) aTerm;
		AFun fun = evalTerm.getAFun();
		String functionName = fun.getName();
		ATerm[] arguments = evalTerm.getArgumentArray();
		int nrOfArguments = arguments.length;
		
		try{
			wishInputStream.write(startCallBytes);
			wishInputStream.write(functionName.getBytes());
			wishInputStream.write(spaceBytes);
			int i = 0;
			while(i < nrOfArguments){
				wishInputStream.write(arguments[i++].toString().getBytes());
				wishInputStream.write(spaceBytes);
			}
			wishInputStream.write(endCallBytes);
		}catch(IOException ioex){
			ioex.printStackTrace();
			System.err.println("Something went terribly wrong with the TCL/TK tool. Committing suicide now ....");
			System.exit(0); // Kill yourself.
		}
		
		// Receive the value.
		synchronized(valueLock){
			while(value == null){
				try{
					valueLock.wait();
				}catch(InterruptedException irex){
					// Ignore this exception.
				}
			}
		}
		
		ATerm result = value;
		value = null; // Reset the value field.
		
		return result;
	}
	
	public void receiveTerminate(ATerm aTerm){
		ATermList terminateTerm = (ATermList) aTerm;
		
		try{
			wishInputStream.write(startCallBytes);
			wishInputStream.write(startTerminateBytes);
			wishInputStream.write(spaceBytes);
			
			ATermList empty = getFactory().makeList();
			ATermList next = terminateTerm.getNext();
			while(next != empty){
				ATerm first = terminateTerm.getFirst();
				
				wishInputStream.write(first.toString().getBytes());
				wishInputStream.write(spaceBytes);
				
				terminateTerm = next;
			}
			
			wishInputStream.write(endTerminateBytes);
			wishInputStream.write(endCallBytes);
		}catch(IOException ioex){
			ioex.printStackTrace();
			System.err.println("Something went terribly wrong with the TCL/TK tool. Committing suicide now ....");
			System.exit(0); // Kill yourself.
		}
	}
	
	public void receiveAckEvent(ATerm aTerm){
		ATermList evalTerm = (ATermList) aTerm;
		
		try{
			wishInputStream.write(startCallBytes);
			wishInputStream.write(startAckEventBytes);
			wishInputStream.write(spaceBytes);
			
			ATermList empty = getFactory().makeList();
			ATermList next = evalTerm.getNext();
			while(next != empty){
				ATerm first = evalTerm.getFirst();
				
				wishInputStream.write(first.toString().getBytes());
				wishInputStream.write(spaceBytes);
				
				evalTerm = next;
			}
			wishInputStream.write(endAckEventBytes);
			wishInputStream.write(endCallBytes);
		}catch(IOException ioex){
			ioex.printStackTrace();
			System.err.println("Something went terribly wrong with the TCL/TK tool. Committing suicide now ....");
			System.exit(0); // Kill yourself.
		}
	}
	
	private class OutputStreamHandler implements Runnable{
		private final InputStream inputStream;
		
		public OutputStreamHandler(InputStream inputStream){
			this.inputStream = inputStream;
		}
		
		public void run(){
			BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
			PureFactory factory = getFactory();
			
			String line = null;
			try{
				while((line = reader.readLine()) != null){
					ATermAppl term = (ATermAppl) factory.parse(line);
					AFun fun = term.getAFun();
					String operation = fun.getName();
					
					// The operation has already been interned, so match pointers instead of using equals.
					if(operation == "snd-event"){
						ATerm sndEventTerm = term.getArgument(0);
						sendEvent(sndEventTerm);
					}else if(operation == "rec-value"){
						ATerm recValueTerm = term.getArgument(0);
						valueReady(recValueTerm);
					}else if(operation == "snd-disconnect"){
						disconnect(factory.makeList());
					}
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
