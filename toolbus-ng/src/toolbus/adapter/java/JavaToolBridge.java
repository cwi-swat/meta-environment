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
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import toolbus.IOperations;
import toolbus.ToolBus;
import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermBlob;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.ATermReal;
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
	public JavaToolBridge(PureFactory termFactory, AbstractTool tool, String toolName, int toolID, InetAddress host, int port){
		super(termFactory, toolName, toolID, host, port);
		
		this.termFactory = termFactory;
		this.tool = tool;
		callableFunctions = new HashMap<CallableMethodSignature, Method>();
		initCallableMethods();
	}
	
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
	 * @param classLoader
	 *            The classLoader to use for loading classes.
	 * @param toolbus
	 *            The toolbus to link this bridge to.
	 */
	public JavaToolBridge(PureFactory termFactory, AbstractTool tool, String toolName, int toolID, ToolBus toolbus){
		super(termFactory, toolName, toolID, toolbus);
		
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
		public final String methodName;
		public final Class<?>[] parameters;
		public final Class<?> returnType;
		
		public CallableMethodSignature(String methodName, Class<?>[] parameters, Class<?> returnType){
			super();
			
			this.methodName = methodName;
			this.returnType = returnType;
			this.parameters = parameters;
		}

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
					if(parameters[i] != cms.parameters[i] && !isImplementationOf(parameters[i], cms.parameters[i]) && cms.parameters[i] != ATerm.class) return false;
				}

				return true;
			}

			return false;
		}
		
		/**
		 * @see java.lang.Object#toString()
		 */
		public String toString(){
			StringBuilder sb = new StringBuilder();
			sb.append(returnType);
			sb.append(' ');
			sb.append(methodName);
			sb.append('(');
			int nrOfParameters = parameters.length;
			if(nrOfParameters > 0){
				sb.append(parameters[0]);
				
				for(int i = 1; i < nrOfParameters; i++){
					sb.append(", ");
					sb.append(parameters[i]);
				}
			}
			sb.append(')');
			
			return sb.toString();
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
					
					CallableMethodSignature cms = new CallableMethodSignature(toolMethod.getName(), parameters, returnType);
					
					callableFunctions.put(cms, toolMethod);
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
				ATermAppl methodTerm = (ATermAppl) sig.getArgument(1);

				ATerm[] arguments = methodTerm.getArgumentArray();
				Class<?>[] parameters = new Class[arguments.length];
				for(int i = 0; i < parameters.length; i++){
					// All the arguments are placeholders, so retrieve the type they represent.
					parameters[i] = determainTermType(arguments[i]);
				}

				Method toolMethod = findMethod(EVAL, methodTerm.getName(), parameters);
				if(toolMethod == null){
					LoggerFactory.log("Unable to locate method matching the following signature: " + sig, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
					correct = false;
					break;
				}
			}else if(operation.equals("rec-do")){
				ATermAppl methodTerm = (ATermAppl) sig.getArgument(1);

				ATerm[] arguments = methodTerm.getArgumentArray();
				Class<?>[] parameters = new Class[arguments.length];
				for(int i = 0; i < parameters.length; i++){
					// Retrieve the types of the parameters.
					parameters[i] = determainTermType(arguments[i]);
					
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
			// We will always get an appl.
			ATermAppl methodTerm = (ATermAppl) aTerm;

			String methodName = methodTerm.getName();
			
			ATerm[] arguments = methodTerm.getArgumentArray();
			Object[] convertedArguments = new Object[arguments.length];
			Class<?>[] parameters = new Class[arguments.length];
			for(int i = 0; i < parameters.length; i++){
				parameters[i] = determainTermType(arguments[i]);
				convertedArguments[i] = convertArgument(arguments[i]);
			}

			Method toolMethod = findMethod(operation, methodName, parameters);
			
			if(toolMethod == null){
				String error = "No such method: " + toMethodName(methodName) + ", with " + parameters.length + " arguments.";
				LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
				throw new MethodInvokationException(error);
			}

			Class<?>[] parameterTypes = toolMethod.getParameterTypes();
			for(int i = 0; i < parameters.length; i++){
				convertedArguments[i] = arguments[i];
				
				if(parameterTypes[i] != ATerm.class){
					convertedArguments[i] = convertArgument(arguments[i]);
				}
			}
			
			returnValue = (ATerm) toolMethod.invoke(tool, convertedArguments);
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

	private static String toMethodName(String str){
		StringBuilder name = new StringBuilder();
		
		boolean capNext = false;
		for(int i = 0; i < str.length(); i++){
			if(str.charAt(i) == '-'){
				capNext = true;
			}else if(capNext){
				name.append(Character.toUpperCase(str.charAt(i)));
				capNext = false;
			}else{
				name.append(str.charAt(i));
			}
		}
		return name.toString();
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
		CallableMethodSignature cms;

		if(operation == EVAL){
			cms = new CallableMethodSignature(toMethodName(methodName), parameters, ATerm.class);
		}else if(operation == DO){
			cms = new CallableMethodSignature(toMethodName(methodName), parameters, void.class);
		}else{
			String error = "Unknown operation: "+operation;
			LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOL);
			throw new RuntimeException(error);
		}

		return callableFunctions.get(cms);
	}
	
	/**
	 * Determain the class type of the given aterm (depending on its signature).
	 * 
	 * @param aTerm
	 *            The aterm of which we need to determain the type.
	 * @return The Java class type the aterm corresponds to.
	 */
	private Class<?> determainTermType(ATerm aTerm){
		if(aTerm instanceof ATermPlaceholder){
			ATermPlaceholder placeHolder = (ATermPlaceholder) aTerm;
			ATermAppl typeTerm = (ATermAppl) placeHolder.getPlaceholder();
			String typeName = typeTerm.getName();
			
			if(typeName.equals("str")) return String.class;
			if(typeName.equals("blob")) return byte[].class;
			if(typeName.equals("int")) return int.class;
			if(typeName.equals("real")) return double.class;
			if(typeName.equals("list")) return ATermList.class;
			if(typeName.equals("appl")) return ATermAppl.class;
			if(typeName.equals("term")) return ATerm.class;
		}else if(aTerm instanceof ATermAppl){
			ATermAppl appl = (ATermAppl) aTerm;
			if(appl.getAFun().isQuoted()) return String.class;
			return ATermAppl.class;
		}else if(aTerm instanceof ATermList){
			return ATermList.class;
		}else if(aTerm instanceof ATermInt){
			return int.class;
		}else if(aTerm instanceof ATermReal){
			return double.class;
		}else if(aTerm instanceof ATermBlob){
			return byte[].class;
		}
		
		// Unable to determain type (or it's a type that doesn't need conversion).
		return ATerm.class;
	}
	
	/**
	 * Converts the given aterm to its corresponding Java type object (if needed).
	 * 
	 * @param aTerm
	 *            The aterm to convert.
	 * @return The resulting Java type object.
	 */
	private Object convertArgument(ATerm aTerm){
		int type = aTerm.getType();
		switch(type){
			case ATerm.APPL:
				ATermAppl appl = (ATermAppl) aTerm;
				if(appl.getAFun().isQuoted()) return appl.getAFun().getName();
				return appl;
			case ATerm.LIST:
				return aTerm;
			case ATerm.INT:
				ATermInt integer = (ATermInt) aTerm;
				return new Integer(integer.getInt());
			case ATerm.REAL:
				ATermReal real = (ATermReal) aTerm;
				return new Double(real.getReal());
			case ATerm.BLOB:
				ATermBlob blob = (ATermBlob) aTerm;
				return blob.getBlobData();
			default:
				return aTerm; // No conversion needed, just return it.
		}
	}
	
	/**
	 * Gathers performance statistics about this tool, like memory usage and the user-/system-time
	 * spend per thread.
	 * 
	 * @return Performance statictics.
	 */
	private ATerm getPerformanceStats(){
		String type = getType();
		
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
		ThreadGroup currentThreadGroup = Thread.currentThread().getThreadGroup();
		Thread[] relevantThreads = new Thread[currentThreadGroup.activeCount() * 2 + 10]; // Create an array that's more then big enough.
		currentThreadGroup.enumerate(relevantThreads);
		
		Set<Long> relevantThreadIds = new HashSet<Long>();
		for(int i = 0; i < relevantThreads.length; i++){
			Thread thread = relevantThreads[i];
			if(thread != null){
				relevantThreadIds.add(new Long(thread.getId()));
			}
		}
		
		ThreadMXBean tmxb = ManagementFactory.getThreadMXBean();
		
		ATerm threads;
		
		long[] threadIds = tmxb.getAllThreadIds();
		int nrOfThreads = threadIds.length;
		try{
			ATermList threadsList = termFactory.makeList();
			for(int i = 0; i < nrOfThreads; i++){
				long threadId = threadIds[i];
				if(relevantThreadIds.contains(new Long(threadId))){ // Only list the info if we're interested in it.
					ThreadInfo ti = tmxb.getThreadInfo(threadId);
					if(ti != null){
						String threadName = ti.getThreadName();
						long userTime = tmxb.getThreadUserTime(threadIds[i]);
						long systemTime = tmxb.getThreadCpuTime(threadIds[i]) - userTime;
						
						ATerm userTimeTerm = termFactory.makeAppl(termFactory.makeAFun("user-time", 1, false), termFactory.makeInt(((int) (userTime / 1000000))));
						ATerm systemTimeTerm = termFactory.makeAppl(termFactory.makeAFun("system-time", 1, false), termFactory.makeInt(((int) (systemTime / 1000000))));
						ATerm thread = termFactory.makeAppl(termFactory.makeAFun(threadName, 2, false), userTimeTerm, systemTimeTerm);
						
						threadsList = termFactory.makeList(thread, threadsList);
					}
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
