package toolbus.tool;

import java.lang.reflect.*;
import java.util.*;

import toolbus.*;

import aterm.*;

/**
 * ToolShield encapsulates an actual tool: it creates an instance of the class that implements the tool
 * and acts as communication channel between the tool and JavaTool. The fullpicture is:
 * - JavaTool implements interface ToolInstance (the ToolBus/Tool interface)
 * - Javatool creates an instance of ToolShield (that runs as separate thread)
 * - Toolshield creates an instance of the tool class. Note that the tool constructor
 *   should have one argument of type ToolBridge that is used for tool/ToolShield communication.
 * - JavaTool sends requests to ToolShield, which maintains them in a linked list
 * - Each request ultimately leads to a method call in the tool
 * - Results of method calls (or events) are send to JavaTool (which queues them awaiting
 *   consumption by the ToolBus)
 */

class ToolShield extends Thread implements ToolBridge {

  private Object toolinstance;
  private JavaTool javatool;
  private LinkedList requests;

  /**
   * The constructor for ToolShield. 
   * Arguments: the name of the tool class and the JavaTool that creates us.
   */

  public ToolShield(Constructor cons, JavaTool javatool) {
    try {
      Object actuals[] = new Object[] { this };
      toolinstance = cons.newInstance(actuals);
    } catch (Exception e) {
      System.out.println("ToolShield: " + e);
    }
    this.javatool = javatool;
    requests = new LinkedList();
  }

  /**
   * Add a request from JavaTool to the internal request list
   */

  public synchronized void addRequest(ATerm id, Integer operation, Method m, Object[] actuals) {
    requests.add(new Object[] { id, operation, m, actuals });
  }

  /**
   * Handle a single request from the list
   */

  private void handleRequest() {
    Object request[] = (Object[]) requests.getFirst();
    requests.removeFirst();

    ATerm id = (ATerm) request[0];
    Integer operation = (Integer) request[1];
    Method m = (Method) request[2];
    Object[] actuals = (Object[]) request[3];

    Object res = null;
    try {
      res = m.invoke(toolinstance, actuals);
    } catch (Exception e) {
      System.err.println("ToolShield.handleRequest: " + e);
      e.printStackTrace();
    }
    if (operation == JavaTool.EVAL) {
      javatool.addValue(id, res);
    } else if (operation == JavaTool.TERMINATE) {
      terminate("tool terminated by ToolShield");
    }
  }

  /**
   * The run method for this thread
   */

  public void run() {
    System.err.println("run of ToolShield called");
    while (true) {
      while (!requests.isEmpty())
        handleRequest();
      Thread.yield();
    }
  }

  /**
   *  Methods for the ToolBridge interface
   */

  /**
   * Provide the current ATermfactory.
   */

  public ATermFactory getFactory() {
    return TBTerm.factory;
  }

  /**
   * Send an event to JavaTool (and hence to the ToolBus)
   */

  public ATerm sndEventToToolBus(ATerm trm) {
    return javatool.addEvent(trm);
  }

  /**
   * Terminate execution of this tool
   */

  public void terminate(String msg) {
    System.err.println("ToolShield.terminate(" + msg + ")");
    try {
      join();
    } catch (InterruptedException e) {
    }
  }
}

/**
 * @author paulk, Jul 29, 2002
 * 
 * JavaTool creates the environment for running a JavaTool.
 * On creation it builds a table of all methods that are expected by the ToolBus.
 * Next a ToolShield is created to run the actual tool class.
 */

public class JavaTool implements ToolInstance {
  private String className;
  private Class toolClass;
  private Constructor toolConstructor;
  private Thread toolThread;
  private Object toolInstance;
  private Hashtable methodTable;
  private Hashtable valuesFromTool;
  private LinkedList eventsFromTool;
  private Hashtable pendingEvents;
  private ToolShield toolShield;

  protected static final Integer EVAL = new Integer(1);
  protected static final Integer DO = new Integer(2);
  protected static final Integer TERMINATE = new Integer(3);

  private static final String terminate = "terminate";

  /**
   * Constructor for JavaTool. Arguments are the name of the class implementing the
   * tool and a list of function signatures.
   */

