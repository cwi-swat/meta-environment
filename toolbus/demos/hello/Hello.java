// Java tool interface class Hello
// This file is generated automatically, please do not edit!
// generation time: 10-Apr-97 3:49:34 PM

import toolbus.aterm.*;
import toolbus.tool.ToolException;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.Hashtable;


abstract public class Hello extends toolbus.tool.Tool
{
  // This table will hold the complete input signature
  private Hashtable sigTable = new Hashtable();

  // Declare the patterns that are used to match against incoming terms
  private ATermPattern PgetText0;
  private ATermPattern PrecTerminate0;

  // Mimic the three constructors from the Tool class
  protected Hello(String name) throws UnknownHostException { super(name); init(); }
  protected Hello(String name, InetAddress address, int port) throws UnknownHostException  { super(name, address, port); initSigTable(); }
  protected Hello(String[] args) throws UnknownHostException { super(args); init(); }

  // Initializations common to all constructors
  private void init() { initSigTable(); initPatterns(); }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    try { sigTable.put(ATermParser.makeSimple("rec-terminate(<hello>,<term>)"), new Boolean(true)); } catch (ParseError e) { }
    try { sigTable.put(ATermParser.makeSimple("rec-eval(<hello>,get-text)"), new Boolean(true)); } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      PgetText0 = new ATermPattern("rec-eval(get-text)");
      PrecTerminate0 = new ATermPattern("rec-terminate(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract ATermRef getText() throws ToolException;
  abstract void recTerminate(ATermRef t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATermRef handler(ATermRef term)
        throws ToolException
  {
    if(PgetText0.match(term)) {
      ATermPattern P = PgetText0;
      return getText();
    } else if(PrecTerminate0.match(term)) {
      ATermPattern P = PrecTerminate0;
      recTerminate((ATermRef)P.elementAt(0));
    } else 
      notInInputSignature(term);
    return null;
  }

  // Check the input signature
  protected void checkInputSignature(ATermListRef list)
         throws ToolException
  {
    ATermsRef sigs = list.getATerms();
    while(sigs != null) {
      ATermApplRef sig = (ATermApplRef)sigs.getFirst();
      sigs = sigs.getNext();
      if(!sigTable.containsKey(sig)) {
        // Sorry, but the term is not in the input signature!
        notInInputSignature(sig);
      }
    }
  }

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATermRef t)
        throws ToolException
  {
    throw new ToolException(this, "term not in input signature", t);
  }
}

