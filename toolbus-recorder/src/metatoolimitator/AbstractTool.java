package metatoolimitator;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import toolbus.*;

abstract public class AbstractTool implements Tool, Runnable {
	private final static int LENSPEC = 12;
	private final static int MAX_HANDSHAKE = 512;
	private final static int MIN_MSG_SIZE = 128;

	private Object lockObject;

	protected ATermFactory factory;
	private boolean verbose = false;
	private InputStream inputStream;
	private OutputStream outputStream;

	private String toolname;
	private InetAddress address;
	private int port = -1;
	private int toolid = -1;

	private Map queueMap;

	private ATerm termSndVoid;

	private boolean running;
	private boolean connected;

	public AbstractTool(ATermFactory factory) {
		//System.out.println("Deze abstract");
		this.factory = factory;

		termSndVoid = factory.parse("snd-void");
		queueMap = new HashMap();
		lockObject = this;
	}

	public void init(String[] args) throws UnknownHostException {
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-TB_PORT")) {
				port = Integer.parseInt(args[++i]);
			}
			if (args[i].equals("-TB_HOST")) {
				address = InetAddress.getByName(args[++i]);
			}
			if (args[i].equals("-TB_TOOL_NAME")) {
				toolname = args[++i];
			}
			if (args[i].equals("-TB_TOOL_ID")) {
				toolid = Integer.parseInt(args[++i]);
			}
			if (args[i].equals("-TB_VERBOSE")) {
				verbose = true;
			}
		}
		if (address == null) {
			address = InetAddress.getLocalHost();
		}
	}

	public void setLockObject(Object obj) {
		lockObject = obj;
	}

	public Object getLockObject() {
		return lockObject;
	}

	public void connect() throws IOException {
		//System.out.println("Connect 1");
		Socket socket = new Socket(address, port);
		inputStream = new BufferedInputStream(socket.getInputStream());
		outputStream = new BufferedOutputStream(socket.getOutputStream());

		shakeHands();
		//System.out.println("Connect 1.1");
		connected = true;
		
	}

	public void connect(String toolname, InetAddress address, int port) throws IOException {
		//System.out.println("Connect 2");
		if (toolname != null) {
			this.toolname = toolname;
		}

		if (address != null) {
			this.address = address;
		}

		if (port != -1) {
			this.port = port;
		}

		this.toolid = -1;

		connect();
	}

	public void disconnect() {
		//System.out.println("Disconnect");
		try {
			sendTerm(factory.parse("snd-disconnect"));
		}
		catch (IOException e) {
			throw new RuntimeException("cannot disconnect: " + e.getMessage());
		}
	}

	public boolean isConnected() {
		return connected;
	}

	public void setVerbose(boolean on) {
		verbose = on;
	}

	public boolean getVerbose() {
		return verbose;
	}

	private void shakeHands() throws IOException {
		//System.out.println("Shakehands");
		String host = address.getHostName();
		info("host = " + host);
		if (host == null) {
			String pair = address.toString();
			host = pair.substring(0, pair.indexOf('/'));
			info("local host = " + host);
		}

		String myHand = toolname + " " + host + " " + toolid;
		byte[] hs = myHand.getBytes();
		byte[] handshake = new byte[MAX_HANDSHAKE];
		for (int i = 0; i < hs.length; i++) {
			handshake[i] = hs[i];
		}
		outputStream.write(handshake);
		outputStream.flush();

		int tid = readInt();
		if (tid < 0) {
			throw new RuntimeException("no tool-id assigned by ToolBus");
		}
		if (toolid < 0) {
			toolid = tid;
			info("got tool-id: " + toolid);
		}
		else if (toolid != tid) {
			throw new RuntimeException("tool-id out of phase");
		}

		ATerm term = readTerm();
		List matches = term.match("rec-do(signature([<list>],[<list>]))");
		if (matches != null) {
			info("checking input signature...");
			checkInputSignature((ATermList) matches.get(0));
			sendTerm(termSndVoid);
		}
		else {
			throw new RuntimeException("signature information garbled: " + term);
		}
	}

	void info(String msg) {
		if (verbose) {
			System.err.println("[TOOL: " + toolname + "] " + msg);
		}
	}

	private int readInt() throws IOException {
		byte[] buffer = new byte[MAX_HANDSHAKE];

		inputStream.read(buffer);

		String string = new String(buffer);

		int space = string.indexOf(' ');
		int end = string.indexOf(0);
		String toolname = string.substring(0, space);
		if (!toolname.equals(this.toolname)) {
			throw new RuntimeException("wrong toolname in readInt: " + toolname);
		}
		return Integer.parseInt(string.substring(space + 1, end));
	}

	public void sendTerm(ATerm term) throws IOException {
		//System.out.println("Sendterm");
		synchronized (getLockObject()) {
			String unparsedTerm = term.toString();
			int size = unparsedTerm.length();
			String lenspec = "000000000000" + (size + LENSPEC) + ":";
			int len = lenspec.length();
			byte[] ls = new byte[LENSPEC];

			for (int i = 0; i < LENSPEC; i++) {
				ls[i] = (byte) lenspec.charAt(len + i - LENSPEC);
			}

			if (verbose) {
				System.out.print("tool " + toolname + " writes term:\n");
				System.out.print(new String(ls));
				// // //System.out.println(term);
			}
			outputStream.write(ls);
			term.writeToTextFile(outputStream);
			if (LENSPEC + size < MIN_MSG_SIZE) {
				info("padding with " + (MIN_MSG_SIZE - (LENSPEC + size)) + " zero bytes.");
			}
			for (int i = LENSPEC + size; i < MIN_MSG_SIZE; i++) {
				outputStream.write(0);
			}
			//System.out.println("\n\n\nSENDING: " + term + "\n\n\n");
			outputStream.flush();
		}
	}

	public ATerm readTerm(InputStream stream, ATermFactory factory) throws IOException { //was static
		//System.out.println("readTerm 1");
		return readTerm(stream, factory, stream);
	}

