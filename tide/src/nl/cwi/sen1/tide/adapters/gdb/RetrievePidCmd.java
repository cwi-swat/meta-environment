package nl.cwi.sen1.tide.adapters.gdb;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RetrievePidCmd extends Command
{
	private static Pattern patternInfo;
	private GdbProcess process;

	static {
		patternInfo = Pattern.compile("process ([0-9]+)");
	}
	
	public RetrievePidCmd(GdbAdapter adapter, GdbProcess process)
	{
		super(adapter);
		this.process = process;
	}

	public String command()
	{
		return "info proc\n";
	}

	public boolean response(String line)
	{
		if(line.startsWith("Process status flags:")) {
			return false;
		} 
		
		if(line.startsWith("Reason for stopping:")) {
			return false;
		} 
		
		if(line.startsWith("Additional signal/fault info:")) {
			return true;
		} 
		
		Matcher matcher = patternInfo.matcher(line);
		
		if(matcher.matches()) {
			int pid = Integer.parseInt(matcher.group(1));
			debugMsg("*** PID: " + pid);
			// TODO: get this working again, now the pid is set to 0 always.
			process.setPid(pid);
			return true;
		} 
		
		debugMsg("line '" + line + "' does not match with patternInfo");
		return false;
		
	}
}
