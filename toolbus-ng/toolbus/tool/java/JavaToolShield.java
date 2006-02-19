package toolbus.tool.java;

import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Hashtable;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.ToolShield;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ATermPlaceholder;


/**
 * @author paulk
 *
 * JavaToolShield encapsulates an actual Java tool: it creates an instance of the Java class that 
 * implements the tool and acts as communication channel between the tool and ToolInstance. 
 * The full picture is:
 * - ToolInstance implements the general ToolBus/Tool communication (independent of the actual
 *   tool implementation)
 * - ToolInstance creates an instance of JavaToolShield (that runs as separate thread)
 * - JavaToolShield builds a table of all methods that are expected by the ToolBus.
 * - JavaToolshield creates an instance of the tool class. Note that the tool constructor
 *   should have one argument of type ToolShield that is used for tool/ToolShield communication.
 * - ToolInstance sends requests to ToolShield, which maintains them in a linked list
 * - Each request ultimately leads to a method call in the Java tool
 * - Results of method calls (or events) are sent back to ToolInstance (which queues them awaiting
 *   consumption by the ToolBus)
 */

public class JavaToolShield extends ToolShield {
	
	private ToolBus toolbus;
	
	private ToolDefinition toolDef; 				// Definition of the tool

	private String className; 						// Name of the class implementing the tool

	private Class toolClass; 						// The class itself

	private Constructor toolConstructor; 			// and its constructor function

	private Hashtable<String, Method> methodTable; // Table of methods that implement requests

	private TBTermFactory tbfactory; 				// Term factory to be used.

	private JavaToolBridge bridge;					// The bridge created for it
	
	private final int unitialized = -1;
	private final int running = 0;
	
	private int toolState = unitialized;

	/**
	 * The constructor for JavaToolShield. 
	 * @param toolDef the definition of this tool
	 * @param toolInstance the tool instance that created this JavaToolShield
	 */

	public JavaToolShield(ToolDefinition toolDef, ToolInstance toolInstance) {
		super(toolInstance);
		this.toolDef = toolDef;
		this.className = toolDef.getClassName();
		System.err.println("className = " + className);
		toolbus = toolInstance.getToolBus();
		
		methodTable = new Hashtable<String, Method>();
		tbfactory = toolInstance.getTBTermFactory();
	}

	synchronized public void executeTool() throws ToolBusException {
		try {
			URL[] urls = toolDef.getLoadPath();
			URLClassLoader loader = new URLClassLoader(urls);
			toolClass = Class.forName(className, false, loader);
		} catch (ClassNotFoundException e) {
			throw new ToolBusError("while starting tool " + toolDef.getName() + ": class " + className + " not found");
		}

		try {
			toolConstructor = findConstructor();
		} catch (Exception e) {
		throw new ToolBusError("while starting tool " + toolDef.getName() + ": appropriate constructor cannot be found");
		}
		
		String actuals[] = new String[] { "-TB_PORT",
				"" + toolbus.getWellKnownSocketPort(), "-TB_HOST",
				toolbus.getLocalHost().getHostName(), "-TB_TOOL_NAME",
				toolDef.getName(), "-TB_TOOL_ID",
				"" + getToolInstance().getToolCount(), "-TB_VERBOSE", "false" };

		System.err.println("JavaToolShield.executeTool");
		bridge = new JavaToolBridge(toolConstructor, toolInstance, actuals);
		toolState = running;
	}

	/**
	 * Find the constructor of the tool class.
	 * 
	 * @throws NoSuchMethodException
	 * @throws SecurityException
	 */

	private Constructor findConstructor() throws SecurityException,
			NoSuchMethodException {
		return toolClass.getConstructor(JavaToolBridge.class, String[].class);
	}

