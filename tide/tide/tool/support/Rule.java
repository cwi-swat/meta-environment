package tide.tool.support;

import java.util.*;

public class Rule
{
  private int  rid;
  private boolean enabled;
  private Port port;
  private Expr cond;
  private Expr act;
  private String tag;

  //{{{ public Rule(int rid, Port port, Expr cond, Expr act, tag, enabled)

  public Rule(int rid, Port port, Expr cond, Expr act, String tag, boolean enabled)
  {
    this.rid  = rid;
    this.port = port;
    this.cond = cond;
    this.act  = act;
    this.tag  = tag;
    this.enabled = enabled;
  }

  //}}}
  //{{{ public int getRid()

  public int getRid()
  {
    return rid;
  }

  //}}}
  //{{{ public Port getPort()

  public Port getPort()
  {
    return port;
  }

  //}}}
  //{{{ public Expr getCondition()

  public Expr getCondition()
  {
    return cond;
  }

  //}}}
  //{{{ public Expr getAction()

  public Expr getAction()
  {
    return act;
  }

  //}}}
  //{{{ public void modify(Expr condition, Expr action, boolean enabled)

  public void modify(Port port, Expr condition, Expr action, boolean enabled)
  {
    this.port = port;
    this.cond = condition;
    this.act  = action;
    this.enabled = enabled;
  }

  //}}}
  //{{{ public String getTag()

  public String getTag()
  {
    return tag;
  }

  //}}}
  //{{{ public boolean isEnabled()

  public boolean isEnabled()
  {
    return enabled;
  }

  //}}}

  //{{{ public Expr getLocation()

  public Expr getLocation()
  {
    Iterator iter = cond.iterator();

    while (iter.hasNext()) {
      Expr expr = (Expr)iter.next();
      if (expr.isLocation()) {
	return expr;
      }
    }

    return null;
  }

  //}}}
  //{{{ public boolean isBreakpoint()

  public boolean isBreakpoint()
  {
    Iterator iter = act.iterator();

    while (iter.hasNext()) {
      Expr expr = (Expr)iter.next();
      if (expr.isBreak()) {
	return true;
      }
    }

    return false;
  }

  //}}}
  //{{{ public Str ing toString()

  public String toString()
  {
    return "rule " + rid + " [" + tag + "," + enabled + "]: " + port.toTerm() + ","
      + cond.toTerm() + "," + act.toTerm();
  }

  //}}}
}