  public JavaTool(ToolDefinition toolDef) throws ToolBusException {
    System.err.println("JavaTool");
    this.className = toolDef.getToolName();
    try {
      toolClass = Class.forName(className);
    } catch (ClassNotFoundException e) {
      throw new ToolBusException("class " + className + " not found");
    }
    methodTable = new Hashtable();
    valuesFromTool = new Hashtable();
    eventsFromTool = new LinkedList();
    pendingEvents = new Hashtable();
    toolConstructor = findConstructor();
    checkToolSignature(toolDef.getFunctionSignatures());
    toolShield = new ToolShield(toolConstructor, this);
    toolShield.start();
  }

  /**
   * Find the constructor of the tool class.
   */

  private Constructor findConstructor() throws ToolBusException {
    Constructor[] constructors = toolClass.getConstructors();
    for (int i = 0; i < constructors.length; i++) {
      Class parameters[] = constructors[i].getParameterTypes();
      if (parameters.length != 1 || !parameters[0].getName().equals("toolbus.tool.ToolBridge"))
        continue;
      else
        return constructors[i];
    }
    throw new ToolBusException("no appropriate constructor found for " + className);
  }

  /**
   * Check equality of types in a signature definition and a Java type
   */

  static private boolean equalType(ATerm t, Class c) {
    if (t.getType() == ATerm.PLACEHOLDER)
      t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());
    String ctype = c.getName();
    if (t == TBTerm.IntType)
      return ctype.equals("int");
    else if (t == TBTerm.StrType)
      return ctype.equals("java.lang.String");
    else if (t == TBTerm.TermType)
      return ctype.equals("aterm.ATerm");
    else if (t == TBTerm.VoidType)
      return ctype.equals("void");

