package tide.tool;

import javax.swing.JInternalFrame;

public abstract class TideTool
  extends JInternalFrame
{
  private static int next_id = 0;

  private int id;
  private ToolManager manager;

  //{{{ public TideTool(ToolManager manager)

  public TideTool(ToolManager manager)
  {
    super("", true, true, true, true);

    this.manager = manager;

    id = next_id++;
  }

  //}}}

  //{{{ public ToolManager getManager()

  public ToolManager getManager()
  {
    return manager;
  }

  //}}}
  //{{{ public int getId()

  public int getId()
  {
    return id;
  }

  //}}}
}
