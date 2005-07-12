/*
 * Created on Jul 8, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package toolbus.tool.classic;

import java.net.Socket;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class Client {

	public static void main(String[] args) {
		String host = args[0];
		int port = Integer.parseInt(args[1]);
		try {
			Socket s = new Socket(host, port);
			System.out.println("Socket created for " + host + " on port " + port);
		} catch (Exception e) {
			System.err.println(e);
		}

	}
}
