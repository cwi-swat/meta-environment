
package toolbus.tide;
import toolbus.aterm.*;

/**
 * DebugPort objects represent the ports at which execution can be halted.
 */

abstract public class DebugPort
{
  //{ Port types

  static final public int EXEC_STATE            = 0;
  static final public int ALWAYS                = 1;
  static final public int LOCATION              = 2;
  static final public int CALL                  = 3;
  static final public int RETRY                 = 4;
  static final public int FAIL                  = 5;
  static final public int SUCCEED		= 6;
  static final public int EXCEPTION	        = 7;
  static final public int VARIABLE	        = 8;
  static final public int SEND		        = 9;
  static final public int RECEIVE		= 10;
  static final public int PROCESS_CREATION      = 11;
  static final public int PROCESS_DESTRUCTION   = 12;
  static final public int NR_PORT_TYPES	        = 13;

  //}
  //{ When constants

  public static final int WHEN_AT     = 0;
  public static final int WHEN_BEFORE = 1;
  public static final int WHEN_AFTER  = 2;

  //}

  private int type;
  private int when;

  abstract public ATermRef onthewire();

  //{ static public int typeTerm2Int(ATermRef port)

  /**
    * Translate a port type into an integer.
    */

  static public int typeTerm2Int(ATermRef port)
  {
    String fun = ((ATermApplRef)port).getFun();
    switch(fun.charAt(0)) {
      case 'e': 
	if(fun.equals("exec-state"))
	  return EXEC_STATE;
	return EXCEPTION;
      case 'a': return ALWAYS;
      case 'l': return LOCATION;
      case 'c': return CALL;
      case 'r': 
	if(fun.equals("retry"))
	  return RETRY;
	return RECEIVE;
      case 'f': return FAIL;
      case 's':
	if(fun.equals("succeed"))
	  return SUCCEED;
	return SEND;
      case 'v': return VARIABLE;
      case 'p':
	if(fun.equals("process-creation"))
	  return PROCESS_CREATION;
	return PROCESS_DESTRUCTION;
    }
    throw new IllegalArgumentException("illegal port: " + fun);
  }

  //}
  //{ static public int whenTerm2Int(ATermRef when)

  /**
    * Translate a when term into the corresponding integer.
    */

  static public int whenTerm2Int(ATermRef when)
  {
    String fun = ((ATermApplRef)when).getFun();
    if(fun.equals("before"))
      return WHEN_BEFORE;
    if(fun.equals("after"))
      return WHEN_AFTER;
    return WHEN_AT;
  }

  //}

  //{ public DebugPort(int type, int when)

  /**
   * Construct a new debug port.
   * @argument type The type of the port (i.e. DebugPort.LOCATION)
   * @argument when When is this port activated? (BEFORE, AFTER, or AT the type)
   */

  public DebugPort(int type, int when)
  {
    this.type = type;
    this.when = when;
  }

  //}
  //{ static public DebugPort newPort(ATermRef port)

  /**
    * Construct a debug port from its term representation.
    */

  static public DebugPort newPort(ATermRef port)
  {
    DebugPort result;

    if(!(port instanceof ATermListRef))
      System.err.println("expected list, got: " + port);
    ATermsRef Data = ((ATermListRef)port).getATerms();

    ATermRef Port = Data.getFirst();
    Data = Data.getNext();
    ATermRef When = Data.getFirst();
    Data = Data.getNext();
    
    int type = typeTerm2Int(Port);
    int when = whenTerm2Int(When);

    switch(type) {
      case EXCEPTION:
	result = new ExceptionPort(Data.getFirst(), when);
	break;

      case LOCATION:
	result = new LocationPort(Data, when);
	break;

      case EXEC_STATE:
	result = new ExecStatePort(Data.getFirst(), when);
	break;

      case PROCESS_CREATION:
	result = new ProcessCreationPort();
	break;

      case PROCESS_DESTRUCTION:
	result = new ProcessDestructionPort();
	break;

      case SEND:
	result = new SendPort(when, Data.getFirst());
	break;

      case RECEIVE:
	result = new ReceivePort(when, Data.getFirst());
	break;

      default:
	throw new IllegalArgumentException("illegal port type: " + port.toString());
    }
    return result;
  }

  //}
  //{ int getType()

  /**
   * Retrieve the type of this port.
   */

  int getType()
  {
    return type;
  }

  //}
  //{ int getWhen()
  
  /**
   * Retrieve the activation moment of this port.
   */

  int getWhen()
  {
    return when;
  }

  //}
  //{ int getWhenString()
  
  /**
   * Retrieve the activation moment of this port as a string.
   */

  String getWhenString()
  {
    switch(when) {
      case WHEN_BEFORE:  return "before";
      case WHEN_AFTER:   return "after";
      case WHEN_AT:      return "at";
    }
    throw new IllegalArgumentException("illegal activation moment: " + when);
  }

  //}
  //{ int getWhenTerm()

  /**
   * Retrieve the activation moment of this port.
   */

  ATermRef getWhenTerm()
  {
    switch(when) {
      case WHEN_BEFORE: return new ATermApplRef("before", null);
      case WHEN_AFTER:  return new ATermApplRef("after", null);
      case WHEN_AT:     return new ATermApplRef("at", null);
    }
    throw new IllegalArgumentException("illegal when type: " + when);
  }

  //}
}


