package toolbus.adapter;

import java.net.InetAddress;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import toolbus.IOperations;
import toolbus.adapter.AbstractTool;
import toolbus.communication.IDataHandler;
import toolbus.communication.IIOHandler;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

/**
 * This class supplies an interface for the tool towards the ToolBus and handles the invokation of
 * methods on the tool.
 * 
 * @author Arnold Lankamp
 */
public abstract class ToolBridge implements IDataHandler, Runnable, IOperations{
	private final PureFactory termFactory;

	private final Map<Long, ThreadLocalJobQueue> threadLocalQueues;
	private final Map<AFun, JobQueue> queues;

	private IIOHandler ioHandler;

	private final String type;

	private final String toolName;
	private int toolID = -1;

	private final InetAddress host;
	private final int port;

	/**
	 * Constructor.
	 * 
	 * @param type
	 *            The type of the tool (Remote of direct).
	 * @param toolName
	 *            The name of the with this bridge associated tool.
	 * @param toolID
	 *            The id of the with this bridge associated tool.
	 * @param host
	 *            The host on which the ToolBus is running.
	 * @param port
	 *            The port on which the ToolBus is running.
	 */
	public ToolBridge(PureFactory termFactory, String type,  String toolName, int toolID, InetAddress host, int port){
		super();
		
		this.termFactory = termFactory;
		this.type = type;
		this.toolName = toolName;
		this.toolID = toolID;
		this.host = host;
		this.port = port;

		threadLocalQueues = new HashMap<Long, ThreadLocalJobQueue>();
		queues = new HashMap<AFun, JobQueue>();
	}
	
	/**
	 * Returns what type of connection we have with the ToolBus.
	 * 
	 * @return What type of connection we have with the ToolBus.
	 */
	public String getType(){
		return type;
	}

	/**
	 * Returns the tool name of the tool that is associated with this tool bridge.
	 * 
	 * @return The tool name of the tool that is associated with this tool bridge.
	 */
	public String getToolName(){
		return toolName;
	}

	/**
	 * Sets the tool id to the given values. This method will only be called once, after
	 * successfully connecting to the ToolBus.
	 * 
	 * @param toolID
	 *            The value the toolID has to be set too.
	 */
	protected void setToolID(int toolID){
		this.toolID = toolID;
	}

	/**
	 * Returns the tool id of the tool that is associated with this tool bridge.
	 * 
	 * @return The tool id of the tool that is associated with this tool bridge.
	 */
	public int getToolID(){
		return toolID;
	}

	/**
	 * Returns a reference to the term factory.
	 * 
	 * @return A reference to the term factory.
	 */
	public PureFactory getFactory(){
		return termFactory;
	}

	/**
	 * Returns the adress of the host the ToolBus is running on.
	 * 
	 * @return The adress of the host the ToolBus is running on. Is null when uninitialized.
	 */
	protected InetAddress getHost(){
		return host;
	}

	/**
	 * Returns the port number the ToolBus is running on.
	 * 
	 * @return The port number the ToolBus is running on. Is -1 when uninitialized.
	 */
	protected int getPort(){
		return port;
	}
	
	/**
	 * Associates an I/O handler with this tool bridge.
	 * 
	 * @param ioHandler
	 *            The I/O handler to associate this tool bridge with.
	 */
	public void setIOHandler(IIOHandler ioHandler){
		this.ioHandler = ioHandler;
	}
	
	/**
	 * Checks if the tool associated with this tool bridge supplies the given signature.
	 * 
	 * @param signatures
	 *            The signature we need to compare the interface of the tool too.
	 * @return True if the tool supplies the expected interface; false otherwise.
	 */
	public abstract boolean checkSignature(ATerm signature);
	
	/**
	 * Executes a DO operation with the given ATerm.
	 * 
	 * @param aTerm
	 *            The ATerm that contains the necessary data to complete the DO request.
	 */
	public abstract void doDo(ATerm aTerm);
	
	/**
	 * Executes an EVAL operation with the given ATerm.
	 * 
	 * @param aTerm
	 *            The ATerm that contains the necessary data to complete the EVAL request.
	 * @return The result the EVAL request produced (may not be null).
	 */
	public abstract ATerm doEval(ATerm aTerm);
	
