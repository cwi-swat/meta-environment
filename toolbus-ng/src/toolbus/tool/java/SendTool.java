package toolbus.tool.java;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextPane;
import javax.swing.WindowConstants;

import toolbus.adapter.java.AbstractJavaTool;
import aterm.ATerm;
import aterm.ATermFactory;

public class SendTool extends AbstractJavaTool{
	private final JFrame frame;
	private final JTextPane textPane;
	private final JButton submitButton;

	public SendTool(String[] args){
		super();
		
		try{
			connect(args);
		}catch(Exception ex){
			throw new RuntimeException(ex);
		}
		
		frame = new JFrame();
		textPane = new JTextPane();
		submitButton = new JButton("Submit");
		layout();
		
		setListeners();
	}

	private void layout(){
		frame.setSize(200, 200);
		frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				ATermFactory factory = getToolBridge().getFactory();
				ATerm message = factory.makeAppl(factory.makeAFun("exit", 1, false), factory.makeList());
				sendEvent(message);
			}
		});
		
		Container contentPane = frame.getContentPane();
		contentPane.setLayout(new BorderLayout());
		
		contentPane.add(textPane, BorderLayout.CENTER);
		
		contentPane.add(submitButton, BorderLayout.SOUTH);
		
		frame.setVisible(true);
	}
	
	private void setListeners(){
		ButtonListener buttonListener = new ButtonListener();
		submitButton.addActionListener(buttonListener);
		
		KeyListener kl = new KeyAdapter(){
			public void keyTyped(KeyEvent e){
				ATermFactory factory = getToolBridge().getFactory();
				ATerm message = factory.makeAppl(factory.makeAFun("available", 0, false));
				sendEvent(message);
			}
			
		};
		textPane.addKeyListener(kl);
	}
	
	protected class ButtonListener implements ActionListener{

		public void actionPerformed(ActionEvent e){
			if(e.getSource() == submitButton){
				ATermFactory factory = getToolBridge().getFactory();
				ATerm message = factory.makeAppl(factory.makeAFun("available", 0, false));
				sendEvent(message);
			}
		}
	}
	
	public ATerm getText(){
		ATermFactory factory = getToolBridge().getFactory();
		return factory.makeAppl(factory.makeAFun("getText", 1, false), factory.makeAppl(factory.makeAFun(textPane.getText(), 0, false)));
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// Left blank intentionally.
	}
	
	public void receiveTerminate(ATerm msg){
		frame.dispose();
	}
	
	public static void main(String[] args){
		new SendTool(args);
	}
}
