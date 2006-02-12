package toolbus.tool.java;


import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

import toolbus.ToolBus;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;

public class JavaToolBridge  extends Thread {
//		private Object lockObject;

		protected ATermFactory factory;
		private boolean verbose = true;
		
		private ToolBus myToolBus;
		private ToolInstance myToolInstance;
		private Object myTool;

		private String toolname;
		private InetAddress address;
		private int port = -1;
		private int toolid = -1;

		private Map<String,EventQueue> queueMap;

		private ATerm termSndVoid;

		private boolean running;
		private boolean connected;

		public JavaToolBridge(Constructor toolConstructor, ToolInstance toolInstance, String[] args) {
			
			System.err.println("constructor for JavaToolBridge called");
			
			for (int i = 0; i < args.length; i++) {
				if (args[i].equals("-TB_PORT")) {
					port = Integer.parseInt(args[++i]);
				}
				if (args[i].equals("-TB_HOST")) {
					//address = InetAddress.getByName(args[++i]);
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
			myToolInstance = toolInstance;
			myToolBus = toolInstance.getToolBus();
			this.factory = myToolBus.getTBTermFactory();

			termSndVoid = factory.parse("snd-void");
			queueMap = new HashMap<String,EventQueue>();
//			lockObject = this;
			try {
				myTool = toolConstructor.newInstance(new Object[] { this, args });
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InstantiationException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}


		public void connect() throws IOException {
			myToolInstance.connect(this);
			connected = true;
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
		
		public ATermFactory getFactory(){
			return factory;
		}

		public void setVerbose(boolean on) {
			verbose = on;
		}

		public boolean getVerbose() {
			return verbose;
		}

		void info(String msg) {
			if (verbose) {
				System.err.println("[JavaToolBridge: " + toolname + "] " + msg);
			}
		}

		public void sendTerm(ATerm term) throws IOException {
			info("sendterm(" + term + ")");
			myToolInstance.handleTermFromTool(term);
			myToolBus.wakeup();
		}
		
		private synchronized void setRunning(boolean state)  {
			running = state;
		}
		
		public void stopRunning() {
			setRunning(false);
		}

		synchronized public void run() {
			setRunning(true);
			while (running) {
				try {
					wait();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

		synchronized public void handleTermFromToolBus(Integer operation, Method m, Object[] actuals) throws IOException {	
			info("handling operation from toolbus: " + operation);

			if(operation == ToolInstance.TERMINATE){
				setRunning(false);
				connected = false;
			}
			ATerm result = null;
			try {
				result = (ATerm) m.invoke(myTool, actuals);
			} catch(Exception e) {
				System.err.println("Method '" + m.getName() + "' in Java tool thows unexpected exception");
				e.printStackTrace();
			} 

			if(operation == ToolInstance.DO){
				sendTerm(termSndVoid);
			}
			else if (result != null) {
				sendTerm(result);
			}

			if(operation == ToolInstance.ACK){
				ackEvent((ATerm)actuals[0]);
			}
		}

		synchronized public void postEvent(ATerm term) {
			info("postEvent: " + term);
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

		private void ackEvent(ATerm event) throws IOException {
			info("ackEvent: " + event);
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
