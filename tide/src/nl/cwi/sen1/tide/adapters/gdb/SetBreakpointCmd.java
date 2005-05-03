package nl.cwi.sen1.tide.adapters.gdb;

import java.io.File;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SetBreakpointCmd
  extends Command
{
	private static Pattern breakPattern;

	private int breakpoint;
	private String method;
	private String file;
	private int    linenr;

	static {
		breakPattern = Pattern.compile("Breakpoint ([0-9]+) at 0x[0-9a-f]+: " + "file ([a-zA-Z\\.]+), line ([0-9]+)\\.");
	}
	
	public SetBreakpointCmd(GdbAdapter adapter, String method)
	{
		super(adapter);
		this.method = method;
	}

	public SetBreakpointCmd(GdbAdapter adapter, String file, int line)
	{
		super(adapter);
		this.file   = file;
		this.linenr = line;
	}

	public String command()
	{
		if(method != null)
			return "break " + method + "\n";
		else {
			File f = new File(file);
			return "break " + f.getName() + ":" + linenr + "\n";
		}
	}

	public boolean response(String line)
	{
		Matcher matcher = breakPattern.matcher(line);
		
		if(matcher.matches()) {
			breakpoint = Integer.parseInt(matcher.group(1));
			file       = matcher.group(2);
			linenr     = Integer.parseInt(matcher.group(3));
			return true;
		}
		
		debugMsg("line '" + line + "' does not match with break pattern");
			return false;
	}

	public int getBreakpoint()
	{
		return breakpoint;
	}

	public String getFileName()
	{
		return file;
	}

	public int getLineNr()
	{
		return linenr;
	}
}