	/**
	 * Executes a RECACKEVENT operation with the given ATerm.
	 * 
	 * @param aTerm
	 *            The ATerm that can potentially contain callback data.
	 */
	public abstract void doReceiveAckEvent(ATerm aTerm);
	
	/**
	 * Executes a TERMINATE operation with the given ATerm.
	 * 
	 * @param aTerm
	 *            The ATerm that can potentially contain background informantion about the termination request.
	 */
	public abstract void doTerminate(ATerm aTerm);
	
	/**
	 * Retrieves performance statistic information from the tool (if possible).
	 * 
	 * @return The gathered performance information (may not be null).
	 */
	public abstract ATerm doGetPerformanceStats();
	
	/**
	 * @see IDataHandler#send(byte, ATerm)
	 */
	public void send(byte operation, ATerm aTerm){
		ioHandler.send(operation, aTerm);
	}
	
	/**
	 * Posts the given event.
	 * 
	 * @param aTerm
	 *            The event.
	 */
	public void postEvent(ATerm aTerm){
		long threadId = Thread.currentThread().getId();
		ThreadLocalJobQueue threadLocalQueue;
		synchronized(threadLocalQueues){
			threadLocalQueue = threadLocalQueues.get(new Long(threadId));
			if(threadLocalQueue == null){
				threadLocalQueue = new ThreadLocalJobQueue();
				threadLocalQueues.put(new Long(threadId), threadLocalQueue);
			}
		}
		threadLocalQueue.postEvent(aTerm, threadId);
	}
	
	/**
	 * Posts the given request.
	 * 
	 * @param aTerm
	 *            The request.
	 */
	public ATerm postRequest(ATerm aTerm){
		long threadId = Thread.currentThread().getId();
		ThreadLocalJobQueue threadLocalQueue;
		synchronized(threadLocalQueues){
			threadLocalQueue = threadLocalQueues.get(new Long(threadId));
			if(threadLocalQueue == null){
				threadLocalQueue = new ThreadLocalJobQueue();
				threadLocalQueues.put(new Long(threadId), threadLocalQueue);
			}
		}
		return threadLocalQueue.postRequest(aTerm, threadId);
	}

