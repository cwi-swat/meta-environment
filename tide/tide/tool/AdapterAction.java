package tide.tool;

import java.awt.event.*;
import javax.swing.*;

import tide.tool.support.*;

public class AdapterAction
  extends AbstractAction
{
  private String tool;
  private ToolManager manager;
  private DebugAdapter adapter;

  //{{{ public AdapterAction(String text, Icon icon, DebugAdapter adapter)

  public AdapterAction(String tool, Icon icon, ToolManager manager)
  {
    super(tool, icon);
    this.tool = tool;
    this.manager = manager;
    setEnabled(false);
  }

  //}}}
  //{{{ public DebugAdapter getAdapter()

  public DebugAdapter getAdapter()
  {
    return adapter;
  }

  //}}}
  //{{{ public void setAdapter(DebugAdapter adapter)

  public void setAdapter(DebugAdapter adapter)
  {
    this.adapter = adapter;
    setEnabled(adapter != null);
  }

  //}}}
  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    manager.launchAdapterTool(tool, adapter);
  }

  //}}}
}
