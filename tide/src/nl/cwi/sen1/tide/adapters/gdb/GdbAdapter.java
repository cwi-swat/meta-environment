package nl.cwi.sen1.tide.adapters.gdb;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Iterator;

import nl.cwi.sen1.tide.adapters.DebugAdapter;
import nl.cwi.sen1.tide.adapters.DebugAdapterRule;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class GdbAdapter extends DebugAdapter {
	static public final int MODE_STEP_INTO = 0;
	static public final int MODE_STEP_OVER = 1;
	static public final int MODE_RUN = 2;

	private String name;
	private Process gdb;
	private GdbProcess process;

	private BufferedReader input;
	private BufferedReader error;
	private Writer output;

	static public final void main(String[] args) throws IOException {
		int pid = -1;
		int port = 9500;
		String program = null;
		String arguments = "";
		ATermFactory factory = new PureFactory();

		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-attach")) {
				pid = Integer.parseInt(args[++i]);
			} else if (args[i].equals("-program")) {
				program = args[++i];
			} else if (args[i].equals("-help")) {
				usage();
			} else if (args[i].equals("-args")) {
				arguments = arguments + " " + args[++i];
			} else if (args[i].equals("-port")) {
				port = Integer.parseInt(args[++i]);
			}
		}
		
		if (program == null) {
			usage();
		}

		// String cmd = "gdb -interpreter=mi -f -q " + program;
		String cmd = "gdb -f -q " + program;
		if (pid >= 0) {
			cmd += " " + pid;
		}

		Process process = Runtime.getRuntime().exec(cmd);
		debugMsg("gdb started");
		GdbAdapter adapter = new GdbAdapter(factory, program, args, arguments, process, port);
		adapter.run();
	}

	static void usage() {
		System.err.println(
			"usage: tide-gdb -port <tide-port> -program <prg> [-attach <pid>]");
		System.exit(1);
	}
	
	static private void debugMsg(String msg) {
		System.err.println(msg);
	}

	public GdbAdapter(
		ATermFactory factory,
		String filename,
		String[] args,
		String processArguments,
		Process proc,
		int port)
		throws IOException {
		super(factory, args, port);	

		File file = new File(filename);
		this.name = file.getName();
		gdb = proc;

		createGdbIOReaders(proc);
		buildGdbConnection(processArguments, name);
		run();
	}

	private void buildGdbConnection(String args, String name) {
		writeln("set args " + args);
		writeln("set prompt (gdb)\\n");
		writeln("define hook-stop");
		writeln("bt -1");
		writeln("end");
	
		process = new GdbProcess(this,name);
	
		evaluate(new SetBreakpointCmd(this, "main"));
		evaluate(new ContinueCmd(this, process) {
			public String command() {
				return "run\n";
			}
		});
		evaluate(new RetrievePidCmd(this, process));
		
		processCreated(process);
	}

	private void createGdbIOReaders(Process proc) {
		input =
			new BufferedReader(new InputStreamReader(proc.getInputStream()));
		error =
			new BufferedReader(new InputStreamReader(proc.getErrorStream()));
		output = new OutputStreamWriter(proc.getOutputStream());
	}

	public void writeln(String line) {
		try {
			output.write(line);
			output.write("\n");
			output.flush();
		} catch (IOException e) {
			debugMsg("connection with gdb broken!");
		}
	}
	public void evaluate(Command cmd) {
		try {
			String string = cmd.command();
			debugMsg("entering poll mode with gdb command:\n\t" + string);
			output.write(string);
			output.flush();
			String line;
			do {
				line = input.readLine();
				debugMsg("processing line in poll mode:\n\t" + line);
				if (line.length() == 0) {
					continue; // Ignore empty lines
				} else if (line.startsWith("(gdb)")) {
					continue; // Ignore prompt
				} else if (line.startsWith("Starting program:")) {
					continue; // Ignore 'Starting program:' line
				}
			} while (!cmd.response(line));
			debugMsg("poll mode done!");
		} catch (IOException e) {
			debugMsg("connection with GDB broken.");
			System.exit(1);
		}
	}

	public int calcRunMode() {
		if (process.rulesPerPort[DebugAdapterRule.PORT_STEP].size() == 0) {
			return MODE_RUN;
		}

		// Look for any 'non step-over' rules
		Iterator iter =
			process.rulesPerPort[DebugAdapterRule.PORT_STEP].iterator();
		while (iter.hasNext()) {
			DebugAdapterRule rule = (DebugAdapterRule) iter.next();
			if (!rule.isStepOver()) {
				return MODE_STEP_INTO;
			}
		}

		return MODE_STEP_OVER;
	}
}
