// Java tool interface class SourceViewerTif
// This file is generated automatically, please do not edit!
// generation time: 17-Aug-99 1:42:13 PM

package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.ToolException;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.Hashtable;


abstract public class SourceViewerTif extends toolbus.tool.Tool
{
  // This table will hold the complete input signature
  private Hashtable sigTable = new Hashtable();

  // Declare the patterns that are used to match against incoming terms
  private ATermPattern Pcpe0;
  private ATermPattern PcurrentPort0;
  private ATermPattern PdapDisconnected0;
  private ATermPattern PruleCreated0;
  private ATermPattern PruleDestroyed0;
  private ATermPattern PexecState0;
  private ATermPattern PdapConnected0;
  private ATermPattern PruleModified0;
  private ATermPattern PprocessCreation0;
  private ATermPattern PviewProcess0;
  private ATermPattern PprocessDestruction0;
  private ATermPattern PrecTerminate0;
  private ATermPattern PrecAckEvent0;

  // Mimic the three constructors from the Tool class
  protected SourceViewerTif(String name) throws UnknownHostException { super(name); init(); }
  protected SourceViewerTif(String name, InetAddress address, int port) throws UnknownHostException  { super(name, address, port); init(); }
  protected SourceViewerTif(String[] args) throws UnknownHostException { super(args); init(); }

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
      Pcpe0 = world.makePattern("rec-do(cpe(<debug-adapter>,<term>,<term>))");
      PcurrentPort0 = world.makePattern("rec-do(current-port(<debug-adapter>,<term>,<term>))");
      PdapDisconnected0 = world.makePattern("rec-do(dap-disconnected(<debug-adapter>))");
      PruleCreated0 = world.makePattern("rec-do(rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))");
      PruleDestroyed0 = world.makePattern("rec-do(rule-destroyed(<debug-adapter>,<int>))");
      PexecState0 = world.makePattern("rec-do(exec-state(<debug-adapter>,<term>,<term>))");
      PdapConnected0 = world.makePattern("rec-do(dap-connected(<debug-adapter>,<list>,<term>))");
      PruleModified0 = world.makePattern("rec-do(rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))");
      PprocessCreation0 = world.makePattern("rec-do(process-creation(<debug-adapter>,<term>,<str>,<list>))");
      PviewProcess0 = world.makePattern("rec-do(view-process(<debug-adapter>,<term>))");
      PprocessDestruction0 = world.makePattern("rec-do(process-destruction(<debug-adapter>,<term>))");
      PrecTerminate0 = world.makePattern("rec-terminate(<term>)");
      PrecAckEvent0 = world.makePattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void cpe(ATermAppl a0, ATerm t1, ATerm t2) throws ToolException;
  abstract void currentPort(ATermAppl a0, ATerm t1, ATerm t2) throws ToolException;
  abstract void dapDisconnected(ATermAppl a0) throws ToolException;
  abstract void ruleCreated(ATermAppl a0, ATerm t1, int i2, ATerm t3, ATerm t4, ATerm t5, ATerm t6) throws ToolException;
  abstract void ruleDestroyed(ATermAppl a0, int i1) throws ToolException;
  abstract void execState(ATermAppl a0, ATerm t1, ATerm t2) throws ToolException;
  abstract void dapConnected(ATermAppl a0, ATermList l1, ATerm t2) throws ToolException;
  abstract void ruleModified(ATermAppl a0, ATerm t1, int i2, ATerm t3, ATerm t4, ATerm t5, ATerm t6) throws ToolException;
  abstract void processCreation(ATermAppl a0, ATerm t1, String s2, ATermList l3) throws ToolException;
  abstract void viewProcess(ATermAppl a0, ATerm t1) throws ToolException;
  abstract void processDestruction(ATermAppl a0, ATerm t1) throws ToolException;
  abstract void recTerminate(ATerm t0) throws ToolException;
  abstract void recAckEvent(ATerm t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATerm handler(ATerm term)
	throws ToolException
  {
    if(Pcpe0.match(term)) {
      ATermPattern P = Pcpe0;
      cpe((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), (ATerm)P.elementAt(2));
    } else if(PcurrentPort0.match(term)) {
      ATermPattern P = PcurrentPort0;
      currentPort((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), (ATerm)P.elementAt(2));
    } else if(PdapDisconnected0.match(term)) {
      ATermPattern P = PdapDisconnected0;
      dapDisconnected((ATermAppl)P.elementAt(0));
    } else if(PruleCreated0.match(term)) {
      ATermPattern P = PruleCreated0;
      ruleCreated((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), ((Integer)P.elementAt(2)).intValue(), (ATerm)P.elementAt(3), (ATerm)P.elementAt(4), (ATerm)P.elementAt(5), (ATerm)P.elementAt(6));
    } else if(PruleDestroyed0.match(term)) {
      ATermPattern P = PruleDestroyed0;
      ruleDestroyed((ATermAppl)P.elementAt(0), ((Integer)P.elementAt(1)).intValue());
    } else if(PexecState0.match(term)) {
      ATermPattern P = PexecState0;
      execState((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), (ATerm)P.elementAt(2));
    } else if(PdapConnected0.match(term)) {
      ATermPattern P = PdapConnected0;
      dapConnected((ATermAppl)P.elementAt(0), (ATermList)P.elementAt(1), (ATerm)P.elementAt(2));
    } else if(PruleModified0.match(term)) {
      ATermPattern P = PruleModified0;
      ruleModified((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), ((Integer)P.elementAt(2)).intValue(), (ATerm)P.elementAt(3), (ATerm)P.elementAt(4), (ATerm)P.elementAt(5), (ATerm)P.elementAt(6));
    } else if(PprocessCreation0.match(term)) {
      ATermPattern P = PprocessCreation0;
      processCreation((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1), (String)P.elementAt(2), (ATermList)P.elementAt(3));
    } else if(PviewProcess0.match(term)) {
      ATermPattern P = PviewProcess0;
      viewProcess((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1));
    } else if(PprocessDestruction0.match(term)) {
      ATermPattern P = PprocessDestruction0;
      processDestruction((ATermAppl)P.elementAt(0), (ATerm)P.elementAt(1));
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

