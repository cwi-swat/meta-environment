package tide.tool;

import javax.swing.Icon;
import tide.tool.support.*;

public interface TideToolFactory
{
  public TideTool createTool();
  public String getName();
  public Icon   getIcon();
}
