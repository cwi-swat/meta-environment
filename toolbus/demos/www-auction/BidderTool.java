import java.awt.*;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.net.*;

class BidderTool extends BidderTif
{
  BidderUI ui;

  //{ static public void main(String[] args)

  static public void main(String[] args)
    throws java.io.IOException, java.net.UnknownHostException, ToolException
  {
    BidderTool tool = new BidderTool(args);
    tool.connect();
    tool.run();
  }

  //}  
  //{ public BidderTool(String[] args)

  public BidderTool(String[] args)
    throws java.net.UnknownHostException
  {
    super(args);
    Frame frame = new Frame("Auction Bidder");
    ui = new BidderUI("Test", true, this);
    frame.add(ui);
    frame.resize(310,280);
    frame.show();
  }

  //}
  //{ public BidderTool(String name, InetAddress host, int port)

  public BidderTool(String name, InetAddress host, int port)
    throws java.net.UnknownHostException
  {
    super(name, host, port);
    Frame frame = new Frame("Auction Bidder");
    ui = new BidderUI("Test", true, this);
    frame.add(ui);
    frame.resize(310,280);
    frame.show();
  }

  //}
  //{ public Panel getPanel()

  /**
    * Retrieve the UI panel.
    */

  public Panel getPanel()
  {
    return ui;
  }

  //}

  //{ void bidders(ATermListRef bidders)

  void bidders(ATermListRef bidders)
  {
    System.out.println("bidders: " + bidders);
    ui.changeBidders(bidders.getATerms());
  }

  //}
  //{ void anyHigherBid(int time)

  void anyHigherBid(int time)
  {
    System.out.println("any higher bid.");
    ui.msg("Last chance to bid (" + time + " seconds)");
  }

  //}
  //{ void bid(int amount)

  void bid(int amount)
  {
    System.out.println("bid: " + amount);
    ui.highest(amount);
  }

  //}
  //{ void sold(int amount)

  void sold(int amount)
  {
    System.out.println("sold: " + amount);
    ui.msg("item sold for " + amount);
  }

  //}
  //{ void newItem(String item, int amount)

  void newItem(String item, int amount)
  {
    System.out.println("new item: " + item + ", amount: " + amount);
    ui.item(item);
    ui.highest(amount);
  }

  //}
  //{ ATermRef myName()

  ATermRef myName()
  {
    ATermRef result = null;
    try {
      result = ATermParser.makeSimple("snd-value(\"Test\")");
    } catch (ParseError e) {
      System.err.println("internal parse error in 'BidderTool.myName'");
    }
    return result;
  }

  //}
  //{ void bidAccepted()

  void bidAccepted()
  {
    ui.msg("Your bid was accepted.");
  }

  //}
  //{ void bidRejected()

  void bidRejected()
  {
    ui.msg("Your bid was rejected!");
  }

  //}

  //{ void recTerminate(ATermRef t0)

  void recTerminate(ATermRef t0)
  {
    System.exit(0);
  }

  //}
  //{ void recAckEvent(ATermRef t0)

  void recAckEvent(ATermRef t0)
  {
    System.out.println("ack event: " + t0);
  }

  //}
}