	/**
	 * @see IDataHandler#receive(byte, ATerm)
	 */
	public void receive(byte operation, ATerm aTerm){
		switch(operation){
			case DO:
				doDo(aTerm);
				send(ACKDO, termFactory.makeList());
				break;
			case EVAL:
				send(VALUE, doEval(aTerm));
				break;
			case ACKEVENT:
				ATermList ackEvent = ((ATermList) aTerm);
				ATerm event = ackEvent.getFirst();
				
				AFun ackSourceFun = ((ATermAppl) event).getAFun();
				
				JobQueue eventQueue;
				synchronized(queues){
					eventQueue = queues.get(ackSourceFun);
				}
				if(eventQueue == null){
					LoggerFactory.log("Received acknowledgement for a non-existent event: " + ackSourceFun, ILogger.WARNING, IToolBusLoggerConstants.TOOL);
					return;
				}
				eventQueue.ackEvent();
				
				ATerm callBackInfo = ackEvent.elementAt(1);
				doReceiveAckEvent(callBackInfo);
				break;
			case RESPONSE:
				AFun responseSourceFun = ((ATermAppl) aTerm).getAFun();
				
				JobQueue requestQueue;
				synchronized(queues){
					requestQueue = queues.get(responseSourceFun);
				}
				if(requestQueue == null){
					LoggerFactory.log("Received response on a non-existent request: " + responseSourceFun, ILogger.WARNING, IToolBusLoggerConstants.TOOL);
					return;
				}
				requestQueue.recResponse(aTerm);
				break;
			case TERMINATE:
				doTerminate(aTerm);
				terminate();
				break;
			case PERFORMANCESTATS:
				ATerm performanceStats = doGetPerformanceStats();
				send(PERFORMANCESTATS, performanceStats);
				break;
			case DEBUGPERFORMANCESTATS:
				ATerm debugPerformanceStats = doGetPerformanceStats();
				send(DEBUGPERFORMANCESTATS, debugPerformanceStats);
				break;
			default:
				LoggerFactory.log("Unkown operation id: " + operation, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
		}
	}

	/**
	 * Requests the termination of this tool, so it can perform an orderly shutdown on the toolbus
	 * side.
	 * 
	 * @see IDataHandler#terminate()
	 */
	public void terminate(){
		ioHandler.terminate();
	}

	/**
	 * Informs the tool that it was shut down by the toolbus.
	 * 
	 * @see IDataHandler#shutDown()
	 */
	public void shutDown(){
		LoggerFactory.log("The connection with the ToolBus was closed. Waiting for the tool to shut down ....", ILogger.INFO, IToolBusLoggerConstants.TOOL);
	}
	
	/**
	 * @see IDataHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		LoggerFactory.log("Lost connection with the ToolBus. Initiating ungraceful shutdown ....", ILogger.FATAL, IToolBusLoggerConstants.TOOL);
		
		System.exit(0);
	}

	/**
	 * Executes the ToolBridge.
	 * 
	 * @see Runnable#run()
	 */
	public void run(){
		// Only start the connection stuff if we haven't been linked to an I/O handler yet.
		if(type.equals(AbstractTool.REMOTETOOL)){
			if(host == null || port == -1){
				LoggerFactory.log("Dunno where the ToolBus is running.", ILogger.FATAL, IToolBusLoggerConstants.TOOL);
				throw new RuntimeException("Dunno where the ToolBus is running.");
			}
			
			ToolConnectionHandler toolConnectionHandler = new ToolConnectionHandler(this, host, port);
			toolConnectionHandler.run();
			
			// Send a connect message to the ToolBus.
			send(CONNECT, termFactory.makeAppl(termFactory.makeAFun(toolName, 1, false), termFactory.makeInt(toolID)));
		}else if(type.equals(AbstractTool.DIRECTTOOL)){
			// We don't need to do anything in this case we will be linked to a direct I/O handler.
		}else{
			String error = "Unknown tool type: " + type;
			LoggerFactory.log(error, ILogger.FATAL, IToolBusLoggerConstants.TOOL);
			throw new RuntimeException(error);
		}
	}
	
	/**
	 * A job.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class Job{
		public final ATerm term;
		public final long threadId;
		public ATerm response; // Optional field
		
		/**
		 * Constructor.
		 * 
		 * @param term
		 *            The message associated with this event.
		 * @param threadId
		 *            The id of the thread associated with this event.
		 */
		public Job(ATerm term, long threadId){
			super();
			
			this.term = term;
			this.threadId = threadId;
		}
	}

	/**
	 * This job queue holds all the jobs that are send from a single source.
	 * 
	 * @author Arnold Lankamp
	 */
	private class JobQueue{
		private final List<Job> jobs;
		private Job current;

		/**
		 * Default constructor.
		 */
		public JobQueue(){
			super();
			
			jobs = new LinkedList<Job>();
			
			current = null;
		}
		
		/**
		 * Schedules the given job for transmission to the ToolBus. If there are currently no
		 * jobs in the queue, the event will be send immediately; otherwise we'll need to wait till
		 * all the requests (of the same source) that where previously scheduled have been send and
		 * acknowledged.
		 * 
		 * @param job
		 *            A container that hold the details about the request.
		 */
		public synchronized void post(Job job){
			if(current == null){
				ioHandler.send(EVENT, job.term);
				current = job;
			}else{
				jobs.add(job);
			}
		}

		/**
		 * Returns the next job in the queue.
		 * 
		 * @return The next job in the queue; null if the queue is empty.
		 */
		public synchronized Job getNext(){
			if(!jobs.isEmpty()) return jobs.remove(0);
			
			return null;
		}
		
		/**
		 * Notifies the thread local queue of the acknowledgement and executes the next queued job
		 * (if present).
		 */
		private synchronized void acknowledge(){
			long threadId = current.threadId;
			ThreadLocalJobQueue threadLocalQueue;
			synchronized(threadLocalQueues){
				threadLocalQueue = threadLocalQueues.get(new Long(threadId));
			}
			threadLocalQueue.acknowledge();
			
			Job next = getNext();
			current = next;
			if(next != null){
				ioHandler.send(EVENT, next.term);
			}
		}

