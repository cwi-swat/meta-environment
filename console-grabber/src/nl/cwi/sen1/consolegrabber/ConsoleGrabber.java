package nl.cwi.sen1.consolegrabber;

import java.io.BufferedReader;
import java.io.InputStreamReader;
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
			System.err.println("Could not establish connection to ToolBus: "+ e);
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
		thread.setName("ConsoleGrabber");
		thread.start();
	}

	public void sendMessage(String message) {
		ATerm event = pureFactory.make("console-message(<str>)", message);
		bridge.postEvent(event);
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		int maxTries = 100;
		
		while (maxTries-- > 0 && (line = br.readLine()) != null) {
			try {
				Scanner s = new Scanner(line);
				s.findInLine("The ToolBus server allocated port \\((\\d+)\\)");
				MatchResult result = s.match();
				
				System.out.println(line); // Print the message we matched on.
				
				String port = result.group(1);
				args = buildToolArgs(port);

				ConsoleGrabber grabber = new ConsoleGrabber(args);

				// Eat up all input and send it line by line to the ToolBus
				while((line = br.readLine()) != null) {
					grabber.sendMessage(line + "\n");
				}

				break; // End of file
			} catch (IllegalStateException e) {
				// ToolBus port not yet found, echo the input to stderr
				System.err.println(line);
			}
		}

		if (maxTries == 0) {
			System.err.println("console-grabber: failed to find ToolBus port. Continuing to print on stderr...");

			// If we have something to print left, simply print it
			while((line = br.readLine()) != null){
				System.err.print(line);
			}
		}

		br.close();
	}

	private static String[] buildToolArgs(String port) {
		String[] args;
		args = new String[6];
		args[0] = "-TB_HOST";
		args[1] = "localhost";
		args[2] = "-TB_PORT";
		args[3] = port;
		args[4] = "-TB_TOOL_NAME";
		args[5] = "console-grabber";
		return args;
	}

	public void recTerminate(ATerm t0) {
		//System.exit(0);
	}

	public void recAckEvent(ATerm t0) {
	}
}
