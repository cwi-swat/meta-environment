
package toolbus.tool.java;

import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.nio.channels.SocketChannel;
import java.util.Hashtable;
import java.util.LinkedList;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.ToolShield;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ATermPlaceholder;

/*
class JavaToolShieldThread extends Thread {
	private ToolShield javaToolShield;
	private Object javaToolInstance;         // The instance created for this tool
	private LinkedList requests = new LinkedList();
	private boolean running = false;
	
	public JavaToolShieldThread(ToolShield jts, Constructor toolConstructor, Object[] actuals){
		javaToolShield = jts;
	     try {
			javaToolInstance = toolConstructor.newInstance(actuals);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}
	
	public void connect(){
		
	}
	
	synchronized void addRequestForTool(int operation, Method m, Object[] actuals){
		requests.addLast(new Object[] { operation, m, actuals});
	}
	
	protected void handleRequestForTool() {
	    Object request[] = (Object[])requests.getFirst();
	    requests.removeFirst();

	    Integer operation = (Integer) request[0];
	    Method m = (Method) request[1];
	    Object[] actuals = (Object[]) request[2];

	    ATerm res = null;
	    try {
	      res = (ATerm) m.invoke(javaToolInstance, actuals);
	    } catch (Exception e) {
	      System.err.println("ToolShield.handleRequest: " + e);
	      e.printStackTrace();
	    }
	    if (operation == ToolInstance.EVAL) {
	      javaToolShield.sndValueFromToolToToolBus(res);
	    } else if (operation == ToolInstance.TERMINATE) {
	      javaToolShield.terminate(javaToolShield.getTBTermFactory().make("tool terminated by ToolShield"));
	    }
	  }
	
	public void run(){
		while(running){
			while(requests.size() > 0){
				handleRequestForTool();
			}
			try {
				sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public void stopRunning(){
		running = false;
	}
}
*/

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
	private ToolDefinition toolDef;          // Definition of the tool
	private String className;                // Name of the class implementing the tool
	private Class toolClass;                 // The class itself
	private Constructor toolConstructor;	 // and its constructor function

	private Hashtable<String,Method> methodTable;           // Table of methods that implement requests
	private TBTermFactory tbfactory;         // Term factory to be used.
	
	private static final String terminate = "terminate";
	
	private Object javaToolInstance;			// The actual instance of the constructor class for this tool
	private AbstractTool abstractToolInstance; // The AbstractTool instance ("bridge") created by it

  /**
   * The constructor for JavaToolShield. 
   * @param toolDef the definition of this tool
   * @param toolInstance the tool instance that created this JavaToolShield
   */

  public JavaToolShield(ToolDefinition toolDef, ToolInstance toolInstance) {
  	super(toolInstance);
  	this.toolDef = toolDef;
    this.className = toolDef.getCommand();
    System.err.println("className = " + className);
    try {
      toolClass = Class.forName(className);
    } catch (ClassNotFoundException e) {
      System.err.println("class " + className + " not found");
    }
    methodTable = new Hashtable<String,Method>();
    tbfactory = toolInstance.getTBTermFactory();
    try {
    	toolConstructor = findConstructor();
  
        String actuals[] = new String[] { 
        		"-TB_PORT", "" + ToolBus.getWellKnownSocketPort(),
        		"-TB_HOST", ToolBus.getLocalHost().getHostName(),
        		"-TB_TOOL_NAME", toolDef.getName(),
        		"-TB_TOOL_ID", "" + toolInstance.getToolCount(),
        		"-TB_VERBOSE", "false" };
			
        javaToolInstance = toolConstructor.newInstance(new Object[] { actuals });
    } catch (Exception e) {
      System.out.println("JavaToolShield: " + e);
      e.printStackTrace();
    }
  }
  
  /**
   * Find the constructor of the tool class.
   */

  private Constructor findConstructor() throws ToolBusException {
    Constructor[] constructors = toolClass.getConstructors();
    for (int i = 0; i < constructors.length; i++) {
      Class parameters[] = constructors[i].getParameterTypes();
      if(parameters.length >= 1){
    	  System.err.println("findConstructor: " + parameters[0].getName());
      }
      System.err.println(parameters[0].getSimpleName() + " ; " + parameters[0].isArray());
      if (parameters.length == 1 && 
    	  parameters[0].getSimpleName().equals("String[]")){
        return constructors[i];
      }
    }
    throw new ToolBusException("no appropriate constructor found for " + className);
  }
  
  public void connect(Object connection) throws IOException {
		if(connection instanceof AbstractTool){
			abstractToolInstance = (AbstractTool) connection;	
		  	abstractToolInstance.checkInputSignature(toolDef.getInputSignature());
		} else {
			throw new IOException("connection object should be instance of AbstractTool");
		}
	}
  
  /**
   * Send an eval or do request to the tool by adding it to the request queue of the ToolShield
   */

  public void sndRequestToTool(Integer operation, ATerm call) {
		AFun fun = tbfactory.makeAFun(ToolInstance.OperatorForTool[operation.intValue()], 1, false);
		ATermAppl req = tbfactory.makeAppl(fun, call);
		try {
			abstractToolInstance.handleIncomingTerm(req);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
  }
  
  public void terminate(ATerm msg) {
		System.err.println("JavaToolShield.terminate");

		sndRequestToTool(ToolInstance.TERMINATE, msg);
	}

  /**
	 * Check equality of types in a signature definition and a Java type
	 */
/*
  private boolean equalType(ATerm t, Class c) {
    if (t.getType() == ATerm.PLACEHOLDER) {
      t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());
    }
    String ctype = c.getName();
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
  */
  
  /**
   * Find a method in the tool class with given name and argument types.
   * @param call of the method
   * @param returnsVoid should the class return void?
   */
/*
  private void findMethod(ATermAppl call, boolean returnsVoid) throws ToolBusException {
    String name = call.getName();
    ATermList args = call.getArguments();
    System.err.println("findMethod(" + name + ", " + args + ")");
    
    Method methods[] = toolClass.getDeclaredMethods();
    
    // HDJ: todo: refactor inner loop to separate method to avoid the need for label.
    searchMethods : 
      for (int i = 0; i < methods.length; i++) {
      Class returntype = methods[i].getReturnType();
      Class parameters[] = methods[i].getParameterTypes();

      if (methods[i].getName().equals(name) && Modifier.isPublic(methods[i].getModifiers())) {
        if (args.getLength() != parameters.length)
          continue;
        
        for (int j = 0; j < parameters.length; j++) {
          if (!equalType(args.getFirst(), parameters[j]))
            continue searchMethods;
          args = args.getNext();
        }
        
        if (returnsVoid && equalType(tbfactory.VoidType, returntype)) {
        	methodTable.put(name, methods[i]);
            return;
        } else if (!returnsVoid && equalType(tbfactory.TermType, returntype)) {
        	methodTable.put(name, methods[i]);
            return;
        }
      }
    }
    throw new ToolBusException("no method " + name + " found");
  }
  */
  
  /**
   * Print a method heading.
   */

  private void printMethod(Method m) {
    Class returntype = m.getReturnType();
    Class parameters[] = m.getParameterTypes();
    System.err.print(Modifier.toString(m.getModifiers()) + " " + returntype.getName() + " " + m.getName() + "(");
    for (int i = 0; i < parameters.length; i++) {
      System.err.print(parameters[i].getName() + " ");
    }
    System.err.println(")");
  }
  
  /**
   * Check the required signature of the tool class
   */
/*
  private void checkToolSignature() throws ToolBusException {
  	ATermList sigs = toolDef.getInputSignature();
 	System.err.println("checkInputSignature(" + sigs + ")");
  	while(!sigs.isEmpty()){
  		ATermAppl sig = (ATermAppl) sigs.getFirst();
 		sigs = sigs.getNext();
  		if (sig.getName().equals("Eval")) {
  			ATermAppl call = (ATermAppl) sig.getArgument(1);
  			findMethod(call, false);
  		} else
  			if (sig.getName().equals("Do")) {
  				ATermAppl call = (ATermAppl) sig.getArgument(1);
  				findMethod(call, true);
  			} else
  				if (sig.getName().equals("AckEvent")) {
  					ATermAppl call = (ATermAppl) tbfactory.make("ackEvent(<term>)", tbfactory.TermPlaceholder);
  					findMethod(call, true);
  				} else
  					if (sig.getName().equals("Terminate")) {
  						ATermAppl call = (ATermAppl) tbfactory.make("terminate(<term>)", tbfactory.StrPlaceholder);
  						findMethod(call, true);
  					}
  	}
  }
  */
  
  /**
   * Send an eval or do request to the tool by adding it to the request queue of the ToolShield
   */
/*
  public void sndRequestToTool(Integer operation, ATerm call) {
    System.err.println("sndRequestToTool(" + operation + ", " + call + ")");
    ATermAppl acall = (ATermAppl) call;
    String name = acall.getName();
    ATerm[] args = acall.getArgumentArray();
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
    shield.addRequestForTool(operation, m, actuals);
  }
  
 // synchronized protected void returnValueFromTool(ATerm res){
//	  getToolInstance().addValueFromTool(res);
 // }
  
 */
	

}
