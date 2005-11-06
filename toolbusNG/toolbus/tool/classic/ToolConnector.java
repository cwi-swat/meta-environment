/*
 * Created on Oct 8, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package toolbus.tool.classic;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

import toolbus.ToolBus;
import toolbus.tool.ToolInstance;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class ToolConnector extends Thread {
	private final static int MAX_HANDSHAKE = 512;   // Do not change since they correspond with
	private final static int MIN_MSG_SIZE = 128;	// the C implementation
	private ToolBus toolbus;
	private boolean running = false;
	private boolean verbose = false;
	//private InetAddress address;
	private String toolname;
	private Socket connection;
	private InputStream inputStream;
	private OutputStream outputStream;
	private int toolid = -1;
	private Vector connectedTools;
	
	public ToolConnector(ToolBus tb){
		toolbus = tb;
		connectedTools = new Vector();
	}
	
	public void setRunning(boolean on){
		running = on;
	}
	public void run(){
		int errorCount = 0;
		running = true;
		while(running){
			try {
				connect();
			} catch(IOException e){
				if(running){
					System.err.println("ToolConnector: " + e);
					errorCount++;
					if(errorCount > 5){
						e.printStackTrace();
						//throw new ToolBusException("no connection with tool");
						int n = 2/0;
					}	
				}
			}
		}
	}
	
	void info(String msg) {
		if (verbose) {
			System.err.println("[TOOLCONNECTOR] " + msg);
		}
	}
	
	public void connect() throws IOException {
		info("connect");
		ServerSocket server = ToolBus.getWellKnownSocket();
		info("accepting ...");
		connection = server.accept();
		inputStream = new BufferedInputStream(connection.getInputStream());
		outputStream = new BufferedOutputStream(connection.getOutputStream());
		info("shakeHands ...");
		shakeHands();
	}
	
	private void shakeHands() throws IOException {
	//	String host = address.getHostName();
	//	info("host = " + host);
	//	if (host == null) {
	//		String pair = address.toString();
	//		host = pair.substring(0, pair.indexOf('/'));
	//		info("local host = " + host);
	//	}
		
		byte[] handshake = new byte[MAX_HANDSHAKE];
		int nr = inputStream.read(handshake);
		
		String toolHand = new String(handshake).toLowerCase().trim();
		info("input: <" + toolHand + ">");
		String elems[] = toolHand.split(" ");

		toolname = elems[0];
		info("toolname = " + toolname);
		String host = elems[1];
		info("host = " + host);
		
		int lastd = -1;
		for(int i = 0; i < elems[2].length(); i++){
			if((i == 0) && (elems[2].charAt(0) == '-')){
				lastd = i;
			} else if(!Character.isDigit(elems[2].charAt(i))){
				break;
			}
			lastd = i;
		}
		toolid = Integer.parseInt(elems[2].substring(0,lastd+1));
		info("toolid = " + toolid);
		
		if(toolid >= 0){
			writeInt(toolid);
			ToolInstance ti = toolbus.getToolInstance(toolid);
			ti.connect(inputStream, outputStream);
		} else {
			try {
				ToolInstance ti = toolbus.addToolInstance(toolname, true);
				toolid = ti.getToolCount();
				writeInt(toolid);
				info("shakeHands: created ti");
				connectedTools.add(ti);
				info("shakeHands: added to list");
				for(int i = 0; i < connectedTools.size(); i++){
					ToolInstance ti1 = (ToolInstance) connectedTools.elementAt(i);
					info("shakeHands: considering: " + ti1.getToolName());
				}
				
				ti.connect(inputStream, outputStream);
			} catch (Exception e) {
				// TODO: handle exception
			}
		}
	}
	
	public ToolInstance getConnectedTool(String toolname){
		//info("getConnectedTool: " + toolname);
		for(int i = 0; i < connectedTools.size(); i++){
			ToolInstance ti = (ToolInstance) connectedTools.elementAt(i);
			//info("getConnectedTool: considering: " + ti.getToolName());
			if(ti.getToolName().equals(toolname)){
				connectedTools.removeElementAt(i);
				//info("getConnectedTool: " + toolname + " ==> " + ti);
				return ti;
			}
		}
		//info("getConnectedTool: " + toolname + " ==> null");
		return null;
	}
	
	private void writeInt(int n) throws IOException {
		byte[] buffer = new byte[MAX_HANDSHAKE];
		String s = toolname + " " + Integer.toString(n);
		byte bs[] = s.getBytes();
		for (int i = 0; i < bs.length; i++) {
			buffer[i] = bs[i];
		}
		outputStream.write(buffer);
		outputStream.flush();
	}
}
