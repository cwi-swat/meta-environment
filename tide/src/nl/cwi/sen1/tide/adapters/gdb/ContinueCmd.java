package nl.cwi.sen1.tide.adapters.gdb;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ContinueCmd extends Command
{
	private static Pattern patternStoppedKnown;
	private static Pattern patternStoppedUnknown;
	private static Pattern patternFrame;
	private GdbProcess process;

	static {
		patternStoppedKnown = Pattern.compile("\032\032([^:]+):([0-9]+):.*");
		patternStoppedUnknown = Pattern.compile("0x[0-9a-f]+\\sin\\s.+()");
		patternFrame          = Pattern.compile("#([0-9]+)\\s+.*");
	}
	
	public ContinueCmd(GdbAdapter adapter, GdbProcess process)
	{
		super(adapter);
		this.process = process;
	}

	public String command()
	{
		switch(adapter.calcRunMode()) {
			case GdbAdapter.MODE_STEP_INTO:
				System.err.println("single stepping...");
				return "step\n";
			case GdbAdapter.MODE_STEP_OVER:
				System.err.println("stepping over...");
				return "next\n";
			case GdbAdapter.MODE_RUN:
				System.err.println("running...");
				return "cont\n";
			default:
				throw new RuntimeException("illegal run-mode!");
		}
	}

	public boolean response(String line)
	{
		if(line.startsWith("Breakpoint")) {
			return false;
		} 
		
		Matcher matcher;
		
		matcher = patternFrame.matcher(line);
		
		if(matcher.matches()) {
			int level = Integer.parseInt(matcher.group(1));
			process.setStackLevel(level);
			debugMsg("*** stack level: " + level);
			return false;
		} 
		
		matcher = patternStoppedKnown.matcher(line);
		if(matcher.matches()) {
			String file = matcher.group(1);
			int linenr = Integer.parseInt(matcher.group(2));
			debugMsg("execution stopped: file=" + file + ",line=" + linenr);
			process.setCpe(file, linenr);
			return true;
		}
		
		matcher = patternStoppedUnknown.matcher(line);
		if(matcher.matches()) {
			debugMsg("execution stopped at unknown: " + line);
			process.setCpe(null, 0);
			return true;
		} 
		
		if (line.startsWith("Program exited normally")) {
			process.setCpe(null, 0);
			return true;
		}
		
    	System.out.println("line '" + line + "' does not match with patternStopped");
		return false;
	}
}
