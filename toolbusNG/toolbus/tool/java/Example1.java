package toolbus.tool.java;

import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import aterm.ATerm;
import aterm.ATermFactory;

public class Example1
  extends Frame
  implements ActionListener
{
  private ATermFactory factory;
  private JavaToolBridge bridge;
  private Button button;
  private int count;

  public static final void main(String[] args)
    throws IOException
  {
    new Example1(null,args);
  }

  public Example1(JavaToolBridge bridge, String[] args)
    throws IOException
  {
	this.bridge = bridge;
	
	// Obtain the ATerm factory from the bridge passed to us.
	// It is crucial that all tools use the same factory!
	factory = bridge.getFactory();

    // Build the user interface: just a single button
    button = new Button("Button");
    button.addActionListener(this);
    add(button);
    pack();
    show();
    
    // Actually establish the connection with the ToolBus
    bridge.connect();

    // Start the tool event loop
    bridge.start();
  }

  public void actionPerformed(ActionEvent event)
  {
    if (event.getSource() == button) {
      // When the user presses the button, we send an event to the ToolBus
      System.err.println("actionPerformed: button");
      bridge.postEvent(factory.make("button(<str>)", button.getLabel()));
    }
  }

  public ATerm msg(String message)
  {
    // Print the incoming message
    System.out.println("Example tool received msg: " + message);

    // Increase the counter and return the current value to the ToolBus
    return factory.make("snd-value(count(<int>))", new Integer(count++));
  }

  public void recAckEvent(ATerm event)
  {
    // This simple tool ignores event acknowledgements
  }

  public void recTerminate(ATerm arg)
  {
    // Clean up when this tool terminates
	dispose();  // of this frame
  }
}
