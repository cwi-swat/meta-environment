package toolbus.tide;

import toolbus.aterm.*;
import java.util.*;

/**
  * Filters a list of processes.
  */

public class ProcessFilter implements Enumeration
{
  private Enumeration list;
  private ATerms pids;
  private DebugProcess next;

  public ProcessFilter(Enumeration list, ATerm whichpids)
  {
    this.list = list;
    try {
      if(whichpids.equals(ATerm.the_world.makeSimple("all")))
	pids = null;
      else
	pids = ((ATermList)whichpids).getATerms();
    } catch (ParseError e) {
      throw new RuntimeException("internal parse error: " + e.getMessage());
    }
  }

  public boolean hasMoreElements()
  {
    next = null;
    while(list.hasMoreElements() && next == null) {
      next = (DebugProcess)list.nextElement();
      if(pids != null && pids.search(ATerm.the_world.makeInt(next.getPid())) < 0)
	next = null;
    } 
    return next != null;
  }

  public Object nextElement()
  {
    return next;
  }
}
