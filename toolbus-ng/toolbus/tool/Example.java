package toolbus.tool;
import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 30, 2002
 */
public class Example extends Frame implements ActionListener {
	private ToolBridge bridge;
	private Button button;
	private int count = 0;
	private ATermFactory factory;

	/**
	 * Constructor for Example.
	 */
	public Example(ToolBridge bridge) {
		System.out.println("Yep, Example instance created");
		this.bridge = bridge;
		factory = bridge.getFactory();

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
			bridge.sndEventToToolBus(factory.make("button(<str>)", button.getLabel()));
		}
	}

	public ATerm msg(String message) {
		// Print the incoming message
		System.out.println("Example tool received msg: " + message);
		try {
			Thread.sleep(5);
		} catch (InterruptedException e) {
			System.out.println("msg: " + e);
		}

		// Increase the counter and return the current value to the ToolBus
		return factory.make("count(<int>))", new Integer(count++));
	}

	public void ackEvent(ATerm event) {
		// This simple tool ignores event acknowledgements
	}

	public void terminate(String msg) {
		// Just exit when the ToolBus terminate
		bridge.terminate(msg);
	}

}
