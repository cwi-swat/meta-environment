package nl.cwi.bus.client.test;

import nl.cwi.bus.server.Bus;

public class StartTest{

	public StartTest(){
		super();
	}
	
	/**
	 * Entrypoint
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception{
		Bus.getInstance().start();
		new ReceivingClient();
		new ReceivingClient();
		new SendingClient();
		new DirectClient();
	}
}
