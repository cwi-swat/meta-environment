package toolbus.tool;

import java.lang.reflect.*;
import java.util.*;

import toolbus.*;

import aterm.*;

class ToolShield extends Thread implements ToolBridge {

  private Object toolinstance;
  private JavaTool javatool;
  private LinkedList requests;

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

  public synchronized void addRequest(ATerm id, Integer operation, Method m, Object[] actuals) {
    requests.add(new Object[] { id, operation, m, actuals });
  }

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

  public ATermFactory getFactory() {
    return TBTerm.factory;
  }

  public ATerm sndEventToToolBus(ATerm trm) {
    return javatool.addEvent(trm);
  }

  public void run() {
    System.err.println("run of ToolShield called");
    while (true) {
      while (!requests.isEmpty())
        handleRequest();
      Thread.yield();
    }
  }

  public void terminate(String msg) {
    System.err.println("ToolShield.terminate(" + msg + ")");
    try {
      join();
      stop();
    } catch (ThreadDeath e) {
    } catch (InterruptedException e) {
    }
  }
}

/**
 * @author paulk, Jul 29, 2002
 */

public class JavaTool implements ToolInstance {
  private String className;
  //private ATerm toolId;
  private Class toolclass;
  private Constructor toolconstructor;
  private Thread toolthread;
  private Object toolinstance;
  private Hashtable methodtable;
  private Hashtable valuesFromTool;
  private LinkedList eventsFromTool;
  private Hashtable pendingEvents;
  private ToolShield toolshield;

  protected static final Integer EVAL = new Integer(1);
  protected static final Integer DO = new Integer(2);
  protected static final Integer TERMINATE = new Integer(3);

  private static final String terminate = "terminate";

  public JavaTool(String className, ATerm toolId, ATermList sigs) throws ToolBusException {
    System.err.println("JavaTool");
    this.className = className;
    //    this.toolId = toolId;
    try {
      toolclass = Class.forName(className);
    } catch (ClassNotFoundException e) {
      throw new ToolBusException("class " + className + " not found");
    }
    methodtable = new Hashtable();
    valuesFromTool = new Hashtable();
    eventsFromTool = new LinkedList();
    pendingEvents = new Hashtable();
    toolconstructor = findConstructor();
    checkInputSignature(sigs);
    toolshield = new ToolShield(toolconstructor, this);
    toolshield.start();
  }

  private Constructor findConstructor() throws ToolBusException {
    Constructor[] constructors = toolclass.getConstructors();
    for (int i = 0; i < constructors.length; i++) {
      Class parameters[] = constructors[i].getParameterTypes();
      if (parameters.length != 1 || !parameters[0].getName().equals("toolbus.tool.ToolBridge"))
        continue;
      else
        return constructors[i];
    }
    throw new ToolBusException("no appropriate constructor found for " + className);
  }

  static private boolean equalType(ATerm t, Class c) {

    if (t.getType() == ATerm.PLACEHOLDER)
      t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());

    System.err.println("equalType(" + t + ", " + c + ")");

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

  private Method findMethod(String name, ATermList args, boolean returnsVoid) throws ToolBusException {
    System.err.println("findMethod(" + name + ", " + args + ")");
    Method methods[] = toolclass.getDeclaredMethods();
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

  private void printMethod(Method m) {
    Class returntype = m.getReturnType();
    Class parameters[] = m.getParameterTypes();
    System.err.print(Modifier.toString(m.getModifiers()) + " " + returntype.getName() + " " + m.getName() + "(");
    for (int i = 0; i < parameters.length; i++) {
      System.err.print(parameters[i].getName() + " ");
    }
    System.err.println(")");
  }

  private void checkInputSignature(ATermList sigs) throws ToolBusException {
    System.err.println("checkInputSignature(" + sigs + ")");

    while (!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl) sigs.getFirst();
      sigs = sigs.getNext();
      if (sig.getName().equals("Eval")) {
        ATerm call = sig.getArguments().getFirst();
        String name = ((ATermAppl) call).getName();
        ATermList args = ((ATermAppl) call).getArguments();
        methodtable.put(name, findMethod(name, args, false));
      }
      if (sig.getName().equals("AckEvent")) {
        String name = "ackEvent";
        ATermList args = TBTerm.factory.makeList(TBTerm.TermPlaceholder);
        args = TBTerm.factory.makeList(TBTerm.TermPlaceholder, args);
        args = TBTerm.factory.makeList(TBTerm.TermPlaceholder, args);
        methodtable.put(name, findMethod(name, args, true));
      }
      if (sig.getName().equals("Terminate")) {
        String name = terminate;
        ATermList args = TBTerm.factory.makeList(TBTerm.StrPlaceholder);
        methodtable.put(name, findMethod(name, args, true));
      }
    }

    if (methodtable.get(terminate) == null) {
      String name = terminate;
      ATermList args = TBTerm.factory.makeList(TBTerm.StrPlaceholder);
      methodtable.put(name, findMethod(name, args, true));
    }
  }

  public void terminate(ATerm id, String msg) {
    Object actuals[] = new Object[] { msg };
    Method m = (Method) methodtable.get(terminate);
    printMethod(m);
    if(m == null){
      throw new ToolBusInternalError("no terminate method");
    }
    toolshield.addRequest(id, TERMINATE, m, actuals);
  }

  private void sndRequestToTool(ATerm id, Integer operation, ATermAppl call) {
    System.err.println("sndRequestToTool(" + id + ", " + operation + ", " +call);
    String name = call.getName();
    ATerm[] args = call.getArgumentArray();
    Object actuals[] = new Object[args.length];

    Method m = (Method) methodtable.get(name);
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
    toolshield.addRequest(id, operation, m, actuals);
  }

  synchronized public void sndEvalToTool(ATerm id, ATermAppl call) {
    sndRequestToTool(id, EVAL, call);
  }

  synchronized public void sndDoToTool(ATerm id, ATermAppl call) {
    sndRequestToTool(id, DO, call);
  }

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

  synchronized void addValue(ATerm id, Object obj) {
    valuesFromTool.put(id, obj);
    System.err.println("JavaTool.addValue: id = " + id + " obj = " + obj);
  }

  synchronized ATerm addEvent(Object obj) {
    Object event[] = new Object[] { TBTerm.newTransactionId(), obj };
    eventsFromTool.addLast(event);
    System.err.println("JavaTool.addEvent: id = " + event[0] + " obj= = " + event[1]);
    return (ATerm) event[0];
  }

  //  synchronized public ATerm getToolId() {
  //    return toolId;
  //  }

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
}
