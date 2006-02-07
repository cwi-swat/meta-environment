package toolbus;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

import toolbus.tool.ToolInstance;
import toolbus.tool.java.Tool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class AbstractTool  extends Thread implements Tool{

	private Object lockObject;

	protected ATermFactory factory;
	private boolean verbose = true;
	
	private ToolBus myToolBus;
	private ToolInstance myToolInstance;

	private String toolname;
	private InetAddress address;
	private int port = -1;
	private int toolid = -1;

	private Map<String,EventQueue> queueMap;

	private ATerm termSndVoid;

	private boolean running;
	private boolean connected;

	public AbstractTool(ATermFactory factory) {
		
		System.err.println("constructor for AbstractTool called");
		this.factory = factory;

		termSndVoid = factory.parse("snd-void");
		queueMap = new HashMap<String,EventQueue>();
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
		try {
			myToolBus = ToolBus.getToolBus(port);
			myToolInstance = myToolBus.getToolInstance(toolid);
		} catch (ToolBusException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void setLockObject(Object obj) {
		lockObject = obj;
	}

	public Object getLockObject() {
		return lockObject;
	}

	public void connect() throws IOException {
		myToolInstance.connect(this);
		connected = true;
	}

	public void connect(String toolname, InetAddress address, int port) throws IOException {
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

	void info(String msg) {
		if (verbose) {
			System.err.println("[TOOL: " + toolname + "] " + msg);
		}
	}

	public void sendTerm(ATerm term) throws IOException {
		myToolInstance.handleTermFromTool(term);
	}
	
	private synchronized void setRunning(boolean state)  {
		running = state;
	}
	
	public void stopRunning() {
		setRunning(false);
	}

	synchronized public void run() {
		//this.start();
		setRunning(true);
		while (running) {
			try {
				//System.err.println("before wait");
				wait();
				//System.err.println("after wait");
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public void handleIncomingTerm(ATerm t) throws IOException {
		synchronized (getLockObject()) {
			
			info("tool " + toolname + " handling term from toolbus: " + t);

			if (t.match("rec-terminate(<term>)") != null) {
				setRunning(false);
				connected = false;
			}
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
		myToolInstance.addEventFromTool(factory.make("snd-event(<term>)", term));
	}

	public void postEvent(ATerm term) {
		synchronized (getLockObject()) {
			ATermAppl appl = (ATermAppl) term;
			EventQueue queue = queueMap.get(appl.getName());
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
		EventQueue queue = queueMap.get(appl.getName());
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
	private List<ATermAppl> events = new Vector<ATermAppl>();

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

		ATermAppl event = events.get(0);
		events.remove(0);
		return event;
	}

	public void addEvent(ATermAppl event) {
		events.add(event);
	}
}
