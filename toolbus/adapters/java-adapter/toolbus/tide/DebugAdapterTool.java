package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.util.*;
import java.io.*;
import java.net.*;
import sun.tools.debug.*;

class DebugAdapterTool extends DebugAdapterTif
{
  private JavaDebugger debugger = null;
  private String name;

  //{ static public void main(String[] args)

  /**
    * The main function starts a new DebugAdapterTool, and analyzes 
    * the arguments to find the location of the debugger ToolBus, 
    * and to find if it should connect to a specific java interpreter,
    * or maybe start its own slave interpreter.
    * @exception Exception When the debugging bus or the slave interpreter
    *            cannot be located.
    */

  static public void main(String[] args)
    throws Exception
  {
    String passwd = null;
    String debugHost = null;
    String classToLoad = null;
    String javaArgs = null;

    for(int i=0; i<args.length; i++) {
      if(args[i].equals("-connect"))
	passwd = args[++i];
      if(args[i].equals("-load"))
	classToLoad = args[++i];
      if(args[i].equals("-debug-host"))
	debugHost = args[++i];
      if(args[i].equals("-javaargs"))
	javaArgs = args[++i];
    }

    if(passwd != null && classToLoad != null)
      System.err.println("You cannot specify both -connect and -load!");
    else if(passwd == null && classToLoad == null)
      System.err.println("You must specify either -connect or -load!");
    else {
      DebugAdapterTool tool;

      if(passwd != null)
	tool = new DebugAdapterTool(args, debugHost, passwd);
      else {
	tool = new DebugAdapterTool(args, javaArgs);
	tool.loadClass(classToLoad);
      }

      tool.connect();
      tool.run();
    }
  }

  //}

  //{ public DebugAdapterTool(String[] args, String host, String passwd)

  /**
    * This constructor is used to connect to a remote interpreter.
    * @exception UnknownHostException when the local host or the
    *            debugger host cannot be determined.
    * @exception Exception when the contact with the remote interpreter
    *            cannot be established.
    */
  
  public DebugAdapterTool(String[] args, String host, String passwd)
    throws Exception
  {
    super(args);
    debugger = new JavaDebugger(host, passwd, this);
    host = (host == null ? "local" : host);
    name = host + ":" + passwd + " (Java)";
  }

  //}
  //{ public DebugAdapterTool(String[] args, String classToLoad)

  /**
    * This constructor is used to start a new slave interpreter.
    * @exception UnknownHostException when the local host or the
    *            debugger host cannot be determined.
    * @exception Exception When the slave interpreter cannot be
    *            started.
    */
  
  public DebugAdapterTool(String[] args, String javaArgs)
    throws Exception
  {
    super(args);
    debugger = new JavaDebugger(javaArgs, this);
  }

  //}

  //{ void loadClass(String classToLoad)

  /**
    * Load a class in the slave interpreter.
    * @exception Exception when something goes wrong when loading the class.
    */

  void loadClass(String classToLoad)
    throws Exception
  {
    debugger.loadClass(classToLoad);
  }

  //}

  //{ ATermRef getInfo()

  /**
    * Supply information about this debug adapter.
    */

  ATermRef getInfo()
  {
    ATermRef result;
    try {
      ATermsRef info = null;
      ATermPattern addPattern = new ATermPattern("[[<fun>,<term>],<terms>]");
      ATermPattern returnPattern = new ATermPattern("snd-value(info([<terms>]))");
      Properties props = debugger.getProperties();
      props.put("name", "\"" + name + "\"");
      props.put("type", "\"Java\"");
      Enumeration names = props.propertyNames();
      while(names.hasMoreElements()) {
	String prop = (String)names.nextElement();
	String value = props.getProperty(prop);
	info = ((ATermListRef)addPattern.make(prop, 
		       ATermParser.makeSimple(value), info)).getATerms();
      }
      result = returnPattern.make(info);
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error in getInfo()");
    }
    return result;
  }

  //}
  //{ ATermRef getProcesses()

  /**
    * Retrieve the list of processes controlled by this
    * debug adapter.
    */

  ATermRef getProcesses()
  {
    ATermRef result = null;

    try {
      ATermsRef procs = null;
      ATermPattern add = new ATermPattern("[<term>,<terms>]");
      ATermPattern pair = new ATermPattern("[<int>,<str>]");
      Enumeration e = debugger.getProcesses();
      while(e.hasMoreElements()) {
	DebugProcess process = (DebugProcess)e.nextElement();
	add.make(pair.make(new Integer(process.getPid())), process.getName());
      }
      ATermPattern value = new ATermPattern("snd-value(processes(<term>))");
      result = value.make(procs);
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
    return result;
  }

  //}

  //{ ATermRef execActions(ATermRef procs, ATermListRef acts)

  /**
    * Execute a list of actions.
    */

  ATermRef execActions(ATermRef procs, ATermListRef acts)
  {
    return null;
  }

  //}
  //{ ATermRef createRule(ATermRef procs, port, cond, acts, life)

  /**
    * Create a new debug rule.
    */

  ATermRef createRule(ATermRef Procs, ATermRef Port, ATermRef Cond, 
		      ATermListRef Acts, ATermRef Life)
    throws ToolException
  {
    ATermRef result = null;

    try {
      ATermPattern value = new ATermPattern("snd-value(" +
	         "create-rule(<term>,<term>,<term>,<term>,<term>,<int>))");

      DebugPort port = DebugPort.newPort(Port);
      int life = DebugRule.lifeTerm2Int(Life);
      if(port.getType() == DebugPort.ALWAYS && life == DebugRule.ONE_SHOT) {
	// Execute immediately, no need to create a rule
	executeActions(Procs, Acts);
	return value.make(Procs, Port, Cond, Acts, Life, new Integer(-1));
      }

      DebugProcess[] procs = debugger.getProcessArray(Procs);
      DebugRule rule = new DebugRule(procs, port, Cond, Acts.getATerms(), life);
      debugger.addRule(rule);

      result = value.make(Procs, Port, Cond, Acts, Life, 
			  new Integer(rule.getId()));
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
    return result;
  }

  //}
  //{ void executeActions(ATermRef procs, ATermRef acts)

  /**
    * Execute a list of actions just as if a rule containing the
    * actions was triggered.
    */

  void executeActions(ATermRef procs, ATermRef acts)
  {
    DebugProcess[] processes = debugger.getProcessArray(procs);
    debugger.executeActions(processes, acts);
  }

  //}
  //{ void modifyRule(int rid, procs, port, cond, acts, life)

  /**
    * Modify an existing debug rule.
    */

  void modifyRule(int rid, ATermRef procs, ATermRef port, ATermRef cond, 
		  ATermListRef acts, ATermRef life)
    throws ToolException
  {
  }

  //}
  //{ void destroyRule(ATermRef procs, int rid)

  /**
    * Destroy an existing rule.
    */

  void destroyRule(ATermRef procs, int rid)
    throws ToolException
  {
  }

  //}

  //{ void recTerminate(ATermRef arg)

  /**
    * The debug adapter received a termination request from the debugger bus.
    */

  void recTerminate(ATermRef arg)
  {
    debugger.closeConnection();
  }

  //}
  //{ void recAckEvent(ATermRef event)

  /**
    * Receive an event acknowledgement.
    */

  void recAckEvent(ATermRef event)
  {
  }

  //}
}