    return false;
  }

  /**
   * Find a method in the tool class with given name and argument types.
   */

  private Method findMethod(String name, ATermList args, boolean returnsVoid) throws ToolBusException {
    System.err.println("findMethod(" + name + ", " + args + ")");
    Method methods[] = toolClass.getDeclaredMethods();
    searchMethods : for (int i = 0; i < methods.length; i++) {
      Class returntype = methods[i].getReturnType();
      Class parameters[] = methods[i].getParameterTypes();

      if (methods[i].getName().equals(name) && Modifier.isPublic(methods[i].getModifiers())) {
        if (args.getLength() != parameters.length)
          continue;
        for (int j = 0; j < parameters.length; j++) {
          if (!equalType(args.getFirst(), parameters[j]))
            continue searchMethods;
        }
        if (returnsVoid && equalType(TBTerm.VoidType, returntype))
          return methods[i];
        else if (!returnsVoid && equalType(TBTerm.TermType, returntype))
          return methods[i];
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

  private void checkToolSignature(ATermList sigs) throws ToolBusException {
    System.err.println("checkInputSignature(" + sigs + ")");

    while (!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl) sigs.getFirst();
      sigs = sigs.getNext();
      if (sig.getName().equals("Eval")) {
        ATerm call = sig.getArguments().getFirst();
        String name = ((ATermAppl) call).getName();
        ATermList args = ((ATermAppl) call).getArguments();
        methodTable.put(name, findMethod(name, args, false));
      }
      if (sig.getName().equals("AckEvent")) {
        String name = "ackEvent";
        ATermList args = TBTerm.factory.makeList(TBTerm.TermPlaceholder);
        args = TBTerm.factory.makeList(TBTerm.TermPlaceholder, args);
        args = TBTerm.factory.makeList(TBTerm.TermPlaceholder, args);
        methodTable.put(name, findMethod(name, args, true));
      }
      if (sig.getName().equals("Terminate")) {
        String name = terminate;
        ATermList args = TBTerm.factory.makeList(TBTerm.StrPlaceholder);
        methodTable.put(name, findMethod(name, args, true));
      }
    }

    if (methodTable.get(terminate) == null) {
      String name = terminate;
      ATermList args = TBTerm.factory.makeList(TBTerm.StrPlaceholder);
      methodTable.put(name, findMethod(name, args, true));
    }
  }

  /**
   * Send an evaluation request to the ToolShield.
   * (the answer will be returned by the ToolShield using addValue)
   */

  synchronized public void sndEvalToTool(ATerm id, ATermAppl call) {
    sndRequestToTool(id, EVAL, call);
  }

  /**
   * Send a do request to the tool.
   */

  synchronized public void sndDoToTool(ATerm id, ATermAppl call) {
    sndRequestToTool(id, DO, call);
  }

  /**
   * Send an eval or do request to the tool by adding it to the request queue of the ToolShield
   */

  private void sndRequestToTool(ATerm id, Integer operation, ATermAppl call) {
    System.err.println("sndRequestToTool(" + id + ", " + operation + ", " + call);
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
    toolShield.addRequest(id, operation, m, actuals);
  }

  /**
   * Send an acknowledgement to a previous event
   */

  synchronized public void sndAckToTool(ATerm id, ATerm result) throws ToolBusException {
    System.err.println("sndAckToTool(" + id + ", " + result);
    ATerm event = (ATerm) pendingEvents.get(id);
    if (event == null) {
      throw new ToolBusException("cannot acknowledge event: " + result);
    }
    AFun afun = TBTerm.factory.makeAFun("ackEvent", 3, false);
    ATermList args = TBTerm.factory.makeList(result);
    args = TBTerm.factory.makeList(event, args);
    args = TBTerm.factory.makeList(id, args);
    ATermAppl call = TBTerm.factory.makeAppl(afun, args);
    sndRequestToTool(id, DO, call);
  }

  /**
   * Add a return value to valuesFromTool
   */

  synchronized void addValue(ATerm id, Object obj) {
    valuesFromTool.put(id, obj);
    System.err.println("JavaTool.addValue: id = " + id + " obj = " + obj);
  }

  /** 
   * Add an event to eventsFromTool
   */

  synchronized ATerm addEvent(Object obj) {
    Object event[] = new Object[] { TBTerm.newTransactionId(), obj };
    eventsFromTool.addLast(event);
    System.err.println("JavaTool.addEvent: id = " + event[0] + " obj= = " + event[1]);
    return (ATerm) event[0];
  }

  /**
   * * Pass a value obtained from the ToolShield to the ToolBus
   * @see toolbus.tool.ToolInstance#getValueFromTool(ATerm, ATerm, Environment)
   */
  
  synchronized public boolean getValueFromTool(ATerm id, ATerm trm, Environment env) throws ToolBusException {
    System.err.println("getValueFormTool: " + id + " " + trm);
    ATerm result = (ATerm) valuesFromTool.get(id);
    if (result == null) {
      return false;
    } else {
      boolean matches = TBTerm.match(trm, env, result, new Environment());
      if (matches) {
        valuesFromTool.remove(id);
        return true;
      } else {
        return false;
      }
    }
  }

  /**
   * Pass an even obtained from the ToolShield to the ToolBus
   * @see toolbus.tool.ToolInstance#getEventFromTool(ATerm, ATerm, Environment)
   */

  synchronized public boolean getEventFromTool(ATerm id, ATerm trm, Environment env) {
    System.err.println("getEventFromTool: " + id + " " + trm);
    for (int i = 0; i < eventsFromTool.size(); i++) {
      try {
        Object event[] = (Object[]) eventsFromTool.get(i);
        ATerm eventId = (ATerm) event[0];
        ATerm eventTerm = (ATerm) event[1];
        boolean matches = TBTerm.match(trm, env, eventTerm, new Environment());
        System.err.println(matches + " " + eventId + eventTerm);
        if (matches) {
          env.assignVar(id, eventId);
          eventsFromTool.remove(i);
          pendingEvents.put(eventId, eventTerm);
          return true;
        }
      } catch (ToolBusException e) {
        System.err.println("getFromTool: cannot happen :-)");
      }
    }
    System.err.println("getEventFromTool returns false");
    return false;
  }

  /**
   * Terminate the execution of this tool.
   * @see toolbus.tool.ToolInstance#terminate(ATerm, String)
   */

  public void terminate(ATerm id, String msg) {
    Object actuals[] = new Object[] { msg };
    Method m = (Method) methodTable.get(terminate);
    printMethod(m);
    if (m == null) {
      throw new ToolBusInternalError("no terminate method");
    }
    toolShield.addRequest(id, TERMINATE, m, actuals);
  }
}
