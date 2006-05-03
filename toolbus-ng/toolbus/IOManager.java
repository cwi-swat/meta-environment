package toolbus;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

import toolbus.exceptions.ToolBusError;
import toolbus.tool.ToolInstance;
import toolbus.tool.classic.ClassicToolShield;
import aterm.ATerm;

public class IOManager {
	
	private static final boolean verbose = true;
	
	private final static int MAX_HANDSHAKE = 512; // Do not change since they correspond with

	private final static int MIN_MSG_SIZE = 128; // the C implementation
	
	private ToolBus toolbus;
	
	private String toolname;
	
	private SocketChannel client;
	
	private ByteBuffer handshake = ByteBuffer.allocate(MAX_HANDSHAKE);
	
	private static int WellKnownSocketPort = 8999;

	private ServerSocketChannel WellKnownSocketChannel;

	private ServerSocket WellKnownSocket;

	private InetAddress localHost;
	
	private Selector selector;
	
	public IOManager(ToolBus toolbus) throws ToolBusError{
		this.toolbus = toolbus;
		try {
			localHost = InetAddress.getLocalHost();
			info("Creating WellKnownSocket: " + WellKnownSocketPort + " "
					+ localHost);
			WellKnownSocketChannel = ServerSocketChannel.open();
			WellKnownSocket = WellKnownSocketChannel.socket();
			WellKnownSocket.bind(new InetSocketAddress(WellKnownSocketPort));
			WellKnownSocketChannel.configureBlocking(false);
			WellKnownSocket.setPerformancePreferences(0,2,1);
			selector = Selector.open();
			WellKnownSocketChannel.register(selector, SelectionKey.OP_ACCEPT);

		} catch (IOException e) {
			throw new ToolBusError("Cannot create IOManager: " + e.getMessage());
		}

		info("WellKnownSocket created: " + WellKnownSocket);
	}
	
	public void closeConnections() throws ToolBusError{
		try {
		WellKnownSocket.close();
		WellKnownSocketChannel.close();
		selector.close();
		} catch (IOException e) {
			throw new ToolBusError("Cannot create IOManager: " + e.getMessage());
		}
	}
	
	void info(String msg) {
		if (verbose) {
			System.err.println("[IOManager] "
					+ msg.substring(0, Math.min(msg.length(), 100)));
		}
	}
	
	public void handleInputFromTools(long timeout) {
		try {
			if(selector.select(timeout) == 0){
				return;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		Set readyKeys = selector.selectedKeys();
		Iterator iterator = readyKeys.iterator();
		while (iterator.hasNext()) {
			SelectionKey key = (SelectionKey) (iterator.next());
			iterator.remove();
			info("key " + key);

			try {
				if (key.isAcceptable()) {
					info("case acceptable");
					ServerSocketChannel server = (ServerSocketChannel) key
							.channel();
					client = server.accept();
					client.configureBlocking(true);
					shakeHands();

				} else if (key.isReadable()) {
					info("case readable");
					client = (SocketChannel) key.channel();
					if(key.attachment() instanceof  ClassicToolShield){
						ClassicToolShield ts = (ClassicToolShield) key.attachment();
						ATerm term = ts.receiveTerm();
						if (term != null) {
							info("TERM READ: " + term);
							ts.sndTermFromToolToToolBus(term);
						}
				/*	} else if(key.attachment() instanceof InputStream){	
						info("case InputStream");
						InputStream is = (InputStream) key.attachment();
						if(is.available() > 0){
							InputStreamReader isr = new InputStreamReader(is);
				            //BufferedReader br = new BufferedReader(isr);
				           // String line = null;
				            // while ( (line = br.readLine()) != null)
				            //     System.out.println(">>> " + line); 
							char[]  cbuf  = new char[100];
							int n;
							while((n = isr.read(cbuf)) > 0){
								info(n + " bytes read");
								for(int j = 0; j < n; j++)
									System.out.print(cbuf[j]);
							}
						}
                        info("seen all output"); */
					} else {
						System.err
						.println("Unrecognized attachment in key: " + key.attachment());
					}
				} else if (key.isWritable()) {
					info("case writable");
					client = (SocketChannel) key.channel();
					ClassicToolShield ts = (ClassicToolShield) key.attachment();
					ts.sendTerm();
				} else {
					System.err
							.println("Cannot handle key in handleInputFromTools");
				}
			} catch (IOException e) {
				System.err.println("handleInputFromTools: " + e);
				e.printStackTrace();
				key.cancel();
				try {
					key.channel().close();
				} catch (IOException ce) {
					System.err.println("handleInputFromTools: " + ce);
					ce.printStackTrace();
				}
			}
		}
	}
	
	public int getWellKnownSocketPort() {
		return WellKnownSocketPort;
	}
	
	public InetAddress getLocalHost() {
		return localHost;
	}
	
	public Selector getSelector(){
		return selector;
	}
	
	public void wakeup(){
		selector.wakeup();
	}
	
	private void shakeHands() throws IOException {
		handshake.clear();
		int nr = client.read(handshake);             // <== read

		info(nr + " bytes read from client");
		handshake.flip();
		String s = "";
		while (handshake.hasRemaining()) {
			s = s + (char) handshake.get();
		}
		info("read: <" + s + ">");

		String toolHand = s.toLowerCase().trim();
		info("input: <" + toolHand + ">");
		String elems[] = toolHand.split(" ");

		toolname = elems[0];
		info("toolname = " + toolname);
		String host = elems[1];
		info("host = " + host);

		info("elems[2] = " + elems[2]);

		int lastd = -1;
		for (int i = 0; i < elems[2].length(); i++) {
			if ((i == 0) && (elems[2].charAt(0) == '-')) {
				lastd = i;
			} else if (!Character.isDigit(elems[2].charAt(i))) {
				break;
			}
			lastd = i;
		}
		int toolid = Integer.parseInt(elems[2].substring(0, lastd + 1));
		info("toolid = " + toolid);

		try{
			ToolInstance ti;
			if (toolid >= 0) {
				ti = toolbus.getToolInstance(toolid);
			} else {
				ti = toolbus.addToolInstance(toolname, true);
				toolid = ti.getToolCount();			
			}
			writeInt(toolid);                     // <=== write
			ti.connect(client);
		} catch (Exception e){
			e.printStackTrace();
		}
	}
	
	private void writeInt(int n) throws IOException {
		// byte[] buffer = new byte[MAX_HANDSHAKE];
		handshake.clear();
		String s = toolname + " " + Integer.toString(n);

		byte bs[] = s.getBytes();
		info("writeInt: " + s + "; length = " + bs.length);
		for (int i = 0; i < MAX_HANDSHAKE; i++) {
			if (i < bs.length) {
				handshake.put(bs[i]);
			} else {
				handshake.put((byte) 0);
			}
		}
		handshake.flip();
		int k = client.write(handshake);
		info("writeInt(" + n + ") writes " + k + "  bytes");
	}

}