		/**
		 * Acknowledges the last event that was send from the source this queue is associated with.
		 * It will execute the next job in the queue if there are any.
		 */
		public void ackEvent(){
			acknowledge();
		}
		
		/**
		 * Acknowledges the last request that was send from the source this queue is associated
		 * with. It will execute the next job in the queue if there are any.
		 * 
		 * @param response
		 *            The response.
		 */
		public synchronized void recResponse(ATerm response){
			synchronized(current){
				current.response = response;
				current.notify();
			}
			
			acknowledge();
		}
	}
	
	/**
	 * This job queue holds all the jobs that are posted by a certain thread.
	 * 
	 * @author Arnold Lankamp
	 */
	private class ThreadLocalJobQueue{
		private final List<Job> requests;
		
		private boolean awaitingAck;

		/**
		 * Default constructor.
		 */
		public ThreadLocalJobQueue(){
			super();
			
			requests = new LinkedList<Job>();
		}
		
		/**
		 * Schedules the given event for transmission to the ToolBus. If there are currently no
		 * jobs in the thread local queue, the event will be send immediately; otherwise we'll need
		 * to wait till all the jobs (associated with the current thread) that were previously
		 * scheduled have been submitted to the request queue.
		 * 
		 * @param aTerm
		 *            The term that hold the details about the event.
		 * @param threadId
		 *            The id of the thread associated with the event.
		 */
		public synchronized void postEvent(ATerm aTerm, long threadId){
			Job request = new Job(aTerm, threadId);
			
			if(!awaitingAck){
				AFun sourceFun = ((ATermAppl) aTerm).getAFun();
				
				JobQueue requestQueue;
				synchronized(queues){
					requestQueue = queues.get(sourceFun);
					if(requestQueue == null){
						requestQueue = new JobQueue();
						queues.put(sourceFun, requestQueue);
					}
				}
				requestQueue.post(request);
				awaitingAck = true;
			}else{
				requests.add(request);
			}
		}
		
		/**
		 * Schedules the given request for transmission to the ToolBus. If there are currently no
		 * jobs in the thread local queue, the event will be send immediately; otherwise we'll need
		 * to wait till all the jobs (associated with the current thread) that were previously
		 * scheduled have been submitted to the request queue.
		 * 
		 * @param aTerm
		 *            The term that hold the details about the request.
		 * @param threadId
		 *            The id of the thread associated with the request.
		 * @return The received response on the issued request.
		 */
		public synchronized ATerm postRequest(ATerm aTerm, long threadId){
			Job job = new Job(aTerm, threadId);
			synchronized(job){
				if(!awaitingAck){
					AFun sourceFun = ((ATermAppl) aTerm).getAFun();
					
					JobQueue requestQueue;
					synchronized(queues){
						requestQueue = queues.get(sourceFun);
						if(requestQueue == null){
							requestQueue = new JobQueue();
							queues.put(sourceFun, requestQueue);
						}
					}
					requestQueue.post(job);
					awaitingAck = true;
				}else{
					requests.add(job);
				}
				
				while(job.response == null){
					try{
						job.wait();
					}catch(InterruptedException irex){
						// Ignore this, since I don't want to know about it.
					}
				}
			}
			return job.response;
		}
		
		/**
		 * Returns the next job in the queue.
		 * 
		 * @return The next job in the queue; null if the queue is empty.
		 */
		public synchronized Job getNext(){
			if(!requests.isEmpty()) return requests.remove(0);
			
			return null;
		}
		
		/**
		 * Acknowledges the last job that was send from the source the current thread is associated
		 * with. It will submit the next job in the queue if there are any.
		 */
		public synchronized void acknowledge(){
			Job next = getNext();
			if(next == null){
				awaitingAck = false;
			}else{
				ATerm term = next.term;
				AFun sourceFun = ((ATermAppl) term).getAFun();
				
				JobQueue requestQueue;
				synchronized(queues){
					requestQueue = queues.get(sourceFun);
					if(requestQueue == null){
						requestQueue = new JobQueue();
						queues.put(sourceFun, requestQueue);
					}
				}
				
				requestQueue.post(next);
			}
		}
	}
}
