package toolbus.adapter;

import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.ThreadInfo;
import java.lang.management.ThreadMXBean;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import toolbus.IOperations;
import toolbus.TBTermFactory;
import toolbus.communication.IDataHandler;
import toolbus.communication.IIOHandler;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.pure.PureFactory;

/**
 * This class supplies an interface for the tool towards the ToolBus and handles the invokation of
 * methods on the tool.
 * 
 * @author Arnold Lankamp
 */
public class ToolBridge implements IDataHandler, Runnable, IOperations{
	private final static PureFactory termFactory = TBTermFactory.getInstance();

	private final Map<CallableMethodSignature, Method> callableFunctions;

	private final Map<Long, ThreadLocalEventQueue> threadLocalQueues;
	private final Map<AFun, EventQueue> queues;

	private final AbstractTool tool;
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
	 * @param tool
	 *            The tool that this tool bridge needs to be associated with.
	 * @param toolName
	 *            The name of the with this bridge associated tool.
	 * @param toolID
	 *            The id of the with this bridge associated tool.
	 * @param host
	 *            The host on which the ToolBus is running.
	 * @param port
	 *            The port on which the ToolBus is running.
	 */
	public ToolBridge(String type, AbstractTool tool, String toolName, int toolID, InetAddress host, int port){
		super();

		this.type = type;
		this.tool = tool;
		this.toolName = toolName;
		this.toolID = toolID;
		this.host = host;
		this.port = port;

		callableFunctions = new HashMap<CallableMethodSignature, Method>();
		initCallableMethods();

		threadLocalQueues = new HashMap<Long, ThreadLocalEventQueue>();
		queues = new HashMap<AFun, EventQueue>();
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
	 * Reads all the callable methods of the tool associated with this tool bridge.
	 */
	private void initCallableMethods(){
		Class<?> toolClass = tool.getClass();
		Method[] toolMethods = toolClass.getMethods();
		for(int i = 0; i < toolMethods.length; i++){
			Method toolMethod = toolMethods[i];
			if(Modifier.isPublic(toolMethod.getModifiers())){

				Class<?> returnType = toolMethod.getReturnType();
				if(isImplementationOf(returnType, ATerm.class)) returnType = ATerm.class;
				if(returnType == void.class || returnType == ATerm.class || isImplementationOf(returnType, ATerm.class)){

					Class<?>[] parameters = toolMethod.getParameterTypes();
					boolean paramsAreTerms = true;
					for(int j = parameters.length - 1; j >= 0; j--){
						Class<?> param = parameters[j];
						if(param != ATerm.class && !isImplementationOf(param, ATerm.class)){
							paramsAreTerms = false;
							break;
						}
					}

					if(paramsAreTerms){
						CallableMethodSignature cms = new CallableMethodSignature();
						cms.methodName = toolMethod.getName();
						cms.returnType = returnType;
						cms.parameters = parameters;

						callableFunctions.put(cms, toolMethod);
					}
				}
			}
		}
	}

	/**
	 * Checks the the given class satisfies the given interface.
	 * 
	 * @param clazz
	 *            The class from which we want to know if it satisfies the given interface.
	 * @param superInterface
	 *            The interface to satisfy.
	 * @return True if clazz implements the specified interface; false otherwise.
	 */
	protected static boolean isImplementationOf(Class<?> clazz, Class<?> superInterface){
		Class<?>[] interfaces = clazz.getInterfaces();

		for(int i = 0; i < interfaces.length; i++){
			Class<?> interfaceX = interfaces[i];
			if(interfaceX.equals(superInterface) || isImplementationOf(interfaceX, superInterface)){
				return true;
			}
		}

		if(!clazz.isInterface()){
			Class<?> superClass = clazz.getSuperclass();
			if(superClass != null) return isImplementationOf(superClass, superInterface);
		}

		return false;
	}

	/**
	 * This class represents a signature of a method (Name + return type + params).
	 * 
	 * @author Arnold Lankamp
	 */
	protected static class CallableMethodSignature{
		public String methodName;
		public Class<?> returnType;
		public Class<?>[] parameters;

		/**
		 * Custom hashcode function. This is needed because we use this object as a key in a
		 * HashMap.
		 */
		public int hashCode(){
			return methodName.hashCode();
		}

		/**
		 * Custom equals method. Matches when the object we are comparing ourselfs to can be called
		 * by this method signature.<br />
		 * <br />
		 * For example: void method(String o) equals void method(Object o), but method(Object o)
		 * does not equal method(String o).
		 * 
		 * @see java.lang.Object#equals(java.lang.Object)
		 */
		public boolean equals(Object o){
			if(o == this){
				return true;
			}else if(o instanceof CallableMethodSignature){
				CallableMethodSignature cms = (CallableMethodSignature) o;

				if(!methodName.equals(cms.methodName)) return false;

				if(cms.returnType != returnType && returnType != void.class && !isImplementationOf(cms.returnType, returnType)) return false;

				if(parameters.length != cms.parameters.length) return false;
				for(int i = 0; i < parameters.length; i++){
					if(parameters[i] != cms.parameters[i] && !isImplementationOf(parameters[i], cms.parameters[i])){
						return false;
					}
				}

				return true;
			}

			return false;
		}
	}

	/**
	 * Checks if the tool associated with this tool bridge supplies the given signature.
	 * 
	 * @param signatures
	 *            The signature we need to compare the interface of the tool too.
	 * @return True if the tool supplies the expected interface; false otherwise.
	 */
	public boolean checkSignature(ATerm signatures){
		boolean correct = true;

		ATermList inputSignatures = (ATermList) ((ATermAppl) signatures).getArgument(0);
		while(!inputSignatures.isEmpty()){
			ATermAppl sig = (ATermAppl) inputSignatures.getFirst();
			String operation = sig.getName();
			if(operation.equals("rec-eval")){
				ATermAppl methodTerm = (ATermAppl) sig.getArgument(0);

				ATerm[] arguments = methodTerm.getArgumentArray();
				Class<?>[] parameters = new Class[arguments.length];
				for(int i = 0; i < parameters.length; i++){
					// All the arguments are placeholders, so retrieve the type they represent.
					parameters[i] = ((ATermPlaceholder) arguments[i]).getPlaceholder().getClass();
				}

				Method toolMethod = findMethod(EVAL, methodTerm.getName(), parameters);
				if(toolMethod == null){
					LoggerFactory.log("Unable to locate method matching the following signature: " + sig, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
					correct = false;
					break;
				}
			}else if(operation.equals("rec-do")){
				ATermAppl methodTerm = (ATermAppl) sig.getArgument(0);

				ATerm[] arguments = methodTerm.getArgumentArray();
				Class<?>[] parameters = new Class[arguments.length];
				for(int i = 0; i < parameters.length; i++){
					// Retrieve the types of the parameters.
					ATerm parameter = arguments[i];
					if(parameter instanceof ATermPlaceholder){
						parameters[i] = ((ATermPlaceholder) parameter).getPlaceholder().getClass();
					}else{
						parameters[i] = parameter.getClass();
					}
				}

				Method toolMethod = findMethod(DO, methodTerm.getName(), parameters);
				if(toolMethod == null){
					LoggerFactory.log("Unable to locate method matching the following signature: " + sig, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
					correct = false;
					break;
				}
			}else if(operation.equals("rec-ack-event")){
				// Ignore this, you can always handle event acknowledgements.
			}else if(operation.equals("rec-terminate")){
				// Why even bother to check this?
				// It's impossible to write a tool that doesn't have it.
			}else{
				LoggerFactory.log("Unknown operation in signature: " + sig, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
				correct = false;
				break;
			}
			inputSignatures = inputSignatures.getNext();
		}

		return correct;
	}

	/**
	 * Returns the tool method that matches the given name, arguments and operation.
	 * 
	 * @param operation
	 *            The operation associated with the given term.
	 * @param methodName
	 *            The name of the method we want to find.
	 * @param parameters
	 *            The list of parameters that the method needs be able to accept.
	 * @return The method corresponding to the given term.
	 */
	private Method findMethod(byte operation, String methodName, Class<?>[] parameters){
		CallableMethodSignature cms = new CallableMethodSignature();
		cms.methodName = methodName;
		cms.parameters = parameters;

		if(operation == EVAL){
			cms.returnType = ATerm.class;
		}else if(operation == DO){
			cms.returnType = void.class;
		}

		return callableFunctions.get(cms);
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
	 * @see IDataHandler#send(byte, ATerm)
	 */
	public void send(byte operation, ATerm aTerm){
		if(operation == EVENT){
			long threadId = Thread.currentThread().getId();
			ThreadLocalEventQueue threadLocalQueue = null;
			synchronized(threadLocalQueues){
				threadLocalQueue = threadLocalQueues.get(new Long(threadId));
				if(threadLocalQueue == null){
					threadLocalQueue = new ThreadLocalEventQueue();
					threadLocalQueues.put(new Long(threadId), threadLocalQueue);
				}
			}
			threadLocalQueue.postEvent(aTerm, threadId);
		}else{
			ioHandler.send(operation, aTerm);
		}
	}

	private ATerm invokeMethod(byte operation, ATerm aTerm) throws MethodInvokationException{
		ATerm returnValue = null;
		try{
			// We will always get an appl, otherwise we wouldn't know what method to invoke.
			ATermAppl methodTerm = (ATermAppl) aTerm;

			String methodName = methodTerm.getName();

			ATerm[] arguments = methodTerm.getArgumentArray();
			Class<?>[] parameters = new Class[arguments.length];
			for(int i = 0; i < parameters.length; i++){
				parameters[i] = arguments[i].getClass();
			}

			Method toolMethod = findMethod(operation, methodName, parameters);
			if(toolMethod == null){
				String error = "No such method: " + methodName + ", with " + parameters.length + " arguments.";
				LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
				throw new MethodInvokationException(error);
			}
			returnValue = (ATerm) toolMethod.invoke(tool, (Object[]) arguments);
		}catch(ClassCastException ccex){
			LoggerFactory.log("A class cast exception occured during the invokation of a method. Discarding term ....", ccex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
			throw new MethodInvokationException(ccex);
		}catch(InvocationTargetException itex){
			LoggerFactory.log("Something went wrong during the invokation of a method. Discarding associated term ....", itex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
			throw new MethodInvokationException(itex);
		}catch(IllegalAccessException iaex){
			LoggerFactory.log("Unable to invoke the with the term associated method. Discarding term ....", iaex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
			throw new MethodInvokationException(iaex);
		}

		return returnValue;
	}

	/**
	 * @see IDataHandler#receive(byte, ATerm)
	 */
	public void receive(byte operation, ATerm aTerm){
		switch(operation){
			case DO:
				try{
					invokeMethod(operation, aTerm);
				}catch(MethodInvokationException miex){
					LoggerFactory.log("Unable to execute DO request.", miex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
				}
				send(ACKDO, termFactory.makeList());
				break;
			case EVAL:
				ATerm result = null;
				try{
					result = invokeMethod(operation, aTerm);
				}catch(MethodInvokationException miex){
					LoggerFactory.log("Unable to execute EVAL request.", miex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
				}
				send(VALUE, result);
				break;
			case ACKEVENT:
				ATerm event = ((ATermList) aTerm).getFirst();
				
				AFun sourceFun = ((ATermAppl) event).getAFun();
				
				EventQueue eventQueue;
				synchronized(queues){
					eventQueue = queues.get(sourceFun);
				}
				eventQueue.ackEvent();
				break;
			case TERMINATE:
				tool.receiveTerminate(aTerm);
				terminate();
				break;
			case PERFORMANCESTATS:
				ATerm performaceStats = getPerformanceStats();
				send(PERFORMANCESTATS, performaceStats);
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
	 * An event.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class Event{
		public final ATerm term;
		public final long threadId;
		
		/**
		 * Constructor.
		 * 
		 * @param term
		 *            The message associated with this event.
		 * @param threadId
		 *            The id of the thread associated with this event.
		 */
		public Event(ATerm term, long threadId){
			super();
			
			this.term = term;
			this.threadId = threadId;
		}
	}

	/**
	 * This event queue holds all the events that are send from a single source.
	 * 
	 * @author Arnold Lankamp
	 */
	private class EventQueue{
		private final List<Event> events;
		private Event current;

		/**
		 * Default constructor.
		 */
		public EventQueue(){
			super();
			
			events = new LinkedList<Event>();
			
			current = null;
		}

		/**
		 * Schedules the given event for transmission to the ToolBus. If there are currently no
		 * messages in the queue, the event will be send immediately; otherwise we'll need to wait
		 * till all the events (of the same source) that where previously scheduled have been send
		 * and acknowledged.
		 * 
		 * @param aTerm
		 *            The term that hold the details about the event.
		 * @param threadId
		 *            The id of the thread associated with the event.
		 */
		public synchronized void postEvent(ATerm aTerm, long threadId){
			Event event = new Event(aTerm, threadId);
			if(current == null){
				ioHandler.send(EVENT, aTerm);
				current = event;
			}else{
				events.add(event);
			}
		}

		/**
		 * Returns the next event in the queue.
		 * 
		 * @return The next event in the queue; null if the queue is empty.
		 */
		public synchronized Event getNext(){
			if(!events.isEmpty()) return events.remove(0);
			
			return null;
		}

		/**
		 * Acknowledges the last event that was send from the source this queue is associated with.
		 * It will send the next term in the queue if there are any.
		 */
		public synchronized void ackEvent(){
			long threadId = current.threadId;
			ThreadLocalEventQueue threadLocalQueue;
			synchronized(threadLocalQueues){
				threadLocalQueue = threadLocalQueues.get(new Long(threadId));
			}
			threadLocalQueue.ackEvent();
			
			Event next = getNext();
			current = next;
			if(next != null){
				ioHandler.send(EVENT, next.term);
			}
		}
	}
	
	/**
	 * This event queue holds all the events that are posted by a certain thread.
	 * 
	 * @author Arnold Lankamp
	 */
	private class ThreadLocalEventQueue{
		private final List<Event> events;
		
		private boolean awaitingAck;

		/**
		 * Default constructor.
		 */
		public ThreadLocalEventQueue(){
			super();
			
			events = new LinkedList<Event>();
		}
		
		/**
		 * Schedules the given event for transmission to the ToolBus. If there are currently no
		 * messages in the thread local queue, the event will be send immediately; otherwise we'll
		 * need to wait till all the events (associated with the current thread) that were
		 * previously scheduled have been submitted to the event queue.
		 * 
		 * @param aTerm
		 *            The term that hold the details about the event.
		 * @param threadId
		 *            The id of the thread associated with the event.
		 */
		public synchronized void postEvent(ATerm aTerm, long threadId){
			if(!awaitingAck){
				AFun sourceFun = ((ATermAppl) aTerm).getAFun();
				
				EventQueue eventQueue;
				synchronized(queues){
					eventQueue = queues.get(sourceFun);
					if(eventQueue == null){
						eventQueue = new EventQueue();
						queues.put(sourceFun, eventQueue);
					}
				}
				eventQueue.postEvent(aTerm, threadId);
				awaitingAck = true;
			}else{
				events.add(new Event(aTerm, threadId));
			}
		}
		
		/**
		 * Returns the next event in the queue.
		 * 
		 * @return The next event in the queue; null if the queue is empty.
		 */
		public synchronized Event getNext(){
			if(!events.isEmpty()) return events.remove(0);
			
			return null;
		}
		
		/**
		 * Acknowledges the last event that was send from the source the current thread is associated
		 * with. It will submit the next term in the queue if there are any.
		 */
		public synchronized void ackEvent(){
			Event next = getNext();
			if(next == null){
				awaitingAck = false;
			}else{
				ATerm term = next.term;
				AFun sourceFun = ((ATermAppl) term).getAFun();
				
				EventQueue eventQueue;
				synchronized(queues){
					eventQueue = queues.get(sourceFun);
					if(eventQueue == null){
						eventQueue = new EventQueue();
						queues.put(sourceFun, eventQueue);
					}
				}
				
				eventQueue.postEvent(term, next.threadId);
			}
		}
	}

	/**
	 * Custom exception. Thrown whenever the method associated with a certain DO or EVAL request
	 * could not be located, or something goes wrong during execution of that request.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class MethodInvokationException extends Exception{
		private final static long serialVersionUID = 7944846564197962451L;

		/**
		 * Constructor.
		 * 
		 * @see Exception#Exception(java.lang.String)
		 */
		public MethodInvokationException(String message){
			super(message);
		}

		/**
		 * Constructor.
		 * 
		 * @see Exception#Exception(java.lang.Throwable)
		 */
		public MethodInvokationException(Throwable exception){
			super(exception);
		}

		/**
		 * Constructor.
		 * 
		 * @see Exception#Exception(java.lang.String, java.lang.Throwable)
		 */
		public MethodInvokationException(String message, Throwable exception){
			super(message, exception);
		}
	}
	
	/**
	 * Gathers performance statistics about this tool, like memory usage and the user-/system-time
	 * spend per thread.
	 * 
	 * @return performance statictics.
	 */
	private ATerm getPerformanceStats(){
		if(type == AbstractTool.DIRECTTOOL) return termFactory.make("performance-stats(unsupported-operation)"); // You can't request the stats from a direct tool in this way.
		
		// Type stuff
		ATerm remote = termFactory.makeAppl(termFactory.makeAFun(type, 0, true));
		ATerm toolType = termFactory.makeAppl(termFactory.makeAFun("type", 1, false), remote);
		
		ATerm java = termFactory.makeAppl(termFactory.makeAFun("Java", 0, true));
		ATerm toolLanguage = termFactory.makeAppl(termFactory.makeAFun("language", 1, false), java);
		
		ATerm toolData = termFactory.makeAppl(termFactory.makeAFun("tool", 2, false), toolType, toolLanguage);
		
		// Memory stuff
		MemoryMXBean mmxb = ManagementFactory.getMemoryMXBean();
		long heapMemoryUsage = mmxb.getHeapMemoryUsage().getUsed();
		long nonHeapMemoryUsage = mmxb.getNonHeapMemoryUsage().getUsed();
		
		ATerm heapUsage = termFactory.makeAppl(termFactory.makeAFun("heap-usage", 1, false), termFactory.makeInt(((int) (heapMemoryUsage / 1024))));
		ATerm nonHeapUsage = termFactory.makeAppl(termFactory.makeAFun("non-heap-usage", 1, false), termFactory.makeInt(((int) (nonHeapMemoryUsage / 1024))));
		
		ATerm memory = termFactory.makeAppl(termFactory.makeAFun("memory-usage", 2, false), heapUsage, nonHeapUsage);
		
		// Thread stuff
		ThreadMXBean tmxb = ManagementFactory.getThreadMXBean();
		
		ATerm threads;
		
		long[] threadIds = tmxb.getAllThreadIds();
		int nrOfThreads = threadIds.length;
		try{
			ATermList threadsList = termFactory.makeList();
			for(int i = 0; i < nrOfThreads; i++){
				ThreadInfo ti = tmxb.getThreadInfo(threadIds[i]);
				if(ti != null){
					String threadName = ti.getThreadName();
					long userTime = tmxb.getThreadUserTime(threadIds[i]);
					long systemTime = tmxb.getThreadCpuTime(threadIds[i]) - userTime;
					
					if((userTime + systemTime) <= 0) continue;
					
					ATerm userTimeTerm = termFactory.makeAppl(termFactory.makeAFun("user-time", 1, false), termFactory.makeInt(((int) (userTime / 1000000))));
					ATerm systemTimeTerm = termFactory.makeAppl(termFactory.makeAFun("system-time", 1, false), termFactory.makeInt(((int) (systemTime / 1000000))));
					ATerm thread = termFactory.makeAppl(termFactory.makeAFun(threadName, 2, false), userTimeTerm, systemTimeTerm);
					
					threadsList = termFactory.makeList(thread, threadsList);
				}
			}
			
			threads = termFactory.makeAppl(termFactory.makeAFun("threads", 1, false), threadsList);
		}catch(UnsupportedOperationException uoex){
			threads = termFactory.make("threads(unsupported-operation)");
			LoggerFactory.log("Thread time profiling is not supported by this JVM.", ILogger.ERROR, IToolBusLoggerConstants.TOOL);
		}
		
		return termFactory.makeAppl(termFactory.makeAFun("performance-stats", 3, false), toolData, memory, threads);
	}
}