/*	public static ATerm readTerm(InputStream inputStream, ATermFactory factory, Object lock) throws IOException {
		ATerm result;
		byte[] lspecBuf = new byte[LENSPEC];
		int index;
		// //System.out.println("DEBUG: 1.0");
		index = 0;
		while (index != LENSPEC) {
			// //System.out.println("DEBUG: 1.1");
		   // // //System.out.println("DEBUG: 1.2 " + lspecBuf + " " + index + " " + LENSPEC);
		 //   // //System.out.println("value " + inputStream.read(lspecBuf, index, LENSPEC - index));
			// //System.out.println(lspecBuf +" "+ index +" "+ LENSPEC);
			//// //System.out.println("Testje: " + inputStream.read(lspecBuf, index, LENSPEC - index));
			int bytes_read = inputStream.read(lspecBuf, index, LENSPEC - index);
			 // //System.out.println("DEBUG: 1.3");
			if (bytes_read <= 0) {
				// //System.out.println("DEBUG: 2: 0 bytes gelezen");
				throw new IOException("ToolBus connection terminated");
			}
			index += bytes_read;
		}
		 // //System.out.println("DEBUG: 3");
		String lspec = new String(lspecBuf);
		// //System.out.println("DEBUG: 4: String: " + lspec + " LENSPEC: " + LENSPEC + " Berekening: " + (lspec.substring(0, LENSPEC - 1)));
		int bytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
		//// //System.out.println("TEST " +Integer.parseInt("poetie"));
		//int bytesLeft = Integer.parseInt("poetiepoetie");
		if (bytesLeft < MIN_MSG_SIZE) {
			bytesLeft = MIN_MSG_SIZE;
			// //System.out.println("DEBUG: 5");
		}
		bytesLeft -= LENSPEC;
		// //System.out.println("DEBUG: 6");
		byte[] data = new byte[bytesLeft];
		index = 0;
		// //System.out.println("DEBUG: 7");
		while (index != bytesLeft) {
			int bytes_read = inputStream.read(data, index, bytesLeft - index);
			if (bytes_read <= 0) {
				// //System.out.println("DEBUG: 8");
				throw new IOException("ToolBus connection terminated");
			}
			// //System.out.println("DEBUG: 9");
			index += bytes_read;
		}
		// //System.out.println("DEBUG: 10");
		String stringdata = new String(data);
		// //System.out.println("DEBUG: 11: String: " + stringdata);
		//info("data read (" + bytesLeft + " bytes): '" + stringdata + "'");
		// //System.out.println("DEBUG: 12");
		result = factory.parse(stringdata);
		// //System.out.println("DEBUG: 13");
		return result;
	}*/
	public ATerm readTerm(InputStream inputStream, ATermFactory factory, Object lock) throws IOException { //was static
		//System.out.println("readTerm 2");
		ATerm result;
		byte[] lspecBuf = new byte[LENSPEC];
		int index;
		index = 0;
		////System.out.println("wrong readTerm used");
		while (index != LENSPEC) {
			int bytes_read = inputStream.read(lspecBuf, index, LENSPEC - index);
			if (bytes_read <= 0) {
				throw new IOException("ToolBus connection terminated");
			}
			index += bytes_read;
		}
		String lspec = new String(lspecBuf);

		int bytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
		if (bytesLeft < MIN_MSG_SIZE) {
			bytesLeft = MIN_MSG_SIZE;
		}
		bytesLeft -= LENSPEC;

		byte[] data = new byte[bytesLeft];
		index = 0;
		while (index != bytesLeft) {
			int bytes_read = inputStream.read(data, index, bytesLeft - index);
			if (bytes_read <= 0) {
				throw new IOException("ToolBus connection terminated");
			}
			index += bytes_read;
		}

		String stringdata = new String(data);
		////System.out.println("Stringdata:");
		////System.out.println(stringdata);
		//info("data read (" + bytesLeft + " bytes): '" + stringdata + "'");

		if(stringdata.indexOf("\"_baf-encoded_\"(\"")!=-1)
			stringdata = replaceBaf(stringdata, factory);
		result = factory.parse(stringdata);
		////System.out.println("\n\n\nreturnvalue:\n" + result.toString() + "\n\n");
		return result;
	}
	
	public String replaceBaf(String stringdata, ATermFactory factory) //was static
	{
		//System.out.println("Replacebaf");
		ATerm result;
		int beginBaf, endBaf, endBaf1, endBaf2, hashcode, tempPlace;
		String hashstring = new String();
		beginBaf = stringdata.indexOf("\"_baf-encoded_\"(\"");
		////System.out.println("wrong replaceBaf used");
		endBaf = stringdata.indexOf("\")]",beginBaf+2);
		
		tempPlace = stringdata.indexOf("],[",beginBaf);
		if(tempPlace ==-1)
			tempPlace = stringdata.indexOf("\"),",beginBaf);
		endBaf = stringdata.lastIndexOf("\"",tempPlace+1);

		hashstring = stringdata.substring(beginBaf+17, endBaf);

		hashcode = hashstring.hashCode();
	
		stringdata = stringdata.substring(0,beginBaf) + "\"_baf-recoded_\"(\"" + hashcode + stringdata.substring(endBaf, stringdata.length());
		if(stringdata.indexOf("\"_baf-encoded_\"(\"")!=-1)
			stringdata = replaceBaf(stringdata, factory);

		return stringdata;
	}


	public ATerm readTerm(InputStream inputStream) throws IOException {
		//System.out.println("readTerm 3");
		return readTerm(inputStream, factory, getLockObject());
	}

	public ATerm readTerm() throws IOException {
		//System.out.println("readTerm 4");
		return readTerm(inputStream);
	}
	
	private synchronized void setRunning(boolean state)  {
		running = state;
	}

	public void run() {
		// //System.out.println("Running Poet version");
		setRunning(true);
		try {
			while (running) {
				//System.out.println("run");
				handleIncomingTerm();
			}
		}
		catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException("IOException: " + e.getMessage());
		}
	}
	
	public void stopRunning() {
		setRunning(false);
	}

	public void handleIncomingTerm() throws IOException {
		//System.out.println("Handling 1");
		ATerm t = readTerm();
		// //System.out.println("Afther reading");
		info("tool " + toolname + " handling term from toolbus: " + t);
// //System.out.println("tool " + toolname + " handling term from toolbus: " + t);
		
		if (t.match("rec-terminate(<term>)") != null) {
			setRunning(false);
			connected = false;
		}

		handleIncomingTerm(t);
	}

	public void handleIncomingTerm(ATerm t) throws IOException {
		//System.out.println("handling 2");
		handleTerm(t);

	}

	protected void handleTerm(ATerm t) throws IOException {
		//System.out.println("handling 3");
		synchronized (getLockObject()) {

			ATerm result = handler(t);

			if (t.match("rec-do(<term>)") != null) {
				sendTerm(termSndVoid);
			}
			else if (result != null) {
				sendTerm(result);
			}

			List terms = t.match("rec-ack-event(<term>)");
			if (terms != null) {
				ackEvent((ATerm) terms.get(0));
			}
		}
	}

	public void sendEvent(ATerm term) {
		try {
			sendTerm(factory.make("snd-event(<term>)", term));
		}
		catch (IOException e) {
			throw new RuntimeException("cannot send event: " + e.getMessage());
		}
	}

	public void postEvent(ATerm term) {
		synchronized (getLockObject()) {
			ATermAppl appl = (ATermAppl) term;
			EventQueue queue = (EventQueue) queueMap.get(appl.getName());
			if (queue == null) {
				queue = new EventQueue();
				queueMap.put(appl.getName(), queue);
			}
			if (queue.ackWaiting()) {
				queue.addEvent(appl);
			}
			else {
				try {
					sendTerm(factory.make("snd-event(<term>)", appl));
				}
				catch (IOException e) {
					throw new RuntimeException("cannot post event: " + appl);
				}
				queue.setAckWaiting();
			}
		}
	}

	private void ackEvent(ATerm event) throws IOException {
		ATermAppl appl = (ATermAppl) event;
		EventQueue queue = (EventQueue) queueMap.get(appl.getName());
		if (queue != null && queue.ackWaiting()) {
			appl = queue.nextEvent();
			if (appl != null) {
				sendTerm(factory.make("snd-event(<term>)", appl));
				return;
			}
		}
	}

	//}}}

	abstract public void checkInputSignature(ATermList sig);
	abstract public ATerm handler(ATerm t);
}

/**
 * The class EventQueue stores a queue of events, and their
 * acknowledgement status.
 *
 */

class EventQueue {
	private boolean ack = false;
	private List events = new Vector();

	public boolean ackWaiting() {
		return ack;
	}

	public void setAckWaiting() {
		ack = true;
	}

	public ATermAppl nextEvent() {
		if (events.size() == 0) {
			ack = false;
			return null;
		}

		ATermAppl event = (ATermAppl) events.get(0);
		events.remove(0);
		return event;
	}

	public void addEvent(ATermAppl event) {
		events.add(event);
	}
}
