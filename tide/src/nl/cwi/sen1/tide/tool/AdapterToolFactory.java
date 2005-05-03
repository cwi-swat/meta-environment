package nl.cwi.sen1.tide.tool;

import javax.swing.Icon;

import nl.cwi.sen1.tide.tool.support.*;

public interface AdapterToolFactory
{
  public AdapterTool createTool(DebugAdapter adapter);
  public String getName();
  public Icon   getIcon();
}
