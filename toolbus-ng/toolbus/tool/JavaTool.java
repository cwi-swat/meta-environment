package toolbus.tool;

import toolbus.ToolBusException;

import aterm.*;
import aterm.pure.*;
import toolbus.*;
import java.lang.reflect.*;
import java.util.Hashtable;
import java.util.LinkedList;

class ToolShield extends Thread {
	private Object toolinstance;
	private JavaTool javatool;
	private LinkedList requests;
	
	public ToolShield (Constructor cons, ToolBridge bridge, JavaTool javatool)
	{
		try {
			Object actuals[] = new Object[] { bridge };
			toolinstance = cons.newInstance(actuals);
		} catch (Exception e) {
			System.out.println("ToolShield: " + e);
		}
		this.javatool = javatool;
		requests = new LinkedList();
	}
	
	public synchronized void addRequest(Method m, Object[] actuals){
		requests.addLast(m);
		requests.addLast(actuals);
	}
	
	private void handleRequest()
	{
		Method m = (Method) requests.getFirst(); 
		requests.removeFirst();
	
		Object[] actuals = (Object[])requests.getFirst();
		requests.removeFirst();
	
		Object res = null;
  		try {
  			res = m.invoke(toolinstance, actuals);
  		}
  		catch (Exception e){
  				System.out.println("ToolShield.request: " + e);
  		}
  		javatool.add(res);
	}
	
	public void run(){
		System.out.println("run of ToolShield called");
		while(true){
			while(!requests.isEmpty())
				handleRequest();
			Thread.yield();
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
	private ToolBridge bridge;
	private LinkedList fromTool;
	private ToolShield toolshield;

	public JavaTool(String className, ATerm toolId, ToolBridge bridge, ATermList sigs) throws ToolBusException {
		this.className = className;
		this.toolId = toolId;
		this.bridge = bridge;
		try {
			toolclass = Class.forName(className);
		}
		catch (ClassNotFoundException e){
			throw new ToolBusException("class "+ className + " not found");
		}
		methodtable = new Hashtable();
		fromTool = new LinkedList();
		toolconstructor = findConstructor();
		checkInputSignature(sigs);
		toolshield = new ToolShield(toolconstructor, bridge, this);
		toolshield.start();
	}
	
//	public void run(){
//		System.out.println("JavaTool: run");	
//	}
	
	private Constructor findConstructor() throws ToolBusException 
	{
		Constructor[] constructors = toolclass.getConstructors();
		for(int i = 0; i < constructors.length; i++){
			Class parameters[] = constructors[i].getParameterTypes();
			if(parameters.length != 1 || !parameters[0].getName().equals("toolbus.tool.ToolBridge"))
				continue;
			else
				return constructors[i];
		}
		throw new ToolBusException("no appropriate constructor found for " + className);
	}
	
	public void setToolInstance(Object ti){
		toolinstance = ti;
		System.out.println("setToolInstance("+ ti + ")");
	}
	
	static private boolean equalType(ATerm t, Class c){
		
		if(t.getType() == ATerm.PLACEHOLDER)
			t = ((ATermAppl) ((ATermPlaceholder) t).getPlaceholder());
			
		//System.out.println("equalType(" + t + ", " + c + ")");
		
		String ctype = c.getName();
				
		if(t == TBTerm.IntType)
			return  ctype.equals("int");
		else
		if(t == TBTerm.StrType)
			return ctype.equals("String");
		else
		if(t == TBTerm.TermType)
				return ctype.equals("aterm.ATerm");
		return false;
	}
	
	private Method findMethod(String name, ATermList args, boolean returnsVoid)
	throws ToolBusException
	{
		//System.out.println("findMethod(" + name + ", " + args + ")");
		Method methods[] = toolclass.getDeclaredMethods();
	searchMethods:
		for(int i = 0; i < methods.length; i++){
			Class returntype = methods[i].getReturnType();
			Class parameters[] = methods[i].getParameterTypes();
				
			if(methods[i].getName().equals(name) && Modifier.isPublic(methods[i].getModifiers())){
				if(args.getLength() != parameters.length)
					continue;	
				for(int j = 0; j < parameters.length; j++){
					if(!equalType(args.getFirst(), parameters[j]))
						continue searchMethods;
				}
				if(returnsVoid &&  equalType(TBTerm.VoidType, returntype))
					return methods[i];
				else
				if(!returnsVoid && equalType(TBTerm.TermType, returntype))
					return methods[i];
			}
		}
		throw new ToolBusException("no method " + name + " found");
	}
	
	private void  checkInputSignature(ATermList sigs)
	throws ToolBusException
	{
		System.out.println("checkInputSignature("  + sigs + ")");
		
		while(!sigs.isEmpty()) {
      		ATermAppl sig = (ATermAppl)sigs.getFirst();
      		sigs = sigs.getNext();
      		if(sig.getName() == "rec-eval"){
      			ATerm call = sig.getArguments().getNext().getFirst();
      			String name = ((ATermAppl) call).getName();
      			ATermList args = ((ATermAppl) call).getArguments();
      			methodtable.put(name, findMethod(name, args, false));
      		}
		}
	}
	
  	synchronized public void sndTermToTool(ATermAppl call){
  		String name = call.getName();
  		ATerm[] args = call.getArgumentArray();
  		Object actuals[]= new Object[args.length];
  		
  		Method m = (Method) methodtable.get(name);
  		Class parameters[] = m.getParameterTypes();
  		for(int i = 0; i < args.length; i++){
  			String ptype = parameters[i].getName();
  			if(ptype.equals("int"))
  				actuals[i] = new Integer(((ATermInt) args[i]).getInt());
  			else
  			if(ptype.equals("String"))
  				actuals[i] = ((ATermAppl) args[i]).getName();
  			else
  				actuals[i] = args[i];
  		}
  		toolshield.addRequest(m, actuals);		
  	}
  	
  	synchronized void add(Object obj){
  		fromTool.addLast(obj);
  		System.out.println("JavaTool.add: queued " + obj);
  	}
  	
  	synchronized public ATerm getToolId(){
  		return toolId;
  	}
  	
//  	synchronized public MatchResult hasValue(ATerm trm, Environment env){
//  		System.out.println("hasValue(" + trm + "), length fromTool = " + fromTool.size());
//  		if(!fromTool.isEmpty()){
//  			try {
//				return TBTerm.match(trm, env, (ATerm) fromTool.getFirst(), new Environment());
//			} catch (ToolBusException e) {
//				System.out.println("hasValue: cannot happen :-)");
//			}
//  		}
//  		System.out.println("hasValue returns false");
//		return new MatchResult(false, null, null);
//  	}
  	
  	 synchronized public MatchResult getValue(ATerm trm, Environment env){
  		System.out.println("getValue(" + trm + "), length fromTool = " + fromTool.size());
  		if(!fromTool.isEmpty()){
  			try {
				MatchResult mr = TBTerm.match(trm, env, (ATerm) fromTool.getFirst(), new Environment());
				fromTool.removeFirst();
				return mr;
			} catch (ToolBusException e) {
				System.out.println("hasValue: cannot happen :-)");
			}
  		}
  		System.out.println("hasValue returns false");
		return new MatchResult(false, null, null);
  	}
}
