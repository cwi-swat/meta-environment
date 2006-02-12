package toolbus.tool.java;
import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 30, 2002
 */
public class ButtonTool extends Frame implements ActionListener {
  private JavaToolBridge bridge;
  private Button button;
  private ATermFactory factory;

  /**
   * Constructor for ButtonTool.
   * @param shield the ToolShield that encapsulates the execution of this tool
   */
  public ButtonTool(JavaToolBridge bridge, String[] args) throws IOException {
    System.out.println("ButtonTool instance created");
    this.bridge = bridge;
    factory = bridge.getFactory();

    // Build the user interface: just a single button
    button = new Button("Button");
    button.addActionListener(this);

    add(button);
    pack();
    show();
    
    bridge.connect();
    bridge.start();
  }

  public void actionPerformed(ActionEvent event) {
    if (event.getSource() == button) {
      System.out.println("actionPerformed(" + event + ")");
      // When the user presses the button, we send an event to the ToolBus
      bridge.postEvent(factory.make("button(<str>)", button.getLabel()));
    }
  }

  public void recAckEvent(ATerm event) {
    // This simple tool ignores event acknowledgements
    System.err.println("ButtonTool.ackEvent(" + event + ")");
  }

  public void recTerminate(ATerm msg) {
    // Just exit when the ToolBus terminates
    dispose();  // of this frame
    System.err.println("ButtonTool.terminate()");
  }

}
