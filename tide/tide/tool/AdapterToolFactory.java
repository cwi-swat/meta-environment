package tide.tool;

import javax.swing.Icon;

import tide.tool.support.*;

public interface AdapterToolFactory
{
  public AdapterTool createTool(DebugAdapter adapter);
  public String getName();
  public Icon   getIcon();
}
