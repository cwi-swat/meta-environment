package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

public abstract class TideTool
  extends JInternalFrame
{
  private static int next_id = 0;

  private int id;
  private ToolManager manager;

  private String name;
  private Object target;

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
  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public Object getTarget()

  public Object getTarget()
  {
    return target;
  }

  //}}}
  //{{{ public void setName(String name)

  public void setName(String name)
  {
    this.name = name;
  }

  //}}}
  //{{{ public void setTarget(Object target)

  public void setTarget(Object target)
  {
    this.target = target;
  }

  //}}}

  //{{{ public void displayError(Expr error)

  public void displayError(Expr error)
  {
    displayError(error.getErrorMessage(), error.getErrorData());
  }

  //}}}
  //{{{ public void displayError(String msg, Expr data)

  public void displayError(String msg, Expr data)
  {
    String string = data.toString();
    if (!string.equals("[]")) {
      msg += ": " + string;
    }

    manager.displayError(msg);
    /* Removed due to a bug in JDK-1.[234]
    JOptionPane.showInternalMessageDialog(this, msg, "Tide Error",
					  JOptionPane.ERROR_MESSAGE);
					  */
    System.err.println(msg + ": " + data);
  }

  //}}}

  //{{{ public void destroy()

  public void destroy()
  {
    Runnable runnable = new Runnable()
    {
      public void run() { dispose(); }
    };
    getToolkit().getSystemEventQueue().invokeLater(runnable);
  }

  //}}}
}
