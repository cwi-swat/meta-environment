package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

abstract public class ProcessTool
  extends JInternalFrame
{
  protected DebugProcess process;

  //{{{ protected ProcessTool()

  protected ProcessTool()
  {
    super("", true, true, true, true);
  }

  //}}}
  //{{{ protected ProcessTool(DebugProcess process)
  

  protected ProcessTool(DebugProcess process)
  {
    this();
    this.process = process;
  }

  //}}}
}
