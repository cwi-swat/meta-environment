package toolbus.adapter.java;

import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.ThreadInfo;
import java.lang.management.ThreadMXBean;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.Map;
import toolbus.IOperations;
import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.pure.PureFactory;

/**
 * This class is a specialized ToolBridge version for Java tools. It supplies an interface for the tool
 * to enable it to communicate with the ToolBus and it handles the invokation of methods on the tool.
 * 
 * @author Arnold Lankamp
 */
public class JavaToolBridge extends ToolBridge{
	private final PureFactory termFactory;
	private final AbstractTool tool;
	private final Map<CallableMethodSignature, Method> callableFunctions;
	
	/**
	 * Constructor.
	 * 
	 * @param type
	 *            The type of the tool (Remote of direct).
	 * @param tool
	 *            The tool this bridge needs to be associated with.
	 * @param toolName
	 *            The name of the with this bridge associated tool.
	 * @param toolID
	 *            The id of the with this bridge associated tool.
	 * @param host
	 *            The host on which the ToolBus is running.
	 * @param port
	 *            The port on which the ToolBus is running.
	 */
	public JavaToolBridge(PureFactory termFactory, String type, AbstractTool tool, String toolName, int toolID, InetAddress host, int port){
		super(termFactory, type, toolName, toolID, host, port);
		
		this.termFactory = termFactory;
		this.tool = tool;
		callableFunctions = new HashMap<CallableMethodSignature, Method>();
		initCallableMethods();
	}
	
	/**
	 * @see toolbus.adapter.ToolBridge#doDo(ATerm)
	 */
	public void doDo(ATerm aTerm){
		try{
			invokeMethod(IOperations.DO, aTerm);
		}catch(MethodInvokationException miex){
			LoggerFactory.log("Unable to execute DO request.", miex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
		}
	}
	
	/**
	 * @see toolbus.adapter.ToolBridge#doEval(ATerm)
	 */
	public ATerm doEval(ATerm aTerm){
		ATerm result = null;
		try{
			result = invokeMethod(IOperations.EVAL, aTerm);
		}catch(MethodInvokationException miex){
			LoggerFactory.log("Unable to execute EVAL request.", miex, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
		}
		return result;
	}
	
	/**
	 * @see toolbus.adapter.ToolBridge#doReceiveAckEvent(ATerm)
	 */
	public void doReceiveAckEvent(ATerm aTerm){
		tool.receiveAckEvent(aTerm);
	}
	
	/**
	 * @see toolbus.adapter.ToolBridge#doTerminate(ATerm)
	 */
	public void doTerminate(ATerm aTerm){
		tool.receiveTerminate(aTerm);
	}
	
	/**
	 * @see toolbus.adapter.ToolBridge#doGetPerformanceStats()
	 */
	public ATerm doGetPerformanceStats(){
		return getPerformanceStats();
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
	 * @see toolbus.adapter.ToolBridge#checkSignature(ATerm)
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
	 * Invokes the method associated with the given term and operation.
	 * 
	 * @param operation
	 *            Indicates the return type of the method (DO = void, EVAL = ATerm).
	 * @param aTerm
	 *            The ATerm that indicates with method should be invoked.
	 * @return The ATerm the invoked method returned; null in case it returned void.
	 * @throws MethodInvokationException
	 *             Thrown when something goes wrong.
	 */
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
	 * Gathers performance statistics about this tool, like memory usage and the user-/system-time
	 * spend per thread.
	 * 
	 * @return performance statictics.
	 */
	private ATerm getPerformanceStats(){
		String type = getType();
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
