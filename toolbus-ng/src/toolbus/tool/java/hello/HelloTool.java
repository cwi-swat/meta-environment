package toolbus.tool.java.hello;

import toolbus.adapter.java.AbstractJavaTool;
import aterm.ATerm;
import aterm.ATermFactory;

public class HelloTool extends AbstractJavaTool{
	
	public HelloTool(){
		super();
	}
	
	public ATerm getText(){
		ATermFactory factory = getFactory();
		return factory.make("text(<str>)", "Hello world in Java!\n");
	}
	
	public void receiveAckEvent(ATerm aTerm){
		// Left blank intentionally.
	}
	
	public void receiveTerminate(ATerm msg){
		System.out.print("rec-terminate received: " + msg);
	}
	
	public static void main(String[] args) throws Exception{
		HelloTool helloTool = new HelloTool();
		helloTool.connect(args);
	}
}
