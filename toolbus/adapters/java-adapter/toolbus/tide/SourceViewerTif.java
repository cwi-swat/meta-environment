// Java tool interface class SourceViewerTif
// This file is generated automatically, please do not edit!
// generation time: 25-Jun-97 2:33:42 PM

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
      sigTable.put(ATermParser.makeSimple("rec-terminate(<debug-adapter>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-terminate(<source-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-terminate(<rule-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-terminate(<watchpoint-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-terminate(<process-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<watchpoint-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,watchpoint(<debug-adapter>,<term>,<int>,<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,rule-destroyed(<debug-adapter>,<term>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,ask-watchpoint(<debug-adapter>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<watchpoint-viewer>,create-watchpoint(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<process-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,disconnected(<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,connected(<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,watchpoint(<debug-adapter>,<term>,<int>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<process-viewer>,new-tool(<str>,<term>,<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<rule-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,current-port(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,watchpoint(<debug-adapter>,<term>,<int>,<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,rule-destroyed(<debug-adapter>,<term>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<rule-viewer>,view-rules(<debug-adapter>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<source-viewer>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,current-port(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,process-destruction(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,process-creation(<debug-adapter>,<term>,<str>,<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,exec-state(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,cpe(<debug-adapter>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,rule-destroyed(<debug-adapter>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,dap-disconnected(<debug-adapter>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,dap-connected(<debug-adapter>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<source-viewer>,view-process(<debug-adapter>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<debug-adapter>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<debug-adapter>,exec-actions(<term>,<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<debug-adapter>,destroy-rule(<term>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<debug-adapter>,modify-rule(<int>,<term>,<term>,<term>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<debug-adapter>,create-rule(<term>,<term>,<term>,<list>,<term>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<debug-adapter>,get-processes)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<debug-adapter>,get-info)"), new Boolean(true));
    } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      Pcpe0 = new ATermPattern("rec-do(cpe(<debug-adapter>,<term>,<term>))");
      PcurrentPort0 = new ATermPattern("rec-do(current-port(<debug-adapter>,<term>,<term>))");
      PdapDisconnected0 = new ATermPattern("rec-do(dap-disconnected(<debug-adapter>))");
      PruleCreated0 = new ATermPattern("rec-do(rule-created(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))");
      PruleDestroyed0 = new ATermPattern("rec-do(rule-destroyed(<debug-adapter>,<int>))");
      PexecState0 = new ATermPattern("rec-do(exec-state(<debug-adapter>,<term>,<term>))");
      PdapConnected0 = new ATermPattern("rec-do(dap-connected(<debug-adapter>,<list>,<term>))");
      PruleModified0 = new ATermPattern("rec-do(rule-modified(<debug-adapter>,<term>,<int>,<term>,<term>,<term>,<term>))");
      PprocessCreation0 = new ATermPattern("rec-do(process-creation(<debug-adapter>,<term>,<str>,<list>))");
      PviewProcess0 = new ATermPattern("rec-do(view-process(<debug-adapter>,<term>))");
      PprocessDestruction0 = new ATermPattern("rec-do(process-destruction(<debug-adapter>,<term>))");
      PrecTerminate0 = new ATermPattern("rec-terminate(<term>)");
      PrecAckEvent0 = new ATermPattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void cpe(ATermApplRef a0, ATermRef t1, ATermRef t2) throws ToolException;
  abstract void currentPort(ATermApplRef a0, ATermRef t1, ATermRef t2) throws ToolException;
  abstract void dapDisconnected(ATermApplRef a0) throws ToolException;
  abstract void ruleCreated(ATermApplRef a0, ATermRef t1, int i2, ATermRef t3, ATermRef t4, ATermRef t5, ATermRef t6) throws ToolException;
  abstract void ruleDestroyed(ATermApplRef a0, int i1) throws ToolException;
  abstract void execState(ATermApplRef a0, ATermRef t1, ATermRef t2) throws ToolException;
  abstract void dapConnected(ATermApplRef a0, ATermListRef l1, ATermRef t2) throws ToolException;
  abstract void ruleModified(ATermApplRef a0, ATermRef t1, int i2, ATermRef t3, ATermRef t4, ATermRef t5, ATermRef t6) throws ToolException;
  abstract void processCreation(ATermApplRef a0, ATermRef t1, String s2, ATermListRef l3) throws ToolException;
  abstract void viewProcess(ATermApplRef a0, ATermRef t1) throws ToolException;
  abstract void processDestruction(ATermApplRef a0, ATermRef t1) throws ToolException;
  abstract void recTerminate(ATermRef t0) throws ToolException;
  abstract void recAckEvent(ATermRef t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATermRef handler(ATermRef term)
	throws ToolException
  {
    if(Pcpe0.match(term)) {
      ATermPattern P = Pcpe0;
      cpe((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), (ATermRef)P.elementAt(2));
    } else if(PcurrentPort0.match(term)) {
      ATermPattern P = PcurrentPort0;
      currentPort((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), (ATermRef)P.elementAt(2));
    } else if(PdapDisconnected0.match(term)) {
      ATermPattern P = PdapDisconnected0;
      dapDisconnected((ATermApplRef)P.elementAt(0));
    } else if(PruleCreated0.match(term)) {
      ATermPattern P = PruleCreated0;
      ruleCreated((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), ((Integer)P.elementAt(2)).intValue(), (ATermRef)P.elementAt(3), (ATermRef)P.elementAt(4), (ATermRef)P.elementAt(5), (ATermRef)P.elementAt(6));
    } else if(PruleDestroyed0.match(term)) {
      ATermPattern P = PruleDestroyed0;
      ruleDestroyed((ATermApplRef)P.elementAt(0), ((Integer)P.elementAt(1)).intValue());
    } else if(PexecState0.match(term)) {
      ATermPattern P = PexecState0;
      execState((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), (ATermRef)P.elementAt(2));
    } else if(PdapConnected0.match(term)) {
      ATermPattern P = PdapConnected0;
      dapConnected((ATermApplRef)P.elementAt(0), (ATermListRef)P.elementAt(1), (ATermRef)P.elementAt(2));
    } else if(PruleModified0.match(term)) {
      ATermPattern P = PruleModified0;
      ruleModified((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), ((Integer)P.elementAt(2)).intValue(), (ATermRef)P.elementAt(3), (ATermRef)P.elementAt(4), (ATermRef)P.elementAt(5), (ATermRef)P.elementAt(6));
    } else if(PprocessCreation0.match(term)) {
      ATermPattern P = PprocessCreation0;
      processCreation((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1), (String)P.elementAt(2), (ATermListRef)P.elementAt(3));
    } else if(PviewProcess0.match(term)) {
      ATermPattern P = PviewProcess0;
      viewProcess((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1));
    } else if(PprocessDestruction0.match(term)) {
      ATermPattern P = PprocessDestruction0;
      processDestruction((ATermApplRef)P.elementAt(0), (ATermRef)P.elementAt(1));
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

