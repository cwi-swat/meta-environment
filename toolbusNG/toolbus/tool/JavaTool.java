package toolbus.tool;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Hashtable;
import java.util.LinkedList;

import toolbus.Environment;
import toolbus.MatchResult;
import toolbus.TBTerm;
import toolbus.ToolBusException;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ATermPlaceholder;

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

	public synchronized void addRequest(
		Integer operation,
		Method m,
		Object[] actuals) {
		requests.addLast(operation);
		requests.addLast(m);
		requests.addLast(actuals);
	}

	private void handleRequest() {
		Integer operation = (Integer) requests.getFirst();
		requests.removeFirst();

		Method m = (Method) requests.getFirst();
		requests.removeFirst();

		Object[] actuals = (Object[]) requests.getFirst();
		requests.removeFirst();

		Object res = null;
		try {
			res = m.invoke(toolinstance, actuals);
		} catch (Exception e) {
			System.out.println("ToolShield.handleRequest: " + e);
			e.printStackTrace();
		}
		if (operation == JavaTool.EVAL) {
			javatool.addValue(res);
		}
	}

	public ATermFactory getFactory() {
		return TBTerm.factory;
	}

	public void sndValueToToolBus(ATerm trm) {
		javatool.addValue(trm);
	}

	public void sndEventToToolBus(ATerm trm) {
		javatool.addEvent(trm);
	}

	public void run() {
		System.out.println("run of ToolShield called");
		while (true) {
			while (!requests.isEmpty())
				handleRequest();
			Thread.yield();
		}
	}
	
	public void terminate(String msg){
		System.out.println("ToolShield.terminate(" + msg + ")");
		try {
			join(0);
		} catch (InterruptedException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
}

/**
 * @author paulk, Jul 29, 2002
 */

public class JavaTool implements ToolInstance {
	private String className;
	private ATerm toolId;
	private Class toolclass;
	private Constructor toolconstructor;
	private Thread toolthread;
	private Object toolinstance;
	private Hashtable methodtable;
	private LinkedList valuesFromTool;
	private LinkedList eventsFromTool;
	private ToolShield toolshield;

	protected static final Integer EVAL = new Integer(1);
	protected static final Integer DO = new Integer(2);
	private static final String terminate = "terminate";

	public JavaTool(String className, ATerm toolId, ATermList sigs)
		throws ToolBusException {
		System.out.println("JavaTool");
		this.className = className;
		this.toolId = toolId;
		try {
			toolclass = Class.forName(className);
		} catch (ClassNotFoundException e) {
			throw new ToolBusException("class " + className + " not found");
		}
		methodtable = new Hashtable();
		valuesFromTool = new LinkedList();
		eventsFromTool = new LinkedList();
		toolconstructor = findConstructor();
		checkInputSignature(sigs);
		toolshield = new ToolShield(toolconstructor, this);
		toolshield.start();
	}

	private Constructor findConstructor() throws ToolBusException {
		Constructor[] constructors = toolclass.getConstructors();
		for (int i = 0; i < constructors.length; i++) {
			Class parameters[] = constructors[i].getParameterTypes();
			if (parameters.length != 1
				|| !parameters[0].getName().equals("toolbus.tool.ToolBridge"))
				continue;
			else
				return constructors[i];
		}
		throw new ToolBusException(
			"no appropriate constructor found for " + className);
	}

	static private boolean equalType(ATerm t, Class c) {

		if (t.getType() == ATerm.PLACEHOLDER)
			t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());

		System.out.println("equalType(" + t + ", " + c + ")");

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

	private Method findMethod(String name, ATermList args, boolean returnsVoid)
		throws ToolBusException {
		System.out.println("findMethod(" + name + ", " + args + ")");
		Method methods[] = toolclass.getDeclaredMethods();
		searchMethods : for (int i = 0; i < methods.length; i++) {
			Class returntype = methods[i].getReturnType();
			Class parameters[] = methods[i].getParameterTypes();

			if (methods[i].getName().equals(name)
				&& Modifier.isPublic(methods[i].getModifiers())) {
				if (args.getLength() != parameters.length)
					continue;
				for (int j = 0; j < parameters.length; j++) {
					if (!equalType(args.getFirst(), parameters[j]))
						continue searchMethods;
				}
				if (returnsVoid && equalType(TBTerm.VoidType, returntype))
					return methods[i];
				else if (
					!returnsVoid && equalType(TBTerm.TermType, returntype))
					return methods[i];
			}
		}
		throw new ToolBusException("no method " + name + " found");
	}
	
	private void printMethod(Method m){
		Class returntype = m.getReturnType();
		Class parameters[] = m.getParameterTypes();
		System.out.print(Modifier.toString(m.getModifiers()) + " " + returntype.getName() + " " + m.getName() + "(");
		for(int i = 0; i < parameters.length; i++){
			System.out.print(parameters[i].getName() + " ");
		}
		System.out.println(")");
	}
	

	private void checkInputSignature(ATermList sigs) throws ToolBusException {
		System.out.println("checkInputSignature(" + sigs + ")");

		while (!sigs.isEmpty()) {
			ATermAppl sig = (ATermAppl) sigs.getFirst();
			sigs = sigs.getNext();
			if (sig.getName().equals("toolbus.atom.Eval")) {
				ATerm call = sig.getArguments().getFirst();
				String name = ((ATermAppl) call).getName();
				ATermList args = ((ATermAppl) call).getArguments();
				methodtable.put(name, findMethod(name, args, false));
			}
			if (sig.getName().equals("toolbus.atom.AckEvent")) {
				String name = "ackEvent";
				ATermList args =
					TBTerm.factory.makeList(TBTerm.TermPlaceholder);
				methodtable.put(name, findMethod(name, args, true));
			}
			if (sig.getName().equals("toolbus.atom.Terminate")) {
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

	public void terminate(String msg) {
		Object actuals[] = new Object[] { msg };
		Method m = (Method) methodtable.get(terminate);
		printMethod(m);
		toolshield.addRequest(DO, m, actuals);
	}

	private void sndRequestToTool(Integer operation, ATermAppl call) {
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
		toolshield.addRequest(operation, m, actuals);
	}

	synchronized public void sndEvalToTool(ATermAppl call) {
		sndRequestToTool(EVAL, call);
	}

	synchronized public void sndDoToTool(ATermAppl call) {
		sndRequestToTool(DO, call);
	}

	synchronized void addValue(Object obj) {
		valuesFromTool.addLast(obj);
		System.out.println("JavaTool.addValue: queued " + obj);
	}

	synchronized void addEvent(Object obj) {
		eventsFromTool.addLast(obj);
		System.out.println("JavaTool.addEvent: queued " + obj);
	}

	synchronized public ATerm getToolId() {
		return toolId;
	}

	private MatchResult getFromTool(
		ATerm trm,
		Environment env,
		LinkedList fromTool) {
		System.out.println(
			"getFromTool(" + trm + "), length fromTool = " + fromTool.size());
		if (!fromTool.isEmpty()) {
			try {
				System.out.println("first = " + fromTool.getFirst());
				MatchResult mr =
					TBTerm.match(
						trm,
						env,
						(ATerm) fromTool.getFirst(),
						new Environment());
				fromTool.removeFirst();
				System.out.println("getFromTool returns: " + mr);
				return mr;
			} catch (ToolBusException e) {
				System.out.println("getFromTool: cannot happen :-)");
			}
		}
		System.out.println("getFromTool returns false");
		return new MatchResult(false, null, null);
	}

	synchronized public MatchResult getValueFromTool(
		ATerm trm,
		Environment env) {
		return getFromTool(trm, env, valuesFromTool);
	}

	synchronized public MatchResult getEventFromTool(
		ATerm trm,
		Environment env) {
		return getFromTool(trm, env, eventsFromTool);
	}

}
