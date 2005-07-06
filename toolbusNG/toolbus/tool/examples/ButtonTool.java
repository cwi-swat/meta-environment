package toolbus.tool.examples;
import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import toolbus.tool.ToolShield;
import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 30, 2002
 */
public class ButtonTool extends Frame implements ActionListener {
  private ToolShield shield;
  private Button button;
  private ATermFactory factory;

  /**
   * Constructor for ButtonTool.
   * @param shield the ToolShield that encapsulates the execution of this tool
   */
  public ButtonTool(ToolShield shield) {
    System.out.println("ButtonTool instance created");
    this.shield = shield;
    factory = shield.getFactory();

    // Build the user interface: just a single button
    button = new Button("Button");
    button.addActionListener(this);

    add(button);
    pack();
    show();
  }

  public void actionPerformed(ActionEvent event) {
    if (event.getSource() == button) {
      System.out.println("actionPerformed(" + event + ")");
      // When the user presses the button, we send an event to the ToolBus
      shield.sndEventToToolBus(factory.make("button(<str>)", button.getLabel()));
    }
  }

  public void ackEvent(ATerm event) {
    // This simple tool ignores event acknowledgements
    System.err.println("ButtonTool.ackEvent(" + event + ")");
  }

  public void terminate(String msg) {
    // Just exit when the ToolBus terminates
    dispose();  // of this frame
    System.err.println("ButtonTool.terminate()");
  }

}
