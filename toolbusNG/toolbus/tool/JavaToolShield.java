
package toolbus.tool;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Hashtable;

import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.ToolBusInternalError;
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
	private String className;
	private Class toolClass;
	private ToolDefinition toolDef;
	private Constructor toolConstructor;
	private Object javaToolObject;
	private Hashtable methodTable;
	private static final String terminate = "terminate";

  /**
   * The constructor for JavaToolShield. 
   * @param toolDef the definition of this tool
   * @param toolInstance the tool instance that created this JavaToolShield
   */

  public JavaToolShield(ToolDefinition toolDef, ToolInstance toolInstance) {
  	super(toolInstance);
  	this.toolDef = toolDef;
    this.className = toolDef.getCommand();
    try {
      toolClass = Class.forName(className);
    } catch (ClassNotFoundException e) {
      System.err.println("class " + className + " not found");
    }
    methodTable = new Hashtable();
    try {
    	toolConstructor = findConstructor();
    	checkToolSignature();
      Object actuals[] = new Object[] { this };
      javaToolObject = toolConstructor.newInstance(actuals);
    } catch (Exception e) {
      System.out.println("JavaToolShield: " + e);
    }
  }
  
  /**
   * Find the constructor of the tool class.
   */

  private Constructor findConstructor() throws ToolBusException {
    Constructor[] constructors = toolClass.getConstructors();
    for (int i = 0; i < constructors.length; i++) {
      Class parameters[] = constructors[i].getParameterTypes();
      if (parameters.length == 1 && parameters[0].getName().equals("toolbus.tool.ToolShield")) {
        return constructors[i];
      }
    }
    throw new ToolBusException("no appropriate constructor found for " + className);
  }

  /**
   * Check equality of types in a signature definition and a Java type
   */

  static private boolean equalType(ATerm t, Class c) {
    if (t.getType() == ATerm.PLACEHOLDER) {
      t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());
    }
    String ctype = c.getName();
    if (t == TBTerm.IntType) {
      return ctype.equals("int");
    } else if (t == TBTerm.StrType) {
      return ctype.equals("java.lang.String");
    } else if (t == TBTerm.TermType) {
      return ctype.equals("aterm.ATerm");
    } else if (t == TBTerm.VoidType) {
      return ctype.equals("void");
    }
    return false;
  }
  
  /**
   * Find a method in the tool class with given name and argument types.
   * @param call of the method
   * @param returnsVoid doe sthe class return void?
   */

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
        
        if (returnsVoid && equalType(TBTerm.VoidType, returntype)) {
        	methodTable.put(name, methods[i]);
            return;
        } else if (!returnsVoid && equalType(TBTerm.TermType, returntype)) {
        	methodTable.put(name, methods[i]);
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
    System.err.print(Modifier.toString(m.getModifiers()) + " " + returntype.getName() + " " + m.getName() + "(");
    for (int i = 0; i < parameters.length; i++) {
      System.err.print(parameters[i].getName() + " ");
    }
    System.err.println(")");
  }
  
  /**
   * Check the required signature of the tool class
   */

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
  					ATermAppl call = (ATermAppl) TBTerm.factory.make("ackEvent(<term>)", TBTerm.TermPlaceholder);
  					findMethod(call, true);
  				} else
  					if (sig.getName().equals("Terminate")) {
  						ATermAppl call = (ATermAppl) TBTerm.factory.make("terminate(<term>)", TBTerm.StrPlaceholder);
  						findMethod(call, true);
  					}
  	}
  }
  
  /**
   * Send an eval or do request to the tool by adding it to the request queue of the ToolShield
   */

  public void sndRequestToTool(Integer operation, ATermAppl call) {
    System.err.println("sndRequestToTool(" + operation + ", " + call + ")");
    String name = call.getName();
    ATerm[] args = call.getArgumentArray();
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
    addRequestForTool(new Object[] { operation, m, actuals} );
  }

  /**
   * Handle the next request for the tool
   */

  protected void handleRequestForTool() {
    Object request[] = getNextRequestForTool();

    Integer operation = (Integer) request[0];
    Method m = (Method) request[1];
    Object[] actuals = (Object[]) request[2];

    Object res = null;
    try {
      res = m.invoke(javaToolObject, actuals);
    } catch (Exception e) {
      System.err.println("JavaToolShield.handleRequest: " + e);
      e.printStackTrace();
    }
    if (operation == ToolInstance.EVAL) {
      getToolInstance().addValueFromTool(/*id, */res);
    } else if (operation == ToolInstance.TERMINATE) {
    	stopRunning();
    }
  }
  
  public void terminate(String msg) {
  	System.err.println("JavaToolShield.terminate");
    Object actuals[] = new Object[] { msg };
    Method m = (Method) methodTable.get(terminate);

    if (m == null){
    	stopRunning();
    } else {
    	printMethod(m);
    	addRequestForTool(new Object[] {ToolInstance.TERMINATE, m, actuals});
    }
  }
 
}
