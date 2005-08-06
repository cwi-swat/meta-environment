/*
 * Created on Jul 8, 2005
 * 
 * @author paulk
 *
 */
package toolbus.tool.classic;

import java.net.Socket;

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
