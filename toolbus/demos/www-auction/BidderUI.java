
import java.awt.*;
import java.util.*;
import toolbus.aterm.*;
import toolbus.tool.*;

public class BidderUI extends Panel
{
  private Tool tool;
  private Label nameLabel;
  private TextField item;
  private TextField highest;
  private TextField myBid;
  private TextField newItem;
  private TextField lowest;
  private Button bid;
  private List bidders;
  private Label message;
  private Button quit;
  private Vector bidderVector = new Vector();

  //{ some patterns

  private ATermPattern patternDisconnect;
  private ATermPattern patternBidEvent;
  private ATermPattern patternNewItemEvent;

  //}

  //{ public BidderUI(String name, boolean canQuit)

  public BidderUI(String name, boolean canQuit, Tool tool)
  {
    //{ build patterns
    
    this.tool = tool;

    try {
      patternDisconnect = new ATermPattern("snd-disconnect");
      patternBidEvent = new ATermPattern("snd-event(bid(<str>,<int>))");
      patternNewItemEvent = new ATermPattern("snd-event(new-item(<str>,<int>))");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    //}

    setFont(new Font("Helvetica", Font.BOLD, 12));
    BorderLayout layout = new BorderLayout();
    setLayout(layout);

    Label nameLabel = new Label("Bidder: " + name, Label.CENTER);
    nameLabel.resize(300, 12);    
    add(nameLabel);
    layout.addLayoutComponent("North", nameLabel);

    Panel bottom = new Panel();
    bottom.setLayout(new GridLayout(0, 1));
    add(bottom);
    layout.addLayoutComponent("South", bottom);

    Panel offerPanel = new Panel();
    Button offerButton = new Button("Offer item:");
    newItem = new TextField(10);
    Label offerPrice = new Label("Price:");
    lowest = new TextField(5);
    offerPanel.add(offerButton);
    offerPanel.add(newItem);
    offerPanel.add(offerPrice);
    offerPanel.add(lowest);
    bottom.add(offerPanel);

    message = new Label("");
    message.setBackground(Color.green);
    bottom.add(message);

    if(canQuit) {
      quit = new Button("Q U I T");
      bottom.add(quit);
    }

    Panel right = new Panel();
    BorderLayout bl = new BorderLayout();
    right.setLayout(bl);
    add(right);
    layout.addLayoutComponent("East", right);
    Label bd = new Label("Bidders:", Label.CENTER);
    right.add(bd);
    bl.addLayoutComponent("North", bd);
    bidders = new List(8, false);
    right.add(bidders);
    bidders.setBackground(Color.white);
    bl.addLayoutComponent("Center", bidders);

    Panel left = new Panel();
    left.setLayout(new GridLayout(0, 2));
    add(left);
    layout.addLayoutComponent("Center", left);

    left.add(new Label("Current Sale:", Label.CENTER));
    left.add(new Panel());
    Label itemLabel = new Label("Item:");
    left.add(itemLabel);
    item = new TextField(10);
    left.add(item);
    Label hb = new Label("Higest bid:");
    left.add(hb);
    highest = new TextField(10);
    highest.setEditable(false);
    left.add(highest);
    Label mb = new Label("My bid:");
    left.add(mb);
    myBid = new TextField(10);
    left.add(myBid);
    left.add(new Panel());
    bid = new Button("Bid");
    left.add(bid);    
  }

  //}
  //{ public void msg(String m)

  public void msg(String m)
  {
    message.setText(m);
  }

  //}
  //{ public void changeBidders(ATermsRef bidders)

  public void changeBidders(ATermsRef bidderList)
  {
    bidders.clear();
    while(bidderList != null) {
      ATermApplRef bidder = (ATermApplRef)bidderList.getFirst();
      bidderList = bidderList.getNext();
      bidders.addItem(bidder.getFun());
    }
  }

  //}
  //{ public void bid(int amount)

  public void highest(int amount)
  {
    highest.setText("" + amount);
  }

  //}
  //{ public void item(String name)

  public void item(String name)
  {
    item.setText(name);
  }

  //}

  //{ public boolean action(Event evt, Object what)

  /**
    * React on events like the pressing of a button, or the
    * selection of a menu item.
    */

  public boolean action(Event evt, Object what)
  {
    String whatitem;
    Integer howmuch;

    try {
      if(what.equals("Q U I T")) {
	tool.send(patternDisconnect.make());
	System.exit(0);
      }
      if(what.equals("Bid")) {
	whatitem = item.getText();
	howmuch = new Integer(myBid.getText());
	tool.send(patternBidEvent.make(whatitem, howmuch));
	return true;
      }
      if(what.equals("Offer item:")) {
	whatitem = newItem.getText();
	howmuch = new Integer(lowest.getText());
	tool.send(patternNewItemEvent.make(whatitem, howmuch));
	return true;
      }
    } catch (ToolException e) {
      System.err.println("cannot send to ToolBus, giving up!");
      System.exit(1);
    }
    return false;
  }

  //}
}
