// Java tool interface class Testing
// This file is generated automatically, please do not edit!
// generation time: 23-Jun-97 11:50:41 AM

package toolbus.tool;
import toolbus.aterm.*;
import toolbus.tool.ToolException;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.Hashtable;


abstract public class Testing extends toolbus.tool.Tool
{
  // This table will hold the complete input signature
  private Hashtable sigTable = new Hashtable();

  // Declare the patterns that are used to match against incoming terms
  private ATermPattern Ptestit0;
  private ATermPattern Ptestit1;
  private ATermPattern Ptestit2;
  private ATermPattern Pquestion0;
  private ATermPattern PrecTerminate0;
  private ATermPattern PrecAckEvent0;

  // Mimic the three constructors from the Tool class
  protected Testing(String name) throws UnknownHostException { super(name); init(); }
  protected Testing(String name, InetAddress address, int port) throws UnknownHostException  { super(name, address, port); init(); }
  protected Testing(String[] args) throws UnknownHostException { super(args); init(); }

  // Initializations common to all constructors
  private void init() { initSigTable(); initPatterns(); }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    try {
      sigTable.put(ATermParser.makeSimple("rec-terminate(<testing>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<testing>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<testing>,question(square))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<testing>,testit(<str>,f(<int>)))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<testing>,testit(<str>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<testing>,testit(<str>))"), new Boolean(true));
    } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      Ptestit0 = new ATermPattern("rec-do(testit(<str>))");
      Ptestit1 = new ATermPattern("rec-do(testit(<str>,<int>))");
      Ptestit2 = new ATermPattern("rec-do(testit(<str>,<appl>))");
      Pquestion0 = new ATermPattern("rec-eval(question(<appl>))");
      PrecTerminate0 = new ATermPattern("rec-terminate(<term>)");
      PrecAckEvent0 = new ATermPattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void testit(String s0) throws ToolException;
  abstract void testit(String s0, int i1) throws ToolException;
  abstract void testit(String s0, ATermApplRef a1) throws ToolException;
  abstract ATermRef question(ATermApplRef a0) throws ToolException;
  abstract void recTerminate(ATermRef t0) throws ToolException;
  abstract void recAckEvent(ATermRef t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATermRef handler(ATermRef term)
	throws ToolException
  {
    if(Ptestit0.match(term)) {
      ATermPattern P = Ptestit0;
      testit((String)P.elementAt(0));
    } else if(Ptestit1.match(term)) {
      ATermPattern P = Ptestit1;
      testit((String)P.elementAt(0), ((Integer)P.elementAt(1)).intValue());
    } else if(Ptestit2.match(term)) {
      ATermPattern P = Ptestit2;
      testit((String)P.elementAt(0), (ATermApplRef)P.elementAt(1));
    } else if(Pquestion0.match(term)) {
      ATermPattern P = Pquestion0;
      return question((ATermApplRef)P.elementAt(0));
    } else if(PrecTerminate0.match(term)) {
      ATermPattern P = PrecTerminate0;
      recTerminate((ATermRef)P.elementAt(0));
    } else if(PrecAckEvent0.match(term)) {
      ATermPattern P = PrecAckEvent0;
      recAckEvent((ATermRef)P.elementAt(0));
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

