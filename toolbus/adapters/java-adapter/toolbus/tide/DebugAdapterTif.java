// Java tool interface class DebugAdapterTif
// This file is generated automatically, please do not edit!
// generation time: 07-Sep-98 6:44:31 PM

package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.ToolException;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.Hashtable;


abstract public class DebugAdapterTif extends toolbus.tool.Tool
{
  // This table will hold the complete input signature
  private Hashtable sigTable = new Hashtable();

  // Declare the patterns that are used to match against incoming terms
  private ATermPattern PmodifyRule0;
  private ATermPattern PdestroyRule0;
  private ATermPattern PgetInfo0;
  private ATermPattern PcreateRule0;
  private ATermPattern PexecActions0;
  private ATermPattern PgetProcesses0;
  private ATermPattern PrecTerminate0;
  private ATermPattern PrecAckEvent0;

  // Mimic the three constructors from the Tool class
  protected DebugAdapterTif(String name) throws UnknownHostException { super(name); init(); }
  protected DebugAdapterTif(String name, InetAddress address, int port) throws UnknownHostException  { super(name, address, port); init(); }
  protected DebugAdapterTif(String[] args) throws UnknownHostException { super(args); init(); }

  // Initializations common to all constructors
  private void init() { initSigTable(); initPatterns(); }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    try {
      sigTable.put(world.makeSimple("rec-terminate(<debug-adapter>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-terminate(<source-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-terminate(<watchpoint-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-terminate(<process-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-ack-event(<watchpoint-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,watchpoint(<debug-adapter>,<term>,<int>,<list>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,rule-destroyed(<debug-adapter>,<term>,<int>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,ask-watchpoint(<debug-adapter>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<watchpoint-viewer>,create-watchpoint(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-ack-event(<process-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,disconnected(<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,connected(<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,watchpoint(<debug-adapter>,<term>,<int>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<process-viewer>,new-tool(<str>,<term>,<list>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-ack-event(<source-viewer>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,current-port(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,process-destruction(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,process-creation(<debug-adapter>,<term>,<str>,<list>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,exec-state(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,cpe(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,rule-destroyed(<debug-adapter>,<int>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<source-viewer>,view-process(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-ack-event(<debug-adapter>,<term>)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-eval(<debug-adapter>,exec-actions(<term>,<list>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<debug-adapter>,destroy-rule(<term>,<int>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-do(<debug-adapter>,modify-rule(<int>,<term>,<term>,<term>,<list>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-eval(<debug-adapter>,create-rule(<term>,<term>,<term>,<list>,<term>))"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-eval(<debug-adapter>,get-processes)"), new Boolean(true));
      sigTable.put(world.makeSimple("rec-eval(<debug-adapter>,get-info)"), new Boolean(true));
    } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      PmodifyRule0 = world.makePattern("rec-do(modify-rule(<int>,<term>,<term>,<term>,<list>,<term>))");
      PdestroyRule0 = world.makePattern("rec-do(destroy-rule(<term>,<int>))");
      PgetInfo0 = world.makePattern("rec-eval(get-info)");
      PcreateRule0 = world.makePattern("rec-eval(create-rule(<term>,<term>,<term>,<list>,<term>))");
      PexecActions0 = world.makePattern("rec-eval(exec-actions(<term>,<list>))");
      PgetProcesses0 = world.makePattern("rec-eval(get-processes)");
      PrecTerminate0 = world.makePattern("rec-terminate(<term>)");
      PrecAckEvent0 = world.makePattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void modifyRule(int i0, ATerm t1, ATerm t2, ATerm t3, ATermList l4, ATerm t5) throws ToolException;
  abstract void destroyRule(ATerm t0, int i1) throws ToolException;
  abstract ATerm getInfo() throws ToolException;
  abstract ATerm createRule(ATerm t0, ATerm t1, ATerm t2, ATermList l3, ATerm t4) throws ToolException;
  abstract ATerm execActions(ATerm t0, ATermList l1) throws ToolException;
  abstract ATerm getProcesses() throws ToolException;
  abstract void recTerminate(ATerm t0) throws ToolException;
  abstract void recAckEvent(ATerm t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATerm handler(ATerm term)
	throws ToolException
  {
    if(PmodifyRule0.match(term)) {
      ATermPattern P = PmodifyRule0;
      modifyRule(((Integer)P.elementAt(0)).intValue(), (ATerm)P.elementAt(1), (ATerm)P.elementAt(2), (ATerm)P.elementAt(3), (ATermList)P.elementAt(4), (ATerm)P.elementAt(5));
    } else if(PdestroyRule0.match(term)) {
      ATermPattern P = PdestroyRule0;
      destroyRule((ATerm)P.elementAt(0), ((Integer)P.elementAt(1)).intValue());
    } else if(PgetInfo0.match(term)) {
      ATermPattern P = PgetInfo0;
      return getInfo();
    } else if(PcreateRule0.match(term)) {
      ATermPattern P = PcreateRule0;
      return createRule((ATerm)P.elementAt(0), (ATerm)P.elementAt(1), (ATerm)P.elementAt(2), (ATermList)P.elementAt(3), (ATerm)P.elementAt(4));
    } else if(PexecActions0.match(term)) {
      ATermPattern P = PexecActions0;
      return execActions((ATerm)P.elementAt(0), (ATermList)P.elementAt(1));
    } else if(PgetProcesses0.match(term)) {
      ATermPattern P = PgetProcesses0;
      return getProcesses();
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

