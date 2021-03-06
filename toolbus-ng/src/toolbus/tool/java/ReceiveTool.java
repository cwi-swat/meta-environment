package toolbus.tool.java;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTextPane;
import javax.swing.WindowConstants;

import toolbus.adapter.java.AbstractJavaTool;
import aterm.ATerm;
import aterm.ATermFactory;

public class ReceiveTool extends AbstractJavaTool{
	private final JFrame frame;
	private final JTextPane textPane;

	public ReceiveTool(){
		super();
		
		frame = new JFrame();
		textPane = new JTextPane();
		layout();
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
		
		frame.setVisible(true);
	}
	
	public void set(String message){
		textPane.setText(message);
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// Left blank intentionally.
	}
	
	public void receiveTerminate(ATerm msg){
		frame.dispose();
	}
	
	public static void main(String[] args){
		ReceiveTool receiveTool = new ReceiveTool();
		try{
			receiveTool.connect(args);
		}catch(Exception ex){
			throw new RuntimeException(ex);
		}
	}
}
