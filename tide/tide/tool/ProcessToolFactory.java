package tide.tool;

import javax.swing.Icon;
import tide.tool.support.*;

public interface ProcessToolFactory
{
  public ProcessTool createTool(DebugProcess process);
  public String getName();
  public Icon   getIcon();
}
