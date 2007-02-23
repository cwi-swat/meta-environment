package nl.cwi.sen1.gui.plugin;

import java.io.IOException;
import java.util.Scanner;

import aterm.ATerm;
import aterm.pure.PureFactory;

public class ConsoleGrabber implements ConsoleGrabberTif {
	private ConsoleGrabberBridge bridge;

	private PureFactory pureFactory = new PureFactory();

	public ConsoleGrabber(String[] args) {
		bridge = new ConsoleGrabberBridge(pureFactory, this);
		try {
			bridge.init(args);
			bridge.connect();
		} catch (IOException e) {
			System.err.println("Could not establish connection to ToolBus: "
					+ e);
			System.exit(1);
		}

		Thread thread = new Thread(new Runnable() {
			public void run() {
				try {
					bridge.run();
				} catch (java.lang.RuntimeException e) {
					e.printStackTrace();
				}
			}
		});
		thread.setName("ModuleManager");
		thread.start();
	}

	public void sendMessage(String message) {
		ATerm event = pureFactory.make("console-message(<str>)", message);
		bridge.postEvent(event);
	}
	
	public static void main(String[] args) {
		ConsoleGrabber grabber = new ConsoleGrabber(args);
		Scanner in = new Scanner(System.in);

		while (in.hasNext()) {
			grabber.sendMessage(in.nextLine());
		}
		
		in.close();
	}

	public void recTerminate(ATerm t0) {
	}
}
