
package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.util.*;
import java.net.*;
import sun.tools.debug.*;

class JavaDebugger extends DebugAdapterInfo implements DebuggerCallback
{
  private Tool tool;
  private RemoteDebugger debugger;

  //{ public JavaDebugger(String args, Tool tool)

  /**
    * This constructor is used to start a new slave interpreter.
    * @exception Exception When the slave interpreter cannot be
    *            started.
    */
  public JavaDebugger(String args, Tool tool)
    throws Exception
  {
    super(tool.getTid(), null);
    this.tool = tool;
    debugger = new RemoteDebugger(args, this, false);
  }

  //}
  //{ public JavaDebugger(String host, String passwd, Tool tool)

  /**
    * This constructor is used to connect to a remote interpreter.
    * @exception Exception when the contact with the remote interpreter
    *            cannot be established.
    */
  public JavaDebugger(String host, String passwd, Tool tool)
    throws Exception
  {
    super(tool.getTid(), null);
    this.tool = tool;
    debugger = new RemoteDebugger(host, passwd, this, false);
  }

  //}

  //{ public Properties getProperties()

  /**
    * Retrieve the properties of this debugger.
    */

  public Properties getProperties()
  {
    Properties p = new Properties();

    String dir = System.getProperty("user.dir");
    p.put("search-paths", "[[config,[\""+dir+"\"]],[source,[\""+dir+"\"]]]");
    p.put("ports", "[[exec-state,at],[always,after],[location,after]," +
	  "process-creation,at],[process-destruction,at]]");
    p.put("exec-control", "[single-step, step-over, run, stop]");
    p.put("actions", "[[halt,0,\"suspend a thread\"]" +
	  "[single-step,0,\"execute one statement of a thread\"]," +
	  "[step-over,0,\"execute one statement, step over functions\"]," +
	  "[run,0,\"continue execution\"]," +
	  "[watch,1,\"watch an expression\"]]");
    p.put("expressions", 
	  "[cpe,0,\"highlight the current point of execution of a thread\"]," +
	  "[exec-state,0,\"return the current state of execution of a thread\"]," +
	  "[process-name,0,\"return the name of the current thread\"]" +
	  "[var,1,\"return the value of a local variable cq. attribute\"]]");
    p.put("multi-process", "true");

    return p;
  }

  //}
  //{ public void executeActions(DebugProcess[] procs, ATerm acts)

  /**
    * Execute a list of actions.
    */

  public void executeActions(DebugProcess[] procs, ATerm acts)
  {
    System.err.println("execute actions " + acts.toString() + "in processes:");
    for(int i=0; i<procs.length; i++)
      System.err.print(procs[i].getPid() + " = " + procs[i].getName());
    System.err.println("");
  }

  //}

  //{ public void loadClass(String classToLoad)

  public void loadClass(String classToLoad)
    throws Exception
  {
    RemoteClass cls = debugger.findClass(classToLoad);
    String name = cls.toString() + " (Java)";
    if(cls == null)
      System.err.println("couldn't find class: " + classToLoad);
    else
      System.out.println("loaded class " + cls.toString());
  }

  //}
  //{ public void closeConnection()

  /**
    * Close the connection with the slave interpreter.
    */

  public void closeConnection()
  {
    debugger.close();
  }

  //}

  //{ public void breakpointEvent(RemoteThread t)

  /** 
    * A breakpoint event has been hit in the specified thread.
    */

  public void breakpointEvent(RemoteThread t)
    throws Exception
  {
    System.err.println("breakpoint event received.");
  }

  //}
  //{ public void exceptionEvent(RemoteThread t, String errorText)

  /**
    * An exception has occured in the application being debugged.
    */

  public void exceptionEvent(RemoteThread t, String errorText) 
    throws Exception
  {
    System.err.println("exception event received.");
  }

  //}
  //{ public void threadDeathEvent(RemoteThread t)

  /**
    * A thread has died in the application being debugged.
    */

  public void threadDeathEvent(RemoteThread t)
    throws Exception
  {
    System.err.println("threadDeath event received.");
  }

  //}
  //{ public void quitEvent()

  /**
    * The client interpreter has exited, either by returning from its 
    * main thread, or by calling System.exit().
    */

  public void quitEvent()
    throws Exception
  {
    System.err.println("quit event received.");
  }

  //}
  //{ public void printToConsole(String msg)

  /**
    * Print a debug message tot the console.
    */

  public void printToConsole(String msg)
  {
    System.out.println("jdb> " + msg);
  }

  //}
}
