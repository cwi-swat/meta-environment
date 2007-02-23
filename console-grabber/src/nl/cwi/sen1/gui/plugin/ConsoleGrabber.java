package nl.cwi.sen1.gui.plugin;

import java.io.IOException;
import java.util.Scanner;
import java.util.regex.MatchResult;

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
		Scanner s = new Scanner(System.in);
		MatchResult result = null;

		s.findInLine("The ToolBus server allocated port (\\d+)");
		try {
			result = s.match();
			args = new String[6];
			args[0] = "-TB_HOST_NAME";
			args[1] = "localhost";
			args[2] = "-TB_PORT";
			args[3] = result.group(1);
			args[4] = "-TB_TOOL_NAME";
			args[5] = "console-grabber";

			ConsoleGrabber grabber = new ConsoleGrabber(args);
			while (s.hasNext()) {
				String message = s.nextLine();
				grabber.sendMessage(message);
			}
		} catch (IllegalStateException e) {
			System.err.println("No ToolBus started\n");
			while (s.hasNext()) {
				System.err.println(s.nextLine());
			}
		}

		s.close();
	}

	public void recTerminate(ATerm t0) {
		System.exit(0);
	}

	public void recAckEvent(ATerm t0) {
	}
}
