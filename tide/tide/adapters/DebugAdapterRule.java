package tide.adapters;

import aterm.*;

public class DebugAdapterRule
{
	public final static int PORT_STEP         = 0;
	public final static int PORT_STOPPED      = 1;
	public final static int PORT_STARTED      = 2;
    
	public final static int NR_PORT_TYPES = 3;
	
	private boolean enabled;

	private int   id;
	private int   porttype;
	private ATerm port;
	private ATerm cond;
	private ATerm act;
	private ATerm tag;
	
	public String toString() {
		return "rule [\n\tport:" + port +"\n\tcond: " + cond +"\n\tact:" + act + "\n\ttag:" +tag + "\n\tenabled:" + enabled + "\n]";
	}

	static int portType(ATerm port)
	{
		String fun = ((ATermAppl)port).getName();

		int type;

		if(fun.equals("step")) {
			type = PORT_STEP;
		} else if(fun.equals("stopped")) { 
			type = PORT_STOPPED;
		} else if(fun.equals("started")) {
			type = PORT_STARTED;
		} else {
			throw new RuntimeException("strange port: " + port);
		}

		return type;
	}

	public DebugAdapterRule(int rid, ATerm port, ATerm cond, ATerm act, ATerm tag, boolean enabled)
	{
		this.id = rid;
		this.port = port;
		this.cond = cond;
		this.act = act;
		this.tag = tag;
		this.enabled = false;
		this.porttype = portType(port);
	}

	public boolean isEnabled()
	{
		return enabled;
	}

	public void setEnabled(boolean on)
	{
		enabled = on;
	}
	public int getId()
	{
		return id;
	}

	public int getPortType()
	{
		return porttype;
	}

	public ATerm getPort()
	{
		return port;
	}

	public ATerm getCondition()
	{
		return cond;
	}

	public ATerm getAction()
	{
		return act;
	}

	public void modify(ATerm port, ATerm cond, ATerm act, boolean enabled)
	{
		this.port = port;
		this.cond = cond;
		this.act  = act;
		this.enabled = enabled;
		this.porttype = portType(port);
	}

	public boolean isStepOver()
	{
		return cond.match("higher-equal(start-level,stack-level)") != null;
	}
}
