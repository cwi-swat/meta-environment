package tide.tool.ruleinspector;

import javax.swing.Icon;

import tide.tool.*;
import tide.tool.support.*;

public class RuleInspectorFactory
  implements ProcessToolFactory
{
  //{{{ public ProcessTool createTool(DebugProcess process)

  public ProcessTool createTool(DebugProcess process)
  {
    ProcessTool tool = new RuleInspector(process);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "RuleViewer";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