	synchronized public void connect(Object connection) throws IOException {
		if (connection instanceof JavaToolBridge) {
			bridge = (JavaToolBridge) connection;
			//if(cbridge != bridge){
			//	throw new IOException("connection object is instance of wrong JavaToolBridge");
			//}
			try {
				checkInputSignature();
			} catch (ToolBusException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} else {
			throw new IOException(
					"connection object should be instance of JavaToolBridge");
		}
		toolInstance.handleTermFromTool(tbfactory.make("snd-connect(<term>)",
				toolInstance.getToolId()));
		System.err.println("JavaToolShield.connect done");
	}

	/**
	 * Send an eval or do request to the tool by adding it to the request queue of the ToolShield
	 */

	synchronized public void sndRequestToTool(int operation, ATerm call) {
		System.err.println("sndRequestToTool(" + operation + ", " + call + ")");
		ATermAppl acall = (ATermAppl) call;

		String name;
		ATerm[] args;
		if (operation == ToolInstance.ACK) {
			name = "recAckEvent";
			args = new ATerm[] { call };
		} else if (operation == ToolInstance.TERMINATE) {
			name = "recTerminate";
			args = new ATerm[] { call };
		} else {
			name = acall.getName();
			args = acall.getArgumentArray();
		}

		Object actuals[] = new Object[args.length];

		Method m = (Method) methodTable.get(name);
		Class parameters[] = m.getParameterTypes();
		for (int i = 0; i < args.length; i++) {
			String ptype = parameters[i].getName();
			if (ptype.equals("int"))
				actuals[i] = new Integer(((ATermInt) args[i]).getInt());
			else if (ptype.equals("java.lang.String"))
				actuals[i] = ((ATermAppl) args[i]).getName();
			else
				actuals[i] = args[i];
		}
		try {
			bridge.handleTermFromToolBus(operation, m, actuals);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void terminate(ATerm msg) {
		if(toolState == running){
			System.err.println("JavaToolShield.terminate");
			sndRequestToTool(ToolInstance.TERMINATE, msg);
		}
	}

	/**
	 * Check equality of one type in a signature definition and a Java parameter type
	 */

	private boolean equalType(ATerm t, Class c) {
		//System.err.println("equalType(" + t + ", " + c + ")");
		if (t.getType() == ATerm.PLACEHOLDER) {
			t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());
		}
		String ctype = c.getName();
		if(ctype.equals("aterm.ATerm")){
			return true;
		}
		if (t == tbfactory.IntType) {
			return ctype.equals("int");
		} else if (t == tbfactory.StrType) {
			return ctype.equals("java.lang.String");
		} else if (t == tbfactory.TermType) {
			return ctype.equals("aterm.ATerm");
		} else if (t == tbfactory.VoidType) {
			return ctype.equals("void");
		}
		return false;
	}
	
	/**
	 * Check equality of a list of type in a signature definition and a lists of Java parameter types
	 */

	private boolean equalTypes(ATermList args, Class[] parameters){
		if (args.getLength() != parameters.length)
			return false;;
		for(Class parameter : parameters){
			if (!equalType(args.getFirst(), parameter))
				return false;
			args = args.getNext();
		}
		return true;
	}

	/**
	 * Find a method in the tool class with given name and argument types.
	 * @param call of the method
	 * @param returnsVoid should the class return void?
	 */

	private void findMethod(ATermAppl call, boolean returnsVoid)
			throws ToolBusException {
		String name = call.getName();
		ATermList args = call.getArguments();
		//System.err.println("findMethod(" + name + ", " + args + ")");

		Method methods[] = toolClass.getDeclaredMethods();

		for(Method method : methods){
			Class returntype = method.getReturnType();
			Class parameters[] = method.getParameterTypes();
			if (method.getName().equals(name)
					&& Modifier.isPublic(method.getModifiers())
				    && equalTypes(args, parameters)){
				
				if (returnsVoid && equalType(tbfactory.VoidType, returntype)) {
					methodTable.put(name, method);
					return;
				} else if (!returnsVoid && equalType(tbfactory.TermType, returntype)) {
					methodTable.put(name, method);
					return;
				}
			}
		}
		throw new ToolBusException("no method " + name + " found");
	}

	/**
	 * Print a method heading.
	 */

	private void printMethod(Method m) {
		Class returntype = m.getReturnType();
		Class parameters[] = m.getParameterTypes();
		System.err.print(Modifier.toString(m.getModifiers()) + " "
				+ returntype.getName() + " " + m.getName() + "(");
		for (int i = 0; i < parameters.length; i++) {
			System.err.print(parameters[i].getName() + " ");
		}
		System.err.println(")");
	}

	/**
	 * Check the required signature of the tool class
	 */

	private void checkInputSignature() throws ToolBusException {
		ATermList sigs = toolDef.getInputSignature();
		System.err.println("checkInputSignature(" + sigs + ")");
		while (!sigs.isEmpty()) {
			ATermAppl sig = (ATermAppl) sigs.getFirst();
			sigs = sigs.getNext();
			if (sig.getName().equals("rec-eval")) {
				ATermAppl call = (ATermAppl) sig.getArgument(1);
				findMethod(call, false);
			} else if (sig.getName().equals("rec-do")) {
				ATermAppl call = (ATermAppl) sig.getArgument(1);
				findMethod(call, true);
			} else if (sig.getName().equals("rec-ack-event")) {
				ATermAppl call = (ATermAppl) tbfactory.make(
						"recAckEvent(<term>)", tbfactory.TermPlaceholder);
				findMethod(call, true);
			} else if (sig.getName().equals("rec-terminate")) {
				ATermAppl call = (ATermAppl) tbfactory.make(
						"recTerminate(<term>)", tbfactory.TermPlaceholder);
				findMethod(call, true);
			}
		}
	}

}
