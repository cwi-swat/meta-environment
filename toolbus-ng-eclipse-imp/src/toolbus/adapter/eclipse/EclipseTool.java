package toolbus.adapter.eclipse;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;

import toolbus.ToolBusEclipsePlugin;
import toolbus.adapter.java.AbstractJavaTool;
import toolbus.adapter.java.JavaToolBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermBlob;
import aterm.ATermList;
import aterm.pure.PureFactory;
import aterm.pure.binary.BinaryReader;

public class EclipseTool extends AbstractJavaTool{
	protected static final String TIME_OUT = "time-out";

	protected static PureFactory factory = ToolBusEclipsePlugin.getFactory();

	private static InetAddress host;
	static{
		try{
			host = InetAddress.getLocalHost();
		}catch(UnknownHostException uhex){
			uhex.printStackTrace();
		}
	}
	private final static int port = ToolBusEclipsePlugin.getPort();
	
	private final String name;

	public EclipseTool(String name){
		super();
		
		this.name = name;
	}
	
	public void connect(){
		try{
			//connect(new String[0]);
			connectDirectly();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	protected ATerm decode(ATerm encoded) {
		if (encoded.getType() == ATerm.APPL) {
			ATermAppl tmp = (ATermAppl) encoded;
			ATermList chunkList = (ATermList) tmp.getArgument(0);
			int nrOfChunks = chunkList.getLength();
			BinaryReader reader = new BinaryReader((PureFactory) encoded.getFactory());
			 
		    do {
		        ATermBlob chunk = (ATermBlob) chunkList.elementAt(--nrOfChunks);
		        byte[] data = chunk.getBlobData();
		        
		        ByteBuffer buffer = ByteBuffer.allocate(data.length);
				buffer.put(data);
				buffer.flip();
				
		        reader.deserialize(buffer);
		      } while(nrOfChunks > 0);

		      return reader.getRoot();
		}
		
		return encoded;
	}
	
	private void connectDirectly() throws Exception{
		connectDirectly(ToolBusEclipsePlugin.getToolBus(), name, -1);
	}
	
	public String getName() {
		return name;
	}

	public void connect(String[] args) throws Exception{
		toolBridge = new JavaToolBridge(factory, this, name, -1, host, port);
		toolBridge.setExceptionHandler(new ToolBridgeExceptionHandler());
		toolBridge.run();	
	}
	
	private static class ToolBridgeExceptionHandler implements Runnable{
		
		public ToolBridgeExceptionHandler(){
			super();
		}
		
		public void run(){
			// TODO What to do?
		}
	}

	public void receiveTerminate(ATerm aTerm){
		// Intentionally left empty.
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// Intentionally left empty.
	}
}
