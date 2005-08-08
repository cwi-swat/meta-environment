package nl.cwi.sen1.tide.tool;

import javax.swing.Icon;

import nl.cwi.sen1.tide.tool.support.DebugProcess;

public interface ProcessToolFactory
{
  public ProcessTool createTool(DebugProcess process);
  public String getName();
  public Icon   getIcon();
}
