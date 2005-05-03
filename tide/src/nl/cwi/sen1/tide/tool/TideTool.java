package nl.cwi.sen1.tide.tool;

import java.awt.EventQueue;
import java.net.URL;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JInternalFrame;

import nl.cwi.sen1.tide.tool.support.Expr;

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

  //{{{ protected Icon loadIcon(String name)

  protected Icon loadIcon(String name)
  {
    URL url = getClass().getResource("/resources/images/" + name);
    return new ImageIcon(url);
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
  }

  //}}}

  //{{{ public void destroy()

  public void destroy()
  {
    Runnable runnable = new Runnable()
    {
      public void run() { dispose(); }
    };
    EventQueue.invokeLater(runnable);
  }

  //}}}
}
