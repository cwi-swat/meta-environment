package nl.cwi.bus.client.test;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.net.InetAddress;
import java.net.InetSocketAddress;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

import nl.cwi.bus.client.ITool;
import nl.cwi.bus.client.ToolBridge;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.config.Config;
import nl.cwi.bus.variable.Variable;
import nl.cwi.bus.variable.VariableHandler;
import nl.cwi.term.serializable.SerializableStringTerm;

/**
 * A dummy client application / tool. This client will only receive data.
 * 
 * @author Arnold Lankamp
 */
public class SendingClient implements ITool{
	private ToolBridge toolBridge = null;

	private JFrame frame = null;
	private JTextArea textArea = null;

	/**
	 * Default constructor
	 */
	public SendingClient(){
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
		c.add(textArea, BorderLayout.CENTER);
		c.add(new JButton(new SubmitAction()), BorderLayout.SOUTH);

		frame.setSize(200, 200);
		frame.setVisible(true);
	}

	private class SubmitAction extends AbstractAction{
		//Useless, I'm not gonna serialize it.
		public final static long serialVersionUID = -1;

		public SubmitAction(){
			super();
		}

		public void actionPerformed(ActionEvent event){
			//System.out.println("Action: "+event.getSource());
			try{
				String text = textArea.getText();
				textArea.setText("");
				Variable variable = new Variable(new SerializableStringTerm(text), new InetSocketAddress(InetAddress.getLocalHost(), Config.getUsingPort()), toolBridge.getToolID());
				
				PutOperation putOperation = PutOperation.createStripped(variable);
				toolBridge.send(putOperation);
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
	}

	public void string(SerializableStringTerm string){
		// Do nothing
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
		new SendingClient();
	}
}
