// Java tool interface class Testing
// This file is generated automatically, please do not edit!
// generation time: Thu Mar 05 16:18:25 1998

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
      sigTable.put(world.makeSimple("rec-terminate(<testing>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-ack-event(<testing>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-eval(<testing>,question(square))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<testing>,testit(<str>,f(<int>)))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<testing>,testit(<str>,<int>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<testing>,testit(<str>))"), new Boolean(true));
    } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      Ptestit0 = world.makePattern("rec-do(testit(<str>))");
      Ptestit1 = world.makePattern("rec-do(testit(<str>,<int>))");
      Ptestit2 = world.makePattern("rec-do(testit(<str>,<appl>))");
      Pquestion0 = world.makePattern("rec-eval(question(<appl>))");
      PrecTerminate0 = world.makePattern("rec-terminate(<term>)");
      PrecAckEvent0 = world.makePattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void testit(String s0) throws ToolException;
  abstract void testit(String s0, int i1) throws ToolException;
  abstract void testit(String s0, ATermAppl a1) throws ToolException;
  abstract ATerm question(ATermAppl a0) throws ToolException;
  abstract void recTerminate(ATerm t0) throws ToolException;
  abstract void recAckEvent(ATerm t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATerm handler(ATerm term)
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
      testit((String)P.elementAt(0), (ATermAppl)P.elementAt(1));
    } else if(Pquestion0.match(term)) {
      ATermPattern P = Pquestion0;
      return question((ATermAppl)P.elementAt(0));
    } else if(PrecTerminate0.match(term)) {
      ATermPattern P = PrecTerminate0;
      recTerminate((ATerm)P.elementAt(0));
    } else if(PrecAckEvent0.match(term)) {
      ATermPattern P = PrecAckEvent0;
      recAckEvent((ATerm)P.elementAt(0));
    } else 
      notInInputSignature(term);
    return null;
  }

  // Check the input signature
  protected void checkInputSignature(ATermList list)
         throws ToolException
  {
    ATerms sigs = list.getATerms();
    while(!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl)sigs.getFirst();
      sigs = sigs.getNext();
      if(!sigTable.containsKey(sig)) {
        // Sorry, but the term is not in the input signature!
        notInInputSignature(sig);
      }
    }
  }

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATerm t)
        throws ToolException
  {
    throw new ToolException(this, "term not in input signature", t);
  }
}

