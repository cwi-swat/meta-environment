package tide.adapters.gdb;

import aterm.ATermFactory;


public abstract class Command
{
	protected GdbAdapter adapter;
	private boolean completed;
	private ATermFactory factory;

	public Command(GdbAdapter adapter)
	{
		this.adapter = adapter;
		this.factory = adapter.getFactory();
	}
	
	public ATermFactory getFactory() {
		return factory;
	}

	abstract public String command();
	abstract public boolean response(String line);

	public boolean isCompleted()
	{
		return completed;
	}

	public void setCompleted(boolean on)
	{
		completed = on;
	}

	public String toString()
	{
		return command();
	}

	protected void debugMsg(String msg) {
		System.err.println(msg);
	}
}
