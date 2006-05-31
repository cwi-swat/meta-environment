package nl.cwi.bus.client.test;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTextArea;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.term.serializable.SerializableStringTerm;

/**
 * A dummy client application / tool. This client will only send data.
 * 
 * @author Arnold Lankamp
 */
public class ReceivingClient implements ITool{
	private ToolBridge toolBridge = null;

	private JFrame frame = null;
	private JTextArea textArea = null;

	/**
	 * Default constructor
	 */
	public ReceivingClient(){
		super();

		init();

		initGUI();
	}

	/**
	 * Initializes the client
	 */
	private void init(){
		toolBridge = ToolRegistery.getInstance().createBridge(this);
		toolBridge.start();
	}

	private void initGUI(){
		frame = new JFrame();

		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent event){
				System.out.println("Closing "+event.getSource());
				frame.dispose();
				terminate();
			}
		});

		Container c = frame.getContentPane();
		c.setLayout(new BorderLayout());

		textArea = new JTextArea();
		textArea.setLineWrap(true);
		c.add(textArea, BorderLayout.CENTER);
		
		frame.setSize(200, 200);
		frame.setVisible(true);
	}

	public void string(SerializableStringTerm string){
		textArea.setText(string.getValue());
	}

	/**
	 * Called when a tool is requested to shut down.
	 */
	public void terminate(){
		toolBridge.stopRunning();
	}

	/**
	 * Entrypoint
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception{
		new ReceivingClient();
	}
}
