
import java.applet.*;
import java.awt.*;
import java.io.*;
import java.net.*;
import toolbus.tool.*;
import toolbus.aterm.*;

public class BidderApplet extends Applet
{
  BidderTool tool;
  Thread toolThread;

  public void init()
  {
    String host = getParameter("host");
    String port = getParameter("port");
    System.out.println("searching for ToolBus: " + host + ", " + port);
    try {
      tool = new BidderTool("bidder", InetAddress.getByName(host),
			    (new Integer(port)).intValue());
      tool.connect();
      add(tool.getPanel());
      
      toolThread = new Thread(tool);
      toolThread.start();
    } catch (java.net.UnknownHostException e) {
      System.err.println("host " + host + " not found: " + e);
    } catch (IOException e) {
      System.err.println("IOException caught: " + e);
    } catch (ToolException e) {
      System.err.println("ToolBus connection lost!");
    }
  }

  public void destroy()
  {
    try {
      tool.send(ATermParser.makeSimple("snd-disconnect"));
    } catch(ParseError e) {
      System.err.println("internal parse error");
    } catch(ToolException e) {
      System.err.println("ToolBus connection lost!");
    }
  }
}

