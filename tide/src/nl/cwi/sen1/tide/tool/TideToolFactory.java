package nl.cwi.sen1.tide.tool;

import javax.swing.Icon;

public interface TideToolFactory
{
  public TideTool createTool();
  public String getName();
  public Icon   getIcon();
}
