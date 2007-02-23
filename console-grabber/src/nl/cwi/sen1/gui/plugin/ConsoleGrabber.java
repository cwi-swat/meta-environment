package nl.cwi.sen1.gui.plugin;

import java.io.IOException;

import aterm.pure.PureFactory;

public class ConsoleGrabber {
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

	public static void main(String[] args) {
		new ConsoleGrabber(args);
	}
}
