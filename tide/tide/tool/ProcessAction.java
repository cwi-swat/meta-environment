package tide.tool;

import java.awt.event.*;
import javax.swing.*;

import tide.tool.*;
import tide.tool.support.*;

public class ProcessAction
  extends AbstractAction
{
  private String tool;
  private ToolManager manager;
  protected DebugProcess process;

  //{{{ public ProcessAction(String text, Icon icon, ToolManager manager)

  public ProcessAction(String tool, Icon icon, ToolManager manager)
  {
    super(tool, icon);
    this.tool    = tool;
    this.manager = manager;
    setEnabled(false);
  }

  //}}}
  //{{{ public void setProcess(DebugProcess process)

  public void setProcess(DebugProcess process)
  {
    this.process = process;
    setEnabled(process != null);
  }

  //}}}
  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    manager.launchProcessTool(tool, process);
  }

  //}}}
}
