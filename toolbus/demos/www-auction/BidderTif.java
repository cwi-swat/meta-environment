// Java tool interface class BidderTif
// This file is generated automatically, please do not edit!
// generation time: 23-May-97 5:48:54 PM

import toolbus.aterm.*;
import toolbus.tool.ToolException;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.Hashtable;


abstract public class BidderTif extends toolbus.tool.Tool
{
  // This table will hold the complete input signature
  private Hashtable sigTable = new Hashtable();

  // Declare the patterns that are used to match against incoming terms
  private ATermPattern Pbidders0;
  private ATermPattern PbidRejected0;
  private ATermPattern Pbid0;
  private ATermPattern PanyHigherBid0;
  private ATermPattern Psold0;
  private ATermPattern PbidAccepted0;
  private ATermPattern PnewItem0;
  private ATermPattern PmyName0;
  private ATermPattern PrecTerminate0;
  private ATermPattern PrecAckEvent0;

  // Mimic the three constructors from the Tool class
  protected BidderTif(String name) throws UnknownHostException { super(name); init(); }
  protected BidderTif(String name, InetAddress address, int port) throws UnknownHostException  { super(name, address, port); init(); }
  protected BidderTif(String[] args) throws UnknownHostException { super(args); init(); }

  // Initializations common to all constructors
  private void init() { initSigTable(); initPatterns(); }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    try {
      sigTable.put(ATermParser.makeSimple("rec-terminate(<bidder>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,bid-rejected)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,bid-accepted)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-ack-event(<bidder>,<term>)"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,sold(<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,bid(<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,any-higher-bid(<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,new-item(<str>,<int>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-do(<bidder>,bidders(<list>))"), new Boolean(true));
      sigTable.put(ATermParser.makeSimple("rec-eval(<bidder>,my-name)"), new Boolean(true));
    } catch (ParseError e) { }
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    try {
      Pbidders0 = new ATermPattern("rec-do(bidders(<list>))");
      PbidRejected0 = new ATermPattern("rec-do(bid-rejected)");
      Pbid0 = new ATermPattern("rec-do(bid(<int>))");
      PanyHigherBid0 = new ATermPattern("rec-do(any-higher-bid(<int>))");
      Psold0 = new ATermPattern("rec-do(sold(<int>))");
      PbidAccepted0 = new ATermPattern("rec-do(bid-accepted)");
      PnewItem0 = new ATermPattern("rec-do(new-item(<str>,<int>))");
      PmyName0 = new ATermPattern("rec-eval(my-name)");
      PrecTerminate0 = new ATermPattern("rec-terminate(<term>)");
      PrecAckEvent0 = new ATermPattern("rec-ack-event(<term>)");
    } catch (ParseError e) {}
  }


  // Override these abstract methods to handle incoming ToolBus terms
  abstract void bidders(ATermListRef l0) throws ToolException;
  abstract void bidRejected() throws ToolException;
  abstract void bid(int i0) throws ToolException;
  abstract void anyHigherBid(int i0) throws ToolException;
  abstract void sold(int i0) throws ToolException;
  abstract void bidAccepted() throws ToolException;
  abstract void newItem(String s0, int i1) throws ToolException;
  abstract ATermRef myName() throws ToolException;
  abstract void recTerminate(ATermRef t0) throws ToolException;
  abstract void recAckEvent(ATermRef t0) throws ToolException;

  // The generic handler calls the specific handlers
  protected ATermRef handler(ATermRef term)
	throws ToolException
  {
    if(Pbidders0.match(term)) {
      ATermPattern P = Pbidders0;
      bidders((ATermListRef)P.elementAt(0));
    } else if(PbidRejected0.match(term)) {
      ATermPattern P = PbidRejected0;
      bidRejected();
    } else if(Pbid0.match(term)) {
      ATermPattern P = Pbid0;
      bid(((Integer)P.elementAt(0)).intValue());
    } else if(PanyHigherBid0.match(term)) {
      ATermPattern P = PanyHigherBid0;
      anyHigherBid(((Integer)P.elementAt(0)).intValue());
    } else if(Psold0.match(term)) {
      ATermPattern P = Psold0;
      sold(((Integer)P.elementAt(0)).intValue());
    } else if(PbidAccepted0.match(term)) {
      ATermPattern P = PbidAccepted0;
      bidAccepted();
    } else if(PnewItem0.match(term)) {
      ATermPattern P = PnewItem0;
      newItem((String)P.elementAt(0), ((Integer)P.elementAt(1)).intValue());
    } else if(PmyName0.match(term)) {
      ATermPattern P = PmyName0;
      return myName();
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

